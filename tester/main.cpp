/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/08/21 21:46:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

int main(void)
{
    std::cout << "~~~ TEST vector ~~~" << std::endl;

    std::cout << "constructor test" << std::endl;
    ft::vector<int> first;
    for (size_t i = 0; i < first.size(); i++)
        std::cout << first[i] << " ";
    std::cout << std::endl;

    ft::vector<int> second(4, 100);
    for (size_t i = 0; i < second.size(); i++)
        std::cout << second[i] << " ";
    std::cout << std::endl;

    ft::vector<int> third(second.begin(), second.end());
    for (size_t i = 0; i < third.size(); i++)
        std::cout << third[i] << " ";
    std::cout << std::endl;

    ft::vector<int> fourth(third);
    for (size_t i = 0; i < fourth.size(); i++)
        std::cout << fourth[i] << " ";
    std::cout << std::endl;

    int myints[] = {16,2,77,29};
    ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << std::endl;
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

    std::cout << std::endl;
    std::cout << "v1 insert test" << " size: " << v_1.size() << " capacity: " << v_1.capacity() << std::endl;
    v_1.insert(v_1.begin(), 200);
    v_1.insert(v_1.end(), 300);
    v_1.insert(v_1.begin(), 400);
    v_1.insert(v_1.begin(), 500);
    v_1.insert(v_1.end(), 600);
    v_1.insert(v_1.begin(), 700);
    v_1.insert(v_1.end(), 4, 700);
    for (size_t i = 0; i < v_1.size(); i++)
        std::cout << v_1[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "v1 insert iterator test" << std::endl;
    int arr[] = {501, 502, 503};
    std::cout << "v1_size: " << v_1.size() << std::endl;
    v_1.insert(v_1.begin(), arr, arr + 3);
    std::cout << "v1_size: " << v_1.size() << std::endl;
    for (size_t i = 0; i < v_1.size(); i++)
        std::cout << v_1[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "erase test" << std::endl;
    ft::vector<int> erase_test;
    for (int i = 1; i <= 10; i++)
        erase_test.push_back(i);
    erase_test.erase(erase_test.begin() + 5);
    erase_test.erase(erase_test.begin(), erase_test.begin() + 3);
    for (unsigned i = 0; i < erase_test.size(); ++i)
        std::cout << erase_test[i] << " ";
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "resize() test" << std::endl;
    ft::vector<int> resize_test;
    for (int i=1;i<10;i++)
        resize_test.push_back(i);
    resize_test.resize(5);
    resize_test.resize(8,100);
    resize_test.resize(12);
    for (size_t i = 0; i < resize_test.size(); i++)
        std::cout << resize_test[i] << " ";
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
