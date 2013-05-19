# Design Document for PA1

## Purpose/Overview

This programming assignment is to make a social networking application capable of tracking friends between different users.
The assignment will teach us how to utilize the data structures introduced in this course and additionally understand an abstract
representation of graphs.



## Requirements

- Use `GMLReader` class to read in raw node/vertex and edge data.
- Parse the strings as users and their friends which appear as node and edge data.
- Read commands that add and/or remove friends.
- Write the code to a new GML file.
- Reflexive linking between friends. ex. A is friends with B, then B is friends with A.



## Classes
1. `template <typename T> class MyList<T>`
  * `MyList`: List class that can hold Users and/or their id's used for friend tracking.
  * Members:
   * `int capacity`: amount the dynamic array can hold.
   * `int size`: the current amount of data in the 
   * `T* data`: the dynamic array
  * Function:
   * `ListString();` : Constructor used to initialize all variables.
   * `~ListString();` : Deletes the dynamically allocated array.
   * `bool push_back(T item)` : pushes the item of type T to the back of data.
   * `int sizeOf()` : returns the number of items in data.
   * `T& at(int position)` : returns the item at data[position]
   * `T& operator[] (int position)`: overloads operator [] so getting and setting indicies is possible.
   * `T pop(int loc)` : removes the item from the array, returns that item, and shifts elements to fill empty spot.
   * `bool remove(T val)` : iterates through the array to remove the first element `val`.
   
2. `User` class
  * `User`: Class that defines users in the social network. Users can friend each other.
  * Members:
   * `string name`: name of the user.
   * `int age`: age of the user
   * `MyList<int> friendList` : stores the id's of the friends of the user.
  * Functions:
   * `string getName()`: gets the name of the user
   * `void setName()`: sets the name of the user
   * `int getAge()`: gets the name of the user
   * `void setAge()`: sets the age of the user
   * `int getZipCode()` : gets user zipcode
   * `void setZipCode(int newZipCode)` : sets the user zipcode
   * `MyList<int> getFriends()`: gets the list of friends.
   * `void addFriend(int id)`: adds the friend id to the friendList.
   * `void removeFriend(int id)`: removes the friend id from the friend list.
   
3. `GMLWriter` class
  * `GMLWriter`: Outputs updated GML data of all friends after command file as a re-readable GML file.
  * Functions:
   * static bool write(char *outputFile, MyList<User*> users) : takes user list and parses through friends to creat an output.gml file.
  


## Global Data/Functions

## High-level Architecture
The program will keep track of one main vector containing all the users in the social networking program. Each `User` will have a
templated list class called `MyList` that will contain all the id's of that user's friends. The `User` class and the `MyList` class
interact together to form the social networking link. The `GML Reader` should be able to read the
`User` and friend data to display a graphical representation of the social network using edge
and node data. `GMLWriter` should be able to take an existing user database and create a .gml output file formatted specifically
for gml that contains the nodes and edges of users and their corresponding friends.



## User Interface
The user will create a command file in the form of a text file which will be read by the program.
Certain command prompt commands that are read will execute different functions in the program.
For example:
``` shell
a "name 1" "name 2" \n
r "name 1" "name 2" \n
```
The 'a' command signifies adding a friend and the 'r' command signifies removing a friend.
All commands are command-line style text.


##Test Cases
System test:
 * The assignment comes with a testable command file.
Potential Problems:
 * Removing a friend that is non-existent in the friend list or as a user.
 * Removing a user that is non-existent.
 * Adding a friend that is non-existent as a user.
 * Adding a user as a friend of itself.
 * Improperly formatted GML files and/or command text files.
Nonimal Cases:
 * The provided test command file should have sufficient nominal test cases.
