#pragma once

#include <string>
#include "utils.h"
#include "Movement.h"

using namespace std;


class Entity: public Movement
{
public:
   Entity(unsigned char uPosX, unsigned char uPosy, FacingOrientation orientation);
   // Status
   unsigned char GetPosX(); // Returns X coordinates
   unsigned char GetPosY(); // Returns Y coordinates
   std::string GetOrientation(); // Returns where the robot is facing
   // Movements
   void RotateRight(); // Rotates the robot clockwise by 90 degrees
   void RotateLeft();  // Rotates the robot counterclockwise by 90 degrees
   void Move(Platform&); // Moves the robot depending on its Axis

private:
   Coords currPosition;
   std::shared_ptr<Moves> currLocation;
};

