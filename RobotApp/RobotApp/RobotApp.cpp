// RobotApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

#include "CommandHandler.h"

using namespace std;

int main(int argc, char* argv[])
{
   if (argc < 2) {
      std::cout << "Robot on the Table\n";
      std::cout << "------------------\n";
      while (CommandHandler::getInstance().ToContinue()) {
         string strUserInput;
         getline(cin, strUserInput);

         CommandHandler::getInstance().Interpret(strUserInput);
      }
   } else {

      std::ifstream file(argv[1]);
      if (!file.is_open()) {
         std::cout << "File not found" << std::endl;
         return -1;
      }
      std::cout << "Robot on the Table\n";
      std::cout << "------------------\n";
      std::string strLine;
      while (CommandHandler::getInstance().ToContinue() && 
         std::getline(file, strLine))
      {
         std::cout << strLine << "\n";;
         CommandHandler::getInstance().Interpret(strLine);
      }
   }

   return 0;
}
