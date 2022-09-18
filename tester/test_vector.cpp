/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:30:35 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/18 22:35:50 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_vector.hpp"

void test_constructor()
{
    std::cout << "[constructor test]" << std::endl;
    std::vector<int> first;
    ft::vector<int> ft_first;
    for (size_t i = 0; i < ft_first.size(); i++)
        std::cout << ft_first[i] << " ";
    if (!std::equal(first.begin(), first.end(), ft_first.begin()))
        error_process("constructor test failed!!");
    std::cout << std::endl;

    std::vector<int> second(4, 100);
    ft::vector<int> ft_second(4, 100);
    for (size_t i = 0; i < ft_second.size(); i++)
        std::cout << ft_second[i] << " ";
    if (!std::equal(second.begin(), second.end(), ft_second.begin()))
        error_process("constructor test failed!!");
    std::cout << std::endl;

    std::vector<int> third(second.begin(), second.end());
    ft::vector<int> ft_third(ft_second.begin(), ft_second.end());
    for (size_t i = 0; i < ft_third.size(); i++)
        std::cout << ft_third[i] << " ";
    if (!std::equal(third.begin(), third.end(), ft_third.begin()))
        error_process("constructor test failed!!");
    std::cout << std::endl;

    std::vector<int> fourth(third);
    ft::vector<int> ft_fourth(ft_third);
    for (size_t i = 0; i < ft_fourth.size(); i++)
        std::cout << ft_fourth[i] << " ";
    if (!std::equal(fourth.begin(), fourth.end(), ft_fourth.begin()))
        error_process("constructor test failed!!");
    std::cout << std::endl;

    int myints[] = {16,2,77,29};
    std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    ft::vector<int> ft_fifth(myints, myints + sizeof(myints) / sizeof(int));
    std::cout << "The contents of fifth are:";
    for (ft::vector<int>::iterator it = ft_fifth.begin(); it != ft_fifth.end(); ++it)
        std::cout << ' ' << *it;
    if (!std::equal(fifth.begin(), fifth.end(), ft_fifth.begin()))
        error_process("constructor test failed!!");
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_assign()
{
    std::cout << "[assign test]" << std::endl;
    std::vector<int> assign1;
    ft::vector<int> ft_assign1;
    std::vector<int> assign2;
    ft::vector<int> ft_assign2;
    std::vector<int> assign3;
    ft::vector<int> ft_assign3;

    assign1.assign(7, 100);
    ft_assign1.assign(7, 100);
    std::vector<int>::iterator it;
    ft::vector<int>::iterator ft_it;
    it = assign1.begin() + 1;
    ft_it = ft_assign1.begin() + 1;

    assign2.assign(it, assign1.end()-1);
    ft_assign2.assign(ft_it, ft_assign1.end()-1);

    int assign_ints[] = {1776, 7, 4};
    assign3.assign(assign_ints, assign_ints + 3);
    ft_assign3.assign(assign_ints, assign_ints + 3);

    std::cout << "Size of assign1: " << int(ft_assign1.size()) << std::endl;
    std::cout << "Size of assign2: " << int (ft_assign2.size()) << std::endl;
    std::cout << "Size of assign3: " << int (ft_assign3.size()) << std::endl;

    if (!std::equal(assign1.begin(), assign1.end(), ft_assign1.begin()) ||
        !std::equal(assign2.begin(), assign2.end(), ft_assign2.begin()) ||
        !std::equal(assign3.begin(), assign3.end(), ft_assign3.begin()))
        error_process("assign test failed!!");
    std::cout << std::endl;
}

void test_at()
{
    std::cout << "[at test]" << std::endl;
    std::vector<int> at_test(10);
    ft::vector<int> ft_at_test(10);

    for (unsigned i = 0; i < at_test.size(); i++)
        at_test.at(i) = i;
    for (unsigned i = 0; i < ft_at_test.size(); i++)
        ft_at_test.at(i) = i;

    std::cout << "at_test contains:";
    for (unsigned i = 0; i < at_test.size(); i++)
    {
        if (at_test.at(i) != ft_at_test.at(i))
            error_process("at test failed!!");
        std::cout << ' ' << ft_at_test.at(i);
    }
    std::cout << std::endl;
    try {
        std::cout << "Access 10th factor"  << std::endl;
        std::cout << ft_at_test.at(10) << std::endl;
    }
    catch (const std::out_of_range& le) {
        std::cerr << "[Error] " << le.what() << std::endl;
    }
    std::cout << std::endl;
}

void test_back()
{
    std::cout << "[back test]" << std::endl;
    std::vector<int> back_test;
    ft::vector<int> ft_back_test;

    back_test.push_back(10);
    ft_back_test.push_back(10);
    while (back_test.back() != 0)
    {
        back_test.push_back(back_test.back() - 1);
        ft_back_test.push_back(ft_back_test.back() - 1);
    }

    if (!std::equal(back_test.begin(), back_test.end(), ft_back_test.begin()))
        error_process("back test failed!!");

    std::cout << "back_test contains:";
    for (unsigned i = 0; i < ft_back_test.size() ; i++)
        std::cout << ' ' << ft_back_test[i];

    std::cout << std::endl;
    std::cout << std::endl;
}

void test_begin()
{
    std::cout << "[begin test]" << std::endl;
    std::vector<int> begin_test;
    ft::vector<int> ft_begin_test;

    for (int i = 1; i <= 5; i++)
    {
        begin_test.push_back(i);
        ft_begin_test.push_back(i);
    }

    if (*(begin_test.begin()) != *(ft_begin_test.begin()))
        error_process("begin test failed!!");

    std::cout << "begin_test contains:";
    for (ft::vector<int>::iterator it = ft_begin_test.begin(); it != ft_begin_test.end(); ++it)
        std::cout << ' ' << *it;

    std::cout << std::endl;
    std::cout << std::endl;
}

void test_capacity_and_max_size()
{
    std::cout << "[capacity and max_size test]" << std::endl;
    std::vector<int> cap_test;
    ft::vector<int> ft_cap_test;

    for (int i = 0; i < 100; i++)
    {
        cap_test.push_back(i);
        ft_cap_test.push_back(i);
    }

    if (cap_test.size() != ft_cap_test.size() ||
        cap_test.capacity() != ft_cap_test.capacity() ||
        cap_test.max_size() != ft_cap_test.max_size())
        error_process("capacity and max_size failed!!");

    std::cout << "size: " << (int)cap_test.size() << std::endl;
    std::cout << "capacity: " << (int)cap_test.capacity() << std::endl;
    std::cout << "max_size: " << cap_test.max_size() << std::endl;
    std::cout << std::endl;
}

void test_clear()
{
    std::cout << "[clear test]" << std::endl;
    std::vector<int> clear_test;
    ft::vector<int> ft_clear_test;
    clear_test.push_back(100);
    clear_test.push_back(200);
    clear_test.push_back(300);
    ft_clear_test.push_back(100);
    ft_clear_test.push_back(200);
    ft_clear_test.push_back(300);

    std::cout << "clear_test contains:";
    for (unsigned i = 0; i < ft_clear_test.size(); i++)
        std::cout << ' ' << ft_clear_test[i];
    std::cout << std::endl;

    clear_test.clear();
    clear_test.push_back(1101);
    clear_test.push_back(2202);
    ft_clear_test.clear();
    ft_clear_test.push_back(1101);
    ft_clear_test.push_back(2202);

    if (!std::equal(clear_test.begin(), clear_test.end(), ft_clear_test.begin()))
        error_process("clear test failed!!");

    std::cout << "clear_test contains:";
    for (unsigned i = 0; i < ft_clear_test.size(); i++)
        std::cout << ' ' << ft_clear_test[i];
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_empty()
{
    std::cout << "[empty test]" << std::endl;
    std::vector<int> empty_test;
    ft::vector<int> ft_empty_test;

    int sum = 0;
    int ft_sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        empty_test.push_back(i);
        ft_empty_test.push_back(i);
    }

    while (!empty_test.empty())
    {
        sum += empty_test.back();
        empty_test.pop_back();
    }
    while (!ft_empty_test.empty())
    {
        ft_sum += ft_empty_test.back();
        ft_empty_test.pop_back();
    }

    if (sum != ft_sum)
        error_process("empty test failed!!");

    std::cout << "total: " << ft_sum << std::endl;
    std::cout << std::endl;
}

void test_end()
{
    std::cout << "[end test]" << std::endl;
    std::vector<int> end_test;
    ft::vector<int> ft_end_test;

    for (int i = 1; i <= 5; i++)
    {
        end_test.push_back(i);
        ft_end_test.push_back(i);
    }

    if (*(end_test.end()) != *(ft_end_test.end()))
        error_process("end test failed!!");

    std::cout << "empty_test contains:";
    for (ft::vector<int>::iterator it = ft_end_test.begin(); it != ft_end_test.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_erase()
{
    std::cout << "[erase test]" << std::endl;
    std::vector<int> erase_test;
    ft::vector<int> ft_erase_test;

    for (int i = 1; i <= 10; i++)
    {
        erase_test.push_back(i);
        ft_erase_test.push_back(i);
    }

    erase_test.erase(erase_test.begin() + 5);
    erase_test.erase(erase_test.begin(), erase_test.begin() + 3);
    ft_erase_test.erase(ft_erase_test.begin() + 5);
    ft_erase_test.erase(ft_erase_test.begin(), ft_erase_test.begin() + 3);

    if (!std::equal(erase_test.begin(), erase_test.end(), ft_erase_test.begin()))
        error_process("erase test failed!!");

    for (unsigned i = 0; i < ft_erase_test.size(); ++i)
        std::cout << ft_erase_test[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_front()
{
    std::cout << "[front test]" << std::endl;
    std::vector<int> front_test;
    ft::vector<int> ft_front_test;

    front_test.push_back(78);
    front_test.push_back(16);
    front_test.front() -= front_test.back();
    ft_front_test.push_back(78);
    ft_front_test.push_back(16);
    ft_front_test.front() -= ft_front_test.back();

    if (front_test.front() != ft_front_test.front())
        error_process("front test failed!!");

    std::cout << "front_test.front() is now " << front_test.front() << std::endl;
    std::cout << std::endl;
}

void test_get_allocator()
{
    std::cout << "[get_allocator test]" << std::endl;
    std::vector<int> get_alloc_test;
    ft::vector<int> ft_get_alloc_test;
    int *p;
    int *ft_p;
    unsigned int i;

    p = get_alloc_test.get_allocator().allocate(5);
    ft_p = ft_get_alloc_test.get_allocator().allocate(5);
    for (i = 0; i < 5; i++)
    {
        get_alloc_test.get_allocator().construct(&p[i], i);
        ft_get_alloc_test.get_allocator().construct(&ft_p[i], i);
    }

    std::cout << "The allocated array contains:";
    for (i = 0; i < 5; i++)
        std::cout << ' ' << ft_p[i];
    std::cout << std::endl;

    for (i = 0; i < 5; i++)
    {
        get_alloc_test.get_allocator().destroy(&p[i]);
        ft_get_alloc_test.get_allocator().destroy(&ft_p[i]);
    }
    get_alloc_test.get_allocator().deallocate(p,5);
    ft_get_alloc_test.get_allocator().deallocate(ft_p,5);

    if (!std::equal(get_alloc_test.begin(), get_alloc_test.end(), ft_get_alloc_test.begin()) ||
        get_alloc_test.capacity() != ft_get_alloc_test.capacity())
        error_process("get_allocator test failed!!");
    std::cout << std::endl;
}

void test_insert()
{
    std::cout << "[insert test]" << std::endl;
    std::vector<int> vec_test(3,100);
    ft::vector<int> ft_vec_test(3,100);
    std::vector<int>::iterator it;
    ft::vector<int>::iterator ft_it;

    it = vec_test.begin();
    ft_it = ft_vec_test.begin();

    it = vec_test.insert(it, 200);
    ft_it = ft_vec_test.insert(ft_it, 200);

    vec_test.insert(it, 2, 300);
    ft_vec_test.insert(ft_it, 2, 300);

    it = vec_test.begin();
    ft_it = ft_vec_test.begin();

    std::vector<int> another_vec(2, 400);
    ft::vector<int> ft_another_vec(2, 400);
    vec_test.insert(it + 2, another_vec.begin(), another_vec.end());
    ft_vec_test.insert(ft_it + 2, ft_another_vec.begin(), ft_another_vec.end());
    int arr_test[] = {501, 502, 503};
    vec_test.insert(vec_test.begin(), arr_test, arr_test + 3);
    ft_vec_test.insert(ft_vec_test.begin(), arr_test, arr_test + 3);

    if (!std::equal(vec_test.begin(), vec_test.end(), ft_vec_test.begin()))
        error_process("insert test failed!!");

    std::cout << "vec_test contains:";
    for (ft_it = ft_vec_test.begin(); ft_it < ft_vec_test.end(); ft_it++)
        std::cout << ' ' << *ft_it;
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_operators()
{
    {
        std::cout << "[operator[] test]" << std::endl;
        std::vector<int> op_test(10);
        ft::vector<int> ft_op_test(10);

        ft::vector<int>::size_type sz = ft_op_test.size();
        for (unsigned i = 0; i < sz; i++)
        {
            op_test[i]=i;
            ft_op_test[i]=i;
        }

        for (unsigned i = 0; i < sz / 2; i++)
        {
            int temp;
            temp = op_test[sz - 1 - i];
            op_test[sz - 1 - i] = op_test[i];
            op_test[i] = temp;

            temp = ft_op_test[sz - 1 - i];
            ft_op_test[sz - 1 - i] = ft_op_test[i];
            ft_op_test[i] = temp;
        }

        if (!std::equal(op_test.begin(), op_test.end(), ft_op_test.begin()))
            error_process("operator[] test failed!!");

        for (unsigned i = 0; i < sz; i++)
            std::cout << ' ' << ft_op_test[i];
        std::cout << std::endl;
    }

    std::cout << std::endl;

    {
        std::cout << "[operator= test]" << std::endl;
        std::vector<int> foo(3, 0);
        std::vector<int> bar(5, 0);
        ft::vector<int> ft_foo(3, 0);
        ft::vector<int> ft_bar(5, 0);

        bar = foo;
        foo = std::vector<int>();
        ft_bar = ft_foo;
        ft_foo = ft::vector<int>();

        if (!std::equal(bar.begin(), bar.end(), ft_bar.begin()) || 
            !std::equal(foo.begin(), foo.end(), ft_foo.begin()))
            error_process("operator= test failed!!");

        std::cout << "Size of foo: " << int(foo.size()) << std::endl;
        std::cout << "Size of bar: " << int(bar.size()) << std::endl;
    }
    std::cout << std::endl;
}

void test_pop_back()
{
    std::cout << "[pop_back test]" << std::endl;
    std::vector<int> pop_test;
    ft::vector<int> ft_pop_test;
    int sum = 0;
    int ft_sum = 0;

    pop_test.push_back(100);
    pop_test.push_back(200);
    pop_test.push_back(300);
    ft_pop_test.push_back(100);
    ft_pop_test.push_back(200);
    ft_pop_test.push_back(300);

    while (!pop_test.empty())
    {
        sum += pop_test.back();
        pop_test.pop_back();
    }
    while (!ft_pop_test.empty())
    {
        ft_sum += ft_pop_test.back();
        ft_pop_test.pop_back();
    }

    if (!std::equal(pop_test.begin(), pop_test.end(), ft_pop_test.begin()) ||
        sum != ft_sum)
        error_process("pop_back test failed!!");

    std::cout << "The elements of pop_test add up to " << sum << std::endl;
    std::cout << "Size: " << pop_test.size() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_push_back(int manual_flag)
{
    std::cout << "[push_back test]" << std::endl;
    std::vector<int> push_test;
    ft::vector<int> ft_push_test;

    if (manual_flag == 1)
    {
        int myint;
        std::cout << "Please enter some integers (enter 0 to end):" << std::endl;

        do {
            std::cin >> myint;
            push_test.push_back(myint);
            ft_push_test.push_back(myint);
        } while (myint);
    }
    else
    {
        push_test.push_back(1);
        push_test.push_back(2);
        push_test.push_back(3);
        ft_push_test.push_back(1);
        ft_push_test.push_back(2);
        ft_push_test.push_back(3);
    }

    if (!std::equal(push_test.begin(), push_test.end(), ft_push_test.begin()))
        error_process("push_back test failed!!");

    std::cout << "push_test stores " << int(ft_push_test.size()) << " numbers." << std::endl;
    std::cout << std::endl;
}

void test_rbegin()
{
    std::cout << "[rbegin test]" << std::endl;
    std::vector<int> rbegin_test(5);
    ft::vector<int> ft_rbegin_test(5);

    int i = 0;
    std::vector<int>::reverse_iterator rit = rbegin_test.rbegin();
    for (; rit!= rbegin_test.rend(); ++rit)
        *rit = ++i;

    i = 0;
    ft::vector<int>::reverse_iterator ft_rit = ft_rbegin_test.rbegin();
    for (; ft_rit!= ft_rbegin_test.rend(); ++ft_rit)
        *ft_rit = ++i;

    if (!std::equal(rbegin_test.begin(), rbegin_test.end(), ft_rbegin_test.begin()))
        error_process("rbegin test failed!!");

    std::cout << "rbegin_test contains:";
    for (ft::vector<int>::iterator it = ft_rbegin_test.begin(); it != ft_rbegin_test.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_rend()
{
    std::cout << "[rend test]" << std::endl;
    std::vector<int> rend_test(5);
    ft::vector<int> ft_rend_test(5);

    std::vector<int>::reverse_iterator rit = rend_test.rbegin();
    int i = 0;
    for (rit = rend_test.rbegin(); rit!= rend_test.rend(); ++rit)
        *rit = ++i;

    ft::vector<int>::reverse_iterator ft_rit = ft_rend_test.rbegin();
    i = 0;
    for (ft_rit = ft_rend_test.rbegin(); ft_rit != ft_rend_test.rend(); ++ft_rit)
        *ft_rit = ++i;

    if (!std::equal(rend_test.begin(), rend_test.end(), ft_rend_test.begin()))
        error_process("rend test failed!!");

    std::cout << "rend_test contains:";
    for (ft::vector<int>::iterator it = ft_rend_test.begin(); it != ft_rend_test.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_reverse()
{
    std::cout << "[reserve test]" << std::endl;
    std::vector<int>::size_type sz;
    ft::vector<int>::size_type ft_sz;
    std::vector<int> foo;
    ft::vector<int> ft_foo;

    sz = foo.capacity();
    ft_sz = ft_foo.capacity();
    std::cout << "making foo grow:" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        foo.push_back(i);
        ft_foo.push_back(i);
        if (ft_sz != ft_foo.capacity())
        {
            sz = foo.capacity();
            ft_sz = ft_foo.capacity();
            if (sz != ft_sz)
                error_process("reserve test failed!!");
            std::cout << "capacity changed: " << ft_sz << std::endl;
        }
    }

    std::vector<int> bar;
    ft::vector<int> ft_bar;

    sz = bar.capacity();
    ft_sz = ft_bar.capacity();
    bar.reserve(100);
    ft_bar.reserve(100);
    std::cout << "making bar grow:" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        bar.push_back(i);
        ft_bar.push_back(i);
        if (ft_sz != ft_bar.capacity())
        {
            sz = bar.capacity();
            ft_sz = ft_bar.capacity();
            if (sz != ft_sz)
                error_process("reserve test failed!!");
            std::cout << "capacity changed: " << sz << std::endl;
        }
    }

    std::cout << std::endl;
}

void test_resize()
{
    std::cout << "[resize test]" << std::endl;
    std::vector<int> resize_test;
    ft::vector<int> ft_resize_test;

    for (int i = 1; i < 10; i++)
    {
        resize_test.push_back(i);
        ft_resize_test.push_back(i);
    }

    resize_test.resize(5);
    resize_test.resize(8,100);
    resize_test.resize(12);
    ft_resize_test.resize(5);
    ft_resize_test.resize(8,100);
    ft_resize_test.resize(12);

    if (!std::equal(resize_test.begin(), resize_test.end(), ft_resize_test.begin()))
        error_process("resize test failed!!");

    for (size_t i = 0; i < ft_resize_test.size(); i++)
        std::cout << ft_resize_test[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_size()
{
    std::cout << "[size test]" << std::endl;
    std::vector<int> size_test;
    ft::vector<int> ft_size_test;

    if (size_test.size() != ft_size_test.size())
        error_process("size test failed!!");
    std::cout << "0. size: " << ft_size_test.size() << std::endl;

    for (int i = 0; i < 10; i++)
    {
        size_test.push_back(i);
        ft_size_test.push_back(i);
    }
    if (size_test.size() != ft_size_test.size())
        error_process("size test failed!!");
    std::cout << "1. size: " << ft_size_test.size() << std::endl;

    size_test.insert(size_test.end(), 10, 100);
    ft_size_test.insert(ft_size_test.end(), 10, 100);
    if (size_test.size() != ft_size_test.size())
        error_process("size test failed!!");
    std::cout << "2. size: " << ft_size_test.size() << std::endl;

    size_test.pop_back();
    ft_size_test.pop_back();
    if (size_test.size() != ft_size_test.size())
        error_process("size test failed!!");
    std::cout << "3. size: " << ft_size_test.size() << std::endl;
    std::cout << std::endl;
}

void test_swap()
{
    std::cout << "[swap test]" << std::endl;
    std::vector<int> foo(3, 100);
    std::vector<int> bar(5, 200);
    ft::vector<int> ft_foo(3, 100);
    ft::vector<int> ft_bar(5, 200);

    foo.swap(bar);
    ft_foo.swap(ft_bar);

    if (!std::equal(foo.begin(), foo.end(), ft_foo.begin()) ||
        !std::equal(bar.begin(), bar.end(), ft_bar.begin()))
        error_process("swap test failed!!");

    std::cout << "foo contains:";
    for (unsigned i = 0; i < ft_foo.size(); i++)
        std::cout << ' ' << ft_foo[i];
    std::cout << std::endl;

    std::cout << "bar contains:";
    for (unsigned i = 0; i < ft_bar.size(); i++)
        std::cout << ' ' << ft_bar[i];
    std::cout << std::endl;
    std::cout << std::endl;
}

void test_relational_operators()
{
    std::cout << "[relational operators test]" << std::endl;
    std::vector<int> foo(3, 100);
    std::vector<int> bar(2, 200);
    ft::vector<int> ft_foo(3, 100);
    ft::vector<int> ft_bar(2, 200);

    if (foo == bar && ft_foo == ft_bar)
        std::cout << "foo and bar are equal" << std::endl;
    if (foo != bar && ft_foo != ft_bar)
        std::cout << "foo and bar are not equal" << std::endl;
    if (foo < bar && ft_foo < ft_bar)
        std::cout << "foo is less than bar" << std::endl;
    if (foo > bar && ft_foo > ft_bar)
        std::cout << "foo is greater than bar" << std::endl;
    if (foo <= bar && ft_foo <= ft_bar)
        std::cout << "foo is less than or equal to bar" << std::endl;
    if (foo >= bar && ft_foo >= ft_bar)
        std::cout << "foo is greater than or equal to bar" << std::endl;
    std::cout << std::endl;
}

void test_non_member_swap()
{
    std::cout << "[non-member swap test]" << std::endl;
    std::vector<int> foo(3, 100);
    std::vector<int> bar(5, 200);
    ft::vector<int> ft_foo(3, 100);
    ft::vector<int> ft_bar(5, 200);

    std::swap(foo, bar);
    swap(ft_foo, ft_bar);

    if (!std::equal(foo.begin(), foo.end(), ft_foo.begin()) ||
        !std::equal(bar.begin(), bar.end(), ft_bar.begin()))
        error_process("non-member swap test failed!!");

    std::cout << "foo contains:";
    for (ft::vector<int>::iterator it = ft_foo.begin(); it != ft_foo.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    std::cout << "bar contains:";
    for (ft::vector<int>::iterator it = ft_bar.begin(); it != ft_bar.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;
}

void test_vector(int manual_flag)
{
    std::cout << "~~~ TEST vector ~~~" << std::endl;

    test_constructor();
    test_assign();
    test_at();
    test_back();
    test_begin();
    test_capacity_and_max_size();
    test_clear();
    test_empty();
    test_end();
    test_erase();
    test_front();
    test_get_allocator();
    test_insert();
    test_operators();
    test_pop_back();
    test_push_back(manual_flag);
    test_rbegin();
    test_rend();
    test_reverse();
    test_resize();
    test_size();
    test_swap();
    test_relational_operators();
    test_non_member_swap();
}
