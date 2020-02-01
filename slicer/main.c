#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "globals.h"
#include "parser.h"
#include "pizza.h"
#include "order.h"

Order* best = NULL;

void finish(Order* current, int currentIndex) {
	addPizza(current, PIZZAS + currentIndex);
	printOrder(*current);
}

void printStack(Order* order) {
	printf("%i\t| ", order->sliceCount);

	int i;
	for (i = 0; i < order->pizzaCount; printf(" "), i++) 
		printf("%i", order->pizzas[i]->index);

	printf("\n");

}

int recursiveGoal(Order* current, int currentIndex) {
	if(currentIndex < 0) return 0;

	Order* copy = copyOrder(current);
	addPizza(copy, PIZZAS + currentIndex);
	// printStack(copy);

	if(copy->sliceCount == MAX_SLICES) {
		finish(current, currentIndex);
		freeOrder(copy);
		return 1;
	} else if (copy->sliceCount <= MAX_SLICES) {
		if (copy->sliceCount > best->sliceCount) {
			free(best);
			best = copyOrder(copy);
		}
		int result = recursiveGoal(copy, currentIndex - 1);
		freeOrder(copy);
		if (result) return 1;
		if (recursiveGoal(current, currentIndex - 1)) return 1;
		return 0;
	} else {
		freeOrder(copy);
		return recursiveGoal(current, currentIndex - 1);
	}
}

int main(int argc, char** argv) {
	parsePizzas(argv[1]);
	best = malloc(sizeof(Order));
	best->pizzaCount = 0;
	best->sliceCount = 0;
	best->pizzas = 0;

	Order* start = malloc(sizeof(Order));
	start->pizzaCount = 0;
	start->sliceCount = 0;
	start->pizzas = 0;

	if(!recursiveGoal(start, PIZZA_COUNT - 1)) 
		printOrder(*best);

	freeOrder(best);
	freeOrder(start);
	free(PIZZAS);

	return 0;
}
