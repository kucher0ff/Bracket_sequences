#pragma once
#include <set>
#include <string>
std::set<int> Generate_level_tree_from_previous(int Number_pairs);
std::string Decode(int bit_mask, char open_symbol, char close_symbol);
int Add_zeros_and_unit(int bit_mask, int N);