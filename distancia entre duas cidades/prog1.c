#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//#include<math.h>
#include<string.h>
//#include<conio.h>
#define INFINITY 9999
#define MAX 5

int main(){
	

FILE *mapa;
char nomeDoArquivo [1000];
char c;
char valor[10];
int nun=0;
char entrada[10];
int tamanho=0,i=0,k=0,j=0;
	printf("Digite o nome do arquivo de entrada: ");
	scanf("%s",nomeDoArquivo);
	mapa = fopen(nomeDoArquivo,"r");	
	//primeira leitura do arquivo para pegar a entrada
	if(!mapa) {
 			printf("Erro na abertura do arquivo.\n");
 			return 0;
 			}
	c=fgetc(mapa);
	entrada[i]=c;
	while(!feof(mapa)){
		i++;		
		c=fgetc(mapa);
		if(tamanho==0){
		entrada[i]=c;
		}		
		if(c=='\n'){
			tamanho++;
					
		}
		i++;		
	}
	fclose(mapa);
	//converto a entrada em inteiro
	nun=atoi(entrada);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//printf("%i",nun);

	
	//variaveis auxiliares
	int h = 0;
	int l=0;
	int esp=0;
	int numero[nun];
	int b=0;
	char cidade[nun][25];	
	tamanho=0;
	i=0;
	j=0;
	k=0;
	char estrada1[25][25];
	char estrada2[25][25];
	char bo;
///////////////////////////////////////////////////////////////////////////////////////////////////////
	//leio os arquivos novamente e separo as rotas e os valores
	//em vetores deixando suas posiçoes em paralelo
	mapa = fopen(nomeDoArquivo,"r");
		if(!mapa) {
 			printf("Erro na abertura do arquivo.\n");
 			return 0;
 			}		
	while(!feof(mapa)){
			bo=fgetc(mapa);
			if(tamanho>=1){
				if(esp==0 && bo!=' ' && bo!='\n' ){
					estrada1[j][k]=bo;
					k++;

				}
				if(esp==1 && bo!=' ' && bo!='\n'){
					estrada2[j][l]=bo;
					estrada2[j][l+1]='\0';
					l++;
					
				}
				if(esp==2 && bo!=' ' && bo!='\n'){
					valor[h]=bo;
					h++;
				}
				if(bo=='\n'){
					
					j++;
					k=0;
					l=0;
					h=0;
					numero[b]=atoi(valor);
					b++;
					int y = 0;
					for(y = 0;y<10;y++){
					valor[y]='\0';
					}
					esp=0;
				}			

			}
			if(bo=='\n'){
			   tamanho++;
			}
			if(bo==' '){
				if(esp==0){
					estrada1[j][k]='\0';
				}
				if(esp==1){
					estrada2[j][l]='\0';
				}
			   esp++;
		       }
		}	
		
		fclose(mapa);
///////////////////////////////////////////////////////////////////////////////////////////////////
		//com base do tamanho do texto que pego na segunda leitura do arquivo
		//pego a rota de destino e de origem		
		char rota1[22];
		char rota2[22];		
		strcpy(rota1,estrada1[nun]);
		strcpy(rota2,estrada2[nun]);
		estrada1[nun][0]='\0';
		estrada2[nun][0]='\0';
/////////////////////////////////////////////////////////////////////////////////////////////////////
		//verifico quantas cidades diferentes a nas minhas rotas
		//e adiciono em vetor		
		j=0;
		k=0;
		int cidadeDiferente=0;
		int igual=0;
		int igual2=0;
		for(j = 0;j<nun;j++){
			for(k=0;k<nun;k++){
				if(strcmp(estrada1[j],cidade[k])==0){
					igual++;
				//	printf("estrada1 = %s           cidade = %s",estrada1[j],cidade[k]);
					//printf("%i\n",igual);

				}
			
			}
			if(igual==0){
				strcpy(cidade[cidadeDiferente],estrada1[j]);
				//printf("estrada1 = %s%i           cidade = %s\n",estrada1[j],j,cidade[k]);
				cidadeDiferente++;	
				igual=0;
				
			}
			else{
				igual=0;
				
			}

		}
		for(j = 0;j<nun;j++){
			for(k=0;k<nun;k++){
				if(strcmp(estrada2[j],cidade[k])==0){
					igual2++;
				}

			}
			if(igual2==0){
				strcpy(cidade[cidadeDiferente],estrada2[j]);
				//printf("estrada1 = %s%i           cidade = %s\n",estrada1[j],j,cidade[k]);
				cidadeDiferente++;	
				igual2=0;
			}
			else{
				igual2=0;
			}

		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//com base nas minhas informaçoes coletadas acima
		//crio a matriz adjacente de distancias entre as rotas	
		//chamada peso,poois coloco os valores de cada rota	
		int peso[cidadeDiferente][cidadeDiferente];
		int u=0;
		int t=0;
		for(u=0;u<cidadeDiferente;u++){
			for(t=0;t<cidadeDiferente;t++){
				peso[u][t]=0;
		}

		}
		for(i=0;i<cidadeDiferente;i++){
			for(j=0;j<nun;j++){
				if(strcmp(cidade[i],estrada1[j])==0){
					for(k=0;k<cidadeDiferente;k++){
						if(strcmp(estrada2[j],cidade[k])==0){
							peso[i][k]=numero[j];
							peso[k][i]=numero[j];    	
					
							
						}
										
					}

					
					
				}
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//verifico em qual posicao esta minha rota de origem
	//e de destino com base no meu vetor de cidades diferentes[chamado cidade]	
	int n=cidadeDiferente;;
	int startnode=0;		
	int rotaFinal=0;							
	for(i = 0;i<cidadeDiferente;i++){
		if(strcmp(cidade[i],rota1)==0){
		startnode=i;		
		}
		if(strcmp(cidade[i],rota2)==0){
		rotaFinal=i;		
		}
	}	
		j=0;
		i =0;
////////////////////////////////////////////////////////////////////////////////////////////////////////
	//daqui pra baixo utilizo o algoritimo de dijkstra	
	int cost[10][10],distance[10],pred[10];
	int visited[10],count,mindistance,nextnode;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(peso[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=peso[i][j];
	
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
			//check if a better path exists through nextnode			
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 	int melhor=0;
	int melhorPo=0;
	int printar[nun];
		
	
	k=0;
	int aux4=0;
	//print the path and distance of each node
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//para printar corretamento comparo minha rota final com o indice i
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
		if(rotaFinal==i){
			//printf("\nDistance of node%d=%d",i,distance[i]);
			//printf("\nPath=%d",i);
			 melhor=distance[i];
			 melhorPo=i;	
			j=i;
			do
			{
				j=pred[j];
				printar[k]=j;
				k++;
				aux4=k;
				//printf("<-%d",j);
			}while(j!=startnode);
			k=0;
		}
	}

	printf("Menor percurso: ");
		for(k=0;k<aux4;k++){
			printf("%s ",cidade[printar[aux4-k-1]]);
		}	
	printf("%s",cidade[melhorPo]);
	printf("\nDistancia total: %i Km\n",melhor);
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
