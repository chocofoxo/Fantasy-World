//
//  Unicorn.h
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Unicorn : public Creature {
private:
    const int UNICORN_WIDTH = 50;
    const int UNICORN_HEIGHT = 36;
    double LavenderX;
    double LavenderY;
    bool foundLavender;
    float moveX;
    float moveY;
    bool foundUnicorn;
    double UnicornX;
    double UnicornY;
    bool makeUnicorn;
    int V;
    
public:
    
    Unicorn(); //default constructor
   Unicorn(double ux, double uy, int uDieAge, int uReproduce); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
    
};