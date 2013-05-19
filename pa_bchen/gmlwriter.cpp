#include "gmlwriter.h"

bool GMLWriter::write(char *outputFile, MyList<User*>& users){
	ofstream out;								//Create file to write to.
	out.open(outputFile);							//opens the file name given in the command prompt.
	if (out.fail()){							//if the open fails then.
		cout<<"Could not write to file! Failed."<<endl;			//say that it failed
		return false;							//return false.
	}
	
	out<<"graph ["<<endl;							//"graph" syntax for first line.
	for (int i=0; i<users.size();i++){					//iterating through the nodes.
		out<<"node ["<<endl;						//"node" syntax
		out<<"id "<<users[i]->getID()<<endl;				//"id" syntax
		out<<"name "<<users[i]->getName()<<endl;			//"name" syntax
		out<<"age "<<users[i]->getAge()<<endl;				//"age" syntax
		out<<"zip "<<users[i]->getZipCode()<<endl;			//"zipcode" syntax
		out<<"]"<<endl;							//"end bracket" syntax
	}

	for (int i=0; i<users.size();i++){					//iterate through edges
		for (int j=0; j<users[i]->getFriendIDs()->size();j++){		//iterate through all friends in each user
			out<<"edge ["<<endl;					//"edge" syntax
			out<<"source "<<users[i]->getID()<<endl;		//"source" syntax
			out<<"target "<<users[i]->getFriendIDs()->at(j)<<endl;	//"target" syntax
			out<<"]"<<endl;						//"end bracket" syntax
		}
	}
	out<<"]";								//another "end bracket" syntax
	
	out.close();								//close the file
	return true;								//successfully opened and closed file.
}
