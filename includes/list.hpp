/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:13:03 by zdawnsta          #+#    #+#             */
/*   Updated: 2021/02/25 16:13:09 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP

#include "utils.hpp"

namespace ft
{
    template <typename T, class Alloc = std::allocator<T> >
    class list
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef bidirectional_iterator<T> iterator;
        typedef const_bidirectional_iterator<T> const_iterator;
        typedef reverse_iterator<T> reverse_iterator;
        typedef const_reverse_iterator<T> const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;

    private:
        t_list<value_type> *_front;
        t_list<value_type> *_back;
        t_list<value_type> *_end;
        size_type _size;
        allocator_type _alloc;

    public:
        //  --- empty container constructor (default constructor) ---
        // Constructs an empty container, with no elements.
        explicit list(const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc)
        {
            _end = new t_list<T>;
            _end->value = new T();
            _end->prev = _end;
            _end->next = _end;
            _front = _end;
            _back = _end;
        }

        //  --- fill constructor ---
        // Constructs a container with n elements. Each element is a copy of val.
        explicit list(int n, const value_type &val = value_type(),
                      const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc)
        {
            // _end = _nodeAlloc.allocate(1);
            // _nodeAlloc.construct(_end);
            _end = new t_list<T>;
            _end->value = new T();
            _end->prev = _end;
            _end->next = _end;
            _front = _end;
            _back = _end;
            while (n--)
                push_back(val);
        }

        //  --- range constructor ---
        // Constructs a container with as many elements as the range [first,last),
        // with each element constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        // list(InputIterator first, typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last,
        // 	 const Alloc &alloc = Alloc()): _size(0), _alloc(alloc) {
        list(InputIterator first, InputIterator last,
             const allocator_type &alloc = allocator_type()) : _size(0), _alloc(alloc)
        {
            // _end = _nodeAlloc.allocate(1);
            // _nodeAlloc.construct(_end);
            _end = new t_list<T>;
            _end->value = new T();
            _end->prev = _end;
            _end->next = _end;
            _front = _end;
            _back = _end;
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        //  --- copy constructor ---
        // Constructs a container with a copy of each of the elements in x, in the same order.
        list(const list &copy) : _size(0)
        {
            _end = new t_list<T>;
            _end->value = new T();
            _end->prev = _end;
            _end->next = _end;
            _front = _end;
            _back = _end;
            *this = copy;
        }

        virtual ~list()
        {
            clear();
            delete (_end->value);
            delete (_end);
            // _nodeAlloc.destroy(_end);
            // _nodeAlloc.deallocate(_end, 1);
        }

        //  --- Assign content ---
        // Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
        list &operator=(const list &equal)
        {
            clear();
            for (const_iterator it = equal.begin(); it != equal.end(); ++it)
                push_back(*it);
            return (*this);
        }

        iterator begin()
        {
            return (iterator(_front));
        }

        iterator end()
        {
            return (iterator(_end));
        }

        // template <class InputIterator, class Distance>
        // void    advance (InputIterator& it, Distance n) {
        //     while (it != end() && n--)
        //         ++it;
        //     return (it);
        // }

        const_iterator begin() const
        {
            return (const_iterator(_front));
        }

        const_iterator end() const
        {
            return (const_iterator(_end));
        }

        reverse_iterator rbegin()
        {
            return (reverse_iterator(_back));
        }

        reverse_iterator rend()
        {
            return (reverse_iterator(_end));
        }

        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(_back));
        }

        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(_end));
        }

        bool empty() const
        {
            return (_size == 0);
        }

        size_type size() const
        {
            return (_size);
        }

        size_type max_size() const
        {
            return (std::numeric_limits<size_type>::max() / sizeof(t_list<T>));
        }

        reference front()
        {
            return (*_front->value);
        }

        const_reference front() const
        {
            return (*_front->value);
        }

        reference back()
        {
            return (*_back->value);
        }

        const_reference back() const
        {
            return (*_back->value);
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last)
        {
            // void assign (iterator first, iterator last) {
            // void assign (InputIterator first, iterator typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last) {
            clear();
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        // template <class T1>
        // void assign (size_type n, T1 val) {
        void assign(int n, const value_type &val)
        {
            clear();
            while (n--)
                push_back(val);
        }

        void clear()
        {
            while (_size)
                erase(begin());
        }

        //	Erase elements
        // -single element (position)-
        iterator erase(iterator elem)
        {
            t_list<T> *tmp = elem.getValue();
            if (tmp == _end)
                return (end());
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            if (tmp->prev == _end)
                _front = tmp->next;
            if (tmp->next == _end)
                _back = tmp->prev;
            delete tmp;
            _size--;
            return (++elem);
        }

        // -range of elements ([first,last))-
        iterator erase(iterator first, iterator last)
        {
            if (first == last)
                return last;
            while (first != last)
                first = erase(first);
            if (last.getValue() == _end)
                return (end());
            return (last);
        }

        // Add element at the end
        void push_back(const value_type &val)
        {
            insert(end(), val);
        }

        // Insert element at beginning
        void push_front(const value_type &val)
        {
            insert(begin(), val);
        }

        // Delete last element
        void pop_front()
        {
            t_list<T> *temp;
            temp = _back->prev;
            delete (_back->value);
            delete (_back);
            if (_size == 1)
            {
                _end->prev = _end;
                _end->next = _end;
                _front = _end;
                _back = _end;
                _size = 0;
                return;
            }
            _back = temp;
            _back->next = _end;
            _end->prev = _back;
            _size--;
        }

        // Delete first element
        void pop_back()
        {
            if (_size == 1)
            {
                pop_front();
                return;
            }
            t_list<T> *temp;
            temp = _front->next;
            delete (_front->value);
            delete (_front);
            _front = temp;
            _front->prev = _end;
            _end->next = _front;
            _size--;
        }

        //	Insert elements
        // -single element-
        iterator insert(iterator position, const value_type val)
        {
            t_list<T> *tmp = new t_list<T>;
            tmp->value = new T();
            // tmp->value = _alloc.allocate(1);
            // tmp->value = *val;
            _alloc.construct(tmp->value, val);
            tmp->next = position.getValue();
            tmp->prev = position.getValue()->prev;
            tmp->next->prev = tmp;
            tmp->prev->next = tmp;
            if (tmp->prev == _end)
                _front = tmp;
            if (tmp->next == _end)
                _back = tmp;
            _size++;
            return (iterator(tmp));
        }

        // -fill-
        void insert(iterator position, int n, const value_type val)
        {
            while (n--)
                insert(position, val);
        }

        // -range-
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last)
        {
            // void insert(iterator position, InputIterator first,
            // 	typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last) {
            for (InputIterator it = first; it != last; ++it)
                insert(position, *it);
        }

        // Swap content
        void swap(list &x)
        {
            list<T> tmp;
            tmp = x;
            x = *this;
            *this = tmp;
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

        // Transfer elements from list to list
        // -entire list-
        void splice(iterator position, list &x)
        {
            insert(position, x.begin(), x.end());
            x.clear();
        }

        // -single element-
        void splice(iterator position, list &x, iterator i)
        {
            insert(position, i, ++i);
            x.erase(--i);
        }

        // -element range-
        void splice(iterator position, list &x, iterator first, iterator last)
        {
            insert(position, first, last);
            x.erase(first, last);
        }

        // Sort elements in container
        // -with no parameters-
        void sort()
        {
            T *tmp;
            iterator it = begin();
            while (it != end())
            {
                iterator next = it;
                ++next;
                while (next != end())
                {
                    if (*it > *next)
                    {
                        tmp = it.getValue()->value;
                        it.getValue()->value = next.getValue()->value;
                        next.getValue()->value = tmp;
                    }
                    ++next;
                }
                ++it;
            }
        }

        // -specific comparison function-
        template <class Compare>
        void sort(Compare comp)
        {
            T *tmp;
            iterator it = begin();
            while (it != end())
            {
                iterator next = it;
                ++next;
                while (next != end())
                {
                    if (!comp(*it, *next))
                    {
                        tmp = it.getValue()->value;
                        it.getValue()->value = next.getValue()->value;
                        next.getValue()->value = tmp;
                    }
                    ++next;
                }
                ++it;
            }
        }

        // Remove elements with specific value
        void remove(const value_type &val)
        {
            iterator it = begin();
            while (it != end())
            {
                if (*it == val)
                    it = erase(it);
                else
                    ++it;
            }
        }

        // Remove elements fulfilling condition
        template <class Predicate>
        void remove_if(Predicate pred)
        {
            iterator it = begin();
            while (it != end())
            {
                if (pred(*it))
                    it = erase(it);
                else
                    ++it;
            }
        }

        // Remove duplicate values
        // -with no parameters-
        void unique()
        {
            iterator it = begin();
            while (it != end())
            {
                iterator tmp = it;
                ++tmp;
                while (tmp != end())
                {
                    if (*it == *tmp)
                        tmp = erase(tmp);
                    else
                        ++tmp;
                }
                ++it;
            }
        }

        // -specific comparison function-
        template <class BinaryPredicate>
        void unique(BinaryPredicate binary_pred)
        {
            iterator it = begin();
            while (it != end())
            {
                iterator tmp = it;
                ++tmp;
                while (tmp != end())
                {
                    if (binary_pred(*it, *tmp))
                        tmp = erase(tmp);
                    else
                        ++tmp;
                }
                ++it;
            }
        }

        // Merge sorted lists
        void merge(list &x)
        {
            iterator it1 = begin();
            iterator it2 = x.begin();
            while (x._size)
            {
                if (*it1 > *it2 || it1 == end())
                {
                    insert(it1, *it2);
                    it2 = x.erase(it2);
                }
                else
                    ++it1;
            }
        }

        template <class Compare>
        void merge(list &x, Compare comp)
        {
            iterator it1 = begin();
            iterator it2 = x.begin();
            while (x._size)
            {
                if (comp(*it2, *it1) || it1 == end())
                {
                    insert(it1, *it2);
                    it2 = x.erase(it2);
                }
                else
                    ++it1;
            }
        }

        // Reverse the order of elements
        void reverse()
        {
            T *tmp;
            iterator first = begin();
            iterator second = end();
            size_t half = (_size + 1) / 2;
            --second;
            for (size_t i = 0; i < half; i++)
            {
                tmp = first.getValue()->value;
                first.getValue()->value = second.getValue()->value;
                second.getValue()->value = tmp;
                ++first;
                --second;
            }
        }

        friend bool operator==(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
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

        friend bool operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
        {
            return (!(lhs == rhs));
        }

        friend bool operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
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

        friend bool operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
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

        friend bool operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
        {
            return (!(lhs > rhs));
        }

        friend bool operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
        {
            return (!(lhs < rhs));
        }
    };

    // Exchanges the contents of two lists
    template <class T, class Alloc>
    void swap(list<T, Alloc> &x, list<T, Alloc> &y)
    {
        x.swap(y);
    }
}

#endif
