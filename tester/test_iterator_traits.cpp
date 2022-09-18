/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterator_traits.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:34:50 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/18 22:37:14 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_iterator_traits.hpp"

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
    if (typeid(typename ft::iterator_traits<BidirIt>::iterator_category) == typeid(std::random_access_iterator_tag))
        std::cout << "vector is a random-access iterator" << std::endl;
    else if (typeid(typename ft::iterator_traits<BidirIt>::iterator_category) == typeid(std::bidirectional_iterator_tag))
        std::cout << "list is a bidirectional iterator" << std::endl;
    if (typeid(typename std::iterator_traits<BidirIt>::iterator_category) !=
        typeid(typename ft::iterator_traits<BidirIt>::iterator_category))
        error_process("iterator_traits test failed!!");
}

void test_iterator_traits()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "~~~ TEST iterator_traits ~~~" << std::endl;
    typedef std::iterator_traits<int*> traits;
    typedef ft::iterator_traits<int*> ft_traits;
    if (typeid(ft_traits::iterator_category) == typeid(std::random_access_iterator_tag))
        std::cout << "int* is a random-access iterator" << std::endl;

    if (typeid(traits::iterator_category) != typeid(ft_traits::iterator_category))
        error_process("iterator_traits test failed!!");

    {
        int ints[] = {1, 2, 3, 4, 5};
        std::vector<int> v(ints, ints + sizeof(ints) / sizeof(int));
        my_reverse(v.begin(), v.end());
        for (size_t n = 0; n < v.size(); n++)
            std::cout << v[n] << ' ';
        std::cout << std::endl;
    }

    {
        int ints[] = {1, 2, 3, 4, 5};
        std::list<int> v(ints, ints + sizeof(ints) / sizeof(int));
        my_reverse(v.begin(), v.end());
        std::cout << std::endl;
    }
}
