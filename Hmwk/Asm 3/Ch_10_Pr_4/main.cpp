/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 18, 2015, 6:19 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int letCount(char *,int);

int main(int argc, char** argv) {
    const int SIZE = 100;
    char phrase[SIZE];
    int avg;
    
    cout<<"Enter a pharse, the average amount of letters in each word"<<endl
            <<"will be displayed.    ";
    cin.ignore();
    cout<<"here  ";
    cin.ignore();
    cin.getline(phrase, SIZE);
//    cin.ignore(5,'\n');
    cout<<"this is probable good";
    
    avg = letCount(phrase,SIZE);
    cout<<"The average amount of letters in each word of this phrase is :"<<avg;

    return 0;
}

int letCount(char *ph,int siz){
    int length[siz];
    int word = 0;
    
    while(*ph != '\0'){
        int let = 0;
        while(*ph != ' '){
            if(isalpha(*ph))
                let++;
        }
        length[word] = let;
        cout<<length[word];
        word++;
    }
    cout<<"This is ";
}

