/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:01:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 03:39:57 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <stdexcept>

/**
 * throws my exception if grade is out of bounds
 */
int Form::getCheckedGrade(const int grade) {
	if (grade > _lowestGrade)
		throw GradeTooLowException();
	if (grade < _highestGrade)
		throw GradeTooHighException();
	return grade;
}

Form::Form() :
_name("Unknown form"),
_isSigned(false),
_requiredGradeToSign(_lowestGrade),
_requiredGradeToExec(_lowestGrade) {}

Form::Form(const Form &copy) :
_name(copy._name),
_isSigned(copy._isSigned),
_requiredGradeToSign(getCheckedGrade(copy._requiredGradeToSign)),
_requiredGradeToExec(getCheckedGrade(copy._requiredGradeToExec)) {}

Form& Form::operator=(const Form &other) {
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {}

Form::Form(const std::string name, int requiredGradeToSign, int requiredGradeToExec) : 
_name(name),
_isSigned(false),
_requiredGradeToSign(getCheckedGrade(requiredGradeToSign)),
_requiredGradeToExec(getCheckedGrade(requiredGradeToExec)) {}

const std::string& Form::getName() const {
	return (_name);
}

int Form::getRequiredGradeToExec() const {
	return (_requiredGradeToExec);
}

int Form::getRequiredGradeToSign() const {
	return (_requiredGradeToSign);
}

bool Form::getIsSigned() const {
	return (_isSigned);
}

void Form::beSigned(const Bureaucrat &bc) {
	if (bc.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << bc.getName() << " signed " << _name << std::endl;
}


std::ostream& operator<<(std::ostream &os, const Form &bc) {
	os
		<< bc.getName()
		<< ", to sign: " << bc.getRequiredGradeToSign()
		<< ", to exec: " << bc.getRequiredGradeToExec()
		<< ", signed: ";
	if (bc.getIsSigned())
		os << "yes.";
	else
		os << "no.";
	return (os);
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form: grade too high";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form: grade too low";
}
