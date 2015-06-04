/* 
 * File:   Date.h
 * Author: RR
 *
 * Created on May 14, 2015, 5:23 PM
 */

#ifndef DATE_H
#define	DATE_H
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class Date{
private:
    int month;
    int day;
    int year;
//    string mon[12];
public:
    void getDay(int);
    void getMonth(int);
    void getYear(int);
    string showMon();
    void dateInts();
    void dateStan();
    void dateAmer();
};


#endif	/* DATE_H */

