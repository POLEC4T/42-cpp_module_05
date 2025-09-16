/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:12:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 03:54:18 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void) {
	Bureaucrat bc("Arthur", 1);

	try {
		bc.setGrade(150);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << bc << std::endl;
	try {
		bc.setGrade(1);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << bc << std::endl;
	try {
		bc.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << bc << std::endl;
	try {
		bc.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << bc << std::endl;

	std::cout << "--- Exceptions: ---" << std::endl;
	try {
		bc.incrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		bc.setGrade(-50);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		bc.setGrade(151);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	bc.setGrade(150);
	try {
		bc.decrementGrade();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}