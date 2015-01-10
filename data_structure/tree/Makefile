objects = testTree.o tree_list.o 
terminal = testTree
structure = tree_list

$(terminal): $(objects)
	gcc -o $(terminal) $(objects)
$(terminal).o: $(terminal).c $(structure).h
	gcc -c $(terminal).c 
$(structure).o: $(structure).c $(structure).h
	gcc -c $(structure).c

.PHONY: clean
clean:
	rm -f *.o
