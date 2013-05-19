#include "mylist.h"
#include "iostream"
#include "string"

using namespace std;

int main(){
	MyList<int> intList;
	MyList<string> stringList;
	
	(intList).push_back(1);
	(intList).push_back(-1);
	(intList).push_back(5);
	(intList).push_back(266);
	(intList).push_back(2);
	(intList).push_back(-20);
	
	(stringList).push_back("Hello");
	(stringList).push_back("a");
	(stringList).push_back("ab1");
	(stringList).push_back("124s");
	(stringList).push_back("124");
	(stringList).push_back("lalalaa");
	
	//Show intList
	cout<<"intList"<<endl;
	for (int i=0; i<intList.size(); i++){
		cout<<intList.at(i)<<" ";
	}
	//Remove from intList
	int i = intList.pop(1);
	intList.remove(266);
	cout<<endl;
	//Show change intList
	for (int i=0; i<intList.size(); i++){
		cout<<intList.at(i)<<" ";
	}
	cout<<endl;
	//Testing Popped
	cout<<"Popped from index 1 is "<<i;
	cout<<endl;
	cout<<endl;
	//Show stringList
	cout<<"stringList"<<endl;
	for (int i=0; i<stringList.size(); i++){
		cout<<stringList.at(i)<<" ";
	}
	cout<<endl;
	//Remove from stringList
	string z = stringList.pop(2);
	stringList.remove("lalalaa");
	stringList.remove("Hello");
	//Show change stringList
	for (int i=0; i<stringList.size(); i++){
		cout<<stringList.at(i)<<" ";
	}
	cout<<endl;
	//Testing popped
	cout<<"Popped from index 2 is "<<z;
	
	cout<<endl;
	cout<<endl;
	//Testing Try / Catch system
	try {
		cout<<stringList.at(100);
	}
	catch (invalid_argument e){
		cout<<e.what()<<endl;
	}
	catch (...){
		cout<<"Unidentified Error"<<endl;
	}

return 0;
}
