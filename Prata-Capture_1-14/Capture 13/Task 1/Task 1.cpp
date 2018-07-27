// zad 1 rozdzial 13.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include "disk.h"

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Sonta Fortepianowa B-dur, Fantazja C moll", "Alfred Brendel",
		"Philips", 2, 57.17);

	Cd *pcd = &c1;

	std::cout << "Bezposrednie uzycie obiektu:\n";
	c1.report();
	c2.report();

	std::cout << "Uzycie wskaznika na typ Cd:\n";
	pcd->report();
	pcd = &c2;
	pcd->report();

	std::cout << "Wywolanie funkcji z argumentem w postaci referencji do typu Cd:\n";
	Bravo(c1);
	Bravo(c2);

	std::cout << "Test przypisania : ";
	Classic copy;
	copy = c2;
	copy.report();
	system("PAUSE");
    return 0;
}

