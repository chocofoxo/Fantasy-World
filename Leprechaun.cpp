//
//  Leprechaun.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Leprechaun.h"
#include "math.h"

Leprechaun::Leprechaun() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 60;
    age = 0;
};

Leprechaun::Leprechaun(double lx, double ly, int lDieAge, unsigned int cGrow) {
    x = lx;
    y = ly;
    creatureType = "Leprechaun";
    creatureImage = "leprechaun.gif";
    image = new GImage(creatureImage);
    speed = 14;
    dieAge = lDieAge;
    cAppear = cGrow;
    age = 0;
    makeClover = false;
    cT = 1;
};

bool Leprechaun::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeClover=false;
    creatureImage = "leprechaun.gif";
    if (cAppear == 0) {
        std::cout << "Error cAppear" << std::endl;
    } else if ((cT > cAppear) && (cT % cAppear == 0)) {
        makeClover=true;
    }
    
    if (pond->contains(x+speed,y+speed)) {
        x-=speed;
        y-=speed;
    } else if (pond->contains(x-speed,y-speed)) {
        x+=speed;
        y+=speed;
    } else {
        
    //Random direction for x and y
    int RandX = rand() % 10 + 1;
    
    if (RandX<=4) {
        if (x+speed >= WINDOW_WIDTH) {
            x-=speed;
        }
        x+=speed;
    } else if (RandX<=8){
        if (x-speed <= 0) {
            x+=speed;
        }
        x-=speed;
    }
    else {
    };

    //Random direction for y
    int RandY = rand() % 10 + 1;
    if (RandY<=4) {
        if (y+speed >= WINDOW_HEIGHT) {
            y-=speed;
        }
        y+=speed;
    } else if (RandY<=8){
        if (y-speed <= 0) {
            y+=speed;
        }
        y-=speed;
    }
    else {
    };
        }
    cT++;
    return makeClover;
};

void Leprechaun::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A leprechaun has died! :( " << std::endl;
        
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

void Leprechaun::mate(Vector<Creature*>& creatures) {
};

void Leprechaun::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
};

