/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:49:48 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/03 16:49:49 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main() {

    Array<int> intArray;
    std::cout << "Size (default): " << intArray.size() << std::endl;
    try
    {
        std::cout << "Value : " << intArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    Array<float> floatArray(10);
    std::cout << "Size (10): " << floatArray.size() << std::endl;
    for (int i = 0; i < 10; i ++)
        std::cout << "Value " << i << " : " << floatArray[i] << std::endl;

    try
    {
        floatArray[5] = 4.2f;
        std::cout << "floatArray[5]: " << floatArray[5] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "--- Access out of range ---\n" << floatArray[10] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    Array<float> copiedArray = floatArray;
    copiedArray[5] = 3.1415f;

    std::cout << "floatArray[5]: " << floatArray[5] << std::endl;
    std::cout << "copiedArray[5]: " << copiedArray[5] << std::endl;

    Array<float> copiedArray2;
    copiedArray2 = copiedArray;
    copiedArray2[5] = 2.19f;

    std::cout << "copiedArray[5]: " << copiedArray[5] << std::endl;
    std::cout << "copiedArray2[5]: " << copiedArray2[5] << std::endl;

    return 0;
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }