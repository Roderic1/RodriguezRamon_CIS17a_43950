/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 14, 2015, 5:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Date.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    Date neu;
    int num;
    
    cout<<"What is the month?"<<endl;
    cin>>num;
    neu.getMonth(num);
    cout<<"What day of the month is it?"<<endl;
    cin>>num;
    neu.getDay(num);
    cout<<"What year is it?"<<endl;
    cin>>num;
    neu.getYear(num);
    
    neu.dateInts();
    neu.dateStan();
//    neu.dateAmer();
 
    return 0;
}

