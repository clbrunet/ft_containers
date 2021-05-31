/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:12:30 by clbrunet          #+#    #+#             */
/*   Updated: 2021/05/31 12:45:47 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include "list.hpp"
#include "vector.hpp"
#include "map.hpp"
#include "tests.hpp"

// int main(int argc, char* argv[])
// {
// 	if (argc == 1) {
// 		std::cout << "test usage :" << std::endl
// 			<< "  path/test container_name" << std::endl;
// 		return 1;
// 	}
// 	for (int i = 1; i < argc; ++i) {
// 		if (strcmp(argv[i], "list") == 0) {
// 			tests::list::launch();
// 		}
// 		else if (strcmp(argv[i], "vector") == 0) {
// 			tests::vector::launch();
// 		}
// 		else {
// 			std::cout << "Unknown container_name: " << argv[i] << std::endl;
// 		}
// 	}
// 	return 0;
// }

// template <typename Vector>
// void print_vector(Vector vec)
// {
// 	std::cout << "elems:";
// 	for (typename Vector::iterator it = vec.begin(), ite = vec.end();
// 			it != ite; ++it) {
// 		std::cout << " " << *it;
// 	}
// 	std::cout << std::endl;
// }

class t
{
public:
	int val;

	t() :
		val(42)
	{
		std::cout << "wsh" << std::endl;
	}
};

int main(void)
{
	ft::pair<int, t> p;
	std::cout << p.first << std::endl;
	std::cout << p.second.val << std::endl;
	return 0;
}
