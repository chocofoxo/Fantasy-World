//
//  Bunny.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Bunny.h"
#include "math.h"

Bunny::Bunny() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 30;
    age = 0;
};

Bunny::Bunny(double bx, double by, int bDieAge, int bReproduce) {
    x = bx;
    y = by;
    creatureType = "Bunny";
    creatureImage = "bunny.gif";
    image = new GImage(creatureImage);
    speed = 14;
    dieAge = bDieAge;
    reproduce = bReproduce;
    age = 0;
    foundClover=false;
    foundBunny = false;
    foundLavender = false;
};

bool Bunny::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeBunny=false;
    creatureImage = "bunny.gif";
    //if need to get food: follow clover
    if (foundClover) {
        float dx = CloverX-x;
        float dy = CloverY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following clover" << std::endl;
        } else if ((distance == 0) || (distance<speed)) {
            x=CloverX;
            y=CloverY;
            creatures[C]->removeCreature(gw);
            creatures.remove(C);
            std::cout << "A clover has been eaten by a bunny! :( " << std::endl;
            foundClover=false;
            reproduce-=(reproduce*0.1);
            dieAge+=(dieAge*0.05);
        } else {
            moveX = dx/distance *speed;
            moveY = (dy/distance * speed);
            x+=moveX;
            y+=moveY;
            foundClover = false;
        }
    }
    else if (foundLavender) {
        float dx = LavenderX-x;
        float dy = LavenderY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following Lavender" << std::endl;
        } else if ((distance == 0) || (distance<speed)) {
            x=LavenderX;
            y=LavenderY;
            creatures[V]->removeCreature(gw);
            creatures.remove(V);
            std::cout << "A Lavender has been eaten by a bunny! :( " << std::endl;
            foundLavender=false;
            reproduce-=(reproduce*0.1);
            dieAge+=(dieAge*0.05);
        } else {
            moveX = dx/distance *speed;
            moveY = (dy/distance * speed);
            x+=moveX;
            y+=moveY;
            foundLavender = false;
        }
    }

    //if need to reproduce: follow bunny
    else if (foundBunny) {
        float dx = BunnyX-x;
        float dy = BunnyY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following bunny" << std::endl;
        } else if (distance<speed) {
            makeBunny = true;
            reproduce+=(reproduce*3);
            foundBunny = false;
        } else {
            moveX = dx/distance * speed;
            moveY = dy/distance * speed;
            x+=moveX;
            y+=moveY;
        }
    } else {
        if ((pond->contains(x+speed,y+speed) || mountains->contains(x+speed,y+speed))
            &&
            (pond->contains((x+speed)+BUNNY_WIDTH,(y+speed)+BUNNY_HEIGHT) || mountains->contains((x+speed)+BUNNY_WIDTH,(y+speed)+BUNNY_HEIGHT))) {
            x-=speed;
            y-=speed;
        } else if ((pond->contains(x-speed,y-speed) || mountains->contains(x-speed,y-speed))
                   &&
                   (pond->contains((x-speed)+BUNNY_WIDTH,(y-speed)+BUNNY_HEIGHT) || mountains->contains((x-speed)+BUNNY_WIDTH,(y-speed)+BUNNY_HEIGHT))) {
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
        }; }
        
    } return makeBunny;
};

void Bunny::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A bunny has died! :( " << std::endl;
        
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

void Bunny::mate(Vector<Creature*>& creatures) {
    
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Bunny") == 0) && (creatures[i]!=this)) {
            std::cout << "A bunny found a bunny!" << std::endl;
            foundBunny= true;
            BunnyX=creatures[i]->getX();
            BunnyY=creatures[i]->getY();
            break;
        }
    }
    
};

void Bunny::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Clover")) == 0) {
            std::cout << "A bunny found a clover!" << std::endl;
            foundClover = true;
            CloverX=creatures[i]->getX();
            CloverY=creatures[i]->getY();
            C=i;
            break;
            
        }
        else if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Lavender")) == 0) {
            std::cout << "A bunny found a Lavender!" << std::endl;
            foundLavender = true;
            LavenderX=creatures[i]->getX();
            LavenderY=creatures[i]->getY();
            V=i;
            break;
            
        }

    }
    
};
