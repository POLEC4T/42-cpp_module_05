/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 01:01:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/25 11:18:11 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <stdexcept>

/**
 * throws my exception if grade is out of bounds
 */
int AForm::getCheckedGrade(const int grade) {
	if (grade > _lowestGrade)
		throw GradeTooLowException();
	if (grade < _highestGrade)
		throw GradeTooHighException();
	return grade;
}

AForm::AForm() :
_name("Unknown AForm"),
_isSigned(false),
_requiredGradeToSign(_lowestGrade),
_requiredGradeToExec(_lowestGrade) {}

AForm::AForm(const AForm &copy) :
_name(copy._name),
_isSigned(copy._isSigned),
_requiredGradeToSign(getCheckedGrade(copy._requiredGradeToSign)),
_requiredGradeToExec(getCheckedGrade(copy._requiredGradeToExec)) {}

AForm& AForm::operator=(const AForm &other) {
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

AForm::AForm(const std::string name, int requiredGradeToSign, int requiredGradeToExec) : 
_name(name),
_isSigned(false),
_requiredGradeToSign(getCheckedGrade(requiredGradeToSign)),
_requiredGradeToExec(getCheckedGrade(requiredGradeToExec)) {}

const std::string& AForm::getName() const {
	return (_name);
}

int AForm::getRequiredGradeToExec() const {
	return (_requiredGradeToExec);
}

int AForm::getRequiredGradeToSign() const {
	return (_requiredGradeToSign);
}

bool AForm::getIsSigned() const {
	return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &bc) {
	if (bc.getGrade() > _requiredGradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
	std::cout << bc.getName() << " signed " << _name << std::endl;
}


std::ostream& operator<<(std::ostream &os, const AForm &bc) {
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

void AForm::throwIfNotExecutable(const Bureaucrat &executor) const{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _requiredGradeToExec)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "AForm: grade too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "AForm: grade too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "AForm: form not signed";
}
