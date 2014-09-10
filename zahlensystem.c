#!/home/pi/bin/ctorun
// Gordian Edenhofer 01.05.14 15:11
// Entwicklung eines Systemumwandlers fuer Zahlen
// indent -ut -brf -nbad -bap -bbo -nbc -br -brs -c33 -cd33 -ncdb -ce -cli0 -cp33 -cs -d0 -di1 -nfc1 -nfca -hnl -i8 -ip0 -l100 -lp -npcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss [Dateiname]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hoch(int a, int b);

int main(int argc, char *input[2]) {

	if (argc != 3) {
		puts("Es muessen genau zwei Argumente mitgegeben werden.");
		return 2;
	}

	int number = atoi(input[1]);
	int system = atoi(input[2]);
	int output[128];
	int x = 0;
	int n = 0;
	int a = 1;

	if (system <= 1) {
		puts("Das System kann weder gleich noch kleiner als eins sein.");
		return 3;
	}

	if (number < 0) {
		printf("- ");
		number *= -1;
	}

	do {
		x = number / a;
		output[n++] = x % system;
		a *= system;
	} while (x >= system);

	// Prints the result to the console
	while (n > 1) {
		printf("%d.", output[--n]);
	}
	printf("%d\n", output[--n]);

	return 0;
}

#ifdef NICHT_BENOETIGT
int hoch(int a, int b) {
	int n = 0;
	int x = 1;

	for (n = 0; n < b; n++) {
		x *= a;
	}
	return x;
}
#endif
