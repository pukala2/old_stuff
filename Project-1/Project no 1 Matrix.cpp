// Project no 1 Matrix.cpp: Okreœla punkt wejœcia dla aplikacji konsoli.
//

#include "stdafx.h"
#include "matrix.h"
#include <iostream>

int main()
{
	{
		std::cout << "Test Addition\n";
		Matrix<double> a1(2, 2);
		a1.Set_Matrix();
		Matrix<double> b1(2, 2);
		b1.Set_Matrix();
		Matrix<double> c1 = a1 + b1;
		std::cout << c1 << "\n\n";

		std::cout << "Test Subtraction\n";
		Matrix<double> a2(2, 2);
		a2.Set_Matrix();
		Matrix<double> b2(2, 2);
		b2.Set_Matrix();
		Matrix<double> c2 = a2 - b2;
		std::cout << c2 << "\n\n";

		std::cout << "Multiplication\n";
		Matrix<double> a3(2, 3);
		a3.Set_Matrix();
		Matrix<double> b3(3, 3);
		b3.Set_Matrix();
		Matrix<double> c3 = a3*b3;
		std::cout << c3 << "\n\n";


	system("PAUSE");
    return 0;
	}
}

