#include "myLib.h"
#include "spaceSplash.h"
#include "spaceBack.h"
#include "spacePause.h"
#include "space.h"
#include "vitals.h"
#include "loseBG.h"
#include "winner.h"
#include "m1sprites.h"


unsigned short buttons;
unsigned short oldButtons;




OBJ_ATTR shadowOAM[128];
// Altered to determine which state game is in
int state;
// Variables for cursor
int curRow = 104;
int curCol = 86;
// Horizontal Offset
unsigned short hOff;
// Prototypes for states
void initialize();
void initGame();
void updateGame();
void drawGame();
void goToStart();
void goToPause();
void goToGame();
void gotToLose();
void goToWin();
void drawCursor();
void start();
void pause();
void game();
void lose();
void win();

enum { START, GAME, PAUSE, WIN, LOSE};
int main() {

    initialize(); 

	while(1) {

        oldButtons = buttons;
        buttons = BUTTONS;
    
        // State machine 
        switch (state) {
            case START:
                start();
                break;
            case PAUSE:
                pause();
                break;
            case GAME:
                game();
                break;
            case WIN:
                win();
                break;
            case LOSE:
                lose();
                break;
        }
    }
    return 0;
}


void initialize() {

    REG_DISPCTL = MODE0 | BG1_ENABLE | SPRITE_ENABLE;
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(28) | BG_SIZE_SMALL;

    
  

    goToStart();
    hOff = 0;
}
void drawCursor() {
    shadowOAM[0].attr0 = curCol | ATTR0_REGULAR | ATTR0_SQUARE | ATTR0_4BPP;
    shadowOAM[0].attr1 = curRow | ATTR1_SMALL;
    shadowOAM[0].attr2 = ATTR2_TILEID(0, 0);
}

void goToStart() {
    // Displays start screen
    REG_DISPCTL = MODE0 | BG1_ENABLE | SPRITE_ENABLE;
    REG_BG1CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(28) | BG_SIZE_SMALL;
    DMANow(3, spaceSplashPal, PALETTE, 256);
    DMANow(3, spaceSplashTiles, &CHARBLOCK[0], spaceSplashTilesLen / 2);
    DMANow(3, spaceSplashMap, &SCREENBLOCK[28], spaceSplashMapLen / 2);

    DMANow(3, m1spritesPal, SPRITEPALETTE, 256);
    DMANow(3, m1spritesTiles, &CHARBLOCK[4], m1spritesTilesLen / 2);
    hideSprites();
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    curRow = 104;
    curCol = 86;
    state = START;
}

void goToPause() {
    
    // The pause screen 
    DMANow(3, spacePausePal, PALETTE, 256);
    DMANow(3, spacePauseTiles, &CHARBLOCK[0], spacePauseTilesLen / 2);
    DMANow(3, spacePauseMap, &SCREENBLOCK[25], spacePauseMapLen / 2);

    DMANow(3, m1spritesPal, SPRITEPALETTE, 256);
    DMANow(3, m1spritesTiles, &CHARBLOCK[4], m1spritesTilesLen / 2);
    hideSprites();
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    curRow = 60;
    curCol = 68;
    state = PAUSE;
}

