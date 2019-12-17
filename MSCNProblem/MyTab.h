#pragma once
#include <stdlib.h>

class MyTab
{
public:
	MyTab(int size);
	~MyTab();
	bool makeRandomValues(int minValue, int maxValue);
	bool makeNewSize(int newSize);
	bool addOne(double value);
	void print();
	int findMax_Index(); 
	int findMin_Index();
private:
	double* tab;
	int tabSize;
};

