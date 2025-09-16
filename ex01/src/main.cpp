/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:12:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 03:51:41 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main (void) {
	{
		std::cout << "--- Basics ---" << std::endl;
		Bureaucrat bc("Arthur", 50);
		Form f("Form 1", 100, 1);
		bc.signForm(f);
		std::cout << f << std::endl;
		Form f2("Form 2", 50, 1);
		bc.signForm(f2);
		std::cout << f2 << std::endl;
	}
	{
		// Trying to sign a form with a bureaucrat that has a too low grade throws an exception
		std::cout << "\n--- Signing exceptions ---" << std::endl;
		Bureaucrat bc2("Toto", 50);
		Form f3("Form 3", 25, 1);
		bc2.signForm(f3);
		std::cout << f3 << std::endl;
	}
	{
		// We can't create forms with out of bounds grades (1 - 150)
		std::cout << "\n--- Form exceptions ---" << std::endl;
		try {
			Form f4("Form 4", 0, 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Form f5("Form 5", 151, 1);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Form f6("Form 6", 1, 0);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			Form f7("Form 7", 1, 151);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}