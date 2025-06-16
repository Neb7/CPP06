/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:58:19 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/16 17:09:22 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "other.hpp"

// Use dynamic_cast to safely downcast pointers and references in C++

/**
 * @brief	Generates a "random" Base-derived object.
 * 
 * @return	A pointer to a Base object, which can be of type A, B, or C.
 */
Base	*generate(void)
{
	Base *ptr = NULL;

	switch (rand() % 3)
	{
		case 0:
			ptr = new A();
			break;
		case 1:
			ptr = new B();
			break;
		case 2:
			ptr = new C();
			break;
		default:
			break;
	}
	return (ptr);
}

/**
 * @brief	Identifies the type of a Base pointer using dynamic_cast.
 * 
 * @param	p A pointer to a Base object.
 */
void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Type: C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

/**
 * @brief	Identifies the type of a Base reference using dynamic_cast.
 * 
 * @param	p A reference to a Base object.
 */
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Type: A" << std::endl;
		return ;
	}
	catch (...)
	{}
	
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Type: B" << std::endl;
		return ;
	}
	catch (...)
	{}
	
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Type: C" << std::endl;
		return ;
	}
	catch (...)
	{}
	std::cout << "Unknown type" << std::endl;
}
