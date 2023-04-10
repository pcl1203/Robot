#include <fstream>

#include "CommandHandler.h"
#include "utils.h"

#define TABLE_TILES_LENGTH 5 // X - Axis
#define TABLE_TILES_WIDTH  5 // Y - Axis
#define DELIMITER_CMD          " "
#define DELIMITER_ARG          ","

bool CommandHandler::PlaceRobot(string strIn)
{
   std::string strX = tokenize(strIn, DELIMITER_ARG); // Get the X Coord
   std::string strY = tokenize(strIn, DELIMITER_ARG); // Get the Y Coord
   std::string strOrientation = strIn; // Get the remaining token as Facing orientation

   try {
      unsigned char uCoordX = unsigned char(stoul(strX));
      unsigned char uCoordY = unsigned char(stoul(strY));
      FacingOrientation faced = ConvertOrientation(strOrientation);
      if ((faced != FacingOrientation::NUMBER_OF_DIRECTIONS) || // Wrong orientation
         (uCoordX >= TABLE_TILES_LENGTH) ||  // Robot is placed outside of the box
         (uCoordY >= TABLE_TILES_WIDTH)) {   // Robot is placed outside of the box
         Robot.reset(new Entity(uCoordX, uCoordY, faced));
         bPlace = true;
         return true;
      }
      else return false;
   }
   catch (std::invalid_argument e) {
      // Invalid Argument format
      return false;
   }

   return false;
}

bool CommandHandler::Left(string)
{
   if (!bPlace) return false;
   Robot->RotateLeft();
   return true;
}

bool CommandHandler::Right(string)
{
   if (!bPlace) return false;
   Robot->RotateRight();
   return true;
}

bool CommandHandler::End(string)
{
   bContinue = false;
   return true;
}

bool CommandHandler::Help(string)
{
   std::ifstream file("./help.txt");
   if (!file.is_open()) {
      std::cout << "File not found" << std::endl;
      return false;
   }
   std::string strLine;
   std::cout << "\n";
   while (std::getline(file, strLine))
   {
      std::cout << strLine << "\n";
   }
   std::cout << "\n";

   return true;
}

bool CommandHandler::Report(string)
{
   if (!bPlace) {
      std::cout << "No robot found!\r\n";
      return false;
   }
   std::cout << "Robot Placement: ";
   std::cout << (int)Robot->GetPosX() << ", ";
   std::cout << (int)Robot->GetPosY() << ", ";
   std::cout << Robot->GetOrientation() << "\r\n";

   return true;
}

bool CommandHandler::Move(string)
{
    if (!bPlace) return false;

    Robot->Move(Table);

    return true;
}

bool CommandHandler::Interpret(string strIn)
{
   string strCapitalize = CapitalizeString(strIn);

   std::string cmd = strCapitalize.substr(0, strCapitalize.find(DELIMITER_CMD)); // Get the first argument

   auto func = func_map.find(cmd);
   if (func == func_map.end()) return false;

   std::string args = strCapitalize.erase(0, strCapitalize.find(" ") + string(DELIMITER_CMD).length());
   return (this->*func->second)(args); // Execute command
}

CommandHandler::CommandHandler() : bPlace(false) , bContinue(true)
{
   Table.SetSize(TABLE_TILES_LENGTH, TABLE_TILES_WIDTH);
}
