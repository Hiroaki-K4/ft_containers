/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:46:18 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/04 23:16:44 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_ITERATOR_HPP
# define STL_ITERATOR_HPP

#include "iterator_concepts.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator : public std::iterator<typename ft::iterator_traits<Iterator>::iterator_category,
                                             typename ft::iterator_traits<Iterator>::value_type,
                                             typename ft::iterator_traits<Iterator>::difference_type,
                                             typename ft::iterator_traits<Iterator>::pointer,
                                             typename ft::iterator_traits<Iterator>::reference>
    {
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename ft::iterator_traits<Iterator>::value_type value_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::pointer pointer;
            typedef typename ft::iterator_traits<Iterator>::reference reference;

            reverse_iterator() : current() {};
            explicit reverse_iterator(iterator_type it) : current(it) {};
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter> &rev_it): current(rev_it.base()) {};

            iterator_type base() const
            {
                return current;
            }
            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(current + n);
            }
            reverse_iterator &operator--()
            {
                ++current;
                return *this;
            }
            reverse_iterator operator--(int)
            {
                reverse_iterator tmp = *this;
                ++current;
                return tmp;
            }
            reverse_iterator &operator-=(difference_type n)
            {
                current += n;
	            return *this;
            }
            pointer operator->() const
            {
                return &(operator*());
            }
            reference operator[](difference_type n) const
            {
                return *(*this + n);
            }
            reference operator*() const
            {
                iterator_type tmp = current;
	            return *--tmp;
            }
            reverse_iterator operator+(difference_type n) const
            {
                return reverse_iterator(current - n);
            }
            reverse_iterator &operator++()
            {
                --current;
                return *this;
            }
            reverse_iterator operator++(int)
            {
                reverse_iterator tmp = *this;
                --current;
                return tmp;
            }
            reverse_iterator &operator+=(difference_type n)
            {
                current -= n;
	            return *this;
            }

        protected:
            Iterator current;

        private:
    };


    template <class Iterator>
    typename reverse_iterator<Iterator>::difference_type operator-(
        const reverse_iterator<Iterator>& lhs,
        const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() - rhs.base();
    }

    template <class Iterator>
    reverse_iterator<Iterator> operator+(
        typename reverse_iterator<Iterator>::difference_type n,
        const reverse_iterator<Iterator> &rev_it)
    {
        return reverse_iterator<Iterator>(rev_it.base() - n);
    }

    template <class Iterator>
    bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() == rhs.base();
    }

    template <class Iterator>
    bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() != rhs.base();
    }

    template <class Iterator>
    bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() < rhs.base();
    }

    template <class Iterator>
    bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() <= rhs.base();
    }

    template <class Iterator>
    bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() > rhs.base();
    }

    template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return lhs.base() >= rhs.base();
    }
}

#endif
