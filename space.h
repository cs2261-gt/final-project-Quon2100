
//{{BLOCK(space)

//======================================================================
//
//	space, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 965 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 30880 + 4096 = 35488
//
//	Time-stamp: 2020-04-08, 01:38:56
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPACE_H
#define GRIT_SPACE_H

#define spaceTilesLen 30880
extern const unsigned short spaceTiles[15440];

#define spaceMapLen 4096
extern const unsigned short spaceMap[2048];

#define spacePalLen 512
extern const unsigned short spacePal[256];

#endif // GRIT_SPACE_H

//}}BLOCK(space)
