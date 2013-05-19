# Lab 06: Linked List, Stack, and Queue Template Classes

### Design Document
There is no design writeup due with this lab.

### Grading
This assignment is worth 10 points.

### Introduction
In this lab you will learn to implement a `stack` and a `queue` templated class using a linked structure. You must also write a `printStack` and a `printQueue` function that iterates through the `stack`/`queue` and prints the values of the nodes - one per line. These methods are **NOT** to be part of your `stack` and `queue` classes. Put them in your main application file.

## Part 1: Templated Linked List (3 points)
Complete the templated linked list class described and started in class. Code is available in the lab 06 repository if you have yet to obtain it:
```shell
#Change directory to your home directory
#   If your repositories are in another directory, 
#   switch to that one
cd

#If you have yet to clone the class labs repository, clone it here
git clone git@github.com:usc-csci102-spring2013/labs.git

#Change directory to your private lab repository
#   replace usc-username with your USCNet username
cd lab_usc-username

#Make a directory for lab06
mkdir lab06

#Copy lab06's llist.h & llist_test.cpp files
cp ../../labs/lab06/llist.h ../../labs/lab06/llist_test.cpp lab06/

#Now, we commit the initial state of lab06
git add lab06
git commit -m "Lab06 initial commit using the lecture linked list code as a starting point"

#Push the initial state to the server
git push

#Change directory to lab06 and start working on the lab
cd lab06
```

The `llist.h` file downloaded above has more methods defined, but you may change it to only implement what you need.  As a minimal set you should implement the following public member functions.  You can use any implementation (head pointer only, head + size, head + size + tail pointer, etc.):
```C++
LList();
~LList();
bool empty() const;
int size() const;
void clear();
void push_back(const T& new_val);
void pop_front();
T& peek_front() const;
T& at(int loc);
```

>If you downloaded `llist.h` before this lab, you should change the `push_back` declaration to take a constant reference to a `T` item, have `pop_front()` return void, and have `peek_front()` return a reference to the `front` value.


## Part 2: Stack (4 points)
Build a templated `Stack<T>` class from your linked list class in a file named `stack.h`. You can use inheritance, or composition. It is your choice, just make sure the `stack` implements the following public member functions:
```C++
Stack();
~Stack();
int size() const;
void push(const T& value);
void pop();
T& top();
bool empty() const;
```

Put test code in your `main` function to _add_ integers and _remove_ integers to your stack printing the `top` item after every `push` or `pop`.

As a further test, delete all the items in your stack until it is empty, then try to delete one more item. Trying to delete an item on an empty stack is not to abort your code. It is also not an error, so no need to return an error message, nor throw an exception. Lastly, add more items to the stack after you have deleted all the items, printing the top item again after each push.  Finally, enter a loop to print and pop each item on the stack until it is empty. 


## Part 3: Queue (3 points)
Do the same thing you did with a stack, but now with a queue. Your `Queue<T>` should have the following public member functions:
```C++
Queue();
~Queue();
int size() const;
void push_back(const T& value); //enqueue
void pop_front();  // dequeue
T& front();
T& back();
bool empty() const;
```

Put test code in your `main` function to _add_ and _remove_ integers, printing the front and back item after each change. Prove that your methods work when you create a queue, delete all the items, then add more items, like you did with your stack.


## Extra Credit (2 points)
Change your main function to create an empty stack and queue and then enter a loop that displays a menu of options to the user to select the operation they want to perform [have them enter the integer number of the command they want to perform].: 
  1. Push to Stack (and then have the user enter an integer), 
  1. Print and pop top of stack
  1. Push_back to Queue (and then have the user enter an integer)
  1. Print and pop front of queue
  1. Quit

