//
//  Clover.h
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Creature.h"

class Clover : public Creature {
private:
    bool makeClover; //null
public:
    
    Clover(); //default constructor
    Clover(double cx, double cy, int cDieAge); //constructor
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures); //null
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures); //null
    
    
};
