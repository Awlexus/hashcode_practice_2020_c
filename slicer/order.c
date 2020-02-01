#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "globals.h"
#include "order.h"
#include "pizza.h"

void addPizza(Order* order, Pizza* pizza) {
	int last = order->pizzaCount++;
	order->sliceCount += pizza->slices;

	order->pizzas = realloc(order->pizzas, sizeof(Pizza*) * order->pizzaCount);
	order->pizzas[last] = pizza;
}


// qsort(order.pizzas, order.pizzaCount, sizeof(Pizza), pizzaCompare);
void printOrder(Order order) {
	printf("%i\n", order.pizzaCount);

	int i;
	for(i = order.pizzaCount - 1; i >= 0; printf(" "), i--) {
		printf("%i", order.pizzas[i]->index);
	}

	printf("\n");
}

Order* mergeOrders(Order a, Order b) {
	Order* new = malloc(sizeof(Order));
	new->pizzaCount = a.pizzaCount + b.pizzaCount;
	new->sliceCount = a.sliceCount + b.sliceCount;

	new->pizzas = malloc(new->pizzaCount * sizeof(Pizza*));
	memcpy(new->pizzas, a.pizzas, a.pizzaCount * sizeof(Pizza*));
	memcpy(new->pizzas + a.pizzaCount, b.pizzas, b.pizzaCount * sizeof(Pizza*));

	return new;
}

int conflict(Order a, Order b) {
	int i,j;

	if(a.sliceCount + b.sliceCount > MAX_SLICES) return 1;

	for(i = 0; i < a.pizzaCount; i++) 		
		for(j = 0; j < b.pizzaCount; j++) 			
			if(a.pizzas[i]->index == b.pizzas[j]->index)
				return 1;

	return 0;
}

void freeOrder(Order* order) {
	if(order->pizzas != NULL) free(order->pizzas);
	free(order);
}

Order* copyOrder(Order* original) {
	Order* new = malloc(sizeof(Order));
	new->pizzaCount = original->pizzaCount;
	new->sliceCount = original->sliceCount;

	new->pizzas = malloc(new->pizzaCount * sizeof(Pizza*));
	memcpy(new->pizzas, original->pizzas, original->pizzaCount * sizeof(Pizza*));

	return new;
}

