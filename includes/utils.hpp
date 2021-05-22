/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:37:46 by zdawnsta          #+#    #+#             */
/*   Updated: 2021/02/25 10:37:54 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

// # include <memory>
#include <iostream>
#include <limits>
#include <memory>
#include <iterator>

template <typename T>
struct t_list
{
    T *value;
    struct t_list *next;
    struct t_list *prev;
};

template <class Key_type, class Value_type>
struct t_cell
{
    struct t_cell *parent;
    struct t_cell *next;
    struct t_cell *prev;
    bool end;
    std::pair<const Key_type, Value_type> *value;
};

template <class T>
class bidirectional_iterator
{
private:
    t_list<T> *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    explicit bidirectional_iterator() : _ptr(nullptr) {}
    explicit bidirectional_iterator(t_list<T> *ptr) : _ptr(ptr) {}

    bidirectional_iterator(const bidirectional_iterator &copy) : _ptr(copy._ptr) {}
    bidirectional_iterator &operator=(const bidirectional_iterator &equal)
    {
        _ptr = equal._ptr;
        return (*this);
    }

    virtual ~bidirectional_iterator() {}

    bidirectional_iterator &operator++()
    {
        _ptr = _ptr->next;
        return (*this);
    }

    bidirectional_iterator &operator--()
    {
        _ptr = _ptr->prev;
        return (*this);
    }

    const bidirectional_iterator operator++(int)
    {
        bidirectional_iterator it(_ptr);
        _ptr = _ptr->next;
        return (it);
    }

    const bidirectional_iterator operator--(int)
    {
        bidirectional_iterator it(_ptr);
        _ptr = _ptr->prev;
        return (it);
    }

    bool operator==(const bidirectional_iterator &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(const bidirectional_iterator &it)
    {
        return (_ptr != it._ptr);
    }

    reference operator*() const
    {
        return (*_ptr->value);
    }

    pointer operator->() const
    {
        return (_ptr->value);
    }

    t_list<T> *getValue() const
    {
        return (_ptr);
    }

    // template <class InputIterator, class Distance>
    // void advance (InputIterator& it, Distance n) {
    // void advance(bidirectional_iterator it, size_t n) {
    //     while (/*it != end() && */n--)
    //         ++it;
    // }
};

template <class T>
class const_bidirectional_iterator
{
private:
    t_list<T> *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    explicit const_bidirectional_iterator() : _ptr(nullptr) {}
    explicit const_bidirectional_iterator(t_list<T> *ptr) : _ptr(ptr) {}

    const_bidirectional_iterator(const const_bidirectional_iterator &copy) : _ptr(copy._ptr) {}
    const_bidirectional_iterator(const bidirectional_iterator<T> &copy) : _ptr(copy.getValue()) {}
    virtual ~const_bidirectional_iterator() {}

    const_bidirectional_iterator &operator=(const const_bidirectional_iterator &equal)
    {
        _ptr = equal._ptr;
        return (*this);
    }

    const_bidirectional_iterator &operator=(const bidirectional_iterator<T> &equal)
    {
        _ptr = equal.getValue();
        return (*this);
    }

    const_bidirectional_iterator &operator++()
    {
        _ptr = _ptr->next;
        return (*this);
    }

    const_bidirectional_iterator &operator--()
    {
        _ptr = _ptr->prev;
        return (*this);
    }

    const const_bidirectional_iterator operator++(int)
    {
        const_bidirectional_iterator it(_ptr);
        _ptr = _ptr->next;
        return (it);
    }

    const const_bidirectional_iterator operator--(int)
    {
        const_bidirectional_iterator it(_ptr);
        _ptr = _ptr->prev;
        return (it);
    }

