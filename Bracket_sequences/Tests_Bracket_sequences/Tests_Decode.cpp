#include "pch.h"
#include "CppUnitTest.h"
#include "../Bracket_sequences/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsBracketsequences
{
	TEST_CLASS(Tests_Decode)
	{
	public:

		TEST_METHOD(SimpleTest)
		{
			std::string Work = Decode(1, '(', ')');
			std::string Correct = "()";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(DefaultTest)
		{
			std::string Work = Decode(1101, '(', ')');
			std::string Correct = "(()())";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(NeedOnlyCloseSymbol)
		{
			std::string Work = Decode(11, '(', ')');
			std::string Correct = "((()))";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(LongSequence)
		{
			std::string Work = Decode(110011101101, '(', ')');
			std::string Correct = "(())((()(()())))";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(QueueOnesAndZeros)
		{
			std::string Work = Decode(10101, '(', ')');
			std::string Correct = "(()())()";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(RandomTest)
		{
			std::string Work = Decode(1101001, '(', ')');
			std::string Correct = "(()())()";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(SmallSequence)
		{
			std::string Work = Decode(101, '(', ')');
			std::string Correct = "()()";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(SquareBrackets)
		{
			std::string Work = Decode(10111, '(', ')');
			std::string Correct = "[][[[]]]";
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(RoundBrackets)
		{
			std::string Work = Decode(1110101, '(', ')');
			std::string Correct = "{{{}{}{}}}";
			Assert::AreEqual(Work, Correct);
		}
	};
}