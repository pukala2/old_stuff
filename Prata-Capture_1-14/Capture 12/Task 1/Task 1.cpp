// zad 1 rozdzial 12.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include <iostream>
#include "cow.h"


int main()
{
	{
		Cow x("Lala", "dupa", 22.0);
		Cow y;
		Cow z(x);
		Cow a;
		a = y;
		x.ShowCow();
		y.ShowCow();
		z.ShowCow();
		a.ShowCow();

	}
	system("PAUSE");
    return 0;
}

