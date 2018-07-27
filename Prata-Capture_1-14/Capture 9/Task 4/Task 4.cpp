// zad 4 rozdzial 9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "sales.h"

using namespace SALES;

int main()
{
	Sales x;
	double arr[4] = { 2.5,3.3,5.3,2.1 };
	setSales(x, arr, 4);
	showSales(x);

	Sales y;
	y.sales[0] = 22.1;
	y.sales[1] = 5.2;
	y.sales[2] = 3.9;
	y.sales[3] = 11.11;

	setSales(y);
	showSales(y);

	system("PAUSE");
    return 0;
}

