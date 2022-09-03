/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_enable_if.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:34:50 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/03 21:56:59 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_enable_if.hpp"

template <class T>
typename ft::enable_if<ft::is_integral<T>::value, bool>::type is_odd(T i)
{
    return bool(i % 2);
}

template <class T, class = typename ft::enable_if<ft::is_integral<T>::value>::type> bool is_even (T i)
{
    return !bool(i % 2);
}

void test_enable_if()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "~~~ TEST enable_if ~~~" << std::endl;

    short int i = 1;
    std::cout << i << " is odd: " << is_odd(i) << std::endl;
    std::cout << i << " is even: " << is_even(i) << std::endl;
}
