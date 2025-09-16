/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:01:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 05:10:16 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat() : _name("Unknown bureaucrat") {
	setGrade(150);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name) {
	setGrade(copy._grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other)
	{
		setGrade(other._grade);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
: _name(name) {
	setGrade(grade);
}

const std::string& Bureaucrat::getName() const {
	return (_name);
}

int Bureaucrat::getGrade() const {
	return (_grade);
}

void Bureaucrat::setGrade(const int grade) {
	if (grade > _lowestGrade)
		throw GradeTooLowException();
	if (grade < _highestGrade)
		throw GradeTooHighException();
	_grade = grade;
}

void Bureaucrat::incrementGrade() {
	setGrade(_grade - 1);
}

void Bureaucrat::decrementGrade() {
	setGrade(_grade + 1);
}

void Bureaucrat::signForm(Form &form) const{
	try {
		form.beSigned(*this);
	} catch (std::exception &e) {
		std::cerr << _name
			<< " couldn’t sign " << form.getName()
			<< " because " << e.what() << std::endl; 
	}
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc) {
	os << bc.getName() << ", bureaucrat grade " << bc.getGrade() << ".";
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat: grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat: grade too low";
}
