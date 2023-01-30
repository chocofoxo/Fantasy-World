//
//  Fish.h
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Fish : public Creature {
private:
    const int FISH_WIDTH = 50;
    const int FISH_HEIGHT = 19;
    float moveX;
    float moveY;
    bool foundFish;
    double FishX;
    double FishY;
    bool makeFish;
    
public:
    
    Fish(); //default constructor
    Fish(double hx, double hy, int hDieAge, int hReproduce); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
    
};