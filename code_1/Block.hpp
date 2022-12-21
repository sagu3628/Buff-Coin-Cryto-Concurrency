#pragma once
#include<iostream>
#include <vector>
#include "Transaction.hpp"

using namespace std;

class Block {
private:
    long long nonce; // An arbitrary number crucial in mining

    string previousHash; // Hash of previous block
    time_t timestamp; // Time when mined 

    
public:
    Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash);
    vector<Transaction> transactions; //vector of transactions
    void setPreviousHash(string hash);
    string calculateHash();
    void mineBlock(unsigned int nDifficulty);
    int blockbal(string address);
    string toString();
    string getprev(Block tete);
    string hash; // Hash of this block
};

