#include "includes/list.hpp"
#include "includes/vector.hpp"
#include "includes/map.hpp"
#include "includes/stack.hpp"
#include "includes/queue.hpp"
#include "includes/deque.hpp"

#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>

#include <iostream>
#include <cmath>

// // --------------stack::top--------------
// int main()
// {
//     ft::stack<int> mystack;

//     mystack.push(10);
//     mystack.push(20);

//     mystack.top() -= 5;

//     std::cout << "mystack.top() is now " << mystack.top() << '\n';

//     return 0;
// }

// // --------------stack::pop--------------
// // --------------stack::push--------------
// // --------------stack::empty--------------
// int main()
// {
//     ft::stack<int> mystack;
//     int sum(0);

//     for (int i = 1; i <= 10; i++)
//         mystack.push(i);

//     while (!mystack.empty())
//     {
//         sum += mystack.top();
//         mystack.pop();
//     }

//     std::cout << "total: " << sum << '\n';

//     return 0;
// }

// // --------------stack::size--------------
// int main()
// {
//     std::stack<int> myints;
//     std::cout << "0. size: " << myints.size() << '\n';

//     for (int i = 0; i < 5; i++)
//         myints.push(i);
//     std::cout << "1. size: " << myints.size() << '\n';

//     myints.pop();
//     std::cout << "2. size: " << myints.size() << '\n';

//     return 0;
// }

// // --------------stack::stack--------------
// int main()
// {
//     std::deque<int> mydeque(3, 100);   // deque with 3 elements
//     std::vector<int> myvector(2, 200); // vector with 2 elements

//     std::stack<int> first;           // empty stack
//     std::stack<int> second(mydeque); // stack initialized to copy of deque

//     ft::stack<int, std::vector<int>> third; // empty stack using vector
//     ft::stack<int, std::vector<int>> fourth(myvector);

//     std::cout << "size of first: " << first.size() << '\n';
//     std::cout << "size of second: " << second.size() << '\n';
//     std::cout << "size of third: " << third.size() << '\n';
//     std::cout << "size of fourth: " << fourth.size() << '\n';

//     return 0;
// }

// // -------------- std::relational operators (map) --------------
// int main()
// {
//     std::map<char, int> foo, bar;
//     foo['a'] = 100;
//     foo['b'] = 200;
//     bar['a'] = 10;
//     bar['z'] = 1000;

//     // foo ({{a, 100}, {b, 200}}) vs bar ({a, 10}, {z, 1000}}):
//     if (foo == bar)
//         std::cout << "foo and bar are equal\n";
//     if (foo != bar)
//         std::cout << "foo and bar are not equal\n";
//     if (foo < bar)
//         std::cout << "foo is less than bar\n";
//     if (foo > bar)
//         std::cout << "foo is greater than bar\n";
//     if (foo <= bar)
//         std::cout << "foo is less than or equal to bar\n";
//     if (foo >= bar)
//         std::cout << "foo is greater than or equal to bar\n";

//     return 0;
// }

// // --------------map::equal_range--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['a'] = 10;
//     mymap['b'] = 20;
//     mymap['c'] = 30;

//     std::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
//     ret = mymap.equal_range('b');

//     std::cout << "lower bound points to: ";
//     std::cout << ret.first->first << " => " << ret.first->second << '\n';

//     std::cout << "upper bound points to: ";
//     std::cout << ret.second->first << " => " << ret.second->second << '\n';

//     return 0;
// }

// // --------------map::lower_bound--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     ft::map<char, int>::iterator itlow, itup;

//     mymap['a'] = 20;
//     mymap['b'] = 40;
//     mymap['c'] = 60;
//     mymap['d'] = 80;
//     mymap['e'] = 100;

//     itlow = mymap.lower_bound('b'); // itlow points to b
//     itup = mymap.upper_bound('d');  // itup points to e (not d!)

//     mymap.erase(itlow, itup); // erases [itlow,itup)

//     // print content:
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::count--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     char c;

//     mymap['a'] = 101;
//     mymap['c'] = 202;
//     mymap['f'] = 303;

//     for (c = 'a'; c < 'h'; c++)
//     {
//         std::cout << c;
//         if (mymap.count(c) > 0)
//             std::cout << " is an element of mymap.\n";
//         else
//             std::cout << " is not an element of mymap.\n";
//     }

//     return 0;
// }

// // --------------map::find--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     ft::map<char, int>::iterator it;

//     mymap['a'] = 50;
//     mymap['b'] = 100;
//     mymap['c'] = 150;
//     mymap['d'] = 200;

//     it = mymap.find('b');
//     if (it != mymap.end())
//         mymap.erase(it);

//     // print content:
//     std::cout << "elements in mymap:" << '\n';
//     std::cout << "a => " << mymap.find('a')->second << '\n';
//     std::cout << "c => " << mymap.find('c')->second << '\n';
//     std::cout << "d => " << mymap.find('d')->second << '\n';

//     return 0;
// }

// // --------------map::value_comp--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['x'] = 1001;
//     mymap['y'] = 2002;
//     mymap['z'] = 3003;

//     std::cout << "mymap contains:\n";

//     std::pair<char, int> highest = *mymap.rbegin(); // last element

//     ft::map<char, int>::iterator it = mymap.begin();
//     do
//     {
//         std::cout << it->first << " => " << it->second << '\n';
//     } while (mymap.value_comp()(*it++, highest));

//     return 0;
// }

// // --------------map::key_comp--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     ft::map<char, int>::key_compare mycomp = mymap.key_comp();

//     mymap['a'] = 100;
//     mymap['b'] = 200;
//     mymap['c'] = 300;

//     std::cout << "mymap contains:\n";

//     char highest = mymap.rbegin()->first; // key value of last element

//     ft::map<char, int>::iterator it = mymap.begin();
//     do
//     {
//         std::cout << it->first << " => " << it->second << '\n';
//     } while (mycomp((*it++).first, highest));

//     return 0;
// }

// // --------------map::clear--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['x'] = 100;
//     mymap['y'] = 200;
//     mymap['z'] = 300;

