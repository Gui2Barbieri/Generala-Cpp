#include <iostream>
#include <string>
#include "ui_utils.h"
#include "game.h"
#include "game_utils.h"
#include "rlutil.h"
using namespace std;

void game(int &highest_score, string &highest_score_player, bool is_debug,bool is_two_players, bool is_spanish){
    rlutil::saveDefaultColor();
    bool served_generala[2]={};
    bool scratched_combination[2][10]={};
    // Tracks if a player has already used or scratched a combination.
    // A 'true' value means the combination is no longer available.
    // First index: Player (0 for Player 1, 1 for Player 2).
    // Second index: Combination type (for example, 0 is Generala).
    string player_name[2];
    int player_score[2]={};
    if(is_two_players){
        is_spanish ? cout << "■" << " Introduzca el nombre del jugador 1: " : cout << "■" << " Enter player 1 name: ";
        cin >> player_name[0];
        clear_console();
        is_spanish ? cout << "■" << " Introduzca el nombre del jugador 2: " : cout << "■" << " Enter player 2 name: ";
        cin >> player_name[1];
        clear_console();
    }else{
        is_spanish ? cout << "■" << " Introduzca el nombre del jugador: " : cout << "■" << " Enter player name: ";
        cin >> player_name[0];
        clear_console();
    }
    int dice[5];
    match(player_name,player_score,dice,highest_score,highest_score_player,served_generala,is_debug,scratched_combination,is_two_players,is_spanish);
    update_ranking(player_score,player_name,highest_score,highest_score_player,is_two_players);
}

void match(const string player_name[], int player_score[], int dice[], int &highest_score, string &highest_score_player, bool served_generala[], bool is_debug, bool scratched_combination[][10], bool is_two_players, bool is_spanish){
    int round=1;
    for(;!served_generala[0] && !served_generala[1] && round<11;round++){
        turn(player_name[0],player_score[0],dice,served_generala[0],round,is_debug,scratched_combination[0],is_spanish);
        if(is_two_players && !served_generala[0]){
           turn(player_name[1],player_score[1],dice,served_generala[1],round,is_debug,scratched_combination[1],is_spanish);
        }
    }
    display_victory_message(served_generala,player_name,round,is_debug,player_score,is_two_players,is_spanish);
}
void turn(const string &player_name, int &player_score,int dice[], bool &served_generala, int &round, bool is_debug, bool scratched_combination[], bool is_spanish){
    int roll_count=1;
    int round_score=0;
    bool is_reroll=false;
    bool dice_rolling_animation[5]={true,true,true,true,true};
    string selected_combination;
    if(is_debug){
        roll_dice_debug(dice);
    }else{
        roll_dice(dice);
    }
    clear_console();
    player_turn_ui(player_name,player_score,round,roll_count,is_spanish);
    display_dice(dice,dice_rolling_animation,is_reroll);
    roll_again(player_name,player_score,dice,served_generala,round,roll_count,round_score,is_debug,selected_combination,scratched_combination,dice_rolling_animation,is_reroll,is_spanish);
    show_end_turn_message(player_name,round,round_score,served_generala,selected_combination,is_spanish);
    clear_console();
    }

