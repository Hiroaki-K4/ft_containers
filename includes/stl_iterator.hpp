/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stl_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:46:18 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/04 21:01:38 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STL_ITERATOR_HPP
# define STL_ITERATOR_HPP

#include <iterator>
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

            iterator_type base() const {return current;}

        protected:
            Iterator current;

        private:
    };
}

#endif
