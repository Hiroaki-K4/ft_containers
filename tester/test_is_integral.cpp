/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is_integral.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:38:09 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/05 08:52:17 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_is_integral.hpp"

template <unsigned n>
struct factorial : ft::integral_constant<int, n * factorial<n - 1>::value> {};

template <>
struct factorial<0> : ft::integral_constant<int, 1> {};

void test_is_integral()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "~~~ TEST is_integral ~~~" << std::endl;

    std::cout << "[integral_constant test]" << std::endl;
    std::cout << factorial<5>::value << std::endl;
    std::cout << std::endl;

    std::cout << "[is_integral test]" << std::endl;
    std::cout << "char: " << ft::is_integral<char>::value << std::endl;
    std::cout << "int: " << ft::is_integral<int>::value << std::endl;
    std::cout << "float: " << ft::is_integral<float>::value << std::endl;
    if (ft::is_integral<int>())
        std::cout << "int is an integral type" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
