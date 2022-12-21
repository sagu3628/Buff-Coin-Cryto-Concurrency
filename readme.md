# CSCI 2270 – Data Structures - Final Project 

Start by carefully reading the write-up contained in `CSCI2270_Spring22_Project.pdf`.

Please include a thorough description of your program's functionality. Imagine that you are publishing this for users who know nothing about this project. Also, include the names of the team-members/authors.

Saulo Guzman , Noah Garrett

Background
We creating a blockchain with using block, and a blockchain class. Each Block which is held in a vector, will have a trancation vector, preivous hash of the last block, and a timestamp. By calling funcation in the blockchain, we can create of system of mining and adding toward the blockchain to make buffcoin.
 
 
Functions for Block cpp
 
SetPreviousHash:: It takes a parameter as a string of a hash value of the previous block, and attaches it to the new block.
 
CalculateHash:: By going inside the Transaction vector in order to compress all the item into stringstream, we did the same to timestamp, and the previous hash, where we hash it to one string value.
 
mineBlock::There needs to be a specific type of hash value string that we want. By using difficulty to determine how many zero we want in front of the hash string, we keep hashing the value to get the right string. Inorder to change the hash value, we increment the nonces to and call calculateHash with a new hash value. Then we set equal to the hash that is public to the block when conditions are met.
 
ToString:: It will take all the private data members from the block class and convert it to a string to be hash.
 
BlockBal:: This function is called during the PendingMineTrancation in which it will take in the address of the parameter. The will be going to all the transactions in that block, it would check whether the address is a sender or receiver. Then it would do the calculation toward the balance depending if it a receiver or sender.
 
getprev:: It will give us access to previous hash value
 
/////////////////////////////////////
 
BlockChain Function 
 
minePendingTransactions::This function will do the process of mining. Mining is the process of inserting a block in the blockchain, as long as it meets certain specifications. It would use another vector call pending transitions , and then create a new block. Then it would call mineblock, which is where the new block will have its hash, previous block of hash value, and timestamp.
 
IsChainValue::This function will traverse each block to double check if the previous hash of the block is the same as the last block hash. It will also examine the hash value string to see if the difficulty match with the amount of zero.
 
getBalanceOfAddress::This will go through all the blocks and look through each transition of sender and receiver to compare with the address. If it is a sender, then it will take money away since it is in debt. If it is a receiver, then money would be added to their balance as what they gain. By gaining the total of sender and receiver, to show the balance of the person.
 
addTransaction:: By getting access to their balances with getBalance, we can add transactions and determine if the mine was accomplished.
 
prettyPrint::Print out the block chain in fashion showing all the previous transactions.





