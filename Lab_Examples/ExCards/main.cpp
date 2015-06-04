/* 
 * File:   main.cpp
 * Author: RR
 *
 * Created on May 13, 2015, 12:56 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

//System Libraries
#include "Card.h
#include "BaseDeck.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
//    for(int i = 0;i<52;i++){
//    Card card(i);
//    cout<<card.face()<<

    
    BaseDeck deck;
    
    deck.shuffle();
    
    int hand=deck.deal();
    
    for(int card = 0;card<52;card++)(
            Card a(hand[card]):
            cout<<a.face()<<"  "<<a.suit()<<)
    return 0;
}

