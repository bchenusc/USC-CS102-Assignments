#include <iostream>

using namespace std;

class User {
	public:
		string getName();
		void setName(string newName);
		int getAge();
		void setAge(int newAge);
		ListString getFriends();
	
	private:
		string name;
		int age;
		ListString friends;
};

string User::getName(){return name;}
void User::setName(string newName){name = newName;}
int User::getAge(){return age;}
void User::setAge(int newAge){age = newAge;}
ListString User::getFriends(){return friends;}





