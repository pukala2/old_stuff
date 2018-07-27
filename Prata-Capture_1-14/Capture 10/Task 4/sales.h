namespace SALES {
	const int QUATERS = 4;

	class Sales {
	private:
		double sales[QUATERS];
		double average;
		double max;
		double min;
	public:
	Sales(const double ar[], int n);
	Sales();
	void showSales()const;
	};
	
}