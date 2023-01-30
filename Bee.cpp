//
//  Bee.cpp
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Bee.h"
#include "math.h"

Bee::Bee() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 60;
    age = 0;
};

Bee::Bee(double ex, double ey, int eDieAge, unsigned int vGrow) {
    x = ex;
    y = ey;
    creatureType = "Bee";
    creatureImage = "bee.gif";
    image = new GImage(creatureImage);
    speed = 20;
    dieAge = eDieAge;
    age = 0;
    vAppear = vGrow;
    makeLavender = false;
    vT=1;
    sting = false;
};

bool Bee::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeLavender=false;
    creatureImage = "bee.gif";
    //sting
    if (sting) {
        std::cout << "A bee stung a " << creatures[S]->getType() << " and both died in the process! :( " << std::endl;
        creatures[S]->removeCreature(gw);
        creatures.remove(S);
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* e = creatures[i];
            if(e==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    } else
    if (vAppear == 0) {
        std::cout << "Error vAppear" << std::endl;
    } else if ((vT > vAppear) && (vT % vAppear == 0)) {
        makeLavender=true;
    }
        
        //Random direction for x and y
        int RandX = rand() % 10 + 1;
        
        if (RandX<=4) {
            if (x+speed >= WINDOW_HEIGHT) {
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
    vT++;
    return makeLavender;
};

void Bee::die(Vector<Creature*>& creatures, GWindow& gw) {
    
    if (age>dieAge) {
        std::cout << "A bee has died! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* e = creatures[i];
            if(e==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Bee::mate(Vector<Creature*>& creatures) {
};

void Bee::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
    double sx=x-(BEE_SEE_DISTANCE/2);
    double sy=y-(BEE_SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, BEE_SEE_DISTANCE, BEE_SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if (g.contains(creatures[i]->getX(), creatures[i]->getY()) && ((creatures[i]->getType()).compare("Bee")!=0) && ((creatures[i]->getType()).compare("Clover")!=0) && ((creatures[i]->getType()).compare("Lavender")!=0)) {
            stingRand = rand() % 10 + 1;
            if (stingRand<=2) {
                S=i;
                sting = true;
                break;
            }
            
        }
    
    }
};
