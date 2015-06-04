/* 
 * File:   AbsDeck.h
 * Author: RR
 *
 * Created on May 13, 2015, 1:04 PM
 */

#ifndef ABSDECK_H
#define	ABSDECK_H

class AbsDeck{
    public:
        virtual void shuffle()=0;
        virtual int *deal()=0;
};

#endif	/* ABSDECK_H */

