#include "NEF_Solver.h"
#include <string>

using namespace std;

void NEF_Solver::set(string inp) {
	_input_reader = new NEF_Input_Reader;
	_dom = new NEF_Domain;

	NEF_Input_Reader& inp_reader = get_input_reader();
	NEF_Domain& dom = get_domain();
	
	inp_reader.set(inp);
	inp_reader.read(dom);
	int a = 1;
	a += 1;
	
}


void NEF_Solver::run(void) {
	NEF_Domain& dom = get_domain();
	dom.calculate();


}

