#include <stdlib.h>
#include "myLib.h"
#include "game.h"





// Global variables
int timer;
int oxyLevel;
int crystalCount;

// Initialize the game
void initGame() {


 	initPlayer();
    initCrystals();
    initOxygen();
    initObstacle();
}
void initPlayer() {
	player.width = 16;
    player.height = 16;
    player.row = (MAPWIDTH / 16) - 20;
    player.col = (MAPHEIGHT / 4) - 14;
    player.cdel = 1;
    player.rdel = 1;
    
}
void initCrystals() {
    for (int i = 0; i < CRYSTALMAX; i++) {
        crystals[i].row = 260; //set to be offscreen
        crystals[i].col = rand() % SCREENHEIGHT; 
        crystals[i].active = 1;
    }
}

void initOxygen() {
    for (int i = 0; i < OXYMAX; i++) {
        oxygen[i].row = 245;
        oxygen[i].col = rand() % SCREENHEIGHT;
        oxygen[i].active = 1;
    }
}

void initObstacle() {
    for (int i = 0; i < MAXOB; i++) {
        obstacle[i].row = 265;
        obstacle[i].col = rand() % SCREENHEIGHT;
        obstacle[i].active = 1;
    }
}

void drawGame() {
    drawPlayer();
    for (int i = 0; i < CRYSTALMAX; i++) {
        drawCrystal(&crystals[i]);
    }
    for (int i = 0; i < OXYMAX; i++) {
        drawOxygen(&oxygen[i]);
    }
    for (int i = 0; i < CRYSTALMAX; i++) {
        drawObstacle(&obstacle[i]);
    }
}
void drawPlayer() {
    shadowOAM[0].attr0 = player.col | ATTR0_REGULAR | ATTR0_SQUARE | ATTR0_4BPP;
    shadowOAM[0].attr1 = player.row | ATTR1_SMALL;
    shadowOAM[0].attr2 = ATTR2_TILEID(0,0);
}
 void drawCrystal(CRYSTAL* c) {

     if (c->active) {
        shadowOAM[1].attr0 = c->col | ATTR0_REGULAR | ATTR0_TALL | ATTR0_4BPP;
        shadowOAM[1].attr1 = c->row | ATTR1_TINY;
        shadowOAM[1].attr2 = ATTR2_TILEID(4,0);
     }
    //  for (int i = 0; i < CRYSTALMAX; i++) {
    //     shadowOAM[1].attr0 = crystals[i].col | ATTR0_REGULAR | ATTR0_TALL | ATTR0_4BPP;
    //     shadowOAM[1].attr1 = crystals[i].row | ATTR1_TINY;
    //     shadowOAM[1].attr2 = ATTR2_TILEID(4,0);
    //  }    
}
void drawOxygen(OXYGEN* o) {
    if (o->active) {
        shadowOAM[2].attr0 = o->col | ATTR0_REGULAR | ATTR0_WIDE | ATTR0_4BPP;
        shadowOAM[2].attr1 = o->row | ATTR1_TINY;
        shadowOAM[2].attr2 = ATTR2_TILEID(2,0);
    }
}
void drawObstacle(OBSTACLE* a) {
    if (a->active) {
        shadowOAM[3].attr0 = a->col | ATTR0_REGULAR | ATTR0_SQUARE | ATTR0_4BPP;
        shadowOAM[3].attr1 = a->row | ATTR1_LARGE;
        shadowOAM[3].attr2 = ATTR2_TILEID(6,0);
    }
}

void updatePlayer() {

    if(BUTTON_HELD(BUTTON_UP)) {
        if (!(player.col <= 0)) {
            player.col -= player.cdel;
        }
    }
    if(BUTTON_HELD(BUTTON_DOWN)) {
        if (!(player.col >= 144)) {
            player.col += player.cdel;
        }
    }
}
void updateCrystal(CRYSTAL* c) {
    if (c->active) {
        if (c->row >= 0) {
            c->row -= 2;
        } else {
            c->active = 0;
        }
    }
    for (int i = 0; i < CRYSTALMAX; i++) {
			if (crystals[i].active) {
				if (collision(player.col, player.row, player.width, player.height,
				c->col, c->row, 8, 16)) {
					c->active = 0;
					crystalCount++;
			}
		}
	}
}
void updateOxygen(OXYGEN* o) {
    if (o->active) {
        if (o->row >= 0) {
            o->row -= 1;
        } else {
            o->active = 0;
        }
    }
}
void updateObstacle(OBSTACLE* a) {
    if (a->active) {
        if (a->row >= 0) {
            a->row -= 1;
        } else {
            a->active = 0;
       }
    }
}
// Updates the game each frame
 void updateGame() {
	updatePlayer();
    for (int i = 0; i < CRYSTALMAX; i++) {
        updateCrystal(&crystals[i]);
        crystals[i].active = 1;
    }
	for (int i = 0; i < OXYMAX; i++) {
        updateOxygen(&oxygen[i]);
    }
    for (int i = 0; i < MAXOB; i++) {
        updateObstacle(&obstacle[i]);
    }
    
}






