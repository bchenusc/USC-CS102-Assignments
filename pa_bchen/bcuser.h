#ifndef BCUSER_H
#define BCUSER_H
#include "user.h"

class BCUser : public User {
	public:
		BCUser();
		BCUser(string name_, int age_, int zipCode_, int id_);
		~BCUser();
		int dist;           // distance to current source vertex
		int numsp;          // number of shortest paths
		MyList<int>* preds;  // List of predecessors
		double delta;       // partial BC score
		double bc;          // total BC score
	
	private:
		
};

#endif
