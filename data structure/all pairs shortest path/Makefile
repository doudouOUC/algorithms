objects = floyd-warshall.o adjacencyMatrix.o testFloyd.o

result:$(objects)
	gcc -o result $(objects)
testFloyd.o:  floyd-warshall.h testFloyd.c
	gcc -c testFloyd.c
floyd-warshall.o: floyd-warshall.h floyd-warshall.c
	gcc -c floyd-warshall.c
adjacencyMatrix.o: adjacencyMatrix.h adjacencyMatrix.c
	gcc -c adjacencyMatrix.c
.PHONY:clean
clean:
	rm -f *.o
