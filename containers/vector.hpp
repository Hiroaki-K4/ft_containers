/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/07/12 23:08:41 by hkubo            ###   ########.fr       */
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

        explicit vector(const allocator_type &alloc = allocator_type())
            : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc) {};
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
            : first_(NULL), last_(NULL), reserved_last_(NULL), alloc_(alloc)
        {
            if (n > 0)
            {
                allocate(n);
                std::cout << "ok1" << std::endl;
                std::uninitialized_fill_n(first_, n, val);
                std::cout << "ok2" << std::endl;
            }
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : alloc_(alloc)
        {
            (void)first;
            (void)last;
        }
        vector(const vector &x)
        {
            (void)x;
        }
        ~vector()
        {
            clear();
            // deallocate();
        }

        vector &operator=(const vector &x) {};

        void push_back(const value_type &val)
        {
            if (size() + 1 > capacity())
            {
                size_type current_size = size();
                if (current_size == 0)
                    reserve(1);
                else
                    reserve(current_size * 2);
            }
            alloc_.construct(last_, val);
            last_++;
        }
        // T &operator[](std::size_t i);

        iterator begin() {return first_;}
        iterator end() {return last_;}
        iterator begin() const {return first_;}
        iterator end() const {return last_;}
        // reverse_iterator rbegin() {return reverse_iterator{last_};};
        // reverse_iterator rend() {return reverse_iterator{first_}};

        size_type size() const {return begin() - end();}
        bool empty() const {return end() - begin();}
        size_type capacity() const {return reserved_last_ - first_;}

        reference operator[](size_type i) {return first_[i];}
        const_reference operator[](size_type i) const {return first_[i];}

        reference at(size_type i)
        {
            if (i >= size())
                throw std::out_of_range("Index is out of range.");
            return first_[i];
        }
        const_reference at(size_type i) const
        {
            if (i >= size())
                throw std::out_of_range("Index is out of range.");
            return first_[i];
        }

        reference front() {return first_;}
        const_reference front() const {return first_;}
        reference back() {return last_ - 1;}
        const_reference back() const {return last_ - 1;}

        void reserve(size_type sz)
        {
            if (sz <= capacity())
                return ;
            pointer ptr = allocate(sz);
            size_type old_size = size();

            first_ = ptr;
            last_ = first_ + old_size;
        }
        void resize(size_type n, value_type val = value_type())
        {
            if (n < size())
            {
                erase(begin() + n, end());
            }
            else
            {
                insert(end(), n - size(), val);
            }
        }

    private:
        pointer first_;
        pointer last_;
        pointer reserved_last_;
        allocator_type alloc_;

        pointer allocate(size_type n)
        {
            alloc_.allocate(n);
            last_ = first_ + n;
            reserved_last_ = last_;
            return first_;
        }
        void deallocate()
        {
            alloc_.deallocate(first_, capacity());
        }
        void construct(pointer ptr)
        {
            alloc_.construct(ptr);
        }
        void destroy_until_end(pointer new_last)
        {
            pointer now = last_;
            while (now != new_last)
            {
                std::cout << "Loop" << std::endl;
                alloc_.destroy(--now);
            }
            last_ = new_last;
        }
        void clear()
        {
            // destroy_until_end(first_);
        }
};
}

#endif
