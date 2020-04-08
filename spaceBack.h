
//{{BLOCK(spaceBack)

//======================================================================
//
//	spaceBack, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 2034 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 65088 + 4096 = 69696
//
//	Time-stamp: 2020-04-08, 01:35:02
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPACEBACK_H
#define GRIT_SPACEBACK_H

#define spaceBackTilesLen 65088
extern const unsigned short spaceBackTiles[32544];

#define spaceBackMapLen 4096
extern const unsigned short spaceBackMap[2048];

#define spaceBackPalLen 512
extern const unsigned short spaceBackPal[256];

#endif // GRIT_SPACEBACK_H

//}}BLOCK(spaceBack)
