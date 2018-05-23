.PHONY: run
run: random_local make

random_local: random_funcion.c random_local.c
	gcc random_funcion.c random_local.c -o random_local

.PHONY: make
make: Makefile.rand
	make -f Makefile.rand

.PHONY: clean
clean:
	rm rand_*
	rm Makefile.rand
	rm rand.h

.PHONY: new
new: clean
	rpcgen -C -a rand.x
