/**
 * @file functions.h
 * @brief Header file for generating bracket sequences
 * @author kucheroff
 */

#pragma once
#include <set>
#include <string>

 /**
  * @brief Generates a mask tree for bracket sequences
  * @param[in] Number_pairs Number of bracket pairs needed
  * @return Set of integer masks representing sequences
  * @note Each mask encodes a sequence in binary form (1 - opening symbol, 0 - closing symbol)
  */
std::set<int> Generate_level_tree_from_previous(int Number_pairs);

/**
 * @brief Decodes a bit mask into a bracket string
 * @param[in] bit_mask Numeric sequence mask
 * @param[in] open_symbol Opening bracket character
 * @param[in] close_symbol Closing bracket character
 * @return String with decoded bracket sequence
 * @warning The mask must be generated by Generate_level_tree_from_previous function
 */
std::string Decode(int bit_mask, char open_symbol, char close_symbol);

/**
 * @brief Adds the required number of zeros and ones to generate the next level of the tree
 * @param[in] bit_mask Source bit mask
 * @param[in] N Difference between number of zeros and ones
 * @return New bit mask for the next level
 * @details Helper function for mask tree generation
 */
int Add_zeros_and_unit(int bit_mask, int N);

/**
 * @brief Generates all valid bracket sequences
 * @param[in] Number_pairs Number of bracket pairs needed
 * @param[in] open_symbol Opening bracket character (must be one of: '(', '{', '[')
 * @param[in] close_symbol Closing bracket character (must be one of: ')', '}', ']')
 * @return Set of valid bracket sequences
 * @see Generate_level_tree_from_previous()
 * @see Decode()
 */
std::set<std::string> Generate_correct_bracket_sequences(int Number_pairs, char open_symbol, char close_symbol);