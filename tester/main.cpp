/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/08/28 22:38:51 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test_vector.hpp"
#include "test_enable_if.hpp"
#include "test_is_integral.hpp"

int main(void)
{
    test_vector();
    std::cout << "TEST map" << std::endl;
    std::cout << "TEST stack" << std::endl;
    std::cout << "TEST iterators_traits" << std::endl;
    std::cout << "TEST reverse_iterator" << std::endl;
    test_enable_if();
    test_is_integral();
    std::cout << "TEST equal and/or lexicographical_compare" << std::endl;
    std::cout << "TEST std::pair" << std::endl;
    std::cout << "TEST std::make_pair" << std::endl;

    return (0);
}
