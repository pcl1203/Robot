#pragma once

class Platform
{
public:
   Platform();
   bool SetSize(unsigned char uTilesX, unsigned char uTilesY); // uTilesX number of Tiles along X-axis, uTilesY number of Tiles along Y-axis, returns true if created successully 
   void GetSize(unsigned char& uTilesX, unsigned char& uTilesY);
private:
   unsigned char uTilesX;
   unsigned char uTilesY;
};