//     std::cout << "mymap contains:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     mymap.clear();
//     mymap['a'] = 1101;
//     mymap['b'] = 2202;

//     std::cout << "mymap contains:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------swap(map)--------------
// // --------------map::swap--------------
// int main()
// {
//     ft::map<char, int> foo, bar;

//     foo['x'] = 100;
//     foo['y'] = 200;

//     bar['a'] = 11;
//     bar['b'] = 22;
//     bar['c'] = 33;


// 	std::cout << "Startttt\n";
//     foo.swap(bar);

//     std::cout << "foo contains:\n";
//     for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     std::cout << "bar contains:\n";
//     for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     swap(foo, bar);
//     std::cout << "foo contains:\n";
//     for (ft::map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     std::cout << "bar contains:\n";
//     for (ft::map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::erase--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     ft::map<char, int>::iterator it;

//     // insert some values:
//     mymap['a'] = 10;
//     mymap['b'] = 20;
//     mymap['c'] = 30;
//     mymap['d'] = 40;
//     mymap['e'] = 50;
//     mymap['f'] = 60;

//     it = mymap.find('b');
//     mymap.erase(it); // erasing by iterator

//     mymap.erase('c'); // erasing by key

//     it = mymap.find('e');
//     mymap.erase(it, mymap.end()); // erasing by range

//     // show content:
//     for (it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::insert--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     // first insert function version (single parameter):
//     mymap.insert(std::pair<char, int>('a', 100));
//     mymap.insert(std::pair<char, int>('z', 200));
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";
//     mymap.insert(std::pair<char, int>('z', 500));
//     std::cout << "\nMap after new insert is not changed:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     // second insert function version (with hint position):
//     ft::map<char, int>::iterator it = mymap.begin();
//     mymap.insert(it, std::pair<char, int>('b', 300)); // max efficiency inserting
//     mymap.insert(it, std::pair<char, int>('c', 400)); // no max efficiency inserting
//     std::cout << "\nMap after new insertions:\n";
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     // third insert function version (range insertion):
//     ft::map<char, int> anothermap;
//     anothermap.insert(mymap.begin(), mymap.find('c'));
//     std::cout << "\nAnothermap contains:\n";
//     for (ft::map<char, int>::iterator it = anothermap.begin(); it != anothermap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     return 0;
// }

// // --------------map::operator[]--------------
// int main()
// {
//     ft::map<char, std::string> mymap;

//     mymap['a'] = "an element";
//     mymap['b'] = "another element";
//     mymap['c'] = mymap['b'];

//     std::cout << "mymap['a'] is " << mymap['a'] << '\n';
//     std::cout << "mymap['b'] is " << mymap['b'] << '\n';
//     std::cout << "mymap['c'] is " << mymap['c'] << '\n';
//     std::cout << "mymap['d'] is " << mymap['d'] << '\n';

//     std::cout << "mymap now contains " << mymap.size() << " elements.\n";

//     return 0;
// }

// // --------------map::max_size--------------
// int main()
// {
//     int i;
//     ft::map<int, int> mymap;

//     if (mymap.max_size() > 1000)
//     {
//         for (i = 0; i < 1000; i++)
//             mymap[i] = 0;
//         std::cout << "The map contains 1000 elements.\n";
//     }
//     else
//         std::cout << "The map could not hold 1000 elements.\n";
//     std::cout << "max_size: " << mymap.max_size() << "\n";

//     return 0;
// }

// // --------------map::empty--------------
// // --------------map::size--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     std::cout << "mymap.size() is " << mymap.size() << '\n';
//     mymap['g'] = 101;
//     mymap['b'] = 202;
//     mymap['d'] = 300;
//     mymap['c'] = 302;
//     mymap['f'] = 202;
//     mymap['j'] = 300;
//     mymap['n'] = 302;

//     std::cout << "mymap.size() is " << mymap.size() << '\n';

//     while (!mymap.empty())
//     {
//         std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
//         mymap.erase(mymap.begin());
//     }
//     std::cout << "mymap.size() is " << mymap.size() << '\n';
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     return 0;
// }

// // --------------map::rend--------------
// // --------------map::rbegin--------------
// int main()
// {
//     ft::map<char, int> mymap;

//     mymap['y'] = 100;
//     mymap['z'] = 200;
//     mymap['x'] = 300;

//     // show content:
//     ft::map<char, int>::reverse_iterator rit;
//     for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
//         std::cout << rit->first << " => " << rit->second << '\n';

//     return 0;
// }

// // --------------map::end--------------
// // --------------map::begin--------------
// int main()
// {
//     ft::map<char, int> mymap;
//     mymap['c'] = 100;
//     mymap['a'] = 200;
//     mymap['b'] = 300;

//     // show content:
//     for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
//         std::cout << it->first << " => " << it->second << '\n';
//     ft::map<char, int>::iterator it = mymap.begin();
//     std::cout << it->first << " => " << it->second << '\t';
//     it++;
//     std::cout << it->first << " => " << it->second << '\t';
//     ++it;
//     std::cout << it->first << " => " << it->second << '\n';

//     return 0;
// }

// // --------------map::size--------------
// // --------------map::operator=--------------
// int main()
// {
//     ft::map<char, int> first;
//     ft::map<char, int> second;

//     first['x'] = 12;
//     first['a'] = 16;
//     first['z'] = 32;

//     second = first;               // second now contains 3 ints
//     first = ft::map<char, int>(); // and first is now empty

//     std::cout << "Size of first: " << first.size() << '\n';
//     std::cout << "Size of second: " << second.size() << '\n';
//     for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";
//     return 0;
// }

