#include "pch.h"
#include <string>
#include "CppUnitTest.h"
#include "../RobotApp/Entity.cpp"
#include "../RobotApp/Platform.cpp"
#include "../RobotApp/Movement.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	Platform Table;
	TEST_CLASS(ENTITY)
	{
	public:

		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Table.SetSize(5, 5);
		}
		#pragma region STATUS
		TEST_METHOD(GetOrientation)
		{
			Entity robot(0, 1, FacingOrientation::NORTH);
			Assert::AreEqual(std::string("NORTH"), robot.GetOrientation());
		}

		TEST_METHOD(GetPosX)
		{
			Entity robot(2, 1, FacingOrientation::EAST);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
		}

		TEST_METHOD(GetPosY)
		{
			Entity robot(0, 3, FacingOrientation::WEST);
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}
		#pragma endregion


		#pragma region ROTATE
		TEST_METHOD(RotateRight)
		{
			Entity robot(0, 1, FacingOrientation::NORTH);
			robot.RotateRight();
			Assert::AreEqual(std::string("EAST"), robot.GetOrientation());
		}

		TEST_METHOD(RotateLeft)
		{
			Entity robot(2, 1, FacingOrientation::EAST);
			robot.RotateLeft();
			Assert::AreEqual(std::string("NORTH"), robot.GetOrientation());
		}
		#pragma endregion


		#pragma region MOVE
		TEST_METHOD(Move_X_FWD)
		{
			Entity robot(0, 3, FacingOrientation::EAST);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(1), robot.GetPosX());
			robot.Move(Table);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}

		TEST_METHOD(Move_X_BWD)
		{
			Entity robot(3, 3, FacingOrientation::WEST);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			robot.Move(Table);
			Assert::AreEqual(unsigned char(1), robot.GetPosX());
		}

		TEST_METHOD(Move_X_FWD_BWD)
		{
			Entity robot(3, 3, FacingOrientation::EAST);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(4), robot.GetPosX());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move(Table);
			Assert::AreEqual(unsigned char(3), robot.GetPosX());
			robot.Move(Table);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move(Table);
			Assert::AreEqual(unsigned char(3), robot.GetPosX());
		}

		TEST_METHOD(Move_X_Limit_Max)
		{
			Entity robot(0xff, 3, FacingOrientation::EAST);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(0xff), robot.GetPosX());
		}

		TEST_METHOD(Move_X_Limit_Min)
		{
			Entity robot(0, 3, FacingOrientation::WEST);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(0), robot.GetPosX());
		}

		TEST_METHOD(Move_Y_FWD)
		{
			Entity robot(0, 3, FacingOrientation::NORTH);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			robot.Move(Table); // exceeds
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			Assert::AreEqual(unsigned char(0), robot.GetPosX());
		}

		TEST_METHOD(Move_Y_BWD)
		{
			Entity robot(3, 3, FacingOrientation::SOUTH);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(2), robot.GetPosY());
			robot.Move(Table);
			Assert::AreEqual(unsigned char(1), robot.GetPosY());
		}

		TEST_METHOD(Move_Y_FWD_BWD)
		{
			Entity robot(3, 3, FacingOrientation::NORTH);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move(Table);
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
			robot.Move(Table);
			Assert::AreEqual(unsigned char(2), robot.GetPosY());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move(Table);
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}

		TEST_METHOD(Move_Y_Limit_Max)
		{
			Entity robot(0xff, 0xff, FacingOrientation::NORTH);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(0xff), robot.GetPosY());
		}

		TEST_METHOD(Move_Y_Limit_Min)
		{
			Entity robot(0, 0, FacingOrientation::SOUTH);
			robot.Move(Table);
			Assert::AreEqual(unsigned char(0), robot.GetPosY());
		}
		#pragma endregion

	};
	TEST_CLASS(PLATFORM)
	{
	public:
		TEST_METHOD(ValidSize)
		{
			Platform table;
			Assert::AreEqual(true, table.SetSize(1, 4));

			unsigned char uTilesX = 0;
			unsigned char uTilesY = 0;

			table.GetSize(uTilesX, uTilesY);
			Assert::AreEqual(unsigned char(1), uTilesX);
			Assert::AreEqual(unsigned char(4), uTilesY);
		}

		TEST_METHOD(InvalidSize)
		{
			Platform table;
			Assert::AreEqual(false, table.SetSize(0, 0));

			unsigned char uTilesX = 1;
			unsigned char uTilesY = 2;

			table.GetSize(uTilesX, uTilesY);
			Assert::AreEqual(unsigned char(0), uTilesX);
			Assert::AreEqual(unsigned char(0), uTilesY);
		}

		TEST_METHOD(NoSize)
		{
			Platform table;

			unsigned char uTilesX = 1;
			unsigned char uTilesY = 2;

			table.GetSize(uTilesX, uTilesY);
			Assert::AreEqual(unsigned char(0), uTilesX);
			Assert::AreEqual(unsigned char(0), uTilesY);
		}
	};
	TEST_CLASS(MOVEMENT)
	{

		TEST_CLASS_INITIALIZE(ClassInitialize)
		{
			Table.SetSize(5, 5);
		}
		TEST_METHOD(ExtractOrientation_NORTH)
		{
			Movement test;
			auto ptr_moves = test.ExtractOrientation("NORTH");
			Assert::AreEqual(std::string("NORTH"), ptr_moves->faced);

			auto ptr_ccw = ptr_moves->ccw;
			Assert::AreEqual(std::string("WEST"), ptr_ccw->faced);

			auto ptr_cw = ptr_moves->cw;
			Assert::AreEqual(std::string("EAST"), ptr_cw->faced);

			Coords coords(0, 0);
			ptr_moves->fwd(&coords, Table);
			Assert::AreEqual((uint8_t)0, coords.x);
			Assert::AreEqual((uint8_t)1, coords.y);

			Coords coords2(0, 4);
			ptr_moves->fwd(&coords2, Table);
			Assert::AreEqual((uint8_t)0, coords2.x);
			Assert::AreEqual((uint8_t)4, coords2.y); // no movement due to table has only 5 tiles
		}
		TEST_METHOD(ExtractOrientation_SOUTH)
		{
			Movement test;
			auto ptr_moves = test.ExtractOrientation("SOUTH");
			Assert::AreEqual(std::string("SOUTH"), ptr_moves->faced);

			auto ptr_ccw = ptr_moves->ccw;
			Assert::AreEqual(std::string("EAST"), ptr_ccw->faced);

			auto ptr_cw = ptr_moves->cw;
			Assert::AreEqual(std::string("WEST"), ptr_cw->faced);

			Coords coords(0, 0);
			ptr_moves->fwd(&coords, Table);
			Assert::AreEqual((uint8_t)0, coords.x);
			Assert::AreEqual((uint8_t)0, coords.y); // no movement

			Coords coords2(1, 4);
			ptr_moves->fwd(&coords2, Table);
			Assert::AreEqual((uint8_t)1, coords2.x);
			Assert::AreEqual((uint8_t)3, coords2.y);
		}
		TEST_METHOD(ExtractOrientation_EAST)
		{
			Movement test;
			auto ptr_moves = test.ExtractOrientation("EAST");
			Assert::AreEqual(std::string("EAST"), ptr_moves->faced);

			auto ptr_ccw = ptr_moves->ccw;
			Assert::AreEqual(std::string("NORTH"), ptr_ccw->faced);

			auto ptr_cw = ptr_moves->cw;
			Assert::AreEqual(std::string("SOUTH"), ptr_cw->faced);

			Coords coords(0, 0);
			ptr_moves->fwd(&coords, Table);
			Assert::AreEqual((uint8_t)1, coords.x);
			Assert::AreEqual((uint8_t)0, coords.y); 

			Coords coords2(4, 3);
			ptr_moves->fwd(&coords2, Table);
			Assert::AreEqual((uint8_t)4, coords2.x);// no movement
			Assert::AreEqual((uint8_t)3, coords2.y);
		}
		TEST_METHOD(ExtractOrientation_WEST)
		{
			Movement test;
			auto ptr_moves = test.ExtractOrientation("WEST");
			Assert::AreEqual(std::string("WEST"), ptr_moves->faced);

			auto ptr_ccw = ptr_moves->ccw;
			Assert::AreEqual(std::string("SOUTH"), ptr_ccw->faced);

			auto ptr_cw = ptr_moves->cw;
			Assert::AreEqual(std::string("NORTH"), ptr_cw->faced);

			Coords coords(0, 0);
			ptr_moves->fwd(&coords, Table);
			Assert::AreEqual((uint8_t)0, coords.x);// no movement
			Assert::AreEqual((uint8_t)0, coords.y);

			Coords coords2(4, 3);
			ptr_moves->fwd(&coords2, Table);
			Assert::AreEqual((uint8_t)3, coords2.x);
			Assert::AreEqual((uint8_t)3, coords2.y);
		}
	};
}
