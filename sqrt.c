#!/home/pi/bin/ctorun

#include <stdio.h>
#include <math.h>

int main() {

int x=0;
for (x=0; x<=40; x++) {
	switch (x) {
		case 5:
			printf ("Der Logarithmus von 5 ist %f\n", log(x));
			break;
		case 15:
			printf ("Der Sinus von 15 ist %f\n", sin(x));
			break;
		case 20:
			printf ("Der Kosinus von 20 ist %f\n", cos(20));
			break;
		default:
			printf("Die Wurzel von %d ist %f\n", x, sqrt(x));
			break;
		}
}
}
