//
//  Bunny.h
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Bunny : public Creature {
private:
    const int BUNNY_WIDTH = 25;
    const int BUNNY_HEIGHT = 25;
    double CloverX;
    double CloverY;
    bool foundClover;
    double LavenderX;
    double LavenderY;
    bool foundLavender;
    float moveX;
    float moveY;
    bool foundBunny;
    double BunnyX;
    double BunnyY;
    bool makeBunny;
    int C;
    int V;
    
public:
    
    Bunny(); //default constructor
    Bunny(double bx, double by, int bDieAge, int bReproduce); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
    
};