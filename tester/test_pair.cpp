/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:58:26 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/18 22:43:37 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_pair.hpp"

void test_pair()
{
    std::cout << "~~~ TEST std::pair ~~~" << std::endl;

    {
        std::cout << "[constructor test]" << std::endl;
        std::pair<std::string, double> product1;
        std::pair<std::string, double> product2("tomatoes", 2.30);
        std::pair<std::string, double> product3(product2);
        ft::pair<std::string, double> ft_product1;
        ft::pair<std::string, double> ft_product2("tomatoes", 2.30);
        ft::pair<std::string, double> ft_product3(ft_product2);

        product1 = std::make_pair(std::string("lightbulbs"), 0.99);
        product2.first = "shoes";
        product2.second = 39.90;
        ft_product1 = ft::make_pair(std::string("lightbulbs"), 0.99);
        ft_product2.first = "shoes";
        ft_product2.second = 39.90;

        if (product1.first != ft_product1.first || product1.second != ft_product1.second ||
            product2.first != ft_product2.first || product2.second != ft_product2.second ||
            product3.first != ft_product3.first || product3.second != ft_product3.second)
            error_process("pair test failed!!");

        std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
        std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
        std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
        std::cout << std::endl;
    }

    {
        std::cout << "[relational operators test]" << std::endl;
        ft::pair<int,char> foo(10, 'z');
        ft::pair<int,char> bar(90, 'a');

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

    std::cout << std::endl;
    std::cout << std::endl;
}

void test_make_pair()
{
    std::cout << "~~~ TEST std::make_pair ~~~" << std::endl;
    ft::pair<int, int> foo;
    ft::pair<int, int> bar;
    foo = ft::make_pair(10, 20);
    bar = ft::make_pair(10.5, 'A');
    std::cout << "foo: " << foo.first << ", " << foo.second << std::endl;
    std::cout << "bar: " << bar.first << ", " << bar.second << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
