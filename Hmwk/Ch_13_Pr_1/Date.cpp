#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Date.h"
using namespace std;


void Date::getDay(int d){
    day = d;
}
void Date::getMonth(int m){
    month = m;
}
void Date::getYear(int y){
    year = y;
}

string Date::showMon(){
    static string mont[12]={"January","Febuary","March","April","May","June",
    "July","August","September","October","November","December"};
    
    return mont[month];
}
void Date::dateInts(){
    cout<<endl<<month<<'/'<<day<<'/'<<year<<endl;
}
void Date::dateStan(){
    cout<<"here?";
    string mo = showMon();
    cout<<"Standared"<<mo<<"  "<<day<<", "<<year<<endl;
}
//void Date::dateAmer(){
//    Date a;
//    cout<<"american"<<day<<"  "<<a.showMon()<<" "<<year<<endl;
//}