void roll_again(const string &player_name, int &player_score,int dice[5], bool &served_generala, int &round, int &roll_count, int &round_score, bool is_debug, string &selected_combination, bool scratched_combination[],bool dice_rolling_animation[], bool is_reroll, bool is_spanish){
    bool is_turn_finished=false;
    do{
        char reroll='\0';
        int reroll_quantity=0;
        int dice_to_reroll[5];
        is_spanish ? cout << "■" << " ¿Continuar lanzando?(S/N): " : cout << "■" << " Do you want to reroll? (Y/N): ";
        cin >> reroll;
        while(reroll!='S' && reroll!='N' && reroll!='s' && reroll!='n' && reroll!='Y' && reroll!='y'){
            rlutil::setColor(4);
            is_spanish ? cout << "Ingrese un valor válido." : cout << "Enter a valid value.";
            cin >> reroll;
            reset_game_colors(is_debug);
        }
        if(reroll=='S' || reroll=='s' || reroll=='y' || reroll =='Y'){ //Accepts both 'Y' and 'S' to support bilingual user input (English/Spanish)
            roll_count++;
            for(int i=0;i<5;i++){
                dice_rolling_animation[i]=false; //Disables the animation for dice, so that way it will only animate the user chosen dice in the future.
            }
            is_reroll=true;
            is_spanish ? cout << "■" << " ¿Cuántos dados volves a tirar?: " : cout << "How many dice do you want to reroll?: ";
            cin >> reroll_quantity;
            while(reroll_quantity<1 || reroll_quantity>5){
                rlutil::setColor(4);
                is_spanish ? cout << "Ingrese una cantidad válida.\n" : cout << "Enter valid quantity.\n";
                cin >> reroll_quantity;
                reset_game_colors(is_debug);
            }
            cout << "-----------------------------------\n";
            for(int i=0;i<reroll_quantity;i++){
                is_spanish ? cout << "Dado #" << i+1 << " a relanzar: " : cout << "Die #" << i+1 << " to reroll: ";
                cin >> dice_to_reroll[i];
                while(dice_to_reroll[i]<1 || dice_to_reroll[i]>5){
                    rlutil::setColor(4);
                    is_spanish ? cout << "Ingrese un valor válido.\n" : cout << "Enter a valid value.\n";
                    reset_game_colors(is_debug);
                    cin >> dice_to_reroll[i];
                }
                check_duplicate_reroll(dice_to_reroll,i,is_spanish,is_debug);
                dice_rolling_animation[dice_to_reroll[i]-1]=true;
            }
            for(int i=0;i<reroll_quantity;i++){
                if(is_debug){
                    is_spanish ? cout << "Ingrese el valor de dado deseado para el dado " << dice_to_reroll[i] << '\n' : cout << "Enter the desired value for die number " << dice_to_reroll[i] << '\n';
                    cin >> dice[dice_to_reroll[i]-1];
                }else{
                    dice[dice_to_reroll[i]-1]=(rand()%6)+1;
                }
            }
            clear_console();
            player_turn_ui(player_name,player_score,round,roll_count,is_spanish);
            display_dice(dice,dice_rolling_animation,is_reroll);
            if(roll_count==3){
                end_turn(player_score,dice,served_generala,round,roll_count,round_score,selected_combination,scratched_combination,is_turn_finished,is_spanish);
            }

            }else if(reroll=='N' || reroll=='n'){
                end_turn(player_score,dice,served_generala,round,roll_count,round_score,selected_combination,scratched_combination,is_turn_finished,is_spanish);
            }

    }while(!is_turn_finished);

}

