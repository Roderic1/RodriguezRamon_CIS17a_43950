
#include "Hangman.h"


Hangman::Hangman(){
    hangman = new string[10];
    ifstream inputFile;
    int j;
    inputFile.open("hangman.txt");
    while(inputFile >> hangman[j]){
        j++;
    }
    inputFile.close();
    
}

void Hangman::displyHang(int a){
    int perLine = 3;
    int i = 0;
    
    cout<<endl;
    for(i;i<3 && i<a;i++){
        cout<<"   "<<hangman[i]<<endl;
    }
    if(a>3){
        cout<<"  ";
        for(i;i<6 && i<a;i++){
            cout<<hangman[i];
            if(i%perLine==(perLine-1))cout<<endl;
        }
    }
    if(a>6){
        cout<<' ';
        for(i;i<a;i++){
            cout<<' '<<hangman[i];
        }
    }
    cout<<endl<<endl;
}



Hangman::~Hangman(){
    delete [] hangman;
}