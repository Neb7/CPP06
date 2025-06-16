/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:42:50 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/10 14:19:30 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/**
 * @brief	Default constructor for Data.
 */
Data::Data() : id(0), name("default")
{}

/**
 * @brief	Constructor for Data with parameters.
 * 
 * @param id	An integer ID for the data.
 * @param name	A string name for the data.
 */
Data::Data(int id, std::string name) : id(id), name(name)
{}

/**
 * @brief	Copy constructor for Data.
 * 
 * @param	origin The Data object to copy from.
 */
Data::Data(const Data &origin)
{
	this->id = origin.id;
	this->name = origin.name;
}

/**
 * @brief	Assignment operator for Data.
 * 
 * @param	other The Data object to assign from.
 * @return	A reference to this Data object.
 */
Data	&Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->name = other.name;
	}
	return (*this);
}

/**
 * @brief	Destructor for Data.
 */
Data::~Data()
{}
