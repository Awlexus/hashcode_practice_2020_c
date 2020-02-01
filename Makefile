all:
	(cd slicer; make slicer)
	(cd validator; make validator)

solutions: all
	(cd slicer; make solutions)
	(cd validator; make validate)

clean:
	(cd slicer; make clean)
	(cd validator; make clean)
	(cd parser; make clean)

test:
	(cd slicer; make test)
	(cd validator; make test)

