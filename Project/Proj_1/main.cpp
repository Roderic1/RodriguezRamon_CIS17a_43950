/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on April 26, 2015, 2:03 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

void gameRules();
int getWord(char *,int ,bool &);
void prntAryC(char *,int);

void displayGam(string ,int ,int *);

void prntAry(string *,int);
/*
 * 
 */
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
    
    
    cout<<"Please enter your name for the game to start"<<endl;
    getline(cin,name);
    gameRules();
    do{
        wordSiz = getWord(wordRay,SIZE,finish);
        cout<<"Finish is "<<finish<<endl;                                          //**
     
        gamPly++;
        if(gamPly == 9)
            finish = false;
    }while(finish == true);
    

    displayGam(name,gamPly,score);
    return 0;
}

void displayGam(string na ,int gam,int *sco){
    cout<<"Congrats: "<<na<<endl;
    if(gam == 0){
        cout<<"Sorry but our records show you didn't play any games"<<endl;
        cout<<"To play, please run the program again."<<endl;
        cout<<"Good luck :)";
    }
    else{
        for(int i = 0; i < gam;i++){
            cout<<"Game: "<<i+1;
            if(sco[i] == 0)
                cout<<"Congrats, you won this game";
            else if(sco[i] == -1)
                cout<<"You quit this game, therefore you lost.";
            else
                cout<<"You got "<<sco[i]<<" letters correct.";
        }
    }
}




int getWord(char *word,int SIZE,bool &fin){
    ifstream inputFile;
    string fileName;
    string canidate[SIZE];
    bool num = true;
    int wordSiz;
    int i = 0;
    int selWord;
    do{
        cout<<"Would you like a 3 or 5 letter word?"<<endl;
        cin>>wordSiz;
        switch(wordSiz){
            case 3: fileName = "3word.txt";
                    num = true;
                    break;
            case 5: fileName = "5word.txt";
                    num = true;
                    break;
            case 0: fin = false;
                    num = true;
                    break;
            default: cout<<"That is an invalid entry, please try again";
                     num = false;
        }
        cout<<"Fin is "<<fin<<endl;
    }while(num != true);
    //Open the file to get the word
    inputFile.open(fileName.c_str());
    while(inputFile >> canidate[i]){
        i++;
    }
    prntAry(canidate,i);                                                      //**
    selWord = rand()%90+10;
    cout<<"Random";
    cout<<"hte number is "<<selWord<<endl;                                                            //**
    selWord = selWord%10;
    cout<<"try "<<selWord;                                                            //**
    std::strcpy(word,canidate[selWord].c_str());
    prntAryC(word,wordSiz);
    
    //Close the file of the word list
    inputFile.close();
    return wordSiz;
}

void gameRules(){
    cout<<"Welcome to the wonderful world of Hangman."<< endl;
    cout<<"You will be able to select games with 3 or 5 letter words"<<endl;
    cout<<"Once you begin, you will be able to play up to 10 consecutive games";
    cout<<endl<<"You can enter the number 0 at any point in the game to exit\n";
}

void prntAry(string *a,int n){
    //Loop and print
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void prntAryC(char *a,int n){
    //Loop and print
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}