#include "bcuser.h"

BCUser:: BCUser() : User(){
		 dist =-1;           // distance to current source vertex
		 numsp=0;          // number of shortest paths
		 delta=0;       // partial BC score
		 bc=0;          // total BC score
		 preds = new MyList<int>;
};
BCUser:: BCUser(string name_, int age_, int zipCode_, int id_) : User(name_, age_, zipCode_, id_){
		 dist =-1;           // distance to current source vertex
		 numsp=0;          // number of shortest paths
		 delta=0;       // partial BC score
		 bc=0;          // total BC score
		 preds = new MyList<int>;
}

BCUser::~BCUser(){ delete preds;}