    bool operator==(const const_bidirectional_iterator &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(const const_bidirectional_iterator &it)
    {
        return (_ptr != it._ptr);
    }

    reference operator*() const
    {
        return (*_ptr->value);
    }

    pointer operator->() const
    {
        return (_ptr->value);
    }
};

template <class T>
class reverse_iterator
{
private:
    t_list<T> *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    explicit reverse_iterator() : _ptr(nullptr) {}
    explicit reverse_iterator(t_list<T> *ptr) : _ptr(ptr) {}

    reverse_iterator(const reverse_iterator &copy) : _ptr(copy._ptr) {}
    virtual ~reverse_iterator() {}

    reverse_iterator &operator=(const reverse_iterator &equal)
    {
        _ptr = equal._ptr;
        return (*this);
    }

    reverse_iterator &operator++()
    {
        _ptr = _ptr->prev;
        return (*this);
    }

    reverse_iterator &operator--()
    {
        _ptr = _ptr->next;
        return (*this);
    }

    const reverse_iterator operator++(int)
    {
        reverse_iterator it(_ptr);
        _ptr = _ptr->prev;
        return (it);
    }

    const reverse_iterator operator--(int)
    {
        reverse_iterator it(_ptr);
        _ptr = _ptr->next;
        return (it);
    }

    bool operator==(reverse_iterator &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(reverse_iterator &it)
    {
        return (_ptr != it._ptr);
    }

    reference operator*() const
    {
        return (*_ptr->value);
    }

    pointer operator->() const
    {
        return (_ptr->value);
    }

    t_list<T> *getValue() const
    {
        return (_ptr);
    }
};

template <class T>
class const_reverse_iterator
{
private:
    t_list<T> *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    explicit const_reverse_iterator() : _ptr(nullptr) {}
    explicit const_reverse_iterator(t_list<T> *ptr) : _ptr(ptr) {}

    const_reverse_iterator(const const_reverse_iterator &copy) : _ptr(copy._ptr) {}
    const_reverse_iterator(const reverse_iterator<T> &copy) : _ptr(copy.getValue()) {}
    virtual ~const_reverse_iterator() {}

    const_reverse_iterator &operator=(const const_reverse_iterator &equal)
    {
        _ptr = equal._ptr;
        return (*this);
    }

    const_reverse_iterator &operator=(const reverse_iterator<T> &equal)
    {
        _ptr = equal.getValue();
        return (*this);
    }

    const_reverse_iterator &operator++()
    {
        _ptr = _ptr->prev;
        return (*this);
    }

    const_reverse_iterator &operator--()
    {
        _ptr = _ptr->next;
        return (*this);
    }

    const const_reverse_iterator operator++(int)
    {
        const_reverse_iterator it(_ptr);
        _ptr = _ptr->prev;
        return (it);
    }

    const const_reverse_iterator operator--(int)
    {
        const_reverse_iterator it(_ptr);
        _ptr = _ptr->next;
        return (it);
    }

    bool operator==(const_reverse_iterator &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(const_reverse_iterator &it)
    {
        return (_ptr != it._ptr);
    }

    reference operator*() const
    {
        return (*_ptr->value);
    }

    pointer operator->() const
    {
        return (_ptr->value);
    }
};

template <typename T>
class random_access_iterator
{
private:
    T *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    random_access_iterator() : _ptr(nullptr) {}

    random_access_iterator(T *ptr) : _ptr(ptr) {}

    random_access_iterator(const random_access_iterator &randomAccessIterator)
    {
        *this = randomAccessIterator;
    }

    random_access_iterator &operator=(const random_access_iterator &iter)
    {
        _ptr = iter.getValue();
        return (*this);
    }

    virtual ~random_access_iterator() {}

    random_access_iterator &operator++()
    {
        _ptr++;
        return (*this);
    }

    const random_access_iterator operator++(int)
    {
        random_access_iterator it(_ptr);
        _ptr++;
        return it;
    }

    const random_access_iterator &operator--()
    {
        _ptr--;
        return (*this);
    }

    const random_access_iterator operator--(int)
    {
        random_access_iterator it(_ptr);
        _ptr--;
        return it;
    }

