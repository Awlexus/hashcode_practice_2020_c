CC=gcc
CFLAGS=-I ../includes/

DEPS=pizza.h globals.h parser.h
OBJ= main.o ../parser/parser.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

validator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

validate:
	./validator ../inputs/a_example.in ../outputs/a_example.in
	./validator ../inputs/b_small.in ../outputs/b_small.in
	./validator ../inputs/c_medium.in ../outputs/c_medium.in
	./validator ../inputs/d_quite_big.in ../outputs/d_quite_big.in
	./validator ../inputs/e_also_big.in ../outputs/e_also_big.in

slicer:
	(cd ../slicer; make slicer)

test: validator slicer
	../slicer/slicer ../inputs/a_example.in > ../outputs/a_example.out
	./validator ../inputs/a_example.in ../outputs/a_example.out

clean: 
	rm -f *.o validator 

