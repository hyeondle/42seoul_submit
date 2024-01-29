/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:09 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/26 17:28:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern();
private:
    typedef AForm* (*FormCreatorFunc)(const std::string& target);
    struct FormEntry {
        const char* formName;
        FormCreatorFunc creatorFunc;
    };
    static FormEntry formEntries[];
public:
    AForm* makeForm(const std::string& formName, const std::string& target);
    static AForm* createShrubbery(const std::string& target);
    static AForm* createRobotomy(const std::string& target);
    static AForm* createPresidential(const std::string& target);
};

#endif