#include "functions.h"
#include <set>
#include <string>
#include <vector>
#include <algorithm> // ��� reverse

std::set<int> Generate_level_tree_from_previous(int Number_pairs) 
{
    //������� ��� ����� ��� ������ ���-��
    std::set<int> result;

    if (Number_pairs < 1) return result;

    //������� ������ ������� (������� = 1)
    std::vector<int> previous_level = {1};

    for (int level = 1; level < Number_pairs; ++level) 
    {
        std::vector<int> current_level;

        //��� ������� �������� ����������� ������
        for (int mask : previous_level) 
        {
            // ��������� ������� ����� ��������� � ������ (N)
            std::string s = std::to_string(mask);
            int ones = std::count(s.begin(), s.end(), '1');
            int zeros = std::count(s.begin(), s.end(), '0');
            int N = ones - zeros;

            //��������� K ����� � ���� ������� (K �� 0 �� N)
            for (int K = 0; K <= N; ++K) 
            {
                //�������� �����, � ������� ����� ����� ���������
                int new_mask = Add_zeros_and_unit(mask, K);

                //������� ����� ��������� � ����� ������ �������
                current_level.push_back(new_mask);
            }
        }
        //���������� ������� ������ ����� ��������
        previous_level = current_level;
    }

    // 3. ���������� ��� �������� ���������� ������ � set
    result.insert(previous_level.begin(), previous_level.end());

    return result;
}


std::string Decode(int bit_mask, char open_symbol, char close_symbol) 
{
    std::string bracket_sequence = "";
    int balance = 0; // ������� �������� ������

    // ������������ ������ ����� ����� (0 ��� 1)
    while (bit_mask != 0) 
    {
        int last_digit = bit_mask % 10; // �������� ��������� �����
        bit_mask /= 10; // ������� ��������� ����� �� �����

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

    // �������������, ��� ��� ����� �������������� ������ ������
    std::reverse(bracket_sequence.begin(), bracket_sequence.end());

    // ��������� ����������� ����������� ������
    while (balance > 0) 
    {
        bracket_sequence += close_symbol;
        balance--;
    }

    return bracket_sequence;
    }



int Add_zeros_and_unit(int bit_mask, int N) 
{
    //����������� int � string
    std::string stringMask = std::to_string(bit_mask);

    //��������� N ����� � ������
    for (int i = 0; i < N; i++)
    {
        stringMask += '0';
    }
   
    //��������� ���� �������
    stringMask += '1';

    //����������� string � int
    bit_mask = std::stoi(stringMask);

    return bit_mask;
}
