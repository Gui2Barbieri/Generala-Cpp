#include <iostream>
#include "ui_utils.h"
#include "game.h"
#include "game_utils.h"
#include <ctime>
#include <string>
#include "rlutil.h"
#ifdef _WIN32
#include <windows.h> //if the platform we are compiling is Windows, then we include the windows.h header.
#endif
using namespace std;

int main(){
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); //We set the Windows console using Windows's API to accept UTF-8 characters.
    SetConsoleCP(CP_UTF8);       //This is done to improve Spanish text and maintain character compatibility with Linux.
    #endif
    bool is_debug=false;
    reset_game_colors(is_debug);
    clear_console(); //Update the console background color.
    srand(time(0));
    char user_choice='\0';
    bool is_two_players=false;
    bool is_spanish=false;
    int highest_score=0;
    string highest_score_player;
    do{
    credits(is_spanish);
    title();
    cout << '\n';
    draw_lower_line(79);
    is_spanish ? cout << "Seleccione una opción: \n" : cout << "Select an option: \n";
    is_spanish ? cout << "1.Juego nuevo para un jugador\n" : cout << "1.New game for one player\n";
    is_spanish ? cout << "2.Juego nuevo para dos jugadores\n" : cout << "2.New game for two players\n";
    is_spanish ? cout << "3.Ver puntuación mas alta\n" : cout << "3.Check highest score\n";
    is_spanish ? cout << "4.Reglas\n" : cout << "4.Rules\n";
    is_spanish ? cout << "5.Cambiar idioma a Inglés\n" : cout << "5.Change language to Spanish\n";
    cout << "----------------------------------\n";
    is_spanish ? cout << "Ingrese '0' para salir.\n\n" : cout << "Enter '0' to exit.\n\n";
    is_spanish ? cout << "■" << " Opción: ": cout << "■" << " Option: ";
    cin >> user_choice;
    cin.ignore(1000,'\n'); //Cleans the buffer in order to make rules work properly on Linux.
    switch(user_choice){
        case '1':
            clear_console();
            is_two_players=false;
            game(highest_score,highest_score_player,is_debug,is_two_players,is_spanish);
            clear_console();
            break;
        case '2':
            clear_console();
            is_two_players=true;
            game(highest_score,highest_score_player,is_debug,is_two_players,is_spanish);
            clear_console();
            break;
        case '3':
            clear_console();
            ranking(highest_score,highest_score_player,is_spanish);
            pause(is_spanish);
            clear_console();
            break;
        case '4':
            clear_console();
            rules(is_spanish);
            clear_console();
            break;
        case '5':
            if(!is_spanish){
                is_spanish=true;
            }else{
                is_spanish=false;
            }
            break;
        case '9':
            debug_mode(is_debug,is_spanish);
            break;
        case '0':
            break;
        default:
            rlutil::setColor(4);
            is_spanish ? cout << " Ingrese una opción válida\n" : cout << " Please select a valid option\n";
            pause(is_spanish);
            clear_console();
            reset_game_colors(is_debug);
        }
        clear_console();
    }while(user_choice!='0');
    return 0;
}
