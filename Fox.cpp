//
//  Fox.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Fox.h"
#include "math.h"

Fox::Fox() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 40;
    age = 0;
};

Fox::Fox(double fx, double fy, int fDieAge, int fReproduce) {
    x = fx;
    y = fy;
    creatureType = "Fox";
    creatureImage = "fox.gif";
    image = new GImage(creatureImage);
    speed = 11;
    dieAge = fDieAge;
    reproduce = fReproduce;
    age = 0;
    foundBunny=false;
    foundFox = false;
    BunnyX = 0;
    BunnyY = 0;
    FoxX = 0;
    FoxY = 0;
    
};

bool Fox::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeFox = false;
    creatureImage = "fox.gif";
    //if need to get food: follow Bunny
    if (foundBunny) {
        float dx = BunnyX-x;
        float dy = BunnyY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following bunny" << std::endl;
        } else if ((distance == 0) || (distance<speed)) {
            x=BunnyX;
            y=BunnyY;
            creatures[B]->removeCreature(gw);
             creatures.remove(B);
            std::cout << "A Bunny has been eaten by a fox! :( " << std::endl;
            foundBunny=false;
            reproduce-=(reproduce*0.1);
            dieAge+=(dieAge*0.05);
        } else {
            moveX = dx/distance *speed;
            moveY = (dy/distance * speed);
            x+=moveX;
            y+=moveY;
            foundBunny = false;
        }
    }
    
    //if need to reproduce: follow fox
    else if (foundFox) {
        float dx = FoxX-x;
        float dy = FoxY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        
        if (distance < 0) {
            std::cout << "ERROR following fox" << std::endl;
        } else if (distance<speed) {
            makeFox = true;
            reproduce+=(reproduce*3);
            foundFox=false;
        } else {
            moveX = dx/distance * speed;
            moveY = dy/distance * speed;
            x+=moveX;
            y+=moveY;
        }
    } else {
        if ((pond->contains(x+speed,y+speed)) && (pond->contains((x+speed)+FOX_WIDTH,(y+speed)+FOX_HEIGHT))) {
            x-=speed;
            y-=speed;
        } else if ((pond->contains(x-speed,y-speed)) && (pond->contains((x-speed)+FOX_WIDTH,(y-speed)+FOX_HEIGHT))) {
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
    }
    return makeFox;
};

void Fox::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A fox has died! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* f = creatures[i];
            if(f==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Fox::mate(Vector<Creature*>& creatures) {
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Fox") == 0) && (creatures[i]!=this)) {
            std::cout << "Fox found Fox" << std::endl;
            foundFox = true;
            FoxX=creatures[i]->getX();
            FoxY=creatures[i]->getY();
            break;
        }
    }
    
};

void Fox::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Bunny")) == 0) {
            std::cout << "Fox found Bunny" << std::endl;
            foundBunny = true;
            BunnyX=creatures[i]->getX();
            BunnyY=creatures[i]->getY();
            B = i;
            break;
            
        }
    }
    
};


