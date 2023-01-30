//
//  Fish.cpp
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Fish.h"
#include "math.h"

Fish::Fish() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 30;
    age = 0;
};

Fish::Fish(double hx, double hy, int hDieAge, int hReproduce) {
    x = hx;
    y = hy;
    creatureType = "Fish";
    creatureImage = "fish.gif";
    image = new GImage(creatureImage);
    speed = 5;
    dieAge = hDieAge;
    reproduce = hReproduce;
    age = 0;
    foundFish = false;
};

bool Fish::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeFish=false;
    creatureImage = "fish.gif";
    //if need to reproduce: follow fish
    if (foundFish) {
        float dx = FishX-x;
        float dy = FishY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following fish" << std::endl;
        } else if (distance<speed) {
            makeFish = true;
            reproduce+=(reproduce*3);
            foundFish = false;
        } else {
            moveX = dx/distance * speed;
            moveY = dy/distance * speed;
            x+=moveX;
            y+=moveY;
        }
    } else {
        if (pondrect->contains(x+speed,y+speed) && pondrect->contains(x-speed,y-speed) && pondrect->contains((x+speed)+FISH_WIDTH, (y+speed)+FISH_HEIGHT) && pondrect->contains((x-speed)+FISH_WIDTH, (y-speed)+FISH_HEIGHT)) {
            
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
        } //close if pond->all
        //move one direction
        else if ((pondrect->contains(x+speed,y+speed)) && (pondrect->contains((x+speed)+FISH_WIDTH,(y+speed)+FISH_HEIGHT))) {
            x+=speed;
            y+=speed;
            
        } else if ((pondrect->contains(x-speed,y-speed)) && (pondrect->contains((x-speed)+FISH_WIDTH, (y-speed)+FISH_HEIGHT))) {
            x-=speed;
            y-=speed;
            
        }else {
            //move in any direction possible
            if (pondrect->contains(x,y)) {
                x+=speed;
                y+=speed;
            } else if (pondrect->contains(x+FISH_WIDTH,y+FISH_HEIGHT)) {
                x-=speed;
                y-=speed;
                //dies from poor climate
            } else for (int i=0; i<creatures.size(); i++) {
                Creature* h = creatures[i];
                if(h==this) {
                    creatures[i]->removeCreature(gw);
                    creatures.remove(i);
                    std::cout << "A fish has been washed ashore! :( " << std::endl;
                }
            }
            
            
        };
        
        
    } return makeFish;
};

void Fish::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A fish has died! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* h = creatures[i];
            if(h==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Fish::mate(Vector<Creature*>& creatures) {
    
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Fish") == 0) && (creatures[i]!=this)) {
            std::cout << "A fish found a fish!" << std::endl;
            foundFish= true;
            FishX=creatures[i]->getX();
            FishY=creatures[i]->getY();
            break;
        }
    }
    
};

void Fish::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
};

