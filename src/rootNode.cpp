/**
 * @file rootNode.cpp
 * @author Adrian Goessl
 * @brief This file contains the implementation of the RootNode class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#include "../src/include/rootNode.h"

using namespace rootNode;

RootNode::RootNode(int counter, normalNode::Node* left, normalNode::Node* right) : Node(0), counter(counter), left(left), right(right)
{
    if (left == nullptr || right == nullptr)
    {
        throw std::runtime_error("Left or right is null");
    }

    if (counter < 0)
    {
        throw std::runtime_error("Counter is negative");
    }
}

RootNode::RootNode(int counter, normalNode::Node* left, normalNode::Node* right, int timeStamp) : Node(timeStamp), counter(counter), left(left), right(right)
{
    if (left == nullptr || right == nullptr)
    {
        throw std::runtime_error("Left or right is null");
    }

    if (counter < 0)
    {
        throw std::runtime_error("Counter is negative");
    }
}

int RootNode::getFrequency() const
{
    return counter;
}
