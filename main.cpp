#include <stdio.h>
#include <Windows.h>
#include <string>

#include "NEF_Solver.h"

using namespace std;

int main(int argc, char** argv) {
	int idx = 0;
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], "-i")) {
			idx = i + 1;
			break;
		}
	}
	string inp;
	inp = argv[idx];

	NEF_Solver solver;
	solver.set(inp);
	solver.run();
}