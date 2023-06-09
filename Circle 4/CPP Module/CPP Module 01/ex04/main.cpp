/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:45:11 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/24 11:26:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void replaceFileString(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inputFile(filename);
    if (!inputFile)
    {
        std::cout << "Failed to open input file: " << filename << std::endl;
        return;
    }

    std::string fileContents;
    std::string line;
    while (std::getline(inputFile, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        fileContents += line;
		if (!inputFile.eof())
            fileContents += "\n";
    }
    inputFile.close();

    std::ofstream outputFile(filename + ".replace");
    if (!outputFile)
    {
        std::cout << "Failed to create output file: " << filename << ".replace" << std::endl;
        return;
    }
    outputFile << fileContents;
    outputFile.close();

    std::cout << "Replacement completed. Modified content written to " << filename << ".replace" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		if (argc < 4)
			std::cout << "Usage : <filename> <s1> <s2>" << std::endl;
		std::cout << "Unexpected inputs" << std::endl;
		return (0);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.compare("") == 0)
	{
		int i = 0;
		std::cout << "Input s1 as \"\" could occur infinite loop : press 1 to continue" << std::endl;
		std::cin >> i;
		if (i != 1)
			return 0;
	}

	replaceFileString(filename, s1, s2);
}