#include <iostream>
#include <vector>
#include <string>
#include "bcalg.h"
#include "bcuser.h"
#include "queue.h"
#include "stack.h"
#include "gmlreader.h"
#include "gmlwriter.h"
#include <sstream>

// Add appropriate headers here

using namespace std;

BCUser* createUser(string node);
void makeEdges(string edge, MyList<BCUser*>* users);
BCUser* findUserWithID(int id, MyList<BCUser*>* users);
bool readCommandText(char *inputFile, MyList<User*>* users);
int findIDOfUser(string user, MyList<BCUser*>* users);


int main(int argc, char *argv[])
{
  vector<string> nodes;			//empty vector of type string called nodes    
  vector<string> edges;			//empty vector of type string called edges.
  MyList<BCUser*> allUsers;		//MyList that contains all users in social network
  
  if(argc < 3){
    cerr << "Please provide the input GML file, command file, and output file" << endl;
    return 1;
  }
  
   
  
  //----------------GML READER------------
  cout<<"Reading..."<<endl;
  //Read input file and save data to nodes and edges.
  if(!GMLReader::read(argv[1],nodes,edges)){
  	return 0;
  }
  
  for(unsigned int i=0; i<nodes.size();i++){		//Iterate through all the nodes
	try{allUsers.push_back(createUser(nodes[i]));}	//create 'n push users to allUsers.
	catch (invalid_argument e){cout<<e.what()<<endl;}
  }
  
  for(unsigned int i=0; i<edges.size();i++){		//Iterate through all the edges
  	makeEdges(edges[i],&allUsers);			//initializes the friends list in each user based on input file.
  }
  cout<<"--Done"<<endl;	
  
  MyList<double>* norms = BCAlg::computeBC(allUsers);						
  
  cout<<"Running GMLWriter..."<<endl;
  //----------------WRITER-----------------------------
  ofstream out;
  out.open(argv[2]);
  if (out.fail()){
  	cout<<"Failed to open file."<<endl;
  }else{
  	for (int i=0; i<norms->size();i++){
  		if(norms->at(i)!=-1){
  		out<<i<<" "<<norms->at(i)<<endl;
  		}
  	}
  }
  cout<<"--Done"<<endl;
  cout<<"Deleting Users for End of Program..."<<endl;
  //-------------Delete users when program ends for efficiency--------------
  for (int i=0; i<allUsers.size(); i++){
  	delete allUsers[i];
  }
  
  delete norms;
  cout<<"--Done"<<endl;
 
  return 0;
}
//------------GMLREADER FUNCTIONS--------------
BCUser* createUser(string node){
  string type = "";
  int importantInt = 0;
  string importantString = "";
  string skipString = "";
  stringstream nd(node);
  int counter = 0;
  
  int newID = -1;
  string newName = "";
  int newAge = -1;
  int newZip = -1;
  
  //Reading/parsing data to create users.
  while (counter<4){
  	nd>>type;
		if (type == "id"){ 
			nd>>importantInt;
			if (!nd.fail()){
				newID = importantInt;
				counter++;
			}
			else {throw invalid_argument("sn.cpp 129: Invalid ID");}
		}else
		if (type == "name") {
			getline(nd,skipString, '\"');
			getline(nd,importantString, '\"');
			if (!nd.fail()){
				newName = importantString;
				counter++;
			}
			else {throw invalid_argument("sn.cpp 129: Invalid ID");}
		}else
		if (type == "age"){ 
			nd>>importantInt;
			if (!nd.fail()){
				newAge = importantInt;
				counter++;
			}
			else {throw invalid_argument("sn.cpp 129: Invalid ID");}
		}else
		if (type == "zip"){ 
			nd>>importantInt;
			if (!nd.fail()){
				newZip = importantInt;
				counter++;
			}
			else {throw invalid_argument("sn.cpp 129: Invalid ID");}
		}
		if (nd.eof()){
			throw invalid_argument("sn.cpp 153. Invalid User. Skipping to next user.");
		}
	}
	BCUser* newUser = new BCUser(newName, newAge, newZip, newID);
  return newUser;				//returns the newly created user.
}

