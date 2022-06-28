/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/06/28 23:00:54 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iterator>
#include <deque>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
        private:

        public:
            typedef T value_type;
            typedef T* pointer;
            typedef const pointer const_pointer;
            typedef value_type& reference;
            typedef const value_type& const_reference;
            typedef Allocator allocator_type;
            typedef std::size_t size_type;

            vector(std::size_t n = 0, Allocator a = Allocator());
            ~vector();

            vector(const vector &x);
            vector &operator=(const vector &x);

            void push_back(const T &x);
            T &operator[](std::size_t i);

            typedef typename std::deque<T>::iterator iterator;
            iterator begin();
            iterator end();
    };
}

#endif
