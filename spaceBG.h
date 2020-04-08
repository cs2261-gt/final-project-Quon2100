
//{{BLOCK(spaceBG)

//======================================================================
//
//	spaceBG, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 1122 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 35904 + 4096 = 40512
//
//	Time-stamp: 2020-04-07, 14:25:11
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPACEBG_H
#define GRIT_SPACEBG_H

#define spaceBGTilesLen 35904
extern const unsigned short spaceBGTiles[17952];

#define spaceBGMapLen 4096
extern const unsigned short spaceBGMap[2048];

#define spaceBGPalLen 512
extern const unsigned short spaceBGPal[256];

#endif // GRIT_SPACEBG_H

//}}BLOCK(spaceBG)
