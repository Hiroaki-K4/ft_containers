/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_reverse_iterator.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:47:44 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/04 21:03:22 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_reverse_iterator.hpp"

void test_reverse_iterator()
{
    std::cout << std::endl;
    std::cout << "~~~ TEST reverse_iterator ~~~" << std::endl;

    {
        std::cout << "constructor test" << std::endl;
        std::vector<int> myvector;
        for (int i = 0; i < 10; i++)
            myvector.push_back(i);
        typedef std::vector<int>::iterator iter_type;
        iter_type from(myvector.begin());
        iter_type until(myvector.end());
        ft::reverse_iterator<iter_type> rev_until(from);
        std::reverse_iterator<iter_type> rev_from(until);
        // std::cout << "myvector:";
        // while (rev_from != rev_until)
        //     std::cout << ' ' << *rev_from++;
        std::cout << std::endl;
    }

    {
        std::cout << "base test" << std::endl;
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
    }
}
