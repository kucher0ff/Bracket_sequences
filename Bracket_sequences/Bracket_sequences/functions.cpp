#include "functions.h"
#include <set>
#include <string>
#include <algorithm> // для reverse
std::set<int> Generate_level_tree_from_previous(int Number_pairs)
{
	std::set<int> d = { 111, 110101, 11001, 1011, 10101 };
	return d;
}


std::string Decode(int bit_mask, char open_symbol, char close_symbol) 
{
    std::string bracket_sequence = "";
    int balance = 0; // Счётчик открытых скобок

    // Обрабатываем каждую цифру числа (0 или 1)
    while (bit_mask != 0) {
        int last_digit = bit_mask % 10; // Получаем последнюю цифру
        bit_mask /= 10; // Убираем последнюю цифру из числа

        if (last_digit == 1) {
            bracket_sequence += open_symbol;
            balance++;
        }
        else if (last_digit == 0) {
            bracket_sequence += close_symbol;
            balance--;
        }
    }

    // Разворачиваем, так как цифры обрабатывались справа налево
    std::reverse(bracket_sequence.begin(), bracket_sequence.end());

    // Добавляем недостающие закрывающие скобки
    while (balance > 0) {
        bracket_sequence += close_symbol;
        balance--;
    }

    

    return bracket_sequence;
    }



int Add_zeros_and_unit(int bit_mask, int N) 
{

    // 11001
    //Сдвинуть биты на N+1 элементов влево

    std::string stringMask = std::to_string(bit_mask);
    for (int i = 0; i < N; i++)
    {
        stringMask += '0';
    }
   
    stringMask += '1';
    bit_mask = std::stoi(stringMask);


    //Заменить крайний ноль на единицу через побитовое ИЛИ
    //bit_mask = bit_mask | 1;

    return bit_mask;
}
