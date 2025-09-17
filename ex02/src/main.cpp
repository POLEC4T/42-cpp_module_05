/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:57:12 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/17 01:31:43 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

int main(void) {
	srand(time(NULL));
	ShrubberyCreationForm shrub("home");
	PresidentialPardonForm pres("me");
	RobotomyRequestForm robot("target");
	{
		Bureaucrat boss("boss", 1);
		
		boss.signForm(shrub);
		boss.signForm(pres);
		boss.signForm(robot);
		boss.executeForm(shrub);
		boss.executeForm(pres);
		boss.executeForm(robot);
	}
	{
		std::cout << "\n--- Limits tests ---" << std::endl;
		Bureaucrat limitBc("limitBc", 137);
		std::cout << limitBc << std::endl;
		limitBc.executeForm(shrub);

		limitBc.decrementGrade();
		std::cout << limitBc << std::endl;
		limitBc.executeForm(shrub);

		std::cout << "-----" << std::endl;
		limitBc.setGrade(5);
		std::cout << limitBc << std::endl;
		limitBc.executeForm(pres);
		limitBc.decrementGrade();
		std::cout << limitBc << std::endl;
		limitBc.executeForm(pres);

		std::cout << "-----" << std::endl;
		limitBc.setGrade(45);
		std::cout << limitBc << std::endl;
		limitBc.executeForm(robot);
		limitBc.decrementGrade();
		std::cout << limitBc << std::endl;
		limitBc.executeForm(robot);
	}
	{
		std::cout << "\n--- 50% robotomy success rate test ---" << std::endl;
		Bureaucrat randBc("randBc", 1);
		for (int i = 0; i < 10; i++)
			randBc.executeForm(robot);
	}
	{
		std::cout << "\n--- Unsigned form execution test ---" << std::endl;
		Bureaucrat john("john", 1);
		ShrubberyCreationForm unsignedShrub("unsigned");
		PresidentialPardonForm unsignedPres("unsigned");
		RobotomyRequestForm unsignedRobot("unsigned");
		john.executeForm(unsignedShrub);
		john.executeForm(unsignedPres);
		john.executeForm(unsignedRobot);
	}
	return (0);
}