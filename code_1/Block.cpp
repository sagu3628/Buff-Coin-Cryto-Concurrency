#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash){
    // TODO
    previousHash = _previousHash;
    
}

string Block::calculateHash() {
    // TODO
    string ret;
    for(int i = 0; i < transactions.size(); i++){
       Transaction blocks = transactions[i];
        ret = blocks.toString();
    }
    ret = ret+previousHash;
    ret = ret + toString();
    string retrunme = sha256(ret);

    
    return retrunme;
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
    // add the time when the miner finished mining to the function

    string output1 = calculateHash();

    while(output1.find_first_not_of("0") < difficulty){ // if the difficulty is 0 we don't need to brute force it
        nonce++;
        output1 = calculateHash();
    }

hash = output1;

}

string Block::toString() {
    // TODO
    stringstream temp;
    temp<< "(" << timestamp <<"," <<nonce;
   // ss << "(" << sender <<", " << receiver << ", " << amount << ")";
    return temp.str();
}
int Block::blockbal(string address){
    int bal = 0;
    for (int i = 0; i <transactions.size(); i++) {
        if(transactions[i].getSender() == address){
            bal = bal - transactions[i].getAmount();
        }
        else if(transactions[i].getReceiver() == address){
            bal = bal + transactions[i].getAmount();
        }
    }
    return bal;
}

string Block::getprev(Block tete){
    return tete.previousHash;
}