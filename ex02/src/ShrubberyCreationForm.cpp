/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:35:46 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 12:43:08 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("Shrubbery form", _requiredGradeToSign, _requiredGradeToExec),
_target("Unknown target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
AForm(target + "_shrubbery", _requiredGradeToSign, _requiredGradeToExec),
_target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (executor.getGrade() > _requiredGradeToExec)
		throw GradeTooLowException();
	std::ofstream outfile;
	outfile.open(_target + "_shrubbery");
	if (outfile.fail()) {
		std::cerr << "Error: could not open file " << _target + "_shrubbery" << std::endl;
		return ;
	}
	outfile << ASCIITREE;
	outfile.close();
	std::cout << "Shrubbery created in " << _target + "_shrubbery" << std::endl;
}