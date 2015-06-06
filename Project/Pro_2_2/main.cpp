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

//#include "Hangman.h"
#include "User.h"
#include "Comp.h"
#include "score.h"

void gameRules();
void displayGam(string na ,int plys);
//int linSearch(char *a,int size,char b)


int main(int argc, char** argv) {
    User stu;
    Comp ab3;
    Score wins;
//    Hangman game;
    string ab;
    
    int woSz;//WordSize
    bool finish = true;
    int gamPlys = 0;
    
    wins.numb = 0;
    
    cout<<"Please enter your name for the game to start"<<endl;
    getline(cin,ab);
    stu.setN(ab);
    gameRules();
    
    do{
        woSz = stu.getWord(finish);
        if(finish = false){
            wins.score[gamPlys] = -1;
        }
        else{
            ab3(woSz);
        }
        
    }while(finish == true);

    return 0;
}

void gameRules(){
    cout<<"Welcome to the wonderful world of Hangman."<< endl;
    cout<<"You will be able to select games with 3 or 5 letter words"<<endl;
    cout<<"Once you begin, you will be able to play up to 10 consecutive games";
    cout<<endl<<"You can enter the number 0 at any point in the game to exit\n";
}

void displayGam(Score gam ,int plys){
    
    
    for(int j = 0;j < plys;j++){    
    
        if(plys == 1){
            cout<<"Sorry but our records show you didn't play any games"<<endl;
            cout<<"To play, please run the program again."<<endl;
            cout<<"Good luck :)";
        }
        else{
            cout<<"Game: "<<gam->numb + 1<<endl;
            if(gam->score == 0){
                cout<<"Congrats, you won this game"<<endl;
            }
            else if(gam->score == -1)
                cout<<"You quit this game, therefore you lost."<<endl;
            else{
            cout<<"Sorry but you got all the letters incorrect."<<endl;
            }  
        }
    }
}