void goToGame() {
    

    REG_DISPCTL = MODE0 | BG1_ENABLE | BG2_ENABLE | BG3_ENABLE | SPRITE_ENABLE; 
    REG_BG1CNT = BG_CHARBLOCK(3) | BG_SCREENBLOCK(23) | BG_SIZE_WIDE | BG_4BPP; // oxygen + crystals count
    REG_BG2CNT = BG_CHARBLOCK(0) | BG_SCREENBLOCK(25) | BG_SIZE_WIDE | BG_4BPP; // main bg
    REG_BG3CNT = BG_CHARBLOCK(2) | BG_SCREENBLOCK(27) | BG_SIZE_WIDE | BG_4BPP; // deep space

    DMANow(3, vitalsPal, PALETTE, 256); // shared pallete

    DMANow(3, spaceTiles, &CHARBLOCK[0], spaceTilesLen / 2); //deep space
    DMANow(3, spaceMap, &SCREENBLOCK[28], spaceMapLen / 2);

    DMANow(3, spaceBackTiles, &CHARBLOCK[0], spaceBackTilesLen / 2); //main bg
    DMANow(3, spaceBackMap, &SCREENBLOCK[25], spaceBackMapLen / 2);

    DMANow(3, vitalsTiles, &CHARBLOCK[3], vitalsTilesLen / 2); //oxygen + crystals
    DMANow(3, vitalsMap, &SCREENBLOCK[23], vitalsMapLen / 2);

    DMANow(3, m1spritesPal, SPRITEPALETTE, 256);
    DMANow(3, m1spritesTiles, &CHARBLOCK[4], m1spritesTilesLen / 2);

    hideSprites();
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    state = GAME;
}

void goToLose() {
    
    hideSprites();

    REG_DISPCTL = MODE0 | BG1_ENABLE; 
    // Displays lose screen
    DMANow(3, loseBGPal, PALETTE, 256);
    DMANow(3, loseBGTiles, &CHARBLOCK[3], loseBGTilesLen / 2);
    DMANow(3, loseBGMap, &SCREENBLOCK[23], loseBGMapLen / 2);

    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    state = LOSE;
}

void goToWin() {

    hideSprites();
    // Displays win screen
    REG_DISPCTL = MODE0 | BG1_ENABLE; 
    DMANow(3, winnerPal, PALETTE, 256);
    DMANow(3, winnerTiles, &CHARBLOCK[3], winnerTilesLen / 2);
    DMANow(3, winnerMap, &SCREENBLOCK[23], winnerMapLen / 2);
    
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);

    state = WIN;
}

void start() {

    drawCursor();
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);
    if(BUTTON_PRESSED(BUTTON_DOWN)) {
        if (curCol < 80) {
            curCol += 35;
        }
    }
    if(BUTTON_PRESSED(BUTTON_UP)) {
        if (curCol > 60) {
            curCol -= 35;
        }
    }
    if(BUTTON_PRESSED(BUTTON_START)) {
        if (curCol == 86) {
            initGame();
            hOff = 0;
            REG_BG1HOFF = hOff;
            goToGame();
        } else if (curCol == 121) {
            //goToInstructions();
        }
    }
}

void pause() {

    drawCursor();
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);
    if(BUTTON_PRESSED(BUTTON_DOWN)) {
        if (curCol < 200) {
            curCol += 34;
        }
    }
    if(BUTTON_PRESSED(BUTTON_UP)) {
        if (curCol > 60) {
            curCol -= 34;
        }
    }
    if(BUTTON_PRESSED(BUTTON_START)) {
        if (curCol == 68) {
            goToGame();
        } else if (curCol == 102) {
            //goToInstructions();
        } else if (curCol > 102) {
            hOff = 0;
            REG_BG1HOFF = hOff;
            goToStart();
        }
    }
}

void game() {
    updateGame();
    drawGame();
    hOff++;
    waitForVBlank();
    DMANow(3, shadowOAM, OAM, 128 * 4);
    
    if (BUTTON_PRESSED(BUTTON_START)) {
        hOff = 0;
        REG_BG1HOFF = hOff;
        goToPause();
    }
    if (BUTTON_PRESSED(BUTTON_A)) {
        hOff = 0;
        REG_BG1HOFF = hOff;
        goToWin();
    }
    if (BUTTON_PRESSED(BUTTON_B)) {
        hOff = 0;
        REG_BG1HOFF = hOff;
        goToLose();
    }
    //REG_BG1HOFF = hOff / 2;
    
}

void win() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        hOff = 0;
        REG_BG1HOFF = hOff;
        goToStart();
    }
}

void lose() {
    if (BUTTON_PRESSED(BUTTON_START)) {
        hOff = 0;
        REG_BG1HOFF = hOff;
        goToStart();
    }
}