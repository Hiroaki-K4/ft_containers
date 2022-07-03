/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/07/03 18:02:54 by hkubo            ###   ########.fr       */
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

        vector(size_type size, const allocator_type &alloc = allocator_type()) : alloc(alloc)
        {
            (void)size;
        }
        vector(size_type size, const_reference value, const allocator_type &alloc = allocator_type()): alloc(alloc)
        {
            (void)size;
        }
        ~vector() {};

        vector(const vector &x) {};
        vector &operator=(const vector &x) {};

        void push_back(const T &x);
        // T &operator[](std::size_t i);

        iterator begin() {return first;}
        iterator end() {return last;}
        iterator begin() const {return first;}
        iterator end() const {return last;}
        // const_iterator cbegin() const {return const_iterator(first);};
        // const_iterator cend() const {return last;};
        // reverse_iterator rbegin() {return reverse_iterator{last};};
        // reverse_iterator rend() {return reverse_iterator{first}};

        // size_type size() const {return std::distance(begin(), end());}
        size_type size() const {return begin() - end();}
        bool empty() const {return end() - begin();}
        size_type capacity() const {return reserved_last - first;}

        reference operator[](size_type i) {return first[i];}
        const_reference operator[](size_type i) const {return first[i];}

        reference at(size_type i)
        {
            if (i >= size())
                throw std::out_of_range("Index is out of range.");
            return first[i];
        }
        const_reference at(size_type i) const
        {
            if (i >= size())
                throw std::out_of_range("Index is out of range.");
            return first[i];
        }

        reference front() {return first;}
        const_reference front() const {return first;}
        reference back() {return last - 1;}
        const_reference back() const {return last - 1;}

        pointer data() {return first;}
        // const_pointer data() const {return first;}

    private:
        pointer first;
        pointer last;
        pointer reserved_last;
        allocator_type alloc;
};
}

#endif
