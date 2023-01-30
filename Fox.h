//
//  Fox.h
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Fox : public Creature {
private:
    const int FOX_WIDTH = 60;
    const int FOX_HEIGHT = 45;
    double BunnyX; //x of bunny
    double BunnyY; //y of bunny
    bool foundBunny;
    float moveX; //new x
    float moveY; //new y
    bool foundFox;
    double FoxX; // x of fox
    double FoxY; //y of fox
    int B; //index of bunny
    bool makeFox;
    
public:
    
    Fox(); //default constructor
    Fox(double fx, double fy, int fDieAge, int fReproduce); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
};