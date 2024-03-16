/**
 * @file leafNode.cpp
 * @author Adrian Goessl
 * @brief This file contains the implementation of the LeafNode class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#include "../src/include/leafNode.h"

using namespace leafNode;

/// @brief This is the constructor for the LeafNode class
/// @param character These are the characters
/// @param frequency This is the frequency of the characters
LeafNode::LeafNode(char character, int frequency) : Node(0), character(character), frequency(frequency)
{
    if (frequency < 0)
    {
        throw std::runtime_error("Frequency is negative");
    }

    if (!std::isprint(character))
    {
        throw std::runtime_error("Character is not ASCII");
    }
}

/// @brief This is the function to get the frequency of the characters
/// @return This will return the frequency of the characters
int LeafNode::getFrequency() const
{
    return frequency;
}

/// @brief This is the function to get the characters
/// @return This will return the characters
char LeafNode::getCharacter() const
{
    return character;
}