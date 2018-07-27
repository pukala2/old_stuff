#pragma once
#include <iostream>

template <typename T>
class Matrix;
template <typename T>
std::ostream& operator<<(std::ostream & os, const Matrix<T> & m);

template<typename T>
class Matrix {
private:
	int width;  //number of columns 
	int height;  //number of rows
	T **matrice;  //array of pointers
public:
	Matrix(int y = 0, int = 0); //constructor
	Matrix(const Matrix & m);  //copy constructor
	~Matrix();  //destructor
	void Set_Matrix(); //setting matrix values
	void Set_zero();  //setting the matrix value to zero
	Matrix & operator=(const Matrix & m); //overloading basic assignment operator
	Matrix operator+(const Matrix & m); //overloading addition operator
	Matrix operator-(const Matrix & m); //overloading subtraction operator
	Matrix operator*(const Matrix & m); //overloading Multiplication operator  

	friend std::ostream & operator<< <T>(std::ostream & os, const Matrix<T> &m); //overloading Stream extraction operator 

};

template <typename T>
std::ostream & operator<<(std::ostream & os, const Matrix<T> & m);


//=========================================================================

template<typename T>
Matrix<T>::Matrix(int y, int x) {
	height = y;
	width = x;
	matrice = new T *[height];
	for (int i = 0; i < height; i++)
		matrice[i] = new T[width];
}

//=========================================================================

template<typename T>
Matrix<T>::Matrix(const Matrix & m) {
	height = m.height;
	width = m.width;

	matrice = new T *[height];
	for (int i = 0; i < height; i++)
		matrice[i] = new T[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrice[i][j] = m.matrice[i][j];
		}
	}
}

//=========================================================================

template<typename T>
Matrix<T>::~Matrix() {
	for (int i = 0; i<height; i++)
		delete[] matrice[i];
	delete[] matrice;
}

//=========================================================================

template<typename T>
void Matrix<T>::Set_Matrix() {
	for (int i = 0; i < height; i++) {
		std::cout << "Number " << i + 1 << " row:\n";
		for (int j = 0; j < width; j++) {
			std::cout << "Set value " << j + 1 << " column:";
			std::cin >> matrice[i][j];
		}
	}
}

//=========================================================================

template<typename T>
void Matrix<T>::Set_zero() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrice[i][j] = 0;
		}
	}
}

//=========================================================================

template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix & m) {
	if (&m == this)
		return *this;

	for (int i = 0; i<height; i++)
		delete[] matrice[i];
	delete[] matrice;

	height = m.height;
	width = m.width;

	matrice = new int *[height];
	for (int i = 0; i < height; i++)
		matrice[i] = new int[width];

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrice[i][j] = m.matrice[i][j];
		}
	}
	return *this;
}

//=========================================================================

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix & m) {
	if (m.height == height && m.width == width) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				matrice[i][j] += m.matrice[i][j];
		return *this;
	}
	else {
		std::cout << "Arrays of matrices must have the same size.\n";
		std::cout << "Operation failed.\n";
		return *this;;
	}
}

//=========================================================================

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix & m) {
	if (m.height == height && m.width == width) {
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				matrice[i][j] -= m.matrice[i][j];

		return *this;
	}
	else {
		std::cout << "Arrays of matrices must have the same size.\n";
		std::cout << "Operation failed.\n";
		return *this;
	}
}

//=========================================================================

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix & m) {
	Matrix temp(height, m.width);
	temp.Set_zero();
	if (width == m.height) {
		for (int i = 0; i < height; ++i)
			for (int j = 0; j < m.width; ++j)
				for (int k = 0; k < width; ++k) {
					temp.matrice[i][j] += matrice[i][k] * m.matrice[k][j];
				}
		return temp;
	}
	else {
		std::cout << " Number of columns in the 1st one, have to be equals the number of rows in the 2nd one.\n";
		std::cout << "Operation failed.\n";
		return temp;
	}
}

//=========================================================================

template <typename T>
std::ostream & operator<<(std::ostream & os, const Matrix<T> &m) {
	for (int i = 0; i < m.height; i++) {
		os << std::endl;
		for (int j = 0; j < m.width; j++)
			os << m.matrice[i][j] << "|";
	}
	os << std::endl;
	return os;
}
