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

Compare::Compare()
{
}

bool Compare::operator()(const normalNode::Node* a, const normalNode::Node* b) const
{
    int freqA = a->getFrequency();
    int freqB = b->getFrequency();

    return (freqA != freqB) ? (freqA > freqB) : (a->getTimeStamp() > b->getTimeStamp());
}

