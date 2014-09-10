#!/home/pi/bin/ctorun
// Gordian Edenhofer 22.04.14 20:23
// Entwicklung eines komplexen, sowie modularen Taschenrechners
// indent -ut -brf -nbad -bap -bbo -nbc -br -brs -c33 -cd33 -ncdb -ce -cli0 -cp33 -cs -d0 -di1 -nfc1 -nfca -hnl -i8 -ip0 -l100 -lp -npcs -nprs -npsl -saf -sai -saw -nsc -nsob -nss [Dateiname]

#include <stdio.h>
#include <math.h>


int Determinante3x3();
int Taschenrechner();
int Formelsammlung();
int Wahlmoeglichkeiten();
int pqFormel(double p, double q, double *pqergebniss1, double *pqergebniss2);
int Wertetabelle(int *a, int *b, int *c, int *d, int *e, int *yG);
int Geradengleichung(int *y, int *m, int *x, int *b, int *failG);


int main(int argc, char *argv[]) {
	int WoderB = 0;
	int AWM = 3;		// AWM: Anzahl der Wahlmoeglichkeiten

	while (WoderB != AWM) {
		puts("*****Menu*****\n(1) Taschenrechner\n(2) Formelsammlung\n(3) Beenden");
		scanf("%d", &WoderB);
		if (WoderB == 1) {
			Taschenrechner();
		} else if (WoderB == 2) {
			Formelsammlung();
		} else if (WoderB == AWM) {
			break;
		} else {
			printf("Ungueltige Eingabe!\n");
		}
	}
	return 0;
}


int Taschenrechner() {
	char Eingabe[205], Opf = 0, Op[205];
	int EingabenL = 1,
		CounterL = 0,
		CounterE = 0,
		Zahl1V = 1, fsV = 1, fsZ = 0, AbbruchL = 200, fs = 0, fsE = 0, Zahl[205];
	int CounterAZ = 0, CounterAOp = 0, CounterB = 1, CounterZE = 0, ZErgebnis, x = 0, Punkt = 0;	// Loesche alle vorhergehenden Ergebnisse
	
	for (CounterL = 0; CounterL < AbbruchL; ++CounterL)
		Eingabe[CounterL] = 0, Op[CounterL] = 0, Zahl[CounterL] = 0;
	puts("Eingabe (bitte zum Schluss ein '=' setzen!):");
	scanf("%s", Eingabe);
	for (CounterL = 0; CounterL < AbbruchL; CounterL++) {
		if (Eingabe[EingabenL - 1] == '=') {
			AbbruchL = -1;
		} else {
			EingabenL++;
		}
	}
	CounterE = 0;
	if (Eingabe[0] == '-') {
		fsV = -1;
		CounterE = 1;
	}
	for (; CounterE < EingabenL; CounterE++) {
		if (Eingabe[CounterE] == '0' ||
		    Eingabe[CounterE] == '1' ||
		    Eingabe[CounterE] == '2' ||
		    Eingabe[CounterE] == '3' ||
		    Eingabe[CounterE] == '4' ||
		    Eingabe[CounterE] == '5' ||
		    Eingabe[CounterE] == '6' ||
		    Eingabe[CounterE] == '7' ||
		    Eingabe[CounterE] == '8' || Eingabe[CounterE] == '9') {
			fsZ = fs * 10 + (Eingabe[CounterE] - '0');
			fs = fsZ;
		} else if (Eingabe[CounterE] == '+'
			   || Eingabe[CounterE] == '-'
			   || Eingabe[CounterE] == '*' || Eingabe[CounterE] == '/') {
			fsE = fsZ * fsV;
			Opf = Eingabe[CounterE];
			Zahl[++CounterAZ] = fsE;
			Op[++CounterAOp] = Opf;
			Opf = 0;
			fsE = 0;
			fs = 0;
			fsV = 1;
		} else if (Eingabe[CounterE] == '=') {
			fsE = fsZ * fsV;
			Opf = Eingabe[CounterE];
			Zahl[++CounterAZ] = fsE;
			Op[++CounterAOp] = Opf;
		} else {
			puts("Ungueltige Eingabe!");
			break;
		}
	}
	for (CounterB = 0; CounterB <= CounterAOp; CounterB++) {
		if (CounterB == 1) {
			switch (Op[CounterB]) {
			case ('+'):
				ZErgebnis = Zahl[CounterB] + Zahl[CounterB + 1];
				break;
			case ('-'):
				ZErgebnis = Zahl[CounterB] - Zahl[CounterB + 1];
				break;
			case ('*'):
				ZErgebnis = Zahl[CounterB] * Zahl[CounterB + 1];
				break;
			case ('/'):
				ZErgebnis = Zahl[CounterB] / Zahl[CounterB + 1];
				break;
			default:
				break;
			}
		} else {
			switch (Op[CounterB]) {
			case ('+'):
				ZErgebnis = ZErgebnis + Zahl[CounterB + 1];
				break;
			case ('-'):
				ZErgebnis = ZErgebnis - Zahl[CounterB + 1];
				break;
			case ('*'):
				ZErgebnis = ZErgebnis * Zahl[CounterB + 1];
				break;
			case ('/'):
				ZErgebnis = ZErgebnis / Zahl[CounterB + 1];
				break;
			}
		}
	}
	printf("Ergebnis: %d\n\n", ZErgebnis);
	return 0;
}