// // --------------map::map--------------
// int main()
// {
//     ft::map<char, int> first; // empty constructor (default constructor)
//     first['b'] = 10;
//     first['a'] = 30;
//     first['c'] = 50;
//     first['c'] = 60;
//     first['d'] = 70;
//     std::cout << "The contents of the first map are:\n";
//     for (ft::map<char, int>::iterator it = first.begin(); it != first.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     ft::map<char, int> second(first.begin(), first.end()); // range constructor
//     std::cout << "\nThe contents of the second map are:\n";
//     for (ft::map<char, int>::iterator it = second.begin(); it != second.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     ft::map<char, int> third(second); // copy constructor
//     std::cout << "\nThe contents of the third map are:\n";
//     for (ft::map<char, int>::iterator it = third.begin(); it != third.end(); ++it)
//         std::cout << it->first << " => " << it->second << ";\t";

//     return 0;
// }

// // std::relational operators (vector)
// int main () {
//   ft::vector<int> foo(3,100);   // three ints with a value of 100
//   ft::vector<int> bar(2,200);   // two ints with a value of 200

//   if (foo == bar) std::cout << "foo and bar are equal\n";
//   if (foo != bar) std::cout << "foo and bar are not equal\n";
//   if (foo < bar) std::cout << "foo is less than bar\n";
//   if (foo > bar) std::cout << "foo is greater than bar\n";
//   if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }

// // --------------swap(vector)--------------
// int main () {
//   ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (ft::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (ft::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::swap--------------
// int main () {
//   ft::vector<int> foo(3, 100);   // three ints with a value of 100
//   ft::vector<int> bar(5, 200);   // five ints with a value of 200

//   std::cout << "foo contains:";
//   for (unsigned i = 0; i < foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i = 0; i < bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
//   std::cout << "foo capacity: " << foo.capacity() << std::endl;
//   std::cout << "bar capacity: " << bar.capacity() << std::endl;

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i = 0; i < foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i = 0; i < bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';
//   std::cout << "foo capacity: " << foo.capacity() << std::endl;
//   std::cout << "bar capacity: " << bar.capacity() << std::endl;

//   return 0;
// }

// // --------------vector::erase--------------
// int main() {
//   ft::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i = 1; i <= 10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase(myvector.begin() + 5);

//   // erase the first 3 elements:
//   myvector.erase(myvector.begin(), myvector.begin() + 3);

//   std::cout << "myvector contains:";
//   for (unsigned i = 0; i < myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::insert--------------
// int main () {
//   ft::vector<int> myvector(3, 100);
//   ft::vector<int>::iterator it;
//   ft::vector<int>::iterator it2;

//   it = myvector.begin();
//   it = myvector.insert(it, 200);

//   std::cout << "1. myvector contains:";
//   for (it2 = myvector.begin(); it2 < myvector.end(); it2++)
//     std::cout << ' ' << *it2;
//   std::cout << '\n';

//   myvector.insert(it, 2, 300);
//   std::cout << "2. myvector contains:";
//   for (it2 = myvector.begin(); it2 < myvector.end(); it2++)
//     std::cout << ' ' << *it2;
//   std::cout << '\n';

//   // "it" no longer valid, get a new one:
//   it = myvector.begin();
//   ft::vector<int> anothervector(2, 400);
//   myvector.insert(it + 2, anothervector.begin(), anothervector.end());
//   std::cout << "3. myvector contains:";
//   for (it2 = myvector.begin(); it2 < myvector.end(); it2++)
//     std::cout << ' ' << *it2;
//   std::cout << '\n';

//   int myarray[] = {501, 502, 503};
//   myvector.insert(myvector.begin(), myarray, myarray + 3);
//   std::cout << "4. myvector contains:";
//   for (it2 = myvector.begin(); it2 < myvector.end(); it2++)
//     std::cout << ' ' << *it2;
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::pop_back--------------
// int main()
// {
//     ft::vector<int> myvector;
//     int sum = 0;
//     myvector.push_back(100);
//     myvector.push_back(200);
//     myvector.push_back(300);
//     myvector.push_back(5);
//     myvector.pop_back();
//       myvector.push_back(55);

//     while (!myvector.empty())
//     {
//         sum += myvector.back();
//         std::cout << myvector.back() << "--";
//         myvector.pop_back();
//     }
//     std::cout << "\nSize of empty mylist: " << myvector.size() << std::endl;
//     myvector.pop_back();
//     std::cout << "Size of error mylist: " << myvector.size() << std::endl;
//     myvector.push_back(1000);
//     myvector.push_back(2000);

//     std::cout << "\nThe elements of myvector summed " << sum << "\nmyvector = { ";
//     for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
//     {
//         std::cout << *it << " ";
//     }
//     std::cout << "};\n";
//     std::cout << "Size of mylist: " << myvector.size() << std::endl;
//     return 0;
// }

// // --------------vector::clear--------------
// // --------------vector::push_back--------------
// int main () {
//   ft::vector<int> myvector;
//   myvector.push_back(100);
//   myvector.push_back(200);
//   myvector.push_back(300);

//   std::cout << "myvector contains:";
//   for (unsigned i = 0; i < myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   myvector.clear();
//   std::cout << "capacity: " << myvector.capacity() << '\n';
//   std::cout << "size: " << myvector.size() << '\n';
//   myvector.push_back(1101);
//   myvector.push_back(2202);

//   std::cout << "myvector contains:";
//   for (unsigned i = 0; i < myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::assign--------------
// int main () {
//   ft::vector<int> first;
//   ft::vector<int> second;
//   ft::vector<int> third;

//   first.assign(7, 100);             // 7 ints with a value of 100
//   // first.assign(2, 50);

//   ft::vector<int>::iterator it;
//   for (it = first.begin(); it != first.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//   std::cout << "1. capacity: " << first.capacity() << '\n';

//   it = first.begin() + 1;

//   second.assign(it, first.end() - 1); // the 5 central values of first
//   for (it = second.begin(); it != second.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//   std::cout << "2. capacity: " << second.capacity() << '\n';

//   int myints[] = {1776, 7, 4};
//   third.assign(myints, myints + 3);   // assigning from array.
//   for (it = third.begin(); it != third.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//   std::cout << "3. capacity: " << third.capacity() << '\n';

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
//   return 0;
// }

// // --------------vector::back--------------
// int main () {
//   std::vector<int> myvector;

//   myvector.push_back(10);

