


#include "Card.h"

Card::Card(int){
    if(n>=0&&n<){
        num=n;
    }
    else{
        num=0;
    }
    
}
char Card::suit(){
    if(num<13)return 'S';
    if(num<26)return 'D';
    if(num<39)return 'C';
    else 'H';
            
        }
char Card::face(){
    static char facVal[14]="A23456789TJQK";
    return facVal[num%13];
            
        }
int Card::value(){
    if(num%13>=9)return 10;
    if(num&13==0)return 11;
    
    
            
        }
