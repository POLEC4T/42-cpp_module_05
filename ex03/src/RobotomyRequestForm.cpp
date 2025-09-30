/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:35:46 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/30 12:22:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
AForm("unknown_target_robotomy", _requiredGradeToSign, _requiredGradeToExec),
_target("unknown_target") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
AForm(copy), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
AForm(target + "_robotomy", _requiredGradeToSign, _requiredGradeToExec),
_target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	throwIfNotExecutable(executor);
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
