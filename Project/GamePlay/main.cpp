/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on April 26, 2015, 5:27 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int gamePly(char *,char *,int ,bool &);


int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    string name;
    const int SIZE = 26;
    char guesRay[SIZE];
    char wordRay[SIZE];
    int score[SIZE];
    int wordSiz;
    int gamPly = 0;
    bool finish = true;
    
    
    wordSiz = 3;
    wordRay[0] = 'W';
    wordRay[1] = 'I';
    wordRay[2] = 'N';
    do{
        
        cout<<"Finish is "<<finish<<endl;                                          //**
     
        score[gamPly] = gamePly(guesRay,wordRay,wordSiz,finish);
        gamPly++;
        if(gamPly == 9)
            finish = false;
    }while(finish == true);

    return 0;
}

int gamePly(char *gues,char *word,int siz, bool &fin){
    bool tr = true;
    char input;
    int score;
    int trys = 0;
    cout<<"Welcome to the wonderful world of Hang Man."<<endl;
    do{
        
        cout<<"Please enter the the letter you would like to try."<<endl;
        cout<<"Remember, you can enter the number 0 any time to quit."<<endl;
        cin>>input;
        if(isalpha(input)){
            if(islower(input))
                input = toupper(input);
            
        }
        if(input == 0){
            cout<<"You have entered 0, we will now exit the game."<<endl;
            fin = false;
            tr = false;
        }
        else
            cout<<"That is an invaild input, please try again.";
        if(tr = true){
            
        }
        trys++;
    }while(tr == true);
    
    return score;
    
    
}