objects = testGraph.o adjacencyMatrix.o

result:$(objects)
	gcc -o result $(objects)
testGrapc.o: testGraph.c adjacencyMatrix.h
	gcc -c testGraph.o
#adjacencyList.o: adjacencyList.c adjacencyList.h
#	gcc -c adjacencyList.c
adjacencyMatrix.o: adjacencyMatrix.c adjacencyMatrix.h
	gcc -c adjacencyMatrix.c
#traverse.o: traverse.c  traverse.h adjacencyList.h queue_list.h
#	gcc -c traverse.c 
#queue_list.o: queue_list.h queue_list.c
#	gcc -c queue_list.c

.PHONY:clean
clean:
	rm -f *.o
