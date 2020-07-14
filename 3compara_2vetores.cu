#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tempo.h"

#define TAM 30800


//-----aloca memória global - na RAM e na GPU
__managed__ char genoma1[TAM];
__managed__ char genoma2[TAM];
__managed__ int equals[10][10];
 

__global__ void compara(int *quantidade)
{
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	if ((genoma1[idx] != NULL) || (genoma2[idx] != NULL))
	{
		if (genoma1[idx] == genoma2[idx])
		{
			atomicAdd(quantidade, 1);
		}
	}
	genoma1[idx] = NULL;
	genoma2[idx] = NULL;
}


void equals()
{
    int maior = 0;
    int val1;
    int val2;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(maior < maior[i][j]){
							maior = maior[i][j];
                val1 = i;
                val2 = j;
						}
						printf(" %5d ", matriz_quantidade_iguais[i][j]);
				}
				printf("\n");
    }
}

int main(int argc, char *argv[0])
{
	tempo1();
	int *num;
	*num = 0;

	int i;

  cudaMallocManaged(&num, 4);
  srand(time(NULL));

	for (int j = 0; j < 9; j++)
	{
		for (int k = j + 1; k < 10; k++)
		{
			char g1[14] = "genomas/";
			g1[8] = j + '0';
			strcat(g1, ".txt");

			char g2[14] = "genomas/";
			g2[8] = k + '0';
			strcat(g2, ".txt");
			char c; 

			FILE *file1;
			file1 = fopen(g1, "r");
			int i = 0;
			while ((c = getc(file1)) != EOF)
			{
				gen_a[i] = c;
				i++;
			}
			fclose(file1);

			FILE *file2;
			file2 = fopen(g2, "r");
			i = 0;
			while ((c = getc(file2)) != EOF)
			{
				gen_b[i] = c;
				i++;
			}
			fclose(file2);

			compara<<<700, 44>>>(num);

			cudaDeviceSynchronize();

			matriz_quantidade_iguais[j][k] = *num;
			*num = 0;
			printf("\n\n");
		}
	}
	equals();
	tempo2();
	tempoFinal("mili segundos", argv[0], MSGLOG);
}




