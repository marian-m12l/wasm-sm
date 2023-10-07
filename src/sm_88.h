#pragma once

//#define kPowerBombExplosionFreeSpace ((uint8*)RomFixedPtr(0x88a206))

uint8 kPowerBombExplosionFreeSpace[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

//#define kPowerBombExplosionShapeTopOffset ((uint8*)RomFixedPtr(0x88a286))

uint8 kPowerBombExplosionShapeTopOffset[] = {
	0xbf, 0xbf, 0xbe, 0xbd, 0xba, 0xb8, 0xb6, 0xb2, 0xaf, 0xab, 0xa6, 0xa2, 0x9c, 0x96, 0x90, 0x8a, 
	0x84, 0x7d, 0x75, 0x6e, 0x66, 0x5e, 0x56, 0x4d, 0x45, 0x3c, 0x33, 0x2a, 0x20, 0x17,  0xd,  0x4,
};

//#define kPowerBombExplosionColors ((uint8*)RomFixedPtr(0x888d85))

uint8 kPowerBombExplosionColors[] = {
	 0xe, 0xe, 0xa, 
	 0xf, 0xf, 0x9, 
	0x10,0x10, 0x8, 
	0x11,0x11, 0x7, 
	0x12,0x12, 0x6, 
	0x13,0x13, 0x5, 
	0x14,0x14, 0x4, 
	0x15,0x15, 0x3, 
	0x16,0x16, 0x2, 
	0x17,0x17, 0x1, 
	0x18,0x18, 0x0, 
	0x19,0x19, 0x0, 
	0x1a,0x1a, 0x0, 
	0x1a,0x1a, 0x0, 
	0x1a,0x1a,0x1a, 
	0x1a,0x1a,0x1a, 
	0x1b,0x1b,0x1b, 
	0x1b,0x1b,0x1b, 
	0x1c,0x1c,0x1c, 
	0x1b,0x1b,0x1b, 
	0x1a,0x1a,0x1a, 
	0x1a,0x18,0x18, 
	0x1a,0x17,0x17, 
	0x19,0x16,0x16, 
	0x18,0x15,0x15, 
	0x17,0x15,0x15, 
	0x16,0x14,0x14, 
	0x15,0x13,0x13, 
	0x12,0x10,0x10, 
	0x12, 0xe, 0xe, 
	0x12, 0xd, 0xd, 
	0x12, 0xd, 0xd,
};

//#define kPowerBombPreExplosionColors ((uint8*)RomFixedPtr(0x889079))

uint8 kPowerBombPreExplosionColors[] = {
	0x10,0x10,0x10, 
	 0x4, 0x4, 0x4, 
	 0x6, 0x6, 0x6, 
	 0x8, 0x8, 0x8, 
	 0xa, 0xa, 0xa, 
	 0xc, 0xc, 0xc, 
	 0xe, 0xe, 0xa, 
	0x10,0x10, 0x8, 
	0x12,0x12, 0x8, 
	0x14,0x14, 0x8, 
	0x16,0x16, 0x8, 
	0x18,0x18, 0x8, 
	0x1a,0x1a, 0xa, 
	0x18,0x18, 0x8, 
	0x16,0x16, 0x6, 
	0x14,0x14, 0x4,
};

//#define kBG3XscrollWave ((uint16*)RomFixedPtr(0x88a938))

uint16 kBG3XscrollWave[] = {
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0, 
	   0x0,    0x1,    0x2,    0x3,    0x3,    0x2,    0x1,    0x0,    0x0, 0xffff, 0xfffe, 0xfffd, 0xfffd, 0xfffe, 0xffff,    0x0,
};

//#define kHdmaScrollEntrys ((HdmaScrollEntry*)RomFixedPtr(0x88aec1))

HdmaScrollEntry kHdmaScrollEntrys[] = {
	   0x0, 0x8000,    0x0, 0x9f80,
	  0x10, 0xc000,    0x0, 0x9f84,
	  0x38, 0x8000,    0x0, 0x9f88,
	  0xd0, 0xc000,    0x0, 0x9f8c,
	  0xe0, 0x8000,    0x0, 0x9f90,
	 0x120, 0xc000,    0x0, 0x9f94,
	 0x1a0, 0x8000,    0x0, 0x9f98,
	 0x1d8, 0xc000,    0x0, 0x9f9c,
	 0x238, 0x8000,    0x0, 0x9fa0,
	 0x268, 0xc000,    0x0, 0x9fa4,
	 0x2a0, 0x8000,    0x0, 0x9fa8,
	 0x2e0, 0xc000,    0x0, 0x9fa0,
	 0x300, 0x8000,    0x0, 0x9fb0,
	 0x320, 0xc000,    0x0, 0x9fb4,
	 0x350, 0x8000,    0x0, 0x9fb8,
	 0x378, 0xc000,    0x0, 0x9fbc,
	 0x3c8, 0x8000,    0x0, 0x9fc0,
	 0x440, 0x7000,    0x0, 0x9fc4,
	 0x460, 0xc000,    0x0, 0x9fc8,
	 0x480, 0x8000,    0x0, 0x9fcc,
	 0x490,    0x0,    0x0, 0x9fd0,
	 0x4a8,    0x0,    0x0, 0x9fd4,
	 0x4b8,    0x0,    0x0, 0x9fd8,
	 0x500,
};

//#define kLavaAcidBG2YScrollLongWave ((uint16*)RomFixedPtr(0x88b589))

uint16 kLavaAcidBG2YScrollLongWave[] = {
	   0x0,    0x0,    0x1,    0x1,    0x1,    0x1,    0x0,    0x0, 
	0xffff, 0xffff, 0xffff, 0xffff,    0x0,    0x0,    0x0,    0x0,
};

//#define kLavaAcidBG2YScrollShortWave ((uint16*)RomFixedPtr(0x88b60a))

uint16 kLavaAcidBG2YScrollShortWave[] = {
	   0x0,    0x1,    0x1,    0x0,    0x0, 0xffff, 0xffff,    0x0, 
	   0x0,    0x1,    0x1,    0x0,    0x0, 0xffff, 0xffff,    0x0,
};

//#define kBG3RainXvels ((uint16*)RomFixedPtr(0x88d992))

uint16 kBG3RainXvels[] = {
	0xfa00,  0x600, 0xfc00,  0x400,
};

//#define kSuitPickupLightBeamCurveWidths ((uint8*)RomFixedPtr(0x88e3c9))

uint8 kSuitPickupLightBeamCurveWidths[] = {
	1, 2, 3, 4, 5, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 
	11, 12, 12, 12, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 
	16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 
	19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 21, 21, 
	21, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 22, 
	22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 
	23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24, 24, 24, 
	24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
};

//#define kRainbowBeamHdmaValues ((uint16*)RomFixedPtr(0x88e833))

uint16 kRainbowBeamHdmaValues[] = {
	  0x1f,   0x5f,   0x9f,   0xdf,  0x11f,  0x15f,  0x19f,  0x1df, 
	 0x23f,  0x27f,  0x2bf,  0x2ff,  0x33f,  0x37f,  0x3bf,  0x3ff, 
	 0x3fd,  0x3fb,  0x3f9,  0x3f7,  0x3f5,  0x3f3,  0x3f1,  0x3ef, 
	 0x3ec,  0x3ea,  0x3e8,  0x3e6,  0x3e4,  0x3e2,  0x3e0,  0xba0, 
	0x1360, 0x1b20, 0x22e0, 0x2aa0, 0x3260, 0x3a20, 0x45e0, 0x4d80, 
	0x5540, 0x5d00, 0x64c0, 0x6c80, 0x7440, 0x7c00, 0x7c02, 0x7c04, 
	0x7c06, 0x7c08, 0x7c0a, 0x7c0c, 0x7c0d, 0x7c2f, 0x7c31, 0x7c33, 
	0x7c35, 0x7c37, 0x7c39, 0x7c3b, 0x7c1f, 0x741f, 0x6c1f, 0x641f, 
	0x5c1f, 0x541f, 0x4c1f, 0x441f, 0x3c1f, 0x301f, 0x281f, 0x201f, 
	0x181f, 0x101f,  0x81f, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 
	0xffff, 0xffff, 0xffff,
};

//#define kMorphBallEyeBeamHdmaValues ((uint8*)RomFixedPtr(0x88ea8b))

uint8 kMorphBallEyeBeamHdmaValues[] = {
	48, 80, 128, 0, 
	47, 79, 128, 0, 
	46, 78, 128, 0, 
	45, 77, 128, 0, 
	44, 76, 128, 0, 
	43, 75, 128, 0, 
	42, 74, 128, 0, 
	41, 73, 128, 0, 
	40, 72, 128, 0, 
	41, 73, 128, 0, 
	42, 74, 128, 0, 
	43, 75, 128, 0, 
	44, 76, 128, 0, 
	45, 77, 128, 0, 
	46, 78, 128, 0, 
	47, 79, 128, 0,
};