    bool operator==(random_access_iterator const &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(random_access_iterator const &it)
    {
        return (_ptr != it._ptr);
    }

    bool operator<(random_access_iterator const &it)
    {
        return (_ptr < it._ptr);
    }

    bool operator<=(random_access_iterator const &it)
    {
        return (_ptr <= it._ptr);
    }

    bool operator>(random_access_iterator const &it)
    {
        return (_ptr > it._ptr);
    }

    bool operator>=(random_access_iterator const &it)
    {
        return (_ptr >= it._ptr);
    }

    reference &operator*() const
    {
        return (*_ptr);
    }

    pointer *operator->() const
    {
        return (_ptr);
    }

    random_access_iterator operator+(std::ptrdiff_t n)
    {
        random_access_iterator tmp = *this;
        return (tmp += n);
    }

    random_access_iterator &operator+=(std::ptrdiff_t step)
    {
        std::ptrdiff_t i = step;
        if (i >= 0)
            while (i--)
                _ptr++;
        else
            while (i++)
                _ptr--;
        return (*this);
    }

    random_access_iterator operator-(long n)
    {
        random_access_iterator tmp = *this;
        return (tmp -= n);
    }

    random_access_iterator &operator-=(std::ptrdiff_t i)
    {
        return (*this += -i);
    }

    std::ptrdiff_t operator-(random_access_iterator &it)
    {
        return (_ptr - it._ptr);
    }

    reference &operator[](std::ptrdiff_t i)
    {
        return (*(*this + i));
    }

    T *getValue() const
    {
        return (_ptr);
    }

    void setValue(T *value)
    {
        _ptr = value;
    }
};

template <typename T>
class const_random_access_iterator
{
private:
    T *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    const_random_access_iterator() : _ptr(nullptr) {}

    explicit const_random_access_iterator(T *ptr) : _ptr(ptr) {}

    const_random_access_iterator(const const_random_access_iterator &const_random_access_iterator)
    {
        *this = const_random_access_iterator;
    }

    const_random_access_iterator &operator=(const const_random_access_iterator &iter)
    {
        _ptr = iter.getValue();
        return (*this);
    }

    const_random_access_iterator &operator=(const random_access_iterator<T> &iter)
    {
        _ptr = iter.getValue();
        return (*this);
    }

    virtual ~const_random_access_iterator() {}

    const_random_access_iterator &operator++()
    {
        _ptr++;
        return (*this);
    }

    const const_random_access_iterator operator++(int)
    {
        const_random_access_iterator it(_ptr);
        _ptr++;
        return it;
    }

    const const_random_access_iterator &operator--()
    {
        _ptr--;
        return (*this);
    }

    const const_random_access_iterator operator--(int)
    {
        const_random_access_iterator it(_ptr);
        _ptr--;
        return it;
    }

    bool operator==(const_random_access_iterator const &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(const_random_access_iterator const &it)
    {
        return (_ptr != it._ptr);
    }

    bool operator<(const_random_access_iterator const &it)
    {
        return (_ptr < it._ptr);
    }

    bool operator<=(const_random_access_iterator const &it)
    {
        return (_ptr <= it._ptr);
    }

    bool operator>(const_random_access_iterator const &it)
    {
        return (_ptr > it._ptr);
    }

    bool operator>=(const_random_access_iterator const &it)
    {
        return (_ptr >= it._ptr);
    }

    const reference &operator*() const
    {
        return (*_ptr);
    }

    pointer *operator->() const
    {
        return (_ptr);
    }

    const_random_access_iterator operator+(std::ptrdiff_t n)
    {
        const_random_access_iterator tmp = *this;
        return (tmp += n);
    }

    const_random_access_iterator &operator+=(std::ptrdiff_t step)
    {
        std::ptrdiff_t i = step;
        if (i >= 0)
            while (i--)
                _ptr++;
        else
            while (i++)
                _ptr--;
        return (*this);
    }

    const_random_access_iterator operator-(long n)
    {
        const_random_access_iterator tmp = *this;
        return (tmp -= n);
    }

    const_random_access_iterator &operator-=(std::ptrdiff_t i)
    {
        return (*this += -i);
    }

    std::ptrdiff_t operator-(const_random_access_iterator &a)
    {
        return (_ptr - a._ptr);
    }

    reference &operator[](std::ptrdiff_t i)
    {
        return (*(*this + i));
    }

    T *getValue() const
    {
        return (_ptr);
    }
};

template <typename T>
class reverse_random_access_iterator
{
private:
    T *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    reverse_random_access_iterator() : _ptr(nullptr) {}

