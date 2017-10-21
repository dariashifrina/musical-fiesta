all: main.c
	gcc main.c -o music
run: music
	./music
clean:
	rm *.o