//   while (myvector.back() != 0)
//     myvector.push_back (myvector.back() - 1);

//   std::cout << "myvector contains:";
//   for (unsigned i = 0; i < myvector.size() ; i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::front--------------
// int main () {
//   ft::vector<int> myvector;

//   myvector.push_back(78);
//   myvector.push_back(16);

//   // now front equals 78, and back 16

//   myvector.front() -= myvector.back();

//   std::cout << "myvector.front() is now " << myvector.front() << '\n';

//   return 0;
// }

// // --------------vector::operator[]--------------
// // --------------vector::at--------------
// int main () {
//   ft::vector<int> myvector (10);   // 10 zero-initialized ints

//   // assign some values:
//   for (unsigned i = 0; i < myvector.size(); i++)
//     myvector.at(i) = i;

//   std::cout << "1. myvector contains:";
//   for (unsigned i = 0; i < myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   std::cout << "2. myvector contains:";
//   for (unsigned i = 0; i < myvector.size(); i++)
//     std::cout << ' ' << myvector.at(i);
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::reserve--------------
// int main () {
//   ft::vector<int>::size_type sz;

//   ft::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i = 0; i < 100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   ft::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   for (int i = 0; i < 100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }
//   return 0;
// }

// // --------------vector::empty--------------
// int main()
// {
// 	ft::vector<int> myvector;
// 	int sum(0);

// 	for (int i = 1; i <= 10; i++)
// 		myvector.push_back(i);

// 	while (!myvector.empty())
// 	{
// 		sum += myvector.back();
// 		myvector.pop_back();
// 	}

// 	std::cout << "total: " << sum << '\n';

// 	return 0;
// }

// // --------------vector::resize--------------
// int main()
// {
// 	ft::vector<int> myvector;

// 	// set some initial content:
// 	for (int i = 1; i < 10; i++)
// 		myvector.push_back(i);

// 	std::cout << "1. size: " << myvector.size() << '\n';
// 	myvector.resize(5);
// 	std::cout << "2. size: " << myvector.size() << '\n';
// 	myvector.resize(8, 100);
// 	std::cout << "3. size: " << myvector.size() << '\n';
// 	myvector.resize(12);
// 	std::cout << "4. size: " << myvector.size() << '\n';
// 	std::cout << "4. capacity: " << myvector.capacity() << '\n';

// 	std::cout << "myvector contains:";
// 	for (size_t i = 0; i < myvector.size(); i++)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------vector::max_size--------------
// int main()
// {
// 	ft::vector<int> myvector;

// 	// set some content in the vector:
// 	for (int i = 0; i < 100; i++)
// 		myvector.push_back(i);

// 	std::cout << "size: " << myvector.size() << "\n";
// 	std::cout << "capacity: " << myvector.capacity() << "\n";
// 	std::cout << "max_size: " << myvector.max_size() << "\n";
// 	return 0;
// }

// // --------------vector::size--------------
// int main()
// {
// 	ft::vector<int> myints;
// 	std::cout << "0. size: " << myints.size() << '\n';

// 	for (int i = 0; i < 10; i++)
// 		myints.push_back(i);
// 	std::cout << "1. size: " << myints.size() << '\n';
// 	std::cout << "1. capacity: " << myints.capacity() << '\n';

// 	myints.insert(myints.end(), 10, 100);
// 	std::cout << "2. size: " << myints.size() << '\n';

// 	myints.pop_back();
// 	std::cout << "3. size: " << myints.size() << '\n';
// 	std::cout << "3. capacity: " << myints.capacity() << '\n';
// 	std::cout << "myvector contains:";
// 	for (ft::vector<int>::iterator it = myints.begin(); it != myints.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------vector::rend--------------
// // --------------vector::rbegin--------------
// int main()
// {
// 	ft::vector<int> myvector(5); // 5 default-constructed ints

// 	int i = 0;

// 	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
// 	for (; rit != myvector.rend(); ++rit)
// 		*rit = ++i;

// 	std::cout << "myvector contains:";
// 	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------vector::end--------------
// // --------------vector::begin--------------
// int main()
// {
// 	ft::vector<int> myvector;
// 	std::cout << "Capacity: " << myvector.capacity() << std::endl;
// 	std::cout << "Size: " << myvector.size() << std::endl;
// 	for (int i = 1; i <= 5; i++)
// 		myvector.push_back(i);

// 	std::cout << "myvector contains:";
// 	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';
// 	std::cout << "Capacity: " << myvector.capacity() << std::endl;
// 	std::cout << "Size: " << myvector.size() << std::endl;

// 	return 0;
// }

// // --------------vector::operator=--------------
// int main()
// {
// 	ft::vector<int> foo(3, 0);
// 	ft::vector<int> bar(5, 0);

// 	bar = foo;
// 	foo = ft::vector<int>();

// 	std::cout << "Size of foo: " << int(foo.size()) << '\n';
// 	std::cout << "Size of bar: " << int(bar.size()) << '\n';
// 	return 0;
// }

// // --------------vector::capacity--------------
// // --------------vector::vector--------------
// int main()
// {
// 	// constructors used in the same order as described above:
// 	ft::vector<int> first;								 // empty list of ints
// 	ft::vector<int> second(5, 100);						 // four ints with value 100
// 	ft::vector<int> third(second.begin(), second.end()); // iterating through second
// 	ft::vector<int> fourth(third);						 // a copy of third

// 	// the iterator constructor can also be used to construct from arrays:
// 	int myints[] = {16, 2, 77, 29};
// 	ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

// 	std::cout << "The contents of the first are: ";
// 	for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the second are: ";
// 	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the third are:  ";
// 	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the fourth are: ";
// 	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the fifth are:  ";
// 	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "Capacity: " << first.capacity() << std::endl;
// 	std::cout << "Size: " << first.size() << std::endl;
// 	std::cout << "Capacity: " << second.capacity() << std::endl;
// 	std::cout << "Size: " << second.size() << std::endl;
// 	std::cout << "Capacity: " << third.capacity() << std::endl;
// 	std::cout << "Size: " << third.size() << std::endl;
// 	std::cout << "Capacity: " << fourth.capacity() << std::endl;
// 	std::cout << "Size: " << fourth.size() << std::endl;
// 	std::cout << "Capacity: " << fifth.capacity() << std::endl;
// 	std::cout << "Size: " << fifth.size() << std::endl;

