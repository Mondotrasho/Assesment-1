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
	string vis = "o";
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
	bool gravity(bool below, float timer)
	{
		if (below == true)
		{
			if (timer >= 1.0f)
			{
				if (y >= 0) {
					switch (y)
					{
					case 0: y = 1; //top air
						return 1;
						break;
					case 1: y = 2; //mid air
						return 1;
						break;
					case 2: y = 2; //ground
						return 1;
						break;
					}
				}
			}
		}
		return 0;
	}
};

class Map
{
public:

	int map_length = 41;
	int map_height = 3;

	

	bool collision[3][41] = { //grid of true tiles you can move into and false tiles you cannot
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },//sky
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1 },//middle
		{ 1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1 } };//ground

	string vis[3][41] = {
		{ " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","_","_"," "," ","|","P","|"," "," "," "," "," "},//sky
		{ " "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","_","_"," ","|","|"," "," "," "," ","|"," "," "," "," "," "},//middle
		{ " ","^"," "," "," "," "," ","^"," "," "," ","^"," "," "," "," "," "," "," "," "," "," "," "," "," "," ","|","|"," ","|","|"," "," "," "," ","|"," "," "," "," "," "} };//ground

	bool below(int y, int x)
	{//weird order on input WATCH OUT
		int temp = y + 1; //opersite WATCH
		return collision[temp][x];
	}

	void print(int x,int y)
	{
		for(int i = 0; i < map_height; i++)
		{
			for(int j = 0; j < map_length;j++)
			{
				if (x == j)
				{
					if (y ==i) {
						cout << "o";
					}
					else
					{
						cout << vis[i][j];
					}
					}
				else
				{
					cout << vis[i][j];
				}
			}
			cout << endl;
		}
	}

	bool location_check(int Potential_x, int Potential_y) //checks if a move is valid by taking in a potential new X and Y Coordinate and checking the Map array
	{
		if (collision[Potential_y][Potential_x] == true) //WATCH ORDER OF XY
		{
			return true;
		}
		else { return false; }
	};
};


int main()
{
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::duration<float, std::milli> duration;

	auto start = Time::now(); //Start time

	float timer = 0;		  //this is where we store time

	duration start_jump;
	duration end_jump;

	bool jump_true = 0;
	Map world;
	Player player;
	player.x = 27; //starting x
	player.y = 1; //starting y		Add default constructor in final

	while (true)
	{
		auto end = Time::now(); //reads time now

		duration elapsed = end - start; //how long has passed between start and end

		float delta = elapsed.count() / 1000.0f; //calls this function and converts it down to a nice size

		start = Time::now();					//start timer

		int fps = (int)(1.0f / delta);			//frames per second
		// GAME LOGIC

		system("cls");
		world.print(player.x, player.y);
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
				jump_true = 1;
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
		
		if(jump_true == 1)
		{
			start_jump = Time::now();

		}
		bool reset_timer = player.gravity(world.below(player.y, player.x), timer);

		timer += delta;
		if (reset_timer == 1)
		{
			timer = 0.f;
			reset_timer = 0;
		}
		std::cout << timer << "\n";
		std::cout << player.x << " X and " << player.y <<" Y "<< "\n";

		std::cout << fps << "\n";
		//cout << player.x << "-" << player.y << endl; //to debug key presses
	}
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