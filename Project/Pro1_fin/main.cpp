/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 3, 2015, 10:29 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

#include "score.h"

void gameRules();
int getWord(Score * ,bool &);

void gamePly(Score *,int ,bool &);
void prntAry(char *,int);
int linSearch(char *,int ,char);
void disHagman(string *,int ,int);
void prntStruc(Score * ,int);
void displayGam(string ,int );
void prntAryS(string *,int);

//USER LIBRARIES



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
    Score *game = new Score;
    fstream dataFile;
 
    cout<<"Please enter your name for the game to start"<<endl;
    getline(cin,name);
    gameRules();
    dataFile.open("FinalScores.dat",ios::out|ios::binary);
    if(!dataFile){
        cout<<"error opening the write file";
    }
    do{
        game->numb = gamPly;
        wordSiz = getWord(game,finish);
        
        if(finish == false){
            for(int j = 0;j < 5;j++){
                game->word[j] = ' ';
            }
            game->score = -1;
        }
        else{
            gamePly(game,wordSiz,finish);
            if(gamPly == 9)
                finish = false;
        }
        gamPly++;
//        cout<<game->numb<<endl<<game->word<<endl<<game->corrc<<endl;
//        cout<<game->guess<<endl<<game->score<<endl;
        dataFile.write(reinterpret_cast<char *>(&game),sizeof(game));
    }while(finish == true);
    dataFile.close();
    delete [] game;
//    displayGam(name,gamPly);
    

    return 0;
}

void displayGam(string na ,int plys){
    fstream dataF;
    Score *gam = new Score;
    dataF.open("FinalScores.dat",ios::in|ios::binary);
    
    cout<<"Congrats: "<<na<<endl;
    if(!dataF){
        cout<<"Error opening File";
    }
    for(int j = 0;j < plys;j++){
        dataF.read(reinterpret_cast<char *>(&gam),sizeof(gam));    
    
        if(plys == 1){
            cout<<"Sorry but our records show you didn't play any games"<<endl;
            cout<<"To play, please run the program again."<<endl;
            cout<<"Good luck :)";
        }
        else{
            cout<<"Game: "<<gam->numb + 1<<endl;
            if(gam->score == 0){
                cout<<"Congrats, you won this game"<<endl;
                cout<<"The word was "<<gam->word<<endl;
            }
            else if(gam->score == -1)
                cout<<"You quit this game, therefore you lost."<<endl;
            else{
            cout<<"Sorry but you got all the letters incorrect."<<endl;
            cout<<"The Correct word was "<<gam->word<<endl;
            }  
        }
    }
    dataF.close();
    delete [] gam;
}

