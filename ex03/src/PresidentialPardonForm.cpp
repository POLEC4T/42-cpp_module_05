/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:35:46 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/30 12:22:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
AForm("unknown_target_presidential", _requiredGradeToSign, _requiredGradeToExec),
_target("unknown_target") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
AForm(copy), _target(copy._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm(target + "_presidential", _requiredGradeToSign, _requiredGradeToExec),
_target(target) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	throwIfNotExecutable(executor);
	std::cout << _target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}
