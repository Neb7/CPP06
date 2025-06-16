/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:30:43 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/10 14:18:38 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include "Data.hpp"
# include <iostream>
# include <cstddef>

// For uintptr_t
# include <stdint.h>

/**
 * @brief	A class to serialize and deserialize Data pointers to uintptr_t.
 * 
 * This class provides static methods to convert a pointer to a Data object
 * into a uintptr_t and back, allowing for easy serialization and deserialization.
 */
class Serialize
{
	private:
		Serialize();
		Serialize(Serialize const &origin);
		Serialize			&operator=(Serialize const &other);
		~Serialize();

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif