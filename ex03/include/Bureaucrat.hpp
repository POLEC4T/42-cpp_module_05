/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:46:41 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 12:35:56 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>
#include "./AForm.hpp"

class AForm;
class Bureaucrat {
	private:
		static const int _lowestGrade = 150;
		static const int _highestGrade = 1;
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		
		Bureaucrat(const std::string &name, int grade);
		const std::string& getName() const;
		int getGrade() const;
		void setGrade(const int grade);
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form) const;
		void executeForm(AForm const &form) const;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bc);

#endif