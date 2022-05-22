#pragma once
#include <type_traits>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using std::string;
using std::endl;
using std::transform;
using std::toupper;

static string CapitalizeString(string s)
{
   transform(s.begin(), s.end(), s.begin(),
      [](unsigned char c) { return toupper(c); });
   return s;
}

enum class FacingOrientation {
   NORTH,
   EAST,
   SOUTH,
   WEST,
   NUMBER_OF_DIRECTIONS
};

static FacingOrientation ConvertOrientation(std::string& strIn) {
   if (CapitalizeString(strIn) == "NORTH") return FacingOrientation::NORTH;
   else if (CapitalizeString(strIn) == "EAST") return FacingOrientation::EAST;
   else if (CapitalizeString(strIn) == "SOUTH") return FacingOrientation::SOUTH;
   else if (CapitalizeString(strIn) == "WEST") return FacingOrientation::WEST;

   return FacingOrientation::NUMBER_OF_DIRECTIONS;
}

static string ConvertOrientationToString(FacingOrientation orientation) {
   switch (orientation)
   {
      case FacingOrientation::NORTH: return "NORTH";
      case FacingOrientation::EAST: return "EAST";
      case FacingOrientation::SOUTH: return "SOUTH";
      case FacingOrientation::WEST: return "WEST";
      default:
         break;
   }

   return "";
}

constexpr FacingOrientation RotateCCW(FacingOrientation d) {
   using ut = underlying_type<FacingOrientation>::type;
   return (FacingOrientation)((ut(d) + ut(FacingOrientation::NUMBER_OF_DIRECTIONS) - 1)
      % ut(FacingOrientation::NUMBER_OF_DIRECTIONS));
}

constexpr FacingOrientation RotateCW(FacingOrientation d) {
   using ut = underlying_type<FacingOrientation>::type;
   return (FacingOrientation)((ut(d) + ut(FacingOrientation::NUMBER_OF_DIRECTIONS) + 1)
      % ut(FacingOrientation::NUMBER_OF_DIRECTIONS));
}

static std::string& ltrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
   str.erase(0, str.find_first_not_of(chars));
   return str;
}

static std::string& rtrim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
   str.erase(str.find_last_not_of(chars) + 1);
   return str;
}

static std::string& trim(std::string& str, const std::string& chars = "\t\n\v\f\r ")
{
   return ltrim(rtrim(str, chars), chars);
}

static std::string tokenize(std::string& strIn, const std::string& delimiter = " ")
{
   std::size_t found= strIn.find(delimiter);
   std::string str = "";
   if (found != std::string::npos) {
      str = strIn.substr(0, found); // Get the Y coordinate
      strIn.erase(0, found);
      strIn = trim(strIn, delimiter); // Remove Delimiter
      strIn = trim(strIn); // Remove extra spaces if any
   }
   return str;
}