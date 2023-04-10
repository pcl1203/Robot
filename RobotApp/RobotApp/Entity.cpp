
#include <string>
#include "Entity.h"

Entity::Entity(unsigned char _uPosX, unsigned char _uPosY, FacingOrientation _Orientation)
{
	currPosition.x = _uPosX;
	currPosition.y = _uPosY;
	currLocation = ExtractOrientation(ConvertOrientationToString(_Orientation));
}

#pragma region STATUS
unsigned char Entity::GetPosX()
{
   return currPosition.x;
}

unsigned char Entity::GetPosY()
{
   return currPosition.y;
}

std::string Entity::GetOrientation()
{
	return currLocation->faced;
}
#pragma endregion


#pragma region MOVEMENTS
void Entity::RotateRight()
{
	currLocation = currLocation->cw;
}

void Entity::RotateLeft()
{
	currLocation = currLocation->ccw;
}

void Entity::Move(Platform& p)
{
	currLocation->fwd(&currPosition, p);
}
#pragma endregion