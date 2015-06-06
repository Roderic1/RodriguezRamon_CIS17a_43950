

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
//        int ALPHA;//The amount of letters that the alphabet has

protected:

    string *hangman;
    
public:
    //Default constructor
    Hangman();
    //
    
    void displyHang(int r);
   
    ~Hangman();
};



#endif	/* HANGMAN_H */

