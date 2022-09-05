/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:46:06 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/05 09:00:00 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_compare.hpp"

bool mypredicate(int i, int j)
{
    return (i==j);
}


void test_compare()
{
    std::cout << "~~~ TEST equal and/or lexicographical_compare ~~~" << std::endl;
    std::cout << "[equal test]" << std::endl;
    {
        int myints[] = {20,40,60,80,100};
        std::vector<int>myvector (myints,myints+5);
        if ( std::equal (myvector.begin(), myvector.end(), myints) )
            std::cout << "The contents of both sequences are equal." << std::endl;
        else
            std::cout << "The contents of both sequences differ." << std::endl;
        myvector[3]=81;
        if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
            std::cout << "The contents of both sequences are equal." << std::endl;
        else
            std::cout << "The contents of both sequences differ." << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
