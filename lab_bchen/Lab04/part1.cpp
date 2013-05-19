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
	
	cout<<"intList"<<endl;
	for (int i=0; i<intList.size(); i++){
		cout<<intList.at(i)<<" ";
	}
	cout<<endl;
	cout<<endl;
	cout<<"stringList"<<endl;
	for (int i=0; i<stringList.size(); i++){
		cout<<stringList.at(i)<<" ";
	}
	cout<<endl;

return 0;
}
