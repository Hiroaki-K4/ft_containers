/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/08/28 21:41:41 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"

int main(void)
{
    std::cout << "~~~ TEST vector ~~~" << std::endl;

    {
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
    }

    {
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
    }

    {
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
    }

    {
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
    }

    {
        std::cout << std::endl;
        std::cout << "begin test" << std::endl;
        ft::vector<int> begin_test;
        for (int i = 1; i <= 5; i++)
            begin_test.push_back(i);

        std::cout << "begin_test contains:";
        for (ft::vector<int>::iterator it = begin_test.begin(); it != begin_test.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "capacity and max_size test" << std::endl;
        ft::vector<int> cap_test;
        for (int i = 0; i < 100; i++)
            cap_test.push_back(i);
        std::cout << "size: " << (int)cap_test.size() << std::endl;
        std::cout << "capacity: " << (int)cap_test.capacity() << std::endl;
        std::cout << "max_size: " << cap_test.max_size() << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "clear test" << std::endl;
        ft::vector<int> clear_test;
        clear_test.push_back(100);
        clear_test.push_back(200);
        clear_test.push_back(300);

        std::cout << "clear_test contains:";
        for (unsigned i = 0; i < clear_test.size(); i++)
            std::cout << ' ' << clear_test[i];
        std::cout << std::endl;

        clear_test.clear();
        clear_test.push_back(1101);
        clear_test.push_back(2202);

        std::cout << "clear_test contains:";
        for (unsigned i = 0; i < clear_test.size(); i++)
            std::cout << ' ' << clear_test[i];
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "empty test" << std::endl;
        ft::vector<int> empty_test;
        int sum (0);
        for (int i = 1; i <= 10; i++) empty_test.push_back(i);
        while (!empty_test.empty())
        {
            sum += empty_test.back();
            empty_test.pop_back();
        }
        std::cout << "total: " << sum << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "empty test" << std::endl;
        ft::vector<int> empty_test;
        for (int i = 1; i <= 5; i++)
            empty_test.push_back(i);
        std::cout << "empty_test contains:";
        for (ft::vector<int>::iterator it = empty_test.begin(); it != empty_test.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    {
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
    }

    {
        std::cout << std::endl;
        std::cout << "front test" << std::endl;
        ft::vector<int> front_test;
        front_test.push_back(78);
        front_test.push_back(16);
        front_test.front() -= front_test.back();
        std::cout << "front_test.front() is now " << front_test.front() << std::endl;
    }

    {
        std::cout << "get_allocator test" << std::endl;
        ft::vector<int> get_alloc_test;
        int *p;
        unsigned int i;

        p = get_alloc_test.get_allocator().allocate(5);
        for (i = 0; i < 5; i++)
            get_alloc_test.get_allocator().construct(&p[i], i);

        std::cout << "The allocated array contains:";
        for (i = 0; i < 5; i++)
            std::cout << ' ' << p[i];
        std::cout << std::endl;

        for (i = 0; i < 5; i++)
            get_alloc_test.get_allocator().destroy(&p[i]);
        get_alloc_test.get_allocator().deallocate(p,5);
    }

    {
        std::cout << std::endl;
        std::cout << "insert test" << std::endl;
        ft::vector<int> vec_test(3,100);
        ft::vector<int>::iterator it;

        it = vec_test.begin();
        it = vec_test.insert(it, 200);
        vec_test.insert(it, 2, 300);
        it = vec_test.begin();
        ft::vector<int> another_vec(2, 400);
        vec_test.insert(it + 2,another_vec.begin(), another_vec.end());
        int arr_test[] = {501, 502, 503};
        vec_test.insert(vec_test.begin(), arr_test, arr_test + 3);

        std::cout << "vec_test contains:";
        for (it = vec_test.begin(); it < vec_test.end(); it++)
            std::cout << ' ' << *it;
        std::cout << std::endl;
    }

    {
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
    }

    {
        std::cout << std::endl;
        std::cout << "operator= test" << std::endl;
        ft::vector<int> foo(3, 0);
        ft::vector<int> bar(5, 0);
        bar = foo;
        foo = ft::vector<int>();
        std::cout << "Size of foo: " << int(foo.size()) << std::endl;
        std::cout << "Size of bar: " << int(bar.size()) << std::endl;
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

    {
        std::cout << std::endl;
        std::cout << "push_back test" << std::endl;
        ft::vector<int> push_test;
        int myint;
        std::cout << "Please enter some integers (enter 0 to end):" << std::endl;

        do {
            std::cin >> myint;
            push_test.push_back(myint);
        } while (myint);

        std::cout << "push_test stores " << int(push_test.size()) << " numbers.\n";
    }

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
        std::cout << "reserve test" << std::endl;
        ft::vector<int>::size_type sz;
        ft::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:" << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            foo.push_back(i);
            if (sz != foo.capacity())
            {
                sz = foo.capacity();
                std::cout << "capacity changed: " << sz << std::endl;
            }
        }

        ft::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);
        std::cout << "making bar grow:" << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            bar.push_back(i);
            if (sz != bar.capacity())
            {
                sz = bar.capacity();
                std::cout << "capacity changed: " << sz << std::endl;
            }
        }
    }

    {
        std::cout << std::endl;
        std::cout << "resize test" << std::endl;
        ft::vector<int> resize_test;
        for (int i=1;i<10;i++)
            resize_test.push_back(i);
        resize_test.resize(5);
        resize_test.resize(8,100);
        resize_test.resize(12);
        for (size_t i = 0; i < resize_test.size(); i++)
            std::cout << resize_test[i] << " ";
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "size test" << std::endl;
        ft::vector<int> size_test;
        std::cout << "0. size: " << size_test.size() << std::endl;

        for (int i = 0; i < 10; i++) size_test.push_back(i);
            std::cout << "1. size: " << size_test.size() << std::endl;

        size_test.insert(size_test.end(), 10, 100);
        std::cout << "2. size: " << size_test.size() << std::endl;

        size_test.pop_back();
        std::cout << "3. size: " << size_test.size() << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "swap test" << std::endl;
        ft::vector<int> foo (3,100);
        ft::vector<int> bar (5,200);

        foo.swap(bar);
        std::cout << "foo contains:";
        for (unsigned i = 0; i < foo.size(); i++)
            std::cout << ' ' << foo[i];
        std::cout << std::endl;

        std::cout << "bar contains:";
        for (unsigned i = 0; i < bar.size(); i++)
            std::cout << ' ' << bar[i];
        std::cout << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "relational operators test" << std::endl;
        ft::vector<int> foo(3, 100);
        ft::vector<int> bar(2, 200);

        if (foo == bar)
            std::cout << "foo and bar are equal" << std::endl;
        if (foo != bar)
            std::cout << "foo and bar are not equal" << std::endl;
        if (foo < bar)
            std::cout << "foo is less than bar" << std::endl;
        if (foo > bar)
            std::cout << "foo is greater than bar" << std::endl;
        if (foo <= bar)
            std::cout << "foo is less than or equal to bar" << std::endl;
        if (foo >= bar)
            std::cout << "foo is greater than or equal to bar" << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "non-member swap test" << std::endl;
        ft::vector<int> foo(3, 100);
        ft::vector<int> bar(5, 200);

        swap(foo, bar);
        std::cout << "foo contains:";
        for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;

        std::cout << "bar contains:";
        for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
            std::cout << ' ' << *it;
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
