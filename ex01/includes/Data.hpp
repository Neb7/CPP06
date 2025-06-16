/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:40:55 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/10 14:18:31 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DATA_HPP
# define DATA_HPP

# include <string>

/**
 * @brief	A simple struct to represent data with an ID and a name.
 */
struct Data
{
	int			id;
	std::string	name;

	Data();
	Data(int id, std::string name);
	Data(const Data &origin);
	Data	&operator=(const Data &other);
	~Data();
};

#endif
