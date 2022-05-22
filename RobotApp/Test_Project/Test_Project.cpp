#include "pch.h"
#include <string>
#include "CppUnitTest.h"
#include "../RobotApp/Entity.cpp"
#include "../RobotApp/Platform.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(ENTITY)
	{
	public:
		#pragma region STATUS
		TEST_METHOD(GetOrientation)
		{
			Entity robot(0, 1, FacingOrientation::NORTH);
			Assert::AreEqual(int(FacingOrientation::NORTH), int(robot.GetOrientation()));
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
			Assert::AreEqual(int(FacingOrientation::EAST), int(robot.RotateRight()));
		}

		TEST_METHOD(RotateLeft)
		{
			Entity robot(2, 1, FacingOrientation::EAST);
			Assert::AreEqual(int(FacingOrientation::NORTH), int(robot.RotateLeft()));
		}
		#pragma endregion


		#pragma region MOVE
		TEST_METHOD(Move_X_FWD)
		{
			Entity robot(0, 3, FacingOrientation::EAST);
			robot.Move();
			Assert::AreEqual(unsigned char(1), robot.GetPosX());
			robot.Move();
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}

		TEST_METHOD(Move_X_BWD)
		{
			Entity robot(3, 3, FacingOrientation::WEST);
			robot.Move();
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			robot.Move();
			Assert::AreEqual(unsigned char(1), robot.GetPosX());
		}

		TEST_METHOD(Move_X_FWD_BWD)
		{
			Entity robot(3, 3, FacingOrientation::EAST);
			robot.Move();
			Assert::AreEqual(unsigned char(4), robot.GetPosX());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move();
			Assert::AreEqual(unsigned char(3), robot.GetPosX());
			robot.Move();
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move();
			Assert::AreEqual(unsigned char(3), robot.GetPosX());
		}

		TEST_METHOD(Move_X_Limit_Max)
		{
			Entity robot(0xff, 3, FacingOrientation::EAST);
			robot.Move();
			Assert::AreEqual(unsigned char(0), robot.GetPosX());
		}

		TEST_METHOD(Move_X_Limit_Min)
		{
			Entity robot(0, 3, FacingOrientation::WEST);
			robot.Move();
			Assert::AreEqual(unsigned char(0xff), robot.GetPosX());
		}

		TEST_METHOD(Move_Y_FWD)
		{
			Entity robot(0, 3, FacingOrientation::NORTH);
			robot.Move();
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			robot.Move();
			Assert::AreEqual(unsigned char(5), robot.GetPosY());
			Assert::AreEqual(unsigned char(0), robot.GetPosX());
		}

		TEST_METHOD(Move_Y_BWD)
		{
			Entity robot(3, 3, FacingOrientation::SOUTH);
			robot.Move();
			Assert::AreEqual(unsigned char(2), robot.GetPosY());
			robot.Move();
			Assert::AreEqual(unsigned char(1), robot.GetPosY());
		}

		TEST_METHOD(Move_Y_FWD_BWD)
		{
			Entity robot(3, 3, FacingOrientation::NORTH);
			robot.Move();
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move();
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
			robot.Move();
			Assert::AreEqual(unsigned char(2), robot.GetPosY());
			robot.RotateLeft();
			robot.RotateLeft();
			robot.Move();
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}

		TEST_METHOD(Move_Y_Limit_Max)
		{
			Entity robot(0xff, 0xff, FacingOrientation::NORTH);
			robot.Move();
			Assert::AreEqual(unsigned char(0), robot.GetPosY());
		}

		TEST_METHOD(Move_Y_Limit_Min)
		{
			Entity robot(0, 0, FacingOrientation::SOUTH);
			robot.Move();
			Assert::AreEqual(unsigned char(0xff), robot.GetPosY());
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
}
