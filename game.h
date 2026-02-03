#ifndef game_H_INCLUDED
#define game_H_INCLUDED
#include <string>
/**
* @brief Controls the main game flow.
* *This function handles the full game loop and calls other core functions like 'match', 'turn', etc. to run the game logic.
* @param highest_score reference to the highest recorded score between all players.
* @param highest_score_player reference to the name of the player that holds the highest score.
* @param is_debug controls if the game runs in debug mode (manual dice selection).
* @param is_two_players Checks if the game is running in two player mode.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void game(int &highest_score, std::string &highest_score_player, bool is_debug, bool is_two_players, bool is_spanish);
/**
* @brief Controls overall game match logic.
* * This function handles how the game match evolves over time in both single and two players mode.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param player_score Is an array that has both player 1 and 2 scores. Index 0 for player 1, index 1 for player 2.
* @param dice Is an array that has the dice value, each index from 0 to 4 is for each die counting from 1 (being 0 die 1, and 4 die 5).
* @param highest_score Reference to the highest recorded score between all players.
* @param highest_score_player Reference to the name of the player that holds the highest score.
* @param served_generala Is an array that stores if the player (1 or 2) has scored a served generala.
* @param is_debug Controls if the game runs in debug mode (manual dice selection).
* @param scratched_combination 2D Array tracking which categories have been used by each player. First dimension is for each player (0 or 1), next dimension for each different combination.
* @param is_two_players Checks if the game is running in two player mode.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void match(const std::string player_name[], int player_score[], int dice[], int &highest_score, std::string &highest_score_player, bool served_generala[], bool is_debug,bool scratched_combination[][10], bool is_two_players, bool is_spanish);
/**
* @brief Controls turn logic.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param player_score Is an array that has both player 1 and 2 scores. Index 0 for player 1, index 1 for player 2.
* @param dice Is an array that has the dice value, each index from 0 to 4 is for each die counting from 1 (being 0 die 1, and 4 die 5).
* @param served_generala Is an array that stores if the player (1 or 2) has scored a served generala.
* @param is_debug Controls if the game runs in debug mode (manual dice selection).
* @param scratched_combination 2D Array tracking which categories have been used by each player. First dimension is for each player (0 or 1), next dimension for each different combination.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void turn(const std::string &player_name, int &player_score, int dice[], bool &served_generala, int &round, bool is_debug, bool scratched_combination[], bool is_spanish);
/**
* @brief Manages the dice re-rolling process, including user prompts and selection logic.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param player_score Is an array that has both player 1 and 2 scores. Index 0 for player 1, index 1 for player 2.
* @param dice Is an array that has the dice value, each index from 0 to 4 is for each die counting from 1 (being 0 die 1, and 4 die 5).
* @param served_generala Is an array that stores if the player (1 or 2) has scored a served generala.
* @param round Reference to current round that is being played.
* @param roll_count Reference to the number of rolls the user has done.
* @param round_score Reference to the current round score.
* @param is_debug Controls if the game runs in debug mode (manual dice selection).
* @param selected_combination Stores the name of the combination to scratch.
* @param scratched_combination 2D Array tracking which categories have been used by each player. The implementation here just interacts with the second dimension of the array.
* @param dice_rolling_animation Controls which die should be animated.
* @param is_reroll Checks if the user is rerolling.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void roll_again(const std::string &player_name, int &player_score,int dice[5], bool &served_generala, int &round, int &roll_count, int &round_score, bool is_debug, std::string &selected_combination, bool scratched_combination[],bool dice_rolling_animation[],bool is_reroll, bool is_spanish);
/**
* @brief Checks the roll results.
* @param dice Is an array that has the dice value, each index from 0 to 4 is for each die counting from 1 (being 0 die 1, and 4 die 5).
* @param score References the player score.
* @param served_generala References if the player has a served generala.
* @param roll_count Reference to the number of rolls the user has done.
* @param round_score Reference to the current round score.
* @param round Reference to current round that is being played.
* @param selected_combination Stores the name of the combination to scratch.
* @param scratched_combination 2D Array tracking which categories have been used by each player. The implementation here just interacts with the second dimension of the array.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void evaluate_roll(const int dice[5], int &score, bool &served_generala,int roll_count, int &round_score, int &round, std::string &selected_combination, bool scratched_combination[], bool is_spanish);
/**
* @brief Checks if the user is selecting the same die twice when rerolling.
* @param dice_to_reroll Store the dice values, each die value in the assigned index minus 1 (example, die 5 is index 4).
* @param i Is the index number of the die.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void check_duplicate_reroll(int dice_to_reroll[], int i, bool is_spanish, bool is_debug);
/**
* @brief Checks if the player is scratching a valid combination.
* @param combination_to_scratch References to the player's chosen combination to scratch.
* @param scratched_combination Stores if a combination has already been scratched.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void check_valid_scratch(int &combination_to_scratch,bool scratched_combination[], bool is_spanish);
/**
* @brief Updates player's game data after finishing the turn.
* @param player_score Reference current player score.
* @param dice Is an array that has the dice value, each index from 0 to 4 is for each die counting from 1 (being 0 die 1, and 4 die 5).
* @param served_generala References if the player has scored a served generala.
* @param round Reference to current round that is being played.
* @param roll_count Reference to the number of rolls the user has done.
* @param round_score Reference to the current round score.
* @param selected_combination Stores the name of the combination to scratch.
* @param scratched_combination Stores if a combination has already been scratched.
* @param is_turn_finished Stores state of the current turn.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void end_turn(int &player_score, const int dice[5], bool &served_generala, int &round, int &roll_count, int &round_score, std::string &selected_combination, bool scratched_combination[], bool &is_turn_finished, bool is_spanish);
#endif // game_H_INCLUDED
