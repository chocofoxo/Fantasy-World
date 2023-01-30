//
//  Dragon.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Dragon.h"
#include "math.h"

Dragon::Dragon() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 50;
    age = 0;
};

Dragon::Dragon(double dx, double dy, int dDieAge, int dReproduce) {
    x = dx;
    y = dy;
    creatureType = "Dragon";
    creatureImage = "dragon.gif";
    image = new GImage(creatureImage);
    speed = 13;
    dieAge = dDieAge;
    reproduce = dReproduce;
    age = 0;
    foundLeprechaun=false;
    foundDragon = false;
    LepX = 0;
    LepY = 0;
    DragonX = 0;
    DragonY = 0;
    
};

bool Dragon::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeDragon = false;
    creatureImage = "dragon.gif";
    //if need to get food: follow leprechaun
    if (foundLeprechaun) {
        float dx = LepX-x;
        float dy = LepY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following lep" << std::endl;
        } else if ((distance == 0) || (distance<speed)) {
            x=LepX;
            y=LepY;
            creatures[L]->removeCreature(gw);
            creatures.remove(L);
            std::cout << "A leprechaun has been eaten by a dragon! :( " << std::endl;
            foundLeprechaun=false;
            reproduce-=(reproduce*0.1);
            dieAge+=(dieAge*0.05);
        } else {
            moveX = dx/distance * speed;
            moveY = (dy/distance * speed);
            x+=moveX;
            y+=moveY;
            foundLeprechaun = false;
        }
    }
    
    //if need to reproduce: follow dragon
    else if (foundDragon) {
        float dx = DragonX-x;
        float dy = DragonY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following dragon" << std::endl;
        } else if (distance<speed) {
            makeDragon = true;
            reproduce+=(reproduce*3);
            foundDragon=false;
        } else {
            moveX = dx/distance * speed;
            moveY = dy/distance * speed;
            x+=moveX;
            y+=moveY;
        }
    } else {
        if ((forest1->contains(x+speed,y+speed) && (forest1->contains((x+speed)+DRAGON_WIDTH,(y+speed)+DRAGON_HEIGHT)))
            || ((forest2->contains(x+speed,y+speed)) && (forest2->contains((x+speed)+DRAGON_WIDTH,(y+speed)+DRAGON_HEIGHT)))) {
            x-=speed;
            y-=speed;
        } else if ((forest1->contains(x-speed,y-speed) && (forest1->contains((x-speed)+DRAGON_WIDTH,(y-speed)+DRAGON_HEIGHT)))
                   || ((forest2->contains(x-speed,y-speed)) && (forest2->contains((x-speed)+DRAGON_WIDTH,(y-speed)+DRAGON_HEIGHT)))) {
            x+=speed;
            y+=speed;
        } else {
            
        //Random direction for x
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
    } return makeDragon;
};

void Dragon::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A dragon has died! :( " << std::endl;
        
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

void Dragon::mate(Vector<Creature*>& creatures) {
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Dragon") == 0) && (creatures[i]!=this)) {
            std::cout << "Dragon found Dragon" << std::endl;
            foundDragon = true;
            DragonX=creatures[i]->getX();
            DragonY=creatures[i]->getY();
            break;
        }
    }
    
};

void Dragon::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && (((creatures[i]->getType()).compare("Leprechaun")) == 0) && ((!forest1->contains(creatures[i]->getX(), creatures[i]->getY())) || (!forest2->contains(creatures[i]->getX(), creatures[i]->getY())))) {
            std::cout << "Dragon found Leprechaun" << std::endl;
            foundLeprechaun = true;
            LepX=creatures[i]->getX();
            LepY=creatures[i]->getY();
            L = i;
            break;
            
        }
    }
    
};