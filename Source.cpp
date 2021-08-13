#include<stdio.h>
#include<string.h>

int gamemenu;

void get_player_move(char board[9])                           //To take the input of the player in single player game
{
    int single_input, k = 0, l = 0, g = 0 ;
    char arr[9];
    for (int i = 0; i < 3; i++)                                  //Loop for knowing the places of the empty places
    {
        if (i == 1)
            k = 3;
        else if (i == 2)
            k = 6;

        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                arr[l] = j + k + 1;
                l++;
            }
        }
    }

    printf("please enter ");
    for (int i = 0; i < l; i++)                                  //To print what is the empty places
    {
        if (i < l - 1)
            printf("%d,", arr[i]);
        else
            printf("%d ", arr[i]);
    }
    printf("to place your X: ");

    scanf("%d", &single_input);                                  //To take the input

    if (single_input == 1 && board[0] == ' ')
        board[0] = 'X';
    else if (single_input == 2 && board[1] == ' ')
        board[1] = 'X';
    else if (single_input == 3 && board[2] == ' ')
        board[2] = 'X';
    else if (single_input == 4 && board[3] == ' ')
        board[3] = 'X';
    else if (single_input == 5 && board[4] == ' ')
        board[4] = 'X';
    else if (single_input == 6 && board[5] == ' ')
        board[5] = 'X';
    else if (single_input == 7 && board[6] == ' ')
        board[6] = 'X';
    else if (single_input == 8 && board[7] == ' ')
        board[7] = 'X';
    else if (single_input == 9 && board[8] == ' ')
        board[8] = 'X';
    else
    {
        printf("Error you entered %d \n",single_input);
        get_player_move(board);                                  //if wrong int return it again
    }
}

