#include <iostream>
#include <vector>

using namespace std;

 class ListString {
	public:
		ListString();
		ListString(int size);
		~ListString();
		bool push_back(string item);
		int size();
		string at(int position);
	private:
		int capacity; // how much the array can hold
		int sizeOf; // how much is in the array.
		string* data;
};

ListString::ListString(){
	data = new string[1];
	sizeOf=0;
	capacity=1;
}

ListString::ListString(int sz){
	data = new string[sz];
	capacity = sz;
	sizeOf = 0;	
}

 bool ListString::push_back(string item){
	if (sizeOf<capacity){
		data[sizeOf] = item;
		sizeOf++;
		return true;
	}
	else {
		string* temp = new string[capacity*2];
		capacity*=2;
		for (int i=0; i<sizeOf; i++){
			temp[i] = data[i];
		}
		data = temp;
		data[sizeOf] = item;
		sizeOf++;
		return true;
	}
	return false;
}

 int ListString::size(){
	return sizeOf;
}

 string ListString::at(int position){
	if (position<capacity){
		return data[position];
	}
	else return "";
}


class User {
	public:
		string getName();
		void setName(string newName);
		int getAge();
		void setAge(int newAge);
		ListString getFriends();
		void addFriend(string name);
		void printUser();
	
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
void User::addFriend(string name){friends.push_back(name);}
void User::printUser(){cout<<"User Name: "<<getName()<<endl<<"User age: "<<getAge()<<endl;
	for (int i=0; i<friends.size(); i++){
		cout<<friends.at(i)<<" ";
	}
	cout<<endl<<endl;
}


int main(){
	vector<User*> users;
	int userCount =0;
	
	while(true){
	string firstName;
	int myAge;
	
	cout<<"Input Name: ";
	cin>>firstName;
	if (firstName == "done"){
		firstName = "";
		break;
	}
	cout<<"Input Age: ";
	cin>>myAge;
	
	User* user = new User();
	
	(*user).setName(firstName);
	(*user).setAge(myAge);
	userCount++;
	users.push_back(user);
	}
	
	//Second part
	string text1 = "";
	string text2 = "";
	User* user1;

	while (true) {
		cout<<"Enter a User's Name: ";
		cin>>text1;
		if (text1 == "done"){
			text1 = "";
			cout<<endl;
			break;
		}
		bool foundUser = false;
		for (int i=0; i<userCount; i++){
			if ((*users[i]).getName()==text1){
				cout<<"Accepted"<<endl;
				user1 = users[i];
				foundUser = true;
				break;
			}
		}
		if (!foundUser){
			cout<<"!User not found"<<endl;
			continue;
		}
		cout<<"Enter the User's Friend: ";
		cin>>text2;
		for (int i=0; i<userCount; i++){
			if ((*users[i]).getName()==text2){
				cout<<"Accepted"<<endl;
				(*user1).addFriend(text2);
			}
		}
		
	}
	
	for (int i=0; i<userCount; i++){
		(*users[i]).printUser();
	}

return 0;
}
