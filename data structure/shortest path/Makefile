objects = testGraph.o adjacencyMatrix.o dijkstra.o

result:$(objects)
	gcc -o result $(objects)
testGrapc.o: testGraph.c  adjacencyMatrix.h
	gcc -c -g testGraph.o
adjacencyList.o: adjacencyMatrix.c adjacencyMatrix.h
	gcc -c adjacencyMatrix.c
bellman-ford.o: dijkstra.c dijkstra.h
	gcc -c -g dijkstra.c

.PHONY:clean
clean:
	rm -f *.o
