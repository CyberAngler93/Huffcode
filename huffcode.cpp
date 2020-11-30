
// huffcode.cpp  UNFINISHED
// Glenn G. Chappell
// 29 Nov 2015
//
// For CS 411/611 Fall 2015
// Assignment 6, Exercise A
// Source for class HuffCode
//
// Modified 11/22/17
// Chris Hartman
// For CS 411 Fall 2017
// Started on 11/29/20
// Last Modified on 11/30/20
// Matt Perry
// Based on skeleton file provided by Glenn Chappell and Chris Hartman
// For CS 411 Fall 2020

#include "huffcode.hpp"  // for class HuffCode declaration
#include <string>
#include <unordered_map>

void HuffCode::setWeights(const std::unordered_map<char, int> & the_weights)
{
    auto cmp = [&](const Node & lhs, const Node & rhs) {return lhs._weight > rhs._weight;};
    std::priority_queue<Node, std::vector<Node>, decltype(cmp)> weight_queue(cmp);
    for(auto & i : the_weights) {
        weight_queue.push(Node(i.first, i.second));
    }

    if (weight_queue.empty()) { return; }
    if (weight_queue.size() == 1){
        _root = weight_queue.top();
        codes_map(_root, "1");
        return;
    }
    while(weight_queue.size() != 1){
        auto left = weight_queue.top();
        weight_queue.pop();

        auto right = weight_queue.top();
        weight_queue.pop();

        Node new_root(std::make_shared<Node>(left), std::make_shared<Node>(right), left._weight + right._weight);
        weight_queue.push(new_root);
    }
    _root = weight_queue.top();
    codes_map(_root, "");
}


std::string HuffCode::encode(const std::string & text) const
{
    std::string encoding;
    for(auto letter:text) {
        encoding+=_encodeMap.find(letter)->second;
    }
    return encoding;
}


std::string HuffCode::decode(const std::string & code_str) const
{
    auto current_node = _root;
    auto code_str_pos = code_str.begin();
    std::ostringstream os;

    while(code_str_pos != code_str.end()) {
        if((*code_str_pos) == '0'){
            current_node = *current_node._leftNode;
            code_str_pos++;
        }
        else if ((*code_str_pos) == '1') {
            current_node = *current_node._rightNode;
            code_str_pos++;
        }
        if(current_node._key != 0 ) {
            os << current_node._key;
            current_node = _root;
            continue;
        }

    }
    return os.str();
}

void HuffCode::codes_map(Node & node, const std::string & code) {
    if (node._weight > 0) {
        if(node._key == 0 ) {
            codes_map(*(node._leftNode), code + "0");
            codes_map(*(node._rightNode), code + "1");
        }
        else {
            _encodeMap.insert({node._key, code });
        }
    }
}