// zad 4 rozdzial 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "sales.h"

using namespace SALES;

int main()
{
	
	double arr[4] = { 2.5,3.3,5.3,2.1 };
	Sales x(arr, 4);
	x.showSales();

	Sales y;
	y.showSales();
	
	system("PAUSE");
	return 0;
    return 0;
}

