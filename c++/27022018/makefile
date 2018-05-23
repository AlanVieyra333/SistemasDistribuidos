.PHONY: exec
exec: ejercicio_3
	@echo "========================="
	@echo "Executing..."
	time ./ejercicio_3_a
	@echo "\n"
	@echo "Executing..."
	time ./ejercicio_3_b
	@echo "\n"
	@echo "Executing..."
	time java ejercicio_3

ejercicio_3: ejercicio_3_a ejercicio_3_b ejercicio_3.class
	@echo "Compilados."

################################################################################
ejercicio_3_a: ejercicio_3.c
	@g++ ejercicio_3.c -o ejercicio_3_a

################################################################################
ejercicio_3_b: ejercicio_3.cpp
	@g++ ejercicio_3.cpp -o ejercicio_3_b

################################################################################
ejercicio_3.class: ejercicio_3.java
	@javac ejercicio_3.java
