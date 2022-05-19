#pragma once

#include <string>
#include "utils.h"

using namespace std;


class Robot
{
public:
   Robot(unsigned char uPosX, unsigned char uPosy, FacingOrientation orientation);
   // Status
   unsigned char GetPosX(); // Returns X coordinates
   unsigned char GetPosY(); // Returns Y coordinates
   FacingOrientation GetOrientation(); // Returns where the robot is facing
   // Movements
   FacingOrientation RotateRight(); // Rotates the robot clockwise by 90 degrees, returns where the robot is currently facing
   FacingOrientation RotateLeft();  // Rotates the robot counterclockwise by 90 degrees, returns where the robot is currently facing
   void MoveX(bool bFwd = true);    // Moves the robot along x-axis
   void MoveY(bool bFwd = true);    // Moves the robot along y-axis

private:
   FacingOrientation orientation;
   unsigned char uPosX;
   unsigned char uPosY;
};

