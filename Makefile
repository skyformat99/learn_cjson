all:test

test: *.c
	gcc *.c -o test -lm
clean:
	rm test -rf
