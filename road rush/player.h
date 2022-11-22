#ifndef _PLAYER_H
#define _PLAYER_H


#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>


using namespace std;

// function definations are in player.cpp file /
// file used to save player data  - player.dat //

class player
{
	string name;
	string country;
	string age;
public:
	float score;
	void input();
	void output();
	void read();
	void write(float s);
};

/////////////////////////////////////////////
//                                         //
//  function for input and write in file   //
//                                         //
/////////////////////////////////////////////

void player::input()
{
	system("cls");
	cout << "\n\n\t\t Enter name : ";
	cin >> name;
	cout << "\n\t\t Enter country : ";
	cin >> country;
	cout << "\n\t\t Enter age : ";
	cin >> age;
}

// write all player data in file - player.dat //

void player::write(float s)
{
	system("cls");
	player p;
	ofstream file;
	file.open("player.dat", ios::out | ios::app | ios::binary);
	p.input();
	p.score = s;
	file.write((char*)&p, sizeof(p));
	file.close();

}


/////////////////////////////////////////////
//                                         //
// functions to output or read player data //
//                                         //
/////////////////////////////////////////////

void player::output()
{

	cout << "\n " << name << " \t " << country << " \t\t" << age << "   \t 	" << score;
}

void player::read()
{
	system("cls");
	player p;
	ifstream file;
	file.open("player.dat", ios::in | ios::binary);
	cout << "/////////////////////////////////////////////////////\n";
	cout << "/  NAME \t COUNTRY \t AGE  \t   SCORE   /\n";
	cout << "////////////////////////////////////////////////////\n";
	while (file.read((char*)&p, sizeof(p)))
	{
		p.output();
	}
	file.close();
}




#endif