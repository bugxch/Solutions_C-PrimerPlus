#include <iostream>

class Move
{
private:
    double x;
    double y;
public:
    Move(double a = 0, double b = 0)
    :x(a), y(b) {};
    void ShowMove() const;
    Move add(const Move & m) const;
    void reset(double a = 0, double b = 0);
};

void Move::ShowMove() const
{
    std::cout << "x = " << x << ", and y = " << y << std::endl;
}

Move Move::add(const Move & m) const
{
    Move newmove;
    newmove.x = this->x + m.x;
    newmove.y = this->y + m.y;
    return newmove;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}

int main()
{
    using namespace std;
    Move move1(-23, 453.33);
    Move move2(3.4, 55.6);
    move1.ShowMove();
    move2.ShowMove();
    Move move3;
    move3 = move2.add(move1);
    move2.reset(-23.4, 99.92);
    move3.ShowMove();
    move3 = move2.add(move1);
    move3.ShowMove();
    return 0;
}