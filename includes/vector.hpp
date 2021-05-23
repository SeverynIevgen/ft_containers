/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 11:33:03 by zdawnsta          #+#    #+#             */
/*   Updated: 2021/03/10 11:33:12 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "utils.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class vector
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
        explicit vector(const allocator_type &alloc = allocator_type()) : // _node(nullptr), _size(0), _capacity(0), _alloc(alloc) {}
                                                                          _size(0), _capacity(0), _alloc(alloc)
        {
            _node = _alloc.allocate(1);
            // *_node = 0;
        }

        //  --- fill constructor ---
        explicit vector(int n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
        {
            _node = _alloc.allocate(n);
            for (int i = 0; i < n; i++)
                _node[i] = val;
        }

        //  --- range constructor ---
        // Constructs a container with as many elements as the range [first,last),
        // with each element constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        // vector(InputIterator first, typename enable_if<std::is_class<InputIterator>::value,
        //     InputIterator>::type last, const allocator_type &alloc = allocator_type()): _alloc(alloc) {
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type()) : _alloc(alloc)
        {
            size_type i = 0;
            size_type size = last - first;
            _size = size;
            _capacity = size;
            _node = _alloc.allocate(size);
            while (first != last)
            {
                _node[i++] = *first;
                ++first;
            }
        }

        //  --- copy constructor ---
        // Constructs a container with a copy of each of the elements in x, in the same order.
        vector(const vector &copy) : _size(copy._size), _capacity(copy._capacity), _alloc(copy._alloc)
        {
            _node = _alloc.allocate(_capacity);
            *this = copy;
        }

        virtual ~vector()
        {
            clear();
            delete (_node);
        }

        //  --- Assign content ---
        // Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
        vector &operator=(const vector &equal)
        {
            clear();
            _size = equal.size();
            for (size_type i = 0; i < _size; i++)
                _node[i] = equal._node[i];
            return (*this);
        }

        // Access element
        reference operator[](size_type n)
        {
            return (_node[n]);
        }

        const_reference operator[](size_type n) const
        {
            return (_node[n]);
        }

        reference at(size_type n)
        {
            if (n < _size)
                return (_node[n]);
            throw std::out_of_range("Out of Range error: ");
        }

        const_reference at(size_type n) const
        {
            return (_node[n]);
        }

        iterator begin()
        {
            return (iterator(_node));
        }

        iterator end()
        {
            return (iterator(_node + _size));
        }

        const_iterator begin() const
        {
            return (const_iterator(_node));
        }

        const_iterator end() const
        {
            return (const_iterator(_node + _size));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(_node + _size - 1));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(_node - 1));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(_node + _size - 1));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(_node - 1));
        }

        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (std::numeric_limits<size_type>::max() / sizeof(value_type));
        }

        // Change size
        void resize(size_type n, value_type val = value_type())
        {
            if (n < _size)
                while (_size > n)
                    pop_back();
            else if (n > _size)
                while (_size < n)
                    push_back(val);
        }

        size_type capacity() const
        {
            return (_capacity);
        }

        bool empty() const
        {
            return (_size == 0);
        }

        // Request a change in capacity
        void reserve(size_type n)
        {
            if (n > _capacity)
            {
                value_type *newCap;
                newCap = _alloc.allocate(n);
                for (size_type i = 0; i < _size; i++)
                    newCap[i] = _node[i];
                delete[] _node;
                _node = newCap;
                _capacity = n;
            }
        }

        reference front()
        {
            return (_node[0]);
        }

        const_reference front() const
        {
            return (_node[0]);
        }

        reference back()
        {
            return (_size ? _node[_size - 1] : _node[0]);
        }

        const_reference back() const
        {
            return (_size ? _node[_size - 1] : _node[0]);
        }

        // vector::assign
        // -range-
        template <class InputIterator>
        void assign(InputIterator first,
                    InputIterator last)
        {
            clear();
            size_t n = last - first;
            if (n > _capacity)
                reserve(n);
            // _size = n;
            while (first != last)
            {
                // push_back(*first);
                insert(end(), *first);
                ++first;
            }

            // while (n--) {
            //     _node[n] = *last;
            //     --last;
            // }
        }

        // -fill-
        void assign(int n, const value_type &val)
        {
            clear();
            if (n > (int)_capacity)
                reserve(n);
            _size = n;
            while (n--)
                _node[n] = val;
        }

        // Add element at the end
        void push_back(const value_type &val)
        {
            insert(end(), val);
        }

        // Delete last element
        void pop_back()
        {
            erase(end());
        }

        //	Insert elements
        // -single element-
        iterator insert(iterator position, const value_type &val)
        {
            iterator beg = this->begin();
            size_type ind = position - beg;
            size_type finish = _size - ind;
            size_type i = 0;
            if (_size == 0)
                reserve(1);
            else if (_size + 1 > _capacity)
                reserve(2 * _capacity);
            while (i < finish)
            {
                _node[_size - i] = _node[(finish - 1) - i];
                i++;
            }
            _node[ind] = val;
            _size++;
            return (iterator(_node + ind));
        }

        // -fill-
        void insert(iterator position, int n, const value_type &val)
        {
            iterator beg = this->begin();
            size_type ind = position - beg;
            size_type after = _size - ind;
            size_type i = 0;
            if (_size + n > _capacity)
                reserve(n > (int)_capacity ? _size + n : 2 * _capacity);
            _size += n;
            while (i <= after)
            {
                _node[_size - i] = _node[after - i];
                i++;
            }
            i = 0;
            while ((int)i < n)
            {
                _node[ind + i] = val;
                i++;
            }
        }

        // -range-
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last)
        {
            // void insert(iterator position, InputIterator first,
            // 	typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last) {
            iterator beg = this->begin();
            size_type ind = position - beg;
            size_type end = _size;
            size_type i = 0;
            size_type n = last - first;
            if (_size + n > _capacity)
                reserve(n > _capacity ? _size + n : 2 * _capacity);
            _size += n;
            while (i < end)
            {
                _node[_size - 1 - i] = _node[end - 1 - i];
                i++;
            }
            i = 0;
            while (i < n)
            {
                _node[ind + i] = *first;
                ++first;
                i++;
            }
        }

        // Swap content
        void swap(vector &x)
        {
            allocator_type tmpAlloc = _alloc;
            size_type tmpCapacity = _capacity;
            value_type *tmpNode = _node;
            size_type tmpSize = _size;
            _alloc = x._alloc;
            x._alloc = tmpAlloc;
            _capacity = x._capacity;
            x._capacity = tmpCapacity;
            _node = x._node;
            x._node = tmpNode;
            _size = x._size;
            x._size = tmpSize;
        }

        //	Erase elements
        // -single element (position)-
        iterator erase(iterator elem)
        {
            iterator it = elem;
            iterator tmp;
            if (_size == 0)
                return (end());
            while (it != end())
            {
                tmp = it;
                ++it;
                *tmp = *it;
            }
            *tmp = 0;
            _size--;
            return (elem);
        }

        // -range of elements ([first, last))-
        iterator erase(iterator first, iterator last)
        {
            if (first == last)
                return last;
            iterator start = this->begin();
            size_type beg = first - start;
            size_type n = last - first;
            size_type i = 0;
            while (i < _size - n)
            {
                _node[beg + i] = _node[beg + n + i];
                i++;
            }
            i = 0;
            std::cout << 'n = ' << n << std::endl;
            while (i < n)
            {
                _node[_size - 1 - i] = 0;
                std::cout << 'i = ' << _size - 1 - i << std::endl;
                i++;
            }
            _size -= n;
            return (last);
        }

        void clear() { _size = 0; }

        friend bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
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

        friend bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (!(lhs == rhs));
        }

        friend bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            const_iterator it1 = lhs.begin();
            const_iterator it1End = lhs.end();
            const_iterator it2 = rhs.begin();
            const_iterator it2End = rhs.end();
            while (it1 != it1End && it2 != it2End)
            {
                if (*it1 < *it2)
                    return (true);
                else
                {
                    ++it1;
                    ++it2;
                }
            }
            return (false);
        }

        friend bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            const_iterator it1 = lhs.begin();
            const_iterator it1End = lhs.end();
            const_iterator it2 = rhs.begin();
            const_iterator it2End = rhs.end();
            while (it1 != it1End && it2 != it2End)
            {
                if (*it1 > *it2)
                    return (true);
                else
                {
                    ++it1;
                    ++it2;
                }
            }
            return (false);
        }

        friend bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (!(lhs > rhs));
        }

        friend bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
        {
            return (!(lhs < rhs));
        }

        // friend void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y) {
        //     x.swap(y);
        // }
    };

    // Exchanges the contents of two vectors
    template <class T, class Alloc>
    void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
    {
        x.swap(y);
    }
}

#endif