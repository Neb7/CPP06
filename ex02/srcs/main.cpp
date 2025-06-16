/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:04:42 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 17:19:12 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.hpp"

int main()
{
	int N = 10;
	Base *base[N];
	for (int i = 0; i < N; ++i)
	{
		base[i] = generate();
		if (!base[i])
		{
			std::cerr << "Failed to generate object." << std::endl;
			for(int j = 0; j < i; ++j)
				delete base[j];
			return 1;
		}
		std::cout << "Generated object of type: using pointer: ";
		identify(base[i]);
		std::cout << "Identifying using reference: ";
		identify(*base[i]);
		std::cout << std::endl;
	}
	for (int i = 0; i < N; ++i)
	{
		delete base[i];
	}
	Base *noh = new Base();
	std::cout << "Identifying unknown type using pointer: ";
	identify(noh);
	std::cout << "Identifying unknown type using reference: ";
	identify(*noh);
	delete noh;
	return 0;
} 
