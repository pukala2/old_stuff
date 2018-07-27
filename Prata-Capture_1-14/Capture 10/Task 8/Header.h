namespace Client {

	struct Object {
		char fullname[35];
		double age;
	};

	class Stack {
	private:
		enum { MAX = 5 };//stala zasiegu klasy
		Object arr[MAX];//przechowuje elementy stosu
		int top;//indeks szczytowego elementu stosu
	public:
		Stack();
		bool isempty()const;
		bool isfull()const;
		//push() zwraca false, jesli stos jest juz pelny (true w pozostalch przypadkach)
		bool push(Object & item);
		//pop() zwraca false, jesli stos jest pusty (true w pozostalych przypadkach zdjemuje element ze stosu)
		bool pop(Object & item);
		void show();
		void visit(void(*ptr)(Object & str));
	};
	void menu();
	
	void funkcja(Object & stru);
}