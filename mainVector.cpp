// #include "list.hpp"
#include "vector.hpp"
// #include <list>
// #include <iostream>
#include <vector>
#include <cmath>

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
// int main () {
//   std::vector<int> myvector;
//   int sum = 0;
//   myvector.push_back(100);
//   myvector.push_back(200);
//   myvector.push_back(300);
//   myvector.push_back(5);
//   myvector.pop_back();
//   myvector.push_back(55);

//   while (!myvector.empty()) {
//     sum += myvector.back();
//     std::cout << myvector.back() << "--";
//     myvector.pop_back();
//   }
//   myvector.pop_back();
//   myvector.push_back(1000);

//   std::cout << "\nThe elements of myvector summed " << sum << "\nmyvector = { ";
//     for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++) {
//         std::cout << *it << " ";
//     }
//     std::cout << "};\n";
//     std::cout << "Size of mylist: " << myvector.size() << std::endl;
//   return 0;
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
// int main () {
//   ft::vector<int> myvector;
//   int sum (0);

//   for (int i = 1;i <= 10; i++) myvector.push_back(i);

//   while (!myvector.empty()) {
//      sum += myvector.back();
//      myvector.pop_back();
//   }

//   std::cout << "total: " << sum << '\n';

//   return 0;
// }

// // --------------vector::resize--------------
// int main () {
//   ft::vector<int> myvector;

//   // set some initial content:
//   for (int i = 1; i < 10; i++) myvector.push_back(i);

//   std::cout << "1. size: " << myvector.size() << '\n';
//   myvector.resize(5);
//   std::cout << "2. size: " << myvector.size() << '\n';
//   myvector.resize(8, 100);
//   std::cout << "3. size: " << myvector.size() << '\n';
//   myvector.resize(12);
//   std::cout << "4. size: " << myvector.size() << '\n';
//   std::cout << "4. capacity: " << myvector.capacity() << '\n';

//   std::cout << "myvector contains:";
//   for (size_t i = 0; i < myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::max_size--------------
// int main () {
//   ft::vector<int> myvector;

//   // set some content in the vector:
//   for (int i = 0; i < 100; i++) myvector.push_back(i);

//   std::cout << "size: " << myvector.size() << "\n";
//   std::cout << "capacity: " << myvector.capacity() << "\n";
//   std::cout << "max_size: " << myvector.max_size() << "\n";
//   return 0;
// }

// // --------------vector::size--------------
// int main () {
//   ft::vector<int> myints;
//   std::cout << "0. size: " << myints.size() << '\n';

//   for (int i = 0; i < 10; i++) myints.push_back(i);
//   std::cout << "1. size: " << myints.size() << '\n';
//   std::cout << "1. capacity: " << myints.capacity() << '\n';

//   myints.insert(myints.end(), 10, 100);
//   std::cout << "2. size: " << myints.size() << '\n';

//   myints.pop_back();
//   std::cout << "3. size: " << myints.size() << '\n';
//   std::cout << "3. capacity: " << myints.capacity() << '\n';
//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myints.begin(); it != myints.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::rend--------------
// // --------------vector::rbegin--------------
// int main () {
//   ft::vector<int> myvector(5);  // 5 default-constructed ints

//   int i = 0;

//   ft::vector<int>::reverse_iterator rit = myvector.rbegin();
//   for (; rit != myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// // --------------vector::end--------------
// // --------------vector::begin--------------
// int main () {
//   ft::vector<int> myvector;
//   std::cout << "Capacity: " << myvector.capacity() << std::endl;
// 	std::cout << "Size: " << myvector.size() << std::endl;
//   for (int i = 1; i <= 5; i++) myvector.push_back(i);

//   std::cout << "myvector contains:";
//   for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//   std::cout << "Capacity: " << myvector.capacity() << std::endl;
// 	std::cout << "Size: " << myvector.size() << std::endl;

//   return 0;
// }

// // --------------vector::operator=--------------
// int main () {
//   ft::vector<int> foo(3, 0);
//   ft::vector<int> bar(5, 0);

//   bar = foo;
//   foo = ft::vector<int>();

//   std::cout << "Size of foo: " << int(foo.size()) << '\n';
//   std::cout << "Size of bar: " << int(bar.size()) << '\n';
//   return 0;
// }

// // --------------vector::capacity--------------
// // --------------vector::vector--------------
// int main () {
//   // constructors used in the same order as described above:
//   ft::vector<int> first;                                // empty list of ints
//   ft::vector<int> second(5, 100);                       // four ints with value 100
//   ft::vector<int> third(second.begin(), second.end());  // iterating through second
//   ft::vector<int> fourth(third);                        // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16, 2, 77, 29};
//   ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

//   std::cout << "The contents of the first are: ";
//   for (ft::vector<int>::iterator it = first.begin(); it != first.end(); it++)
//     std::cout << *it << ' ';
//   std::cout << '\n';

//   std::cout << "The contents of the second are: ";
//   for (ft::vector<int>::iterator it = second.begin(); it != second.end(); it++)
//     std::cout << *it << ' ';
//   std::cout << '\n';

//   std::cout << "The contents of the third are:  ";
//   for (ft::vector<int>::iterator it = third.begin(); it != third.end(); it++)
//     std::cout << *it << ' ';
//   std::cout << '\n';

//   std::cout << "The contents of the fourth are: ";
//   for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); it++)
//     std::cout << *it << ' ';
//   std::cout << '\n';

//   std::cout << "The contents of the fifth are:  ";
//   for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
//     std::cout << *it << ' ';
//   std::cout << '\n';

//   std::cout << "Capacity: " << first.capacity() << std::endl;
// 	std::cout << "Size: " << first.size() << std::endl;
//   std::cout << "Capacity: " << second.capacity() << std::endl;
// 	std::cout << "Size: " << second.size() << std::endl;
//   std::cout << "Capacity: " << third.capacity() << std::endl;
// 	std::cout << "Size: " << third.size() << std::endl;
//   std::cout << "Capacity: " << fourth.capacity() << std::endl;
// 	std::cout << "Size: " << fourth.size() << std::endl;
//   std::cout << "Capacity: " << fifth.capacity() << std::endl;
// 	std::cout << "Size: " << fifth.size() << std::endl;

//   return 0;
// }
