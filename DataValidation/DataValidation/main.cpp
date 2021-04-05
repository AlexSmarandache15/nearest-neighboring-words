#include "Word.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <memory.h>

int main(int argc, char* argv[])
{
	int no_words, index;
	
	std::string input = "input.txt";
	std::ifstream fin(input);
	fin >> no_words;
	std::vector<std::shared_ptr<Word>> words(no_words, nullptr);

	for (auto& it : words)
	{
		it = std::make_shared<Word>();
		fin >> *it;
	}

	fin >> index;
	auto givenWord = (std::begin(words) + index);

	std::unique_ptr<std::vector<std::shared_ptr<Word>>> left_words    = nullptr;
	std::unique_ptr<std::vector<std::shared_ptr<Word>>> right_words   = nullptr;
	std::unique_ptr<std::vector<std::shared_ptr<Word>>> top_words     = nullptr;
	std::unique_ptr<std::vector<std::shared_ptr<Word>>> bottom_words  = nullptr;

	for (auto it = std::begin(words); it != std::end(words); it++)
	{
		if (it != givenWord)
		{
			if (checkLeftNeighbor((**givenWord), (**it))) 
			{
				if (left_words == nullptr)
				{
					left_words = std::make_unique<std::vector<std::shared_ptr<Word>>>();
				}
				(*left_words).push_back(*it);
			}
			if (checkRightNeighbor((**givenWord), (**it)))
			{
				if (right_words == nullptr)
				{
					right_words = std::make_unique<std::vector<std::shared_ptr<Word>>>();
				}
				right_words->push_back(*it);
			}
			if (checkTopNeighbor((**givenWord), (**it)))
			{
				if (top_words == nullptr)
				{
					top_words = std::make_unique<std::vector<std::shared_ptr<Word>>>();
				}
				(*top_words).push_back(*it);
			}
			if (checkBottomNeighbor((**givenWord), (**it)))
			{
				if (bottom_words == nullptr)
				{
					bottom_words = std::make_unique<std::vector<std::shared_ptr<Word>>>();
				}
				bottom_words->push_back(*it);
			}
		}
	}

	std::string output = "output.txt";
	std::ofstream fout(output);
	
	if (std::size(*top_words))
	{
		auto top_best = std::min_element(std::begin(*top_words), std::end(*top_words),
									[&givenWord](const auto& x, const auto& y) -> bool
									{ return ( topDistance((**givenWord), *x) < topDistance((**givenWord), *y)); });
		fout << "top : " << (*top_best)->getText() << std::endl;
	}
	else
	{
		fout << "top: none" << std::endl;
	}
	
	if (std::size(*left_words))
	{
		auto left_best = std::min_element(std::begin(*left_words), std::end(*left_words),
									[&givenWord](const auto& x, const auto& y) -> bool
									{ return (leftDistance((**givenWord), *x) < leftDistance((**givenWord), *y)); });
		fout << "left : " << (**left_best).getText() << std::endl;
	}
	else
	{
		fout << "left: none" << std::endl;
	}

	if (std::size(*bottom_words))
	{
		auto bottom_best = std::min_element(std::begin(*bottom_words), std::end(*bottom_words),
									[&givenWord](const auto& x, const auto& y) -> bool
									{ return (bottomDistance((**givenWord), *x) < bottomDistance((**givenWord), *y)); });
		fout << "bottom : " << (*bottom_best)->getText() << std::endl;
	}
	else
	{
		fout << "bottom: none" << std::endl;
	}

	if (std::size(*right_words))
	{
		auto right_best = std::min_element(std::begin(*right_words), std::end(*right_words),
									[&givenWord](const auto& x, const auto& y) -> bool
									{ return (rightDistance((**givenWord), *x) < rightDistance((**givenWord), *y)); });
		fout << "right : " << (**right_best).getText() << std::endl;
	}
	else
	{
		fout << "right: none" << std::endl;
	}

	fin.close();
	fout.close();
	return 0;
}