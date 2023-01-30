//
//  Bee.h
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Creature.h"

class Bee : public Creature {
private:
    double moveX; //new x
    double moveY; //new y
    bool makeLavender; //whether to make lavender or not
    int vT; // counter to create clover
    int stingRand;
    int S;
    bool sting;
    
public:
    
    Bee(); //default constructor
    Bee(double ex, double ey, int eDieAge, unsigned int vT); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
    
};
