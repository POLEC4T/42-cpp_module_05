/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:57:12 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/18 02:15:02 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main(void) {
	srand(time(NULL));
	AForm* rrf;
	Intern someRandomIntern;
	Bureaucrat boss("boss", 1);
	{
		rrf = NULL;
		try {
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete rrf;
	}
	{
		rrf = NULL;
		try {
			rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete rrf;
	}
	{
		rrf = NULL;
		try {
			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete rrf;
	}
	{
		rrf = NULL;
		try {
			rrf = someRandomIntern.makeForm("non existing form", "Bender");
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		delete rrf;
	}

	return (0);
}