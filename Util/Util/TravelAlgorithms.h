#include <iostream>
#include <limits>
#include "nodo.h"
using namespace std;


class Travel
{
public:
	Travel();
	~Travel();
	int** floyd(int **arr, int size);
	int** dijkstra(int **arr, int size);
private:
	int minVal(int a, int b);
	int maxVal(int a, int b);
};

Travel::Travel()
{
}

Travel::~Travel()
{
}

int minVal(int a, int b)
{
	return (a > b) ? b : a;
}

int maxVal(int a, int b)
{
	return (a < b) ? b : a;
}

int ** floyd(int **iArr, int size)
{
	int iN = size;
	for (int k = 0; k < iN; k++)
		for (int i = 0; i < iN; i++)
			for (int j = 0; j < iN; j++)
			{
				if (iArr[i][j] > iArr[i][k] || iArr[i][j] > iArr[k][j])
					iArr[i][j] = minVal(iArr[i][j], maxVal(iArr[i][k], iArr[k][j]));
			}
	return iArr;
}

int** dijkstra(int **iAd, int *iL, int *iT, int size)
{
	int iE, vMin, iNodos, iArcos;
	nodo *iS = new nodo[size];
	for (int i = 2; i <= iNodos; i++)
	{
		iL[i] = iAd[1][i];
		iT[i] = 1;
	}

	for (int i = 0; i < iNodos - 1; i++)
	{
		int iMin = numeric_limits<int>::max();
		for (int j = 2; j <= iNodos; j++)
		{
			if (iL[j] >= 0 && iL[j] <= iMin)
			{
				iMin = iL[j];
				vMin = j;
			}
		}
		iE = iAd[iT[vMin]][vMin];
		iS[i].setDestino(vMin);
		iS[i].setOrigen(iT[vMin]);
		for (int k = 2; k <= iNodos; k++)
		{
			if (iL[vMin] != numeric_limits<int>::max()  && iAd[vMin][k] != numeric_limits<int>::max())
			if (iL[vMin] + iAd[vMin][k] < iL[k])
			{
				iL[k] = iL[vMin] + iAd[vMin][k];
				iT[k] = vMin;
			}
		}
		iS[i].setPeso(iL[vMin]);
		iL[vMin] = -1;
	}
	return iAd;
}