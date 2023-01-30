//
//  Crocodile.cpp
//  Mac
//
//  Created by Dina on 4/10/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Crocodile.h"
#include "math.h"

Crocodile::Crocodile() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 40;
    age = 0;
};

Crocodile::Crocodile(double ox, double oy, int oDieAge, int oReproduce) {
    x = ox;
    y = oy;
    creatureType = "Crocodile";
    creatureImage = "crocodile.gif";
    image = new GImage(creatureImage);
    speed = 11;
    dieAge = oDieAge;
    reproduce = oReproduce;
    age = 0;
    foundFish=false;
    foundCrocodile = false;
    FishX = 0;
    FishY = 0;
    BunnyX = 0;
    BunnyY = 0;
    foundBunny = false;
    CrocodileX = 0;
    CrocodileY = 0;
    
};

bool Crocodile::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeCrocodile = false;
    creatureImage = "crocodile.gif";
    //if need to get food: follow Fish
    if (foundFish) {
        float dx = FishX-x;
        float dy = FishY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following fish" << std::endl;
        } else if ((distance == 0) || (distance<speed)) {
            x=FishX;
            y=FishY;
            creatures[H]->removeCreature(gw);
            creatures.remove(H);
            std::cout << "A Fish has been eaten by a crocodile! :( " << std::endl;
            foundFish=false;
            reproduce-=(reproduce*0.1);
            dieAge+=(dieAge*0.05);
        } else {
            moveX = dx/distance *speed;
            moveY = (dy/distance * speed);
            x+=moveX;
            y+=moveY;
            foundFish = false;
        }
    }
    else  if (foundBunny) {
        float dx = BunnyX-x;
        float dy = BunnyY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        if (distance < 0) {
            std::cout << "ERROR following Bunny" << std::endl;
        } else if ((distance == 0) || (distance<speed)) {
            x=BunnyX;
            y=BunnyY;
            creatures[B]->removeCreature(gw);
            creatures.remove(B);
            std::cout << "A Bunny has been eaten by a crocodile! :( " << std::endl;
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

    //if need to reproduce: follow crocodile
    else if (foundCrocodile) {
        float dx = CrocodileX-x;
        float dy = CrocodileY-y;
        float distance = sqrt((pow(dx,2))+(pow(dy,2)));
        
        if (distance < 0) {
            std::cout << "ERROR following crocodile" << std::endl;
        } else if (distance<speed) {
            makeCrocodile = true;
            reproduce+=(reproduce*3);
            foundCrocodile=false;
        } else {
            moveX = dx/distance * speed;
            moveY = dy/distance * speed;
            x+=moveX;
            y+=moveY;
        }
    } else {
        if ((forest1->contains(x+speed,y+speed) && (forest1->contains((x+speed)+CROCODILE_WIDTH,(y+speed)+CROCODILE_HEIGHT)))
            || ((forest2->contains(x+speed,y+speed)) && (forest2->contains((x+speed)+CROCODILE_WIDTH,(y+speed)+CROCODILE_HEIGHT)))
            || ((mountains->contains(x+speed,y+speed)) && (mountains->contains((x+speed)+CROCODILE_WIDTH,(y+speed)+CROCODILE_HEIGHT)))) {
            x-=speed;
            y-=speed;
        } else if ((forest1->contains(x-speed,y-speed) && (forest1->contains((x-speed)+CROCODILE_WIDTH,(y-speed)+CROCODILE_HEIGHT)))
                   || ((forest2->contains(x-speed,y-speed)) && (forest2->contains((x-speed)+CROCODILE_WIDTH,(y-speed)+CROCODILE_HEIGHT)))
                   || ((mountains->contains(x-speed,y-speed)) && (mountains->contains((x-speed)+CROCODILE_WIDTH,(y-speed)+CROCODILE_HEIGHT)))) {
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
    return makeCrocodile;
};

void Crocodile::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A crocodile has died! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* o = creatures[i];
            if(o==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Crocodile::mate(Vector<Creature*>& creatures) {
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Crocodile") == 0) && (creatures[i]!=this)) {
            std::cout << "Crocodile found Crocodile" << std::endl;
            foundCrocodile = true;
            CrocodileX=creatures[i]->getX();
            CrocodileY=creatures[i]->getY();
            break;
        }
    }
    
};

void Crocodile::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Fish")) == 0) {
            std::cout << "Crocodile found Fish" << std::endl;
            foundFish = true;
            FishX=creatures[i]->getX();
            FishY=creatures[i]->getY();
            H = i;
            break;
        } else if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Bunny")) == 0) {
            std::cout << "Crocodile found Bunny" << std::endl;
            foundBunny = true;
            BunnyX=creatures[i]->getX();
            BunnyY=creatures[i]->getY();
            B = i;
            break;
        }
    }
    
};


