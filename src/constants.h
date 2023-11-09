#ifndef CONSTANTS_H
#define CONSTANTS_H

// Define SCALE to convert between pixels and meters
// Example: 100 pixels = 1 meter
const float SCALE = 100.0f;

// Define collision category: 
const uint16 CATEGORY_BALL = 0x0001;
const uint16 CATEGORY_PADDLE = 0x0002;
const uint16 CATEGORY_WALLS = 0x0004;

#endif
