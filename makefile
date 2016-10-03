egg:	egg.o edd.o
	gcc -o egg egg.o
	gcc -o edd edd.o
egg.o	:egg.c edd.c
	gcc -c egg egg.c
	gcc -c edd edd.c
clean:
	rm *.o
