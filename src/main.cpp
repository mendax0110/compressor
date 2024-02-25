/**
 * @file main.cpp
 * @author Adrian Goessl
 * @brief This file contains the main program
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#include <iostream>
#include <string>
#include <queue>
#include <fstream>
#include <vector>
#include <map>

#include "../src/include/node.h"
#include "../src/include/leafNode.h"
#include "../src/include/rootNode.h"
#include "../src/include/compare.h"

using namespace std;
using namespace normalNode;
using namespace leafNode;
using namespace rootNode;
using namespace compare;


vector<uint8_t> pack(const vector<bool>& bitstream, ofstream& compressFile)
{
    vector<uint8_t> encodedBytes;

    for (size_t i = 0; i < bitstream.size(); i += 8)
    {
        uint8_t byte = 0;
        size_t remaining = min<size_t>(8, bitstream.size() - i);

        for (size_t j = 0; j < 8; ++j)
        {
            if (j < remaining)
            {
                byte |= static_cast<uint8_t>(bitstream[i + j]) << (7 - j);
            }
            else
            {
                byte |= 0 << (7 - j);
            }
        }

        encodedBytes.push_back(byte);

        if (compressFile.is_open())
        {
            compressFile << byte;
        }
    }

    return encodedBytes;
}

void unpack(unsigned char character, vector<bool>& bitstream)
{
    for (int i = 7; i >= 0; --i)
    {
        bitstream.push_back((character >> i) & 1);
    }
}

priority_queue<Node*, vector<Node*>, Compare> buildPriorityQueue(int* frequencyTable)
{
    priority_queue<Node*, vector<Node*>, Compare> nodes;

    for (int i = 0; i < 256; ++i)
    {
        if (frequencyTable[i] > 0)
        {
            nodes.push(new LeafNode((char)i, frequencyTable[i]));
        }
    }

    return nodes;
}

void traverseTree(Node* root, string code, map<char, string>& huffmanCode)
{
    if (LeafNode* leaf = dynamic_cast<LeafNode*>(root))
    {
        huffmanCode[leaf->getCharacter()] = code;
    }
    
    if (RootNode* node = dynamic_cast<RootNode*>(root))
    {
        traverseTree(node->left, code + "0", huffmanCode);
        traverseTree(node->right, code + "1", huffmanCode);
    }
}

Node* buildHuffmanTree(priority_queue<Node*, vector<Node*>, Compare>& nodes)
{
    while(nodes.size() >= 2)
    {
        int frequency1 = nodes.top()->getFrequency();
        Node* left = nodes.top();
        nodes.pop();

        int frequency2 = nodes.top()->getFrequency();
        Node* right = nodes.top();
        nodes.pop();

        int depth = max(left->getTimeStamp(), right->getTimeStamp()) + 1;

        if (dynamic_cast<RootNode*>(left) && dynamic_cast<RootNode*>(right))
        {
            depth = max(left->getTimeStamp(), right->getTimeStamp()) + 1;
        }
        else if (dynamic_cast<RootNode*>(left))
        {
            depth = left->getTimeStamp() + 1;
        }
        else if (dynamic_cast<RootNode*>(right))
        {
            depth = right->getTimeStamp() + 1;
        }
        else
        {
            depth = 0;
        }

        Node* root = new RootNode(frequency1 + frequency2, left, right, depth);
        nodes.push(root);
    }

    return nodes.top();
}

void decode(Node* root, ofstream& o, const vector<bool>& decodedBits, int charsToDecode)
{
    Node* current = root;
    int charsDecoded = 0;

    for (bool bit : decodedBits)
    {
        if (bit == 0)
        {
            current = dynamic_cast<RootNode*>(current)->left;
        }
        else
        {
            current = dynamic_cast<RootNode*>(current)->right;
        }

        if (auto leaf = dynamic_cast<LeafNode*>(current))
        {
            o << leaf->getCharacter();
            ++charsDecoded;
            current = root;

            if (charsDecoded == charsToDecode)
            {
                return;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if(argc != 4)
    {
        cout << "Wrong number of arguments" << endl;
        return 1;
    }

    if(string(argv[2]) == "-comp")
    {
        ifstream file;
        file.open(argv[1]);

        if (!file.is_open())
        {
            cout << "File not found" << endl;
            return 1;
        }

        ofstream compressFile;
        compressFile.open(string(argv[3]) + ".txt");

        int frequencyTable[256] = {0};
        int numOfUniqueChars = 0;
        int numOfChars = 0;
        char c;

        while (file >> noskipws >> c)
        {
            ++frequencyTable[(int)c];
            ++numOfChars;
        }

        if (numOfChars == 0)
        {
            cout << "File is empty" << endl;
            return 1;
        }

        compressFile << numOfChars << endl;

        for (int i = 0; i < 256; ++i)
        {
            if (frequencyTable[i] > 0)
            {
                ++numOfUniqueChars;
            }
        }

        compressFile << numOfUniqueChars << endl;

        for (int i = 0; i < 256; ++i)
        {
            if (frequencyTable[i] > 0)
            {
                compressFile << (char)i << " " << frequencyTable[i] << endl;
            }
        }

        priority_queue<Node*, vector<Node*>, Compare> nodes = buildPriorityQueue(frequencyTable);

        Node* root = buildHuffmanTree(nodes);

        map<char, string> huffmanCode;
        traverseTree(root, "", huffmanCode);

        file.clear();
        file.seekg(0, ios::beg);

        vector<bool> bitstream;

        while (file.get(c))
        {
            for (int i = 0; i < huffmanCode[c].size(); ++i)
            {
                if (huffmanCode[c][i] == '0')
                {
                    bitstream.push_back(0);
                }
                else
                {
                    bitstream.push_back(1);
                }
            }
        }

        vector<unsigned char> encodedBytes = pack(bitstream, compressFile);

        return 0;
    }
    else if (string(argv[2]) == "-decomp")
    {
        int charsToDecode = 0;
        int uniqueChars = 0;

        ifstream file;
        file.open(argv[1]);

        if (!file.is_open())
        {
            cout << "File not found" << endl;
            return 1;
        }

        ofstream decompressFile;
        decompressFile.open(string(argv[3]) + ".txt");

        file >> charsToDecode >> uniqueChars;
        file.ignore(1, '\n');

        int frequencyTable[256] = {0};

        // TODO: This is a bug. The frequency table is not being read correctly.
        for (int i = 0; i < uniqueChars; ++i)
        {
            char c;
            int frequency;
            file >> c >> frequency;
            file.ignore(1, '\n');

            int index = (int)c;
            frequencyTable[index] = frequency;
        }

        priority_queue<Node*, vector<Node*>, Compare> nodes = buildPriorityQueue(frequencyTable);

        Node* root = buildHuffmanTree(nodes);

        vector<bool> decodedBits;
        unsigned char pack;

        while (file >> noskipws >> pack)
        {
            unpack(pack, decodedBits);
        }

        decode(root, decompressFile, decodedBits, charsToDecode);

        return 0;
    }
}