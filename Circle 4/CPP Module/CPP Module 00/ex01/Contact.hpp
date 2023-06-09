/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:30:32 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 17:02:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string contact[5];
	std::string infos[5];
	void wronginput(int n);
public:
	Contact();
	~Contact();
	void cadd(int i);
	void csearch(int n);
	void show(void);
	bool isprintable(std::string input);
};

#endif