#ifndef _MOVE_H
#define _MOVE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <windows.h>
#include "player.h"

using namespace std;

void carmove()
{
	player obj;		// object of class player //
	srand(time(NULL));
	int A[] = {  10,200,350,510,650,800 };
	int B, C, D, E, F;	// for index //
	int b, c, d, e, f;		//for getting coordinate from array //
	float scr = 0.0; // to calculate score //
	sf::RenderWindow win(sf::VideoMode(930, 1200), "Road Rush", sf::Style::Titlebar | sf::Style::Close);
	win.setFramerateLimit(60);
	
	// two verterx named line1 and line 2 //
	sf::Vertex line1;
	sf::Vertex line2;

	// LINE POSITIONS //

	line1.position = sf::Vector2f(300, 0);
	line2.position = sf::Vector2f(600, 0);

	// line color //

	line1.color = sf::Color::Black;
	line2.color = sf::Color::Black;


	// array of vector so we can create a perfect line1 //
	sf::VertexArray line(sf::Lines, 2);
	line[0].position = sf::Vector2f(300, 1200);
	line[0].color = sf::Color::Black;
	line[1] = line1;
	 
	// for line 2 same as above // 
	sf::VertexArray linee(sf::Lines, 2);
	linee[0].position = sf::Vector2f(600, 1200);
	linee[0].color = sf::Color::Black;
	linee[1] = line2;

	// player car //
	sf::Texture car;
	car.loadFromFile("car.jpeg");
	sf::Sprite scar(car);
	scar.setPosition(sf::Vector2f(310, 1050));

	// genrate texture for enemy cars //

	sf::Texture ecar;
	sf::Texture ecar1;
	sf::Texture ecar2;
	sf::Texture ecar3;
	sf::Texture ecar4;

	// load cars from file //

	ecar.loadFromFile("car1.jpeg");
	ecar1.loadFromFile("car2.jpeg");
	ecar2.loadFromFile("car3.jpeg");
	ecar3.loadFromFile("car4.jpeg");
	ecar4.loadFromFile("car5.jpeg");

	// create sprits //

	sf::Sprite escar(ecar);
	sf::Sprite escar1(ecar1);
	sf::Sprite escar2(ecar2);
	sf::Sprite escar3(ecar3);
	sf::Sprite escar4(ecar4);
r:
	for (int i = 0; i < 1; i++)
	{
		B = rand() % 7;
		C = rand() % 7;
		D = rand() % 5;
		E = rand() % 4;
		F = rand() % 3;
		b = A[B+3];
		c = A[C+2];
		d = A[D+1];
		e = A[E-2];
		f = A[F-1];
		escar.setPosition(b, -120.f);
		escar1.setPosition(c, -120.f);
		escar2.setPosition(d, -120.f);
		escar3.setPosition(e, -120.f);
		escar4.setPosition(f, -120.f);

	}

	while (win.isOpen())
	{
		scr = scr + 0.1;
		sf::Vector2f p = escar.getPosition();
		sf::Vector2f p1 = escar1.getPosition();
		sf::Vector2f p2 = escar2.getPosition();
		sf::Vector2f p3 = escar3.getPosition();
		sf::Vector2f p4 = escar4.getPosition();
		sf::Event e;
		while (win.pollEvent(e))
		{
			if (e.type == e.Closed)
				win.close();
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			win.close();
		sf::Vector2f pos = scar.getPosition();		// to get current position of sprit //
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			scar.move(sf::Vector2f(-10.0f, 0.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			scar.move(sf::Vector2f(10.0f, 0.0f));
	
		// to keep it in left frame ///
		if (pos.x <= 10)
		{
			if (pos.y <= 10)
				pos.y = 10;
			if (pos.y >= 1050)
				pos.y = 1050;
			scar.setPosition(sf::Vector2f(10, pos.y));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				scar.move(sf::Vector2f(10.f, 0.0f));


		}
		// to keep in right framew //
		if (pos.x >= 820)
		{
			if (pos.y <= 10)
				pos.y = 10;
			if (pos.y >= 1050)
				pos.y = 1050;
			scar.setPosition(sf::Vector2f(820, pos.y));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				scar.move(sf::Vector2f(-10.0f, 0.0f));

		}

		escar.move(0.0f, 15.0f);
		escar1.move(0.0f, 20.0f);
		escar2.move(0.0f, 15.0f);
		escar3.move(0.0f, 20.0f);
		escar4.move(0.0f, 20.0f);
		if ((p.y > 1300 || p2.y > 1300) &&( p1.y > 1700   || p3.y > 1700 || p4.y > 1700))
		{
			goto r;

		}


		if ((pos.y <= p.y + 100 || pos.y + 100 <= p.y + 100) && ((pos.x <= p.x && pos.x + 50 >= p.x) || (pos.x >= p.x && pos.x <= p.x + 50)))
		{
			
			 win.close();
			 obj.write(scr);
			 std::cout << "\n\t\tYOUR FINAL SCORE : " << scr;
			 exit(0);
		}
		if ((pos.y <= p1.y + 100 || pos.y + 100 <= p1.y + 100) && ((pos.x <= p1.x && pos.x + 50 >= p1.x) || (pos.x >= p1.x && pos.x <= p1.x + 50)))
		{
			win.close();
			obj.write(scr);
			std::cout << "\n\t\tYOUR FINAL SCORE : " << scr;
			exit(0);
		}
		if ((pos.y <= p2.y + 100 || pos.y + 100 <= p2.y + 100) && ((pos.x <= p2.x && pos.x + 50 >= p2.x) || (pos.x >= p2.x && pos.x <= p2.x + 50)))
		{
			win.close();
			obj.write(scr);
			std::cout << "\n\t\tYOUR FINAL SCORE : " << scr;
			exit(0);
		}
		if ((pos.y <= p3.y + 100 || pos.y + 100 <= p3.y + 100) && ((pos.x <= p3.x && pos.x + 50 >= p3.x) || (pos.x >= p3.x && pos.x <= p3.x + 50)))
		{
			win.close();
			obj.write(scr);
			std::cout << "\n\t\tYOUR FINAL SCORE : " << scr;
			exit(0);
		}
		if ((pos.y <= p4.y + 100 || pos.y + 100 <= p4.y + 100) && ((pos.x <= p4.x && pos.x + 50 >= p4.x) || (pos.x >= p4.x && pos.x <= p4.x + 50)))
		{
			
			win.close();
			obj.write(scr);
			std::cout << "\n\t\tYOUR FINAL SCORE : " << scr;
			exit(0);
		}

		win.clear(sf::Color::White);
		
		win.draw(escar);
		win.draw(escar1);
		win.draw(escar2);
		win.draw(escar3);
		win.draw(escar4);

		win.draw(scar);
		win.draw(line);
		win.draw(linee);
		win.display();
	}
}



#endif
