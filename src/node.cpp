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

/// @brief This is the constructor for the Node class
Node::Node(int timeStamp) : timeStamp(timeStamp)
{

}

/// @brief This is the method to get the time stamp
/// @return This will return the time stamp or throw an error if it is negative
int Node::getTimeStamp() const
{
    if (timeStamp < 0)
    {
        throw runtime_error("Time stamp is negative");
    }

    return timeStamp;
}