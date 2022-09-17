/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 18:36:34 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/17 17:55:31 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_map.hpp"

bool fncomp(char lhs, char rhs)
{
    return lhs < rhs;
}

struct classcomp
{
    bool operator()(const char& lhs, const char& rhs) const
    {
        return lhs < rhs;
    }
};


void test_map()
{
    std::cout << "~~ TEST map ~~~" << std::endl;

    {
        std::cout << "[constructor test]" << std::endl;
        std::map<char, int> first;

        first['a'] = 10;
        first['b'] = 30;
        first['c'] = 50;
        first['d'] = 70;

        std::map<char, int> second(first.begin(), first.end());
        std::map<char, int> third(second);
        std::map<char, int, classcomp> fourth;

        bool(*fn_pt)(char, char) = fncomp;
        std::map<char, int, bool(*)(char, char)> fifth(fn_pt);
    }

    std::cout << std::endl;
    std::cout << std::endl;
}
