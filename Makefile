CFLAGS: -Wall -pedantic -std=c11 -l. -g

all:					non_empty_test

list.o:				list.c list.h  
							gcc $(CFLAGS) -c list.c

non_empty_test.o: 	non_empty_test.c list.h
											gcc $(CFLAGS) -c non_empty_test.c

non_empty_test:		non_empty_test.o list.o
									gcc $(CFLAGS) non_empty_test.o list.o -o non_empty_test

clean:				rm -f *.o non_empty_test
