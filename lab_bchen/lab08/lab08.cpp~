#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Linked list item struct
struct Item {
  int value;
  Item *next;
};

// Global declarations of an array and linked list head pointer
const int MAXSIZE = 10;
int list[MAXSIZE];
Item *head;

int arraySequentialSearch( int value ) {
  //An array-based sequential search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  for ( int loc=0; loc<MAXSIZE; loc++ ) {
    if ( list[loc] == value ) {
      return loc;
    }
  }

  return -1;
}

Item *linkedSequentialSearch( int value ) {
  //An linked-list-based sequential search algorithm. Returns a pointer to the item
  //containing the value if found and a null otherwise
  Item *current = head;

  while ( current != NULL ) {
    if ( current->value == value ) {
    
      return current;
    }
    current = current->next;
  }

  return NULL;
}

int arrayBinarySearch( int value ) {
  //An array-based binary search algorithm. Returns the index position
  //of the value being searched for if found and returns -1 otherwise
  int first=0, last=MAXSIZE-1, mid;

  while ( first <= last ) {
    mid = (first + last) / 2;

    if ( list[mid] == value ) {
      //Found it
      return mid;
    }

    //Haven't found it, yet. Determine which sublist to continue with and
    //adjust first or last
    if ( list[mid] > value ) {
      //Go left, so adjust last to be mid-1
      last = mid - 1;
    } else {
      //Go right, so adjust first to be mid+1
      first = mid + 1;
    }
  }

  return -1;
}



// **************** CHANGE ME ************************
// Change the code to populate data with random numbers
// between 0 and 1,000,000 and insert them in sorted order
void populateLinkedList() {
	srand(time(NULL));
  //Appends MAXSIZE even numbers in the list
  Item *temp, *previous;

  //Create the first item so that in the for loop we don't
  //have to check for head == NULL
  head = new Item;
  head->value = rand()%1000001;
  head->next = NULL;
  for ( int i=1; i<MAXSIZE; i++ ) {
    temp = new Item;
    temp->value = rand()%1000001;
    temp->next = head;
    previous= NULL; 
    while (temp->value > temp->next->value){
    	if (temp->next->next == NULL){
    		previous = temp->next;
    		temp->next = NULL;
    		break;
    	}
    	previous=temp->next;
    	temp->next  = temp->next->next;
    }
    if (previous == NULL){
    	head=temp;
    }else{
    	previous->next=temp;
    }
  }
}

// **************** CHANGE ME ************************
// Change the code to populate data with random numbers
// between 0 and 1,000,000
void populateArrayList() {
  //Puts MAXSIZE even numbers in the list
  srand(time(NULL));
  for ( int i=0; i<MAXSIZE; i++ ) {
    list[i] = rand()%1000001;
  }
}

// **************** WRITE ME ************************
// Add your code (function(s)) to implement Selection Sort

int findIndexofLargest(int size){
	int indexSoFar = 0;
	for (int i = 1; i<size; i++){
		if (list[i] > list[indexSoFar]){
			indexSoFar = i;
		}
	}
	return indexSoFar;
}
void selectionSort(){
	for (int i = MAXSIZE-1; i>=1; i--){
		int largest = findIndexofLargest(i+1);
		cout<<"Largest is: "<<endl;
		std::swap(list[largest], list[i]);
	}
}


// **************** WRITE ME ************************
// Add your code (function(s)) to implement Merge Sort
int other[MAXSIZE];

void merge(int first, int mid, int last){
	int first1 = first;
	int last1 = mid;
	int first2 = mid+1;
	int last2 = last;
	
	int index = first1; //next index in the other array.
	
	while ((first1<=last1) && (first2<=last2)){
	//If the indicies have not switched.
		//First check the first1 and middle1.
		//[a,b] --- [c,d]
		//if a is less than or equal to c.
		if (list[first1]<=list[first2]){
			
			//then stick a in the other list and make b the new first1. (index of other will be incremented later)
			other[index] = list[first1];
			first1++;	
		}
		else{
		//otherwise put c in the other list and make d the new first 1. (index of other will be incremented
			other[index] = list[first2];
			
			first2++;
		}
		index++;
	}
	
	//If first and second sub arrays are not equal in length
	//example: [a,b,c] -- [a,b]
	// a and b have been finished off by the first array. Now there is c. Lonely c.
	while(first1<=last1){
	
		//basically if c's index is <= to itself, then just stick it in other
		other[index] = list[first1];
		first1++; //incremented first1 to break out of this while loop.
		index++; //increment 
	}
	//if first and second sub arrays are not equal in length
	//example: [a,b] -- [a,b,c]
	//a and b have been finished off. Now there is c. Lonely c.
	while(first2<=last2){
	
		other[index] = list[first2];
		first2++;
		index++;
	}
	
	//Now put everything back into the main array:
	for (int index = first; index<=last; index++){

		list[index] = other[index];
	}
}

void mergeSort(int first, int last){
	if (first<last)
	{
		int mid = first + (last-first)/2;
		
		mergeSort(first , mid);
		
		mergeSort(mid+1, last);
		
		merge(first, mid, last);
	}
}


int main() {
  clock_t start, finish;
  double  duration;
  cout << "List size of " << MAXSIZE << endl;

  //Put data into the two types of lists
  populateArrayList();
 //populateLinkedList();

  start = clock();

  // Add your call to either selection or merge sort here.

	//selectionSort();
	mergeSort(0,MAXSIZE-1);

  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  
  
	for (int i=0; i< MAXSIZE; i++){
		cout<<list[i]<<endl;
	
	}
	/*
	Item* temp = head;
	while(temp!=NULL){
		cout<<temp->value<<endl;
		temp = temp->next;
	}
	*/
  
  
  cout <<"Total CPU for sort time: "<<duration<<endl;

  // Write a for loop to check that data in your array is 
  // in sorted order


  //Let's start off with a value not in the list and see how long it takes.
  int numiters = 100000;
  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arraySequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for array sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
  
    linkedSequentialSearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU for linked sequential search time: "<<duration/numiters<<endl;

  // Start the stopwatch
  start = clock();
  for ( int i=0; i<numiters; i++ ) {
    arrayBinarySearch( 2*MAXSIZE );
  }
  // Measure the elapsed CPU time, and print.
  finish = clock();
  duration = (double)(finish - start) / CLOCKS_PER_SEC;
  cout <<"Average CPU time for array binary searches time: "<<duration/numiters<<endl;


  return 0;
}

