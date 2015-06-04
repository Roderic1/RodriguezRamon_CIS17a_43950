/* 
 * File:   BaseDeck.h
 * Author: RR
 *
 * Created on May 13, 2015, 1:21 PM
 */

#ifndef BASEDECK_H
#define	BASEDECK_H

class BaseDeck{
    private:
        int place;
        int *cards;
        int size;
    public:
        BaseDeck();
        ~BaseDeck(){delete []cards};
        void shuffle();
        int *deal;
};


#endif	/* BASEDECK_H */

