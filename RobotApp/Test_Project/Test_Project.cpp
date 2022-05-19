#include "pch.h"
#include <string>
#include "CppUnitTest.h"
#include "../RobotApp/Robot.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(ROBOT)
	{
	public:
		#pragma region STATUS
		TEST_METHOD(GetOrientation)
		{
			Robot robot(0, 1, FacingOrientation::NORTH);
			Assert::AreEqual(int(FacingOrientation::NORTH), int(robot.GetOrientation()));
		}

		TEST_METHOD(GetPosX)
		{
			Robot robot(2, 1, FacingOrientation::EAST);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
		}

		TEST_METHOD(GetPosY)
		{
			Robot robot(0, 3, FacingOrientation::WEST);
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}
		#pragma endregion


		#pragma region ROTATE
		TEST_METHOD(RotateRight)
		{
			Robot robot(0, 1, FacingOrientation::NORTH);
			Assert::AreEqual(int(FacingOrientation::EAST), int(robot.RotateRight()));
		}

		TEST_METHOD(RotateLeft)
		{
			Robot robot(2, 1, FacingOrientation::EAST);
			Assert::AreEqual(int(FacingOrientation::NORTH), int(robot.RotateLeft()));
		}
		#pragma endregion


		#pragma region MOVE
		TEST_METHOD(MoveX_FWD)
		{
			Robot robot(0, 3, FacingOrientation::WEST);
			robot.MoveX();
			Assert::AreEqual(unsigned char(1), robot.GetPosX());
			robot.MoveX();
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
		}

		TEST_METHOD(MoveX_BWD)
		{
			Robot robot(3, 3, FacingOrientation::WEST);
			robot.MoveX(false);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			robot.MoveX(false);
			Assert::AreEqual(unsigned char(1), robot.GetPosX());
		}

		TEST_METHOD(MoveX_FWD_BWD)
		{
			Robot robot(3, 3, FacingOrientation::WEST);
			robot.MoveX();
			Assert::AreEqual(unsigned char(4), robot.GetPosX());
			robot.MoveX(false);
			Assert::AreEqual(unsigned char(3), robot.GetPosX());
			robot.MoveX(false);
			Assert::AreEqual(unsigned char(2), robot.GetPosX());
			robot.MoveX();
			Assert::AreEqual(unsigned char(3), robot.GetPosX());
		}

		TEST_METHOD(MoveX_Limit_Max)
		{
			Robot robot(0xff, 3, FacingOrientation::WEST);
			robot.MoveX();
			Assert::AreEqual(unsigned char(0), robot.GetPosX());
		}

		TEST_METHOD(MoveX_Limit_Min)
		{
			Robot robot(0, 3, FacingOrientation::WEST);
			robot.MoveX(false);
			Assert::AreEqual(unsigned char(0xff), robot.GetPosX());
		}

		TEST_METHOD(MoveY_FWD)
		{
			Robot robot(0, 3, FacingOrientation::WEST);
			robot.MoveY();
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			robot.MoveY();
			Assert::AreEqual(unsigned char(5), robot.GetPosY());
		}

		TEST_METHOD(MoveY_BWD)
		{
			Robot robot(3, 3, FacingOrientation::WEST);
			robot.MoveY(false);
			Assert::AreEqual(unsigned char(2), robot.GetPosY());
			robot.MoveY(false);
			Assert::AreEqual(unsigned char(1), robot.GetPosY());
		}

		TEST_METHOD(MoveY_FWD_BWD)
		{
			Robot robot(3, 3, FacingOrientation::WEST);
			robot.MoveY();
			Assert::AreEqual(unsigned char(4), robot.GetPosY());
			robot.MoveY(false);
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
			robot.MoveY(false);
			Assert::AreEqual(unsigned char(2), robot.GetPosY());
			robot.MoveY();
			Assert::AreEqual(unsigned char(3), robot.GetPosY());
		}

		TEST_METHOD(MoveY_Limit_Max)
		{
			Robot robot(0xff, 0xff, FacingOrientation::WEST);
			robot.MoveY();
			Assert::AreEqual(unsigned char(0), robot.GetPosY());
		}

		TEST_METHOD(MoveY_Limit_Min)
		{
			Robot robot(0, 0, FacingOrientation::WEST);
			robot.MoveY(false);
			Assert::AreEqual(unsigned char(0xff), robot.GetPosY());
		}
		#pragma endregion

	};
}
