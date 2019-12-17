#pragma once
#include <stdlib.h>
#include <iostream>
#include "Mother.h"
#include "MyTab.h"


#define MIN_VALUE_X_TO_Y 1
#define MAX_VALUE_X_TO_Y 10

#define MIN_VALUE_POWER 100
#define MAX_VALUE_POWER 1000

#define MIN_VALUE_CONSTCOST 10
#define MAX_VALUE_CONSTCOST 1000

#define MIN_SHOP_PROFIT 20
#define MAX_SHOP_PROFIT 30

using namespace std;

class CMscnProblem
{
public:
	CMscnProblem(int supp,int fact,int ware,int shop);
	~CMscnProblem();
	void makeAllRandom();

	bool addSupp(double power, double cCost);
	bool addFact(double power, double cCost);
	bool addWare(double power, double cCost);
	bool addShop(double power, double cCost);

	bool change_s_to_f(int suppIndex, int factIndex);
	bool change_f_to_w(int factIndex, int wareIndex);
	bool change_w_to_s(int wareIndex, int shopIndex);

	int MIN_SHOP_PROFIT_V();
	int MAX_SHOP_PROFIT_V();

	void printProblem();
private:
	//PROBLEM
	Mother *supp_to_fact;  //suppliers , factories , warehouses , shops (WAYS COSTS)
    Mother *fact_to_ware;  //(PL) macierze kosztów od dostawcy do fabryki itd...
	Mother *ware_to_shop;

	MyTab *suppConst;     //const cost of working (cCost)
	MyTab *factConst;     //(PL) stale koszty pracy jednostki
	MyTab *wareConst;

	MyTab *shopsProfits;

	MyTab *suppPower;  //capasity etc
	MyTab *factPower;  //(PL) moc = pojemnosc magazynu , moc produkcyjna fabryki itd
	MyTab *warePower;
	MyTab *shopPower;

	int suppSize;
	int factSize;
	int wareSize;
	int shopSize;

	//SOLUTION

	Mother *supp_to_fact_Value; 
	Mother *fact_to_ware_Value;  
	Mother *ware_to_shop_Value;

	MyTab* suppUsed;
	MyTab* factUsed;
	MyTab* wareUsed;
	MyTab* shopUsed;




};

