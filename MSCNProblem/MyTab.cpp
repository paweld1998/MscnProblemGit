#include "pch.h"
#include "MyTab.h"
#include <ctime>
#include <iostream>

using namespace std;

MyTab::MyTab(int size)
{
	tab = new double[size];
	tabSize = size;
}


MyTab::~MyTab()
{
	delete[] tab;
}


bool MyTab::makeNewSize(int newSize) {
	if (newSize < 1) {
		return false;
	}
	else {
		double* tablehelper = new double[newSize];

		if (newSize >= tabSize) {
			for (int i = 0; i < tabSize; i++) {
				tablehelper[i] = tab[i];
			}
		}
		else {
			for (int i = 0; i < newSize; i++) {
				tablehelper[i] = tab[i];
			}
		}

		delete[]tab;
		tab = tablehelper;
		tabSize = newSize;

		return true;

	}
}

bool MyTab::makeRandomValues(int minValue, int maxValue) {
    srand(time(NULL));
	if (tabSize<1) {
		return false ;
	}
	else {
		for (int i = 0; i < tabSize; i++) {
			
				tab[i] = rand() % (maxValue - minValue +1) + minValue;
			
		}
		return true;
	}
}


bool MyTab::addOne(double value) {
	int newTabSize = tabSize + 1;
	makeNewSize(newTabSize);
	tab[newTabSize - 1] = value;

	return true;
}

void MyTab::print() {  // wyswietla tablice

	cout << " index \t";
	for (int i = 0; i < tabSize; i++) {
		cout << "[#" << i << "]\t";
	}
	cout << endl << endl<<"\t";

	for (int i = 0; i < tabSize; i++) {
		cout << "[" << tab[i] << "]\t";
	}
}

int MyTab::findMax_Index() {  //zwraca index maksymalnej wartosci w tablicy
	double max = tab[0];
	int maxIndex = 0;
	for (int i = 0; i < tabSize; i++) {
		if (tab[i] > max) {
			max = tab[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}


int MyTab::findMin_Index() {  //zwraca index minimalnej wartosci w tablicy
	double min = tab[0];
	int minIndex = 0;
	for (int i = 0; i < tabSize; i++) {
		if (tab[i] < min) {
			min = tab[i];
			minIndex = i;
		}
	}
	return minIndex;
}