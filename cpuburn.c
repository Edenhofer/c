#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char *argv[]) {
	double x;
	if (argc < 2) return 1;
	int n = atoi(argv[1]);
	while (n-- > 0) {
		x = sin(log(x+10)) + 1.1;
		x = sqrt(x*3.9 + x*x/4.2);
		if (argc >= 3) printf("%f\n",x);
	}
	return 0;
}

