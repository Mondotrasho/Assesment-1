#include <iostream>
#include <string>
#include <conio.h> //required for gechar keycode shenanigans
#include <chrono> //timer for jump
#include <time.h> //or this idk yet https://www.tutorialspoint.com/c_standard_library/time_h.htm
#include <windows.h>
using namespace std;

void gravity(bool playerCurrentLayer[])
{

}


int main()
{
	//Mobs VVV
	string player = "o";
	//mapVVVV
	string sky    = "                             __   |P|   ";
	string middle = "                          __ ||   |     ";
	string ground = "-^-----^---^--------------||-||---|-----";

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