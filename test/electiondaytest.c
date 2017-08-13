/*-------------------------------------------------------
 * Proyecto Final de Programación Avanzada: 12020 - The Election Day
 * Ratio: 21.43%	Volume: 120
 * Fecha: 28/11/2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utest.h"
#include "../src/electionday.h"

//Global Variable
 char msg[100];

static char * test_getProportion()
{
	double INV, T, B, I, V, x, expected;
	int p;
	B = 22;
	I = 1000;
	p = 3;
	V = 14;
	INV = B + I;
	T = V + INV;
	expected = (V - (INV/(T*(double)p)))/100;
	printf("%lf\n", expected);
	x = getProportion((double)p, V, B, I);
	sprintf(msg, "x must be %lf\n", expected);
 	assert_test(msg, x == expected);
	return 0;
}

static char * test_choosePriority()
{
	int *res = malloc(3 * sizeof(int));
	res[0] = 33;
	res[1] = 33;
	res[2] = 34;
	char *names[] = {"Pragmatics", "Paradigmatics", "Programatics"};
	int sum = 99;
	int expected = 34;
	choosePriority(sum, 3, res, names);
	sprintf(msg, "Second party must have %d votes", expected);
	assert_test(msg, res[1]==expected);
	return 0;
}

 int main()
 {
 	run_test("Test Get Proportion:", test_getProportion);
 	run_test("Test Choose Priority:", test_choosePriority);
 	return 0;
 }