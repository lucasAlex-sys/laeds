#include <stdio.h>
#include <stdlib.h>
int fatorial(int num,int *ptrVetor){
    int tamanhoVetor=0;
    int carryIn=0;
    int resultado=0;
    ptrVetor[0]=1;
    for(int i = 2;i<=num;i++){
        for(int k = 0;k<=tamanhoVetor;k++){
            resultado=ptrVetor[k]*i+carryIn;
                if(resultado>=10){
                    carryIn=resultado/10;
                    ptrVetor[k]=resultado%10;
                        if(k+1>tamanhoVetor)
                            tamanhoVetor++;   
                }
                if(resultado<10){
                    carryIn=resultado/10;
                    ptrVetor[k]=resultado%10;
        } 
    }     
}    
    return tamanhoVetor;

}
int main(){

    int numero;
    int* vetorDeNumeros = (int *) malloc (36000 * sizeof(int));
        printf("Digite um numero inteiro: ");
        scanf("%d",&numero);
        int tamanho = fatorial(numero,vetorDeNumeros);
            printf("Resultado: ");
            for(int i = tamanho;i>=0;i--){
                printf("%i",vetorDeNumeros[i] );
            }    
}