/**
 * @file leafNode.h
 * @author Adrian Goessl
 * @brief This file contains the declaration of the LeafNode class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#ifndef LEAFNODE_H
#define LEAFNODE_H

#include <iostream>

#include "node.h"

/// @brief Namespace for the leaf node \namespace leafNode
namespace leafNode
{
    /// @brief This class represents a leaf node, which inherits from the Node class \class LeafNode
    class LeafNode : public normalNode::Node
    {
    public:
        LeafNode(char character, int frequency);
        virtual ~LeafNode() = default;

        int getFrequency() const override;
        char getCharacter() const;
    private:
        char character;
        int frequency;
    };
}

#endif // LEAFNODE_H