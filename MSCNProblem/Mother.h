#pragma once
#include <stdlib.h>
#include <iostream>

using namespace std;

class Mother {
public:
	Mother(int isize_X, int isize_Y);
	Mother();
	~Mother();
	int getSizeX() { return size_X; }
	int getSizeY() { return size_Y; }
	double** getMother() { return macierz; }
	bool changeValue(double value,int index_X, int index_Y);
	bool makeNewSize(int newSize_X,int newSize_Y);
	bool makeRandomValues_All(int minValue, int maxValue);
	bool makeRandomValues_Index_OX(int index_X, int minValue, int maxValue);
	bool makeRandomValues_Index_OY(int index_Y, int minValue, int maxValue);
	
	bool addOneAndRandom_OX(int minValue , int maxValue);
	bool addOneAndRandom_OY(int minValue , int maxValue);
	
	double getAverage_forIndex_X(int index_X);
    double getAverage_forIndex_Y(int index_Y);

	int findMax_forIndex_X(int index_X);
	int findMin_forIndex_X(int index_X);
	int findMin_forIndex_Y(int index_Y);
	int findMax_forIndex_Y(int index_Y);
	void print();

private:
	int size_X;
	int size_Y;
	double** macierz;
	

	
};
