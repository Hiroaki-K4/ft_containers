/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/07/18 21:18:11 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"


int main(void) {
    std::cout << "~~~ TEST vector ~~~" << std::endl;

    std::cout << "[v1 test]" << std::endl;
    ft::vector<int> v_1;
    std::cout << "v1 size(): " << v_1.size() << std::endl;
    std::cout << "v1 empty(): " << v_1.empty() << std::endl;
    v_1.push_back(1);
    std::cout << "v1 push_back(1)" << std::endl;
    std::cout << "v1 size(): " << v_1.size() << std::endl;
    std::cout << "v1 empty(): " << v_1.empty() << std::endl;
    std::cout << "vec1: " << v_1[0] << std::endl;
    std::cout << std::endl;

    std::cout << "[v2 test]" << std::endl;
    ft::vector<int> v_2(100);
    std::cout << "vec2: " << v_2[0] << std::endl;
    std::cout << std::endl;

    std::cout << "[v3 test]" << std::endl;
    ft::vector<int> v_3(100, 1);
    std::cout << std::endl;

    std::cout << "[v4 test]" << std::endl;
    ft::vector<int> v_4(v_2.begin(), v_2.end());
    std::cout << std::endl;

    std::cout << "[v5 test]" << std::endl;
    ft::vector<int> v_5(v_3);
    std::cout << std::endl;

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
