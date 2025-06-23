#pragma once
#include <set>
#include <string>
std::set<int> Generate_level_tree_from_previous(int Number_pairs);
std::string Decode(int bit_mask, char open_symbol, char close_symbol);
int Add_zeros_and_unit(int bit_mask, int N);
std::set<std::string> Generate_correct_bracket_sequences(int Number_pairs, char open_symbol, char close_symbol);