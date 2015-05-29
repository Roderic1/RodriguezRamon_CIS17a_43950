/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 28, 2015, 6:29 PM
 */

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int SIZE = 100;         //Array size for sentences
    string senten[SIZE];    //Array for individual sentences
    string inFile;          //Name of file of incoming sentences
    string oFile;           //Name of file to write sentences
    fstream witFile;        //File string object: Input
    ostream outFile;        //File string object: Output
    
    //Get the file name
    cout<<"Enter in the name of the file you wish to open."<<endl;
    cin>>inFile;
    
    //Open the file
    witFile.open(infile.c_str(),ios::in);
    
    
    
    
    
    

    return 0;
}

