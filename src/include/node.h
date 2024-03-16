/**
 * @file node.h
 * @author Adrian Goessl
 * @brief This file contains the declaration of the Node class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>

/// @brief Namespace for the normal node \namespace normalNode
namespace normalNode
{
    /// @brief This class represents a node \class Node
    class Node
    {
    public:
        Node(int timeStamp);
        virtual ~Node() = default;

        virtual int getFrequency() const = 0;
        int getTimeStamp() const;
    private:
        int timeStamp;
    };
}


#endif // NODE_H