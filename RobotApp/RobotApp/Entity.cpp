
#include <string>
#include "Entity.h"

Entity::Entity(unsigned char _uPosX, unsigned char _uPosY, FacingOrientation _Orientation)
   : orientation(_Orientation)
   , uPosX(_uPosX)
   , uPosY(_uPosY)
{

}

#pragma region STATUS
unsigned char Entity::GetPosX()
{
   return uPosX;
}

unsigned char Entity::GetPosY()
{
   return uPosY;
}

FacingOrientation Entity::GetOrientation()
{
   return orientation;
}
#pragma endregion


#pragma region MOVEMENTS
FacingOrientation Entity::RotateRight()
{
   orientation = RotateCW(orientation);
   return orientation;
}

FacingOrientation Entity::RotateLeft()
{
   orientation = RotateCCW(orientation);
   return orientation;
}

void Entity::Move()
{
   if (orientation == FacingOrientation::EAST) uPosX++;
   else if (orientation == FacingOrientation::WEST) uPosX--;
   else if (orientation == FacingOrientation::NORTH) uPosY++;
   else if (orientation == FacingOrientation::SOUTH) uPosY--;
}
#pragma endregion