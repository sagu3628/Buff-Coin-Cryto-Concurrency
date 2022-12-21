#include <iostream>
#include "code_1/sha256.hpp"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    //cout << "you didn't include the correct number of aruments";
  //  https://www.geeksforgeeks.org/quick-way-check-characters-string/

    if(argc < 3){
        cout << "not enough arguments";
        return 0;
    }
    string randomword = argv[1];
    string input;
    string output1 = "3";
    int difficulty = (*argv[2]) - '0';
    int n  = 0;
    while(output1.find_first_not_of("0") < difficulty || n == 0){
       // cout << difficulty;
        input = randomword + std::to_string(n);
        output1 = sha256(input);
        cout << output1 << endl;
        n++;
    }

    cout << "sha256("<< randomword << "):" << output1 << endl;
    cout << "the value of n is "<< n-1 <<endl;
    cout << "the input was " << input << endl;
    return 0;
}