    reverse_random_access_iterator(T *ptr) : _ptr(ptr) {}

    reverse_random_access_iterator(const reverse_random_access_iterator &it)
    {
        *this = it;
    }

    reverse_random_access_iterator &operator=(const reverse_random_access_iterator &it)
    {
        _ptr = it.getValue();
        return (*this);
    }

    virtual ~reverse_random_access_iterator() {}

    reverse_random_access_iterator &operator++()
    {
        _ptr--;
        return (*this);
    }

    const reverse_random_access_iterator operator++(int)
    {
        reverse_random_access_iterator it(_ptr);
        _ptr--;
        return it;
    }

    const reverse_random_access_iterator &operator--()
    {
        _ptr++;
        return (*this);
    }

    const reverse_random_access_iterator operator--(int)
    {
        reverse_random_access_iterator it(_ptr);
        _ptr++;
        return it;
    }

    bool operator==(reverse_random_access_iterator const &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(reverse_random_access_iterator const &it)
    {
        return (_ptr != it._ptr);
    }

    reference &operator*() const
    {
        return (*_ptr);
    }

    pointer *operator->() const
    {
        return (_ptr);
    }

    reverse_random_access_iterator operator+(std::ptrdiff_t n)
    {
        reverse_random_access_iterator tmp = *this;
        return (tmp -= n);
    }

    reverse_random_access_iterator &operator+=(std::ptrdiff_t step)
    {
        std::ptrdiff_t i = step;
        if (i >= 0)
            while (i--)
                _ptr--;
        else
            while (i++)
                _ptr++;
        return (*this);
    }

    reverse_random_access_iterator operator-(long n)
    {
        reverse_random_access_iterator tmp = *this;
        return (tmp += n);
    }

    reverse_random_access_iterator &operator-=(std::ptrdiff_t i)
    {
        return (*this -= -i);
    }

    std::ptrdiff_t operator-(reverse_random_access_iterator &it)
    {
        return (_ptr - it._ptr);
    }

    reference &operator[](std::ptrdiff_t i)
    {
        return (*(*this - i));
    }

    T *getValue() const
    {
        return (_ptr);
    }

    void setValue(T *value)
    {
        _ptr = value;
    }
};

template <typename T>
class const_reverse_random_access_iterator
{
private:
    T *_ptr;

public:
    typedef typename std::allocator<T>::reference reference;
    typedef typename std::allocator<T>::pointer pointer;

    const_reverse_random_access_iterator() : _ptr(nullptr) {}

    const_reverse_random_access_iterator(T *ptr) : _ptr(ptr) {}

    const_reverse_random_access_iterator(const const_reverse_random_access_iterator &it)
    {
        *this = it;
    }

    const_reverse_random_access_iterator(const reverse_random_access_iterator<T> &it)
    {
        *this = it;
    }

    const_reverse_random_access_iterator &operator=(const const_reverse_random_access_iterator &it)
    {
        _ptr = it.getValue();
        return (*this);
    }

    const_reverse_random_access_iterator &operator=(const reverse_random_access_iterator<T> &it)
    {
        _ptr = it.getValue();
        return (*this);
    }

    virtual ~const_reverse_random_access_iterator() {}

