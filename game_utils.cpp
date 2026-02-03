#include <iostream>
#include <string>
#include "ui_utils.h"
#include "rlutil.h"

using namespace std;

void roll_dice(int dice[]){
    for(int i=0;i<5;i++){
        dice[i]=(rand()%6)+1;;
    }
}

void roll_dice_debug(int dice[]){
    for(int i=0;i<5;i++){
        cout << "Seleccione los dados a ser lanzados." << '\n';
        cin >> dice[i];
    }
}

void ranking(int highest_score, const string &highest_score_player, bool is_spanish){
    if(highest_score==0){
        draw_upper_line(80);
        is_spanish ? cout << " No hay jugadores en el ranking aun.\n" : cout << " There are no players in the ranking yet.\n";
        draw_lower_line(80);
    }
    else{
        draw_upper_line(80);
        is_spanish ? cout << "\t\t\tEl jugador con mayor puntuacion es: " << highest_score_player << '\n' : cout << "\t\t\tThe highest scoring player is: " << highest_score_player << '\n';
        is_spanish ? cout << "\t\t\tEl puntaje es " << highest_score << '\n' : cout << "\t\t\tThe score is: " << highest_score << '\n';
        draw_lower_line(80);
    }
}

void update_ranking(const int player_score[],const string player_name[], int &highest_score, string &highest_score_player, bool is_two_players){
    if(is_two_players){
        if(player_score[0]==player_score[1]){
            return;
        }
        if(player_score[0]>highest_score){
            highest_score=player_score[0];
            highest_score_player=player_name[0];
        }
        if(player_score[1]>highest_score){
            highest_score=player_score[1];
            highest_score_player=player_name[1];
        }
    }else{
        if(player_score[0]>highest_score){
            highest_score=player_score[0];
            highest_score_player=player_name[0];
        }
    }
}

void debug_mode(bool &is_debug, bool is_spanish){
    rlutil::saveDefaultColor();
    clear_console();
    if(is_debug==false){
        rlutil::setBackgroundColor(2);
        clear_console();
        rlutil::setColor(15);
        is_debug=true;
        is_spanish ? cout << "Modo debug activado, ahora puede elegirse los dados en lanzamiento manual.\n" : cout << "Debug mode is now enabled, you can choose each die rolling value.\n";
        pause(is_spanish);
        }else{
        rlutil::setBackgroundColor(4);
        clear_console();
        rlutil::setColor(15);
        is_spanish ? cout << "Modo debug desactivado, los dados van a tener su lanzamiento normal.\n" : cout << "Debug mode is now disabled, rolling will have random values.\n";
        is_debug=false;
        pause(is_spanish);
        reset_game_colors(is_debug);
        }
}

string get_combination_name(int combination_index, bool is_spanish) {
    switch(combination_index) {
        case 0:
            return "Generala";
        case 1:
            return "Poker";
        case 2:
            return "Full";
        case 3:
            return is_spanish ? "Escalera" : "Straight";
        case 4:
            return is_spanish ? "Suma de 6" : "Sum of 6";
        case 5:
            return is_spanish ? "Suma de 5" : "Sum of 5";
        case 6:
            return is_spanish ? "Suma de 4" : "Sum of 4";
        case 7:
            return is_spanish ? "Suma de 3" : "Sum of 3";
        case 8:
            return is_spanish ? "Suma de 2" : "Sum of 2";
        case 9:
            return is_spanish ? "Suma de 1" : "Sum of 1";
        default:
            return is_spanish ? "No se registró una jugada válida" : "A valid combination was not detected";
    }
}

void copy_array(const int source[], int destination[]){

    for(int i=0;i<5;i++){
        destination[i]=source[i];
    }

}

void sort_dice(int dice_copia[]){
    int buffer=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            if(dice_copia[j]>dice_copia[j+1]){
                buffer=dice_copia[j];
                dice_copia[j]=dice_copia[j+1];
                dice_copia[j+1]=buffer;
            }
        }
    }
}
