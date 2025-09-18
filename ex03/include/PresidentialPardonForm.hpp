/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:18:32 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/16 12:41:51 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <string>
# include "./AForm.hpp"

class PresidentialPardonForm: public AForm {
	private:
		static const int _requiredGradeToSign = 25;
		static const int _requiredGradeToExec = 5;
		std::string _target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		PresidentialPardonForm(const std::string &target);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif
