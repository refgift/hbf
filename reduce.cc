// (C) Copyright 2024 Larry B. Daniel
// Reduce, given a number will reduce it to a digit.
#include <iostream>
#include <cstdlib>
using namespace std;

div_t qr;
int reduce(int a) {
	qr.quot=0;
	qr.rem=0;
	while(a>9) {
		qr = div(a,10);
		a =  qr.quot + qr.rem;
	}
	return a;
}

int tmain(int argc, char** argv) {
	if (argv[1]==nullptr) exit(-1);
	cout << argv[1] << endl;
	cout << reduce(atoi(argv[1])) << endl;
	return 0;
}
		
	
