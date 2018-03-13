target = test
$(target): rttree_test.o rbtree.o
	gcc -o $@ $^
rttree_test.o: rttree_test.c 
	gcc -c $^
rbtree.o: rbtree.c rbtree.h
	gcc -c $^
clean:
	rm *.o
	