void evaluate_roll(const int dice[5],int &score, bool &served_generala, int roll_count, int &round_score, int &round, string &selected_combination, bool scratched_combination[], bool is_spanish){
    int combination_to_scratch=0;
    int calculate_dice_score[5]; //This will be a clone of dice[], it will be used to sort the array in order to make combinations checks easier.
    copy_array(dice,calculate_dice_score);
    sort_dice(calculate_dice_score);
    draw_line(50);
    is_spanish ? cout << "\nElegí que jugada vas a tachar.\n"
    << "0-Generala\n"
    << "1-Póker\n"
    << "2-Full\n"
    << "3-Escalera\n"
    << "4-Suma de 6\n"
    << "5-Suma de 5\n"
    << "6-Suma de 4\n"
    << "7-Suma de 3\n"
    << "8-Suma de 2\n"
    << "9-Suma de 1\n\n"
    << "■" << " Su selección: " :
    cout << "\nSelect which combination will you scratch.\n"
    << "0-Generala\n"
    << "1-Poker\n"
    << "2-Full\n"
    << "3-Straight\n"
    << "4-Sum of 6\n"
    << "5-Sum of 5\n"
    << "6-Sum of 4\n"
    << "7-Sum of 3\n"
    << "8-Sum of 2\n"
    << "9-Sum of 1\n\n"
    << "■" << " Your selection: ";
    cin >> combination_to_scratch;
    check_valid_scratch(combination_to_scratch,scratched_combination,is_spanish);
    while(!scratched_combination[combination_to_scratch]){
        is_spanish ? cout << "Usted eligió tachar: " << get_combination_name(combination_to_scratch,is_spanish) << '\n':
                     cout << "You choose to scratch: " << get_combination_name(combination_to_scratch,is_spanish) << '\n';
        cin.ignore(1000,'\n');
        pause(is_spanish);
        switch(combination_to_scratch){
            case 0:
                if(calculate_dice_score[0]==calculate_dice_score[4]){
                    if(roll_count==1){
                        served_generala=true;
                        score+=250;
                    }else{
                        score+=50;
                        round_score=50;
                    }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 1:
                if((calculate_dice_score[0]==calculate_dice_score[3] || calculate_dice_score[1]==calculate_dice_score[4])){
                    score+=40;
                    round_score=40;
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 2:
                if((calculate_dice_score[0]==calculate_dice_score[2] && calculate_dice_score[0]!=calculate_dice_score[4] && calculate_dice_score[3]==calculate_dice_score[4]) || (calculate_dice_score[0]==calculate_dice_score[1] && calculate_dice_score[2]!=calculate_dice_score[0] && calculate_dice_score[2]==calculate_dice_score[4])){
                    score+=30;
                    round_score=30;
                    scratched_combination[combination_to_scratch]=true;
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 3:
                if(calculate_dice_score[0]==calculate_dice_score[1]-1 && calculate_dice_score[0]==calculate_dice_score[2]-2 && calculate_dice_score[0]==calculate_dice_score[3]-3 && calculate_dice_score[0]==calculate_dice_score[4]-4){
                    score+=25;
                    round_score=25;
                    scratched_combination[combination_to_scratch]=true;
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 4:
                for(int i=0;i<5;i++){
                    if(calculate_dice_score[i]==6){
                        score+=6;
                        round_score+=6;
                        scratched_combination[combination_to_scratch]=true;
                    }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 5:
                for(int i=0;i<5;i++){
                    if(calculate_dice_score[i]==5){
                        score+=5;
                        round_score+=5;
                        scratched_combination[combination_to_scratch]=true;
                    }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 6:
                for(int i=0;i<5;i++){
                    if(calculate_dice_score[i]==4){
                        score+=4;
                        round_score+=4;
                        scratched_combination[combination_to_scratch]=true;
                    }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 7:
                for(int i=0;i<5;i++){
                    if(calculate_dice_score[i]==3){
                        score+=3;
                        round_score+=3;
                        scratched_combination[combination_to_scratch]=true;
                    }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 8:
                for(int i=0;i<5;i++){
                    if(calculate_dice_score[i]==2){
                        score+=2;
                        round_score+=2;
                        }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            case 9:
                for(int i=0;i<5;i++){
                    if(calculate_dice_score[i]==1){
                        score+=1;
                        round_score+=1;
                    }
                }
                scratched_combination[combination_to_scratch]=true;
                selected_combination=get_combination_name(combination_to_scratch,is_spanish);
                break;
            }
        }
    }

void check_duplicate_reroll(int dice_to_reroll[], int i, bool is_spanish, bool is_debug){
    bool is_repeated=false;
    do{
       for(int j=0;j<i;j++){
            if(dice_to_reroll[i]==dice_to_reroll[j]){
                is_repeated=true;
                rlutil::setColor(4);
                is_spanish ? cout << "Ese valor ya fue ingresado. Ingrese otro: " :
                cout << "That value is already used. Choose another one.";
                reset_game_colors(is_debug);
                cin >> dice_to_reroll[i];
                while(dice_to_reroll[i]<1 || dice_to_reroll[i]>5){
                    rlutil::setColor(4);
                    is_spanish ? cout << "Ingrese un valor válido (1 a 5): " :
                    cout << "Enter a valid value (1 to 5): ";
                    reset_game_colors(is_debug);
                    cin >> dice_to_reroll[i];
                }
                break;
            }else{
                is_repeated=false;
            }
        }
    }while(is_repeated);
}

void check_valid_scratch(int &combination_to_scratch,bool scratched_combination[],bool is_spanish){
    bool is_valid_scratch=true;
    do{
        if(combination_to_scratch>9 || combination_to_scratch<0){
            is_valid_scratch=false;
            is_spanish ? cout << "Jugada invalida, elegi otra.\n" : cout << "Invalid combination, choose a valid one.\n";
            cin >> combination_to_scratch;
        }else if(scratched_combination[combination_to_scratch]){
            is_valid_scratch=false;
            is_spanish ? cout << "Jugada ya tachada, elegi otra.\n" : cout << "Combination already used, choose another one.\n";
            cin >> combination_to_scratch;
        }else{
            is_valid_scratch=true;
        }

    }while(!is_valid_scratch);
}

void end_turn(int &player_score, const int dice[5], bool &served_generala, int &round, int &roll_count, int &round_score, string &selected_combination, bool scratched_combination[], bool &is_turn_finished, bool is_spanish){
    is_turn_finished=true;
    evaluate_roll(dice,player_score,served_generala,roll_count,round_score,round,selected_combination,scratched_combination,is_spanish);
    clear_console();
}
