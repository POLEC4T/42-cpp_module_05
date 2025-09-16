/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:46:41 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 02:05:37 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
#include "./Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		static const int _lowestGrade = 150;
		static const int _highestGrade = 1;
		const std::string _name;
		bool _isSigned;
		const int _requiredGradeToSign;
		const int _requiredGradeToExec;
		int getCheckedGrade(const int grade);

	public:
		Form();
		Form(const Form &copy);
		Form& operator=(const Form &other);
		~Form();
		
		Form(const std::string name, int requiredGradeToSign, int requiredGradeToExec);
		const std::string& getName() const;
		int getRequiredGradeToSign() const;
		int getRequiredGradeToExec() const;
		bool getIsSigned() const;
		void beSigned(const Bureaucrat &bc);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Form &bc);

#endif