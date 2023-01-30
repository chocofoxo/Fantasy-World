//
//  Lavender.cpp
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Lavender.h"

Lavender::Lavender() {
    x = 0;
    y = 0;
    dieAge = 50;
    age = 0;
};

Lavender::Lavender(double vx, double vy, int vDieAge) {
    x = vx;
    y = vy;
    creatureType = "Lavender";
    creatureImage = "lavender.png";
    image = new GImage(creatureImage);
    dieAge = vDieAge;
    age = 0;
    makeLavender=false;
};

bool Lavender::move(Vector<Creature*>& creatures, GWindow& gw) {
    creatureImage = "lavender.png";
    return makeLavender;
};

void Lavender::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A lavender has withered! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* v = creatures[i];
            if(v==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Lavender::mate(Vector<Creature*>& creatures) {
};

void Lavender::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
};
