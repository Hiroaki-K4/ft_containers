/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:42:14 by hkubo             #+#    #+#             */
/*   Updated: 2022/12/18 16:47:34 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class container = ft::vector<T> >
    class stack
    {
        public:
            typedef T value_type;
            typedef container container_type;
            typedef std::size_t size_type;

            explicit stack(const container_type &ctnr = container_type()) : c(ctnr)
            {
            };

            size_type size() const
            {
                return c.size();
            };
            bool empty() const
            {
                return c.empty();
            };
            void push(const value_type &val)
            {
                c.push_back(val);
            };
            void pop()
            {
                c.pop_back();
            };
            value_type& top()
            {
                return c.back();
            };
            const value_type& top() const
            {
                return c.back();
            };

            friend bool operator==(const stack<T, container> &lhs, const stack<T, container> &rhs)
            {
                return lhs.c == rhs.c;
            };

            friend bool operator!=(const stack<T, container> &lhs, const stack<T, container> &rhs)
            {
                return lhs.c != rhs.c;
            };

            friend bool operator<(const stack<T, container> &lhs, const stack<T, container> &rhs)
            {
                return lhs.c < rhs.c;
            };

            friend bool operator<=(const stack<T, container> &lhs, const stack<T, container> &rhs)
            {
                return lhs.c <= rhs.c;
            };

            friend bool operator>(const stack<T, container> &lhs, const stack<T, container> &rhs)
            {
                return lhs.c > rhs.c;
            };

            friend bool operator>=(const stack<T, container> &lhs, const stack<T, container> &rhs)
            {
                return lhs.c >= rhs.c;
            };

        protected:
            container c;
    };
}

#endif
