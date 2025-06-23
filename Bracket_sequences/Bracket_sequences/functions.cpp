#include "functions.h"
#include <set>
#include <string>
#include <vector>
#include <algorithm> // для reverse

std::set<int> Generate_level_tree_from_previous(int Number_pairs) 
{
    //Создает сет интов для запипи рез-та
    std::set<int> result;

    if (Number_pairs < 1) return result;

    //Создаем первый уровень (элемент = 1)
    std::vector<int> previous_level = {1};

    for (int level = 1; level < Number_pairs; ++level) 
    {
        std::vector<int> current_level;

        //Для каждого элемента предыдущего уровня
        for (int mask : previous_level) 
        {
            // Вычисляем разницу между единицами и нулями (N)
            std::string s = std::to_string(mask);
            int ones = std::count(s.begin(), s.end(), '1');
            int zeros = std::count(s.begin(), s.end(), '0');
            int N = ones - zeros;

            //Добавляем K нулей и одну единицу (K от 0 до N)
            for (int K = 0; K <= N; ++K) 
            {
                //Создадим маску, в которой будет новая генерация
                int new_mask = Add_zeros_and_unit(mask, K);

                //Добавим новую генерацию в конец нашего вектора
                current_level.push_back(new_mask);
            }
        }
        //Предыдущий уровень теперь равен текущему
        previous_level = current_level;
    }

    // 3. Записываем все элементы последнего уровня в set
    result.insert(previous_level.begin(), previous_level.end());

    return result;
}


std::string Decode(int bit_mask, char open_symbol, char close_symbol) 
{
    std::string bracket_sequence = "";
    int balance = 0; // Счётчик открытых скобок

    // Обрабатываем каждую цифру числа (0 или 1)
    while (bit_mask != 0) 
    {
        int last_digit = bit_mask % 10; // Получаем последнюю цифру
        bit_mask /= 10; // Убираем последнюю цифру из числа

        if (last_digit == 1) 
        {
            bracket_sequence += open_symbol;
            balance++;
        }
        else if (last_digit == 0) 
        {
            bracket_sequence += close_symbol;
            balance--;
        }
    }

    // Разворачиваем, так как цифры обрабатывались справа налево
    std::reverse(bracket_sequence.begin(), bracket_sequence.end());

    // Добавляем недостающие закрывающие скобки
    while (balance > 0) 
    {
        bracket_sequence += close_symbol;
        balance--;
    }

    return bracket_sequence;
    }



int Add_zeros_and_unit(int bit_mask, int N) 
{
    //Преобразуем int в string
    std::string stringMask = std::to_string(bit_mask);

    //Добавляем N нулей к строке
    for (int i = 0; i < N; i++)
    {
        stringMask += '0';
    }
   
    //Добавляем одну единицу
    stringMask += '1';

    //Преобразуем string в int
    bit_mask = std::stoi(stringMask);

    return bit_mask;
}
