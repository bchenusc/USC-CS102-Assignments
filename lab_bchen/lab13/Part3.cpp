#include <iostream>
#include <fstream>
#include "rbttest.h"

using namespace std;

int main (int argc, char *argv[]){
	if(argc !=2){
    cerr << "Please provide the input file." << endl;
    return 0;
  }
  
  
  ifstream input;
  input.open(argv[1]);
  
  int number =0;
  
  RBTTree<int> softCornTree;
  
  /*Part1:*/
  while(!input.eof()){
  	input>>number;
  	softCornTree.insert(number);
  	softCornTree.preOrderPrintTraversal(softCornTree.getRoot());
  	cout<<endl;
  }
  cout<<endl<<"_______________________"<<endl;
  cout<<"Inorder: "<<endl;
  softCornTree.inOrderPrintTraversal(softCornTree.getRoot());
  cout<<endl;
  
  cout<<softCornTree.empty()<<endl;
  cout<<softCornTree.getSize()<<endl;
  /*softCornTree.find(1);
  softCornTree.find(20);
  softCornTree.find(25);
  softCornTree.find(5);
  cout<<softCornTree.getSize()<<endl;
  */
  
  softCornTree.find(100);
  softCornTree.find(50);
  softCornTree.find(48);
  softCornTree.find(1337);
  softCornTree.empty();
  softCornTree.getSize();
  
  return 0;
}
