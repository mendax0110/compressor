/**
 * @file compare.h
 * @author Adrian Goessl
 * @brief This file contains the declaration of the Compare class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#ifndef COMPARE_H
#define COMPARE_H

#include <iostream>

#include "node.h"
#include "leafNode.h"
#include "rootNode.h"

namespace compare
{
    class Compare
    {
    public:
        explicit Compare();
        virtual ~Compare() = default;

        bool operator()(const normalNode::Node* a, const normalNode::Node* b) const;
    };
}

#endif // COMPARE_H