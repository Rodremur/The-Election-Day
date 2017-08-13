/*-------------------------------------------------------
 * Proyecto Final de Programación Avanzada: 12020 - The Election Day
 * Ratio: 21.43%	Volume: 120
 * Fecha: 28/11/2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */
#include <stdio.h>
#include "electionday.h"

double getProportion(double p, double V, double B, double I)
{
	double INV, T;
	INV = B + I;
	T = INV + V;
	if (INV > V) return (V - (INV/(T*p)))/100;
	else return (V - (INV/T) - (p/200))/100;
}

void choosePriority(int sum, int p, int * res, char **names)
{
	int j, k;
	while (sum < 100) {
		for (j = 0; j < p - 1; j++)
		{
			if (sum == 100) break;
			if (res[j] == res[j + 1]) {
				for (k = 0; k < 50; k++) {
					if (names[j][k] < names[j + 1][k]) {
						res[j] += 1;
						sum ++;
						break;
					} else if (names[j][k] > names[j + 1][k]) {
						res[j + 1] += 1;
						sum ++;
						break;
					}
				}
			}
		}
	}
	return;
}