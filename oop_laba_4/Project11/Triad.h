class Triad
{
protected:
	int day, month, year;
public:

	Triad();
	Triad(int d, int m, int y);

	//����
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	//����
	int getDay();
	int getMonth();
	int getYear();

	void dayP();
	void dayM();
	void monthP();
	void monthM();
	void yearP();
	void yearM(); 
};