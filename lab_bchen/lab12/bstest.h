#ifndef BSTEST
#define BSTEST

#include <iostream>

using namespace std;

template <typename T> 
struct BTItem{
	T val;
	BTItem<T>* left;
	BTItem<T>* right;
};

template <typename T> class BSTree {
	public:
		BSTree();
		~BSTree();
		BTItem<T>* find(const T& val);
		bool empty();
		int getSize();
		void insert(T& item);
		void inOrderPrintTraversal(BTItem<T>* node);
		void preOrderPrintTraversal(BTItem<T>* node);
		BTItem<T>* getRoot()const;
		
	private:
		int size; // Size of binary tree.
		BTItem<T>* root;
		void insert(BTItem<T>* node, BTItem<T>* parent);
};

template <typename T> BSTree<T>::BSTree(){
	size = 0;
	root = NULL;
}


template <typename T> BSTree<T>::~BSTree(){
				
}

template <typename T> BTItem<T>* BSTree<T>::getRoot() const{
	return root;
}


template <typename T>BTItem<T>* BSTree<T>::find(const T& val){
	BTItem<T>* temp = root;
	while(temp!=NULL){
		if (temp->val == val){
			return temp;
		}
		if (temp->val < val){
			temp = temp->right;
		}
		else 
			temp=temp->left;
	}
	cout <<"bstest.h: 52 No Value: "<<val<<" found."<<endl;
	return NULL;
}

template <typename T>bool BSTree<T>::empty(){
	if (size==0){
		return true;
	}
	else return false;
}

template <typename T> int BSTree<T>::getSize(){
	return size;
}

template <typename T> void BSTree<T>::insert(BTItem<T>* node, BTItem<T>* parent){
	if (node->val==parent->val){
		cout<<"bstest.h 67: Item already exists"<<endl;
		return;
	}

	if (node->val < parent->val){
		//Check the left tree
		//if the left tree is empty stick the node in that place.
		if (parent->left == NULL){
			parent->left = node;
			size++;
			return;
		}
		else{
			insert(node, parent->left);
			return;
		}
	}else if (node->val > parent->val){
		if (parent->right==NULL){
			parent->right = node;
			size++;
			return;
		}
		else {
			insert(node, parent->right);
			return;
		}
	}
}

template <typename T> void BSTree<T>::insert(T& item){
	BTItem<T>* node = new BTItem<T>;
	node->val = item;
	node->left = NULL;
	node->right = NULL;
	if (size==0){
		root = node;
		size++;
		return;
	}
	insert(node, root);
	
}

template <typename T> void BSTree<T>::inOrderPrintTraversal(BTItem<T>* node){
	if (node != NULL){
		inOrderPrintTraversal(node->left);
		cout<<node->val<<" ";
		inOrderPrintTraversal(node->right);
	}
}

template <typename T> void BSTree<T>::preOrderPrintTraversal(BTItem<T>* node){
	if (node!=NULL){
		cout<<node->val<<" ";
		preOrderPrintTraversal(node->left);
		preOrderPrintTraversal(node->right);
	}
	
}

#endif





















