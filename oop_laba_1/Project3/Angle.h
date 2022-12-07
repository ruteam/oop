#include <string>
class Angle {
    int min;
    int deg;
public:
    void getDiapozon();
    double getRadians();
    double getSin();
    Angle add(Angle _angle);
    int sravnenie(Angle _a);
    Angle (int _deg, int _min);
    Angle();
    std::string get();
};