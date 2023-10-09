/* this is a tic tac toe project designed by Ulises Romero */

#include <iostream>
using namespace std;

void GameBoardDisplay(char GameBoard[3][3]);
bool PlayingGame(char GameBoard[3][3], char player);
bool PlayerMove(char GameBoard[3][3], int row, int columns, char Player);


int main(){
    
    const int rows = 3;
    const int columns = 3;
    char GameBoard[rows][columns] = {'*','*','*',
                                    '*', '*', '*',
                                    '*', '*', '*',}; /* GAME BOARD 3 ROWS 3 COLUMNS*/
    char Player = 'X';
    char Player2 = 'O';
    bool GameWinner = false;
    int totalturns = 9; 
    int turns = 0;
    
    
    while(totalturns != turns){
        /* PLAYER TURN */
        int row;
        int column;
        GameBoardDisplay(GameBoard);
        cout << "Player " << Player << " enter a row: ";
        cin >> row;
        cout << "Enter a column: ";
        cin >> column;
        
        if(PlayerMove(GameBoard, row, column, Player)) {

            GameBoard[row][column] = Player;
            turns++;
            bool Valid = PlayingGame(GameBoard,Player); 

            if(Valid == true)
                break;
            
            if (Player == 'X')
                Player = 'O';
            else 
                Player = 'X';
        } 
        else 
            cout << "Invalid move, try again." << endl;
    }

   
    return 0;
}

void GameBoardDisplay(char GameBoard[3][3]){
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << GameBoard[i][j];
        }
        cout << endl;
    }   
        cout << "------------CURRENT BOARD------------" << endl;
        cout << endl;
}

/* Explains how a winner is identified via vertical, horizontal, diagnal 
   Also checks if there is a tie which is when the board if full and no further moves can be implemented
   */
bool PlayingGame(char GameBoard[3][3], char player){
    bool FullBoard = true;
    
    for(int i = 0; i < 3; i++){
        if(GameBoard[i][0] == player && GameBoard[i][1] == player && GameBoard[i][2] == player){
            cout << "You have won the game of Tic Tac Toe!";
            return true;
        }
        if(GameBoard[0][i] == player && GameBoard[1][i] == player && GameBoard[2][i] == player){
             cout << "You have won the game of Tic Tac Toe!";
            return true;
        }
    }

    if((GameBoard[0][0] == player && GameBoard[1][1] == player && GameBoard[2][2] == player)){
         cout << "You have won the game of Tic Tac Toe!";
            return true;
    }

    if(GameBoard[0][2] == player && GameBoard[1][1] == player && GameBoard[2][0] == player){
        cout << "You have won the game of Tic Tac Toe!";
            return true;
    }

    /* Checking if there is a tie if board is FULL */
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(GameBoard[i][j] == '*'){
                FullBoard = false;
            }
        }
    }

    if(FullBoard){
        cout << "The Tic Tac Toe Board is full! End game. " << endl;
        return true;
    }

    return false;
}

/* Checking if player has made a successful move and using input validation to check if it meets the correct criteria*/
bool PlayerMove(char GameBoard[3][3], int row, int columns, char Player){
    if(row >= 0 && row < 3 && columns >= 0 && columns < 3 && GameBoard[row][columns] == '*'){
        cout << "You have made a valid move. " << endl;
        return true;
    }else {
        cout << "Not a successful move, try again. " << endl;
        return false;
    }
    
}