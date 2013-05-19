# Lab 12 &mdash; Binary Search Trees

## Lab Goal
This lab aims for you to learn and implement Binary Search Trees (BSTs).

#### Design Document
There is no design writeup due with this lab.

#### Grading
This lab is worth 10 points.

## Introduction
Write a templated `BSTree` class that can support:
  + `find()`
  + `empty()`
  + `size()`
  + `insert()`
  + `inOrderPrintTraversal()`
  + `preOrderPrintTraversal()`

and a test program that reads a list of `int`'s from a text file, inserting them and printing out the BST using the pre order traversal after every insert and then print the BST using in order traversal when done inserting all the integers.

## Part 1 &ndash; Write `bsttest.cpp` (2 points)
Write `bsttest.cpp` that reads a list of integers from a text file (the file is given as a commandline argument), inserts them into a BST printing the tree using pre order traveral after every insert, then prints the BST using in order traversal.

## Part 2 &ndash; Test 1 (2 points)
Test your `BSTree` implementation by performing the following operations **before** inserting any nodes to the tree:
  + `find(55)`
  + `empty()`
  + `size()`
  + `inOrderPrintTraversal()`
  + `preOrderPrintTraversal()`

Your program should display an appropriate message and your application must not terminate or abort.

After performing these operations on an empty tree, run `bsttest.cpp` on [`btest1.txt`](btest1.txt)

## Part 3 &ndash; Test 2 (3 points)
Run `bsttest.cpp` on [`btest2.txt`](btest2.txt)

After that run the following operations:
  + `empty()`
  + `size()`
  + `find(2)`
  + `find(7)`
  + `find(20)`
  + `find(8)`
  + `find(11)`
  + `size()`
 

## Part 4 &ndash; Test 3 (3 points)
Run `bsttest.cpp` on [`btest3.txt`](btest3.txt)

After that run the following operations:
  + `empty()`
  + `size()`
  + `find(20)`
  + `find(17)`
  + `find(22)`
  + `find(13)`
  + `find(27)`
  + `find(10)`
  + `size()`

