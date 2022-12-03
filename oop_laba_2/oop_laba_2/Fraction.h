class Fraction
{
    int num;
    int den;
public:
    Fraction();

    Fraction(int n, int d);

    ~Fraction();

    Fraction(const Fraction& f);

    void setNum(int n);
    void setDen(int d);

    int getNum() const;
    int getDen() const;

    void reduce();

    int getCommonDen(Fraction& f);

    Fraction operator +(Fraction f);
    Fraction operator -(Fraction f);
    Fraction operator *(const Fraction& f);
    Fraction operator /(const Fraction& f);

    bool operator == (const Fraction f);
    bool operator != (const Fraction f);

    bool operator >(const Fraction f);
    bool operator <(const Fraction f);

    bool operator >=(const Fraction f);
    bool operator <=(const Fraction f);

    friend std::ostream& operator<<(std::ostream& out, const Fraction f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);

    std::string toString();
};