/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 09:12:30 by clbrunet          #+#    #+#             */
/*   Updated: 2021/05/23 13:58:06 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "list.hpp"

int		main(void)
{
	std::list<int> lst(1, 111);
	std::list<int>::iterator it;
	std::list<int>::iterator ite;

	lst.push_back(222);
	lst.push_back(333);
	lst.push_back(444);

	it = lst.begin();
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	++it;
	++it;
	++it;
	std::cout << *it << std::endl;
	// for (it = lst.begin(), ite = lst.end(); it != ite; ++it) {
	// 	std::cout << *it << std::endl;
	// }
	return (0);
}
