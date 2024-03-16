/**
 * @file rootNode.h
 * @author Adrian Goessl
 * @brief This file contains the declaration of the RootNode class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#ifndef ROOTNODE_H
#define ROOTNODE_H

#include <iostream>
#include "node.h"

/// @brief Namespace for the root node \namespace rootNode
namespace rootNode
{
    /// @brief This class represents a root node, which inherits from the Node class \class Root
    class RootNode : public normalNode::Node
    {
    public:
        RootNode(int counter, normalNode::Node* left, normalNode::Node* right);
        RootNode(int counter, normalNode::Node* left, normalNode::Node* right, int timeStamp);
        virtual ~RootNode() = default;

        normalNode::Node* left;
        normalNode::Node* right;

        int getFrequency() const;
    private:
        int counter;
    };
}

#endif // ROOTNODE_H