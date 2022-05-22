#pragma once
#include <string>
#include <map>
#include <unordered_map>
#include <functional>

#include "Platform.h"
#include "Entity.h"

using namespace std;


class CommandHandler
{
private:
   CommandHandler();

   std::map<std::string, bool (CommandHandler::*)(std::string)> func_map{
            {"LEFT", &CommandHandler::Left},
            {"RIGHT", &CommandHandler::Right},
            {"REPORT", &CommandHandler::Report},
            {"PLACE", &CommandHandler::PlaceRobot},
            {"MOVE", &CommandHandler::Move},
            {"END", &CommandHandler::End},
            {"HELP", &CommandHandler::Help},

   };

public:
   static CommandHandler& getInstance() {
      static CommandHandler theInstance;
      return theInstance;
   }

   bool Interpret(string strIn);
   bool ToContinue() { return bContinue; };
private:
   bool bPlace;
   bool bContinue;

   Platform Table;
   std::unique_ptr<Entity> Robot;  

   bool Move(string strIn);
   bool Report(string strIn);
   bool Right(string strIn);
   bool Left(string strIn);
   bool PlaceRobot(string strIn);
   bool End(string strIn);
   bool Help(string strIn);

};

