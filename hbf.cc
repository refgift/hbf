/* hbf - (C) Copyright 2026 Larry B. Daniel Atlanta, Ga. */
// Abuse of Power Fighter

#include <thread>
#include <chrono>
#include <iostream>
#include <sys/resource.h>
#include <cstring>

#define POWERABUSER 175
#define SMALL 72
#define ABUSER 101
#define HOLDBACKER 119

using namespace std;
using namespace std::chrono;


extern int reduce(int);

int rnd() {
    static long rndresult=0;
    asm ("1:  rdrand %0; jnc 1b":"=r" (rndresult));
    return rndresult;
}

void apply() {
        static int F [[maybe_unused]];
	F=0;
	this_thread::sleep_for(milliseconds(110));
	F=SMALL;
	this_thread::sleep_for(milliseconds(110));
	F=0;
	this_thread::sleep_for(milliseconds(110));
	}

int main(int argc, char** argv) {

        static int A,B,C,D,E=0;
	static bool quiet = false;

	for (int i = 1; i < argc; ++i) if (!strcmp(argv[i], "-q")) quiet = true;

	cerr << "hbf" <<endl;

        setpriority(0,0,-20);

	while(true) {
		this_thread::yield();
		if (!quiet) cerr << ".";

		// DETECT
		int n = reduce(abs(rnd()));
		if (n==1 && A==0) A=n;
		if (n==1 && A==1) B=n;
		if (n==9 && B==1) C=n;
		
                // APPLY
		if (A==1 && B==1 && C==9) {
                       if (!quiet) cerr << "!";
			apply();
			A=0;
			B=0;
			C=0;
			D=0;
			E=0;
		}
	}
	return 0;
}	
