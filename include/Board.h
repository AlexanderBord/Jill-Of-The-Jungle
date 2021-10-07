#pragma once

#include <SFML\Graphics.hpp>
#include <Vector>
#include <string>
#include <fstream> 
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <memory>
#include "StaticObject.h"
#include "Player.h"
#include "SpecialWall.h"
#include "Monster.h"
#include "Knife.h"
#include "NinjaStar.h"

using std::vector;
using std::ifstream;
using std::string;
using std::make_unique;

constexpr double POINTFIVE = 0.5;

// The Board class represents all objects that are drawn on the screen

class Board
{

public:

	//----Constructor for Board------
	Board() = default;
	Board(int level);
	

	void draw(sf::RenderWindow& win, float clock_sample);
	void set_object_null(sf::Vector2f place);
	void set_time(int elapsed);
	void openKeyGate();
	void CheckForCollision(Player& p);
	void CheckForMonsCollision(Player& p, vector<Knife>& m_knifes, vector<NinjaStar>& m_Nstars);
	void handleFloating(Player& p);
	void moveMonsters(sf::Vector2f playerLoc, float clock_sample);
	void drawMonsters(sf::RenderWindow& win, float clock_sample);
	void checkWeaponColission(vector<Knife>& m_knifes, vector<NinjaStar>& m_Nstars);
	void set_gift(int x, int y, char icon);

	int get_width();
	int get_time();
	int get_length();
	int get_keys();
	int get_diamonds();
	int get_levelTime();

	bool ObjectsCollided(Object& obj1, Object& obj2);
	bool isFloating(Player& p);
	bool isOnFloor(Player& p);
	bool isOnGround(Player& p);
	bool isClimbing(Player& p);
	bool isAboveLadder(Player& p);
	StaticObject* get_object(sf::Vector2f place); // returns a pointer to static objets for access purpuses

	sf::Vector2i get_player();


private:
	
	sf::Vector2i playerLoc;
	int m_fallSpeed;
	int m_time; // curent level time
	int m_level; // number of current level.
	int m_width;
	int m_length;
	int m_keys; // number of keys in current level
	int m_diamonds; // number of diamonds in current level
	int m_levelTime;


	vector <std::unique_ptr<Monster>> m_monster; //static objects vector.
	vector <string> m_file_vector; //vector of string.
	vector <vector <std::unique_ptr<StaticObject>>> m_board; //static objects vector.

	bool knifeColided;
	bool colided;
	void copy_to_file_vector(ifstream& file); // loads current file to memory
	void define_m_board(vector <string> m_file_vector);
	void make_m_board(); // creates the game board
	sf::Vector2i m_KeyGate; // saves door location to chage the picture when all keys are found
};

