objects = matrixSP.o adjacencyMatrix.o testMatrixSp.o

result:$(objects)
	gcc -o result $(objects)
testMatrixSp.o:  matrixSP.h testMatrixSp.c
	gcc -c testMatrixSp.c
matrixSP.o: matrixSP.h matrixSP.c
	gcc -c matrixSP.c
adjacencyMatrix.o: adjacencyMatrix.h adjacencyMatrix.c
	gcc -c adjacencyMatrix.c
.PHONY:clean
clean:
	rm -f *.o
