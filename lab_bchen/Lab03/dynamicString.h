#include <iostream>

using namespace std;

template <typename T> class ListString {
	public:
		ListString(int size);
		~ListString();
		bool push_back(string item);
		int size();
		string at(int position);
	private:
		int capacity; // how much the array can hold
		int sizeOf; // how much is in the array.
		string data[];
};

template <typename T> ListString<T>::ListString(int size){
	data = new string[size];
	capacity = size;
	size = 0;	
}

template <typename T> bool ListString<T>::push_back(string item){
	if (size<capacity){
		data[sizeOf] = item;
		sizeOf++;
		return true;
	}
	else return false;
}

template <typename T> int ListString<T>::size(){
	return size;
}

template<typename T> string ListString<T>::at(int position){
	if (position<capacity){
		return data[position];
	}
}





