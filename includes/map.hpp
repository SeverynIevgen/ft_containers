/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdawnsta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:57:00 by zdawnsta          #+#    #+#             */
/*   Updated: 2021/03/18 17:57:06 by zdawnsta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "utils.hpp"

namespace ft
{
    template <typename T>
    void swap(T &a, T &b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }

    template <class Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef map_cell<Key, T> *cell;
        typedef map_iterator<Key, T, T *, T &> iterator;
        typedef map_iterator<Key, T, const T *, const T &> const_iterator;
        typedef reverse_map_iterator<Key, T, T *, T &> reverse_iterator;
        typedef reverse_map_iterator<Key, T, const T *, const T &> const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map;

        protected:
            Compare comp;
            value_compare(Compare c) : comp(c) {} // constructed with map's comparison object

        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };

    private:
        cell _root;
        cell _end;
        size_type _size;
        key_compare _comp;
        allocator_type _alloc;

        cell _new_cell(key_type key, mapped_type val, cell parent, bool empty = false)
        {
            cell ret = new map_cell<key_type, mapped_type>();
            ret->value = std::make_pair(key, val);
            ret->parent = parent;
            ret->left = nullptr;
            ret->right = nullptr;
            ret->empty = empty;
            return (ret);
        }

        void _cell_destruct(cell i)
        {
            if (i->right)
                this->_cell_destruct(i->right);
            if (i->left)
                this->_cell_destruct(i->left);
            delete (i);
        }

        // Simple initialization by creation empty cell
        void _map_init()
        {
            this->_end = this->_new_cell(key_type(), mapped_type(), nullptr, true);
            this->_root = this->_end;
        }

        cell _insert_cell(cell i, key_type key, mapped_type val, bool end = false)
        {
            if (this->_size == 1 || i->empty)
            {
                if (this->_size == 1)
                {
                    this->_root = this->_new_cell(key, val, i, end);
                    this->_root->right = this->_end;
                    this->_end->parent = this->_root;
                    return (this->_root);
                }
                i->parent->right = this->_new_cell(key, val, i, end);
                i->parent->right->right = this->_end;
                this->_end->parent = i->parent->right;
                return (i->parent->right);
            }
            if (key < i->value.first)
            {
                if (!i->left)
                {
                    i->left = this->_new_cell(key, val, i, end);
                    return (i->left);
                }
                return (this->_insert_cell(i->left, key, val));
            }
            else if (!i->right)
            {
                i->right = this->_new_cell(key, val, i);
                return (i->right);
            }
            else if (i->right->empty)
            {
                i->right = this->_new_cell(key, val, i);
                i->right->right = this->_end;
                this->_end->parent = i->right;
                return (i->right);
            }
            return (this->_insert_cell(i->right, key, val));
        }

        cell _find(cell i, key_type key) const
        {
            cell ret;
            if (i->left && (ret = this->_find(i->left, key)))
                return (ret);
            if (i->right && (ret = this->_find(i->right, key)))
                return (ret);
            if (i->value.first == key)
                return (i);
            return (nullptr);
        }

        void _delete_cell(cell del)
        {
            if (del == this->_root)
            {
                if (!del->left)
                    this->_root = del->right;
                else if (del->right->empty)
                {
                    this->_root = del->left;
                    cell tmp = del->left;
                    while (tmp->right)
                        tmp = tmp->right;
                    tmp->right = this->_end;
                    this->_end->parent = tmp;
                }
                else
                {
                    cell for_del = del->left;
                    while (for_del->right)
                        for_del = for_del->right;
                    ft::swap(del->value, for_del->value);
                    this->_delete_cell(for_del);
                    return;
                }
                this->_root->parent = nullptr;
                delete (del);
                return;
            }
            cell parent = del->parent;
            if (!del->left && !del->right)
            {
                if (del == parent->left)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            else if (del->left && !del->right)
            {
                if (del == parent->left)
                    parent->left = del->left;
                else
                    parent->right = del->left;
                del->left->parent = parent;
            }
            else if (!del->left && del->right)
            {
                if (del == parent->left)
                    parent->left = del->right;
                else
                    parent->right = del->right;
                del->right->parent = parent;
            }
            else if (del->left && del->right->empty)
            {
                parent->right = del->left;
                cell tmp = del->left;
                while (tmp->right)
                    tmp = tmp->right;
                tmp->right = this->_end;
                this->_end->parent = tmp;
            }
            else
            {
                cell for_del = del->left;
                while (for_del->right)
                    for_del = for_del->right;
                ft::swap(del->value, for_del->value);
                this->_delete_cell(for_del);
                return;
            }
            delete (del);
            return;
        }

    public:
        //  --- empty container constructor (default constructor) ---
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _size(0), _comp(comp), _alloc(alloc)
        {
            this->_map_init();
        }

        //  --- range constructor ---
        template <class InputIterator>
        map(InputIterator first, InputIterator last,
            const key_compare &comp = key_compare(),
            const allocator_type &alloc = allocator_type()) : _size(0), _comp(comp), _alloc(alloc)
        {
            this->_map_init();
            this->insert(first, last);
        }

        //  --- destructor ---
        ~map() {}

        //	Insert elements
        // -single element-
        std::pair<iterator, bool> insert(const value_type &val)
        {
            iterator tmp = this->find(val.first);
            if (tmp != this->end())
                return (std::make_pair(tmp, false));
            this->_size++;
            return (std::make_pair(iterator(this->_insert_cell(this->_root, val.first, val.second)), true));
        }

        iterator insert(iterator pos, const value_type &val)
        {
            iterator tmp = this->find(val.first);
            if (tmp != this->end())
                return (tmp);
            this->_size++;
            if (pos.getPtr()) // TODO
                return (iterator(this->_insert_cell(this->_root, val.first, val.second)));
            return (iterator(this->_insert_cell(pos.getPtr(), val.first, val.second)));
        }

        template <class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                this->insert(*first);
                first++;
            }
        }

        iterator find(const key_type &key)
        {
            cell tmp;
            if ((tmp = this->_find(this->_root, key)))
                return (iterator(tmp));
            return (this->end());
        }

        const_iterator find(const key_type &key) const
        {
            cell tmp;
            if ((tmp = this->_find(this->_root, key)))
                return (const_iterator(tmp));
            return (this->end());
        }

        // Access element
        mapped_type &operator[](const key_type &key)
        {
            iterator tmp = this->find(key);
            if (tmp != this->end())
                return (tmp->second);
            return (this->insert(std::make_pair(key, mapped_type())).first->second);
        }

        // Iterators
        iterator begin()
        {
            if (this->_size == 0)
                return (this->end());
            cell tmp = this->_root;
            while (tmp->left)
                tmp = tmp->left;
            return (iterator(tmp));
        }

        const_iterator begin() const
        {
            if (this->_size == 0)
                return (this->end());
            cell tmp = this->_root;
            while (tmp->left)
                tmp = tmp->left;
            return (const_iterator(tmp));
        }

        iterator end() { return (iterator(this->_end)); }
        const_iterator end() const { return (const_iterator(this->_end)); }

        reverse_iterator rbegin()
        {
            reverse_iterator it = this->_end;
            return (reverse_iterator((++it).getPtr()));
        }

        const_reverse_iterator rbegin() const
        {
            const_reverse_iterator it = this->_end;
            return (const_reverse_iterator((++it).getPtr()));
        }

        reverse_iterator rend() { return (reverse_iterator(this->_end)); }

        const_reverse_iterator rend() const { return (const_reverse_iterator(this->_end)); }

        // --- Return iterator to lower bound ---
        iterator lower_bound(const key_type &k)
        {
            iterator it = this->begin();
            while (it != this->end())
            {
                if (this->_comp(it->first, k) <= 0)
                    break;
                it++;
            }
            return (it);
        }

        const_iterator lower_bound(const key_type &k) const
        {
            const_iterator it = this->begin();
            while (it != this->end())
            {
                if (this->_comp(it->first == k) <= 0)
                    break;
                it++;
            }
            return (it);
        }

        // --- Return iterator to upper bound ---
        iterator upper_bound(const key_type &k)
        {
            iterator it = this->begin();
            while (it != this->end())
            {
                if (it->first != k && this->_comp(it->first, k) <= 0)
                    break;
                it++;
            }
            return (it);
        }

        const_iterator upper_bound(const key_type &k) const
        {
            const_iterator it = this->begin();
            while (it != this->end())
            {
                if (it->first != k && this->_comp(it->first, k) <= 0)
                    return (++it);
                it++;
            }
            return (it);
        }

        // ---Return container size---
        size_type size() const { return (_size); }

        // ---Return maximum size---
        size_type max_size() const
        {
            return (std::numeric_limits<size_type>::max() / sizeof(map_cell<Key, T>));
        }

        // ---Test whether container is empty---
        bool empty() const { return (_size == 0); }

        //	Erase elements
        // ---single element by iterator (position)---
        void erase(iterator position)
        {
            this->_delete_cell(position.getPtr());
            this->_size--;
        }

        // ---single element by key---
        size_type erase(const key_type &key)
        {
            iterator temp = this->find(key);
            if (temp == this->end())
                return (0);
            this->erase(temp);
            return (1);
        }

        // ---elements by range---
        void erase(iterator first, iterator last)
        {
            while (first != last)
                this->erase(first++);
        }

        // --- Swap content ---
        void swap(map &x)
        {
            map<Key, T, Compare, Alloc> temp = *this;
            *this = x;
            x = temp;
        }

        // --- Clear content ---
        void clear() { this->erase(this->begin(), this->end()); }

        // --- Return key comparison object ---
        key_compare key_comp() const { return (_comp); }

        // --- Return value comparison object ---
        value_compare value_comp() const { return (_comp); }

        // --- Return value comparison object ---
        size_type count(const key_type &k) const
        {
            if (this->find(k) != this->end())
                return (1);
            return (0);
        }

        // --- Get range of equal elements ---
        std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
        {
            return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
        }

        std::pair<iterator, iterator> equal_range(const key_type &k)
        {
            return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
        }

        friend bool operator==(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
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

        friend bool operator!=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
        {
            return (!(lhs == rhs));
        }

        friend bool operator<(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
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

        friend bool operator>(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
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

        friend bool operator<=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
        {
            return (!(lhs > rhs));
        }

        friend bool operator>=(const map<Key, T, Compare, Alloc> &lhs, const map<Key, T, Compare, Alloc> &rhs)
        {
            return (!(lhs < rhs));
        }
    };

    // Exchanges the contents of two maps
    template <class Key, class T, class Compare, class Alloc>
    void swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    }
}

#endif