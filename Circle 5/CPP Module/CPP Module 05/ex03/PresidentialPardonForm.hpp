/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:12 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/26 17:28:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
        ~PresidentialPardonForm();
    private:
        const std::string target;
    public:
        PresidentialPardonForm(std::string target);
        void execute(Bureaucrat const & executor) const;
};

#endif