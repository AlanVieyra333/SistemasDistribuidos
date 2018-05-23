.PHONY: run
run: random_local make

random_local: random_funcion.c random_local.c
	gcc random_funcion.c random_local.c -o random_local

.PHONY: make
make: Makefile.rand
	make -f Makefile.rand
