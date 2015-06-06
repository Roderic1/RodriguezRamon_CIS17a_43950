#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>


#ifndef USER_H
#define	USER_H
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

#include "Player.h"

class User : Player{
public:
    char *word;
    char *corrc;
    char *guess;
    int sizWord;
    string *hangman;
    User();
    
    void setN(string a);
    
    int getWord(bool &fin);
    
    void PlayOn();
    
    int linSearch(char b);        
};

#endif	/* USER_H */

