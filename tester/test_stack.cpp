/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:31:26 by hkubo             #+#    #+#             */
/*   Updated: 2022/12/18 16:34:46 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"
#include "utils.hpp"

void test_stack()
{
    std::cout << "~~~ TEST stack ~~~" << std::endl;
    {
        std::cout << "[constructor test]" << std::endl;
        std::vector<int> myvector(2, 200);
        ft::vector<int> ft_myvector(2, 200);
        std::stack<int> first;
        ft::stack<int> ft_first;
        std::stack<int, std::vector<int> > second(myvector);
        ft::stack<int, ft::vector<int> > ft_second(ft_myvector);

        std::cout << "size of first: " << first.size() << std::endl;
        std::cout << "size of ft_first: " << ft_first.size() << std::endl;
        std::cout << "size of second: " << second.size() << std::endl;
        std::cout << "size of ft_second: " << ft_second.size() << std::endl;
        if (first.size() != ft_first.size() || second.size() != ft_second.size())
            error_process("constructor test failed!!");
        std::cout << std::endl;
    }

    {
        std::cout << "[empty, pop, push, top test]" << std::endl;
        std::stack<int> mystack;
        ft::stack<int> ft_mystack;

        for (int i = 0; i < 5; ++i)
        {
            mystack.push(i);
            ft_mystack.push(i);
        }
        std::cout << "Popping out elements...";
        while (!mystack.empty())
        {
            std::cout << ' ' << mystack.top();
            mystack.pop();
        }
        while (!ft_mystack.empty())
        {
            std::cout << ' ' << ft_mystack.top();
            ft_mystack.pop();
        }
        if (mystack.size() != ft_mystack.size())
            error_process("empty, pop, push, top test failed!!");
        std::cout << std::endl;
    }

    {
        
    }
}