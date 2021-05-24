#include "list.hpp"
// #include "vector.hpp"
// #include "map.hpp"
#include "queue.hpp"

#include <cmath>
#include <iostream> // std::cout
#include <stack>    // std::stack
#include <list>     // std::list
#include <queue>    // std::queue
#include <vector>   // std::vector
#include <deque>    // std::deque

// // --------------queue::back--------------
// int main()
// {
//     ft::queue<int> myqueue;

//     myqueue.push(12);
//     myqueue.push(75); // this is now the back

//     myqueue.back() -= myqueue.front();

//     std::cout << "myqueue.back() is now " << myqueue.back() << '\n';

//     return 0;
// }

// // --------------queue::pop--------------
// // --------------queue::push--------------
// // --------------queue::front--------------
// // --------------queue::empty--------------
// int main()
// {
//     ft::queue<int> myqueue;
//     int sum(0);

//     for (int i = 1; i <= 10; i++)
//         myqueue.push(i);

//     while (!myqueue.empty())
//     {
//         sum += myqueue.front();
//         myqueue.pop();
//     }
//     std::cout << "total: " << sum << '\n';

//     return 0;
// }

// // --------------queue::size--------------
// int main()
// {
//     ft::queue<int> myints;
//     std::cout << "0. size: " << myints.size() << '\n';

//     for (int i = 0; i < 5; i++)
//         myints.push(i);
//     std::cout << "1. size: " << myints.size() << '\n';

//     myints.pop();
//     std::cout << "2. size: " << myints.size() << '\n';

//     return 0;
// }

// // --------------queue::queue--------------
// int main()
// {
//     std::list<int> mylist(2, 200);  // list with 2 elements

//     std::queue<int> first;          // empty queue

//     std::queue<int, std::list<int> > second; // empty queue with list as underlying container
//     std::queue<int, std::list<int> > third(mylist);

//     std::cout << "size of first: " << first.size() << '\n';
//     std::cout << "size of third: " << second.size() << '\n';
//     std::cout << "size of fourth: " << third.size() << '\n';

//     return 0;
// }
