#ifndef BC_ALG_H
#define BC_ALG

#include "mylist.h"
#include "bcuser.h"

class BCAlg {
	public:
	 static MyList<double>* computeBC(MyList<BCUser*> &userList);
	 static BCUser* findUserWithID(int id, MyList<BCUser*>* users);

};
#endif
