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
    char corcRay[siz] = {' ',' ',' '};
    int score;
    int trys = 0;
    int postion;
    int miss = 0;
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
                    gues[miss] = input;
                    miss++;
                }
                else
                    corcRay[postion] = word[postion];
            }
            else{
                postion = linSearch(gues,miss,input);
                if(postion == -1){
                    postion = linSearch(word,siz,input);
                    if(postion == -1){
                    gues[miss] = input;
                    miss++;
                    }
                    else
                        corcRay[postion] = word[postion];
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
        if(tr == true){
            cout<<"NICE TRY!!"<<endl<<"    ";
            prntAry(corcRay,siz);
            
            prntAry(gues,miss);
            
            
            
        }
        trys++;
    }while(tr == true);
    
    return score;
    
    
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