
# Huffcode

This repo conaints my soltuion to the CS411 Homework assignment 6. This exercise was to create a Huffman encoding and decoding class.

## The Problem

In this exercise, you will implement Huffman coding. Given character
weights, your package will be able to construct a Huffman code, which it
can then use to encode and decode strings.

## Skeleton 

This exercise was started with a skeleton file and test program that was provided by Prof. Hartman. 

## Testing

Testing suite was provided by Prof. Hartman.

## Interesting Problems

One of the tests that gave me some issues was the single character maping and single character decoding. I was able to do some searching and find a quite informatative stackoverflow [post](https://stackoverflow.com/questions/22429854/huffman-code-for-a-single-character#:~:text=Huffman%20is%20meant%20to%20produce,no%20information%20except%20its%20length.)  
which stated the following "Huffman is meant to produce a minimal-length sequence of bits that contains all the information in the original sequence of symbols, assuming that the decoder already knows the set of symbols. If there's only one symbol, the input data contains no information except its length.

In Huffman-based data formats, length is usually encoded separately, not as part of the Huffman-encoded bit sequence itself. The decoder of a single-symbol Huffman code therefore has all the information it needs to reconstruct the input without needing to read anything from the Huffman-encoded bit sequence. it is logical, then, that the Huffman encoder's output should be 0 bits long.

If you don't have a length encoded separately, then you must have a symbol to represent End Of Sequence so the decoder knows when to stop reading. Then your Huffman tree will have 2 nodes and you won't run into this special case." 

My solution was to create the special case in the setWeights function to handle this issue. I think utilizing an end of sequence would be more elegant but this was my first thought on solving the issue.  

## Method  

The main method I utilized was a std::priority_queue and a node struct that handled the key, weights, child node pointers. This Node struct was made utilizing std::shared pointers and is defined in the "huffcode.hpp"

## Members 

The huffcode class contains two private members and 4 public functions.

### Private

The private data memebers are the Node _root and the std::unordered_map<char, std::string> _encodeMap.  
The _root node represents the complete huffman code tree.  
The _encodeMap contains the map required for encoding.

### Public  

The Public functions for this class are defined as

``void setWeights(const std::unordered_map<char, int> &);``    
``std::string encode(const std::string &) const;``  
``std::string decode(const std::string &) const;``    
``void codes_map(Node &, const std::string &);``    

``setWeights`` handles the creation of the huffman tree by building a priority queue that is weight based on the int from the unordered_map. Which then builds nodes out for the huffman code tree utilizing the helper function  
``codes_map`` to add keys and codes to each node.  

``encode`` && ``decode`` provide methods to encode and decode a string based on the huffman code tree that has been created. 

## Usage 

This class can be used in the following way.

    HuffCode h;
    std::unordered_map<char, int> w;
    w['a'] = 2;
    w['b'] = 20;
    w['c'] = 3;
    w['d'] = 8;
    w['e'] = 12;
    w['f'] = 3;
    w['g'] = 8;
    w['h'] = 2;
    w['i'] = 7;
    w['j'] = 5;
    h.setWeights(w);
    h.encode(text);
    h.decode(encodedtext);
    
## Usefull Resources
 
- Geeks for geeks [post](https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/) on huffman codes  
- cpp reference [page](https://en.cppreference.com/w/cpp/container/priority_queue) on priority_queue. 
