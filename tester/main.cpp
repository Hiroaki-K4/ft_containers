/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/07/16 22:38:30 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"


int main(void) {
    std::cout << "TEST vector" << std::endl;
    ft::vector<int> v_1;
    ft::vector<int> v_2(100);
    ft::vector<int> v_3(100, 1);
    ft::vector<int> v_4(v_2.begin(), v_2.end());
    ft::vector<int> v_5(v_3);

    std::cout << "TEST map" << std::endl;
    std::cout << "TEST stack" << std::endl;
    std::cout << "TEST iterators_traits" << std::endl;
    std::cout << "TEST reverse_iterator" << std::endl;
    std::cout << "TEST enable_if" << std::endl;
    std::cout << "TEST is_integral" << std::endl;
    std::cout << "TEST equal and/or lexicographical_compare" << std::endl;
    std::cout << "TEST std::pair" << std::endl;
    std::cout << "TEST std::make_pair" << std::endl;

    return (0);
}
