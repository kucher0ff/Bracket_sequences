#include "functions.h"
#include <iostream>
#include <set>
#include <string>


//Функция для вывода последовательностей
void PrintSequences(const std::set<std::string>& sequences) 
{
    
    std::cout << "\nCorrect bracket sequences:\n";

    //Используем итератор для прохода по set'у
    for (std::set<std::string>::const_iterator it = sequences.begin();
        it != sequences.end(); ++it) 
    {
        std::cout << *it << '\n';
    }
    std::cout << "Count of sequences: " << sequences.size() << '\n';
}

//Функция для проверки корректности открывающего и закрывающего символов
bool IsValidBracket(char bracket, bool is_open) {
    if (is_open) {
        return bracket == '(' || bracket == '{' || bracket == '[';
    }
    else {
        return bracket == ')' || bracket == '}' || bracket == ']';
    }
}

int main() 
{
    int Number_pairs;
    char open_symbol, close_symbol;

    // Ввод и проверка количества пар скобок
    while (true) 
    {
        std::cout << "Enter the number of pairs of brackets (a positive number): ";
        if (!(std::cin >> Number_pairs) || Number_pairs <= 0) 
        {
            std::cout << "Error! Enter a non-negative integer.\n";
        }
        else 
        {
            break;
        }
    }

    // Ввод открывающих и закрывающих символов
    //Открывающие символы
    while (true) 
    {
        std::cout << "Enter the opening bracket symbol ((, {, [): ";
        std::cin >> open_symbol;

        if (!IsValidBracket(open_symbol, true)) 
        {
            std::cout << "Error! Only '(', '{' or '[' are allowed.\n";
        }
        else 
        {
            break;
        }
    }

    //Закрывающие символы
    while (true) {
        std::cout << "Enter the closing bracket symbol (), }, ]): ";
        std::cin >> close_symbol;

        if (!IsValidBracket(close_symbol, false)) 
        {    
            std::cout << "Error! Only ')', '}' or ']' are allowed.\n";
        }
        else 
        {
            break;
        }
    }

    // Дополнительная проверка на соответствие скобок
    if ((open_symbol == '(' && close_symbol != ')') ||
        (open_symbol == '{' && close_symbol != '}') ||
        (open_symbol == '[' && close_symbol != ']')) 
    {
        std::cout << "Warning: Mismatched bracket types. This may produce unexpected results.\n";
    }

    // Генерация последовательностей
    std::set<std::string> sequences = Generate_correct_bracket_sequences(Number_pairs, open_symbol, close_symbol);

    // Вывод результатов
    PrintSequences(sequences);

    return 0;
}