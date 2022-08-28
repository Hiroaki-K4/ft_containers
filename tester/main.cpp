/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/08/28 11:39:04 by hkubo            ###   ########.fr       */
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
    std::cout << "operator= test" << std::endl;
    ft::vector<int> foo(3, 0);
    ft::vector<int> bar(5, 0);
    bar = foo;
    foo = ft::vector<int>();
    std::cout << "Size of foo: " << int(foo.size()) << std::endl;
    std::cout << "Size of bar: " << int(bar.size()) << std::endl;

    std::cout << std::endl;
    std::cout << "operator[] test" << std::endl;
    ft::vector<int> op_test(10);
    ft::vector<int>::size_type sz = op_test.size();
    for (unsigned i = 0; i < sz; i++)
        op_test[i]=i;

    for (unsigned i = 0; i < sz / 2; i++)
    {
        int temp;
        temp = op_test[sz - 1 - i];
        op_test[sz - 1 - i] = op_test[i];
        op_test[i] = temp;
    }

    for (unsigned i = 0; i < sz; i++)
        std::cout << ' ' << op_test[i];
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

    std::cout << std::endl;
    std::cout << "at test" << std::endl;
    ft::vector<int> at_test(10);
    for (unsigned i = 0; i < at_test.size(); i++)
        at_test.at(i)=i;
    std::cout << "at_test contains:";
    for (unsigned i = 0; i < at_test.size(); i++)
        std::cout << ' ' << at_test.at(i);
    std::cout << std::endl;
    try {
        std::cout << "Access 10th factor"  << std::endl;
        std::cout << at_test.at(10) << std::endl;
    }
    catch (const std::out_of_range& le) {
        std::cerr << "[Error] " << le.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "back test" << std::endl;
    ft::vector<int> back_test;
    back_test.push_back(10);
    while (back_test.back() != 0)
    {
        back_test.push_back(back_test.back() - 1);
    }
    std::cout << "back_test contains:";
    for (unsigned i = 0; i < back_test.size() ; i++)
        std::cout << ' ' << back_test[i];
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "front test" << std::endl;
    ft::vector<int> front_test;
    front_test.push_back(78);
    front_test.push_back(16);
    front_test.front() -= front_test.back();
    std::cout << "front_test.front() is now " << front_test.front() << std::endl;

    std::cout << std::endl;
    std::cout << "assign test" << std::endl;
    ft::vector<int> assign1;
    ft::vector<int> assign2;
    ft::vector<int> assign3;

    assign1.assign(7, 100);
    ft::vector<int>::iterator it;
    it = assign1.begin() + 1;

    assign2.assign(it, assign1.end()-1);

    int assign_ints[] = {1776, 7, 4};
    assign3.assign(assign_ints, assign_ints + 3);

    std::cout << "Size of assign1: " << int(assign1.size()) << std::endl;
    std::cout << "Size of assign2: " << int (assign2.size()) << std::endl;
    std::cout << "Size of assign3: " << int (assign3.size()) << std::endl;

    {
        std::cout << std::endl;
        std::cout << "rbegin test" << std::endl;
        ft::vector<int> rbegin_test(5);
        int i = 0;
        ft::vector<int>::reverse_iterator rit = rbegin_test.rbegin();
        for (; rit!= rbegin_test.rend(); ++rit)
            *rit = ++i;
        std::cout << "rbegin_test contains:";
        for (ft::vector<int>::iterator it = rbegin_test.begin(); it != rbegin_test.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "rend test" << std::endl;
        ft::vector<int> rend_test(5);
        ft::vector<int>::reverse_iterator rit = rend_test.rbegin();
        int i = 0;
        for (rit = rend_test.rbegin(); rit!= rend_test.rend(); ++rit)
            *rit = ++i;
        std::cout << "rend_test contains:";
        for (ft::vector<int>::iterator it = rend_test.begin(); it != rend_test.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "pop_back test" << std::endl;
        ft::vector<int> pop_test;
        int sum(0);
        pop_test.push_back(100);
        pop_test.push_back(200);
        pop_test.push_back(300);
        while (!pop_test.empty())
        {
            sum += pop_test.back();
            pop_test.pop_back();
        }
        std::cout << "The elements of pop_test add up to " << sum << std::endl;
        std::cout << "Size: " << pop_test.size() << std::endl;
        std::cout << std::endl;
    }

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
