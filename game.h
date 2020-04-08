
// Player Struct
typedef struct {
	int row;
	int col;
    int width;
    int height;
    int state;
    int cdel;
    int rdel;
    int prevAniState;
    int anime;
    int numFrames;
} PLAYER;



typedef struct {
    int row;
    int col;
    int anime;
    int active;
    int numFrames;
} OXYGEN;

typedef struct {
    int row;
    int col;
    int active;
    int anime;
    int numFrames;
} CRYSTAL;

typedef struct {
    int row;
    int col;
    int active;
} OBSTACLE;

// Constants
#define CRYSTALMAX (3)
#define MAXOB (3)
#define OXYMAX (5)
#define MAPHEIGHT 256
#define MAPWIDTH 512


// Variables
PLAYER player;
int snakeLen;

// Arrays
CRYSTAL crystals[CRYSTALMAX];
OXYGEN oxygen[OXYMAX];
OBSTACLE obstacle[MAXOB];


// Used to handle player direction states
enum {UP, DOWN, LEFT, RIGHT};


// Prototypes
void initGame();
void initPlayer();
void initCrystals();
void initObstacle();
void initOxygen();
void drawGame();
void drawPlayer();
void drawOxygen(OXYGEN *);
void drawCrystal(CRYSTAL *);
void drawObstacle(OBSTACLE *);
void updateGame();
void updatePlayer();
void updateCrystal(CRYSTAL *);
void updateOxygen(OXYGEN *);
void updateObstacle(OBSTACLE *);

