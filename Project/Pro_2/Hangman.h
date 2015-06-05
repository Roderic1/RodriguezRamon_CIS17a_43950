

#ifndef HANGMAN_H
#define	HANGMAN_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

class Hangman{
private:
public:
        int ALPHA;//The amount of letters that the alphabet has

protected:

    int wordNum;//How many letter word
    char *word(int);//The word that the user is trying to find
    char *corrc;//The correct guesses that a user enters
    char *guess;//All the incorrrect guesses of the player
    
    
    //Default constructor
    Hangman();
    //
    
    Hangman(int );
   
    
};



#endif	/* HANGMAN_H */

