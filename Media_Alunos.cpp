#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

/* 	PROGRAMA ARMAZENA NOTAS DOS ALUNOS E CALCULA A MEDIA INDIVIDUALMENTE.
	
	1 - INSERIR 
	2 - LISTAR 
	3- PESQUISAR
	4- SAIR
*/

void titulo();
void inserir();
void listar();
void media();
void csv();

typedef struct aluno{
	
	char	name[20];
	float 	grade[4];
		
}ALUNO;

main(){
	setlocale(LC_ALL,"Portuguese");
inicio:	
	fflush(stdin);
    titulo();
	
	int opcao;	
	printf("\n (1) - INSERIR:\n\n");
	printf(" (2) - LISTAR:\n\n");
	printf(" (3) - MEDIA:\n\n");
	printf(" (4) - Gerar CSV:\n\n");
	printf(" (5) - SAIR:");
	printf("\n\n Digite a opção desejada: ");
	scanf("%d",&opcao);
	getchar();
	
	do{
		switch(opcao){
			
			case 1:
				fflush(stdin);
				inserir();	
				goto inicio;			
				break;
				
			case 2:
				
				listar();
				goto inicio;
				break;	
				
			case 3:
				titulo();
				media();
				goto inicio;
				break;
				
			case 4:
				csv();
				printf(" \nGerado com sucesso!\n");
				getch();
				goto inicio;
				break;
					 
					
			
			case 5:
				fim:
				titulo();
				printf("\n Desenvolvido por:	Rodrigo Rabelo\n\n");
				getch();
				return 0;
				break;
				
			default:
				titulo();
				printf("\n Opção inválida\n\n");
				getch();
				goto inicio;
				break;			
				} // end switch		
		
	}while(opcao !=4);
	
} // end main

void titulo(){
	
	system("cls");
	printf("____________________________________________\n");
	printf(" CONTROLE DE NOTAS ALUNOS \n");
	printf("____________________________________________\n\n");	
	}// end titulo
	
void inserir(){
	
	FILE *arq;
	ALUNO dados;
	arq = fopen("basealunos.txt","ab");
	
		if(arq == NULL){
		printf("\n Erro na abertura\n\n");
		} // end if
		
			else{
					char op;
					do{
						int i;
						titulo();
						fflush(stdin);
						printf("\n Digite o nome: ");
						gets(dados.name);
						fflush(stdin);
						
							for(i=0;i<4;i++){
								
								printf("\n Digite a nota %d: ",i+1);
								scanf("%f",&dados.grade[i]);
								fflush(stdin);
							}
							fwrite(&dados,sizeof(ALUNO),1,arq);
							
							fflush(stdin);
						printf("\n Deseja continuar? (s/n)");
						op = getch();
						
					}while(op =='s');
					fclose(arq);
					
			} // end else

	
} // end inserir

void listar(){
	
	FILE	*arq;
	ALUNO	dados;	
	arq	=	fopen("basealunos.txt","rb");
	titulo();
		
	if(arq == NULL)	{
		
		printf(" \n Erro na abertura no arquivo");		
					} // end if
	
	else{
		
		while(fread(&dados,sizeof(ALUNO),1,arq)==1){
					
			printf("\n Nome:		%s	",dados.name);
			printf("\n Nota1:		%2.2f",dados.grade[0]);
			printf("\n Nota2:		%2.2f",dados.grade[1]);
			printf("\n Nota3:		%2.2f",dados.grade[2]);
			printf("\n Nota4:		%2.2f",dados.grade[3]);			
		    printf("\n ----------------------------------------------\n\n");
								
			} // end while			
		} // end else
	fclose(arq);
	

	getch();
	
} // end listar

void media(){
	
	FILE	*arq;
	ALUNO dados;
	char nome[20];
	arq	=	fopen("basealunos.txt","rb");
	
	if(arq == NULL){
		printf("\n Erro na abertura do arquivo! \n");
	} // end if
	else{
	  			fflush(stdin);
				printf("\n Digite o nome a pesquisar:	");
				gets(nome);
				
			while(fread(&dados,sizeof(ALUNO),1,arq)==1)
			{
					if(strcmp(nome,dados.name)==0){
					float media,total = 0;
					fflush(stdin);
					printf(" \n Nome:		%s",dados.name);
				
						for(int i =	0;	i<4;	i++){
						printf(" \n Nota 1:	%2.2f",dados.grade[i]);
						total	+=	dados.grade[i];
						media	=	total/4;
						} // end for
						fflush(stdin);
						printf("\n\n O Soma das notas do anluno: %s é: %2.2f e a média é: %2.2f",dados.name,total,media);
						printf("\n");
						media	=	0;
						total	=	0;
						
							
				}// end if
				
			} // end while		
		
	} // end else
	
	fclose(arq);
	getch();	
	
} // end media

void csv(){
	char x[2000];
	
	FILE	*arq;
	ALUNO	dados;	
	arq	=	fopen("basealunos.txt","rb");
	
	titulo();
		
	if(arq == NULL)	{
		
		printf(" \n Erro na abertura no arquivo");		
					} // end if
					sprintf(x,"%s.csv",arq);
					FILE	*csv;	
					csv = 	fopen("file.csv","a");
					fputs("Nome - Nota 1 - Nota 2 - Nota 3 - Nota 4 \r\n",csv);
					
	fclose(arq);
	fclose(csv);	
	
}



