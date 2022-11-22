#ifndef _MENU_H
#define _MENU_H


#include <iostream>
#include "move.h"
#include "player.h"
void menu()
{
	player ob;
	int entr;
	system("cls");
	cout << "\n\n\t\t -: PLEASE CHOOSE FROM BELOW LIST :-  \n";
	cout << "\t\t   1 - PLAY : \n";
	cout << "\t\t   2 - HOW TO PLAY : \n";
	cout << "\t\t   3 - SCORES : \n";
	cout << "\t\t   4 - EXIT : \n";
	cout << "\t\t       -: ";
	cin >> entr;
	if (entr == 1)
	{
		system("cls");
		cout << " \n\n\t GAME WILL START SOON GET READY :";
		for (int i = 0; i <= 100; i+=4)
		{
			system("cls");
			cout << "\n\n\t\t";
			cout << i << " %";
			Sleep(10);
		}
		cout << "\n\n \t\t ";
		system("cls");
		carmove();
	}
	else if (entr == 2)
	{
		system("cls");
		cout << " \n\n\t\tTHE GAME IS INFINITY LONG UNTILL YOU CRASH YOUR CAR ";
		cout << "\n\n\t\t USE ARROW KEYS TO MOVE YOUR CAR AS PER YOUR NEED \n\n\t\t";

		system("pause");
		menu();

	}
	else if (entr == 3)
	{
		ob.read();
		cout << "\n\n";
		system("pause");
		menu();
	}
	else if (entr == 4)
	{
		system("cls");
		cout << "\n\n\t\t THANKS FOR USING OUR SOFTWARE \n\t\t  ";
		exit(0);
	}
	else
	{
		system("cls");

		cout << "WRONG CHOICE ";
		system("pause");
		menu();
	}




}

#endif
