/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:49:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/07/31 10:10:43 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <limits>
#include <memory>
#include <iterator>
#include <deque>
#include <type_traits>

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
            : alloc_(alloc), first_(NULL), last_(NULL), reserved_last_(NULL)
        {
        };
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
            : alloc_(alloc), first_(NULL), last_(NULL), reserved_last_(NULL)
        {
            if (n > 0)
            {
                allocate(n);
                std::uninitialized_fill_n(first_, n, val);
            }
        }
        template <class InputIterator>
        vector(InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type()) : alloc_(alloc)
        {
            allocate(std::distance(first, last));
            std::uninitialized_copy(first, last, first_);
        }
        vector(const vector &x)
            : alloc_(x.alloc_), first_(NULL), last_(NULL), reserved_last_(NULL)
        {
            size_type size = std::distance(x.begin(), x.end());
            if (size > 0)
            {
                allocate(size);
                std::uninitialized_copy(x.begin(), x.end(), first_);
            }
        }
        ~vector()
        {
            clear();
            deallocate();
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

        size_type size() const {return end() - begin();}
        size_type max_size() const
        {
            return std::min(static_cast<size_type>(std::numeric_limits<difference_type>::max() / sizeof(value_type)), alloc_.max_size());
        }
        bool empty() const {return begin() == end();}
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

        void reserve(size_type n)
        {
            if (n > max_size())
                throw std::length_error("ft::vector::reserve");
            if (n <= capacity())
                return ;
            pointer new_first = alloc_.allocate(n);
            size_type old_capacity = capacity();
            size_type old_size = size();
            std::uninitialized_copy(first_, last_, new_first);
            clear();
            alloc_.deallocate(first_, old_capacity);
            first_ = new_first;
            last_ = first_ + old_size;
            reserved_last_ = first_ + n;
        }
        void resize(size_type n, value_type val = value_type())
        {
            if (n < size())
            {
                erase(begin() + n, end());
            }
            else if (n > size())
            {
                insert(end(), n - size(), val);
            }
        }
        void clear()
        {
            destroy_until_end(first_);
        }
        iterator erase(iterator position)
        {
            return erase(position, position + 1);
        }
        iterator erase(iterator first, iterator last)
        {
            difference_type range = std::distance(first, last);
            for (iterator it = first; it + range != end(); it++)
            {
                *it = *(it + range);
            }
            destroy_until_end(first);
            return first;
        }
        iterator insert(iterator position, const value_type &val)
        {
            insert(position, 1, val);
            return position;
        }
        void insert(iterator position, size_type n, const value_type &val)
        {
            size_type range = std::distance(first_, position);
            if (size() + n > capacity())
            {
                std::cout << "insert allocate!" << std::endl;
                size_type old_capacity = capacity();
                size_type old_size = size();
                pointer new_first = alloc_.allocate(size() + n + 1);
                std::uninitialized_copy(first_, first_ + range, new_first);
                std::uninitialized_fill_n(new_first + range, n, val);
                std::uninitialized_copy(first_ + range, last_, new_first + range + n);
                clear();
                alloc_.deallocate(first_, old_capacity);
                first_ = new_first;
                // last_ = new_first + range + n;
                last_ = new_first + old_size + n;
                reserved_last_ = first_ + size() + n + 1;
            }
            else
            {
                std::cout << "insert non-allocate!" << std::endl;
                for (size_type i = 0; i < (size() - range); i++)
                {
                    if (range + i + n >= size())
                        alloc_.construct(first_ + range + i + n, first_[range + i]);
                    else
                        first_[range + i + n] = first_[range + i];
                }
                for (size_type i = 0; i < n; i++)
                {
                    if (range + i >= size())
                        alloc_.construct(&first_[range + i], val);
                    else
                        first_[range + i] = val;
                }
                last_ += n;
            }
        }
        template <class InputIterator>
        void insert(iterator position, InputIterator first, typename std::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type last)
        {
            size_type insert_size = std::distance(first, last);
            size_type range = std::distance(first_, position);
            std::cout << "ok1 " << "capacity: " << capacity() << " size: " << size() << " insert: " << insert_size << " sum: " << size() + insert_size << std::endl;
            if (size() + insert_size > capacity())
            {
                std::cout << "ok2.1" << std::endl;
                std::cout << "insert1" << std::endl;
                pointer new_first = alloc_.allocate(size() + insert_size);
                std::uninitialized_copy(first_, first_ + range, new_first);
                std::uninitialized_copy(first, last, new_first + range);
                std::uninitialized_copy(first_ + range, last_, new_first + range + insert_size);
                deallocate();
                first_ = new_first;
                last_ = new_first + range + insert_size;
                reserved_last_ = first_ + size() + insert_size;
            }
            else
            {
                std::cout << "ok2.2: " << size() - range << std::endl;
                for (size_type i = 0; i < (size() - range); i++)
                {
                    if (range + i + insert_size >= size())
                    {
                        std::cout << "const1: " << range + i + insert_size << " " << first_[range + i] << std::endl;
                        alloc_.construct(first_ + range + i + insert_size, first_[range + i]);
                    }
                    else
                    {
                        std::cout << "const2: " << range + i + insert_size << " " << first_[range + i] << std::endl;
                        first_[range + i + insert_size] = first_[range + i];
                    }
                }
                std::cout << "ok3" << std::endl;
                for (size_type i = 0; i < insert_size; i++)
                {
                    std::cout << "ok3.1" << std::endl;
                    if (range + i >= size())
                    {
                        std::cout << "ok3.2" << std::endl;
                        // alloc_.construct(last_, *(first + i));
                        // std::cout << "range: " << first_[range + i] << " " << first[i] << std::endl;
                        // TODO: Fix heap-buffer-overflow
                        std::cout << "range: " << range + i << " " << first_ + range + i << " " << first_[range + i - 1] << " " << first[i] << std::endl;
                        std::cout << "arg1: " << first_ + range + i << std::endl;
                        std::cout << "arg2: " << first[i] << std::endl;
                        alloc_.construct(first_ + range + i, first[i]);
                        // alloc_.construct(first_, first[i]);
                        std::cout << "ok3.2.1" << std::endl;
                    }
                    else
                    {
                        std::cout << "ok3.3" << std::endl;
                        first_[range + i] = first[i];
                    }
                }
                last_ += insert_size;
                std::cout << "ok4" << std::endl;
            }
        }

    private:
        allocator_type alloc_;
        pointer first_;
        pointer last_;
        pointer reserved_last_;

        void allocate(size_type n)
        {
            first_ = alloc_.allocate(n);
            last_ = first_ + n;
            reserved_last_ = last_;
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
                alloc_.destroy(now--);
            }
            last_ = new_last;
        }
};
}

#endif
