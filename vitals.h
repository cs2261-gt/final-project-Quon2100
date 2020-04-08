
//{{BLOCK(vitals)

//======================================================================
//
//	vitals, 512x256@4, 
//	+ palette 256 entries, not compressed
//	+ 26 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 64x32 
//	Total size: 512 + 832 + 4096 = 5440
//
//	Time-stamp: 2020-04-08, 01:57:35
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_VITALS_H
#define GRIT_VITALS_H

#define vitalsTilesLen 832
extern const unsigned short vitalsTiles[416];

#define vitalsMapLen 4096
extern const unsigned short vitalsMap[2048];

#define vitalsPalLen 512
extern const unsigned short vitalsPal[256];

#endif // GRIT_VITALS_H

//}}BLOCK(vitals)