void gamePly(Score *a,int siz, bool &fin){
    const int SIZE = 10;
    bool tr = true;
    char input;
    int score = -1;
    int trys = 0;
    int postion;
    int miss = 0;
    int correct = 0;
    string hangman[SIZE];
    ifstream inputFile;
    int j = 0;
    
    inputFile.open("hangman.txt");
    while(inputFile >> hangman[j]){
        j++;
    }
    inputFile.close();
    cout<<"Welcome to the wonderful world of Hang Man."<<endl;
    do{
        
        cout<<"Please enter the the letter you would like to try."<<endl;
        cout<<"Remember, you can enter the number 0 any time to quit."<<endl;
        cin>>input;
        if(isalpha(input)){
            if(islower(input))
                input = toupper(input);
            if(trys == 0){
                postion = linSearch(a->word,siz,input);
                if(postion == -1){
                    cout<<"Sorry that letter is incorrect"<<endl;
                    a->guess[miss] = input;
                    miss++;
                }
                else{
                    a->corrc[postion] = a->word[postion];
                    cout<<"Yes, that is one of the letters of the word"<<endl;
                    correct++;
                }
            }
            else{
                postion = linSearch(a->guess,miss,input);
                if(postion == -1){
                    postion = linSearch(a->corrc,siz,input);
                    if(postion == -1){
                        postion = linSearch(a->word,siz,input);
                        if(postion == -1){
                            cout<<"Sorry that letter is incorrect"<<endl;
                            a->guess[miss] = input;
                            miss++;
                        }
                        else{
                            a->corrc[postion] = a->word[postion];
                            cout<<"Yes, that is one of the letters of the word"<<endl;
                            correct++;
                        }
                    }
                    else{
                        cout<<"I'm sorry, but you already guessed that letter";
                        cout<<" correctly.";
                    }  
                }
                else{
                    cout<<"Sorry but you've already used that letter.";
                }
            }    
        }
        else if(input == '0'){
            cout<<"You have entered 0, we will now exit the game."<<endl;
            fin = false;
            tr = false;
            cout<<"This should display"<<fin<<"and "<<tr<<endl;
        }
        else
            cout<<"That is an invaild input, please try again.";
        if(miss == 8){
            score = 8;
            cout<<"Sorry, but you've missed too many letter. :("<<endl;
            cout<<"Better luck next time";
            disHagman(hangman,SIZE,miss);
            cout<<"The correct word was ";
            prntAry(a->word,siz);
            tr = false;
        }
        if(correct == siz){
            cout<<"Congratulations!! You've won this game!!";
            disHagman(hangman,SIZE,miss);
            prntAry(a->corrc,siz);
            prntAry(a->guess,miss);
            tr = false;
            score = 0;
        }
        if(tr == true && miss > 0){
            cout<<"NICE TRY!!";
            disHagman(hangman,SIZE,miss);
            prntAry(a->corrc,siz);
            prntAry(a->guess,miss);
        }
        trys++;
    }while(tr == true);
    
    a->score = score;
}

void disHagman(string *hangMan,int SIZE,int a){
    int perLine = 3;
    int i = 0;
    
    cout<<endl;
    for(i;i<3 && i<a;i++){
        cout<<"   "<<hangMan[i]<<endl;
    }
    if(a>3){
        cout<<"  ";
        for(i;i<6 && i<a;i++){
            cout<<hangMan[i];
            if(i%perLine==(perLine-1))cout<<endl;
        }
    }
    if(a>6){
        cout<<' ';
        for(i;i<a;i++){
            cout<<' '<<hangMan[i];
        }
    }
    cout<<endl<<endl;
}

void prntAry(char *a,int n){
    //Loop and print
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int linSearch(char *a,int size,char b){
    int index = 0;
    int postion = -1;
    bool found = false;
    
    while(index < size && !found){
        if(a[index] == b){
            found = true;
            postion = index;
        }
        index++;
    }
    return postion;
}

int getWord(Score *a,bool &fin){
    const int SIZE = 10;
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
    }while(num != true);
    //Open the file to get the word
    inputFile.open(fileName.c_str());
    while(inputFile >> canidate[i]){
        i++;
    }
//    prntAryS(canidate,i);                                                     
    selWord = rand()%90+10;selWord = selWord%10;                                           
    std::strcpy(a->word,canidate[selWord].c_str());
    //Close the file of the word list
    inputFile.close();
//    prntStruc(a,wordSiz);
    for(int j = 0;j < 5;j++){
        a->corrc[j] = ' ';
    }
    for(int k = 0;k < 10;k++){
        a->guess[k] = ' ';
    }
    
    
    return wordSiz;
}

void prntStruc(Score *a,int size){
    for(int i=0;i<size;i++){
        cout<<a->word[i]<<" ";
    }
    cout<<endl;
}

void gameRules(){
    cout<<"Welcome to the wonderful world of Hangman."<< endl;
    cout<<"You will be able to select games with 3 or 5 letter words"<<endl;
    cout<<"Once you begin, you will be able to play up to 10 consecutive games";
    cout<<endl<<"You can enter the number 0 at any point in the game to exit\n";
}

void prntAryS(string *a,int n){
    //Loop and print
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