int Formelsammlung() {
	double p, q, pqergebnis1, pqergebnis2;
	int y = 0;

	int m = 0, x = 0, b = 0, w = 0, failG = 0;

	int a = 0, f = 0, c = 0, d = 0, e = 0, yG = 0;

	while (w < 4) {
		int w;
		puts("*****Formelsammlung*****\n(1) pq-Formel\n(2) Wertetabelle einer Funktion zweiten Grades\n(3) Geradengleichung\n(4) Bestimmung einer 3*3 Derterminante nach P. F. Sarrus\n(5) Formelsammlung beenden");
		scanf("%d", &w);
		switch (w) {
		case (1):
			printf("p=");
			scanf("%lf", &p);
			printf("q=");
			scanf("%lf", &q);
			y = pqFormel(p, q, &pqergebnis1, &pqergebnis2);
			if (y < 0) {
				puts("Diese Gleichung besitzt keine Nullstellen.\n");
			} else {
				puts("Loesung:");
				printf("x=%f  oder  x=%f\n\n", pqergebnis1, pqergebnis2);
			}
			break;
		case (2):
			puts("Ausgegangen von ax^2+bx+c !");
			printf("Startwert: ");
			scanf("%d", &d);	// cin >> d;
			printf("Endwert: ");
			scanf("%d", &e);	// cin >> e;
			printf("a=");
			scanf("%d", &a);	// cin >> a;
			printf("b=");
			scanf("%d", &b);	// cin >> f;
			printf("c=");
			scanf("%d", &c);	// cin >> c;
			puts("Loesung:");
			puts("y=\t\tx=");
			if (d > e) {
				puts("Upps, du hast wohl Start- und Endwert vertauscht...");
				break;
			}
			for (; d <= e; d++) {
				Wertetabelle(&a, &f, &c, &d, &e, &yG);
				printf("%d\t\t%d\n", yG, d);
				if (d == e) {
					puts("");
				}
			}
			break;
		case (3):
			puts("Schreibe 999 hinter die Variabel, welche du aufgeloest haben willst!");
			puts("Als Erinnerung die Formel war: y=m*x+b\n");
			printf("y=");
			scanf("%d", &y);	// cin >> y;
			printf("m=");
			scanf("%d", &m);	// cin >> m;
			printf("x=");
			scanf("%d", &x);	// cin >> x;
			printf("b=");
			scanf("%d", &b);	// cin >> b;
			Geradengleichung(&y, &m, &x, &b, &failG);
			if (failG == 1) {
				puts("Wohin soll aufgeloest werden? Bitte versuche es erneut.\n");
				break;
			}
			puts("Loesung:");
			printf("y=%d\n", y);
			printf("m=%d\n", m);
			printf("x=%d\n", x);
			printf("b=%d\n", b);
			break;
		case (4):
			Determinante3x3();
			break;
		case (5):
			return 0;
		default:
			puts("Ungueltige Eingabe, bitte versuche es nochmal.\n");
			break;
		}
	}
	return 0;
}


int Determinante3x3() {
	int n=1;
	double x[4], y[4], z[4], Determinante;
	puts("Fuer die Bestimmung einer 3*3 Determinante werden folgense Eingaben benoetigt:");
	puts("Bitte geben sie diese nach folgendem Schema ein:\nx1\ty1\tz1\nx2\ty2\tz2\nx3\ty3\tz3");
	for (n=1; n<=3; n++) {
		printf("\n\tx%d= ", n);
		scanf("%lf", &x[n]);
		printf("\ty%d= ", n);
		scanf("%lf", &y[n]);
		printf("\tz%d= ", n);
		scanf("%lf", &z[n]);
	}
	Determinante=x[1]*y[2]*z[3]+y[1]*z[2]*x[3]+z[1]*x[2]*y[3]-z[1]*y[2]*x[3]-x[1]*z[2]*y[3]-y[1]*x[2]*z[3];
	printf("Die Determinante ist %lf\n\n", Determinante);
	return 0;
}


int pqFormel(double p, double q, double *pqergebnis1, double *pqergebnis2) {
	double x;
	double y;
	x = p / 2;
	y = x * x - q;

	if (y < 0) {
		return -1;
	}

	*pqergebnis1 = -x + sqrt(y);
	*pqergebnis2 = -x - sqrt(y);

	return 0;
}


int Wertetabelle(int *a, int *f, int *c, int *d, int *e, int *yG)	// fuer ax^2+fx+c 
{
	*yG = *a * *d * *d + *f * *d + *c;
	return 0;
}


int Geradengleichung(int *y, int *m, int *x, int *b, int *failG) {
	if (*y == 999) {
		*y = *m * *x + *b;
	} else if (*m == 999) {
		*m = (*y - *b) / *x;
	} else if (*x == 999) {
		*x = (*y - *b) / *m;
	} else if (*b == 999) {
		*b = *y - (*m * *x);
	} else {
		*failG = 1;
		return (-1);
	}

	return 0;
}
