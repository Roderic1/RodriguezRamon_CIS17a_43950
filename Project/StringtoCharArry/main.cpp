/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 3, 2015, 8:38 PM
 */

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void prntAry(string *,int);

int main(int argc, char** argv) {
    const int SIZE = 20;
    ifstream inputFile;
    string words[SIZE];
//    char with[4];
    int j;
    int ran = 3;
    int length = 3;
    char *with= new char[length +1];
    inputFile.open("3word.txt");
    while(inputFile >> words[j]){
        j++;
    }
//    for(int i = 0; i <3;i++){
//        inputFile >> with[i];
//    }
    std::strcpy(with, words[ran].c_str());
    prntAry(words,SIZE);
    inputFile.close();
    cout<<"print out the new letters";
    cout<<with[0]<<with[1]<<with[2];
    delete with;

    return 0;
}

void prntAry(string *a,int n){
    //Loop and print
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
