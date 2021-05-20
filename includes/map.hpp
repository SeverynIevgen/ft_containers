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
    template <class Key, class T, class Compare = std::less<Key>,
              class Alloc = std::allocator<std::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef std::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef T &reference;
        typedef const T &const_reference;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef map_cell<Key, T> *cell;
        typedef map_iterator<Key, T, T *, T &> iterator;
        // typedef const_map_iterator<Key, T, Compare> const_iterator;
        // typedef reverse_map_iterator<Key, T, Compare> reverse_iterator;
        // typedef const_reverse_map_iterator<Key, T, Compare> const_reverse_iterator;
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
                // std::cout << "Value smaller...\n";
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
                // std::cout << "Value greater...\n";
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
            // std::cout << "------------------------------" << val.first << " => " << val.second << ";\n";
            return (std::make_pair(iterator(this->_insert_cell(this->_root, val.first, val.second)), true));
        }

        iterator insert(iterator pos, const value_type &val)
        {
            iterator tmp = this->find(val.first);
            // std::cout << "Here now_1...\n";
            if (tmp != this->end())
                return (std::make_pair(tmp, false));
            this->_size++;
            // std::cout << "Here now_1_2... Size = " << this->_size << "\n";
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
            // std::cout << "______key: " << key << "________\n";
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

        iterator end()
        {
            cell tmp = this->_root;
            while (tmp->right)
                tmp = tmp->right;
            return (iterator(tmp->right));
        }

        size_type size() const
        {
            return (_size);
        }
    };
}

#endif