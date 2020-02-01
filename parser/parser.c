#include <stdio.h>
#include <stdlib.h>

#include "pizza.h"

int MAX_SLICES, PIZZA_COUNT;
Pizza* PIZZAS = NULL;

void parsePizzas(char* filename) {
	int i;
	FILE* file = fopen(filename, "r");

	fscanf(file, "%i %i", &MAX_SLICES, &PIZZA_COUNT);

	PIZZAS = malloc(PIZZA_COUNT * sizeof(Pizza));
	for(i = 0; i < PIZZA_COUNT; i++) {
		PIZZAS[i].index = i;
		fscanf(file, "%i", &PIZZAS[i].slices);
	}
	
	fclose(file);
}