// 	return 0;
// }

// ---------------------------------------------------------------------------------------------------------

// // std::relational operators (list)
// int main()
// {
// 	ft::list<int> a;
// 	a.push_back(10);
// 	a.push_back(20);
// 	a.push_back(30);
// 	ft::list<int> b;
// 	b.push_back(10);
// 	b.push_back(20);
// 	b.push_back(30);
// 	ft::list<int> c;
// 	c.push_back(30);
// 	c.push_back(20);
// 	c.push_back(10);

// 	if (a == b)
// 		std::cout << "a and b are equal\n";
// 	if (b != c)
// 		std::cout << "b and c are not equal\n";
// 	if (b < c)
// 		std::cout << "b is less than c\n";
// 	if (c > b)
// 		std::cout << "c is greater than b\n";
// 	if (a <= b)
// 		std::cout << "a is less than or equal to b\n";
// 	if (a >= b)
// 		std::cout << "a is greater than or equal to b\n";

// 	return 0;
// }

// // --------------list::sort--------------
// // comparison, not case sensitive.
// bool compare_nocase(const std::string &first, const std::string &second)
// {
// 	unsigned int i = 0;
// 	while ((i < first.length()) && (i < second.length()))
// 	{
// 		if (tolower(first[i]) < tolower(second[i]))
// 			return true;
// 		else if (tolower(first[i]) > tolower(second[i]))
// 			return false;
// 		++i;
// 	}
// 	return (first.length() < second.length());
// }

// int main()
// {
// 	ft::list<std::string> mylist;
// 	ft::list<std::string>::iterator it;
// 	mylist.push_back("one");
// 	mylist.push_back("two");
// 	mylist.push_back("Three");

// 	mylist.sort();

// 	std::cout << "mylist contains:";
// 	for (it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	mylist.sort(compare_nocase);

// 	std::cout << "mylist contains:";
// 	for (it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::reverse--------------
// int main()
// {
// 	ft::list<int> mylist;

// 	for (int i = 1; i < 10; ++i)
// 		mylist.push_back(i);

// 	mylist.reverse();

// 	std::cout << "mylist contains:";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;

// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::merge--------------
// // compare only integral part:
// bool mycomparison(double first, double second)
// {
// 	return (int(first) < int(second));
// }

// int main()
// {
// 	ft::list<double> first, second;

// 	first.push_back(3.9);
// 	first.push_back(2.2);
// 	first.push_back(2.9);

// 	second.push_back(3.7);
// 	second.push_back(7.1);
// 	second.push_back(1.4);

// 	first.sort();
// 	//   second.sort();
// 	first.merge(second);

// 	// (second is now empty)
// 	second.push_back(2.1);

// 	first.merge(second, mycomparison);

// 	std::cout << "first contains:";
// 	for (ft::list<double>::iterator it = first.begin(); it != first.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// --------------list::unique--------------
// a binary predicate implemented as a function:
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

