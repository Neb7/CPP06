/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:43:01 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/16 13:34:49 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


//Use statuc_cast cause it's for explicit (but safe) conversion between 
//compatible types

/**
 * @brief	Default constructor for ScalarConverter.
 */
ScalarConverter::ScalarConverter()
{}

/**
 * @brief	Copy constructor for ScalarConverter.
 * 
 * @param	origin The ScalarConverter object to copy from.
 */
ScalarConverter::ScalarConverter(ScalarConverter const &origin)
{
	(void)origin;
}

/**
 * @brief	Assignment operator for ScalarConverter.
 * 
 * @param	other The ScalarConverter object to assign from.
 * @return	A reference to the current object.
 */
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	if (this != &other)
	{}
	return (*this);
}

/**
 * @brief	Destructor for ScalarConverter.
 */
ScalarConverter::~ScalarConverter()
{}

/**
 * @brief	Prints the converted values of a character.
 * 
 * @param	c The character to convert and print.
 */
void	ScalarConverter::printChar(char c)
{
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(c) << std::endl
				<< "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(c) << "f" << std::endl
				<< "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(c) << std::endl;
	return ;
}

/**
 * @brief	Prints the converted values of an integer.
 * 
 * @param	i The integer to convert and print.
 */
void	ScalarConverter::printInt(long int i)
{
	if (i < 0 || i > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		if (isprint(static_cast<char>(i)))
		{
			std::cout << "char: '" << static_cast<char>(i)
					  << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl
			  << "float: " << std::fixed << std::setprecision(1)
			  << static_cast<float>(i) << "f" << std::endl
			  << "double: " << std::fixed << std::setprecision(1)
			  << static_cast<double>(i) << std::endl;
	return ;
}

/**
 * @brief	Prints the converted values of a float.
 * 
 * @param	f The float to convert and print.
 */
void	ScalarConverter::printFloat(float f)
{
	if (static_cast<int>(f) < 0 || static_cast<int>(f) > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		if (isprint(static_cast<char>(static_cast<int>(f))))
		{
			std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(f) << std::endl
			  << "float: " << std::fixed << std::setprecision(1)
			  << f << "f" << std::endl << "double: " << std::fixed
			  << static_cast<double>(f) << std::endl;
	return ;
}

/**
 * @brief	Prints the converted values of a double.
 * 
 * @param	d The double to convert and print.
 */
void	ScalarConverter::printDouble(double d)
{
	if (static_cast<int>(d) < 0 || static_cast<int>(d) > 127)
	{
		std::cout << "char: impossible" << std::endl;
	}
	else
	{
		if (isprint(static_cast<char>(static_cast<int>(d))))
		{
			std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
		}
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(d) << std::endl
			  << "float: "<< std::fixed << std::setprecision(1)
			  << static_cast<float>(d) << "f" << std::endl << "double: " 
			  << std::fixed << std::setprecision(1) << d << std::endl;
	return ;
}

/**
 * @brief	Converts a string to various scalar types and prints the results.
 * 
 * @param	s The string to convert.
 */
void	ScalarConverter::convert(std::string const &s)
{
	char	*end;

	if (s == "nan" || s == "nanf")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << "nanf" << std::endl
				  << "double: " << "nan" << std::endl;
		return ;
	}
	
	if (s == "inf" || s == "inff" || s == "+inf" || s == "+inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << "+inff" << std::endl
				  << "double: " << "+inf" << std::endl;
		return ;
	}
	
	if (s == "-inf" || s == "-inff")
	{
		std::cout << "char: impossible" << std::endl
				  << "int: impossible" << std::endl
				  << "float: " << "-inff" << std::endl
				  << "double: " << "-inf" << std::endl;
		return ;
	}
	
	if (s.length() == 1)
	{
		if (s[0] >= '0' && s[0] <= '9')
			return (printChar(static_cast<char>(s[0] - '0')));
		else
			return (printChar(static_cast<char>(s[0])));
	}

	long int	tmp = std::strtol(s.c_str(), &end, 10);
	if ((*end == '\0' && tmp >= INT_MIN && tmp <= INT_MAX)
		&& errno != ERANGE)
	{
		return (printInt(tmp));
	}

	errno = 0;
	float	ftmp = std::strtof(s.c_str(), &end);
	if ((*end == 'f' || *end == 'F') && *(end + 1) == '\0' && errno != ERANGE)
	{
		return (printFloat(ftmp));
	}

	errno = 0;
	double	dtmp = std::strtod(s.c_str(), &end);
	if (*end == '\0' && errno != ERANGE)
	{
		return (printDouble(dtmp));
	}
	
	std::cout << "char: impossible" << std::endl
			  << "int: impossible" << std::endl
			  << "float: impossible" << std::endl
			  << "double: impossible" << std::endl;
}