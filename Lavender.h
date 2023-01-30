//
//  Lavender.h
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include "Creature.h"

class Lavender : public Creature {
private:
    bool makeLavender; //null
public:
    
    Lavender(); //default constructor
    Lavender(double vx, double vy, int vDieAge); //constructor
    bool move(Vector<Creature*>& creatures, GWindow& gw);
    void die(Vector<Creature*>& creatures, GWindow& gw);
    void mate(Vector<Creature*>& creatures); //null
    void lookForFood(GWindow& gw, Vector<Creature*>& creatures); //null
    
    
};
