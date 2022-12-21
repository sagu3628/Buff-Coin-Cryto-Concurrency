#include <iostream>
#include <fstream>
#include "Blockchain.hpp"
#include "Block.hpp"
#include "sha256.hpp"
#include "Transaction.hpp"
using namespace std;
int main(){
    Blockchain buffCUoin;

    while (true){
        //int option;
        string inputline;
        cout << "=====Main Menu=====" << endl;
        cout << "1. Add a transaction" << endl;
        cout << "2. Verify Blockchain " << endl;
        cout << "3. Mine pending transaction" << endl;
        cout << "4. Print transations" << endl;
        cout << "5. quit" << endl;
        getline(cin,inputline);
        if(inputline == "1"){
            string src = "";
            string dst = "";
            string coins = "";
            cout << "who is making the transaction" << endl;
            getline(cin,src);
            cout << "who is the transaction being payed to" << endl;
            getline(cin,src);
            cout << "how much is being payed" << endl;
            getline(cin,coins);
            buffCUoin.addTransaction(src,dst, stoi(coins));
        } else if(inputline == "2") {
            buffCUoin.isChainValid();
        } else if(inputline == "3"){
            cout << "who is mining" << endl;
            string miner;
            getline(cin, miner);
            buffCUoin.minePendingTransactions(miner);
        } else if(inputline == "4"){
            buffCUoin.prettyPrint();
        } else if(inputline == "5") {
            break;
        } else {
           cout << "invalid input."
        }

    }
}