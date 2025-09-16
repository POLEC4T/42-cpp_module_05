/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:57:12 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 12:54:05 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void) {
	srand(time(NULL));
	Bureaucrat bc("bc1", 1);

	bc.executeForm(ShrubberyCreationForm("home"));
	bc.executeForm(PresidentialPardonForm("me"));
	bc.executeForm(RobotomyRequestForm("target"));

	std::cout << "--- Limits tests ---" << std::endl;
	Bureaucrat limitBc("limitBc", 137);
	std::cout << limitBc << std::endl;
	limitBc.executeForm(ShrubberyCreationForm("home"));

	limitBc.decrementGrade();
	std::cout << limitBc << std::endl;
	limitBc.executeForm(ShrubberyCreationForm("home"));

	std::cout << "-----" << std::endl;
	limitBc.setGrade(5);
	std::cout << limitBc << std::endl;
	limitBc.executeForm(PresidentialPardonForm("me"));
	limitBc.decrementGrade();
	std::cout << limitBc << std::endl;
	limitBc.executeForm(PresidentialPardonForm("me"));

	std::cout << "-----" << std::endl;
	limitBc.setGrade(45);
	std::cout << limitBc << std::endl;
	limitBc.executeForm(RobotomyRequestForm("target"));
	limitBc.decrementGrade();
	std::cout << limitBc << std::endl;
	limitBc.executeForm(RobotomyRequestForm("target"));

	std::cout << "--- 50% robotomy success rate test ---" << std::endl;
	limitBc.setGrade(1);
	for (int i = 0; i < 10; i++)
		limitBc.executeForm(RobotomyRequestForm("target"));
	return (0);
}