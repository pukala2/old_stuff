#pragma once
class Cow {
private:
public:
	char name[20];
	char *hobby;
	double weight;

	Cow();
	Cow(const char *nm, const char *ho, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow()const;  //wyswitla wszystkie dane obiektu
};