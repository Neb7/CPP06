/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:50:36 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/16 13:44:56 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"

int main()
{
	Data data(42, "example");
	std::cout << "Original Data: id: " << data.id
			  << ", name: '" << data.name << "' and ptr : " << &data << "'"
			  << std::endl;

	uintptr_t serialized = Serialize::serialize(&data);
	std::cout << "Serialized Data: " << serialized << " and in hexa : 0x"
			  << std::hex << serialized << std::dec << std::endl;

	Data *deserialized = Serialize::deserialize(serialized);
	std::cout << "Deserialized Data: id: " << deserialized->id
			  << ", name: '" << deserialized->name << "' and ptr : "
			  << &data << "'" << std::endl;

	return 0;
}
