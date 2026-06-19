// (C) Copyright 2024 Larry B. Daniel
// Reduce, given a number will reduce it to a digit.
// Uses Digital root method.

int reduce(int a) {
	if (a<=0) a=0;
	else {
		a %= 9;
		if (a==0) a = 9;
	}
	return a;
}







		
	
