objects = testGraph.o adjacencyList.o bellman-ford.o

result:$(objects)
	gcc -o result $(objects)
testGrapc.o: testGraph.c  bellman-ford.h
	gcc -c -g testGraph.o
adjacencyList.o: adjacencyList.c adjacencyList.h
	gcc -c adjacencyList.c
bellman-ford.o: bellman-ford.c bellman-ford.h
	gcc -c -g bellman-ford.c

.PHONY:clean
clean:
	rm -f *.o
