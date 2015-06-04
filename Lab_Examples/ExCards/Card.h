/* 
 * File:   Card.h
 * Author: RR
 *
 * Created on May 13, 2015, 1:05 PM
 */

#ifndef CARD_H
#define	CARD_H

class Card{
    private:
        int num;
    public:
        Card(int);
        char suit();
        char face();
        int value();
};


#endif	/* CARD_H */

