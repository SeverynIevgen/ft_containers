/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:23:07 by zdawnsta          #+#    #+#             */
/*   Updated: 2021/05/27 17:23:25 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "vector.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class deque : public ft::vector<T, Alloc>
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef random_access_iterator<T> iterator;
        typedef const_random_access_iterator<T> const_iterator;
        typedef reverse_random_access_iterator<T> reverse_iterator;
        typedef const_reverse_random_access_iterator<T> const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;

    private:
        value_type *_node;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;

    public:
        //  --- empty container constructor (default constructor) ---
        explicit deque(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _node(nullptr) {}

        //  --- fill constructor ---
        explicit deque(size_type n, const value_type &val = value_type(),
                       const allocator_type &alloc = allocator_type()) : ft::vector<T, Alloc>(n, val, alloc) {}

        //  --- range constructor ---
        // Constructs a container with as many elements as the range [first,last),
        // with each element constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        deque(InputIterator first, InputIterator last,
              const allocator_type &alloc = allocator_type()) : ft::vector<T, Alloc>(first, last, alloc) {}

        //  --- copy constructor ---
        // Constructs a container with a copy of each of the elements in x, in the same order.
        deque(const deque &copy) : _size(copy._size), _capacity(copy._capacity), _alloc(copy._alloc)
        {
            _node = _alloc.allocate(_capacity);
            *this = copy;
        }

        virtual ~deque()
        {
            this->clear();
            delete (this->_node);
        }

        //  --- Assign content ---
        // Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
        deque &operator=(const deque &equal)
        {
            this->clear();
            this->_size = equal.size();
            for (const_iterator it = equal.begin(); it != equal.end(); it++)
				this->push_back(*it);
            // for (size_type i = 0; i < _size; i++)
            //     _node[i] = equal._node[i];
            return (*this);
        }

        void push_front(const value_type &val)
        {
            this->insert(this->begin(), val);
        }

        void pop_front()
        {
            this->erase(this->begin());
        }

        friend bool operator==(const ft::deque<T, Alloc> &lhs, const ft::deque<T, Alloc> &rhs)
        {
            if (lhs.size() != rhs.size())
                return (false);
            size_t i = lhs.size();
            const_iterator it1 = lhs.begin();
            const_iterator it2 = rhs.begin();
            while (i--)
            {
                if (*it1 != *it2)
                    return (false);
                else
                {
                    ++it1;
                    ++it2;
                }
            }
            return (true);
        }

        friend bool operator!=(const ft::deque<T, Alloc> &lhs, const ft::deque<T, Alloc> &rhs)
        {
            return (!(lhs == rhs));
        }

        friend bool operator<(const ft::deque<T, Alloc> &lhs, const ft::deque<T, Alloc> &rhs)
        {
            const_iterator it1 = lhs.begin();
            const_iterator it1End = lhs.end();
            const_iterator it2 = rhs.begin();
            const_iterator it2End = rhs.end();
            while (it1 != it1End && it2 != it2End && *it1 == *it2)
            {
                it1++;
                it2++;
            }
            return ((it1 == it1End && it2 != it2End) || *it1 < *it2);
        }

        friend bool operator>(const ft::deque<T, Alloc> &lhs, const ft::deque<T, Alloc> &rhs)
        {
            const_iterator it1 = lhs.begin();
            const_iterator it1End = lhs.end();
            const_iterator it2 = rhs.begin();
            const_iterator it2End = rhs.end();
            while (it1 != it1End && it2 != it2End && *it1 == *it2)
            {
                it1++;
                it2++;
            }
            return ((it2 == it2End && it1 != it1End) || *it1 > *it2);
        }

        friend bool operator<=(const ft::deque<T, Alloc> &lhs, const ft::deque<T, Alloc> &rhs)
        {
            return (!(lhs > rhs));
        }

        friend bool operator>=(const ft::deque<T, Alloc> &lhs, const ft::deque<T, Alloc> &rhs)
        {
            return (!(lhs < rhs));
        }
    };

    // Exchanges the contents of two deques
    template <class T, class Alloc>
    void swap(ft::deque<T, Alloc> &x, ft::deque<T, Alloc> &y)
    {
        x.swap(y);
    }
}

#endif
