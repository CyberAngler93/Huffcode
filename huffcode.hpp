// huffcode.hpp
// Created on 11/29/20
// Matt Perry
// Last Modified on 11/29/20
// For CS 411 Fall 2020
// Header file for class HuffCode for HW6

#ifndef HUFFCODE_HUFFCODE_HPP
#define HUFFCODE_HUFFCODE_HPP
#include <sstream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

struct Node {
    Node() {}
    Node(char key, int weight) : _key(key), _weight(weight) {}
    Node(const std::shared_ptr<Node> & lhs, const std::shared_ptr<Node> & rhs, int weight) :
            _leftNode(lhs),
            _rightNode(rhs),
            _key(0),
            _weight(weight)
    {}

    std::shared_ptr<Node> _leftNode,_rightNode = nullptr;
    char _key = 0;
    int _weight = 0;
};

// Class HuffCode
// Encoding & decoding using a Huffman code
class HuffCode {

// ***** HuffCode: ctors, dctor, op= *****
public:

    // Compiler-generated default ctor, copy ctor, copy =, dctor used

// ***** HuffCode: general public functions *****
public:

    void setWeights(const std::unordered_map<char, int> &);
    std::string encode(const std::string &) const;
    std::string decode(const std::string &) const;
    void codes_map(Node &, const std::string &);


// ***** HuffCode: data members *****
private:
    Node _root;
    std::unordered_map<char, std::string> _encodeMap;

};  // End class HuffCode
#endif //HUFFCODE_HUFFCODE_HPP
