#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <string>
#include <Windows.h>
#include <fstream>

/**********************************************************
# Program: PELMANISM Group 11.cpp
# Course: TCP1101 Programming Fundamentals
# Class: TT2V
# Trimester: 2120
# Year: 2021/22 Trimester 2
#
# Member_1: 1201303251 | Koo Wen Hao | 1201303251@student.mmu.edu.my | 016 772 1571 //group leader
# Member_2: 1201100744 | Chew Xu | 1201100744@student.mmu.edu.my |  016 613 7604
# Member_3: 1201102372 | Rahmani Erfan | 1201102372@student.mmu.edu.my | 018 312 0426
# **********************************************************/

using namespace std;

int main();
void Mainmenu();

//file variable
fstream history; //Game history file variable

int menuchoice; //The choice taken after menu is given

class Playername
{
public:
	string player1name;
	string player2name;
};
Playername names;




//for the turns
int p1ans1 = 0; //The first position of the deck picked by player 1.
int p1ans2 = 0;
int p2ans1 = 0;
int p2ans2 = 0;

int p1answer1; //The VALUE in the position of the deck picked by player 1.
int p1answer2;
int p2answer1;
int p2answer2;

//player related
int player1score = 0;
int player2score = 0;

//deck
char intToChar[2]; //Deck that contains the integer that was converted to character (THE DISPLAY DECK IS A CHARACTER DECK, SO it cannot have integers)
char displaydeck[8] = { '*', '*', '*', '*', '*', '*', '*', '*' }; //deck used to show only, does not effect the actual deck.
int Newdeck[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int Arrsize = 0;
int NUMB1 = 0;
int NUMB2 = 0;
int NUMB3 = 0;
int NUMB4 = 0;



void savescore() { //Save the score at the end of the game
	history.open("GameHistory.txt", ios::app); //append mode
	if (history.is_open()) {
		if (player1score > player2score)
		{
			history << names.player1name << " " << "VS" << " " << names.player2name << " " << "(" << player1score << " - " << player2score << ")" << "  " << "Winner: " << names.player1name << endl;
		}
		else if (player2score > player1score)
		{
			history << names.player2name << " " << "VS" << " " << names.player1name << " " << "(" << player2score << " - " << player1score << ")" << " " << "Winner: " << names.player2name << endl;
		}
		else if (player1score == player2score)
		{
			history << names.player2name << " " << "VS" << " " << names.player1name << " " << "(" << player2score << " - " << player1score << ")" << " " << "Draw" << endl;
		}
		history.close();
	}
}


//rules
void howtoplay() {
	cout << "This is a two player memory game called Pelmanism." << endl;
	Sleep(2000);
	cout << "A deck of eight cards with cards 1, 2, 3 and 4 exist. Each card comes in a pair." << endl;
	Sleep(3000);
	cout << "In the beginning of the game, the deck is shuffled and then shown to the players for TWO seconds" << endl;
	Sleep(4000);
	cout << "Each player gets 2 tries per turn. If both of the cards have the same number, the player gets ONE point and another turn." << endl;
	Sleep(4000);
	cout << "Player with highest points wins." << endl;
	Sleep(2000);
	system("CLS");
	Mainmenu();
}

//Show past games
void Gamehistory() {
	int back; //back to the mainmenu
	history.open("GameHistory.txt", ios::in); //read mode
	if (history.is_open())
	{
		string line;
		while (getline(history, line))
		{
			cout << line << endl;
		}
		history.close();
	}
	cout << endl << "Input 1 to go back" << endl;
	cout << endl << "Input: ";
	cin >> back;
	while (back != 1)
	{
		cout << "Input invalid." << endl;
		cout << endl << "Input: ";
		cin >> back;
	}
	system("CLS");
	Mainmenu();
}

//Show score at the end of the game
void releasescore(int player1score, int player2score) {
	cout << names.player1name << "'s score: " << player1score << endl << names.player2name << "'s score: " << player2score << endl;
	if (player1score < player2score)
	{
		cout << names.player2name << " " << "won!!";
	}
	else if (player1score > player2score)
	{
		cout << names.player1name << " " << "won!!";
	}
	else if (player1score == player2score)
	{
		cout << "Its a draw!";
	}
}

//menu
void Mainmenu() {
	int choice;
	cout << "Welcome." << endl;
	cout << "1. Start" << endl;
	cout << "2. How to play" << endl;
	cout << "3. Game history" << endl;
	cout << "4. Exit" << endl;
	cin >> choice;
	system("CLS");

	if (choice == 1)
	{
	}

	else if (choice == 2)
	{
		howtoplay();
	}

	else if (choice == 3)
	{
		Gamehistory();
	}

	else if (choice == 4)
	{
		exit(0);
	}
}

int main() {
	cout << "Player 1 name: ";
	cin >> names.player1name;
	cout << "VS" << endl;
	cout << "Player 2 name: ";
	cin >> names.player2name;
	system("CLS");
	Mainmenu();
	system("CLS");



	//Shuffle feature:
	srand(time(0)); //Seed for random number
	while (Arrsize <= 7)
	{
		int random = rand() % 5; //gets a number between 0 and 4 (0 wont be added to deck) //

		if (random == 1)
		{
			NUMB1 += 1; //keeps track of how many number 1's there are ( CANT HAVE MORE THAN 2)
			if (NUMB1 <= 2)
			{
				Newdeck[Arrsize] = 1; //add the number to the deck
				Arrsize += 1; //keeps track of array size (cant have more than 8) 
			}
		}
		if (random == 2)
		{
			NUMB2 += 1; //keeps track of how many number 2's there are ( CANT HAVE MORE THAN 2)
			if (NUMB2 <= 2)
			{
				Newdeck[Arrsize] = 2;
				Arrsize += 1;
			}
		}
		if (random == 3)
		{
			NUMB3 += 1; //keeps track of how many number 3's there are ( CANT HAVE MORE THAN 2)
			if (NUMB3 <= 2)
			{
				Newdeck[Arrsize] = 3;
				Arrsize += 1;
			}
		}
		if (random == 4)
		{
			NUMB4 += 1; //keeps track of how many number 3's there are ( CANT HAVE MORE THAN 2)
			if (NUMB4 <= 2)
			{
				Newdeck[Arrsize] = 4;
				Arrsize += 1;
			}
		}
	}

	for (int i = 0; i < 8; i++)
	{
		cout << Newdeck[i] << " ";
	} //printing the deck

	Sleep(2000);
	system("CLS");

	//Cotinues the game until ALL positions (1-8) are all empty ("-" meaning they are empty)
	while (displaydeck[0] || '-' && displaydeck[1] != '-' || displaydeck[2] != '-' || displaydeck[3] == '-' || displaydeck[4] == '-' || displaydeck[5] == '-' || displaydeck[6] == '-' || displaydeck[7] == '-')
	{

		p1ans1 = 0;
		p1ans2 = 0;
		//player 1's first turn
		while (p1ans1 == p1ans2) {
			p1ans1 = 0;
			p2ans2 = 0;
			//Checking if deck is empty before asking for answer
			if (displaydeck[0] == '-' && displaydeck[1] == '-' && displaydeck[2] == '-' && displaydeck[3] == '-' && displaydeck[4] == '-' && displaydeck[5] == '-' && displaydeck[6] == '-' && displaydeck[7] == '-') {
				releasescore(player1score, player2score);
				for (int i = 0; i < 8; i++) {//resetting the deck
					displaydeck[i] = '*';
				}
				savescore();
				player1score = 0;
				player2score = 0;
				Arrsize = 0;
				NUMB1 = 0;
				NUMB2 = 0;
				NUMB3 = 0;
				NUMB4 = 0;
				Sleep(4000);
				system("CLS");
				main();
			}


			cout << names.player1name << ", please input the position of the card you would like to pick: " << endl;

			for (int i = 0; i < 8; i++)
			{
				cout << displaydeck[i] << " "; //show displaydeck
			}
			cout << endl << "Input: ";
			cin >> p1answer1; //first answer from player 1. p1 = player1 answer1= first answer

			while (displaydeck[p1answer1 - 1] == '-')
			{
				cout << "Invalid input." << endl << endl;
				cout << "Input: ";
				cin >> p1answer1;
			}

			cout << endl;
			p1ans1 = Newdeck[p1answer1 - 1];  /*the value in the picked position*/

			if (p1ans1 == 1)
			{
				intToChar[0] = '1';
			}

			else if (p1ans1 == 2)
			{
				intToChar[0] = '2';
			}

			else if (p1ans1 == 3)
			{
				intToChar[0] = '3';
			}

			else if (p1ans1 == 4)
			{
				intToChar[0] = '4';
			}

			displaydeck[p1answer1 - 1] = intToChar[0];

			for (int i = 0; i < 8; i++)
			{
				cout << displaydeck[i] << " ";
			}
			cout << endl;

			//player 1's second turn
			cout << "Input: ";
			cin >> p1answer2;

			while (displaydeck[p1answer2 - 1] == '-')
			{
				cout << "Invalid input." << endl << endl;
				cout << "Input: ";
				cin >> p1answer2;
			}

			cout << endl;
			p1ans2 = Newdeck[p1answer2 - 1];  /*the value in the picked position*/

			if (p1ans2 == 1)
			{
				intToChar[0] = '1';
			}

			else if (p1ans2 == 2)
			{
				intToChar[0] = '2';
			}

			else if (p1ans2 == 3)
			{
				intToChar[0] = '3';
			}

			else if (p1ans2 == 4)
			{
				intToChar[0] = '4';
			}

			displaydeck[p1answer2 - 1] = intToChar[0];

			for (int i = 0; i < 8; i++)
			{
				cout << displaydeck[i] << " "; //output displaydeck
			}
			cout << endl;

			if (p1ans1 == p1ans2) //check if answers are the same
			{
				cout << "Nice! You got one point!" << endl;
				displaydeck[p1answer1 - 1] = '-';
				displaydeck[p1answer2 - 1] = '-';
				player1score++;
				Sleep(2000);
				system("CLS");
			}
			else
			{
				cout << "Not the same card!" << endl << endl;
				displaydeck[p1answer1 - 1] = '*';
				displaydeck[p1answer2 - 1] = '*';
				Sleep(2000);
				system("CLS");
			}
		}


		//player 2's first turn
		while (p2ans1 == p2ans2) {
			p2ans1 = 0;
			p2ans2 = 0;
			//checking if deck is empty

			if (displaydeck[0] == '-' && displaydeck[1] == '-' && displaydeck[2] == '-' && displaydeck[3] == '-' && displaydeck[4] == '-' && displaydeck[5] == '-' && displaydeck[6] == '-' && displaydeck[7] == '-') {
				releasescore(player1score, player2score);
				for (int i = 0; i < 8; i++) { //resetting the deck
					displaydeck[i] = '*';
				}
				savescore(); //saving
				player1score = 0; //resetting scores after saving
				player2score = 0;
				Arrsize = 0; //for shuffling
				NUMB1 = 0;
				NUMB2 = 0;
				NUMB3 = 0;
				NUMB4 = 0;
				Sleep(4000);
				system("CLS");
				main();
			}

			cout << names.player2name << ", please input the position of the card you would like to pick: " << endl;

			for (int i = 0; i < 8; i++)
			{
				cout << displaydeck[i] << " ";
			}
			cout << endl;

			cout << "Input: ";
			cin >> p2answer1;

			while (displaydeck[p2answer1 - 1] == '-')
			{
				cout << "Invalid input." << endl << endl;
				cout << "Input: ";
				cin >> p2answer1;
			}

			cout << endl;
			p2ans1 = Newdeck[p2answer1 - 1];  /*the value in the picked position*/

			if (p2ans1 == 1)
			{
				intToChar[0] = '1';
			}

			else if (p2ans1 == 2)
			{
				intToChar[0] = '2';
			}

			else if (p2ans1 == 3)
			{
				intToChar[0] = '3';
			}

			else if (p2ans1 == 4)
			{
				intToChar[0] = '4';
			}

			displaydeck[p2answer1 - 1] = intToChar[0];

			for (int i = 0; i < 8; i++)
			{
				cout << displaydeck[i] << " ";
			}
			cout << endl;

			//player 2's second turn
			cout << "Input: ";
			cin >> p2answer2;

			while (displaydeck[p2answer2 - 1] == '-')
			{
				cout << "Invalid input." << endl << endl;
				cout << "Input: ";
				cin >> p2answer2;
			}

			cout << endl;
			p2ans2 = Newdeck[p2answer2 - 1];  /*the value in the picked position*/

			if (p2ans2 == 1)
			{
				intToChar[0] = '1';
			}

			else if (p2ans2 == 2)
			{
				intToChar[0] = '2';
			}

			else if (p2ans2 == 3)
			{
				intToChar[0] = '3';
			}

			else if (p2ans1 == 4)
			{
				intToChar[0] = '4';
			}

			displaydeck[p2answer2 - 1] = intToChar[0];

			for (int i = 0; i < 8; i++)
			{
				cout << displaydeck[i] << " ";
			}
			cout << endl;

			if (p2ans1 == p2ans2)
			{
				cout << "Nice! You got one point!" << endl;
				displaydeck[p2answer1 - 1] = '-';
				displaydeck[p2answer2 - 1] = '-';
				player2score++;
			}
			else
			{
				cout << "Not the same card!" << endl << endl;
				displaydeck[p2answer1 - 1] = '*';
				displaydeck[p2answer2 - 1] = '*';
			}
			Sleep(2000);
			system("CLS");
		}
	}
	return 0;

}
