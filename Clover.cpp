//
//  Clover.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Clover.h"

Clover::Clover() {
    x = 0;
    y = 0;
    dieAge = 50;
    age = 0;
};

Clover::Clover(double cx, double cy, int cDieAge) {
    x = cx;
    y = cy;
    creatureType = "Clover";
    creatureImage = "clover.gif";
    image = new GImage(creatureImage);
    dieAge = cDieAge;
    age = 0;
    makeClover=false;
};

bool Clover::move(Vector<Creature*>& creatures, GWindow& gw) {
    creatureImage = "clover.gif";
    return makeClover;
};

void Clover::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A clover has withered! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* c = creatures[i];
            if(c==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Clover::mate(Vector<Creature*>& creatures) {
};

void Clover::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
};
