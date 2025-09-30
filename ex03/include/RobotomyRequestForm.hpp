/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:18:32 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/30 12:23:04 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <string>
# include "./AForm.hpp"

class RobotomyRequestForm: public AForm {
	private:
		static const int _requiredGradeToSign = 72;
		static const int _requiredGradeToExec = 45;
		std::string _target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		RobotomyRequestForm(const std::string &target);
		virtual void execute(Bureaucrat const &executor) const;
};

#endif
