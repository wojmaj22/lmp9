all:
	cc src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b

test2: all
	bin/gauss dane/C dane/d
debug: 
	cc src/*.c -o bin/gauss_debug -ggdb
	gdb bin/gauss_debug dane/C dane/d
