#ifndef SLICER_ORDER
#define SLICER_ORDER

#include "pizza.h"

typedef struct {
	int sliceCount;
	int pizzaCount;
	Pizza** pizzas;
} Order;

void addPizza(Order *order, Pizza* pizza);

void printOrder(Order order);
void freeOrder(Order* order);
Order* copyOrder(Order* order);

#endif
