class Move {
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove()const;
	Move add(const Move &m)const;
	//metoda sumuje x obiektu m i x obiektu wuwolujacego ,
	//y obiektu m i y obiektu wywolujaego, tworzy nowy obiekt, inicjalizuje go
	//obliczonymi sumami x i y zweaca tak zainicjalizowany obiekt
	void reset(double a = 0, double b = 0);
};
