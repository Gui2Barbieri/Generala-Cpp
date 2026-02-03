#ifndef ui_utils_H_INCLUDED
#define ui_utils_H_INCLUDED

#include <string>
/**
* @brief Pauses the console.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void pause(bool is_spanish);
/**
* @brief Clears the console.
*/
void clear_console();
/**
* @brief Draws an upper line using Unicode characters.
* @param length Used to store the length.
*/
void draw_upper_line(int length);
/**
* @brief Draws a lower line using Unicode characters.
* @param length Used to store the length.
*/
void draw_lower_line(int length);
/**
* @brief Draws the main title.
*/
void title();
/**
* @brief Shows the rules.
*/
void rules(bool is_spanish);
/**
* @brief Makes an input text to blink.
* @param text_to_print Text input.
* @param x Horizontal position.
* @param y Vertical position.
* @param original_color Gets background color to reset it at the end.
*/
void blinking_text(const std::string &text_to_print, int x, int y, int original_color);
/**
* @brief Draws a line.
* @param length Used to store the length.
*/
void draw_line(int length);
/**
* @brief Shows the credits.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void credits(bool is_spanish);
/**
* @brief Draws die square form.
* @param x Horizontal position.
* @param y Vertical position.
*/
void draw_square(int x, int y);
/**
* @brief Draws die face value.
* @param value Contains the value to draw.
* @param x Horizontal position.
* @param y Vertical position.
*/
void draw_die(int value, int x, int y);
/**
* @brief Shows die.
* @param dice Is an array that has the dice value, each index from 0 to 4 is for each die counting from 1 (being 0 die 1, and 4 die 5).
* @param dice_rolling_animation Is an array that has values in each index linked to each die, determines if the die has to be animated or not.
* @param is_reroll Checks if the user is rerolling.
*/
void display_dice(const int dice[], const bool dice_rolling_animation[], bool is_reroll);
/**
* @brief Shows the UI while playing a match.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param player_score Is an array that has both player 1 and 2 scores. Index 0 for player 1, index 1 for player 2.
* @param round Stores current round that is being played.
* @param roll_count Reference to the number of rolls the user has done.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void player_turn_ui(const std::string &player_name, int player_score, int round, int roll_count, bool is_spanish);
/**
* @brief Displays victory message or tie between players (or solo).
* @param served_generala Is an array that stores if the player (1 or 2) has scored a served generala.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param round Stores current round that is being played.
* @param is_debug Controls if the game runs in debug mode (manual dice selection).
* @param player_score Is an array that has both player 1 and 2 scores. Index 0 for player 1, index 1 for player 2.
* @param is_two_players Checks if the game is running in two player mode.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void display_victory_message(bool served_generala[], const std::string player_name[], int round, bool is_debug, const int player_score[], bool is_two_players, bool is_spanish);
/**
* @brief Gives random animation to a die.
* @param x Horizontal position.
* @param y Vertical position.
*/
void random_die_animation(int x, int y);
/**
* @brief Shows stats when player's turn ends.
* @param player_name Is an array that has both player 1 and 2 names. Index 0 for player 1, index 1 for player 2.
* @param round Stores current round that is being played.
* @param round_score Stores the current round score.
* @param served_generala Is an array that stores if the player (1 or 2) has scored a served generala.
* @param selected_combination Stores the name of the combination to scratch.
* @param is_spanish Checks if the user interface language is set to Spanish.
*/
void show_end_turn_message(const std::string &player_name, int round, int round_score, bool served_generala, const std::string &selected_combination, bool is_spanish);
/**
* @brief Helps frame the text inside a text box.
* @param text_to_print Input of text.
* @param length Calculates how much space needs to fit the text inside a box.
*/
void frame_text(const std::string &text_to_print, int length);
/**
* @brief Resets the console colors to the game's default.
* @param is_debug Controls if the game runs in debug mode (manual dice selection).
*/
void reset_game_colors(bool is_debug);
#endif // ui_utils_H_INCLUDED

