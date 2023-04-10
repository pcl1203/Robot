#include "Platform.h"

Platform::Platform()
   : uTilesX(0)
   , uTilesY(0)
{
	XLimit.max = 0;
	YLimit.max = 0;
	XLimit.min = 0;
	YLimit.min = 0;
}

bool Platform::SetSize(unsigned char _uTilesX, unsigned char _uTilesY)
{
   if ((_uTilesX == 0) || (_uTilesY == 0)) return false;

   uTilesX = _uTilesX;
   uTilesY = _uTilesY;
   XLimit.max = uTilesX - 1;
   YLimit.max = uTilesY - 1;

   return true;
}

void Platform::GetSize(unsigned char& _uTilesX, unsigned char& _uTilesY)
{
   _uTilesX = uTilesX;
   _uTilesY = uTilesY;
}
