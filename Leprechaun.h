//
//  Leprechaun.h
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once
#include "Creature.h"

class Leprechaun : public Creature {
private:
    const int LEP_WIDTH = 30;
    const int LEP_HEIGHT = 30;
    double moveX; //new x
    double moveY; //new y
    bool makeClover; //whether to make clover or not
    int cT; // counter to create clover
    
public:
    
    Leprechaun(); //default constructor
    Leprechaun(double lx, double ly, int lDieAge, unsigned int cGrow); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
    
};


