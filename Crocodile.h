//
//  Crocodile.h
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Crocodile : public Creature {
private:
    const int CROCODILE_WIDTH = 60;
    const int CROCODILE_HEIGHT = 20;
    double FishX; //x of Fish
    double FishY; //y of Fish
    bool foundFish;
    double BunnyX; //x of Bunny
    double BunnyY; //y of Bunny
    bool foundBunny;
    float moveX; //new x
    float moveY; //new y
    bool foundCrocodile;
    double CrocodileX; // x of Crocodile
    double CrocodileY; //y of Crocodile
    int H; //index of Fish
    int B; //index of bunny
    bool makeCrocodile;
    
public:
    
    Crocodile(); //default constructor
    Crocodile(double ox, double oy, int oDieAge, int oReproduce); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
};