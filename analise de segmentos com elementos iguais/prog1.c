#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    //variaveis que serão utilizadas
    int qtdeDeElementos = 0,qtdeDeColunas=0,qtdeSegmentos=0,linha = 1,i=0,j=0,k=0,n=0,h=0,valor,controle=0,diferente = 0;
    int igual = 0;
    //alocação dinamica
    int *elementos = malloc (qtdeDeElementos * sizeof(int));
    int *segmentos = malloc (qtdeSegmentos * sizeof(int));
    int **resultado;
    resultado = malloc ( 2 * sizeof (int*));
    for (k = 0;k< 2;k++){
        resultado[k] = malloc ( qtdeDeColunas * sizeof (int));
        }
    char c;
    char entrada[2000];
    char numero[2000];
    char nomeDoArquivo [1000];
    bool condicao = false;
    //abertura do arquivo
    printf("Digite o nome do arquivo: ");
	scanf("%s",nomeDoArquivo);
    FILE *arquivo;
        arquivo = fopen(nomeDoArquivo,"r");
        if(!arquivo){
            printf("Erro na abertura do arquivo.\n");
            return 0;
        }
    //leitura do arquivo
    c = fgetc(arquivo);
    while(!feof(arquivo)){
        //quantidade de elementos
        if(linha==1){
            if(c!='\n'){
                //printf("%c ", c);
                entrada[i] = c;
                i++;
            }
            else {
                qtdeDeElementos = atoi(entrada);
                linha = 2;
                i=0;
                //realocação dinamica(atualizando a qtde de elementos apos a leitura da primeira linha do arquivo)
                elementos = realloc (elementos,qtdeDeElementos*sizeof(int));
                //printf("\n ");
            }
        } 
        //valores dos n elementos
        if(linha==2 && condicao==true){
            if(c!=' ' && c!='\n'){
                numero[i] = c;
                i++;
            }
            else{
                valor = atoi(numero);
                elementos[j] = valor;
                for(controle=0;controle<i;controle++){
                    numero[controle]='\0';
                }
                i=0;
                j++;
            }
        }
        if(linha==2){
            condicao = true;
        }
        c = fgetc(arquivo);   
    }
    fclose(arquivo);
    //vetor com a copia dos valores dos elementos
    int copiaElementos[qtdeDeElementos];
    for(i=0;i<qtdeDeElementos;i++){
        copiaElementos[i]=elementos[i];  
    }
    //ordenação do vetor de elemntos
    for(i=0;i<qtdeDeElementos;i++){
        for(j=0;j<qtdeDeElementos;j++){
            if(elementos[j]>elementos[i]){
            valor = elementos[i];
            elementos[i] = elementos[j];
            elementos[j] = valor;
            }
        }
    }    
    //quantidade segmentos
    for(i=0;i<qtdeDeElementos;i++){
        for(j=0;j<qtdeDeElementos;j++){
            if(elementos[i]!=elementos[j+1]){
                qtdeSegmentos++;
                i=j+1;
            }
        }
        break;
    }
    //quantidade de colunas
    for(i=0;i<qtdeDeElementos;i++){
        for(j=0;j<qtdeDeElementos;j++){
            if(copiaElementos[i]!=copiaElementos[j+1]){
                qtdeDeColunas++;
                i=j+1;
            }
        }
        break;
    }
    //realocação dinamica(qtde de colunas atualizadas)
    for (k = 0;k< 2;k++){
        resultado[k] = realloc ( resultado[k],qtdeDeColunas * sizeof (int));
    }
    //valores dos segmentos
    //valor da quantidade de segmentos atualizadas
    segmentos = realloc (segmentos,qtdeSegmentos*sizeof(int));

    //preenche o vetor de segmentos
    for(i=0;i<qtdeSegmentos;i++){
        segmentos[i]=23556556;
    }

    //ordena os valores dos segmentos em ordem crescente
    k=0;
    for(i=0;i<qtdeDeElementos;i++){
        for(j=0;j<qtdeDeElementos;j++){
            if(elementos[i]!=elementos[j]){
                diferente=elementos[i];
                for(h=0;h<qtdeSegmentos;h++){
                    if(diferente==segmentos[h]){
                        igual++;
                    } 
                }
                if(igual==0){
                    segmentos[k] = diferente;
                    k++;
                }
                igual=0;  
            }
        }
    }
   //add na matriz a iguldade dos valores e a qual segmento pertence
    for(i=0;i<qtdeDeElementos;i++){
        for(j=0;j<qtdeDeColunas;j++){
            for(k=i;k<qtdeDeElementos;k++){
                if(copiaElementos[i]==copiaElementos[k]){
                    igual++;
                }
                if(copiaElementos[k]!=copiaElementos[k+1]){
                    for(h=0;h<qtdeSegmentos;h++){
                        if(copiaElementos[i]==segmentos[h]){
                            resultado[0][n] = h+1;
                            resultado[1][n] = igual;
                            break;
                        }
                    }
                n++;
                i = k+1;
                j = 0;
                igual = 0;
                }
            }
        } 
    }
    //imprimi o resultado
    printf("Matriz:\n");
    for(i=0;i<2;i++){
        for(j=0;j<qtdeDeColunas;j++){
            printf("%i ",resultado[i][j]);
        }
        printf("\n");
    }
    //libera a memoria
    for (i=0; i < 2; i++)
        free (resultado[i]) ;
    free (resultado) ;
    free(elementos);
    free(segmentos);
    
    return 0;
    
    
    
}