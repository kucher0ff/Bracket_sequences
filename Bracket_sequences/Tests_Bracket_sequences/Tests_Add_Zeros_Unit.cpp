#include "pch.h"
#include "CppUnitTest.h"
#include "../Bracket_sequences/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsBracketsequences
{
	TEST_CLASS(Tests_Add_Zeros_Units)
	{
	public:

		TEST_METHOD(SimpleTest)
		{
			std::string x = Decode(1, '(', ')');
			std::string f = "23";
			Assert::AreEqual(x, f);
		}

		TEST_METHOD(SimpleTest2)
		{
			std::string x = Decode(1, '(', ')');
			std::string f = "";
			Assert::AreEqual(x, f);
		}
	};
}