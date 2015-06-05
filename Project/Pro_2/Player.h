/* 
 * File:   Player.h
 * Author: rcc
 *
 * Created on June 5, 2015, 11:19 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    
    string name;
    
    void setName(string);
    string getName();
    

private:

};

#endif	/* PLAYER_H */

