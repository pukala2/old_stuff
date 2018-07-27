
namespace Client {
	
	

	static double general = 0;

	struct Customer {
		char fullname[35];
		double payment;
	};

	class Stack {
	private:
		enum { MAX = 5 };//stala zasiegu klasy
		Customer arr[MAX];//przechowuje elementy stosu
		int top;//indeks szczytowego elementu stosu
	public:
		Stack();
		bool isempty()const;
		bool isfull()const;
		//push() zwraca false, jesli stos jest juz pelny (true w pozostalch przypadkach)
		bool push(Customer & item);
		//pop() zwraca false, jesli stos jest pusty (true w pozostalych przypadkach zdjemuje element ze stosu)
		bool pop(Customer & item);
		void show();
	};
	void menu();
}
