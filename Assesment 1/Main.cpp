#include <iostream>
#include <string>
#include <conio.h> //required for gechar keycode shenanigans
#include <chrono> //timer for jump
#include <time.h> //or this idk yet https://www.tutorialspoint.com/c_standard_library/time_h.htm
#include <windows.h>
using namespace std;
class Player
{
public:
	int x, y;
	void m_Player(int newx, int newy) //Moves player Takes new X and Y and Clamps within range
	{
		int Xmax = 41;
		int Xmin = -1;
		int Ymax = 3;
		int Ymin = -1;

		x = newx;
		if (x >= Xmax) { x = Xmax - 1; }
		if (x <= Xmin) { x = Xmin + 1; }
		y = newy;
		if (y >= Ymax) { y = Ymax - 1; }
		if (y <= Ymin) { y = Ymin - 1; }
	};
};
class Map
{
public:
	bool collision[3][41] = { //grid of true tiles you can move into and false tiles you cannot
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//sky
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },//middle
		{ 1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1 } };//ground
	bool location_check(int Potential_x, int Potential_y) //checks if a move is valid by taking in a potential new X and Y Coordinate and checking the Map array
	{
		if (collision[Potential_y][Potential_x] == true) //WATCH ORDER OF XY
		{
			return true;
		}
		else { return false; }
	};
};
void gravity(bool playerCurrentLayer[])
{

}

int main()
{

	//Mobs VVV
	string player_char = "o";
	//mapVVVV
	string sky = "                             __   |P|   ";
	string middle = "                          __ ||   |     ";
	string ground = "-^-----^---^--------------||-||---|-----";

	Map world;
	Player player;
	player.x = 4; //starting x
	player.y = 2; //starting y		Add default constructor in final

	while (true)
	{
		//sets the int to GetAsyncKeyState for each key ##NOTE## Aparently what it outputs is a short where 
		//the binary sets the first bit to 1 so in binary it is 1000 0000 0000 0000 but when I convert it to in its -3k or so
		int left = GetAsyncKeyState(VK_LEFT);
		int right = GetAsyncKeyState(VK_RIGHT);
		int up = GetAsyncKeyState(VK_UP);
		int down = GetAsyncKeyState(VK_DOWN);

		//use if statements to filter for potential key presses
		if (left != 0)
		{
			bool maymove = world.location_check((player.x - 1), player.y); //calls may move function
			if (maymove == true)											   //if you can move
			{
				player.m_Player((player.x - 1), player.y);				   //send new x and y cords to plays Move player function 
			}															   //##NOT CHANGING VALUES DIRECTLY AS THAT MIGHT CAUSE FUCK UPS DOWN THE LINE##
		}
		else if (right != 0)
		{
			bool maymove = world.location_check((player.x + 1), player.y);
			if (maymove == true)
			{
				player.m_Player((player.x + 1), player.y);
			}
		}
		else if (up != 0)
		{
			bool maymove = world.location_check(player.x, (player.y - 1));
			if (maymove == true)
			{
				player.m_Player(player.x, (player.y - 1));
			}
		}
		else if (down != 0)
		{
			bool maymove = world.location_check(player.x, (player.y + 1));
			if (maymove == true)
			{
				player.m_Player(player.x, (player.y + 1));
			}

		}
		cout << player.x << "-" << player.y << endl; //to debug key presses
	}
	//cout << ground[1] = player << endl;
	cout << sky << endl << middle << endl << ground << endl; //prints empty map
	
	//arrows work
	system("pause");
	return 0;
}

/*
int main()
{
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::duration<float, std::milli> duration;

	auto start = Time::now();

	float timer = 0;

	while (true)
	{
		auto end = Time::now();

		duration elapsed = end - start;

		float delta = elapsed.count() / 1000.0f;

		start = Time::now();

		int fps = (int)(1.0f / delta);
		// GAME LOGIC
		timer += delta;



		for (int i = 0; i < 1; i++);

		std::cout.clear();
		std::cout << fps << "\n";


	}


	return 0;

	*/