void get_computer_move(char board[3][3])                         //Function of AI 
{
    int i, j;
    for (i = 0; i < 3; i++)                                      //To check if there any place to put the O
    {
        for (j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                break;
        if (board[i][j] != 'X' && board[i][j] != 'O')
            break;
    }

    if (i * j == 9)                                              //To check if there is no any place to put the O
    {
        printf("draw\n");
    }
    else
        board[i][j] = 'O';
}

void disp_board(char boar[9])                                //Fuction to print the board for both single&multi player games
{
    printf("\n");
    printf(" %c | %c | %c\n", boar[0], boar[1], boar[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", boar[3], boar[4], boar[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", boar[6], boar[7], boar[8]);
    printf("\n");
}

char check(char board[9])                                     //Function of finding the winner for single player game
{
    int i , l=0;    
    for (i = 0; i < 3; i++)
    {
        if (board[i+l] == board[i + l + 1] && board[i + l] == board[i + l + 2])
            return board[i+l];
        l = l + 3;
    }
    
    int l = 0;

    for (i = 0; i < 3; i++)                                      //Check for the columns
    {
        if (board[i + l] == board[i + 3 + l] && board[i + l] == board[i + l + 6])
            return board[i + l];
        l++;
    }
    //I didn't put them together to avoid the returning logic error

    int l = 0;

    if (board[0] == board[] && board[0][0] == board[2][2])//Check for diagonals
        return board[0];

    int l = 0;

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    return ' ';
}
                                                                 
void single_player()                                             //The function of playing single player
{
    char boar[9] = { '1','2','3','4','5','6','7','8','9'};
    int done = ' ';
    int single_input = 0;
    printf("\n\nSingle-player has chosen. \n");
    printf("You (X) will be playing against the computer (O).\n");
    done = ' ';                                               
    printf("\n");
    printf(" %c | %c | %c\n", boar[0], boar[1], boar[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", boar[3], boar[4], boar[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", boar[6], boar[7], boar[8]);
    printf("\n");                                                //print to the player the board with numbers to know how to play
    char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };
    do {                                                         //the loop of the game
        disp_board(board);                                       //Print the matrix every input
        get_player_move(board);                                  //To take the move from the player
        done = check(board);                                     //To check if the there any winner
        if (done != ' ')
            break;                                               //To break the loop if there any winner
        get_computer_move(board);
        done = check(board);
    } while (done == ' ');
    if (done == 'X')                                             //If the player wins
    {
        disp_board(board);                                       
        printf("\n YOU WON!\n");
    }
    else
    {
        disp_board(board);
        printf("I WON!\n");
    }
}

void multiplayer()                                               //the function of playing multiplayer
{
    char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
    int win = 0, input = 0, done = ' ', restart=0, k = 0, l = 0, g = 0;
    char player,r;
    char arr[9];

    for (int i = 0; i < 3; i++)                                  //The Following lines is to make the player know what the number he must enter
    {
        if (i == 1)
            k = 3;
        else if (i == 2)
            k = 6;

        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 'O' || board[i][j] == 'X')
            {
                arr[l] = j + k + 1;
                l++;
            }
        }
    }

    for (int i = 0; i < 9 && win == 0; i++)                      //The loop of the game
    {
        disp_board(board);                                       //Print the board every input
        player = i % 2 + 1;                                      //player 1 or 2?      
        do
        {
            printf("please player %d enter 0~9 ",player);        //Take the input from the player
            for (int i = 0; i < l; i++)
            {
                if (i < l - 1)
                    printf("%d,", arr[i]);
                else
                    printf("%d ", arr[i]);
            }
            printf("to place your %c: ", (player == 1) ? 'X' : 'O');
            scanf("%d", &input);
            if (input == 1 && board[0][0] == '1')                //Place the input of the player
            {
                board[0][0] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 2 && board[0][1] == '2')
            {
                board[0][1] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 3 && board[0][2] == '3')
            {
                board[0][2] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 4 && board[1][0] == '4')
            {
                board[1][0] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 5 && board[1][1] == '5')
            {
                board[1][1] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 6 && board[1][2] == '6')
            {
                board[1][2] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 7 && board[2][0] == '7')
            {
                board[2][0] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 8 && board[2][1] == '8')
            {
                board[2][1] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else if (input == 9 && board[2][2] == '9')
            {
                board[2][2] = (player == 1) ? 'X' : 'O';
                restart = 0;
            }
            else
            {
                printf("Error : you entered %d \n", input);
                restart = 1;
            }
        }while(restart == 1);
        done = check(board);                                     //Check if there any winner
        if (done != ' ')                                         //if there any winner
            win = player;
    }
    disp_board(board);                                           //print the final board

    if (win == 0)                                                //If there is no any winners
        printf("\nDraw\n");
    else
        printf("\nplayer %d, YOU WON!\n", win);

}
                                                                 
void again_question()                                            //The again question
{
    int i = 0;
    printf("(1) Play Again? \n");
    printf("(2) Exit the game. \n");
    scanf("%d", &gamemenu);

    if (gamemenu == 1)
    {
            printf("(1) SinglePlayer \n");
            printf("(2) Multiplayer \n");
            scanf("%d", &gamemenu);

            while (gamemenu != 1 && gamemenu != 2)               //If he enters wrong int
            {
                if (i != 2)
                {
                    printf("please enter 1 or 2 \n");
                    scanf("%d", &gamemenu);
                    i++;
                }
                else
                {
                    printf("ERROR YOU ENTERED %d, PLEASE ENTER 1 OR 2 \n", gamemenu);
                    scanf("%d", &gamemenu);
                }
            }


            if (gamemenu == 1)
            {
                single_player();
                again_question();
            }
            else if (gamemenu == 2)
            {
                multiplayer();
                again_question();
            }
    }
    else if (gamemenu == 2)
        printf("\nYou left the game\n");
    else
    {
        printf("Error: you entered %d, please enter 1 or 2\n",gamemenu);
        again_question();
    }
}

int main()
{
    int i = 0;
    printf("WELCOME to Tic Tac Toe game. \n");
    printf("(1) SinglePlayer \n");
    printf("(2) Multiplayer \n");
    printf("(3) Exit the game \n");
    scanf("%d", &gamemenu);                                      //Take the input to know which game will be played
    while (gamemenu != 1 && gamemenu != 2 && gamemenu != 3)      //If the player entered wrong int
    {
        printf("please enter 1 or 2 or 3 \n");
        scanf("%d", &gamemenu);
    }
    if (gamemenu == 1)                                           //To play verses the AI
    {
        single_player();
        again_question();                                        //To ask the user if he want to play again
    }
    else if (gamemenu == 2)                                      //To play Tic Tac Toe multiplayer
    {
        multiplayer();
        again_question();

    }
    else if (gamemenu == 3)                                      //If he chooses to exit the game
    {
        printf("\nAre you Sure \n");
        printf("(1) No, Play the Game \n");
        printf("(2) Yes \n");
        scanf("%d", &gamemenu);


        if (gamemenu == 1)
        {
                printf("\n(1) SinglePlayer \n");
                printf("(2) Multiplayer \n");


                scanf("%d", &gamemenu);

                while (gamemenu != 1 && gamemenu != 2)
                {
                    int i=0;
                    if (i != 2)
                    {
                        printf("please enter 1 or 2 \n");
                        scanf("%d", &gamemenu);
                        i++;
                    }
                    else
                    {
                        printf("ERROR YOU ENTERED %d, PLEASE ENTER 1 OR 2 \n",gamemenu);
                        scanf("%d", &gamemenu);
                    }
                }


                if (gamemenu == 1)
                {
                    single_player();
                    again_question();
                }
                else if (gamemenu == 2)
                {
                    multiplayer();
                    again_question();
                }
        }
        else if (gamemenu == 2)
            printf("\nYou left the game\n");
    }

    return 0;
}
