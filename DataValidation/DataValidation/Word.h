#pragma once
#include <iostream>
#include <string>

class Word
{
private:
	std::string text;
	double x, y, height, width;

public:
	Word() {}

	std::string getText() { return this->text; }

	friend std::istream& operator>>(std::istream&, Word&);
	friend bool checkLeftNeighbor(const Word&, const Word&);
	friend bool checkRightNeighbor(const Word&, const Word&);
	friend bool checkTopNeighbor(const Word&, const Word&);
	friend bool checkBottomNeighbor(const Word&, const Word&);
	friend double topDistance(const Word&, const Word&);
	friend double bottomDistance(const Word&, const Word&);
	friend double leftDistance(const Word&, const Word&);
	friend double rightDistance(const Word&, const Word&);
};

