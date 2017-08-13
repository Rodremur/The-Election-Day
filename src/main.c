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
#include "electionday.h"

int main() {
	int n, i, j, p, sum;
	double V, I, B;
	double x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p);
		int * votes = malloc(sizeof(int) * p);
		char * names[p];
		int * res = malloc(sizeof(int) * p);
		sum = 0;
		V = 0;
		char aux[10];
		scanf("%s %lf", aux, &B);
        scanf("%s %lf", aux, &I);
		for (j = 0; j < p; j++)
		{
				names[j] = malloc(50 * sizeof(char));
                scanf("%s %d", names[j], &votes[j]);
                V += votes[j];
		}
		x = getProportion((double)p, V, B, I);
		for (j = 0; j < p; j++)
		{
			res[j] = (int)((double)votes[j] / x);
			sum += res[j];
		}
		choosePriority(sum, p, res, names);
		for (j = 0; j < p; j++) printf("%s %d\n", names[j], res[j]);
	}
	return 0;
}
