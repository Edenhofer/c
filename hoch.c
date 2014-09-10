#!/home/pi/bin/ctorun
// Gordian Edenhofer 01.05.14 17:36
// Entwicklung eines Programm fuer die Berechnung einer Potenz 
// indent -ut -brf -nbad -bap -bbo -nbc -br -brs -c33 -cd33 -ncdb -ce -cli0 -cp33 -cs -d0 -di1 -nfc1 -nfca -hnl -i8 -ip0 -l100 -lp -npcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss [Dateiname]

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[2]) {

	if (argc != 3) {
		puts("Es muessen genau zwei Argumente mitgegeben werden.\n");
		return 2;
	}
	
	long b = atol(argv[1]);
	long e = atol(argv[2]);
	long x = 1;
	int temp = 0;
	int i2 = 2;
	int ie = e;
	int n = 0;
	
	temp = ie % i2;
	if (b < 0 && temp == 0) {
		b *=-1;
	} else if (b < 0 && temp != 0) {
		b *= -1;
		printf("-");
	}
	
	if (e < 0) {
		printf("1/");
		e *= -1;
	} else if (e == 0) {
		printf("1\n");
		return 0;
	} 


	while (n < e) {
		x *= b;
		n++;
	}
	printf("%ld\n", x);
	
	return 0;
}
