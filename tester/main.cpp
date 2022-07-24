/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/07/24 22:50:22 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"


int main(void) {
    std::cout << "~~~ TEST vector ~~~" << std::endl;

    std::cout << "[v1 test]" << std::endl;
    ft::vector<int> v_1;
    try {
        std::cout << "v1 reserve(max_size() + 1)"  << std::endl;
        v_1.reserve(v_1.max_size() + 1);
    }
    catch (const std::length_error& le) {
        std::cerr << "Length error: " << le.what() << '\n';
    }
    std::cout << "v1 size(): " << v_1.size() << std::endl;
    std::cout << "v1 empty(): " << v_1.empty() << std::endl;
    v_1.push_back(1);
    std::cout << "v1 push_back(1)" << std::endl;
    std::cout << "v1 size(): " << v_1.size() << std::endl;
    std::cout << "v1 empty(): " << v_1.empty() << std::endl;
    std::cout << "vec1: " << v_1[0] << std::endl;
    v_1.clear();

    std::cout << "v1 insert test" << std::endl;
    v_1.insert(v_1.begin(), 200);
    v_1.insert (v_1.end(), 3, 300);
    int array[] = {501, 502, 503};
    v_1.insert(v_1.end(), array, array + 3);

    std::cout << "v1 resize() test" << std::endl;
    // v_1.resize(5);
    // v_1.resize(8,100);
    // v_1.resize(12);
    std::cout << "size: " << v_1.size() << std::endl;
    // for (size_t i = 0; i < v_1.size(); i++)
    for (size_t i = 0; i < 6; i++)
        std::cout << ' ' << v_1[i];
    std::cout << std::endl;

    // v_1.resize(3, 100);
    std::cout << "v1[0] v1[1] v1[2]: " << v_1[0] << " " << v_1[1] << " " << v_1[2] << std::endl;
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
