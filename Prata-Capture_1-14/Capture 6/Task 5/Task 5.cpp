// zad 5 rozdzial 6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

int main()
{
	
	int twarp;
	std::cout << "Podaj ile zarobiles twarpow:";
	while (std::cin >> twarp) {
		
		double give=0;
		if (twarp < 0) 
			break;
		
		else if (twarp >= 0 && twarp < 10000) {
			twarp = 0;
			std::cout << "Twoj podatek to: " << give << "\n";
		}
		else if (twarp >= 10000 && twarp < 20000) {
			give = (5000 * 0.00) + (10000 * 0.10);
			std::cout << "Twoj podatek to: " << give << "\n";
		}
		else if (twarp >= 20000 && twarp < 35000) {
			give = (5000 * 0.00) + (10000 * 0.10) + (20000 * 0.15);
			std::cout << "Twoj podatek to: " << give << "\n";
		}
		else{
			give = (5000 * 0.00) + (10000 * 0.10) + (20000 * 0.15) + (3000 * 0.2);
			std::cout << "Twoj podatek to: " << give << "\n";
		}
		std::cout << "Podaj ile zarobiles twarpow:";
	}

    return 0;
}

