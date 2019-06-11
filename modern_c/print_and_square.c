/* This may look like nonsense but really it is a 
comment  */
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	//declarations
	double A[5] = {
		[0] = 9.0,
		[1] = 2.9,
		[4] = 3.E+25,
		[3] = .00007,
	};

	//loop over the elements in the double list
	for (size_t i = 0; i < 5; i++) {
		printf("element %zu is %g, \tits square is %g\n",
			i,
			A[i],
			A[i]*A[i]);
	}

	return EXIT_SUCCESS;
}
