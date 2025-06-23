#include "pch.h"
#include "CppUnitTest.h"
#include "../Bracket_sequences/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsBracketsequences
{
	TEST_CLASS(Tests_Generate_Correct_Bracket_Sequences)
	{
	public:

		TEST_METHOD(OnePair)
		{
			std::set<std::string> Work = Generate_correct_bracket_sequences(1, '(', ')');
			std::set<std::string> Correct = { "()" };
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(TwoPairs)
		{
			std::set<std::string> Work = Generate_correct_bracket_sequences(2, '(', ')');
			std::set<std::string> Correct = { "(())", "()()"};
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(ThreePairs)
		{
			std::set<std::string> Work = Generate_correct_bracket_sequences(3, '(', ')');
			std::set<std::string> Correct = { "((()))", "()(())", "(()())", "()()()", "(())()"};
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(FourPairs)
		{
			std::set<std::string> Work = Generate_correct_bracket_sequences(4, '(', ')');
			std::set<std::string> Correct = {"(((())))", "((()()))", "((())())", "((()))()","(()(()))", "(()()())", "(()())()", "(())(())","(())()()", "()((()))", "()(()())", "()(())()","()()(())", "()()()()"
			};
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(ThreePairsAndSquareBrackets)
		{
			std::set<std::string> Work = Generate_correct_bracket_sequences(3, '[', ']');
			std::set<std::string> Correct = { "[[[]]]", "[][[]]", "[[][]]", "[][][]", "[[]][]" };
			Assert::IsTrue(Work == Correct);
		}

		TEST_METHOD(ThreePairsAndRoundBrackets)
		{
			std::set<std::string> Work = Generate_correct_bracket_sequences(3, '{', '}');
			std::set<std::string> Correct = { "{{{}}}", "{}{{}}", "{{}{}}", "{}{}{}", "{{}}{}" };
			Assert::IsTrue(Work == Correct);
		}
	};
}