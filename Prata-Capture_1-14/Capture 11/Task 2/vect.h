#pragma once

#include <iostream>
namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };
	private:
		double x;//wartosc skladowej poziomej
		double y;//wartosc skladowej pionowej
		Mode mode;//RECT lub POL
				  //prywatne metody ustawiajace sklado	
	public:
		double set_mag();
		double set_ang();
		void set_x();
		void set_y();
		void set_x(double n1, double n2);
		void set_y(double n1, double n2);
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval()const { return x; }//zwraca wartosc skladowej x
		double yval()const { return y; }//zwraca wartosc skladowej y
		void polar_mode();//ustawia tryb na biegunowy (POL)
		void rect_mode();//ustawia tryb na kartezjanski (RECT)
						 //metody przeciazajace operatory
		Vector operator+(const Vector & b)const;
		Vector operator-(const Vector & b)const;
		Vector operator-()const;
		Vector operator*(double n)const;
		//funkcje zaprzyjaznione
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
		operator double();
	};
}//koniec przestrzeni nazw Vector
