/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:44:59 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/18 02:52:19 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern &other) {
	(void) other;
	return *this;
}

Intern::~Intern() {}

AForm* createShrubberyForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
	std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*formCreators[3])(const std::string &target) = {
		&createShrubberyForm,
		&createRobotomyRequestForm,
		&createPresidentialPardonForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	throw FormDontExistException();
}

const char *Intern::FormDontExistException::what() const throw() {
	return ("Intern: Form does not exist");
}
