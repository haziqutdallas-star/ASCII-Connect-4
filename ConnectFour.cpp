/*
Connect4

(built before learning arrays or lists)

Author: Haziq Shaik
Finish date: 10/30/25

inputs: 2 player names, playspace(1-7)
Outputs: Game board, player's turn + legality of the user's turn, winner




*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//global variables
string line6 = "| | | | | | | |";
string line5 = line6;
string line4 = line6;
string line3 = line6;      //initalize gameboard
string line2 = line6;
string line1 = line6;

bool gameEnd = false;    
string player1, player2;
char playerCoin;
bool validPlay = true;

void boardDisplay(){ //prints game board to console

   string lineDiv = "|-+-+-+-+-+-+-|";
   cout << "\n 1 2 3 4 5 6 7 " << endl;
   //cout << lineDiv << endl;
   cout << line6 << endl;
   cout << lineDiv << endl;
   cout << line5 << endl;
   cout << lineDiv << endl;
   cout << line4 << endl;
   cout << lineDiv << endl;
   cout << line3 << endl;
   cout << lineDiv << endl;
   cout << line2 << endl;
   cout << lineDiv << endl;
   cout << line1 << endl;
   cout << "---------------" << endl;
   cout << "//" << setw(15) << "\\\\\n-" << setw(14) << "-" << endl;
}

bool updateBoard(int j){   //updates the board after a player turn
   if(line1.at(j)==' ')      //checks if space is open to play in
         line1.at(j)=playerCoin; //goes up the game board to find an available play space
      else if(line2.at(j)==' ')
         line2.at(j)=playerCoin;
      else if(line3.at(j)==' ')
         line3.at(j)=playerCoin;
      else if(line4.at(j)==' ')
         line4.at(j)=playerCoin;
      else if(line5.at(j)==' ')
         line5.at(j)=playerCoin;
      else if(line6.at(j)==' ')
         line6.at(j)=playerCoin;
      else
         return false;  //return false if the column is full (unavailable play space)
      return true;      //return true if column isn't full (available play space)

}

bool winDetected(){  //detect if a win is on the game board
   
   for(int k=1;k<8;k+=2){  //checks all the rows for a horizontal win
      if((line1.at(k) != ' ' && line1.at(k) == line1.at(k+2) && line1.at(k) == line1.at(k+4) && line1.at(k) == line1.at(k+6)) ||  //horizontal wins
         (line2.at(k) != ' ' && line2.at(k) == line2.at(k+2) && line2.at(k) == line2.at(k+4) && line2.at(k) == line2.at(k+6)) ||
         (line3.at(k) != ' ' && line3.at(k) == line3.at(k+2) && line3.at(k) == line3.at(k+4) && line3.at(k) == line3.at(k+6)) ||
         (line4.at(k) != ' ' && line4.at(k) == line4.at(k+2) && line4.at(k) == line4.at(k+4) && line4.at(k) == line4.at(k+6)) ||
         (line5.at(k) != ' ' && line5.at(k) == line5.at(k+2) && line5.at(k) == line5.at(k+4) && line5.at(k) == line5.at(k+6)) ||
         (line6.at(k) != ' ' && line6.at(k) == line6.at(k+2) && line6.at(k) == line6.at(k+4) && line6.at(k) == line6.at(k+6)))
         return true;   //return true if a win is detected
      }
   for(int l=1;l<14;l+=2){ //checks all columns for a vertical win
      if((line1.at(l) != ' ' && line1.at(l) == line2.at(l) && line1.at(l) == line3.at(l) && line1.at(l) == line4.at(l)) ||
         (line2.at(l) != ' ' && line2.at(l) == line3.at(l) && line2.at(l) == line4.at(l) && line2.at(l) == line5.at(l)) ||
         (line3.at(l) != ' ' && line3.at(l) == line4.at(l) && line3.at(l) == line5.at(l) && line3.at(l) == line6.at(l)))
         return true;    //return true if a win is detected
   }
   for(int a=1;a<8;a+=2){  //checks all diagnoly right win situations
      if((line1.at(a) != ' ' && line1.at(a) == line2.at(a+2) && line1.at(a) == line3.at(a+4) && line1.at(a) == line4.at(a+6)) ||
         (line2.at(a) != ' ' && line2.at(a) == line3.at(a+2) && line2.at(a) == line4.at(a+4) && line2.at(a) == line5.at(a+6)) ||
         (line3.at(a) != ' ' && line3.at(a) == line4.at(a+2) && line3.at(a) == line5.at(a+4) && line3.at(a) == line6.at(a+6)))
         return true;   //return true if a win is detected
   }
   for(int b=7;b<14;b+=2){//checks all diagnoly left win situations
      if((line1.at(b) != ' ' && line1.at(b) == line2.at(b-2) && line1.at(b) == line3.at(b-4) && line1.at(b) == line4.at(b-6)) ||
         (line2.at(b) != ' ' && line2.at(b) == line3.at(b-2) && line2.at(b) == line4.at(b-4) && line2.at(b) == line5.at(b-6)) ||
         (line3.at(b) != ' ' && line3.at(b) == line4.at(b-2) && line3.at(b) == line5.at(b-4) && line3.at(b) == line6.at(b-6)))
         return true;   //return true if a win is detected
   }

   return false;  //return false if a win isn't detected
}


void play(string player,char playerCoin){

   int playSpace;
   cout << "\n" << player << "'s turn (" << playerCoin << ")" << endl;
   cout << "Enter a space to play (1-7): ";
   cin >> playSpace;    //takes user input for playspace
   
   do{
      while(playSpace < 1 || playSpace > 7){ // check if playspace is out of bounds
         cout << "Not a valid space. Try again." << endl;
         cout << "Enter a space to play (1-7): ";
         cin >> playSpace;
      }
      
      int j = playSpace*2-1;
      if(updateBoard(j) == false){  //calls updateBoard, if the return is false then the column is full
         validPlay = false;
         cout << "Space already full.\nEnter another space to play (1-7): ";
         cin >> playSpace; //takes a new user input until the space entered is valid
      }  
      else
         validPlay = true;
   }while(!validPlay);  //do while loop to only take a valid playspace
   
}



int main(){ //main
   string winner;
   char winnerCoin;

   cout << "Enter player one's name: ";   //user input for player1 name
   cin >> player1;
   
   cout << "Enter player two's name: ";   //user input for player2 name
   cin >> player2;

   int i=1;
   while (!gameEnd && i<=42) //ends game when all spaces are filled or gameEnd = true
   {
      
      if(i%2 == 1){  //alternates player turns
         playerCoin = 'o'; 
         play(player1, playerCoin); //calls play function for the user to play their turn
      }
      else if(i%2 == 0){   //alternates player turns
         playerCoin = 'x';
         play(player2, playerCoin);
      }
      
      boardDisplay();   //calls function to dispalys board
      
      if(winDetected() == true)  //calls function to find if the game has been won yet
         gameEnd = true;
      
      i++;  //switches player turn and adds 1 to the total moves played
   }
   
   if(i%2 == 0 && gameEnd){   //assign winner if 'o' wins
      winner = player1;
      winnerCoin = 'o';
   }
   else if(i%2 == 1 && gameEnd){ ////assign winner if 'w' wins
      winner = player2;
      winnerCoin = 'x';
   }
   
   if(gameEnd) //outputs winner
      cout << "\nThe winner is " << winner << "! (" << winnerCoin << ")" << endl;
   else if(i==43) //if there was no win detected and all the spaces were used up, a draw is printed
      cout << "\nDraw." << endl;
      
   
   return 0;   //end of program
   
}