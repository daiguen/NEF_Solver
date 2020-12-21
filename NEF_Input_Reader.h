#ifndef __NEF_INPUT_READER_H__
#define __NEF_INPUT_READER_H__

#include <string>

using namespace std;

class NEF_Domain;

class NEF_Input_Reader {
private :
	string _inp_file;

public:
	NEF_Input_Reader() {

	}
	~NEF_Input_Reader() {

	}

	void set(string inp) { _inp_file = inp; }
	string get_input_file(void) { return _inp_file; }
	void read(NEF_Domain& dom);


};







#endif