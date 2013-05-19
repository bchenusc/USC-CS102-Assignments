#ifndef BSTEST
#define BSTEST

#include <iostream>

using namespace std;

template <typename T> 
struct BTItem{
	T val;
	bool red;
	BTItem<T>* left;
	BTItem<T>* right;
	BTItem<T>* parent;
};

template <typename T> class RBTTree {
	public:
		RBTTree();
		~RBTTree();
		BTItem<T>* find(const T& val);
		bool empty();
		int getSize();
		void insert(T& item);
		void inOrderPrintTraversal(BTItem<T>* node);
		void preOrderPrintTraversal(BTItem<T>* node);
		BTItem<T>* getRoot()const;
		void checkColor(BTItem<T>* node);
		
	private:
		int size; // Size of binary tree.
		BTItem<T>* root;
		void insert(BTItem<T>* node, BTItem<T>* parent);
		void rotateLeft(BTItem<T>* node);
		void rotateRight(BTItem<T>* node);
};

template <typename T> RBTTree<T>::RBTTree(){
	size = 0;
	root = NULL;
}


template <typename T> RBTTree<T>::~RBTTree(){
				
}

template <typename T> BTItem<T>* RBTTree<T>::getRoot() const{
	return root;
}


template <typename T>BTItem<T>* RBTTree<T>::find(const T& val){
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

template <typename T>bool RBTTree<T>::empty(){
	if (size==0){
		return true;
	}
	else return false;
}

template <typename T> int RBTTree<T>::getSize(){
	return size;
}

template <typename T> void RBTTree<T>::insert(BTItem<T>* node, BTItem<T>* nparent){
	if (node->val==nparent->val){
		cout<<"bstest.h 67: Item "<<node->val <<" already exists"<<endl;
		return;
	}

	if (node->val < nparent->val){
		//Check the left tree
		//if the left tree is empty stick the node in that place.
		if (nparent->left == NULL){
			nparent->left = node;
			node->parent = nparent;
			node->red = true;
			size++;
			BTItem<T>* nodeIter = node;
			while(nodeIter!= NULL && nodeIter->parent !=NULL && nodeIter->red && nodeIter->parent->red){
				checkColor(nodeIter);
				if (nodeIter->parent!=NULL)
					nodeIter=nodeIter->parent->parent;
				else break;
			}
			return;
		}
		else{
			insert(node, nparent->left);
			return;
		}
	}else if (node->val > nparent->val){
		if (nparent->right==NULL){
			nparent->right = node;
			node->parent = nparent;
			node->red = true;
			size++;
			BTItem<T>* nodeIter = node;
			while(nodeIter!= NULL && nodeIter->parent !=NULL && nodeIter->red && nodeIter->parent->red){
				checkColor(nodeIter);
				if (nodeIter->parent!=NULL)
					nodeIter=nodeIter->parent->parent;
				else break;
			}
			return;
		}
		else {
			insert(node, nparent->right);
			return;
		}
	}
}

template<typename T> void RBTTree<T>::checkColor(BTItem<T>* node){
	BTItem<T>* nparent = node->parent;
	//cout<<"DEBUG 1"<<endl;
	if (nparent == NULL){
		cout<<"DEBUG10"<<endl;
		return;
	}
	BTItem<T>* grandParent = node->parent->parent;
	if (grandParent==NULL){
	//cout<<"DEBUG9"<<endl;
		return;
	}
	//cout<<"Debug 8"<<endl;
	BTItem<T>* uncle = NULL;
	bool parentOnLeft=false;
	bool nodeOnLeft=false;;
	
	if (nparent->left==node){
		nodeOnLeft=true;
	}else{
		nodeOnLeft=false;
	}
	
	if (grandParent->left == nparent){
	//cout<<"DEBUG 7"<<endl;
		//uncle is on the right.
		parentOnLeft=true;
		uncle = grandParent->right;
		//cout<<"Debug 7.5"<<endl;
	}
	else{
		//uncle is on the left.
		//cout<<"Debug 6"<<endl;
		parentOnLeft=false;
	 	uncle =grandParent->left;
	 }
	 
	 //cout<<"Debug 0.1"<<endl;
	 //Case 1:
	 if (node->red && nparent->red && uncle != NULL && uncle->red){
	 	//cout<<"DEBUG1"<<endl;
	 	nparent->red=false;
	 	uncle->red=false;
	 	grandParent->red=true;
	 }
	 //cout<<"Debug 0.2"<<endl;
	 //Case 2:
	 if (node->red && nparent->red && (uncle==NULL ||!(uncle->red) )&& parentOnLeft && nodeOnLeft){
	 //cout<<"DEBUG2"<<endl;
	 	nparent->red=false;
	 	grandParent->red=true;
	 	//right rotate parent;
	 	rotateRight(nparent);
	 }
	 //cout<<"Debug 0.3"<<endl;
	 if (node->red && nparent->red && (uncle==NULL || !(uncle->red)) && !parentOnLeft && !nodeOnLeft){
	 //cout<<"DEBUG3"<<endl;
	 	nparent->red=false;
	 	grandParent->red=true;
	 	//left rotate parent
	 	rotateLeft(nparent);
	 }
	 //cout<<"Debug 0.4"<<endl;
	 //Case 3:
	 if (node->red && nparent->red && (uncle==NULL||!(uncle->red)) && parentOnLeft && !nodeOnLeft){
	 //cout<<"DEBUG4"<<endl;
	 	node->red = false;
	 	grandParent->red=true;
	 	//left rotate parent
	 	//right rotate gp
	 	rotateLeft(node);
	 	rotateRight(node);
	 }
	 //cout<<"Debug 0.5"<<endl;
	 if (node->red && nparent->red && (uncle==NULL || !(uncle->red)) && !parentOnLeft && nodeOnLeft){
	 //cout<<"DEBUG5"<<endl;
	 	node->red = false;
	 	grandParent->red=true;
	 	//right rotate parent
	 	//left rotate gp
	 	rotateRight(node);
	 	rotateLeft(node);
	 }
	 
	 	 root->red=false;
}

template <typename T> void RBTTree<T>::rotateRight(BTItem<T>* node){
	BTItem<T>* tempParent = node->parent;
	BTItem<T>* tempGrandParent;
	if (tempParent!=NULL)
		tempGrandParent = node->parent->parent;
	else return;
	//BTItem<T>* tempChild = node->left;
	//node is the parent.
	node->parent = tempGrandParent;
		bool onLeft=false;
	if (tempGrandParent!=NULL && tempGrandParent->left == tempParent){
		onLeft = true;
	}
	if (node->parent == NULL)
	{
		root=node;
	}
	tempParent->parent = node;

	tempParent->left=node->right;
	//--a-ds-fa-df-sa-df-as-df-asd-f
	if (node->right){
		node->right->parent = tempParent;
	}
	node->right = tempParent;
	if (tempGrandParent!=NULL){
		//if left of grandparent
		if (onLeft){
			tempGrandParent->left = node;
			node->parent = tempGrandParent;
			}
		else {
		tempGrandParent->right=node;
		node->parent = tempGrandParent;		
		}
	}
}

template <typename T> void RBTTree<T>::rotateLeft(BTItem<T>* node){
	BTItem<T>* tempParent = node->parent;
	BTItem<T>* tempGrandParent;
	if (tempParent!=NULL)
		tempGrandParent = node->parent->parent;
	//BTItem<T>* tempChild = node->left;
	
	//node is the parent of inserted node
	node->parent = tempGrandParent;
	bool onLeft=false;
	if (tempGrandParent!=NULL&& tempGrandParent->left == tempParent){
		onLeft = true;
	}
	tempParent->parent = node;
	if (node->parent == NULL)
	{
		root=node;
	}
	tempParent->right=node->left;
	//--a-ds-fa-df-sa-df-as-df-asd-f
	if (node->left){
		node->left->parent = tempParent;
	}
	node->left = tempParent;
		if (tempGrandParent!=NULL){
		//if left of grandparent
		if (onLeft){
			tempGrandParent->left = node;
			node->parent=tempGrandParent;
			}
		else {
		tempGrandParent->right=node;
		node->parent = tempGrandParent;
		}
	}
}

template <typename T> void RBTTree<T>::insert(T& item){
	BTItem<T>* node = new BTItem<T>;
	node->val = item;
	node->left = NULL;
	node->right = NULL;
	if (size==0){
		root = node;
		root->red=false;
		root->parent = NULL;
		size++;
		return;
	}
	insert(node, root);
}

template <typename T> void RBTTree<T>::inOrderPrintTraversal(BTItem<T>* node){
	if (node != NULL){
		inOrderPrintTraversal(node->left);
		cout<<node->val;
		if (node->red==true){
			cout<<" red"<<" "<<endl;
		}
		else cout<<" black"<<" "<<endl;
		inOrderPrintTraversal(node->right);
	}
}

template <typename T> void RBTTree<T>::preOrderPrintTraversal(BTItem<T>* node){
	if (node!=NULL){
		cout<<node->val<<" ";
		preOrderPrintTraversal(node->left);
		preOrderPrintTraversal(node->right);
	}
	
}

#endif





















