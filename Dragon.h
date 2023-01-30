//
//  Dragon.h
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Dragon : public Creature {
private:
    const int DRAGON_WIDTH = 55;
    const int DRAGON_HEIGHT = 40;
    double LepX; //x of leprechaun
    double LepY; //y of leprechaun
    bool foundLeprechaun;
    float moveX; //new x
    float moveY; //new y
    bool foundDragon;
    double DragonX; //x of dragon
    double DragonY; //y of dragon
    int L; // index of leprechaun
    bool makeDragon;
    
public:
    
    Dragon(); //default constructor
    Dragon(double dx, double dy, int dDieAge, int dReproduce); //constructor
    
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures);
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures);
};

