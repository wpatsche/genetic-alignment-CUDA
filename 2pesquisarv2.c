#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define TAM 30300

void carrega_genoma();
void compara_genoma();
void exibe_resultado();
void compara_sequencia();

int igual, dif;
char genoma1[TAM];
char genoma2[TAM];
int TAM1, TAM2;

//versao 2
#define L 10
#define C 10
void inicializa_matriz();
void mostra_resultado();
int m1[C][L];



int main(int argc, char *argv[0])
{
	carrega_genoma();          //carrega genoma 1 e 2
	compara_genoma();          //compara
//	exibe_resultado();         //exibe os genomas lado a lado

                                
    m1[0][1] = igual;           //comparamos o genoma 1 com o 2 - na matriz colocamos 0 com 1 pois começa em 0
    mostra_resultado();         // <--- versao 2  - mostra matriz

 //   compara_sequencia();
}




//funcao carrega genomas
//===============================================================  
void carrega_genoma(){

        int i=0;
        char c;


        //genoma 1
	    FILE *file1;

        //abre arquivo para leitura
	    file1 = fopen("genomas/AY278741.txt","r");	  
	 

	    //carrega o conteudo do arquivo no vetor genoma1
        i = 0;        
	    while((c=getc(file1)) != EOF){                     //le um nucleotideo do primeiro genoma enquanto não chegor ao final do arquivo
        
            genoma1[i]=c;   
            i++;
        }
		TAM1 = i;
        printf("\n tamanho do arquivo  %d ", TAM1);
        
        //fecha arquivo
	    fclose(file1);



		//genoma 2  
	    FILE *file2;

        //abre arquivo para leitura
	    file2 = fopen("genomas/KY417146.txt","r");

	    //carrega o conteudo do arquivo no vetor genoma1	    
        i = 0;
	    while((c=getc(file2)) != EOF){                     
        
            genoma2[i]=c;     
			i++;                            
        }

		TAM2 = i;
        printf("\n tamanho do arquivo  %d ", TAM2);
        
        if (TAM1 > TAM2)
			TAM1 = TAM2;

        printf("\n tam do menor arquivo ----------  %d ", TAM1);
        
        //fecha arquivo
     	fclose(file2);

}



//funcao compara 
//===============================================================     
void compara_genoma()
{
	    int i=0, 
            x=0;

        igual=0;
        dif=0;

	    for(i = 0; i < TAM1; i++){                      

           if (genoma1[i] == genoma2[i]) {                                  //compara os dois nucleotideos
                igual  ++;

            } else {
                dif ++;
                //scanf("%d", &x);                            
                //sleep(1); 
            }

        }
}


//exibe resultado 
//===============================================================     
void exibe_resultado()
{

        int i=0;

	    for(i = 0; i < TAM1; i++){                      

            printf("\n | %5d  | %c | %c |", i, genoma1[i], genoma2[i]);

        }


        printf("\n\n | Iguais %-18d \n | Diferentes %-18d ", igual, dif);

        printf("\n\n");

}

 



//funcao compara sequancia 
//===============================================================     
void compara_sequencia()
{

        int i=0,
            j=0,
            igual=0,
            inicio=0,
            qtde=0;

        for(i = 0, j=0; i < TAM; i++, j++){                      

           if (genoma1[i] == genoma2[j]) {                                   
                igual  ++;

            } else {                           

                if (igual > qtde) {

                    qtde = igual;
                    inicio = i - qtde;
                    igual=0;

                    printf("\n i = %-8d | inicio = %-8d | qtde = %-8d | ", i, inicio, qtde);

                }                            
            }
        }
        printf("\n\n");
}




void inicializa_matriz()
{
        int z, v;
        printf("\n inicializando matrizes ...\n");
        for (z=0; z < L; z ++)
        for (v=0; v < C; v++){
            m1[z][v] = 0;
        }
}



void mostra_resultado()
{
        int z, v;
        printf("\n  RESULTADO COMPARAÇÃO DE GENOMAS\n\n");

        for (z=0; z < L; z ++){
        for (v=0; v < C; v++) {
                    printf("  %5.2d", m1[z][v]);
        }
            printf("\n");
    }
    printf("\n\n\n");
    
}

