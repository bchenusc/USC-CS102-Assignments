#include "bcuser.h"
#include "bcalg.h"
#include "stack.h"
#include "queue.h"
MyList<double>* BCAlg::computeBC(MyList<BCUser*> &userList){

	bool useEfficiencyCode = true; //If the id's match the index of userlist, run the more efficient code.
	
	for (int i=0;i<userList.size();i++){
		if (i!=userList[i]->getID()){
			useEfficiencyCode = false;
			break;
		}
	}
	if (useEfficiencyCode == true){cout<<"ID's match the index of the UserList..."<<endl<<"--Using more efficient code."<<endl;}
	else{cout<<"ID's do not match the index of UserList"<<endl<<"--Using less efficient code."<<endl;}
	
	cout<<"Running BC Algorithm..."<<endl;
  //----------------------BC ALGORITHM-------------------	
    	Stack<BCUser*>* St = new Stack<BCUser*>;
  	Queue<BCUser*>* Q = new Queue<BCUser*>;
  for (int s = 0; s<userList.size(); s++){
  	for (int t = 0; t<userList.size(); t++){
  		BCUser* cacheBCUser = userList[t];
  		delete cacheBCUser->preds;
  		cacheBCUser->preds = new MyList<int>;
  		cacheBCUser->numsp =0;
  		cacheBCUser->dist = -1;
  		cacheBCUser->delta=0;
  	}
  	userList[s]->numsp =1; userList[s]->dist=0;
  	
  	Q->push_back(userList[s]);
  	
  	BCUser* v;
  	BCUser* w;
  	
  	while(Q->empty() == false){
		v =Q->front();
  		Q->pop_front();
  		St->push(v);
  		
  		for (int i=0; i<v->getFriendIDs()->size();i++){
  			if (useEfficiencyCode == false){w = findUserWithID(v->getFriendIDAt(i), &userList);}
  			else {w = userList[v->getFriendIDAt(i)];} //Assumes id's are sequential order. Assumes id's are equivalent to index in userlist
  			if (w->dist==-1){
  				Q->push_back(w);
  				w->dist = v->dist+1;
  			}
  			if (w->dist == v->dist+1){
  				w->numsp = w->numsp + v->numsp;
  				w->preds->push_back(v->getID());
  			}
  		}
  	}
  	while (St->empty()==false){
  				w = St->top();
  				St->pop();
  				for (int p=0; p<w->preds->size();p++){
  					if (useEfficiencyCode == false){v = findUserWithID(w->preds->at(p), &userList);}
  					else {v = userList[w->preds->at(p)];} //Assumes id's are sequential order. Assumes id's are equivalent to index in userlist
  					v->delta = v->delta + ((double)(v->numsp)/(double)(w->numsp))*((double)(1+w->delta));
  					
  				}
  				w->bc = w->bc + w->delta;
  				
  	}
  	
  }
  cout<<"--Done"<<endl;	

	if (userList.size()<=0){
		throw std::invalid_argument("bcalg.cpp 5: userList.size() is <= 0");
	}
	MyList<double>* norms = new MyList<double>;
	
	//Find max id of user
	int maxID = -1;
	for (int i=0; i<userList.size();i++){
		int checkID = userList[i]->getID();
		if (checkID>maxID){
			maxID = checkID;
		}
	}
	
	for (int i=0; i<maxID+1; i++){ // max ID +1 b/c array starts at 0;
		norms->push_back(-1);
	}
	double max = userList[0]->bc, min = userList[0]->bc;
	
	for (int i=0; i<userList.size(); i++){// max ID +1 b/c array starts at 0;
		double cacheUserBC = userList[i]->bc;;
		if (cacheUserBC<min){
			min = cacheUserBC;
		}
		if (cacheUserBC>max){
			max = cacheUserBC;
		}
		(*norms)[userList[i]->getID()] = cacheUserBC;
		
	}
	
	double maxMinusMin = max-min;
	
	for (int i=0; i<norms->size(); i++){
		if ((*norms)[i] != -1){
			(*norms)[i] = ((*norms)[i]-min)/maxMinusMin;
		}
	}

	return norms;
}

BCUser* BCAlg::findUserWithID(int id, MyList<BCUser*>* users){
  for(int i=0; i< (*users).size();i++){				//iterates through the user list.
  	if((*users)[i]->getID() == id){				//finds the user with the certain id
  		return (*users)[i];				//if found then return that user pointer
  	}
  }
  throw invalid_argument("No User Found. sn.cpp 179");		//if not found throw an error.
}
