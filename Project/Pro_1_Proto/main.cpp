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

void gameRules();
int getWord(char *,int ,bool &);

int gamePly(char *,char *,int ,bool &);
void prntAry(char *,int);
int linSearch(char *,int ,char);
void disHagman(string *,int ,int);

void displayGam(string ,int ,int *);
void prntAryS(string *,int);


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
        if(finish == true){
            score[gamPly] = gamePly(guesRay,wordRay,wordSiz,finish);
            gamPly++;
            if(gamPly == 9)
                finish = false;
        }
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
            cout<<"Game: "<<i+1<<endl;
            if(sco[i] == 0)
                cout<<"Congrats, you won this game"<<endl;
            else if(sco[i] == -1)
                cout<<"You quit this game, therefore you lost."<<endl;
            else
                cout<<"Sorry but you got all the letters incorrect."<<endl;
        }
    }
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
            score = 8;
            cout<<"Sorry, but you've missed too many letter. :("<<endl;
            cout<<"Better luck next time";
            disHagman(hangman,SIZE,miss);
            cout<<"The correct word was ";
            prntAry(word,siz);
            tr = false;
        }
        if(correct == siz){
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
    }while(num != true);
    //Open the file to get the word
    inputFile.open(fileName.c_str());
    while(inputFile >> canidate[i]){
        i++;
    }
//    prntAryS(canidate,i);                                                     
    selWord = rand()%90+10;selWord = selWord%10;                                           
    std::strcpy(word,canidate[selWord].c_str());
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

void prntAryS(string *a,int n){
    //Loop and print
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
