/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/06/29 23:03:13 by hkubo            ###   ########.fr       */
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
class vector {
    public:
        typedef T value_type;
        typedef T* pointer;
        typedef const pointer const_pointer;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef Allocator allocator_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;

        // iterator alias
        typedef pointer iterator;
        typedef const_pointer const_iterator;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        vector(std::size_t n = 0, Allocator a = Allocator());
        ~vector();

        vector(const vector &x);
        vector &operator=(const vector &x);

        void push_back(const T &x);
        T &operator[](std::size_t i);

        iterator begin() {return first;};
        iterator end() {return last;};
        iterator begin() const {return first;};
        iterator end() const {return last;};
        // const_iterator cbegin() const {return first;};
        // const_iterator cend() const {return last;};
        reverse_iterator rbegin() {return reverse_iterator{last};};
        reverse_iterator rend() {return reverse_iterator{first}};

    private:
        pointer first;
        pointer last;
        pointer reserved_last;
        allocator_type alloc;
};
}

#endif
