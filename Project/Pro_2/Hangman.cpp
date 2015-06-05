#include <bitset>

#include "Hangman.h"


Hangman::Hangman(){
    ALPHA = 26;
    wordNum = 0;
}

Hangman::Hangman(string a){
    Hangman.player = a;
}

Hangman(int i){
    //new *word = 10;
}

void Hangman::setName(string n){
    player = n;
}

string Hangman::getName(){
        return player;
}