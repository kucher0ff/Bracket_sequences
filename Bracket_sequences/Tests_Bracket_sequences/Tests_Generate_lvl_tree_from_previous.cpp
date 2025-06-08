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
			std::set<int> Correct = { 111, 110101, 11001, 1011, 10101 };
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(SmallPairsNumber)
		{
			std::set<int> Work = Generate_level_tree_from_previous(2);
			std::set<int> Correct = { 11, 101 };
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(OnePairBrackets)
		{
			std::set<int> Work = Generate_level_tree_from_previous(1);
			std::set<int> Correct = { 1 };
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(BigPairsNumber)
		{
			std::set<int> Work = Generate_level_tree_from_previous(4);
			std::set<int> Correct = { 1111, 11101, 111001, 1110001, 11011, 110101, 1101001, 110011,100101, 10111, 101101, 1011001, 101011, 10101 };
			Assert::AreEqual(Work, Correct);
		}
	};
}