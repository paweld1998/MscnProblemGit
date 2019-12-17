#include "pch.h"
#include "Mother.h"
#include <ctime>
#include "CMscnProblem.h"

#define DEFAULT_SIZE 10;



Mother::Mother() {
	size_X = DEFAULT_SIZE;
	size_Y = DEFAULT_SIZE;

	macierz = new double *[size_X];

	for (int i = 0; i < size_X; i++) {
		macierz[i] = new double[size_Y];
	}
}

Mother::Mother(int isize_X, int isize_Y) {
	
	size_X = isize_X;
	size_Y = isize_Y;

	macierz = new double *[size_X];

	for (int i = 0; i < size_X; i++) {
		macierz[i] = new double[size_Y];
	}

	
}

Mother::~Mother() {
	for (int i = 0; i < size_X; i++)
		delete[] macierz[i];
	delete[] macierz;
}

bool Mother::makeRandomValues_All(int minValue, int maxValue) {
	srand(time(NULL));
	if (size_X < 1 || size_Y < 1) {
		return false;
	}
	else {


		for (int i = 0; i < size_X; i++) {
			for (int k = 0; k < size_Y; k++) {
				macierz[i][k] = rand() % (maxValue - minValue +1) + minValue;
			}
		}
		return true;
	}
}



bool Mother::makeRandomValues_Index_OX(int index_X, int minValue, int maxValue) {
	
	srand(time(NULL));
	if (size_X < 1 || size_Y < 1)     // false jesli tablica ma mniejsze rozmiary niz 1x1
		return false;
	if ((index_X > size_X) || index_X < 0 )   // false jesli podany index wychodzi poza tablice lub jest ujemny
		return false;
	else {
            for (int k = 0; k < size_Y; k++) {
				macierz[index_X][k] = rand() % (maxValue - minValue +1) + minValue;
			}
		
		return true;
	}
}




bool Mother::makeRandomValues_Index_OY(int index_Y, int minValue, int maxValue) { // wpisuje randomowe wartosci do osi OY  (blad nazwy)
	                                                                              //

	srand(time(NULL));
	if (size_X < 1 || size_Y < 1)            
		return false;
	if ((index_Y > size_X) || index_Y < 0)   
		return false;
	else {
		for (int k = 0; k < size_X; k++) {
			macierz[k][index_Y] = rand() % (maxValue - minValue +1) + minValue;
		}

		return true;
	}
}



bool Mother::makeNewSize(int newSize_X,int newSize_Y){ //tworzy nowa macierz o wskazanym rozmiarze i wspisuje wartosci ze starej
	if (newSize_X < 1 || newSize_Y < 1) {              //jesli nowa macierz jest mniejsza wpisuje wartosci do zakresu indexu nowej macierzy
		return false;
	}

	else {
		double** motherHelper = new double*[newSize_X];
		for (int i = 0; i < newSize_X; i++) {
			motherHelper[i] = new double[newSize_Y];
		}

		if (newSize_X >= size_X && newSize_Y >= size_Y) {
			for (int i = 0; i < size_X; i++) {
				for (int k = 0; k < size_Y; k++) {


					motherHelper[i][k] = macierz[i][k];
				}
			}
		}
		else if (newSize_X >= size_X && newSize_Y < size_Y) {
			for (int i = 0; i < size_X; i++) {
				for (int k = 0; k < newSize_Y; k++) {


					motherHelper[i][k] = macierz[i][k];
				}
			}
		}
		else if (newSize_X < size_X && newSize_Y >= size_Y) {
			for (int i = 0; i < newSize_X; i++) {
				for (int k = 0; k < size_Y; k++) {


					motherHelper[i][k] = macierz[i][k];
				}
			}
		}
		else if (newSize_X < size_X && newSize_Y < size_Y) {
			for (int i = 0; i < newSize_X; i++) {
				for (int k = 0; k < newSize_Y; k++) {


					motherHelper[i][k] = macierz[i][k];
				}
			}
		}

		delete[] macierz;
		macierz = motherHelper;
		size_X = newSize_X;
		size_Y = newSize_Y;

		return true;
	}
}



void Mother::print() { //drukuje macierz
	cout << " index \t ";
	for (int i = 0; i < size_Y; i++) {
		cout << "[#" << i << "]\t";
	}
	cout << endl << endl;
	for (int i = 0; i < size_X; i++) {
		cout << "[#" << i << "]\t";
		for (int k = 0; k < size_Y; k++) {
			cout << "[" << macierz[i][k]<<"]\t";
		}
		cout << endl;
	}
}


bool Mother::addOneAndRandom_OX(int minValue, int maxValue) { //dodaje jedn¹ pozycje w macierzy i wypelnia ja losowymi wartosciami
	int newSizeX = size_X + 1;
	if (makeNewSize(newSizeX, size_Y) == true) {
		if (makeRandomValues_Index_OX(newSizeX - 1, minValue, maxValue) == true) {
			return true;
		}
	}
	else return false;
	
}

bool Mother::addOneAndRandom_OY(int minValue, int maxValue) {
	int newSizeY = size_Y + 1;
	if (makeNewSize(size_X, newSizeY) == true) {
		if(makeRandomValues_Index_OY(newSizeY - 1, minValue, maxValue)==true){
		return true;
	    }
	}
	else return false;
}


bool Mother::changeValue(double value,int index_X, int index_Y) {
	if (index_X > size_X - 1 || index_Y > size_Y - 1) {
		return false;
	}
	if (index_X < 0 || index_Y < 0) {
		return false;
	}
	else {
		macierz[index_X][index_Y] = value;
		return true;
	}
}

int Mother::findMax_forIndex_X(int index_X) { //zwraca index maksymalnej wartosci w macierzy dla indexu X


	double max = macierz[index_X][0];
	int maxIndex_Y = 0;
	for (int i = 0; i < size_Y; i++) {
		if (macierz[index_X][i] > max) {
			max = macierz[index_X][i];
			maxIndex_Y = i;
		}
	}
	return maxIndex_Y;
}

int Mother::findMin_forIndex_X(int index_X) { //zwraca index minimalnej wartosci w macierzy dla indexu X


	double min = macierz[index_X][0];
	int minIndex_Y = 0;
	for (int i = 0; i < size_Y; i++) {
		if (macierz[index_X][i] < min) {
			min = macierz[index_X][i];
			minIndex_Y = i;
		}
	}
	return minIndex_Y;
}

int Mother::findMax_forIndex_Y(int index_Y) { //zwraca index maksymalnej wartosci w macierzy dla indexu Y


	double max = macierz[0][index_Y];
	int maxIndex_X = 0;
	for (int i = 0; i < size_X; i++) {
		if (macierz[i][index_Y] > max) {
			max = macierz[i][index_Y];
			maxIndex_X = i;
		}
	}
	return maxIndex_X;
}

int Mother::findMin_forIndex_Y(int index_Y) { //zwraca index minimalnej wartosci w macierzy dla indexu Y


	double min = macierz[0][index_Y];
	int minIndex_X = 0;
	for (int i = 0; i < size_X; i++) {
		if (macierz[i][index_Y] < min) {
			min = macierz[i][index_Y];
			minIndex_X = i;
		}
	}
	return minIndex_X;
}

