/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:46:06 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/06 09:00:19 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_compare.hpp"

bool mypredicate(int i, int j)
{
    return (i == j);
}

bool mycomp(char c1, char c2)
{
    return std::tolower(c1) < std::tolower(c2);
}

void test_compare()
{
    std::cout << "~~~ TEST equal and/or lexicographical_compare ~~~" << std::endl;
    {
        std::cout << "[equal test]" << std::endl;
        int myints[] = {20, 40, 60, 80, 100};
        std::vector<int>myvector(myints, myints + 5);
        if (ft::equal(myvector.begin(), myvector.end(), myints))
            std::cout << "The contents of both sequences are equal." << std::endl;
        else
            std::cout << "The contents of both sequences differ." << std::endl;
        myvector[3] = 81;
        if (ft::equal(myvector.begin(), myvector.end(), myints, mypredicate))
            std::cout << "The contents of both sequences are equal." << std::endl;
        else
            std::cout << "The contents of both sequences differ." << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[lexicographical_compare test]" << std::endl;
        char foo[] = "Apple";
        char bar[] = "apartment";
        std::cout << std::boolalpha;
        std::cout << "Comparing foo and bar lexicographically (foo<bar):" << std::endl;
        std::cout << "Using default comparison (operator<): ";
        std::cout << ft::lexicographical_compare(foo, foo + 5, bar, bar + 9);
        std::cout << std::endl;
        std::cout << "Using mycomp as comparison object: ";
        std::cout << ft::lexicographical_compare(foo, foo + 5, bar, bar + 9, mycomp);
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;
}
