objects = testGraph.o adjacencyMatrix.o MST.o

result:$(objects)
	gcc -o result $(objects)
testGrapc.o: testGraph.c adjacencyMatrix.h MST.h
	gcc -c -g testGraph.o
#adjacencyList.o: adjacencyList.c adjacencyList.h
#	gcc -c adjacencyList.c
adjacencyMatrix.o: adjacencyMatrix.c adjacencyMatrix.h
	gcc -c -g adjacencyMatrix.c
MST.o: MST.c MST.h
	gcc -c -g MST.c
#traverse.o: traverse.c  traverse.h adjacencyList.h queue_list.h
#	gcc -c traverse.c 
#queue_list.o: queue_list.h queue_list.c
#	gcc -c queue_list.c

.PHONY:clean
clean:
	rm -f *.o
