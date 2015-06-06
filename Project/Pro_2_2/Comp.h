/* 
 * File:   Comp.h
 * Author: rcc
 *
 * Created on June 5, 2015, 10:22 AM
 */

#ifndef COMP_H
#define	COMP_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

#include "Player.h"

using namespace std;

class Comp:public Player{
private:
    int ALPHA;
    char *list;
protected:
    char *word;
    char *correc;
    char *guess;
    int wordSize;
    
public:
    //Constructor
    Comp();
    
    Comp(int i);
    
    void getSize(int i);
    
    int linSearch(char b);
    
    void playOn();
    
    void prntAry(int n);
    
    template <class T>
    void Comp<T>::prntAry(T *a,int n){
    //Loop and print
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
};




#endif	/* COMP_H */

