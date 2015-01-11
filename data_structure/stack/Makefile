objects = testQueue.o queue_list.o 
terminal = testQueue
structure = queue_list

$(terminal): $(objects)
	gcc -o $(terminal) $(objects)
$(terminal).o: $(terminal).c $(structure).h
	gcc -c $(terminal).c 
$(structure).o: $(structure).c $(structure).h
	gcc -c $(structure).c
clean:
	rm -f *.o
