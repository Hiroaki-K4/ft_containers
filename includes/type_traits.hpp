/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkubo <hkubo@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 09:32:02 by hkubo             #+#    #+#             */
/*   Updated: 2022/09/03 22:10:31 by hkubo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
    template<bool Cond, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };


    template <class T, T v>
    struct integral_constant {
        enum {value = v};
        typedef T value_type;
        typedef integral_constant<T, v> type;
        operator T() const {return v;}
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
    struct is_integral<wchar_t> : public true_type {};
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
