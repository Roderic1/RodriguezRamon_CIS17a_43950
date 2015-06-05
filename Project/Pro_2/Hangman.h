/* 
 * File:   Hangman.h
 * Author: rcc
 *
 * Created on June 4, 2015, 6:18 PM
 */

#ifndef HANGMAN_H
#define	HANGMAN_H

class Hangman{
public:
        int ALPHA;//The amount of letters that the alphabet has

protected:
    int wordNum;//How many letter word
    char word[wordNum];//The word that the user is trying to find
    char corrc[wordNum];//The correct guesses that a user enters
    char guess[ALPHA];
    
    //Default constructor
    Hangman();
    
    
};



#endif	/* HANGMAN_H */

