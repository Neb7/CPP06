/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:29:25 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/16 13:41:17 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

//Use reinterpret_cast to convert between pointer types and uintptr_t

/**
 * @brief	Default constructor for Serialize.
 */
Serialize::Serialize()
{}

/**
 * @brief	Copy constructor for Serialize.
 * 
 * @param	origin The Serialize object to copy from.
 */
Serialize::Serialize(Serialize const &origin)
{
	(void)origin;
}

/**
 * @brief	Assignment operator for Serialize.
 * 
 * @param	other The Serialize object to assign from.
 * @return	A reference to this Serialize object.
 */
Serialize	&Serialize::operator=(Serialize const &other)
{
	if (this != &other)
	{}
	return (*this);
}

/**
 * @brief	Destructor for Serialize.
 */
Serialize::~Serialize()
{}

/**
 * @brief	Serializes a Data pointer to a uintptr_t.
 * 
 * @param ptr A pointer to the Data object to serialize.
 * @return A uintptr_t representation of the Data pointer.
 */
uintptr_t	Serialize::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * @brief	Deserializes a uintptr_t back to a Data pointer.
 * 
 * @param raw A uintptr_t representation of the Data pointer.
 * @return A pointer to the Data object.
 */
Data	*Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
