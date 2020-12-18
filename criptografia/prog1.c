#include<stdio.h>
#include<string.h>
void trocaAlfabeto(char *frase1,int tamanhoDoVetor){

    for(int i = 0;i<tamanhoDoVetor;i++){
        switch (frase1[i])
        {
        case 'd': frase1[i]='a';
            break;      
        case 'D': frase1[i]='A';
            break;
        case 'e': frase1[i]='b';
            break;      
        case 'E': frase1[i]='B';
            break;
        case 'f': frase1[i]='c';
            break;      
        case 'F': frase1[i]='C';
            break;
        case 'g': frase1[i]='d';
            break;      
        case 'G': frase1[i]='D';
            break;
        case 'h': frase1[i]='e';
            break;      
        case 'H': frase1[i]='E';
            break;
        case 'i': frase1[i]='f';
            break;      
        case 'I': frase1[i]='F';
            break;
        case 'j': frase1[i]='g';
            break;      
        case 'J': frase1[i]='G';
            break;
        case 'k': frase1[i]='h';
            break;      
        case 'K': frase1[i]='H';
            break;
        case 'l': frase1[i]='i';
            break;      
        case 'L': frase1[i]='I';
            break;
        case 'm': frase1[i]='j';
            break;      
        case 'M': frase1[i]='J';
            break;
        case 'n': frase1[i]='k';
            break;      
        case 'N': frase1[i]='K';
            break;
        case 'o': frase1[i]='l';
            break;      
        case 'O': frase1[i]='L';
            break;                    
        case 'p': frase1[i]='m';
            break;      
        case 'P': frase1[i]='M';
            break;
        case 'q': frase1[i]='n';
            break;      
        case 'Q': frase1[i]='N';
            break;
        case 'r': frase1[i]='o';
            break;      
        case 'R': frase1[i]='O';
            break;
        case 's': frase1[i]='p';
            break;      
        case 'S': frase1[i]='P';
            break;
        case 't': frase1[i]='q';
            break;      
        case 'T': frase1[i]='Q';
            break;
        case 'u': frase1[i]='r';
            break;      
        case 'U': frase1[i]='R';
            break;
        case 'v': frase1[i]='s';
            break;      
        case 'V': frase1[i]='S';
            break;
        case 'w': frase1[i]='t';
            break;      
        case 'W': frase1[i]='T';
            break;                    
        case 'x': frase1[i]='u';
            break;      
        case 'X': frase1[i]='U';
            break;
        case 'y': frase1[i]='v';
            break;      
        case 'Y': frase1[i]='V';
            break;
        case 'z': frase1[i]='w';
            break;      
        case 'Z': frase1[i]='W';
            break;
        case 'a': frase1[i]='x';
            break;      
        case 'A': frase1[i]='X';
            break;
        case 'b': frase1[i]='y';
            break;      
        case 'B': frase1[i]='Y';
            break;
        case 'c': frase1[i]='z';
            break;      
        case 'C': frase1[i]='Z';
            break;
            
        default:
            break;
        }

    }

}
void colocaEsp(char *frase1,int tamanhoDoVetor){
    for(int i = 0;i<tamanhoDoVetor;i++){
        if(frase1[i]=='#')
            frase1[i]=' ';
        if((frase1[i]=='\n') ||(frase1[i]=='\0'))
            break;
    }

}
void trocaPosicao(char *frase1,int tamanhoDoVetor){
    int contador=0;
    char aux1,aux2;
    for(int i  = 0;i<tamanhoDoVetor;i++){
            contador++; 
            if(contador==2){
                aux1=frase1[i-1];
                aux2=frase1[i];
                frase1[i]=aux1;
                frase1[i-1]=aux2;
                contador=0;
            }
            
    }


}
void tiraTraco(char *frase1,int tamanhoDoVetor){
		char aux2;
		for(int i = 0;i<tamanhoDoVetor;i++){
				if(frase1[i]=='-'){
					for(int j = i;j<tamanhoDoVetor;j++){
						aux2=frase1[j+1];
						frase1[j]=aux2;
					}
				}
                if(frase1[i]=='\0'){
                    break;
                }		
		}
        


}
void arrastar(int posicao,char *frase1,int tamanhoDoVetor){
		char aux;
		char aux2;
		for(int i = 0;i<tamanhoDoVetor;i++){
				if(i==posicao){
					aux = frase1[posicao];
					frase1[posicao]='-';	
					for(int j = posicao;j<tamanhoDoVetor;j++){
						aux2=frase1[j+1];
						frase1[j+1]=aux;
						aux=aux2;
					}
				}		
		}

}
void troca(char *frase1,int tamanho){
	char posicao1,posicao2,posicao3,posicao4;
	int par=0;
	int aux=tamanho;
    int autoriza=1;	
		for(int i = 0;i<tamanho/2;i++){
            aux--;
            if(par==2){
                autoriza++;
                
            }
            if(par==2 && autoriza==2){
				posicao1=frase1[i-2];
				posicao2=frase1[i-1];
				posicao3=frase1[aux+2];
				posicao4=frase1[aux+1];
				frase1[i-1]=posicao3;
				frase1[i-2]=posicao4;
				frase1[aux+1]=posicao1;
				frase1[aux+2]=posicao2;
				par=-1;
                autoriza=0;

			}
            if(par>2){
                par=0;
            }
			if(i==aux){
				break;
			}
			par++;
			
		}

}


