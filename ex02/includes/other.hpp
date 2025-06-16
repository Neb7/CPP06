/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:57:14 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 17:00:56 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef OTHER_HPP
# define OTHER_HPP

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <cstdlib>
# include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
