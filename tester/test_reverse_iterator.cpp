/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:47:44 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/05 08:53:50 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_reverse_iterator.hpp"

void test_reverse_iterator()
{
    std::cout << std::endl;
    std::cout << "~~~ TEST reverse_iterator ~~~" << std::endl;

    {
        std::cout << "[constructor test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.begin());
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_until(from);
        ft::reverse_iterator<iter_type> rev_from(until);
        std::cout << "myvector:";
        while (rev_from != rev_until)
            std::cout << ' ' << *rev_from++;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[base test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        ft::reverse_iterator<iter_type> rev_end(myvector.begin());
        ft::reverse_iterator<iter_type> rev_begin(myvector.end());
        std::cout << "myvector:";
        for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
            std::cout << ' ' << *it;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator- test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        ft::reverse_iterator<iter_type> rev_iterator(myvector.begin());
        std::cout << "myvector.begin()-3 points to: " << *(rev_iterator - 3) << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator-- test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        ft::reverse_iterator<iter_type> rev_begin(myvector.end());
        ft::reverse_iterator<iter_type> rev_end(myvector.begin());
        ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
        while ( rev_iterator != rev_end )
            std::cout << *rev_iterator++ << ' ';
        std::cout << std::endl;
        while ( rev_iterator != rev_begin )
            std::cout << *(--rev_iterator) << ' ';
        std::cout << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator-= test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        ft::reverse_iterator<iter_type> rev_iterator(myvector.begin());
        rev_iterator -= 4;
        std::cout << "rev_iterator now points to: " << *rev_iterator << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator-> test]" << std::endl;
        std::map<int,std::string> numbers;
        numbers.insert(std::make_pair(1, "one"));
        numbers.insert(std::make_pair(2, "two"));
        numbers.insert(std::make_pair(3, "three"));
        typedef std::map<int,std::string>::iterator map_iter;
        ft::reverse_iterator<map_iter> rev_end(numbers.begin());
        ft::reverse_iterator<map_iter> rev_iterator(numbers.end());
        for (; rev_iterator != rev_end ; ++rev_iterator)
            std::cout << rev_iterator->first << ' ' << rev_iterator->second << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator[] test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        ft::reverse_iterator<iter_type> rev_iterator(myvector.end());
        std::cout << "The fourth element from the end is: " << rev_iterator[3] << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator* test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.begin());
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_until(from);
        ft::reverse_iterator<iter_type> rev_from(until);
        std::cout << "myvector:";
        while (rev_from != rev_until)
            std::cout << ' ' << *rev_from++;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator+ test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_it(until);
        std::cout << "The fourth element from the end is: " << *(rev_it + 4) << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator++ test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.begin());
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_until(from);
        ft::reverse_iterator<iter_type> rev_from(until);
        std::cout << "myvector:";
        while (rev_from != rev_until) {
            std::cout << ' ' << *rev_from;
            ++rev_from;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator+= test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.end());
        ft::reverse_iterator<iter_type> rev_iterator(from);
        rev_iterator += 2;
        std::cout << "The third element from the end is: " << *rev_iterator << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator-(non-member) test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        ft::reverse_iterator<std::vector<int>::iterator> from(myvector.begin());
        ft::reverse_iterator<std::vector<int>::iterator> until(myvector.end());
        std::cout << "myvector has " << (until-from) << " elements." << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator+(non-member) test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        ft::reverse_iterator<iter_type> rev_it(myvector.end());
        std::cout << "The fourth element from the end is: " << *(3 + rev_it) << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator== and operator!=(non-member) test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++) myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.begin());
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_until(from);
        ft::reverse_iterator<iter_type> rev_from(until);
        std::cout << "myvector:";
        while (rev_from != rev_until)
            std::cout << ' ' << *rev_from++;
        std::cout << std::endl;
        if (rev_from == rev_until)
            std::cout << "Fianl rev_from == rev_until" << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[operator<, operator<=, operator> and operator>=(non-member) test]" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++) myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.begin());
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_until(from);
        ft::reverse_iterator<iter_type> rev_from(until);
        if (rev_from > rev_until)
            std::cout << "rev_from > rev_until" << std::endl;
        if (rev_from >= rev_until)
            std::cout << "rev_from >= rev_until" << std::endl;
        if (rev_until < rev_from)
            std::cout << "rev_until < rev_from" << std::endl;
        if (rev_until <= rev_from)
            std::cout << "rev_until <= rev_from" << std::endl;
    }
}
