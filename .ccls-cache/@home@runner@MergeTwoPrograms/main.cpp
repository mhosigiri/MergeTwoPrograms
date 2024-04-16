/*

Anish KC
Luis Soto
COSC 1437 58002
Dr. T
Replit

    Sinking Ship Grame source: 
  http://pastebin.com/atfSSUef

  //Expanded by Dr. Tyson McMillan on 4-5-2014,10-24-2015
  //Expanded by: Type Teamates Names
  //Date
  //Big Show Hint on Line 104

  Objective:
  1) Make this game more fun, visual (color), and validate input of the two integers. 
  2) In a mult-line comment below the program, state how this program works. 
  3) Expand upon the ways that you improved the game. 
  4 How does the 10 by 10 matrix work
  5) How does one attack a ship in the 10 by 10 matrix? That is what characters represent what? 
*/
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>  
#include <cstdlib>
using namespace std;

string red = "\033[0;31m";
string green = "\033[0;32m";
string blue = "\033[0;34m";
string yellow = "\033[0;33m";
string reset = "\033[0m";
//http://www.cppforschool.com/project/tic-tac-toe-project.html
char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
int checkwin();
void board();

const int rows = 10;
const int elements = 10;

int maxships = 50;

int matrix[rows][elements];

void Clear()
{
  for(int i=0; i < rows; i++)
  {
    for(int j=0; j < elements; j++)
    {
      matrix[i][j] = 0;
    }
  }
}

void Show()
{
  for(int i=0; i < rows; i++)
  {
    for(int j=0; j < elements; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

int NumberOfShips()
{
  int c = 0;

  for(int i=0; i < rows; i++)
  {
    for(int j=0; j < elements; j++)
    {
      if(matrix[i][j] == 1)
        c++;
    }
  }

  return c;
}

void SetShips()
{
  int s = 0;
  while(s < maxships)
  {
    int x = rand() % rows;
    int y = rand() % elements;
    if(matrix[x][y] != 1)
    {
      s++;
      matrix[x][y] = 1;
    }
  }
}

bool Attack(int x,int y)
{
  if(matrix[x][y] == 1)
  {
    matrix[x][y] = 2;
    return true;
  }
  return false;
}

int main()
{
  char option = ' ';
  srand(time(NULL));
  Clear();
  SetShips();
  int pos1,pos2;
  char prompt;
  int player = 1,i,choice;
  char mark;


  cout << "Menu\n";
  cout << "1. Play Sinking Ship\n";
  cout << "2. Play Tic Tac Toe\n";
  cout << "3. Exit\n";
  cin >> option;
  do
    {
      if(option == '1'){
         while(1)
          {
            //Show the Board
          //	Show(); 

            cout << yellow << "Please input location (x [space] y): "; 
            cin >> pos1 >> pos2;
            cout << reset;

            if(Attack(pos1,pos2))
              cout << green << "You got me! :)" << reset << endl;
            else
              cout << red << "Sorry no ship at that position!" << endl;
            cout << green << "Number of ships left: " << reset << blue << NumberOfShips() << endl;
            cout << "Do you want to surrender (y/n)? "; cin >> prompt;
            if(prompt == 'y')
              break;
          }
          cout << red << "Game over!" << blue << endl;
          Show();
      }
      else if(option == '2'){
         do
          {
            board();
            player=(player%2)?1:2;
            cout << "Player " << player << ", enter a number:  ";
            cin >> choice;
            mark=(player == 1) ? 'X' : 'O';
            if (choice == 1 && square[1] == '1')
              square[1] = mark;
            else if (choice == 2 && square[2] == '2')
              square[2] = mark;
            else if (choice == 3 && square[3] == '3')
              square[3] = mark;
            else if (choice == 4 && square[4] == '4')
              square[4] = mark;
            else if (choice == 5 && square[5] == '5')
              square[5] = mark;
            else if (choice == 6 && square[6] == '6')
              square[6] = mark;
            else if (choice == 7 && square[7] == '7')
              square[7] = mark;
            else if (choice == 8 && square[8] == '8')
              square[8] = mark;
            else if (choice == 9 && square[9] == '9')
              square[9] = mark;
            else
            {
              cout<<"Invalid move ";
              player--;

            }
            i=checkwin();
            player++;
            cout << "\033[2J\033[1;1H";
          }while(i==-1);
          board();
          if(i==1)
            cout<<"==>\aPlayer "<<--player<<" win ";
          else
            cout<<"==>\aGame draw";
      } else if(option == '3'){
        cout << "Thank you for playing!\n";
      }
    }while(option != '3');

  return 0;
}


/*********************************************
  FUNCTION TO RETURN GAME STATUS
  1 FOR GAME IS OVER WITH RESULT
  -1 FOR GAME IS IN PROGRESS
  O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
  if (square[1] == square[2] && square[2] == square[3])
    return 1;
  else if (square[4] == square[5] && square[5] == square[6])
    return 1;
  else if (square[7] == square[8] && square[8] == square[9])
    return 1;
  else if (square[1] == square[4] && square[4] == square[7])
    return 1;
  else if (square[2] == square[5] && square[5] == square[8])
    return 1;
  else if (square[3] == square[6] && square[6] == square[9])
    return 1;
  else if (square[1] == square[5] && square[5] == square[9])
    return 1;
  else if (square[3] == square[5] && square[5] == square[7])
    return 1;
  else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
           square[4] != '4' && square[5] != '5' && square[6] != '6' &&
            square[7] != '7' && square[8] != '8' && square[9] != '9')
    return 0;
  else
    return -1;
}


/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{

  cout << "\n\n\tTic Tac Toe\n\n";
  cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
  cout << endl;
  cout << "     |     |     " << endl;
  cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
  cout << "     |     |     " << endl << endl;
}

/*******************************************************************
        END OF PROJECT
********************************************************************/

/*
The program allows user to track down 10 ships that are at random positions in a 10 by 10 matrix. The user is prompted to enter the location of the ships. If the user enters the correct location, the ship gets sunk. The number of ships left is displayed which is reduced by one. The user is prompted to surrender or continue playing. If the user surrenders, the game ends. The program displays the map of the matrix after the user surrenders.

10 by 10 matrix works by having the user enter the location of the ships. The program checks if the location is correct or not. If the location is correct, the ship gets sunk. If the location is incorrect, the user is prompted to enter another value or surrender. The program displays the number of ships left. If the user surrenders, the game ends.

The user attacks the ships by entering the location of the ships. If the location is correct, the ship gets sunk. And the number changes from 1 to 2. If the location is incorrect, the user is prompted to enter another value or surrender. 
*/