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
  
  
  return 0;
}
