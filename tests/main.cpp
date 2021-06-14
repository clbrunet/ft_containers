#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <map>

#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "tests.hpp"

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::cout << "test usage :" << std::endl
			<< "  path/test container_name" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "list") == 0) {
			tests::list::launch();
		}
		else if (strcmp(argv[i], "vector") == 0) {
			tests::vector::launch();
		}
		else if (strcmp(argv[i], "map") == 0) {
			tests::map::launch();
		}
		else {
			std::cout << "Unknown container_name: " << argv[i] << std::endl;
		}
	}
	return 0;
}

// int main(void)
// {
// 	std::map<int, int> map;
// 	std::map<int, int>::iterator it;
// 	std::map<int, int>::const_iterator ite;
// 	map[88] = 0;
// 	map[50] = 50;
// 	map[100] = 100;
// 	map[0] = 0;
// 	map[11] = 0;
// 	map[13] = 0;
// 	map[92] = 0;
// 	map[37] = 0;
// 	map[33] = 0;
// 	map[25] = 0;
// 	map[49] = 0;
// 	map[40] = 0;
// 	it = map.end();
// 	std::cout << it->first << std::endl;
// 	--it;
// 	std::cout << it->first << std::endl;
// 	--it;
// 	std::cout << it->first << std::endl;
// 	--it;
// 	std::cout << it->first << std::endl;
// 	++it;
// 	std::cout << it->first << std::endl;
// 	++it;
// 	std::cout << it->first << std::endl;
// 	++it;
// 	std::cout << it->first << std::endl;
// 	++it;
// 	std::cout << it->first << std::endl;
// 	--it;
// 	std::cout << it->first << std::endl;
// 	return 0;
// }
