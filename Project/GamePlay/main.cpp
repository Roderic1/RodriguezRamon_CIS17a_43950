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
void prntAry(char *,int);
int linSearch(char *,int ,char);
void disHagman(string *,int ,int);



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
    const int SIZE = 10;
    bool tr = true;
    char input;
    char corcRay[siz] = {' ',' ',' '};
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
                postion = linSearch(word,siz,input);
                if(postion == -1){
                    cout<<"Sorry that letter is incorrect"<<endl;
                    gues[miss] = input;
                    miss++;
                }
                else{
                    corcRay[postion] = word[postion];
                    cout<<"Yes, that is one of the letters of the word"<<endl;
                    correct++;
                }
            }
            else{
                postion = linSearch(gues,miss,input);
                if(postion == -1){
                    postion = linSearch(corcRay,siz,input);
                    if(postion == -1){
                        postion = linSearch(word,siz,input);
                        if(postion == -1){
                            cout<<"Sorry that letter is incorrect"<<endl;
                            gues[miss] = input;
                            miss++;
                        }
                        else{
                            corcRay[postion] = word[postion];
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
            cout<<"Sorry, but you've missed too many letter. :("<<endl;
            cout<<"Better luck next time";
            disHagman(hangman,SIZE,miss);
            tr = false;
            score = 8;
        }
        if(correct == (siz-1)){
            cout<<"Congratulations!! You've won this game!!";
            disHagman(hangman,SIZE,miss);
            prntAry(corcRay,siz);
            prntAry(gues,miss);
            tr = false;
            score = 0;
        }
        if(tr == true && miss > 0){
            cout<<"NICE TRY!!";
            disHagman(hangman,SIZE,miss);
            prntAry(corcRay,siz);
            prntAry(gues,miss);
        }
        trys++;
    }while(tr == true);
    
    return score;
    
    
}

void disHagman(string *hangMan,int SIZE,int a){
    int perLine = 3;
    int i = 0;
//    const int SIZE = 10;
//    string hangMan[SIZE] = {"   |\n","   |\n","   O"," / ","|"," \","  /",
//    " \ "};
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
