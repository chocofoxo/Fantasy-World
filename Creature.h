//
//  Creature.h
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "map.h"
#include <iostream>
#include "gwindow.h"
#include "gobjects.h"

class Creature {
    
protected:
    const int WINDOW_WIDTH = 725;
    const int WINDOW_HEIGHT = 300;
    const double SEE_DISTANCE = 140;
    const double BEE_SEE_DISTANCE = 30;
    
    const int FOREST1_X = 0;
    const int FOREST1_Y = 0;
    const int FOREST2_X = 550;
    const int FOREST2_Y = 275;
    const int POND_X = 250;
    const int POND_Y = 150;
    const int MOUNT_X = 600;
    const int MOUNT_Y = 0;
    const int PORTAL1_X = 45;
    const int PORTAL1_Y = 140;
    const int PORTAL2_X = 725;
    const int PORTAL2_Y = 370;
    GImage* field = new GImage("field.jpg");
    GImage* pond = new GImage("pond.png", POND_X, POND_Y);
    GRect* pondrect = new GRect(POND_X+30, POND_Y+20, 165, 105);
    GImage* forest1 = new GImage("forest1.jpg", FOREST1_X, FOREST1_Y);
    GImage* forest2 = new GImage("forest2.jpeg", FOREST2_X, FOREST2_Y);
    GImage* mountains = new GImage("mountains.jpeg", MOUNT_X, MOUNT_Y);
    GImage* portal1 = new GImage("portal.gif",PORTAL1_X, PORTAL1_Y);
    GImage* portal2 = new GImage("portal.gif",PORTAL2_X, PORTAL2_Y);
    
    double x; //position x
    double y; //position y
    int dieAge; //age when dies
    int age;
    int reproduce;
    int speed;
    unsigned int cAppear; // when clover appears
    unsigned int vAppear; // when lavender appears
    std::string creatureType; //creature type
    std::string creatureImage; // creature image
    GImage* image;
    
    bool repeat = true;
    
    
public:
    
    bool virtual move(Vector<Creature*>& creatures, GWindow& gw) = 0;
    double virtual getX();
    double virtual getY();
    std::string virtual getType();
    int virtual getAge();
    int virtual getDieAge();
    int virtual getReproduce();
    void virtual die(Vector<Creature*>& creatures, GWindow& gw) = 0;
    void virtual mate(Vector<Creature*>& creatures) = 0;
    void virtual lookForFood(GWindow& gw, Vector<Creature*>& creatures) = 0;
    void virtual drawCreature(GWindow& gw);
    void virtual removeCreature(GWindow& gw);
    
};