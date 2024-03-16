/**
 * @file compare.cpp
 * @author Adrian Goessl
 * @brief This file contains the implementation of the Compare class
 * @version 0.1
 * @date 2024-02-25
 * 
 * @copyright MIT 2024
 * 
 */
#include "../src/include/compare.h"

using namespace compare;


/// @brief Simple constructor
Compare::Compare()
{

}

/// @brief This function is the operator, which gets the frequency of the nodes
/// @param a This is the first node
/// @param b This is the second node
/// @return This will return the result of the comparison
bool Compare::operator()(const normalNode::Node* a, const normalNode::Node* b) const
{
    int freqA = a->getFrequency();
    int freqB = b->getFrequency();

    return (freqA != freqB) ? (freqA > freqB) : (a->getTimeStamp() > b->getTimeStamp());
}

