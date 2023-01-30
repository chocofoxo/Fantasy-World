// ITP 365 Spring 2015
// HW5 - Artificial World
// Name: Dina Levashova
// Email: levashov@usc.edu
// Platform: Mac


//HW6

#include "gtimer.h"
#include "gevents.h"
#include "ginteractors.h"
#include "Fox.h"
#include "Bunny.h"
#include "Leprechaun.h"
#include "Clover.h"
#include "Dragon.h"
#include "Lavender.h"
#include "Unicorn.h"
#include "Crocodile.h"
#include "Fish.h"
#include "Bee.h"
#include <iostream>
#include "math.h"

int main(int argc, char** argv)
{
    const int WINDOW_WIDTH = 725;
    const int WINDOW_HEIGHT = 300;
    const int X_CORRECTION = 0;
    const int Y_CORRECTION = 5;
    
   // const int FOREST1_WIDTH = 200;
   // const int FOREST1_HEIGHT = 200;
  //  const int FOREST2_WIDTH = 250;
  //  const int FOREST2_HEIGHT = 150;
  //  const int POND_WIDTH = 236;
  //  const int POND_HEIGHT = 146;
   // const int MOUNT_WIDTH = 200;
  //  const int MOUNT_HEIGHT = 150;
    
    const int FOX_WIDTH = 60;
    const int FOX_HEIGHT = 45;
    const int DRAGON_WIDTH = 55;
    const int DRAGON_HEIGHT = 40;
    const int BUNNY_WIDTH = 25;
    const int BUNNY_HEIGHT = 25;
    const int LEP_WIDTH = 30;
    const int LEP_HEIGHT = 30;
    const int CLOVER_WIDTH = 20;
    const int CLOVER_HEIGHT = 20;
    const int UNICORN_WIDTH = 50;
    const int UNICORN_HEIGHT = 36;
    const int CROCODILE_WIDTH = 60;
    const int CROCODILE_HEIGHT = 20;
    const int FISH_WIDTH = 50;
    const int FISH_HEIGHT = 19;
  //  const int BEE_WIDTH = 25;
 //   const int BEE_HEIGHT = 25;
    const int LAV_WIDTH = 10;
    const int LAV_HEIGHT = 50;
    
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
    
    int fNum=0;
    int dNum=0;
    int bNum=0;
    int lNum=0;
    int cNum=0;
    
    int uNum=0;
    int oNum=0;
    int hNum=0;
    int eNum=0;
    int vNum=0;
    
    int fDieAge=0;
    int dDieAge=0;
    int bDieAge=0;
    int lDieAge=0;
    int cDieAge=0;
    
    int uDieAge=0;
    int oDieAge=0;
    int hDieAge=0;
    int eDieAge=0;
    int vDieAge=0;
    
    unsigned int lGrow=0;
    unsigned int cGrow=0;
    unsigned int vGrow=0;
    
    int fReproduce=0;
    int dReproduce=0;
    int bReproduce=0;
    
    int uReproduce=0;
    int oReproduce=0;
    int hReproduce=0;
    
    double fStartX;
    double fStartY;
    double dStartX;
    double dStartY;
    double bStartX;
    double bStartY;
    double lStartX;
    double lStartY;
    double cStartX;
    double cStartY;
    double uStartX;
    double uStartY;
    double oStartX;
    double oStartY;
    double hStartX;
    double hStartY;
    double eStartX;
    double eStartY;
    double vStartX;
    double vStartY;
    
    bool foxRepeat;
    bool dragonRepeat;
    bool bunnyRepeat;
    bool lepRepeat;
    bool cloverRepeat;
    bool unicRepeat;
    bool crocRepeat;
    bool fishRepeat;
    bool lavRepeat;
    
    GRect* screen = new GRect(0,5,WINDOW_WIDTH, WINDOW_HEIGHT);
    screen->setFillColor("red");
    screen->setFilled("false");
    
    GImage* field = new GImage("field.jpg");
    GImage* pond = new GImage("pond.png", POND_X, POND_Y);
    GRect* pondrect = new GRect(POND_X+30, POND_Y+20, 165, 105);
    GImage* forest1 = new GImage("forest1.jpg", FOREST1_X, FOREST1_Y);
    GImage* forest2 = new GImage("forest2.jpeg", FOREST2_X, FOREST2_Y);
    GImage* mountains = new GImage("mountains.jpeg", MOUNT_X, MOUNT_Y);
    GImage* portal1 = new GImage("portal.gif",PORTAL1_X, PORTAL1_Y);
    GImage* portal2 = new GImage("portal.gif",PORTAL2_X, PORTAL2_Y);
    
    int beeRand;
    bool makeBaby;
    int lT; // timer for leprechaun appearance
    
    Vector<Creature*> creatures;
    
    
    //Prompt user for instructions
    
    std::cout << "Welcome to Dina's World!" << "\n" << "Please enter the following (in positive integers please!) and press START to begin!" << std::endl;
    
    // Set up screen
    GWindow gw(800, 500);
    gw.setWindowTitle("Dina's World");
    
    GButton* startButton = new GButton("Start");
    gw.addToRegion(startButton, "SOUTH");
    
    GButton* pauseButton = new GButton("Pause");
    gw.addToRegion(pauseButton, "SOUTH");
    
    GButton* continueButton = new GButton("Continue");
    gw.addToRegion(continueButton, "SOUTH");
    
    GButton* restartButton = new GButton("Restart");
    gw.addToRegion(restartButton, "SOUTH");
    
    GButton* quitButton = new GButton("Quit");
    gw.addToRegion(quitButton, "SOUTH");
    
    GTextField* input = new GTextField(22);
    gw.addToRegion(input, "NORTH");
    input->setText("Enter name of input file and press START!");
    
    
        // Set up timer and button events
    
    GTimer timer(1000);
    lT = 1; // start time for leprechaun appearance
    
    bool game = true;
    
    while(game) {
        GEvent e;
        e = waitForEvent();
        
        if (e.getEventType() == ACTION_PERFORMED ) {
            GActionEvent ae = (GActionEvent)e;
            
            if (ae.getSource() == startButton) {
                if (lT==1) {
                    std::cout << "Enjoy exploring! :)" << std::endl;
                    
                    bool enterFile = true;
                    
                    while (enterFile) {
                        std::ifstream file(input->getText());
                        if (file.is_open()) {
                            while (!file.eof()) {
                                // Grab each line and store as string variable
                                std::string numF;
                                std::string numD;
                                std::string numB;
                                std::string numL;
                                std::string numC;
                                std::string numU;
                                std::string numO;
                                std::string numH;
                                std::string numE;
                                std::string numV;
                                
                                std::string dieF;
                                std::string dieD;
                                std::string dieB;
                                std::string dieL;
                                std::string dieC;
                                std::string dieU;
                                std::string dieO;
                                std::string dieH;
                                std::string dieE;
                                std::string dieV;
                                
                                std::string growL;
                                std::string growC;
                                std::string growV;
                                std::string repF;
                                std::string repD;
                                std::string repB;
                                std::string repU;
                                std::string repO;
                                std::string repH;
                                
                                getline(file, numF);
                                getline(file, numD);
                                getline(file, numB);
                                getline(file, numL);
                                getline(file, numC);
                                getline(file, numU);
                                getline(file, numO);
                                getline(file, numH);
                                getline(file, numE);
                                getline(file, numV);
                                
                                getline(file, dieF);
                                getline(file, dieD);
                                getline(file, dieB);
                                getline(file, dieL);
                                getline(file, dieC);
                                getline(file, dieU);
                                getline(file, dieO);
                                getline(file, dieH);
                                getline(file, dieE);
                                getline(file, dieV);
                                
                                getline(file, growL);
                                getline(file, growC);
                                getline(file, growV);
                                getline(file, repF);
                                getline(file, repD);
                                getline(file, repB);
                                getline(file, repU);
                                getline(file, repO);
                                getline(file, repH);
                                
                                //Convert to integers and store
                                fNum = stringToInteger(numF);
                                dNum = stringToInteger(numD);
                                bNum = stringToInteger(numB);
                                lNum = stringToInteger(numL);
                                cNum = stringToInteger(numC);
                                uNum = stringToInteger(numU);
                                oNum = stringToInteger(numO);
                                hNum = stringToInteger(numH);
                                eNum = stringToInteger(numE);
                                vNum = stringToInteger(numV);
                                
                                fDieAge = stringToInteger(dieF);
                                dDieAge = stringToInteger(dieD);
                                bDieAge = stringToInteger(dieB);
                                lDieAge = stringToInteger(dieL);
                                cDieAge = stringToInteger(dieC);
                                uDieAge = stringToInteger(dieU);
                                oDieAge = stringToInteger(dieO);
                                hDieAge = stringToInteger(dieH);
                                eDieAge = stringToInteger(dieE);
                                vDieAge = stringToInteger(dieV);
                                
                                lGrow = stringToInteger(growL);
                                cGrow = stringToInteger(growC);
                                vGrow = stringToInteger(growV);
                                fReproduce = stringToInteger(repF);
                                dReproduce = stringToInteger(repD);
                                bReproduce = stringToInteger(repB);
                                uReproduce = stringToInteger(repU);
                                oReproduce = stringToInteger(repO);
                                hReproduce = stringToInteger(repH);
                                
                            }
                            enterFile = false;
                            
                        }
                    }
                    
                    
                    // Set up initial characters
                    
                    //Set up foxes
                    
                   
                    for (int i=0; i<fNum; i++) {
                        foxRepeat = true;
                        while (foxRepeat) {
                            fStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            fStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((!pond->contains(fStartX, fStartY)) && (!pond->contains(fStartX+FOX_WIDTH, fStartY+FOX_HEIGHT))) {
                                Fox* F = new Fox(fStartX, fStartY, fDieAge, fReproduce);
                                creatures.add(F);
                                std::cout << "A fox has been born! :) " << std::endl;
                                foxRepeat = false;
                            }
                        }
                    }
                    //Set up bunnies
                    
                    for (int i=0; i<bNum; i++) {
                        bunnyRepeat = true;
                        while (bunnyRepeat) {
                            bStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            bStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((!pond->contains(bStartX, bStartY)) && (!mountains->contains(bStartX, bStartY)) && (!pond->contains(bStartX+BUNNY_WIDTH, bStartY+BUNNY_HEIGHT)) && (!mountains->contains(bStartX+BUNNY_WIDTH, bStartY+BUNNY_HEIGHT))) {
                                Bunny* B = new Bunny(bStartX, bStartY, bDieAge, bReproduce);
                                creatures.add(B);
                                std::cout << "A bunny has been born! :) " << std::endl;
                                bunnyRepeat=false;
                            }
                        }
                    }
                    
                    //Set up leprechauns
                    
                    for (int i=0; i<lNum; i++) {
                        lepRepeat = true;
                        while (lepRepeat) {
                            lStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            lStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((!pond->contains(lStartX, lStartY)) && (!pond->contains(lStartX+LEP_WIDTH, lStartY+LEP_HEIGHT))) {
                                Leprechaun* L = new Leprechaun(lStartX, lStartY, lDieAge, cGrow);
                                creatures.add(L);
                                std::cout << "A leprechaun has appeared! :) " << std::endl;
                                lepRepeat = false;
                            }
                        }
                    }
                    
                    //Set up clovers
                    
                    for (int i=0; i<cNum; i++) {
                        cloverRepeat = true;
                        while (cloverRepeat) {
                            cStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            cStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((!pond->contains(cStartX, cStartY)) && (!mountains->contains(cStartX, cStartY)) && (!pond->contains(cStartX+CLOVER_WIDTH, cStartY+CLOVER_HEIGHT)) && (!mountains->contains(cStartX+CLOVER_WIDTH, cStartY+CLOVER_HEIGHT))) {
                                Clover* C = new Clover(cStartX, cStartY, cDieAge);
                                creatures.add(C);
                                std::cout << "A clover has grown! :) " << std::endl;
                                cloverRepeat = false;
                            }
                        }
                    }
                    
                    //Set up dragons
                   
                    for (int i=0; i<dNum; i++) {
                        dragonRepeat = true;
                        while (dragonRepeat) {
                            dStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            dStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if (!(forest1->contains(dStartX, dStartY)) && !(forest2->contains(dStartX, dStartY)) && !(forest1->contains(dStartX+DRAGON_WIDTH, dStartY+DRAGON_HEIGHT)) && !(forest2->contains(dStartX+DRAGON_WIDTH, dStartY+DRAGON_HEIGHT))) {
                                Dragon* D = new Dragon(dStartX, dStartY, dDieAge, dReproduce);
                                creatures.add(D);
                                std::cout << "A dragon has been born! :) " << std::endl;
                                dragonRepeat = false;
                            }
                        }
                    }
                    
                    //Set up unicorns
                    
                    for (int i=0; i<uNum; i++) {
                        unicRepeat = true;
                        while (unicRepeat) {
                            uStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            uStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((forest1->contains(uStartX, uStartY) && forest1->contains(uStartX+UNICORN_WIDTH, uStartY+UNICORN_HEIGHT))
                                ||
                                (forest2->contains(uStartX, uStartY) || forest2->contains(uStartX+UNICORN_WIDTH, uStartY+UNICORN_HEIGHT))) {
                                Unicorn* U = new Unicorn(uStartX, uStartY, uDieAge, uReproduce);
                                creatures.add(U);
                                std::cout << "A unicorn has been born! :) " << std::endl;
                                unicRepeat = false;
                            }
                        }
                    }
                    //Set up crocodiles
                    
                    for (int i=0; i<oNum; i++) {
                        crocRepeat = true;
                        while (crocRepeat) {
                            oStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            oStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((!forest1->contains(oStartX, oStartY)) && (!forest2->contains(oStartX, oStartY)) && (!mountains->contains(oStartX, oStartY)) && (!forest1->contains(oStartX+CROCODILE_WIDTH, oStartY+CROCODILE_HEIGHT)) && (!forest2->contains(oStartX+CROCODILE_WIDTH, oStartY+CROCODILE_HEIGHT)) && (!mountains->contains(oStartX+CROCODILE_WIDTH, oStartY+CROCODILE_HEIGHT))) {
                                Crocodile* O = new Crocodile(oStartX, oStartY, oDieAge, oReproduce);
                                creatures.add(O);
                                std::cout << "A crocodile has been born! :) " << std::endl;
                                crocRepeat=false;
                            }
                        }
                    }
                    
                    //Set up fish
                    
                    for (int i=0; i<hNum; i++) {
                        fishRepeat = true;
                        while (fishRepeat) {
                            hStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            hStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if ((pondrect->contains(hStartX, hStartY)) && (pondrect->contains(hStartX+FISH_WIDTH, hStartY+FISH_HEIGHT))) {
                                Fish* H = new Fish(hStartX, hStartY, hDieAge, hReproduce);
                                creatures.add(H);
                                std::cout << "A fish has been born! :) " << std::endl;
                                fishRepeat = false;
                            }//close if
                        }//close while
                    }//close for
                    
                    //Set up bees
                    for (int i=0; i<eNum; i++) {
                        eStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                        eStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                        Bee* E = new Bee(eStartX, eStartY, eDieAge, vGrow);
                        creatures.add(E);
                        std::cout << "A bee has been born! :) " << std::endl;
                    }
                    
                    //Set up lavenders
                   
                    for (int i=0; i<vNum; i++) {
                        lavRepeat = true;
                        while (lavRepeat) {
                            vStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                            vStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                            if (!pond->contains(vStartX, vStartY) && !mountains->contains(vStartX, vStartY) && !pond->contains(vStartX+LAV_WIDTH, vStartY+LAV_HEIGHT) && !mountains->contains(vStartX+LAV_WIDTH, vStartY+LAV_HEIGHT)) {
                                Lavender* V = new Lavender(vStartX, vStartY, vDieAge);
                                creatures.add(V);
                                std::cout << "A lavender has grown! :) " << std::endl;
                                lavRepeat = false;
                            }
                        }
                    }
                    timer.start();
                    
                } else {
                    std::cout << "You have already started the game. Press CONTINUE." << std::endl;
                }
            } else if (ae.getSource() == pauseButton) {
                timer.stop();
                std::cout << "You have paused the game. The creatures now live in a torturous limbo state" << std::endl;
            } else if (ae.getSource() == continueButton ) {
                if (lT==1) {
                    std::cout << "Please press START" << std::endl;
                } else {
                std::cout << "You have continued the game. The creatures thank you!" << std::endl;;
                timer.start();
                }
                
            } else if (ae.getSource() == restartButton) {
                timer.stop();
                //Clear vector of creatures
                for (int i=0; i<creatures.size(); i++) {
                    creatures[i]->removeCreature(gw);
                }
                creatures.clear();
                //restart leprechaun timer
                lT=1;
                
            } else if (ae.getSource() == quitButton) {
                timer.stop();
                game = false;
            }
        } else if (e.getEventType() == TIMER_TICKED) {
            
            
            //Add leprechaun time and make leprechaun
            lepRepeat = true;
            if (lGrow == 0) {
                std::cout << "Error making leprechaun" << std::endl;
            } else if ((lT > lGrow) && (lT % lGrow == 0)) {
                while (lepRepeat) {
                    lStartX = (rand() % WINDOW_WIDTH + X_CORRECTION);
                    lStartY = (rand() % WINDOW_HEIGHT + Y_CORRECTION);
                    if (!pond->contains(lStartX, lStartY)) {
                        Leprechaun* L = new Leprechaun(lStartX, lStartY, lDieAge, cGrow);
                        creatures.add(L);
                        std::cout << "A leprechaun has appeared! :) " << std::endl;
                        lepRepeat = false;
                    }
                }
                
            } lT++;
            
            //actions
            for (int i=0; i<creatures.size(); i++) {
                
                creatures[i]->die(creatures, gw);
                
                if ((creatures[i]->getAge())<=(creatures[i]->getReproduce())) {
                    creatures[i]->lookForFood(gw,creatures);
                } else if ((creatures[i]->getAge())>(creatures[i]->getReproduce())) {
                    creatures[i]->mate(creatures);
                    
                }
                makeBaby = creatures[i]->move(creatures, gw);
                beeRand = rand() % 10 + 1;
                if ((creatures[i]->getType().compare("Bee") == 0) && (forest1->contains(creatures[i]->getX(),creatures[i]->getY()) || (forest2->contains(creatures[i]->getX(), creatures[i]->getY()))) && beeRand == 1) {
                    std::cout << beeRand << std::endl;
                    Bee* E = new Bee((creatures[i]->getX())+30,(creatures[i]->getY())+30, eDieAge, vGrow);
                    creatures.add(E);
                    std::cout << "A bee has been born! :) " << std::endl;
                } else if (makeBaby) {
                    
                    if ((creatures[i]->getType().compare("Fox") == 0)) {
                        if ((pond->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)))
                            &&
                            (pond->contains((creatures[i]->getX()+30+FOX_WIDTH), (creatures[i]->getY()+30+FOX_HEIGHT)))) {
                            Fox* F = new Fox((creatures[i]->getX())-30, (creatures[i]->getY())-30, fDieAge, fReproduce);
                            creatures.add(F);
                            std::cout << "A fox has been born! :) " << std::endl;
                        } else {
                            Fox* F = new Fox((creatures[i]->getX())+30, (creatures[i]->getY())+30, fDieAge, fReproduce);
                            creatures.add(F);
                            std::cout << "A fox has been born! :) " << std::endl;
                        }
                    }
                    
                    else if ((creatures[i]->getType().compare("Dragon") == 0)) {
                        if ((forest1->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)) || forest2->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)))
                            &&
                            (forest1->contains((creatures[i]->getX()+30+DRAGON_WIDTH), (creatures[i]->getY()+30+DRAGON_HEIGHT)) || forest2->contains((creatures[i]->getX()+30+DRAGON_WIDTH), (creatures[i]->getY()+30+DRAGON_HEIGHT)))) {
                            
                            Dragon* D = new Dragon((creatures[i]->getX())-30, (creatures[i]->getY())-30, dDieAge, dReproduce);
                            creatures.add(D);
                            std::cout << "A dragon has been born!" << std::endl;
                        } else {
                            Dragon* D = new Dragon((creatures[i]->getX())+30, (creatures[i]->getY())+30, dDieAge, dReproduce);
                            creatures.add(D);
                            std::cout << "A dragon has been born!" << std::endl;
                        }
                        
                    } else if ((creatures[i]->getType().compare("Bunny") == 0)) {
                        if ((pond->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)) || mountains->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)))
                            &&
                            (pond->contains((creatures[i]->getX()+30+BUNNY_WIDTH), (creatures[i]->getY()+30+BUNNY_HEIGHT)) || mountains->contains((creatures[i]->getX()+30+BUNNY_WIDTH), (creatures[i]->getY()+30+BUNNY_HEIGHT)))) {
                            Bunny* B = new Bunny((creatures[i]->getX())-30, (creatures[i]->getY())-30, bDieAge, bReproduce);
                            creatures.add(B);
                            std::cout << "A bunny has been born! :) " << std::endl;
                        } else {
                            Bunny* B = new Bunny((creatures[i]->getX())+30, (creatures[i]->getY())+30, bDieAge, bReproduce);
                            creatures.add(B);
                            std::cout << "A bunny has been born! :) " << std::endl;
                        }
                        
                    } else if ((creatures[i]->getType().compare("Leprechaun") == 0)) {
                        if ((pond->contains((creatures[i]->getX()+10), (creatures[i]->getY()+10)) || mountains->contains((creatures[i]->getX()+10), (creatures[i]->getY()+10)))
                            ||
                            (pond->contains((creatures[i]->getX()+10+LAV_WIDTH), (creatures[i]->getY()+10+LAV_HEIGHT)) || mountains->contains((creatures[i]->getX()+10+LAV_WIDTH), (creatures[i]->getY()+10+LAV_HEIGHT)))) {
                        } else {
                        Clover* C = new Clover((creatures[i]->getX())+10, (creatures[i]->getY())+10, cDieAge);
                        creatures.add(C);
                        std::cout << "A clover has grown! :) " << std::endl;
                        }
                    }
                    
                    else if ((creatures[i]->getType().compare("Unicorn") == 0)) {
                        if ((forest1->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)) || forest2->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)))
                            &&
                            (forest1->contains((creatures[i]->getX()+30+UNICORN_WIDTH), (creatures[i]->getY()+30+UNICORN_HEIGHT)) || forest2->contains((creatures[i]->getX()+30+UNICORN_WIDTH), (creatures[i]->getY()+30+UNICORN_HEIGHT)))) {
                            
                            Unicorn* U = new Unicorn((creatures[i]->getX())+30, (creatures[i]->getY())+30, uDieAge, uReproduce);
                            creatures.add(U);
                            std::cout << "A unicorn has been born!" << std::endl;
                        } else {
                            Unicorn* U = new Unicorn((creatures[i]->getX())-30, (creatures[i]->getY())-30, uDieAge, uReproduce);
                            creatures.add(U);
                            std::cout << "A unicorn has been born!" << std::endl;
                        }
                        
                    } else if ((creatures[i]->getType().compare("Crocodile") == 0)) {
                        if ((forest1->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)) || forest2->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)) || mountains->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)))
                            &&
                            (forest1->contains((creatures[i]->getX()+30+CROCODILE_WIDTH), (creatures[i]->getY()+30+CROCODILE_HEIGHT)) || forest2->contains((creatures[i]->getX()+30+CROCODILE_WIDTH), (creatures[i]->getY()+30+CROCODILE_HEIGHT)) || mountains->contains((creatures[i]->getX()+30+CROCODILE_WIDTH), (creatures[i]->getY()+30+CROCODILE_HEIGHT)))) {
                            Crocodile* O = new Crocodile((creatures[i]->getX())-30, (creatures[i]->getY())-30, oDieAge, oReproduce);
                            creatures.add(O);
                            std::cout << "A crocodile has been born! :) " << std::endl;
                        } else {
                            Crocodile* O = new Crocodile((creatures[i]->getX())+30, (creatures[i]->getY())+30, oDieAge, oReproduce);
                            creatures.add(O);
                            std::cout << "A crocodile has been born! :) " << std::endl;
                        }
                    }
                    
                    else if ((creatures[i]->getType().compare("Fish") == 0)) {
                        if ((pondrect->contains((creatures[i]->getX()+30), (creatures[i]->getY()+30)))
                            &&
                            (pondrect->contains((creatures[i]->getX()+30+FISH_WIDTH), (creatures[i]->getY()+30+FISH_HEIGHT)))) {
                            Fish* H = new Fish((creatures[i]->getX())+30, (creatures[i]->getY())+30, hDieAge, hReproduce);
                            creatures.add(H);
                            std::cout << "A fish has been born! :) " << std::endl;
                        } else {
                            Fish* H = new Fish((creatures[i]->getX())-30, (creatures[i]->getY())-30, hDieAge, hReproduce);
                            creatures.add(H);
                            std::cout << "A fish has been born! :) " << std::endl;
                        }
                        
                    } else if ((creatures[i]->getType().compare("Bee") == 0)) {
                        if ((!pond->contains((creatures[i]->getX()+10), (creatures[i]->getY()+10)) && !mountains->contains((creatures[i]->getX()+10), (creatures[i]->getY()+10)))
                            &&
                            (!pond->contains((creatures[i]->getX()+10+LAV_WIDTH), (creatures[i]->getY()+10+LAV_HEIGHT)) && !mountains->contains((creatures[i]->getX()+10+LAV_WIDTH), (creatures[i]->getY()+10+LAV_HEIGHT)))) {
                            
                            Lavender* V = new Lavender((creatures[i]->getX())+10, (creatures[i]->getY())+10, vDieAge);
                            creatures.add(V);
                            std::cout << "A lavender has grown! :) " << std::endl;
                        }
                    }
                    
                    else {
                        std::cout << ("Error making baby") << std::endl;
                    }
                } // end if baby
                
                //Draw background and creatures
                gw.draw(field);
                gw.draw(forest1);
                gw.draw(forest2);
                gw.draw(pond);
                gw.draw(mountains);
                gw.draw(portal1);
                gw.draw(portal2);
                
                creatures[i]->drawCreature(gw);
            } //end creature for loop
            
        } //end timer ticker
        
    } //end while game
    std::cout << "Have a great day! :) ";
    exitGraphics();
    
    return 0;
}

