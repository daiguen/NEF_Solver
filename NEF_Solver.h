#ifndef __NEF_SOLVER_H__
#define __NEF_SOLVER_H__

#include <stdio.h>
#include "NEF_Input_Reader.h"
#include "NEF_Domain.h"

using namespace std;

class NEF_Solver {
private:
	NEF_Input_Reader* _input_reader;
	NEF_Domain* _dom;

public:
	NEF_Solver() {
		_input_reader = NULL;
		_dom = NULL;
	}
	~NEF_Solver() {

	}
	void set(string inp);
	void run(void);

	NEF_Input_Reader& get_input_reader(void) { return *_input_reader; }
	NEF_Domain& get_domain(void) { return *_dom; }
};


#endif