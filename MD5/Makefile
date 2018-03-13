test: md5.o md5_test.o
	gcc -o $@ $^
md5.o: md5.c md5.h
	gcc -c $<
md5_test.o: md5_test.c md5.h
	gcc -c $<
