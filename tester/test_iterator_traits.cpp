/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_traits.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:34:50 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/04 12:07:02 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_iterator_traits.hpp"

void test_iterator_traits()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "~~~ TEST iterator_traits ~~~" << std::endl;
    typedef std::iterator_traits<int*> traits;
    if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
        std::cout << "int* is a random-access iterator";
    std::cout << std::endl;
}
