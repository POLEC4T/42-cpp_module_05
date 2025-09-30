/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:35:46 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/30 12:25:48 by mniemaz          ###   ########.fr       */
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
	throwIfNotExecutable(executor);
	std::ofstream outfile;
	std::string shrubFilename = _target + "_shrubbery";
	outfile.open(shrubFilename.c_str());
	if (outfile.fail()) {
		std::cerr << "Error: could not open file " << shrubFilename << std::endl;
		return ;
	}
	outfile << ASCIITREE;
	outfile.close();
	std::cout << "Shrubbery created in " << shrubFilename << std::endl;
}