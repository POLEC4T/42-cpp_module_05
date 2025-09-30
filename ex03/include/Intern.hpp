/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:46:41 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/30 12:22:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <iostream>
# include <exception>
# include "./AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &copy);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm* makeForm(const std::string &formName, const std::string &target) const;

		class FormDontExistException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif