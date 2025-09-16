/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:18:32 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 12:41:46 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <string>
# include <fstream>
# include "./AForm.hpp"
# define ASCIITREE "   _-_\n  /~~   ~~\\\n /~~     ~~\\\n{           }\n \\  _- _  /\n   ~  \\/  ~\n_- -   |   _- _\n  _ -  |  -_\n      // \\\n"

class ShrubberyCreationForm: public AForm {
	private:
		static const int _requiredGradeToSign = 145;
		static const int _requiredGradeToExec = 137;
		std::string _target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const std::string &target);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif
