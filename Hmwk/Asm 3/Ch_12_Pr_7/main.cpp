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
    ofstream outFile;       //File string object: Output
    char ch;                //Character to transfer everything over
    
    //Get the file name
    cout<<"Enter in the name of the file you wish to open."<<endl;
    cin>>inFile;
    
    //Open the file
    
    cout<<inFile;
    
    
    cin.ignore();
    
    //Get the output file name
    cout<<"Enter in the name of the file to input the information."<<endl;
    cin>>oFile;
    cin.ignore();
    cout<<"now transfering.";
    
    witFile.open(inFile.c_str(),ios::in);
    outFile.open(oFile.c_str(),ios::out);
    
    //If the file is successfully opened, continue
    if(witFile){
        witFile.get(ch);
        while(witFile){
            if(ch == '.'){
                outFile.put(ch);
                outFile.put('n');
            }
            else
                outFile.put(ch);
        }
        
    }
    else
        cout<<"The in file was unable to open";
    
    
    cout<<"Transfer is complete";
    
    
    //Close the files
    witFile.close();
    outFile.close();

    return 0;
}

