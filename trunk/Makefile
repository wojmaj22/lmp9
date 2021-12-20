all:
	cc src/main.c src/mat_io.c src/gauss.c src/backsubst.c -o bin/gauss

oblicz: all
	bin/gauss dane/A dane/b
debug: 
	cc src/*.c -o bin/gauss_debug -ggdb
	gdb bin/gauss_debug
tester:
	cc src/tester.c src/mat_io.c src/gauss.c src/backsubst.c -o bin/tester
test1: tester
	bin/tester 1 dane/dane_testowe/test1 dane/dane_testowe/test1_w dane/dane_testowe/wyniki_1
test2: tester
	bin/tester 2 dane/dane_testowe/test2 dane/dane_testowe/test2_w
test3: tester
	bin/tester 3 dane/dane_testowe/test3 dane/dane_testowe/test3_w
test4: tester
	bin/tester 3 dane/dane_testowe/test4 dane/dane_testowe/test4_w
