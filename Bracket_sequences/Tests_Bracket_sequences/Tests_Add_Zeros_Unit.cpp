#include "pch.h"
#include "CppUnitTest.h"
#include "../Bracket_sequences/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestsBracketsequences
{
	TEST_CLASS(Tests_Add_Zeros_Units)
	{
	public:
		//Функция принимает int N - разницу единиц и нулей в маске
		//Тесты разбиты на блоки, т.к int N изменяется в ходе работы функции

		//Базовый тест (N = 0, 1, 2)
		TEST_METHOD(BaseTest1)
		{
			int Work = Add_zeros_and_unit(11, 0);
			int Correct = 111;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(BaseTest2)
		{
			int Work = Add_zeros_and_unit(11, 1);
			int Correct = 1101;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(BaseTest3)
		{
			int Work = Add_zeros_and_unit(11, 2);
			int Correct = 11001;
			Assert::AreEqual(Work, Correct);
		}

		//Начальный уровень равен единице (N = 0, 1)
		TEST_METHOD(FirstLvlEqualsOne1)
		{
			int Work = Add_zeros_and_unit(1,0);
			int Correct = 11;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(FirstLvlEqualsOne2)
		{
			int Work = Add_zeros_and_unit(1, 1);
			int Correct = 101;
			Assert::AreEqual(Work, Correct);
		}

		//Много вариантов (N = 0, 1, 2, 3)
		TEST_METHOD(ManyVariants1)
		{
			int Work = Add_zeros_and_unit(111, 0);
			int Correct = 1111;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(ManyVariants2)
		{
			int Work = Add_zeros_and_unit(111, 1);
			int Correct = 11101;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(ManyVariants3)
		{
			int Work = Add_zeros_and_unit(111, 2);
			int Correct = 111001;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(ManyVariants4)
		{
			int Work = Add_zeros_and_unit(111, 3);
			int Correct = 1110001;
			Assert::AreEqual(Work, Correct);
		}

		//В маске есть нули (N = 0, 1)
		TEST_METHOD(MaskAlreadyHasZeros1)
		{
			int Work = Add_zeros_and_unit(11001, 0);
			int Correct = 110011;
			Assert::AreEqual(Work, Correct);
		}

		TEST_METHOD(MaskAlreadyHasZeros2)
		{
			int Work = Add_zeros_and_unit(11001, 1);
			int Correct = 1100101;
			Assert::AreEqual(Work, Correct);
		}

		//Нельзя добавить нули (N = 0)
		TEST_METHOD(NoMoreZeros)
		{
			int Work = Add_zeros_and_unit(1100101, 0);
			int Correct = 11001011;
			Assert::AreEqual(Work, Correct);
		}
	};
}