#include "functions.h"
#include <set>
#include <string>
std::set<int> Generate_level_tree_from_previous(int Number_pairs)
{
	std::set<int> d = { 111, 110101, 11001, 1011, 10101 };
	return d;
}


std::string Decode(int bit_mask, char open_symbol, char close_symbol) 
{
	std::string x = "()";
	return x;
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
