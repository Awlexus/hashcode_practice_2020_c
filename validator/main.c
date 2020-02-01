#include <stdio.h>
#include <stdlib.h>

#include "globals.h"
#include "parser.h"

int main(int argc, char** argv) {
	parsePizzas(argv[1]);

	int i, sum, pizzaCount;
	int* order = NULL;

	FILE* result_file = fopen(argv[2], "r");
	fscanf(result_file, "%i", &pizzaCount);

	order = malloc(pizzaCount * sizeof(int));

	for(i = 0; i < pizzaCount; i++) {
		fscanf(result_file, "%i", order + i);
	}

	fclose(result_file);

	// Check if pizzas are in the right order
	for(i = 0; i < pizzaCount - 1; i++) {
		if(order[i] > order[i + 1]) fprintf(stderr, "Pizza %i should not be before Pizza %i\n", i, i + 1);
	}

	// Check if the total sum is not greater than allowed
	for(i = 0, sum = 0; i < pizzaCount; i++) {
		sum += PIZZAS[order[i]].slices;
	}

	printf("%i out of %i Slices. ", sum, MAX_SLICES);

	if(sum > MAX_SLICES) {
		printf("That's wasted food!\n");
	} else if(sum == MAX_SLICES) {
		printf("Well done!\n");
	} else {
		printf("\n");
	}

	free(order);
	free(PIZZAS);

	return 0;
}
