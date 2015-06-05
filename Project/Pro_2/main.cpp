/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on June 4, 2015, 6:14 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

#include "Hangman.h"
#include "User.h"
#include "Comp.h"
#include "score.h"

void gameRules();


int main(int argc, char** argv) {
    User stu;
    Comp a1;
    Score wins;
    Hangman game;
    
    wins.numb = 0;
    
    cout<<"Please enter your name for the game to start"<<endl;
    getline(cin,stu.player);
    gameRules();

    return 0;
}

void gameRules(){
    cout<<"Welcome to the wonderful world of Hangman."<< endl;
    cout<<"You will be able to select games with 3 or 5 letter words"<<endl;
    cout<<"Once you begin, you will be able to play up to 10 consecutive games";
    cout<<endl<<"You can enter the number 0 at any point in the game to exit\n";
}

