/**
 * @file node.cpp
 * @author Adrian Goessl
 * @brief This file contains the implementation of the Node class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#include "../src/include/node.h"

using namespace normalNode;
using namespace std;

Node::Node(int timeStamp) : timeStamp(timeStamp)
{
}

int Node::getTimeStamp() const
{
    if (timeStamp < 0)
    {
        throw runtime_error("Time stamp is negative");
    }

    return timeStamp;
}