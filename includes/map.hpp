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
              class Alloc = std::allocator<std::pair<const Key, T>>>
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
        // class value_compare : public std::binary_function<value_type, value_type, bool>
        // {
        //     friend class map;

        // protected:
        //     Compare comp;
        //     value_compare(Compare c) : comp(c) {}
        // public:
        //     typedef bool result_type;
        //     typedef value_type first_argument_type;
        //     typedef value_type second_argument_type;
        //     bool operator()(const value_type &x, const value_type &y) const
        //     {
        //         return comp(x.first, y.first);
        //     }
        // };

    private:
        cell _root;
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

        // Simple initialization by creation empty cell
        void _map_init()
        {
            _root = _new_cell(key_type(), mapped_type(), nullptr, true);
            // _root->right = _new_cell(key_type(), mapped_type(), _root, true);
            _size = 0;
        }

        // cell _insert_cell(cell i, key_type key, mapped_type val, bool empty = false)
        cell _insert_cell(cell i, key_type key, mapped_type val)
        {
            if (i->empty)
            {
                i->left = _new_cell(key, val, nullptr);
                i->empty = false;
                _root = i->left;
                free(i);
                return (_root);
            }
            // if (key < i->value.first && !empty)
            if (key < i->value.first)
            {
                if (!i->left)
                {
                    // i->left = _new_cell(key, val, i, empty);
                    i->left = _new_cell(key, val, i);
                    return (i->left);
                }
                return (_insert_cell(i->left, key, val));
            }
            else if (!i->right)
            {
                // i->left = _new_cell(key, val, i, empty);
                i->right = _new_cell(key, val, i);
                return (i->right);
            }
            // std::cout << "Here now3...\n";
            return (_insert_cell(i->right, key, val));
        }

        cell _find(cell i, key_type key) const
        {
            cell ret;
            if (i->left && (ret = _find(i->left, key)))
                return (ret);
            if (i->right && (ret = _find(i->right, key)))
                return (ret);
            if (i->value.first == key)
                return (i);
            return (nullptr);
        }

        void _delete_cell(cell del)
        {
            if (!del->parent)
            {
                if (!del->left && !del->right)
                    this->_root = nullptr;
                else if (!del->left)
                    this->_root = del->right;
                else if (!del->right)
                    this->_root = del->left;
                else
                {
                    cell for_del = del->left;
                    while (for_del->right)
                        for_del = for_del->right;
                    ft::swap(del->value, for_del->value);
                    _delete_cell(for_del);
                    return;
                }
                if (this->_root)
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
                delete (del);
                return;
            }
            if (del->left && !del->right)
            {
                if (del == parent->left)
                {
                    parent->left = del->left;
                    del->left->parent = parent;
                }
                else
                {
                    parent->right = del->right;
                    del->right->parent = parent;
                }
                delete (del);
                return;
            }
            if (!del->left && del->right)
            {
                if (del == parent->left)
                {
                    parent->left = del->right;
                    del->right->parent = parent;
                }
                else
                {
                    parent->right = del->left;
                    del->left->parent = parent;
                }
                delete (del);
                return;
            }
        }

    public:
        //  --- empty container constructor (default constructor) ---
        explicit map(const key_compare &comp = key_compare(),
                     const allocator_type &alloc = allocator_type()) : _size(0), _comp(comp), _alloc(alloc)
        {
            _map_init();
        }

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
                return (std::make_pair(tmp, false));
            this->_size++;
            return (iterator(this->_insert_cell(pos.getPtr(), val.first, val.second)));
        }

        iterator find(const key_type &key)
        {
            cell tmp; //todo --> maybe empty at first
            if ((tmp = this->_find(this->_root, key)))
                return (iterator(tmp));
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

        iterator end()
        {
            cell tmp = this->_root;
            while (tmp->right)
                tmp = tmp->right;
            return (iterator(tmp->right));
        }

        const_iterator end() const
        {
            cell tmp = this->_root;
            while (tmp->right)
                tmp = tmp->right;
            return (const_iterator(tmp->right));
        }

        reverse_iterator rbegin()
        {
            if (this->_size == 0)
                return (this->rend());
            cell tmp = this->_root;
            while (tmp->right)
                tmp = tmp->right;
            return (reverse_iterator(tmp));
        }

        const_reverse_iterator rbegin() const
        {
            if (this->_size == 0)
                return (this->rend());
            cell tmp = this->_root;
            while (tmp->right)
                tmp = tmp->right;
            return (const_reverse_iterator(tmp));
        }

        reverse_iterator rend()
        {
            cell tmp = this->_root;
            while (tmp->left)
                tmp = tmp->left;
            return (reverse_iterator(tmp->left));
        }

        const_reverse_iterator rend() const
        {
            cell tmp = this->_root;
            while (tmp->left)
                tmp = tmp->left;
            return (const_reverse_iterator(tmp->left));
        }

        // ---Return container size---
        size_type size() const { return (_size); }

        // ---Test whether container is empty---
        bool empty() const { return (_size == 0); }

        //	Erase elements
        // -single element (position)-
        void erase(iterator position)
        {
            this->_delete_cell(position.getPtr());
            this->_size--;
        }
    };
}

#endif