//
//  main.cpp
//  TICTAC
//  C++ console application
//  Created by Timothy Dooris on 4/11/13.
//  Copyright (c) 2013 Timothy Dooris. All rights reserved.
//  Everyone knows how to play.

#include <iostream>
#include <string>

using namespace std;

string player1, player2;
char theBoard[9];
bool playAgain = true;
char decision;
void displayBoard();
bool isTheGameOver = false;
int whoseTurn = 1;
int chosenSpace;
bool available(int chosenSpace);                                        //checks if that space is available
void markBoard(int chosenSpace, int whoseTurn);                         //mark space on board
int checkForWin(int whoseTurn);                      //return 1 or 2 if player1 or player2 has won, 3 for draw, otherwise 0

int main(int argc, const char * argv[])
{

    
    while(playAgain){
        
        for (int i = 0; i<9; i++)                       //reset the board
            theBoard[i] = '1'+i;
        
            isTheGameOver = false;
        do{
            
                        
            
            do{                                             //Will keep asking for a choice if choice is invalid.
                displayBoard();
                cout<<"Player "<< whoseTurn<< " please make your selection."<<endl;
                cin>>chosenSpace;
            }
            while(!available(chosenSpace));
            
            markBoard(chosenSpace, whoseTurn);
            if(checkForWin(whoseTurn) == 1 || checkForWin(whoseTurn)== 2)                            //Check to see if someone has won
            {
                cout<<"Player " << whoseTurn << " has won the game!"<<endl;
                isTheGameOver = true;
            }
            else if (checkForWin(whoseTurn== 3)){
                cout<<"The game is a draw."<<endl;
                isTheGameOver = true;
            }
                            
            
            
            if(whoseTurn == 1)                                              //Switch whose turn it is
                whoseTurn++;
            else
                whoseTurn--;
            
            
        }while(isTheGameOver == false);
        
        do{
            cout<<"Would you like to play again? (y/n)";
            cin >> decision;
        }
        while((decision != 'y') && (decision !='n') );
        
        if(decision == 'n')
            playAgain = false;
    
    }
   
    cout<<"\nThanks for playing!"<<endl;
}

void displayBoard(){
    cout<<theBoard[0]<<" | "<<theBoard[1]<<" | "<< theBoard[2]<<endl;
    cout<<theBoard[3]<<" | "<<theBoard[4]<<" | "<< theBoard[5]<<endl;
    cout<<theBoard[6]<<" | "<<theBoard[7]<<" | "<< theBoard[8]<<endl;
    
    
}

void markBoard(int chosenSpace, int whoseTurn){
    
    char playerMarker = 'X';
    if(whoseTurn == 2)
        playerMarker = 'O';
    
    theBoard[chosenSpace-1] = playerMarker;
    
    
}

int checkForWin(int whoseTurn){


        
    if(theBoard[0]==theBoard[1] && theBoard[1]==theBoard[2])
        return whoseTurn;
    else if (theBoard[0]==theBoard[4] && theBoard[4] ==theBoard[8])
        return whoseTurn;
    else if (theBoard[0]==theBoard[3] && theBoard[3]==theBoard[6])
        return whoseTurn;
    else if (theBoard[3]==theBoard[4] && theBoard[4]==theBoard[5])
        return whoseTurn;
    else if (theBoard[6]==theBoard[7] && theBoard[7]==theBoard[8])
        return whoseTurn;
    else if (theBoard[1]==theBoard[4] && theBoard[4]==theBoard[7])
        return whoseTurn;
    else if (theBoard[2]==theBoard[5] && theBoard[5]==theBoard[8])
        return whoseTurn;
    else if (theBoard[2]==theBoard[4] && theBoard[4]==theBoard[6])
        return whoseTurn;
    else if ((theBoard[0] == 'X' || theBoard[0]== 'O') &&
             (theBoard[1] == 'X' || theBoard[1]== 'O') &&
             (theBoard[2] == 'X' || theBoard[2]== 'O') &&
             (theBoard[3] == 'X' || theBoard[3]== 'O') &&
             (theBoard[4] == 'X' || theBoard[4]== 'O') &&
             (theBoard[5] == 'X' || theBoard[5]== 'O') &&
             (theBoard[6] == 'X' || theBoard[6]== 'O') &&
             (theBoard[7] == 'X' || theBoard[7]== 'O') &&
             (theBoard[8] == 'X' || theBoard[8]== 'O') )
        return 3;
    else
        return 0;
    
    
}

bool available(int chosenSpace){
    if(theBoard[chosenSpace-1] == 'X' || theBoard[chosenSpace-1] == 'O')
        return false;
    else
        return true;
}