void makeEdges(string edge, MyList<BCUser*>* users){  	
  	
  string type1 = "";
  string type2 = "";
  int importantInt1 =-1;
  int importantInt2 = -1;
  stringstream edg(edge);
  
  edg >> type1;
  edg >> importantInt1;
  edg>>type2;
  edg>>importantInt2;
  
  BCUser* thisUser;
  
  try{findUserWithID(importantInt1, users);}
  catch (invalid_argument e){return;}
  try{findUserWithID(importantInt2, users);}
  catch (invalid_argument e){return;}
  	
  //Handles either/or order of source and target.
  if (type1 == "source"){
  	try{thisUser = findUserWithID(importantInt1, users);}
  	catch(invalid_argument e){cout<<"sn.cpp 194: " << e.what() <<endl; return;}
  	thisUser->addFriendID(importantInt2);
  }
  if (type2 == "source"){
	try{thisUser = findUserWithID(importantInt2, users);}
  	catch(invalid_argument e){cout<<"sn.cpp 199: " << e.what() <<endl; return;}
  	thisUser->addFriendID(importantInt1);
  }

}

BCUser* findUserWithID(int id, MyList<BCUser*>* users){
  for(int i=0; i< (*users).size();i++){				//iterates through the user list.
  	if((*users)[i]->getID() == id){				//finds the user with the certain id
  		return (*users)[i];				//if found then return that user pointer
  	}
  }
  throw invalid_argument("No User Found. sn.cpp 179");		//if not found throw an error.
}

//-----------------INPUT COMMAND FUNCTIONS -------------------
bool readCommandText(char *inputFile, MyList<BCUser*>*users){
	ifstream in;
	in.open(inputFile);							//opens the file name given in the command prompt.
	if (in.fail()){								//if the open fails then.
		throw invalid_argument("Cannot open GML input file! sn.cpp 102");	//say that it failed
		return false;							//return false.
	}						

	while(!in.eof()){							//While not end of file.
		string fileString;						//string for each line in file.
		string addOrRemove;						//var for "a" or "r"
		string name1;							//Name of the first person.
		string name2;							//Name of the second person.
		in>>addOrRemove;						//Gets either the "a" or the "r"
	  if (!in.eof()){							//Need this check to make sure we did not pass eof
		std::getline(in, fileString);					//Get one line in the file
		stringstream ss(fileString);					//Create a string stream from that one line.
		getline(ss, name1, '\"');					//Start of name quote: ->"Brian" *skip*
		getline(ss, name1, '\"');					//Gets 'Brian' which is the actual name.
		getline(ss, name2, '\"');					//Start of next name quote *skip*
		getline(ss, name2, '\"');					//Gets Brian's friend w/o the quotes.
		
		bool usersVerified = true;					//Flags false if user specified is not found.
		User* user1;							//Friend Command user1.
		User* user2;							//Friend Command user2.

		try{user1 = findUserWithID(findIDOfUser(name1, users), users);}	//Finds User 1 via string name1
		catch(invalid_argument e){cout<<"sn.cpp 211: "<<e.what()<<endl; usersVerified = false;}	//Turns verified to false if usr not found.
		try{user2 = findUserWithID(findIDOfUser(name2, users), users);}	//Finds User 2 via string name2
		catch(invalid_argument e){cout<<"sn.cpp 213: "<<e.what()<<endl;usersVerified = false;}	//Turns verified to false if usr not found.
		
		if (usersVerified == false){
			//Handles if the user is not in the database.
			cout<<"- One or more users was not found. Skipping line. sn.cpp 158"<<endl; //If usr not found
			continue;//Restart while loop for next line.
		}
		if (addOrRemove == "a"){
			//Add friend here
			user1->addFriendID(user2->getID());
			user2->addFriendID(user1->getID());
			cout<<"- "<<user1->getName()<<" and "<<user2->getName()<<" are new friends."<<endl;	//Debugs news feed
		}
		if (addOrRemove == "r"){
			//Remove friend here
			user1->removeFriendID(user2->getID());
			user2->removeFriendID(user1->getID());
			cout<<"- "<<user1->getName()<<" unfriended "<< user2->getName()<<endl;		//Debugs news feed.
		}	
		if (addOrRemove!="a" && addOrRemove!="r"){
			//Handle if a/r is not inputted.
			cout<<"Command a/r is not recognized. Skipping line. sn.cpp 177"<<endl;
			continue;//If a/r command is not recognized, restart the while loop for next line.
		}
	  }
	}
	in.close();
	return true;
}

int findIDOfUser(string user, MyList<BCUser*>* users){
	//Finds the ID of the user given a string parameter.
	for (int i=0; i<users->size(); i++){
		if ((*users)[i]->getName() == user){
			return (*users)[i]->getID();			//if the user exists, return the id of the user.
		}
	}
	throw invalid_argument("Invalid User! sn.cpp 133");		//if the user does not exist, throw an exception.
}






