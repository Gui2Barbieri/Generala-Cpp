#include <iostream>
#include "ui_utils.h"
#include "rlutil.h"
using namespace std;

void credits(bool is_spanish){
    rlutil::locate(45,13); //We move the cursor to specific places in order to build the textbox.
    is_spanish ? draw_upper_line(36) : draw_upper_line(34);
    rlutil::locate(45,15);
    is_spanish ? draw_lower_line(36) : draw_lower_line(34);
    rlutil::locate(45,14);
    is_spanish ? cout << "║" << "Software hecho por Guido Barbieri." << "║" : cout << "║" << "Software made by Guido Barbieri." << "║";
    rlutil::locate(1,1);
}

void rules(bool is_spanish){
    title();
    is_spanish ? frame_text("Reglas del juego: El juego consiste en lanzar los dados durante 10 rondas y",79) : frame_text("Game Rules: The game consists of rolling dice for 10 rounds and trying to",79);
    is_spanish ? frame_text("tratar de alcanzar el puntaje más alto usando combinaciones de dados.",80) : frame_text("achieve the highest score using different dice combinations.",79);
    frame_text(" ",79);
    is_spanish ? frame_text("Los jugadores (en caso de ser 2) empiezan tirando los dados para obtener un",79) : frame_text("Players (if there are 2) start by rolling the dice to get a score.",79);
    if(is_spanish) {frame_text("puntaje.",79);}
    frame_text(" ",79);
    is_spanish ? frame_text("Una vez lanzados los dados, se debe elegir una combinación que represente",80) : frame_text("Once rolled, you must choose a combination that represents that roll,",79);
    is_spanish ? frame_text("esa tirada de dados, y tacharla.",79) : frame_text("and scratch (record) it.",79);
    frame_text(" ",79);
    is_spanish ? frame_text("Las 'sumas individuales' permiten obtener un puntaje en base a la cantidad",79) : frame_text("The 'Individual Sums' allow scoring based on the amount 'x' of dice 'y'",79);
    is_spanish ? frame_text("'x' de dados 'y' que se consigan, otorgando x*y=puntos, siendo x 'cantidad",79) : frame_text("obtained, granting x*y=points, where x is 'dice count' multiplied",79);
    is_spanish ? frame_text("de dados' multiplicado por y 'valor del dado'.",79) : frame_text("by y 'die value'.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Suma de 1: Suma 1 punto por cada dado que haya de 1.",79) : frame_text("-Sum of ones: Adds 1 point for every die showing the number 1.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(1,2,5);
    draw_die(1,13,5);
    draw_die(3,24,5);
    draw_die(4,35,5);
    draw_die(5,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 2 puntos, porque hay dos dados.",79) : frame_text("Adds 2 points, because there are two dice.",79);
    frame_text("2*1=2.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Suma de 2: Suma 2 puntos por cada dado que haya de 2.",79) : frame_text("-Sum of twos: Adds 2 points for every die showing the number 2.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(2,2,5);
    draw_die(1,13,5);
    draw_die(3,24,5);
    draw_die(4,35,5);
    draw_die(5,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 2 puntos, porque hay un dado.",79) : frame_text("Adds 2 points, because there is one die.",79);
    frame_text("1*2=2.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Suma de 3: Suma 3 puntos por cada dado que haya de 3.",79) : frame_text("-Sum of threes: Adds 3 points for every die showing the number 3.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(3,2,5);
    draw_die(3,13,5);
    draw_die(3,24,5);
    draw_die(5,35,5);
    draw_die(4,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 9 puntos, porque hay tres dados.",79) : frame_text("Adds 9 points, because there are three dice.",79);
    frame_text("3*3=9.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Suma de 4: Suma 4 puntos por cada dado que haya de 4.",79) : frame_text("-Sum of fours: Adds 4 points for every die showing the number 4.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(4,2,5);
    draw_die(4,13,5);
    draw_die(3,24,5);
    draw_die(4,35,5);
    draw_die(2,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 12 puntos, porque hay tres dados.",79) : frame_text("Adds 12 points, because there are three dice.",79);
    frame_text("4*3=12.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Suma de 5: Suma 5 puntos por cada dado que haya de 5.",79) : frame_text("-Sum of fives: Adds 5 points for every die showing the number 5.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(5,2,5);
    draw_die(1,13,5);
    draw_die(5,24,5);
    draw_die(2,35,5);
    draw_die(6,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 10 puntos, porque hay dos dados.",79) : frame_text("Adds 10 points, because there are two dice.",79);
    frame_text("5*2=10.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Suma de 6: Suma 6 puntos por cada dado que haya de 6.",79) : frame_text("-Sum of Sixes: Adds 6 points for every die showing the number 6.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(2,2,5);
    draw_die(6,13,5);
    draw_die(5,24,5);
    draw_die(2,35,5);
    draw_die(1,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 6 puntos, porque hay un dado.",79): frame_text("Adds 6 points, because there is one die.",79);
    frame_text("6*1=10.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Escalera: se obtiene cuando se encuentran todos los valores de los dados,",79) : frame_text("-Straight: Obtained when dice show sequential values, from 1 to 5",79);
    is_spanish ? frame_text("del 1 al 5 o del 2 al 6 en una tirada.",79) : frame_text("or from 2 to 6 in a single roll.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(2,2,6);
    draw_die(4,13,6);
    draw_die(5,24,6);
    draw_die(6,35,6);
    draw_die(3,46,6);
    rlutil::locate(2,11);
    is_spanish ? frame_text("Suma 25 puntos.",79) : frame_text("Adds 25 points.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Full: se obtiene cuando 3 dados son iguales, y tambien hay dos diferentes",79) : frame_text("-Full: Obtained when 3 dice are the same, and the other two are",79);
    is_spanish ? frame_text("a los 3 primeros mencionados.",79) : frame_text("a pair (different from the first 3).",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(3,2,6);
    draw_die(3,13,6);
    draw_die(3,24,6);
    draw_die(2,35,6);
    draw_die(2,46,6);
    rlutil::locate(2,11);
    is_spanish ? frame_text("Suma 30 puntos.",79) : frame_text("Adds 30 points.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Póker: se obtiene cuando todos los dados son iguales, a excepción de uno.",81) : frame_text("-Poker: Obtained when 4 dice are the same (except for one).",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(1,2,5);
    draw_die(1,13,5);
    draw_die(1,24,5);
    draw_die(1,35,5);
    draw_die(2,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("Suma 40 puntos.",79) : frame_text("Adds 40 points.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("-Generala/Generala Servida: se obtiene cuando todos los dados son iguales, si",79) : frame_text("-Generala/Served Generala: Obtained when all 5 dice are the same. If rolled",79);
    is_spanish ? frame_text("toca en primer lanzamiento, suma 250 puntos y gana automáticamente la partida",79) : frame_text("on the first throw, it adds 250 points and the player automatically",79);
    is_spanish ? frame_text("el jugador que la sacó.",80) : frame_text("wins the match.",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(6,2,7);
    draw_die(6,13,7);
    draw_die(6,24,7);
    draw_die(6,35,7);
    draw_die(6,46,7);
    rlutil::locate(2,12);
    is_spanish ? frame_text("En caso de que no sea Generala Servida, suma 50 puntos y la partida sigue.",79) : frame_text("If it is not Served Generala, it adds 50 points and the match continues.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("Una vez que los dados hayan salido por la tirada, se debe elegir si se desea",79) : frame_text("Once the dice are rolled, you must choose whether to reroll or not.",79);
    is_spanish ? frame_text("relanzar o no. El jugador puede relanzar 2 veces, y también puede elegir",80) : frame_text("The player can reroll 2 times and choose which dice to reroll.",79);
    if(is_spanish){frame_text("qué dados quiere relanzar.",80);}
    is_spanish ? frame_text("En caso de no querer relanzar, se procede a la tachada de jugada.",79) : frame_text("If you do not want to reroll, proceed to scratch (record) the play.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("La tachada se hace por cada ronda del juego, como vimos antes, hay ",79) : frame_text("Scratching is done each round. As seen before, there are 10 rounds,",79);
    is_spanish ? frame_text("10 rondas, por lo que hay 10 jugadas.",79) : frame_text("so there are 10 plays to record.",79);
    is_spanish ? frame_text("Obligatoriamente se deberá tachar por cada ronda jugada, pero no es necesario",79) : frame_text("It is mandatory to scratch a category each round, but the category to scratch",79);
    is_spanish ? frame_text("que la jugada a tachar corresponda con la jugada realizada.",79) : frame_text("does not necessarily have to match the roll obtained.",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
    title();
    is_spanish ? frame_text("Por ejemplo, si el jugador saca:",79) : frame_text("For example, if the player rolls:",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    frame_text(" ",79);
    draw_die(3,2,5);
    draw_die(3,13,5);
    draw_die(3,24,5);
    draw_die(2,35,5);
    draw_die(2,46,5);
    rlutil::locate(2,10);
    is_spanish ? frame_text("y tacha 'Generala', la jugada se va a tachar, pero al no ser Generala",79) : frame_text("and scratches 'Generala', the category will be scratched, but since it is not",79);
    is_spanish ? frame_text("no va a sumar puntos.",79) : frame_text("a Generala, it will score no points.",79);
    frame_text(" ",79);
    is_spanish ? frame_text("Hay que tener en cuenta que una vez que se tacha, no puede volver a usarse",79) : frame_text("Keep in mind that once scratched, that category cannot be used again",79);
    is_spanish ? frame_text("esa jugada para sumar puntos, ¡por lo que hay que ser cuidadoso!",80) : frame_text("to score points, so be careful!",79);
    cout << '\n';
    draw_lower_line(79);
    pause(is_spanish);
    clear_console();
}

void title(){
    draw_upper_line(79);
    for(int i=0;i<24;i++){
        if(i==0){
            cout << "║";
        }
        else{
            cout <<"═";
        }
    }
    cout << " G   E   N   E   R   A   L   A ";
    for(int i=0;i<24;i++){
        if(i==23){
            cout << "║";
        }
        else{
            cout <<"═";
        }
    }
}

void pause(bool is_spanish){
    is_spanish ? cout << "Presiona una tecla para continuar..." : cout << "Press any key to continue...\n";
    rlutil::anykey();
}

void clear_console(){
    rlutil::cls();
}

void draw_upper_line(int length){
    for(int i=0;i<length;i++){
        if(i==0){
            cout << "╔";
        }else if(i==length-1){
            cout << "╗";
        }else{
            cout <<"═";
        }
    }
        cout << '\n';
}

void draw_line(int length){
    for(int i=0;i<length;i++){
        cout <<"═";
    }
}

void draw_lower_line(int length){
    for(int i=0;i<length;i++){
        if(i==0){
            cout << "╚";
        }
        else if(i==length-1){
            cout << "╝";
        }
        else{
            cout <<"═";
        }
    }
    cout << '\n';

}

void blinking_text(const string &text_to_print, int x, int y, int original_color){
    /*
    In this function we give the text we want to print, alongside the x and y coordinates where we want to print the text.
    We use even and uneven numbers up to 20 in order to change colors in a consecutive matter, from black to white, making it blink.
    We wait 62ms between each iteration, otherwise the colors will not be seen.
    Finally, we set the original font color.
    */
    for(int i=0;i<20;i++){
        if(i%2==0){
            rlutil::setColor(0);
        }
        else{
            rlutil::setColor(15);
        }
        rlutil::locate(x,y);
        cout << text_to_print;
        rlutil::msleep(62);
    }
    rlutil::setColor(original_color);
}

void draw_square(int x, int y){
        rlutil::locate(x,y);
        cout << "╔" << "═" << "═" << "═" << "═" << "═" << "═" << "═" << "╗";
        rlutil::locate(x,y+1);
        cout << "║" << "       " << "║";
        rlutil::locate(x,y+2);
        cout << "║" << "       " << "║";
        rlutil::locate(x,y+3);
        cout << "║" << "       " << "║";
        rlutil::locate(x,y+4);
        cout << "╚" << "═" << "═" << "═" << "═" << "═" << "═" << "═" << "╝";
}

void draw_die(int value,int x, int y){
    switch(value){
        case 1:
            draw_square(x,y);
            rlutil::locate(x+4,y+2); //indicates where to put die's dots.
            cout << "■";
            break;
        case 2:
            draw_square(x,y);
            rlutil::locate(x+1,y+1);
            cout << "▀";
            rlutil::locate(x+7,y+3);
            cout << "▄";
            break;
        case 3:
            draw_square(x,y);
            rlutil::locate(x+1,y+1);
            cout << "▀";
            rlutil::locate(x+4,y+2);
            cout << "■";
            rlutil::locate(x+7,y+3);
            cout << "▄";
            break;
        case 4:
            draw_square(x,y);
            rlutil::locate(x+1,y+1);
            cout << "▀";
            rlutil::locate(x+7,y+3);
            cout << "▄";
            rlutil::locate(x+1,y+3);
            cout << "▄";
            rlutil::locate(x+7,y+1);
            cout << "▀";
            break;
        case 5:
            draw_square(x,y);
            rlutil::locate(x+1,y+1);
            cout << "▀";
            rlutil::locate(x+7,y+3);
            cout << "▄";
            rlutil::locate(x+1,y+3);
            cout << "▄";
            rlutil::locate(x+7,y+1);
            cout << "▀";
            rlutil::locate(x+4,y+2);
            cout << "■";
            break;
        case 6:
            draw_square(x,y);
            rlutil::locate(x+1,y+1);
            cout << "▀";
            rlutil::locate(x+4,y+1);
            cout << "▀";
            rlutil::locate(x+7,y+1);
            cout << "▀";
            rlutil::locate(x+4,y+3);
            cout << "▄";
            rlutil::locate(x+1,y+3);
            cout << "▄";
            rlutil::locate(x+7,y+3);
            cout << "▄";
            break;
    }
}

void display_dice(const int dice[], const bool dice_rolling_animation[],bool is_reroll){
    int i=0;
    if(is_reroll){
        for(int x=1;x<51;x+=10){
            if(!dice_rolling_animation[i]){
                draw_die(dice[i],x,5);
            }
            i++;
            rlutil::locate(1,10);
        }
        i=0; //We reset the counter to check the array again and know which die will be displayed with animation.
        for(int x=1;x<51;x+=10){
            if(dice_rolling_animation[i]){
                random_die_animation(x,5);
                draw_die(dice[i],x,5);
            }
            i++;
            rlutil::locate(1,10);
        }
    }else{
        for(int x=1;x<51;x+=10){
            random_die_animation(x,5);
            draw_die(dice[i],x,5);
            i++;
            rlutil::locate(1,10);
        }
    }
}

void random_die_animation(int x, int y){
    for(int i=0;i<14;i++){
        rlutil::hidecursor();
        draw_die(rand()%6+1,x,y);
        cout << flush; //Force flush characters to fix the rolling animation on Linux.
        rlutil::msleep(1 + (i*13));
    }
}

void player_turn_ui(const string &player_name, int player_score, int round, int roll_count, bool is_spanish){
        is_spanish ? cout << "Turno de " << player_name << " |" << "   Ronda " << round << "   |" << " Puntaje Total: " << player_score << " puntos\n"
        : cout << "Current player: " << player_name << " |" << "   Round " << round << "    |" << " Total Score: " << player_score << " points\n";
        cout << "--------------------------------------------------\n";
        is_spanish ? cout << "Lanzamiento " << roll_count << '\n': cout << "Roll #" << roll_count << '\n';
        cout << "--------------------------------------------------\n";
}

void show_end_turn_message(const string &player_name, int round, int round_score, bool served_generala, const string &selected_combination, bool is_spanish){
    if(!served_generala){
        clear_console();
        draw_upper_line(80);
        is_spanish ? cout << "\t\t\tRonda #" << round << "\t\t\t\t\t       \n" : cout << "\t\t\tRound #" << round << "\t\t\t\t\t       \n";
        is_spanish ? cout << "\t\t\tNombre del Jugador: " << player_name << "\t\t\t       \n" : cout << "\t\t\tPlayer: " << player_name << "\t\t\t       \n";
        is_spanish ? cout <<"\t\t\tPuntaje de la ronda: " << round_score << "\t\t\t\t       \n" : cout <<"\t\t\tRound score: " << round_score << "\t\t\t\t       \n";
        is_spanish ? cout <<"\t\t\tJugada tachada: " << selected_combination << ".\n" : cout <<"\t\t\tScratched combination: " << selected_combination << ".\n";
        draw_lower_line(80);
        pause(is_spanish);
    }
}

void display_victory_message(bool served_generala[], const string player_name[], int round, bool is_debug, const int player_score[],bool is_two_players,bool is_spanish){
    if(is_two_players){
        if(!served_generala[0] && !served_generala[1]){
            if(player_score[0]>player_score[1]){
                draw_upper_line(79);
                is_spanish ? cout << "\t\t\tNombre del jugador ganador: " << player_name[0] << "\t\t\t       \n" : cout << "\t\t\tWinner's name: " << player_name[0] << "\t\t\t       \n";
                is_spanish ? cout << "\t\t\tCantidad de rondas para ganar: " << "10" << "\t\t\t\t\t       \n" : cout << "\t\t\tRounds to win: " << "10" << "\t\t\t\t\t       \n";
                is_spanish ? cout << "\t\t\tPuntaje: " << player_score[0] << '\n': cout << "\t\t\tScore: " << player_score[0] << '\n';
                draw_lower_line(79);
                pause(is_spanish);
            }else if(player_score[0]<player_score[1]){
                draw_upper_line(79);
                is_spanish ? cout << "\t\t\tNombre del jugador ganador: " << player_name[1] << "\t\t\t       \n" : cout << "\t\t\tWinner's name: " << player_name[1] << "\t\t\t       \n";
                is_spanish ? cout << "\t\t\tCantidad de rondas para ganar: " << "10" << "\t\t\t\t\t       \n" : cout << "\t\t\tRounds to win: " << "10" << "\t\t\t\t\t       \n";
                is_spanish ? cout << "\t\t\tPuntaje: " << player_score[1] << '\n': cout << "\t\t\tScore: " << player_score[1] << '\n';
                draw_lower_line(79);
                pause(is_spanish);
            }else{
                draw_upper_line(79);
                if(is_spanish){
                    cout << " Hubo empate entre " << player_name[0] << " y " << player_name[1] << ".\n"
                    << " Ambos jugadores reciben la misma cantidad de puntos: " << player_score[0] << '\n';
                }else{
                    cout << " It's a tie between " << player_name[0] << " and " << player_name[1] << ".\n"
                    << " Both players receive the same amount of points: " << player_score[0] << '\n';
                }
                draw_lower_line(79);
                pause(is_spanish);
            }
        }else if(served_generala[0]){
            draw_upper_line(79);
            is_spanish ? cout << "\t\t\tNombre del Jugador: " << player_name[0] << "\t\t\t       \n" : cout << "\t\t\tPlayer's name: " << player_name[0] << "\t\t\t       \n";
            is_spanish ? cout << "\t\t\tCantidad de rondas para ganar: " << round-1 << "\t\t\t\t\t       \n" : cout << "\t\t\tRounds to win: " << round-1 << "\t\t\t\t\t       \n";
            rlutil::hidecursor();
            draw_lower_line(79);
            if(is_debug){
                is_spanish ? blinking_text("Ganaste por Generala Servida, felicitaciones!\n",22,5,15) : blinking_text("You won by Served Generala, congratulations!\n",18,5,15);
            }else{
                is_spanish ? blinking_text("Ganaste por Generala Servida, felicitaciones!\n",22,5,0) : blinking_text("You won by Served Generala, congratulations!\n",18,5,0);
            }
            pause(is_spanish);
            rlutil::showcursor();
        }else{
            draw_upper_line(79);
            is_spanish ? cout << "\t\t\tNombre del Jugador: " << player_name[1] << "\t\t\t       \n" : cout << "\t\t\tPlayer's name: " << player_name[1] << "\t\t\t       \n";
            is_spanish ? cout << "\t\t\tCantidad de rondas para ganar: " << round-1 << "\t\t\t\t\t       \n" : cout << "\t\t\tRounds to win: " << round-1 << "\t\t\t\t\t       \n";
            rlutil::hidecursor();
            draw_lower_line(79);
            if(is_debug){
                is_spanish ? blinking_text("Ganaste por Generala Servida, felicitaciones!\n",22,5,15) : blinking_text("You won by Served Generala, congratulations!\n",18,5,15);
            }else{
                is_spanish ? blinking_text("Ganaste por Generala Servida, felicitaciones!\n",22,5,0) : blinking_text("You won by Served Generala, congratulations!\n",18,5,0);
            }
            pause(is_spanish);
            rlutil::showcursor();
        }
    }else{
        if(!served_generala[0]){
            draw_upper_line(79);
            is_spanish ? cout << "\t\t\tNombre del jugador ganador: " << player_name[0] << "\t\t\t       \n" : cout << "\t\t\tWinner's name: " << player_name[0] << "\t\t\t       \n";
            is_spanish ? cout << "\t\t\tCantidad de rondas para ganar: " << "10" << "\t\t\t\t\t       \n" : cout << "\t\t\tRounds to win: " << "10" << "\t\t\t\t\t       \n";
            is_spanish ? cout << "\t\t\tPuntaje: " << player_score[0] << '\n': cout << "\t\t\tScore: " << player_score[0] << '\n';
            draw_lower_line(79);
            pause(is_spanish);
        }else{
            draw_upper_line(79);
            is_spanish ? cout << "\t\t\tNombre del Jugador: " << player_name[0] << "\t\t\t       \n" : cout << "\t\t\tPlayer's name: " << player_name[0] << "\t\t\t       \n";
            is_spanish ? cout << "\t\t\tCantidad de rondas para ganar: " << round-1 << "\t\t\t\t\t       \n" : cout << "\t\t\tRounds to win: " << round-1 << "\t\t\t\t\t       \n";
            rlutil::hidecursor();
            draw_lower_line(79);
            if(is_debug){
                is_spanish ? blinking_text("Ganaste por Generala Servida, felicitaciones!\n",22,5,15) : blinking_text("You won by Served Generala, congratulations!\n",18,5,15);
            }else{
                is_spanish ? blinking_text("Ganaste por Generala Servida, felicitaciones!\n",22,5,0) : blinking_text("You won by Served Generala, congratulations!\n",18,5,0);
            }
            pause(is_spanish);
            rlutil::showcursor();
        }
    }
}

void frame_text(const string &text_to_print, int length){
    int char_count=0;
    cout << '\n' << "║" << text_to_print;

    while(text_to_print[char_count]!='\0'){
        char_count++;
    }

    int padding=length-char_count-2; //This is the space between the text and the border of our textbox. We substract 2 characters because
                                     //we have two '║', one at the start, and the last one at the end.

    for(int i=0;i<padding;i++){ //We print empty spaces so we can align "║" in the textbox.
        cout << " ";
    }

    cout << "║";

    //NOTE: This function doesn't work accurately with UTF-8 characters, so it needs manual lenght adjustment in that case.
}

void reset_game_colors(bool is_debug){
    if(!is_debug){
        rlutil::setBackgroundColor(6);
        rlutil::setColor(0);
    }
    else{
        rlutil::setBackgroundColor(2);
        rlutil::setColor(15);
    }
}