int main(){

	FILE *arq;
	char c;
	int quantidadeDeCaracteres=0,i=0,contador=0;
	char frase[1000];
    char nomeDoArquivo[100];
				
	printf("Digite o nome do arquivo: ");
	scanf("%s",nomeDoArquivo);
		arq = fopen(nomeDoArquivo,"r");
			if(!arq) {
 			printf("Erro na abertura do arquivo.\n");
 			return 0;
 			}
 				c = fgetc(arq);
 			
 			while(!feof(arq)){
 				frase[i] = c;
 				if((c>64 && c<91) || (c>96 && c<123) || (c='#') ){
 					quantidadeDeCaracteres++;
 					frase[quantidadeDeCaracteres+1]='\0';
 				}	
						c = fgetc(arq);
						i++;
			}
			i=0;
			fclose(arq);	
			int qtdeDeTracos = (((quantidadeDeCaracteres-1)/2)-1);
			int tamanhoReal = 0;
			quantidadeDeCaracteres=quantidadeDeCaracteres+qtdeDeTracos;
            printf("\n--------------------\n");
            printf("Mensagem codificada:");
            printf("\n--------------------\n");
            printf("%s",frase);	
            printf("\n----------------------\n");
            printf("Mensagem decodificada:");	
            printf("\n----------------------\n");
			for(int i = 0;i<quantidadeDeCaracteres;i++){	
					if(contador==2 && frase[i]!='\n'){
						arrastar(i,frase,quantidadeDeCaracteres);
						i++;
						contador=0;	
						tamanhoReal++;
					}
					if(frase[i]=='\n'){
                        frase[i]='\0';
						break;
					}
					tamanhoReal++;
					contador++;
			}
			troca(frase,tamanhoReal);
			tiraTraco(frase,tamanhoReal);
            frase[quantidadeDeCaracteres]='\0';
			trocaPosicao(frase,quantidadeDeCaracteres);
            trocaAlfabeto(frase,quantidadeDeCaracteres);
            colocaEsp(frase,quantidadeDeCaracteres);
            printf("%s\n",frase);        

	return 0;
}
//se minha quantidade de caraceteres for par
	//entao eu tenho os espaços preenchidos por #
	//se nao 
		// nao tenho
//quinto passo
//		verificar a quantidade de caracteres
		//colocando a frase me um vetor de tamanho indetermindo
		//se impar
			// colocar # nos espaços
		//se nao 
			// nao fazer nada com os espaços
//////////////////////////////////////////////
//quarto passo
		//substituri cada letra pelo codigo de cesar
		//mantendo o #
//terceiro passo
		// a cada duas letras colocar um traço (-)
//segundo passo
		//inverter a posicao de cada boclo
			//guarda a primneira posicao
			//guarda a segunda posicao
			//se traço
			//troca as posicçoes guarda e zera as variaveis auxiliares
//primeiro passo
		//permuta  os blocos 
		//  	ex primeiro com  ultimo	