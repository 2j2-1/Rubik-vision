// Rubikcubevison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int colors_to_cube(char * cubeColors) {
	int cube[6][9];
	int pairs[][3] = {
	{ 1,10,39 },{ 2,38 },{ 3,21,28 },{ 4,11 },{},{ 6,20 },{ 7,12,19 },{ 8,29 },{ 9,28,21 },
	{10,1,39},{ 11,3 },{12,7,19},{ 13,42 },{},{ 15,22 },{16,45,52},{ 17,49 },{18,25,46},
	{19,7,12},{ 20,8 },{21,9,28},{ 22,15 },{},{ 24,31 },{25,18,46},{ 26,47 },{27,34,48},
	{28,9,21},{ 29,6 },{30,3,37},{ 31,24 },{},{ 33,40 },{34,48,27},{ 35,51 },{36,43,54},
	{37,3,30},{ 38,2 },{39,1,10},{ 40,33 },{},{ 42,13 },{43,36,54},{ 44,53 },{45,16,52},
	{46,18,25},{ 47,26 },{48,27,34},{ 49,17 },{},{ 51,35 },{52,16,45},{ 53,44 },{54,36,43},
	};
	int realtions[][6] = { { 0,  4,  6,  8,  2,  0 },
	{ 11, 0, 15,  0, 13, 17 },
	{ 20, 22, 8, 24,  8, 26 },
	{ 29, 0, 31, 35, 33, 35 },
	{ 38,42,0,40,0,44 },
	{ 51,49,47,51,53,0 } };
	int tripleRealtions[][6][6] = {
	{ { 0,0,0,0,0 },{ 0,0,7,0,1 },{ 0,0,0,3,0 },{ 0,0,9,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },
	{ { 0,0,12,0,10 },{ 0,0,0,0,0,0 },{ 0,0,0,0,0,18 },{ 0,0,0,0,0 },{ 0,0,0,0,0,16 },{ 0,0,0,0,0,0 } },
	{ { 0,19,0,21,0 },{ 0,0,0,0,0,25 },{ 0,0,0,0,0 },{ 0,0,0,0,0,27 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },
	{ { 0,0,28,0,30 },{ 0,0,0,0,0 },{ 0,0,0,0,0 },{ 0,0,0,0,0,0 },{ 0,0,0,0,0,36 },{ 0,0,34,0,0 } },
	{ { 0,39,0,37,0 },{ 0,0,0,0,0,45 },{ 0,0,0,0,0 },{ 0,0,0,0,0,43 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } },
	{ { 0,0,0,0,0 },{ 0,0,46,0,52 },{ 0,0,0,48,0 },{ 0,0,0,0,54 },{ 0,0,0,0,0 },{ 0,0,0,0,0 } }
	};
	char * aColors = "ybrgow";
	int colors[54];

	for (int i = 0; i < 54; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (cubeColors[i] == aColors[j])
			{
				colors[i] = j;
			}
		}
	}

	for (int i = 0; i < 54; i++){
		if (i % 9 == 4)
			cube[i / 9][i % 9] = i + 1;
		else if ((i % 9) % 2 == 1) 
			cube[i / 9][i % 9] = realtions[colors[pairs[i][0] - 1]][colors[pairs[i][1] - 1]];
		else 
			cube[i / 9][i % 9] = tripleRealtions[colors[pairs[i][0] - 1]][colors[pairs[i][1] - 1]][colors[pairs[i][2] - 1]];
	}

	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 9; j++){
			std::cout << cube[i][j] << std::endl;
		}
	}
	return 0;
}

int main() {
	char * colors = "yyyyyyyyybbbbbbbbbrrrrrrrrrgggggggggooooooooowwwwwwwww";
	
	colors_to_cube(colors);
	std::cin.get();
	return 0;
}