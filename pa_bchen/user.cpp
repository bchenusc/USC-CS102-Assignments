#include "user.h"
//Constructors, Destructors, getters/setters
User::User(){}
User::User(string name_, int age_, int zipCode_, int id_): name(name_), age(age_), zipCode(zipCode_), id(id_){}

const string User::getName(){return name;}
void User::setName(string newName){name = newName;}
const int User::getAge(){return age;}
void User::setAge(int newAge){age = newAge;}
const int User::getZipCode(){return zipCode;}
void User::setZipCode(int newZipCode){zipCode = newZipCode;}
const int User::getID(){return id;}
void User::setID(int newID){id = newID;}
int User::getFriendIDAt(int loc){return friendIDs[loc];}
MyList<int>* User::getFriendIDs(){return &friendIDs;}
//end of getters/setters
void User::addFriendID(int id){
	for (int i=0; i<friendIDs.size(); i++){
		if (friendIDs[i] == id){
			return;
		}
	}
	friendIDs.push_back(id);
	return;
}
void User::removeFriendID(int id){
	for (int i=0; i<friendIDs.size(); i++){
		if (friendIDs[i] == id){
			friendIDs.pop(i);
			return;
		}
	}
}

