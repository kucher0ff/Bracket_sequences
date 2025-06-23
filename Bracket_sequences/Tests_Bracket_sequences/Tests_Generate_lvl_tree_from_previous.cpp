#include "pch.h"
#include "CppUnitTest.h"
#include "../Bracket_sequences/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsBracketsequences
{
	TEST_CLASS(Tests_Generate_level_tree_from_previous)
	{
	public:
		TEST_METHOD(BaseTest)
		{
			std::set<int> Work = Generate_level_tree_from_previous(3);
			std::set<int> Correct = { 111, 1011, 1101, 10101, 11001 };
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(SmallPairsNumber)
		{
			std::set<int> Work = Generate_level_tree_from_previous(2);
			std::set<int> Correct = { 11, 101 };
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(OnePairBrackets)
		{
			std::set<int> Work = Generate_level_tree_from_previous(1);
			std::set<int> Correct = { 1 };
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(BigPairsNumber)
		{
			std::set<int> Work = Generate_level_tree_from_previous(4);
			std::set<int> Correct = { 1111, 10111, 11011, 11101, 101011, 101101, 110011, 110101, 111001, 1010101, 1011001, 1100101, 1101001, 1110001 };
			Assert::IsTrue(Work == Correct);
		}
	};
}