    const_reverse_random_access_iterator &operator++()
    {
        _ptr--;
        return (*this);
    }

    const const_reverse_random_access_iterator operator++(int)
    {
        const_reverse_random_access_iterator it(_ptr);
        _ptr--;
        return it;
    }

    const const_reverse_random_access_iterator &operator--()
    {
        _ptr++;
        return (*this);
    }

    const const_reverse_random_access_iterator operator--(int)
    {
        const_reverse_random_access_iterator it(_ptr);
        _ptr++;
        return it;
    }

    bool operator==(const_reverse_random_access_iterator const &it)
    {
        return (_ptr == it._ptr);
    }

    bool operator!=(const_reverse_random_access_iterator const &it)
    {
        return (_ptr != it._ptr);
    }

    reference &operator*() const
    {
        return (*_ptr);
    }

    pointer *operator->() const
    {
        return (_ptr);
    }

    const_reverse_random_access_iterator operator+(std::ptrdiff_t n)
    {
        const_reverse_random_access_iterator tmp = *this;
        return (tmp -= n);
    }

    const_reverse_random_access_iterator &operator+=(std::ptrdiff_t step)
    {
        std::ptrdiff_t i = step;
        if (i >= 0)
            while (i--)
                _ptr--;
        else
            while (i++)
                _ptr++;
        return (*this);
    }

    const_reverse_random_access_iterator operator-(long n)
    {
        const_reverse_random_access_iterator tmp = *this;
        return (tmp += n);
    }

    const_reverse_random_access_iterator &operator-=(std::ptrdiff_t i)
    {
        return (*this -= -i);
    }

    std::ptrdiff_t operator-(const_reverse_random_access_iterator &it)
    {
        return (_ptr - it._ptr);
    }

    reference &operator[](std::ptrdiff_t i)
    {
        return (*(*this - i));
    }

    T *getValue() const
    {
        return (_ptr);
    }

    void setValue(T *value)
    {
        _ptr = value;
    }
};

template <class Key_type, class Value_type>
struct map_cell
{
    std::pair<Key_type, Value_type> value;
    map_cell *parent;
    map_cell *left;
    map_cell *right;
    bool empty;
};

template <typename Key, typename T, typename Pointer, typename Ref>
class map_iterator
{
public:
    typedef std::pair<Key, T> cell_type;
    typedef map_iterator<Key, T, Pointer, Ref> iterator;

private:
    typedef map_cell<Key, T> *pointer;
    pointer _ptr;
    pointer _incr(pointer ptr)
    {
        pointer p_next;
        if (ptr->right)
        {
            p_next = ptr->right;
            while (p_next->left)
                p_next = p_next->left;
        }
        else
        {
            p_next = ptr;
            while (p_next->parent && p_next == p_next->parent->right)
                p_next = p_next->parent;
            p_next = p_next->parent;
        }
        return (p_next);
    };
    pointer _decr(pointer ptr)
    {
        pointer p_prev = nullptr;
        if (ptr->left)
        {
            p_prev = ptr->left;
            while (p_prev->right)
                p_prev = p_prev->right;
        }
        else
        {
            p_prev = ptr;
            while (p_prev->parent && p_prev == p_prev->parent->left)
                p_prev = p_prev->parent;
            p_prev = p_prev->parent;
        }
        return (p_prev);
    };

public:
    map_iterator() : _ptr(nullptr) {}
    map_iterator(pointer p) : _ptr(p) {}
    map_iterator(const map_iterator &mapIterator) { *this = mapIterator; }

    virtual ~map_iterator() {}

    map_iterator &operator=(const map_iterator &mapIterator)
    {
        this->_ptr = mapIterator._ptr;
        return (*this);
    }

    pointer getPtr() { return (_ptr); }
    void setPtr(pointer ptr) { this->_ptr = ptr; }

    cell_type &operator*() { return (_ptr->value); }
    cell_type *operator->() { return (&_ptr->value); }

