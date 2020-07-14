
all: compile

compile:
	gcc -o  2	2pesquisar.c -lm	
	gcc -o  21	2pesquisarv2.c -lm	
	nvcc -o 3	3compara_2vetores.cu -lm

clean:
	rm -rf ?