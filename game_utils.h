#ifndef game_utils_H_INCLUDED
#define game_utils_H_INCLUDED
#include <string>
/**
* @brief Rolls the dice with random numbers from 1 to 6.
* @param dice Contains the value of each die per index.
*/
void roll_dice(int dice[]);
/**
* @brief Lets the user choose which value each die will have. Debug is used for testing purposes.
* @param dice Contains the value of each die per index.
*/
void roll_dice_debug(int dice[]);
/**
* @brief Shows the user with highest score.
* @param highest_score Has highest recorded score between all players.
* @param highest_score_player Has the name of the highest score player.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void ranking(int highest_score, const std::string &highest_score_player, bool is_spanish);
/**
* @brief Updates the ranking information.
* @param player_score Is an array that has both player 1 and 2 scores. Index 0 for player 1, index 1 for player 2.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param highest_score Reference to the highest recorded score between all players.
* @param highest_score_player Reference to the name of the player that holds the highest score.
* @param is_two_players Checks if the game is running in two player mode.
*/
void update_ranking(const int player_score[], const std::string player_name[], int &highest_score, std::string &highest_score_player, bool is_two_players);
/**
* @brief Enables debug mode which lets you choose each die value each roll.
* @param is_debug Reference controls if the game runs in debug mode (manual dice selection).
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void debug_mode(bool &is_debug, bool is_spanish);
/**
* @brief Copies an array value to other array.
* @param source Source array.
* @param destination Destination array.
*/
void copy_array(const int source[], int destination[]);
/**
* @brief Sorts the dice to reduce combination logic check complexity.
* @param dice Contains each die value per index.
*/
void sort_dice(int dice[]);
/**
* @brief Converts the combination index into a readable string.
* @param combination_index The ID of the combination (0-9).
* @param is_spanish Checks if the user interface language is set to Spanish.
* @return std::string The name of the combination (e.g., "Full" or "Generala")
*/
std::string get_combination_name(int combination_index, bool is_spanish);
#endif // game_utils_H_INCLUDED

