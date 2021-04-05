#include "Word.h"

std::istream& operator>>(std::istream& in, Word& myWord)
{
    in >> myWord.text >> myWord.x >> myWord.y >> myWord.width >> myWord.height;
    return in;
}

bool checkLeftNeighbor(const Word& w1, const Word& w2)
{
    return (w1.y == w2.y) && (w1.x > (w2.x + w2.width));
}

bool checkTopNeighbor(const Word& w1, const Word& w2)
{
    return ((w1.x == w2.x) && (w1.y < (w2.y - w2.height)));
}

bool checkBottomNeighbor(const Word& w1, const Word& w2)
{
    return ((w1.x == w2.x) && ((w1.y - w1.height) > w2.y ));
}

bool checkRightNeighbor(const Word& w1, const Word& w2)
{
    return (w1.y == w2.y) && ((w1.width + w1.x) < w2.x);
}

double topDistance(const Word& w1, const Word& w2)
{
    return (w2.y - w2.height - w1.y);
}

double leftDistance(const Word& w1, const Word& w2)
{
    return (w1.x - w2.width- w2.x);
}

double rightDistance(const Word& w1, const Word& w2)
{
    return (w2.x - w1.width - w1.x);
}

double bottomDistance(const Word& w1, const Word& w2)
{
    return (w1.y - w1.height - w2.y);
}

