#ifndef LLIST_H
#define LLIST_H
#include <stdexcept>

//using namespace std;

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  bool empty() const;
  int size() const;
  void clear();
  void push_back(const T& new_val);
  void pop_front();
  T& peek_front() const;
  T& at(int loc) const;
  //bool remove(const T& val);
  T& operator[] (int loc);

 private:
  Item<T> *getNodeAt(int loc) const;

 protected:
  Item<T> *head_;
  Item<T> *tail_;
  int size_;
  
};

// Write the constructor here
template <typename T>
LList<T>::LList() : head_(NULL), tail_(NULL), size_(0)
{};




// Write the destructor here
template <typename T>
LList<T>::~LList()
{
  clear();
}





template <typename T>
bool LList<T>::empty() const
{
	//returns true if the LList is empty.
	if (size_==0){
		return true;
	}
	//else return false.
	else {return false;}
}

template <typename T>
int LList<T>::size() const
{
	//Returns the size
	return size_;
}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{
	
}

template <typename T>
void LList<T>::push_back(const T& new_val)
{
	
	Item<T>* temp  = new Item<T>;	//Creates a temp pointer
	temp->val = new_val;		//set the value of the temp pointer to the value being pushed in.
	if (size_==0){
		tail_ = temp;
	}
	else{
	tail_->next = temp;		//Sets the current tail's next to the new temp	
	tail_ = temp;			//Sets the new tail to temp.
	}
	temp->next = NULL;		//new item's next points to nothing b.c it is the last in the list.
	if (empty()){			//if the list is empty
		head_ = temp;		//put the head to point to temp
	}
	size_++;			//increment the size of the list.
} 

template <typename T>
void LList<T>::pop_front()
{
	if (size_>0){
		if (this->size_==1){
			delete head_;
			head_ = NULL;
			tail_ = NULL;
		}
		else{
		Item<T>* next_head = head_->next;
		delete head_;
		head_ = next_head;
		}
		size_ --;
	}
	else{
		//throw std::invalid_argument ("llist.h 110: Head is null");
	}
}

template <typename T>
T& LList<T>::peek_front() const
{
	if (size_>0){			//May have error here
		return head_->val;
	}
	throw std::invalid_argument("llist.h 119: Head is null");
}

//template <typename T>
//bool LList<T>::remove(const T& val)
//{
//
//}

template <typename T>
T& LList<T>::at(int loc) const
{
	if (loc>=0 && loc < size_){
		Item<T>* countpntr = head_;
		for (int i=0; i<loc; i++){
			countpntr = countpntr->next;
		}
		
		return countpntr->val;
	}
	throw std::invalid_argument("llist.h 118: Index out of Bounds.");
}


template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

template<typename T>
T& LList<T> :: operator [] (int loc){
	if (loc>=0 && loc < size_){
		Item<T>* countpntr = head_;
		for (int i=0; i<loc; i++){
			countpntr = countpntr->next;
		}
		
		return countpntr->val;
	}
	throw std::invalid_argument("llist.h 118: Index out of Bounds.");
}


#endif
