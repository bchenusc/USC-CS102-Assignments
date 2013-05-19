#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Item
{
private:
  string name_;
  int qty_;
  double price_;
public:
  Item();
  Item(string name, int qty, double price);
  string getName() const;
  int getQty() const;
  double getPrice() const;
  void setName(string name);
  void setQty(int qty);
  void setPrice(double price);
};

Item::Item() 
{
  name_ = ""; qty_ = -1; price_ = -1; 
}

Item::Item(string name, int qty, double price){
	name_ = name; qty_ = qty; price_ = price;
}

// Complete the Item class methods here
string Item::getName() const{
	return name_;
}

int Item::getQty() const{
	return qty_;
}

double Item::getPrice() const{
	return price_;
}

void Item::setName(string name){
	name_ = name;
}

void Item::setQty(int qty){
	qty_ = qty;
}

void Item::setPrice(double price){
	price_ = price;
}


// Prototypes
void printItems(const Item *items, const int len);
Item *readData(const char *filename, int &len);

// Accepts a data filename as a command line arguments
int main(int argc, char *argv[])
{
  if(argc < 2){
    cerr << "Please supply an input filename as a command line argument" << endl;
    return 1;
  }
  int len;
  Item *dataArray = readData(argv[1], len); 
  if(dataArray == NULL){
    cout << "Unable to open file: " << argv[1] << endl;
    return 1;	
  }
  cout << "Read " << len << " Items from the file: " << argv[1] << endl;
  printItems(dataArray, len);

  // Add a statement to deallocate the dataArray memory
  delete [] dataArray;
  return 0;
}

// Print Item information in a tabular format
void printItems(const Item *items, int len)
{
	cout<<setw(15)<<"Name"<<setw(10)<<"Quantity"<<setw(10)<<"Price"<<endl;
	for(int i=0; i<len; i++){
		cout<<setw(15)<<items[i].getName()<<setw(10)<<items[i].getQty()<<setw(10)<<fixed<<setprecision(2)<<items[i].getPrice()<<endl;
	}
}


// Read Items from a datafile and store them in an array 
//  Return the address of the array and update the len
//  argument.
Item *readData(const char *filename, int &len)
{
	ifstream ifile;
	ifile.open(filename, ios::in);
	if (!ifile.is_open()){
 		return NULL;
 	}

 	int numberOfItems;
 	string itemName;
 	int quantity;
 	double price;
 	
 	ifile>>numberOfItems;
 	
 	Item* itemArray = new Item[numberOfItems];
 	for (int i=0; i<numberOfItems; i++){
 		ifile>>itemName;
 		ifile>>quantity;
 		ifile>>price;
 		
 		Item tempItem = Item(itemName, quantity, price);
 		
 		itemArray[i] = tempItem;
 	}
 	
 	len = numberOfItems;
 	
  return itemArray;
}
