#include <iostream>
#include "NodeForwardList.h"

int main(/*int argc, char *argv[]*/)
{
	NodeForwardList<int> sll;

	sll.push_front(1);
	sll.push_front(2);
	sll.push_front(3);
	sll.push_front(4);
	sll.push_front(5);
	sll.pop_front();
	sll.insert(3, 6);
	sll.erase(4);

	for(int i = 0; i < 4; ++i)
	{
		std::cout << sll.at(i) << std::endl;
	}
	int i;
	std::cin >> i;
}