// a binary predicate implemented as a class:
struct is_near
{
	bool operator()(double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
};

// int main()
// {
// 	double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14, 12.77, 73.35, 72.25, 15.3, 72.25};
// 	ft::list<double> mylist(mydoubles, mydoubles + 10);

// 	mylist.sort(); //  2.72,  3.14, 12.15, 12.77, 12.77,
// 				   // 15.3,  72.25, 72.25, 73.0,  73.35

// 	mylist.unique(); //  2.72,  3.14, 12.15, 12.77
// 					 // 15.3,  72.25, 73.0,  73.35

// 	mylist.unique(same_integral_part); //  2.72,  3.14, 12.15
// 									   // 15.3,  72.25, 73.0

// 	mylist.unique(is_near()); //  2.72, 12.15, 72.25

// 	std::cout << "mylist contains:";
// 	for (ft::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // list::remove_if
// // a predicate implemented as a function:
// bool single_digit (const int& value) { return (value < 10); }

// // a predicate implemented as a class:
// struct is_odd {
//   bool operator() (const int& value) { return (value % 2) == 1; }
// };

// int main () {
//   int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
//   ft::list<int> mylist (myints, myints + 8);   // 15 36 7 17 20 39 4 1

//   mylist.remove_if (single_digit);           // 15 36 17 20 39

//   mylist.remove_if(is_odd());               // 36 20

//   std::cout << "mylist contains:";
//   for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::remove--------------
// int main()
// {
// 	int myints[] = {17, 89, 20, 14};
// 	ft::list<int> mylist(myints, myints + 4);

// 	mylist.remove(20);
// 	mylist.remove(25);

// 	std::cout << "mylist contains:";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// TODO check
// // --------------list::splice--------------
// int main()
// {
// 	std::list<int> mylist1, mylist2;
// 	std::list<int>::iterator it;

// 	// set some initial values:
// 	for (int i = 1; i <= 4; ++i)
// 		mylist1.push_back(i); // mylist1: 1 2 3 4

// 	for (int i = 1; i <= 3; ++i)
// 		mylist2.push_back(i * 10); // mylist2: 10 20 30

// 	it = mylist1.begin();
// 	++it; // points to 2

// 	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
// 								 // mylist2 (empty)
// 								 // "it" still points to 2 (the 5th element)

// 	mylist2.splice(mylist2.begin(), mylist1, it);
// 	// mylist1: 1 10 20 30 3 4
// 	// mylist2: 2
// 	// "it" is now invalid.
// 	std::cout << "*it: " << *it << std::endl;
// 	it = mylist1.begin();
// 	++it;
// 	++it;
// 	++it;
// 	std::cout << "*it: " << *it << std::endl; // "it" points now to 30

// 	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
// 	// mylist1: 30 3 4 1 10 20

// 	std::cout << "mylist1 contains:";
// 	for (it = mylist1.begin(); it != mylist1.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	std::cout << "mylist2 contains:";
// 	for (it = mylist2.begin(); it != mylist2.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::resize--------------
// int main()
// {
// 	ft::list<int> mylist;

// 	// set some initial content:
// 	for (int i = 1; i < 10; ++i)
// 		mylist.push_back(i);

// 	mylist.resize(5);
// 	mylist.resize(8, 100);
// 	mylist.resize(12);

// 	std::cout << "mylist contains:";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;

// 	std::cout << '\n';

// 	return 0;
// }

// // --------------swap(list)--------------
// int main()
// {
// 	ft::list<int> foo(3, 100); // three ints with a value of 100
// 	ft::list<int> bar(5, 200); // five ints with a value of 200

// 	ft::swap(foo, bar);

// 	std::cout << "foo contains:";
// 	for (ft::list<int>::iterator it = foo.begin(); it != foo.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	std::cout << "bar contains:";
// 	for (ft::list<int>::iterator it = bar.begin(); it != bar.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::swap--------------
// int main()
// {
// 	ft::list<int> first(3, 100);  // three ints with a value of 100
// 	ft::list<int> second(5, 200); // five ints with a value of 200

// 	std::cout << "first contains:";
// 	for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	std::cout << "second contains:";
// 	for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	first.swap(second);
// 	// ft::swap(first, second);

// 	std::cout << "first contains:";
// 	for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	std::cout << "second contains:";
// 	for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::erase--------------
// int main()
// {
//     std::list<int> mylist;
//     std::list<int>::iterator it, it1, it2;

//   // set some values:
//   for (int i = 1; i < 10; ++i) mylist.push_back(i * 10);

//                               // 10 20 30 40 50 60 70 80 90
//   it1 = mylist.begin();       // ^                          ^
//   it2 = mylist.end();
//   --it2;  --it2;  --it2;      // ^                 ^
//   ++it1;                      //    ^              ^

//    it1 = mylist.erase(it1);   // 10 30 40 50 60 70 80 90
//                               //    ^           ^
//    it2 = mylist.erase (it2);  // 10 30 40 50 60 80 90
//                               //    ^           ^
//   ++it1;                      //       ^        ^
//   --it2;                      //       ^     ^

// std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   mylist.erase(it1, it2);     // 10 30 60 80 90
//                               //        ^

//   std::cout << "mylist contains:";
//   for (it1 = mylist.begin(); it1 != mylist.end(); ++it1)
//     std::cout << ' ' << *it1;
//   std::cout << '\n';
//   while (true) { } //for checking leaks
//     return 0;
// }

// // --------------list::insert--------------
// int main ()
// {
//   ft::list<int> mylist;
//   ft::list<int>::iterator it;

//   // set some initial values:
//   for (int i = 1; i <= 5; ++i) mylist.push_back(i); // 1 2 3 4 5

//   it = mylist.begin();
//   ++it;       // it points now to number 2               ^

//   mylist.insert (it, 10);                        // 1 10 2 3 111 4 5
//   ++it;    ++it;
//   mylist.insert (it, 111);
//   // "it" points to number 111 now                            ^
//   mylist.insert (it, 2, 20);                      // 1 10 2 3 111 20 20 4 5

//   --it;       // it points now to the second 20                      ^

//   std::vector<int> myvector (2, 30);
//   mylist.insert(it, myvector.begin(), myvector.end());
//                                                 // 1 10 2 3 111 20 30 30 20 4 5
//                                                 //                       ^
//   std::cout << "mylist contains:";
//   for (it = mylist.begin(); it != mylist.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------list::pop_front--------------
// int main()
// {
// 	ft::list<int> mylist;
// 	mylist.push_back(100);
// 	mylist.push_back(200);
// 	mylist.push_back(300);

// 	std::cout << "Popping out the elements in mylist:";
// 	while (!mylist.empty())
// 	{
// 		std::cout << ' ' << mylist.front();
// 		mylist.pop_front();
// 	}
// 	std::cout << "\nFinal size of mylist is " << mylist.size() << '\n';
// 	return 0;
// }

// // --------------list::push_front--------------
// int main()
// {
// 	ft::list<int> mylist(2, 100); // two ints with a value of 100
// 	mylist.push_front(200);
// 	mylist.push_front(300);

// 	std::cout << "mylist contains:";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;

// 	std::cout << '\n';
// 	return 0;
// }

// // --------------list::pop_back--------------
// int main()
// {
// 	ft::list<int> mylist;
// 	int sum = 0;
// 	mylist.push_back(100);
// 	mylist.push_back(200);
// 	mylist.push_back(300);
// 	mylist.push_back(5);
// 	mylist.pop_back();
// 	mylist.push_back(55);

// 	while (!mylist.empty())
// 	{
// 		sum += mylist.back();
// 		std::cout << mylist.back() << "--";
// 		mylist.pop_back();
// 	}

// 	std::cout << "\nThe elements of mylist summed " << sum << "\nmylist = { ";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << "};\n";
// 	std::cout << "Size of mylist: " << mylist.size() << std::endl;
// 	return 0;
// }

// // --------------list::clear--------------
// // --------------list::push_back--------------
// int main()
// {
// 	ft::list<int> mylist;
// 	ft::list<int>::iterator it;

// 	mylist.push_back(100);
// 	mylist.push_back(200);
// 	mylist.push_back(300);

// 	std::cout << "mylist contains:";
// 	for (it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	mylist.clear();
// 	mylist.push_back(1101);
// 	mylist.push_back(2202);

// 	std::cout << "mylist contains:";
// 	for (it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::assign--------------
// int main()
// {
// 	ft::list<int> first;
// 	ft::list<int> second;
// 	ft::list<int> third;

// 	first.assign(7, 100); // 7 ints with value 100
// 	ft::list<int>::iterator it1, it2;
// 	it1 = first.begin();
// 	it1++;
// 	it1++;
// 	it2 = first.end();
// 	it2--;
// 	third.assign(it1, it2);
// 	second.assign(++first.begin(), --first.end()); // a copy of first without begin and end

// 	int myints[] = {1776, 7, 4};
// 	first.assign(myints, myints + 3); // assigning from array

// 	std::cout << "Size of first: " << int(first.size()) << '\n';
// 	std::cout << "Size of second: " << int(second.size()) << '\n';
// 	std::cout << "Size of third: " << int(third.size()) << '\n';
// 	std::cout << "third contains:";
// 	for (it1 = third.begin(); it1 != third.end(); ++it1)
// 		std::cout << ' ' << *it1;
// 	std::cout << '\n';
// 	return 0;
// }

// // --------------list::back--------------
// int main()
// {
// 	ft::list<int> mylist;

// 	mylist.push_back(10);

// 	while (mylist.back() != 0)
// 		mylist.push_back(mylist.back() - 1);

// 	std::cout << "mylist contains:";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;

// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::front--------------
// int main()
// {
// 	ft::list<int> mylist;

// 	mylist.push_back(77);
// 	mylist.push_back(22);

// 	// now front equals 77, and back 22

// 	mylist.front() -= mylist.back();

// 	std::cout << "mylist.front() is now " << mylist.front() << '\n';

// 	return 0;
// }

// // list::max_size
// int main()
// {
// 	std::list<int> mylist1;
// 	ft::list<int> mylist2;

// 	std::cout << "Max size of std_list: " << mylist1.max_size() << std::endl;
// 	std::cout << "Max size of ft_list:  " << mylist2.max_size() << std::endl;

// 	return 0;
// }

// // --------------list::empty--------------
// int main()
// {
// 	ft::list<int> mylist;
// 	int sum(0);

// 	for (int i = 1; i <= 10; ++i)
// 		mylist.push_back(i);

// 	while (!mylist.empty())
// 	{
// 		sum += mylist.front();
// 		std::cout << "Front: " << mylist.front() << "\n";
// 		mylist.pop_front();
// 	}

// 	std::cout << "total: " << sum << '\n';

// 	return 0;
// }

// // --------------list::rend--------------
// // --------------list::rbegin--------------
// int main()
// {
// 	ft::list<int> mylist;
// 	for (int i = 1; i <= 5; ++i)
// 		mylist.push_back(i);

// 	std::cout << "mylist backwards:";
// 	for (ft::list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit)
// 		std::cout << ' ' << *rit;

// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::end--------------
// // --------------list::begin--------------
// int main()
// {
// 	int myints[] = {75, 23, 65, 42, 13};
// 	ft::list<int> mylist(myints, myints + 5);

// 	std::cout << "mylist contains:";
// 	for (ft::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
// 		std::cout << ' ' << *it;

// 	std::cout << '\n';

// 	return 0;
// }

// // --------------list::operator=--------------
// int main()
// {
// 	ft::list<int> first(3);	 // list of 3 zero-initialized ints
// 	ft::list<int> second(5); // list of 5 zero-initialized ints

// 	second = first;
// 	first = ft::list<int>();

// 	std::cout << "Size of first: " << int(first.size()) << '\n';
// 	std::cout << "Size of second: " << int(second.size()) << '\n';
// 	return 0;
// }

// // --------------list::list--------------
// int main()
// {
// 	// constructors used in the same order as described above:
// 	ft::list<int> first;							   // empty list of ints
// 	ft::list<int> second(4, 100);					   // four ints with value 100
// 	ft::list<int> third(second.begin(), second.end()); // iterating through second
// 	ft::list<int> fourth(third);					   // a copy of third

// 	// the iterator constructor can also be used to construct from arrays:
// 	int myints[] = {16, 2, 77, 29};
// 	ft::list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

// 	std::cout << "The contents of the first are: ";
// 	for (ft::list<int>::iterator it = first.begin(); it != first.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the second are: ";
// 	for (ft::list<int>::iterator it = second.begin(); it != second.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the third are: ";
// 	for (ft::list<int>::iterator it = third.begin(); it != third.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the fourth are: ";
// 	for (ft::list<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	std::cout << "The contents of the fifth are: ";
// 	for (ft::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';

// 	return 0;
// }

// int main()
// {
// 	ft::list<int> mylist1, mylist2;
// 	ft::list<int>::iterator it;

// 	// set some initial values:
// 	for (int i = 1; i <= 4; ++i)
// 		mylist1.push_back(i); // mylist1: 1 2 3 4

// 	for (int i = 1; i <= 3; ++i)
// 		mylist2.push_back(i * 10); // mylist2: 10 20 30

// 	it = mylist1.end();
// 	++it; ++it; // points to 2 ?
// 	std::cout << "*it: " << *it << std::endl; // "it" points now to 2

// 	mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
// 								 // mylist2 (empty)
// 								 // "it" still points to 2 (the 5th element)

// 	mylist2.splice(mylist2.begin(), mylist1, it);
// 	// mylist1: 1 10 20 30 3 4
// 	// mylist2: 2
// 	// "it" is now invalid.
// 	std::cout << "*it: " << *it << std::endl;
// 	it = mylist1.begin();
// 	++it;
// 	++it;
// 	++it;
// 	std::cout << "*it: " << *it << std::endl; // "it" points now to 30

// 	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
// 	// mylist1: 30 3 4 1 10 20

// 	std::cout << "mylist1 contains:";
// 	for (it = mylist1.begin(); it != mylist1.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	std::cout << "mylist2 contains:";
// 	for (it = mylist2.begin(); it != mylist2.end(); ++it)
// 		std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }

// int main()
// {
// 	std::cout << std::endl
// 			  << "iterator insert (iterator hint, const value_type& val);" << std::endl;

// 	std::map<int, std::string> a;
// 	ft::map<int, std::string> b;

// 	a.insert(std::pair<int, std::string>(45, "123"));
// 	a.insert(std::pair<int, std::string>(82, "456"));
// 	a.insert(std::pair<int, std::string>(12, "79"));
// 	a.insert(std::pair<int, std::string>(57, "dsaf"));
// 	a.insert(std::pair<int, std::string>(69, "sdf"));
// 	a.insert(std::pair<int, std::string>(123, "asd"));
// 	a.insert(std::pair<int, std::string>(457, "zxc"));
// 	a.insert(std::pair<int, std::string>(1, "yjyu"));
// 	a.insert(std::pair<int, std::string>(457, "mi.l8"));
// 	a.insert(std::pair<int, std::string>(418, "xczz"));
// 	a.insert(std::pair<int, std::string>(77, "ipi"));
// 	a.insert(std::pair<int, std::string>(427, "qwr"));

// 	b.insert(std::pair<int, std::string>(45, "123"));
// 	b.insert(std::pair<int, std::string>(82, "456"));
// 	b.insert(std::pair<int, std::string>(12, "79"));
// 	b.insert(std::pair<int, std::string>(57, "dsaf"));
// 	b.insert(std::pair<int, std::string>(69, "sdf"));
// 	b.insert(std::pair<int, std::string>(123, "asd"));
// 	b.insert(std::pair<int, std::string>(457, "zxc"));
// 	b.insert(std::pair<int, std::string>(1, "yjyu"));
// 	b.insert(std::pair<int, std::string>(457, "mi.l8"));
// 	b.insert(std::pair<int, std::string>(418, "xczz"));
// 	b.insert(std::pair<int, std::string>(77, "ipi"));
// 	b.insert(std::pair<int, std::string>(427, "qwr"));

// 	// print_2m(a, b);
// 	std::cout << "\n__________Std::a__________" << std::endl;
// 	for (std::map<int, std::string>::iterator it = a.begin(); it != a.end(); ++it)
// 		std::cout << it->first << " => " << it->second << ";\t";
// 	std::cout << "\n__________Ft::b__________" << std::endl;
// 	for (ft::map<int, std::string>::iterator it = b.begin(); it != b.end(); ++it)
// 		std::cout << it->first << " => " << it->second << ";\t";
// 	std::cout << '\n';

// 	std::map<int, std::string>::iterator beg1 = a.begin();
// 	ft::map<int, std::string>::iterator beg2 = b.begin();
// 	beg1++;
// 	beg1++;
// 	beg1++;
// 	beg2++;
// 	beg2++;
// 	beg2++;
// 	a.insert(beg1, std::pair<int, std::string>(1267, "gggg"));
// 	b.insert(beg2, std::pair<int, std::string>(1267, "gggg"));
// 	std::cout << "\n__________Std::a__________" << std::endl;
// 	for (std::map<int, std::string>::iterator it = a.begin(); it != a.end(); ++it)
// 		std::cout << it->first << " => " << it->second << ";\t";
// 	std::cout << "\n__________Ft::b__________" << std::endl;
// 	for (ft::map<int, std::string>::iterator it = b.begin(); it != b.end(); ++it)
// 		std::cout << it->first << " => " << it->second << ";\t";
// 	std::cout << '\n';

// 	std::map<int, std::string>::iterator beg12 = a.begin();
// 	ft::map<int, std::string>::iterator beg22 = b.begin();
// 	beg12++;
// 	beg12++;
// 	beg12++;
// 	beg22++;
// 	beg22++;
// 	beg22++;
// 	a.insert(beg12, std::pair<int, std::string>(2, "gggg"));
// 	b.insert(beg22, std::pair<int, std::string>(2, "gggg"));

// 	std::cout << "std ... " << (--(a.end()))->first << std::endl;
// 	// std::cout << "ft ... " << (--(b.end()))->first  << std::endl;
// 	// std::cout << "ft ... " << (--(b.end()))->first  << std::endl;
// 	a.erase(a.begin(), --(a.end()));

// 	ft::map<int, std::string>::iterator bitr = b.begin();
// 	// ft::map<int, std::string>::iterator bitr2 = b.begin();
// 	bitr++;
// 	bitr++;
// 	bitr--;
// 	bitr--;
// 	bitr++;
// 	// bitr++;
// 	// bitr++;
// 	std::cout << "\nbit: " << bitr.getPtr()->value.first << std::endl;
// 	// b.erase(b.begin(), ++(b.begin()));
// 	// b.erase(++(b.begin()), (b.end()));
// 	b.erase((b.begin()), bitr);
// 	std::cout << "\nSize of b: " << b.size() << std::endl;
// 	// bitr2 = b.begin();
// 	/*bitr++; bitr++; bitr++; bitr++; bitr++; bitr++; bitr++; bitr++; bitr++; bitr++;*/
// 	// std::cout << "\n-------------Key:: " << bitr2.getPtr()->value.first << std::endl;
// 	// print_2m(a, b);
// 	std::cout << "\n__________Std::a__________" << std::endl;
// 	for (std::map<int, std::string>::iterator it = a.begin(); it != a.end(); ++it)
// 		std::cout << it->first << " => " << it->second << ";\t";
// 	std::cout << "\n__________Ft::b__________" << std::endl;
// 	for (ft::map<int, std::string>::iterator it = b.begin(); it != b.end(); ++it)
// 		std::cout << it->first << " => " << it->second << ";\t";
// 	std::cout << '\n';

// 	return 0;
// }


void print_two (std::deque<int> &b, ft::deque<int> &a)
{
	std::cout << "ft::deque.size(): " << a.size() << std::endl;
	std::cout << "std::deque.size(): " << b.size() << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << "Значения:" << std::endl;
	std::cout << "std::deque: ";
	for (std::deque<int>::iterator beg = b.begin(); beg != b.end(); beg++)
		std::cout << *beg << " ";
	std::cout << std::endl;
	std::cout << "ft::deque:  ";
	for (ft::deque<int>::iterator beg = a.begin(); beg != a.end(); beg++)
		std::cout << *beg << " ";
	std::cout << std::endl;
	std::cout << "-------------------------" << std::endl;
	
}

int main()
{

	std::cout << "-----------------------Something--------------------------" << std::endl;

	std::cout  << std::endl  << "Count: 100, value 42" << std::endl;
	ft::deque<int> a(100, 42);
	std::deque<int> b(100, 42);
	print_two(b, a);

	return 0;
}