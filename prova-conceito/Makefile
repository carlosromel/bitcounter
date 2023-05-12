#
# Projeto de referência.
#
.PHONY: clean run

obj/main.o: main.c
	gcc $^ -o $@

clean:
	rm -f *.o

run: obj/main.o
#	xterm -fn 10x20 -hold -e ./$<
	$<

install: obj/main.o
	./$<

obj:
	mkdir $@
