/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:32:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/03 17:57:17 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

#include <iostream>

namespace ft
{
    template <class T, T v>
    struct integral_constant {
        enum { value = v };
        typedef T value_type;
        typedef integral_constant<T, v> type;
        constexpr operator T() { return v; }
    };

    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T>
    struct is_integral : public false_type {};
    template <>
    struct is_integral<bool> : public true_type {};
    template <>
    struct is_integral<char> : public true_type {};
    template <>
    struct is_integral<char16_t> : public true_type {};
    template <>
    struct is_integral<char32_t> : public true_type {};
    template <>
    struct is_integral<signed char> : public true_type {};
    template <>
    struct is_integral<short int> : public true_type {};
    template <>
    struct is_integral<int> : public true_type {};
    template <>
    struct is_integral<long int> : public true_type {};
    template <>
    struct is_integral<long long int> : public true_type {};
    template <>
    struct is_integral<unsigned char> : public true_type {};
    template <>
    struct is_integral<unsigned short int> : public true_type {};
    template <>
    struct is_integral<unsigned int> : public true_type {};
    template <>
    struct is_integral<unsigned long int> : public true_type {};
    template <>
    struct is_integral<unsigned long long int> : public true_type {};
}

#endif