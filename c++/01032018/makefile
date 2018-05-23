.PHONY: exec
exec: ejercicio_1
	@echo "========================="
	@echo "Executing..."
	time ./ejercicio_1_a
	@echo "\n"
	@echo "Executing..."
	time ./ejercicio_1_b
	@echo "\n"
	@echo "Executing..."
	time java ejercicio_1

ejercicio_1: ejercicio_1_a ejercicio_1_b ejercicio_1.class
	@echo "Compilados."

################################################################################
ejercicio_1_a: ejercicio_1.c
	@g++ ejercicio_1.c -o ejercicio_1_a

################################################################################
ejercicio_1_b: ejercicio_1.cpp
	@g++ ejercicio_1.cpp -o ejercicio_1_b

################################################################################
ejercicio_1.class: ejercicio_1.java
	@javac ejercicio_1.java
