#pragma once
struct Limit
{
	unsigned char max;
	unsigned char min;
};
class Platform
{
public:
   Platform();
   bool SetSize(unsigned char uTilesX, unsigned char uTilesY); // uTilesX number of Tiles along X-axis, uTilesY number of Tiles along Y-axis, returns true if created successully 
   void GetSize(unsigned char& uTilesX, unsigned char& uTilesY);

   Limit XLimit;
   Limit YLimit;

private:
   unsigned char uTilesX;
   unsigned char uTilesY;
};
