#include <iostream>
#include <string>
#include <conio.h> //required for gechar keycode shenanigans
#include <chrono> //timer for jump
#include <time.h> //or this idk yet https://www.tutorialspoint.com/c_standard_library/time_h.htm
#include <windows.h>
using namespace std;


//


//############ KEY CODES ##############
#define KEY_UP 72 //or 224 72
#define KEY_DOWN 80 //or 224 80
#define KEY_LEFT 75 //or 224 75
#define KEY_RIGHT 77 //or 224 77
#define KEY_ENTER 13
//####### Allow getting input #########

void gravity(bool playerCurrentLayer[])
{

}

int main()
{
	//clock_t


	int key = 0; //current key pick with getch() ie c = getch() will make c = 72 if the up key is pressed

	bool playerCurrentLayer[3] = { 0,0,1 };
	bool destinationLayer[3] = { 0,0,0 };
	//################################## MAP ARRAYS ####################################################
	bool position[3][41] = {//where the player is currently
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//sky
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},//middle
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} };//ground
/*
	colission_Func(player.x, player, y)

		if(collision[player.y][player.x] == 1)
		{
			update_position()
		}
		*/

	bool collision[3][41] = { //grid of true tiles you can move into and false tiles you cannot
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//sky
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1},//middle
		{1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1} };//ground

	//###################################################################################################
	//Mobs VVV
	string player = "o";
	//mapVVVV
	string sky    = "                             __   |P|   ";
	string middle = "                          __ ||   |     ";
	string ground = "-^-----^---^--------------||-||---|-----";

	//cout << ground[1] = player << endl;
	cout << sky << endl << middle << endl << ground << endl; //prints empty map
	
	//arrows work
	while (1) {
		int left = GetAsyncKeyState(VK_LEFT);
		int right = GetAsyncKeyState(VK_RIGHT);
		int up = GetAsyncKeyState(VK_UP);
		int down = GetAsyncKeyState(VK_DOWN);

		cout << left << right << up << down << endl;
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

