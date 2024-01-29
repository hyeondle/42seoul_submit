/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:41:30 by Linsio            #+#    #+#             */
/*   Updated: 2024/01/13 09:53:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	BitcoinExchange exchange;
	if (argc == 2)
		exchange = BitcoinExchange(argv[1]);
	exchange.start();
}
// txt파일 = value가 내가 들고있는 비트코인의 개수
// csv파일 = 해당 날짜의 비트코인 시세
// 결국 둘 다 곱해서 나와야함