/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:31:38 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 14:24:28 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <stdexcept>
# include <climits>
# include <cerrno>
# include <iomanip>
# include <cstdlib> 

/**
 * @brief	ScalarConverter class for converting strings to various scalar types.
 */
class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &origin);
		ScalarConverter	&operator=(ScalarConverter const &other);
		~ScalarConverter();
		
		static void		printChar(char c);
		static void		printInt(long int i);
		static void		printFloat(float f);
		static void		printDouble(double d);

	public:
		static void		convert(std::string const &s);
};

#endif