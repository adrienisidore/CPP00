/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisidore <aisidore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:58:05 by aisidore          #+#    #+#             */
/*   Updated: 2025/04/29 19:00:48 by aisidore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    std::string input;

    std::cout << "Enter something: ";
    std::getline(std::cin, input); // ignore uniquement les espaces en début

    if (input.empty()) {
        std::cout << "Error: input is empty." << std::endl;
    } else {
        std::cout << "You entered: \"" << input << "\"" << std::endl;
    }

    return 0;
}


