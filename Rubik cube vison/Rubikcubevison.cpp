// Rubikcubevison.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int realtions[][6] = {  { 0,  4,  6,  8,  2,  0 },
						{ 11, 0, 15,  0, 13, 17 },
						{ 20, 22, 8, 24,  8, 26 },
						{ 29, 0, 31, 35, 33, 35 },
						{ 38,42,0,40,0,44 },
						{ 51,49,47,51,53,0 } };
int tripleRealtions[][10][6] = {
	{{},{0,0,7,0,1},{0,0,0,3},{0,0,9}}
};
int colors_to_cube(int colors[]) {
	int cube[6][9];
	int pairs[][3] = {
	{ 1,10,39 },{ 2,38 },{ 3,21,28 },{ 4,11 },{},{ 6,20 },{ 7,12,19 },{ 8,29 },{ 9,28,21 },
	{},{ 11,3 },{},{ 13,42 },{},{ 15,22 },{},{ 17,49 },{},
	{},{ 20,8 },{},{ 22,15 },{},{ 24,31 },{},{ 26,47 },{},
	{},{ 29,6 },{},{ 31,24 },{},{ 33,40 },{},{ 35,51 },{},
	{},{ 38,2 },{},{ 40,33 },{},{ 42,13 },{},{ 44,53 },{},
	{},{ 47,26 },{},{ 49,17 },{},{ 51,35 },{},{ 53,44 },{},
	};
	/*
			  1  2  3
			  4  5  6
			  7  8  9
	10 11 12 19 20 21 28 29 30 37 38 39
	13 14 15 22 23 24 31 32 33 40 41 42
	16 17 18 25 26 27 34 35 36 43 44 45
			 46 47 48
			 49 50 51
			 52 53 54
	*/
	for (int i = 0; i < 9; i++)
	{
		//		std::cout << colors[pairs[i][0]] << ", " << colors[pairs[i][1]] << std::endl;
		if (i % 9 == 4)
			cube[i / 9][i % 9] = i + 1;
		else if ((i % 9) % 2 == 1) {
			std::cout << colors[pairs[i][0]] << ", " << colors[pairs[i][1]] << std::endl;
			cube[i / 9][i % 9] = realtions[colors[pairs[i][0] - 1]][colors[pairs[i][1] - 1]];
		}
		else {
			std::cout << colors[pairs[i][0] - 1] << ", " << colors[pairs[i][1] - 1] << ", " << colors[pairs[i][2] - 1] << std::endl;
			cube[i / 9][i % 9] = tripleRealtions[colors[pairs[i][0] - 1]][colors[pairs[i][1] - 1]][colors[pairs[i][2] - 1]];
		}
		std::cout << cube[i / 9][i % 9] << std::endl;
	}

	/*for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << cube[i][j] << std::endl;
		}
	}*/
	return 0;
}
char * aColors = "ybrgow";
int main() {
	char * colors = "yyyyyyyyybbbbbbbbbrrrrrrrrgggggggggooooooooowwwwwwwww";
	int tempCube[54];
	for (int i = 0; i < 54; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (colors[i] == aColors[j])
			{
				tempCube[i] = j;
			}
		}
	}
	colors_to_cube(tempCube);
	std::cin.get();
	return 0;
}