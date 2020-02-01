CC=gcc
CFLAGS=-I ../includes/

DEPS=order.h pizza.h globals.h parser.h
OBJ = main.o order.o ../parser/parser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

slicer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

solutions: slicer
	./slicer ../inputs/a_example.in > ../outputs/a_example.in
	./slicer ../inputs/b_small.in > ../outputs/b_small.in
	./slicer ../inputs/c_medium.in > ../outputs/c_medium.in
	./slicer ../inputs/d_quite_big.in > ../outputs/d_quite_big.in
	./slicer ../inputs/e_also_big.in > ../outputs/e_also_big.in

test: slicer
	./slicer ../inputs/a_example.in

clean: 
	rm -f *.o slicer 

