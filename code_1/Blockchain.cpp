#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO
    Transaction transaction(src,dst,coins);
    if(getBalanceOfAddress(src) >= coins || src == "BFC"){
        pending.push_back(transaction);
    } else{
        cout << "You don't have the balance to do this" << endl;
    }
//    cout << transaction.getAmount() << transaction.getSender() << transaction.getReceiver() << endl;

}

bool Blockchain::isChainValid() { 
    // TODO
    string hashTranfer;
    int len;
    int counter = 0;
    string pre;
    for(int i = 1; i < chain.size(); i++){
        pre = chain[i - 1].hash;
        if(pre != chain[i].getprev(chain[i])){
            cout<<"Hash of the previous block does not match"<<endl;
            return false;
        }
        hashTranfer = chain[i].hash;
        len = hashTranfer.length();
        for(int j = 0; j < len; j++){
            if(hashTranfer[i] == '0'){
                counter++;
                if(hashTranfer[i + 1] != '0'){
                    break;
                }
                continue;
            }
            break;
        }
        if(difficulty > counter){
            cout<<"Hash value does not have the right amount of zero"<<endl;
            return false; 
        }
        counter = 0;

    }
    cout<<"chain is valid"<<endl;
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    if(pending.empty()){
        return false; // there is no pending transactions to mine
    }

  string  previoushash = chain.back().hash;
    while(!pending.empty()) { // mines all the pending transaction

        Block block(pending, time(nullptr), previoushash);
        // ask a ta if this correct
        block.mineBlock(difficulty);
        chain.push_back(block);
        pending.pop_back();


    }
    addTransaction("BFC",minerAddress,miningReward);
    //todo figure out the reward for the minner


    //invoke the mineblock function of the class block, pass the difficult level
    // after successfull return, clear the list of pending transations
    // push the new block to the chain
    // To reward the minter address, add a new transation to the (now) empty list of pending transatinos
    // with scr = "BFC" dst = "mineraddress, and amount = mining reward"




    return true;
}



     //todo figure out the reward for the minner


    //invoke the mineblock function of the class block, pass the difficult level
    // after successfull return, clear the list of pending transations
    // push the new block to the chain
    // To reward the minter address, add a new transation to the (now) empty list of pending transatinos
    // with scr = "BFC" dst = "mineraddress, and amount = mining reward"






int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    int userbalance = 0;
    for (int i = 0; i <chain.size() ;i++) {
        userbalance = userbalance + chain[i].blockbal(address);
    }
    return userbalance;

}

void Blockchain::prettyPrint() {
    // TODO
    for (int i = 0; i <chain.size(); i++) {
        for (int j = 0; j <chain[i].transactions.size(); j++) {
            cout << chain[i].transactions[j].toString() << chain[i].hash << endl;
        }
    }
    cout << endl;
}