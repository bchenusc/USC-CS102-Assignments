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
  	//if (!input.eof()){
  	softCornTree.insert(number);
  	softCornTree.preOrderPrintTraversal(softCornTree.getRoot());
  	cout<<endl;
  	//}
  }
  cout<<endl<<"_______________________"<<endl;
  cout<<"Inorder: "<<endl;
  softCornTree.inOrderPrintTraversal(softCornTree.getRoot());
  cout<<endl;
  
  
  /*Part2/3:
  softCornTree.find(2);
  softCornTree.find(7);
  softCornTree.find(20);
  softCornTree.find(8);
  softCornTree.find(11);
  */
  
  cout<<"_________________________"<<endl;
  cout<<softCornTree.empty()<<endl;
  cout<<softCornTree.getSize()<<endl;
  cout<<"_________________________"<<endl;
  //softCornTree.inOrderPrintTraversal(softCornTree.getRoot());
  //softCornTree.preOrderPrintTraversal(softCornTree.getRoot());
  /*Part4*/
  softCornTree.find(20);
  softCornTree.find(17);
  softCornTree.find(22);
  softCornTree.find(13);
  softCornTree.find(27);
  softCornTree.find(10);
  
  
  return 0;
}