    map_iterator &operator++()
    {
        this->_ptr = _incr(_ptr);
        return (*this);
    }

    const map_iterator operator++(int)
    {

        map_iterator ret(*this);
        this->operator++();
        return (ret);
    }

    map_iterator &operator--()
    {
        this->_ptr = _decr(_ptr);
        return (*this);
    }

    const map_iterator operator--(int)
    {
        map_iterator ret(*this);
        this->operator--();
        return (ret);
    }

    bool operator==(const map_iterator &mapIterator)
    {
        return (this->_ptr == mapIterator._ptr);
    }

    bool operator!=(const map_iterator &mapIterator)
    {
        return (this->_ptr != mapIterator._ptr);
    }

    bool operator!=(const map_iterator &mapIterator) const
    {
        return (this->_ptr != mapIterator.ptr);
    }
};

template <typename Key, typename T, typename Pointer, typename Ref>
class reverse_map_iterator
{
public:
    typedef std::pair<Key, T> cell_type;
    typedef reverse_map_iterator<Key, T, Pointer, Ref> reverse_iterator;
    // typedef reverse_map_iterator<Key, T, T *, T &> iterator; // TODO Really?

private:
    typedef map_cell<Key, T> *pointer;
    pointer _ptr;
    pointer _incr(pointer ptr)
    {
        pointer p_next;
        if (ptr->right)
        {
            p_next = ptr->right;
            while (p_next->left)
                p_next = p_next->left;
        }
        else
        {
            p_next = ptr;
            while (p_next->parent && p_next == p_next->parent->right)
                p_next = p_next->parent;
            p_next = p_next->parent;
        }
        return (p_next);
    };
    pointer _decr(pointer ptr)
    {
        pointer p_prev = nullptr;
        if (ptr->left)
        {
            p_prev = ptr->left;
            while (p_prev->right)
                p_prev = p_prev->right;
        }
        else
        {
            p_prev = ptr;
            while (p_prev->parent && p_prev == p_prev->parent->left)
                p_prev = p_prev->parent;
            p_prev = p_prev->parent;
        }
        return (p_prev);
    };

public:
    reverse_map_iterator() : _ptr(nullptr) {}
    reverse_map_iterator(pointer p) : _ptr(p) {}
    reverse_map_iterator(const reverse_iterator &mapIterator) { *this = mapIterator; }

    virtual ~reverse_map_iterator() {}

    reverse_map_iterator &operator=(const reverse_iterator &mapIterator)
    {
        this->_ptr = mapIterator._ptr;
        return (*this);
    }

    pointer getPtr() { return (_ptr); }
    void setPtr(pointer ptr) { this->_ptr = ptr; }

    cell_type &operator*() { return (_ptr->value); }
    cell_type *operator->() { return (&_ptr->value); }

    reverse_map_iterator &operator++()
    {
        this->_ptr = _decr(_ptr);
        return (*this);
    }

    const reverse_map_iterator operator++(int)
    {

        reverse_map_iterator ret(*this);
        this->operator++();
        return (ret);
    }

    reverse_map_iterator &operator--()
    {
        this->_ptr = _incr(_ptr);
        return (*this);
    }

    const reverse_map_iterator operator--(int)
    {
        reverse_map_iterator ret(*this);
        this->operator--();
        return (ret);
    }

    bool operator==(const reverse_map_iterator &mapIterator)
    {
        return (this->_ptr == mapIterator._ptr);
    }

    bool operator!=(const reverse_map_iterator &mapIterator)
    {
        return (this->_ptr != mapIterator._ptr);
    }

    bool operator!=(const reverse_map_iterator &mapIterator) const
    {
        return (this->_ptr != mapIterator.ptr);
    }
};

template <bool B, class T = void>
struct enable_if
{
};

template <class T>
struct enable_if<true, T>
{
    typedef T type;
};

#endif
