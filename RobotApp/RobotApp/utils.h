#pragma once
#include <type_traits>

using namespace std;

enum class FacingOrientation {
   NORTH,
   EAST,
   SOUTH,
   WEST,
   NUMBER_OF_DIRECTIONS
};

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