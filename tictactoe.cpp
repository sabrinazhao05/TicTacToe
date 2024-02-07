#include <iostream>

using namespace std;

// declare board array
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

// delcare variables
string player1;
string player2;
int choice;
char turn = 'X';
bool draw = 0;

// lists all created functions
void displayBoard();
void playerTurn();
void playerChange();
char ifWin();
void play();

// function to display board
void displayBoard(){
   system("cls");
   cout << "\nTic Tac Toe\n\n";
   cout << player1 << " [X] - " << player2 << " [O]\n\n";
   cout << "     |     |     \n";
   cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
   cout << "_____|_____|_____\n";
   cout << "     |     |     \n";
   cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
   cout << "_____|_____|_____\n";
   cout << "     |     |     \n";
   cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
   cout << "     |     |     \n";
}

// function to determine spot to turn into X or O
void playerTurn(){
   if(turn == 'X'){
      cout << "\n" << player1 << " [X] turn: ";
   } else if(turn == 'O'){
      cout << "\n" << player2 << " [O] turn: ";
   }
   cin >> choice;

   // switch function to change spots into corresponding player's symbol
   switch(choice){
      case 1:
         if(board[0][0] == '1'){
            board[0][0] = turn;
         } else {
            cout << "Invalid move "; // returns invalid move if other characters are entered
            playerTurn();
         }
         break;
      case 2:
         if(board[0][1] == '2'){
            board[0][1] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 3:
         if(board[0][2] == '3'){
            board[0][2] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 4:
         if(board[1][0] == '4'){
            board[1][0] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 5:
         if(board[1][1] == '5'){
            board[1][1] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 6:
         if(board[1][2] == '6'){
            board[1][2] = turn;
         } else{
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 7:
         if(board[2][0] == '7'){
            board[2][0] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 8:
         if(board[2][1] == '8'){
            board[2][1] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      case 9:
         if(board[2][2] == '9'){
            board[2][2] = turn;
         } else {
            cout << "Invalid move ";
            playerTurn();
         }
         break;
      default:
         cout << "Invalid move ";
         playerTurn();
   }
}

// to find out who's turn it is
void playerChange(){
   if(turn == 'X'){ // simple if-else statement
      turn = 'O';
   } else {
      turn = 'X';
   }
}
//create a function to check for a winner
char ifWin(){
    //check for a winner in the rows
   if(board[0][0] == board[0][1] && board[0][1] == board[0][2]){ // checks for a win in rows
      return board[0][0];
   } else if(board[1][0] == board[1][1] && board[1][1] == board[1][2]){
      return board[1][0];
   } else if(board[2][0] == board[2][1] && board[2][1] == board[2][2]){
      return board[2][0];
   } else if(board[0][0] == board[1][0] && board[1][0] == board[2][0]){ // checks for a win in columns
      return board[0][0];
   } else if(board[0][1] == board[1][1] && board[1][1] == board[2][1]){
      return board[0][1];
   } else if(board[0][2] == board[1][2] && board[1][2] == board[2][2]){
      return board[0][2];
   } else if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){ // checks for a win in diagonals
      return board[0][0];
   } else if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
      return board[0][2];
   } else{
        return '/'; // if there is no winner (draw)
   }
}

//create a function to play the game
void play(){
   char player = 'X';
   int n = 0;
   char winner;

   while(n < 9){
      displayBoard();
      playerTurn();
      playerChange();
      n++;
      winner = ifWin();
      if(winner == 'X'){ // determines who wins or if it is a draw
         displayBoard();
         cout << "\n" << player1 << " [X] wins!\n\n";
         break;
      } else if(winner == 'O'){
         displayBoard();
         cout << "\n" << player2 << " [O] wins!\n\n";
         break;
      }
   }
   if(winner == '/'){
      cout << "\nIt's a draw!\n\n";
   }
}

//create a main function
int main(){
   // allows user to enter names
   cout << "Name of Player 1: ";
   cin >> player1;
   cout << "Name of Player 2: ";
   cin >> player2;

   play();
   return 0;
}
