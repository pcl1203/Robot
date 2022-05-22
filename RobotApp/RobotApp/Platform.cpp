#include "Platform.h"

Platform::Platform()
   : uTilesX(0)
   , uTilesY(0)
{

}

bool Platform::SetSize(unsigned char _uTilesX, unsigned char _uTilesY)
{
   if ((_uTilesX == 0) || (_uTilesY == 0)) return false;

   uTilesX = _uTilesX;
   uTilesY = _uTilesY;

   return true;
}

void Platform::GetSize(unsigned char& _uTilesX, unsigned char& _uTilesY)
{
   _uTilesX = uTilesX;
   _uTilesY = uTilesY;
}
