// Util.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "stdafx.h"
#include "TravelAlgorithms.h"
using namespace std;

void fill(int **iAd, int iNodes)
{
	for (int i = 0; i <= iNodes; i++)
	{
		for (int j = 0; j <= iNodes; j++)
		{
			iAd[i][j] = numeric_limits<int>::max();
		}
	}
}

int main(int argc, _TCHAR* argv[])
{
	int size = 20;
	int** matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];
	fill(matrix, size);
	Travel t = Travel();
	t.dijkstra(matrix, size);
	t.floyd(matrix, size);
	return 0;
}

