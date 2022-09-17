/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:12:49 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/17 22:38:41 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "test_vector.hpp"
#include "test_enable_if.hpp"
#include "test_is_integral.hpp"
#include "test_iterator_traits.hpp"
#include "test_reverse_iterator.hpp"
#include "test_compare.hpp"
#include "test_pair.hpp"
#include "test_map.hpp"
#include "test_rb_tree.hpp"

int main(int ac, char *argv[])
{
    (void) argv;
    int flag = 0;
    if (ac == 2)
        flag = 1;
    test_vector(flag);
    std::cout << "TEST stack" << std::endl;
    test_iterator_traits();
    test_reverse_iterator();
    test_enable_if();
    test_is_integral();
    test_compare();
    test_pair();
    test_make_pair();
    test_map();
    test_rb_tree();

    return (0);
}
