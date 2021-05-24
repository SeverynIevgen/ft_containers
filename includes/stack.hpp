/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:44:12 by zdawnsta          #+#    #+#             */
/*   Updated: 2021/05/24 14:44:20 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "utils.hpp"
#include "vector.hpp"

namespace ft
{
    template <class T, class Container = vector<T> >
    class stack
    {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
        container_type cont;

        explicit stack(const container_type &ctnr = container_type()) { this->cont = ctnr; }
        bool empty() const { return (this->cont.empty()); }
        size_type size() const { return (this->cont.size()); }
        value_type &top() { return (this->cont.back()); }
        const value_type &top() const { return (this->cont.back()); }
        void push(const value_type &val) { this->cont.push_back(val); }
        void pop() { this->cont.pop_back(); }

        friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return (lhs.cont == rhs.cont);
        }

        friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return (lhs.cont != rhs.cont);
        }

        friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return (lhs.cont < rhs.cont);
        }

        friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return (lhs.cont > rhs.cont);
        }

        friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return (lhs.cont <= rhs.cont);
        }

        friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
        {
            return (lhs.cont >= rhs.cont);
        }
    };
}

#endif