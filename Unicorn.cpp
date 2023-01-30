//
//  Unicorn.cpp
//  Mac
//
//  Created by Dina on 4/26/15.
//  Copyright (c) 2015 Sanjay Madhav. All rights reserved.
//

#include "Unicorn.h"
#include "math.h"

Unicorn::Unicorn() {
    x = 0;
    y = 0;
    dieAge = 50;
    speed = 30;
    age = 0;
};

Unicorn::Unicorn(double ux, double uy, int uDieAge, int uReproduce) {
    x = ux;
    y = uy;
    creatureType = "Unicorn";
    creatureImage = "unicorn.gif";
    image = new GImage(creatureImage);
    speed = 10;
    dieAge = uDieAge;
    reproduce = uReproduce;
    age = 0;
    foundLavender = false;
    foundUnicorn = false;
};

bool Unicorn::move(Vector<Creature*>& creatures, GWindow& gw) {
    makeUnicorn=false;
    creatureImage = "unicorn.gif";
    //if on portal
    if (portal1->contains(x,y) || portal1->contains(x+UNICORN_WIDTH, y+UNICORN_HEIGHT)) {
        int p1RandX = -(rand() % 20 + 10);
        int p1RandY = rand() % 20 + 10;
        x=PORTAL2_X+p1RandX;
        y=PORTAL2_Y+p1RandY;
        foundLavender = false;
        foundUnicorn = false;
        std::cout << "to portal 2" << std::endl;
    } else if (portal2->contains(x,y) || portal2->contains(x+UNICORN_WIDTH, y+UNICORN_HEIGHT)) {
        int p2RandX = rand() % 20 + 10;
        int p2RandY = -(rand() % 20 + 10);
        x=PORTAL1_X+p2RandX;
        y=PORTAL1_Y+p2RandY;
        foundLavender = false;
        foundUnicorn = false;
        std::cout << "to portal 1" << std::endl;
    } else {
        
        //if need to get food: follow lavender
        if (foundLavender) {
            float dx = LavenderX-x;
            float dy = LavenderY-y;
            float distance = sqrt((pow(dx,2))+(pow(dy,2)));
            if (distance < 0) {
                std::cout << "ERROR following lavender" << std::endl;
            } else if ((distance == 0) || (distance<speed)) {
                x=LavenderX;
                y=LavenderY;
                
                creatures[V]->removeCreature(gw);
                creatures.remove(V);
                std::cout << "A lavender has been eaten by a unicorn! :( " << std::endl;
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
        //if need to reproduce: follow unicorn
        else if (foundUnicorn) {
            float dx = UnicornX-x;
            float dy = UnicornY-y;
            float distance = sqrt((pow(dx,2))+(pow(dy,2)));
            if (distance < 0) {
                std::cout << "ERROR following unicorn" << std::endl;
            } else if (distance<speed) {
                makeUnicorn = true;
                reproduce+=(reproduce*3);
                foundUnicorn = false;
            } else {
                moveX = dx/distance * speed;
                moveY = dy/distance * speed;
                x+=moveX;
                y+=moveY;
               
            }
        } else {
            if (((forest1->contains(x+speed,y+speed) && forest1->contains(x-speed,y-speed)) || (forest2->contains(x+speed,y+speed) && forest2->contains(x-speed,y-speed)))
                &&
                (((forest1->contains((x+speed)+UNICORN_WIDTH,(y+speed)+UNICORN_HEIGHT)) && (forest1->contains((x-speed)+UNICORN_WIDTH,(y-speed)+UNICORN_HEIGHT))) || ((forest2->contains((x+speed)+UNICORN_WIDTH,(y+speed)+UNICORN_HEIGHT)) && (forest2->contains((x-speed)+UNICORN_WIDTH,(y-speed)+UNICORN_HEIGHT))))) {
                
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
                    x-=speed;                 }
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
            }
            //move one direction
            else if (((forest1->contains(x+speed,y+speed)) && (forest1->contains((x+speed)+UNICORN_WIDTH,(y+speed)+UNICORN_HEIGHT)))
                     || (((forest2->contains(x+speed,y+speed))
                         && (forest2->contains((x+speed)+UNICORN_WIDTH,(y+speed)+UNICORN_HEIGHT))))) {
                         x+=speed;
                         y+=speed;
                
                     } else if (((forest1->contains(x-speed,y-speed)) && (forest1->contains((x-speed)+UNICORN_WIDTH,(y-speed)+UNICORN_HEIGHT)))
                                || (((forest2->contains(x-speed,y-speed))
                                    && (forest2->contains((x-speed)+UNICORN_WIDTH,(y-speed)+UNICORN_HEIGHT))))) {
                                    x-=speed;
                                    y-=speed;
                         
                                } else {
                                    //move in any direction possible
                                    if (forest1->contains(x,y)) {
                                        x-=speed;
                                        y-=speed;
                                    } else if (forest2->contains(x+UNICORN_WIDTH,y+UNICORN_HEIGHT)) {
                                        x+=speed;
                                        y+=speed;
                                        //dies from poor climate
                                    } else for (int i=0; i<creatures.size(); i++) {
                                        Creature* u = creatures[i];
                                        if(u==this) {
                                            creatures[i]->removeCreature(gw);
                                            creatures.remove(i);
                                            std::cout << "A unicorn has died wandering from the forest! :( " << std::endl;
                                        }
                                    }


                                };
        };
    };
    return makeUnicorn;
    
};

void Unicorn::die(Vector<Creature*>& creatures, GWindow& gw) {
    if (age>dieAge) {
        std::cout << "A unicorn has died! :( " << std::endl;
        
        for (int i=0; i<creatures.size(); i++) {
            Creature* u = creatures[i];
            if(u==this) {
                creatures[i]->removeCreature(gw);
                creatures.remove(i);
            }
        }
    }//end if statement
    else {
        age++; //increase age
    }
};

void Unicorn::mate(Vector<Creature*>& creatures) {
    
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Unicorn ") == 0) && (creatures[i]!=this)) {
            std::cout << "A unicorn found a unicorn !" << std::endl;
            foundUnicorn= true;
            UnicornX=creatures[i]->getX();
            UnicornY=creatures[i]->getY();
            break;
        }
    }
    
};

void Unicorn::lookForFood(GWindow& gw, Vector<Creature*>& creatures) {
    
    double sx=x-(SEE_DISTANCE/2);
    double sy=y-(SEE_DISTANCE/2);
    GRectangle g;
    g = GRectangle(sx,sy, SEE_DISTANCE, SEE_DISTANCE);
    
    for (int i = 0; i<creatures.size(); i++) {
        if ((g.contains(creatures[i]->getX(), creatures[i]->getY())) && ((creatures[i]->getType()).compare("Lavender") == 0) && ((forest1->contains(creatures[i]->getX(), creatures[i]->getY())) || (forest2->contains(creatures[i]->getX(), creatures[i]->getY())))) {
            std::cout << "A unicorn found a lavender!" << std::endl;
            foundLavender = true;
            LavenderX=creatures[i]->getX();
            LavenderY=creatures[i]->getY();
            V=i;
            break;
            
        }
    }
    
};
