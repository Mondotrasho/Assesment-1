
#include <iostream>
using namespace std;
const char* INDENT = "\t";
void reticule(int i)
{

 
	cout << "o" << endl; //player
	cout << "    V    V              V    " << endl; // ceiling spikes
	cout << " ^     ^   ^    ^  ^  ^     ^" << endl; // spikes
	cout << "------------------------------" << endl; //ground
	cout << "|" << endl;
	cout << INDENT << endl;
}