#ifndef GML_WRITER_H
#define GML_WRITER_
#include <fstream>
#include "bcuser.h"
#include "user.h"

class GMLWriter{
	public:
		static bool write(char *outputFile, MyList<User*>& users); //function can be called outside of class.
		static bool write(char *outputFile, MyList<BCUser*>& bcusers); //function can be called outside of class.

	private:
		
};
#endif
