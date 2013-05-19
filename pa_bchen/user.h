#ifndef USER_H
#define USER_H

#include "mylist.h"
#include <iostream>
#include <stdexcept>

class User {
	public:
		User();
		User(string name_, int age_, int zipCode_, int id_);
		const string getName();
		void setName(string newName);
		const int getAge();
		void setAge(int newAge);
		const int getZipCode();
		void setZipCode(int newZipCode);
		const int getID();
		void setID(int newID);
		MyList<int>* getFriendIDs();
		int getFriendIDAt(int loc);
		void addFriendID(int id);
		void removeFriendID(int id);
	
	private:
		string name;			//Name of the user
		int age;			//Age of the user
		int zipCode;			//ZipCode of the user
		int id;				//ID of the user.
		MyList<int> friendIDs;		//A list that stores the ID's of friends.
};

#endif








