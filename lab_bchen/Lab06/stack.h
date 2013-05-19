#include <stdexcept>
//#include "llist.h"

//using namespace std;

template <typename T>
class Stack : public LList<T>{
  public:
  	 Stack();
  	~Stack();
  	int size() const;
  	void push(const T& value);
  	void pop();
  	T& top();
  	bool empty() const;
  
 // private:

};

template <typename T>
Stack<T>::Stack() : LList<T>(){
}

template <typename T>
Stack<T>::~Stack(){
	this->clear();	
}

template <typename T>
int Stack<T>::size() const {
	return this->size_;
}

template <typename T>
void Stack<T>::push(const T& value){
	return this->push_back(value);
}

template <typename T>
void Stack<T>::pop (){
	//cout<<"HELLO!"<<endl;
	if (this->size_>0){
		if (this->size_==1){
			delete this->head_;
			this->head_ = NULL;
			this->tail_ = NULL;
		}
		else{
			//Iterate through to the second to last
			Item<T>* behind_tail = this->head_;
			for (int i=0; i<this->size_-2;i++){
				behind_tail = behind_tail->next;
			}
			//cout<<behind_tail->val<<endl;
			delete this->tail_;
			this->tail_ = behind_tail;
			this->tail_->next = NULL;
		}
		this->size_ --;
		
	}
	else{
		//throw std::invalid_argument ("stack.h 52: Head is null");
	}
}

template <typename T>
T& Stack<T>:: top(){
	if (this->size_<=0){
		throw std::invalid_argument("stack.h 70: Size of list is 0");
	}
	else return this->tail_->val;
}

template <typename T>
bool Stack<T>::empty() const {
	//returns true if the LList is empty.
	if (this->size_==0){
		return true;
	}
	//else return false.
	else {return false;}
}



