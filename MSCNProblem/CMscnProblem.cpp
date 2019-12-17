#include "pch.h"
#include "CMscnProblem.h"
#include "Mother.h"
#include "MyTab.h"
#include <ctime>
#include <iostream>

using namespace std;

CMscnProblem::CMscnProblem(int supp, int fact, int ware, int shop) {
	suppSize = supp;
	factSize = fact;
	wareSize = ware;
	shopSize = shop;


	supp_to_fact = new Mother(suppSize, factSize);
	fact_to_ware = new Mother(factSize, wareSize);
	ware_to_shop = new Mother(wareSize, shopSize);

	suppConst = new MyTab(suppSize);
	factConst = new MyTab(factSize);
	wareConst = new MyTab(wareSize);

	shopsProfits = new MyTab(shopSize);

	suppPower = new MyTab(suppSize);
	factPower = new MyTab(factSize);
	warePower = new MyTab(wareSize);
	shopPower = new MyTab(shopSize);



}
CMscnProblem::~CMscnProblem() {
	delete supp_to_fact;
	delete fact_to_ware;
	delete ware_to_shop;

	delete suppConst;
	delete factConst;
	delete wareConst;

	delete shopsProfits;

	delete suppPower; //capasity etc
	delete factPower;
	delete warePower;
	delete shopPower;

}

void CMscnProblem::makeAllRandom() {
	supp_to_fact->makeRandomValues_All(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y);
	fact_to_ware->makeRandomValues_All(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y);
	ware_to_shop->makeRandomValues_All(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y);

	suppConst->makeRandomValues(MIN_VALUE_CONSTCOST, MAX_VALUE_CONSTCOST);
	factConst->makeRandomValues(MIN_VALUE_CONSTCOST, MAX_VALUE_CONSTCOST);
	wareConst->makeRandomValues(MIN_VALUE_CONSTCOST, MAX_VALUE_CONSTCOST);

	shopsProfits->makeRandomValues(MIN_SHOP_PROFIT, MAX_SHOP_PROFIT);

	suppPower->makeRandomValues(MIN_VALUE_POWER, MAX_VALUE_POWER);
	factPower->makeRandomValues(MIN_VALUE_POWER, MAX_VALUE_POWER);
	warePower->makeRandomValues(MIN_VALUE_POWER, MAX_VALUE_POWER);
	shopPower->makeRandomValues(MIN_VALUE_POWER, MAX_VALUE_POWER);
	
}


bool CMscnProblem::addSupp(double power, double cCost) {
	
	
	if (supp_to_fact->addOneAndRandom_OX(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y) == true) {
		if (suppConst->addOne(cCost) == true) {
			if (suppPower->addOne(power) == true) {
				suppSize++;
				return true;
			}
		}
	}
	else return false;

}


bool  CMscnProblem::addFact(double power, double cCost){
	
	if (fact_to_ware->addOneAndRandom_OX(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y) == true) {
		if (supp_to_fact->addOneAndRandom_OY(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y) == true) {
			if (factConst->addOne(cCost) == true) {
				if (factPower->addOne(power) == true) {
					factSize++;
					return true;
				}
			}
		}
    }
	else return false;

	

}
bool  CMscnProblem::addWare(double power, double cCost){

	if (ware_to_shop->addOneAndRandom_OX(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y) == true) {
		if (fact_to_ware->addOneAndRandom_OY(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y) == true) {
			if (wareConst->addOne(cCost) == true) {
				if (warePower->addOne(power) == true) {
					wareSize++;
					return true;
				}
			}
		}
	}
	else return false;
}
bool CMscnProblem::addShop(double power, double cCost){   //dodaje sklep o mocy "power" i stalym koszcie "cCOst" , pozota³e koszty losuje 

	if (ware_to_shop->addOneAndRandom_OY(MIN_VALUE_X_TO_Y, MAX_VALUE_X_TO_Y) == true) {
		if (shopsProfits->addOne(cCost) == true) {
			if (shopPower->addOne(power) == true) {
				shopSize++;
				return true;
			}
		}
	}
	else return false;
}



int CMscnProblem::MIN_SHOP_PROFIT_V() {
	return (3 * MIN_VALUE_CONSTCOST) + (3 * MIN_VALUE_X_TO_Y);
}

int CMscnProblem::MAX_SHOP_PROFIT_V() {       // NAD MAX TRZEBA POMYSLEC ????????????????
	return (3 * MAX_VALUE_CONSTCOST) + (3 * MAX_VALUE_X_TO_Y);
}

void CMscnProblem::printProblem() {
	cout << "Number of Suppliers : " << suppSize << endl;
	cout << "Number of factories : " << factSize << endl;
	cout << "Number of warehouses : " << wareSize << endl;
	cout << "Number of shops : " << shopSize << endl << endl;


	cout << "$$$$$$$$$$$$$$$$$$$$$   Cost of transport from suppliers to factories   $$$$$$$$$$$$$$$$$$$$$" << endl<<endl;
	supp_to_fact->print();
	cout << endl << endl;

	cout << "$$$$$$$$$$$$$$$$$$$$$    Cost of transport from factories to warehouses   $$$$$$$$$$$$$$$$$$$$$" << endl<<endl;
	fact_to_ware->print();
	cout << endl << endl;

	cout << "$$$$$$$$$$$$$$$$$$$$$    Cost of transport from warehouses to shops   $$$$$$$$$$$$$$$$$$$$$" << endl<<endl;
	ware_to_shop->print();
	cout << endl << endl << endl;



	cout << "###################################    Const cost of Suppliers  ###################################  " << endl << endl;
	suppConst->print();
	cout << endl << endl << endl;

	cout << "###################################    Const cost of Factories   ###################################  " << endl << endl;
	factConst->print();
	cout << endl << endl << endl;

    cout << "###################################    Const cost of Warehouses   ###################################  " << endl << endl;
	wareConst->print();
	cout << endl << endl << endl<<endl;

    cout << "###################################    Profits of Shops   ###################################  " << endl << endl;
	shopsProfits->print();
	cout << endl << endl<<endl<<endl<<endl;



    cout << "    ###################################   Power of Suppliers  ###################################  " << endl << endl;
	suppPower->print();
	cout << endl << endl << endl;

	cout << "    ###################################   Power of Factories   ###################################  " << endl << endl;
	factPower->print();
	cout << endl << endl << endl;

	cout << "    ###################################   Power of Warehouses   ################################### " << endl << endl;
	warePower->print();
	cout << endl << endl << endl;

	cout << "    ###################################   Power of Warehouses   ###################################  " << endl << endl;
	warePower->print();
	cout << endl << endl;



}