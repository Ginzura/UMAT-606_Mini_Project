srep: main.o functions.o
	gcc main.o functions.o -o srep
	
main.o: main.c
	gcc -c main.c
	
functions.o: functions.c
	gcc -c functions.c
	
