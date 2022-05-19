
#include <string>
#include "Robot.h"

Robot::Robot(unsigned char _uPosX, unsigned char _uPosY, FacingOrientation _Orientation)
   : orientation(_Orientation)
   , uPosX(_uPosX)
   , uPosY(_uPosY)
{

}

#pragma region STATUS
unsigned char Robot::GetPosX()
{
   return uPosX;
}

unsigned char Robot::GetPosY()
{
   return uPosY;
}

FacingOrientation Robot::GetOrientation()
{
   return orientation;
}
#pragma endregion


#pragma region MOVEMENTS
FacingOrientation Robot::RotateRight()
{
   orientation = RotateCW(orientation);
   return orientation;
}

FacingOrientation Robot::RotateLeft()
{
   orientation = RotateCCW(orientation);
   return orientation;
}

void Robot::MoveX(bool bFwd)
{
   bFwd ? uPosX++ : uPosX--;
}

void Robot::MoveY(bool bFwd)
{
   bFwd ? uPosY++ : uPosY--;
}
#pragma endregion