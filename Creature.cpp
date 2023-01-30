//
//  Creature.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Creature.h"


double Creature::getX() {
    return x;
};

double Creature::getY() {
    return y;
};

std::string Creature::getType() {
    return creatureType;
};

int Creature::getAge() {
    return age;
};

int Creature::getDieAge() {
    return dieAge;
};

int Creature::getReproduce() {
    return reproduce;
};

void Creature::drawCreature(GWindow& gw) {
    gw.add(image, x, y);
   
};

void Creature::removeCreature(GWindow& gw) {
    gw.remove(image);
};

