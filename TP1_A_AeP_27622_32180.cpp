#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


# define MAX 50
# define n_Categorias 5


//declaração de variavies globais

int id[MAX], qnt_Stock[MAX], qnt_Venda[MAX];
float preco[MAX], vendas[MAX];
char categoria[MAX], artigo[MAX];
int  contador=0, cnt=0;


//-----------------------------------------------------
void legendaCategoria(){

	printf("\n\n ____________________________________________\n");
	printf("|                Categorias:                 |\n");
	printf("|___________________________________________ |\n");
    printf("|A - Arranjos         | R - Ramos            |\n");
    printf("|J - Jarros           | C - Centro de Mesa   |\n");
    printf("|D - Decoração Evento | P - Cestas Presente  |\n");
    printf("|F - Flores Soltas    | O - Outro            |\n");
	printf("|____________________________________________|\n");
	
return;
}

//-----------------------------------------------------
void legendaArtigo(){

	printf("\n\n _________________________________________\n");
	printf("|                Artigos:                 |  \n");
	printf("|________________________________________ |\n");
    printf("|R - Rosas         | L - Lírios           | \n");
    printf("|T - Tulipas       | G - Girassóis        |\n");
    printf("|Q - Orquídeas     | C - Cravo            |\n");
    printf("|M - Margaridas    | H- Hortências        |\n");
    printf("|A - Aspidistra    | O - Outros           |\n");
	printf("|_________________________________________|\n");
	
return;
}

//-----------------------------------------------------

void inicioStock(){
	
	//PRODUTO 1
	id[contador] = 0;
	artigo[contador] = 'R'; 
  	categoria[contador] = 'R';
  	preco[contador] = 6.00;
  	qnt_Stock[contador] = 25;
  	contador++;
  	

  	//PRODUTO 2
  	id[contador] = 1;
	artigo[contador] = 'T'; 
  	categoria[contador] = 'J';
  	preco[contador] = 9.00;
  	qnt_Stock[contador] = 25;
  	contador++;
  	
  	//PRODUTO 3
  	id[contador] = 2;
	artigo[contador] = 'L'; 
  	categoria[contador] = 'P';
  	preco[contador] = 7.00;
  	qnt_Stock[contador] = 50;
  	contador++;
  	
  	//PRODUTO 4
  	id[contador] = 3;
	artigo[contador] = 'H'; 
  	categoria[contador] = 'R';
  	preco[contador] = 5.00;
  	qnt_Stock[contador] = 40;
  	contador++;
  	
  	//PRODUTO 5
  	id[contador] = 4;
	artigo[contador] = 'C'; 
  	categoria[contador] = 'A';
  	preco[contador] = 9.00;
  	qnt_Stock[contador] = 25;
  	contador++;
  	
  	//PRODUTO 6
  	id[contador] = 5;
	artigo[contador] = 'G'; 
  	categoria[contador] = 'P';
  	preco[contador] = 9.00;
  	qnt_Stock[contador] = 30;
  	contador++;
  	
  	//PRODUTO 7
  	id[contador] = 6;
	artigo[contador] = 'M';
  	categoria[contador] = 'A';
  	preco[contador] = 6.00;
  	qnt_Stock[contador] = 45;
  	contador++;
	
	
}

//-----------------------------------------------------



void adicionar_Artigo(){
  	
  	int codigo, qnt;
  	float precoArtigo;
  	char  cat, art;
  	
  	printf("\nInsira o código do Artigo: ");
  	fflush(stdin);
	scanf("%i", &codigo);
	for(int i=0; i<contador; i++){  
		if(codigo == id[i]){
			printf("\nCódigo ja existente insira novo codigo: ");
	  		fflush(stdin);
			scanf("%i", &codigo);		
    	}
	}
	
  	id[contador] = codigo;
   
    
  	printf("\nInsira o nome do Artigo: ");
  	legendaArtigo();
	fflush(stdin);
	printf("->");
	scanf("%c", &art);
  	artigo[contador] = art;
    
   
  	printf("\nInsira a categoria do Artigo: ");
  	legendaCategoria();
  	fflush(stdin);
  	printf("->");
    scanf("%c", &cat);
  	categoria[contador] = cat;
  	
  	 
  	printf("\nInsira o preço do Artigo: ");
  	fflush(stdin);
  	scanf("%f", &precoArtigo);
  	preco[contador] = precoArtigo;
  
  	 
  	printf("\nInsira a quantidade em Stock do Artigo: ");
  	fflush(stdin);
  	scanf("%i", &qnt);
  	qnt_Stock[contador] = qnt;
  
  	contador++;
    
  	printf("\n***Artigo Adicionado com Sucesso!\n\n");
return;
}
//------------------------------------------------------------------------------------
   void remover_Artigo(){ 
  	
  	int valor, posicao;
  	
  	printf("Qual o código do artigo que pretende apagar: ");
  	scanf("%i", &valor);
  	 fflush(stdin);
  	 
  	for (int i = 0; i < MAX; i++) {
	    if(id[i]==valor)	{
	       posicao = i;
	        id[posicao] = id[posicao + 1];
		    artigo[posicao]= artigo[posicao+1];
		  	categoria[posicao] = categoria[posicao + 1];
		    preco[posicao] = preco[posicao + 1];
		    qnt_Stock[posicao] = qnt_Stock[posicao + 1];
	    }
    }
  
	
	contador--;
  	printf("***Artigo Removido com Sucesso!\n\n");
  
return;
 }

//------------------------------------------------------------------------------------
void modificar_Artigo(){
  	
  	int  qnt, muda, posicao;
  	float precoArtigo;
  	char   valor,  continuar;
  	
  	printf("Qual o artigo que pretende modificar: ");
    legendaArtigo();
    printf("->");
	scanf("%c", &valor);
  	fflush(stdin);
  	 
  	for (int i = 0; i < MAX; i++) {
	    if(artigo[i]==valor)	{
	    	posicao = i;
	    	do{
			  printf("******************************\n");
			  printf("* 1 - Preço Artigo           *\n");
			  printf("* 2 - Quantidade Stock       *\n");
			  printf("******************************\n");
			  
		
			  	printf("\nO que pretende mudar no artigo: ");
			    fflush(stdin);
				scanf("%i", &muda);
			
			     
					switch(muda){
					   	case 1:	
						  	printf("\nInsira o preço do Artigo: ");
						  	fflush(stdin);
						  	scanf("%f", &precoArtigo);
						  	preco[posicao] = precoArtigo;
						  	break;
						  	
						case 2:	  	
						  	printf("\nInsira a quantidade em Stock do Artigo: ");
						  	fflush(stdin);
						  	scanf("%i", &qnt);
						  	qnt_Stock[posicao] = qnt;
						  	break;
						default:
							printf("Detetado numero errado");
				    }
			  
			  	
			    printf("\nPretende modificar algo mais neste artigo: ");
			    fflush(stdin);
				scanf(" %c", &continuar);
				 fflush(stdin);
				 
				}while(continuar == 's' || continuar == 'S');
			    
			printf("\n***Artigo Modificado com Sucesso!\n\n");
       }
	}

return;
}
//------------------------------------------------------------------------------------

void venda(){

char produto, continuar;
int qnt, posicao;
float precoFinal=0;

	do{
	    legendaArtigo();
		printf("Artigo: ");
		fflush(stdin);
		scanf("%c", &produto);
		
		
		for (int i = 0; i < MAX; i++) {
		    if(artigo[i]==produto){
		    	posicao = i;
		    }
	    }
		
		printf("Quantidade: ");
		fflush(stdin);
		scanf("%i", &qnt);
	    qnt_Venda[posicao] = qnt_Venda[posicao] + qnt;
		qnt_Stock[posicao] = qnt_Stock[posicao] - qnt;

		printf("\nPretende adicionar mais produtos: ");
		 fflush(stdin);
		scanf("%c", &continuar);
		vendas[cnt] = preco[posicao]*qnt;
		precoFinal = precoFinal+ (preco[posicao]*qnt);
		cnt++;
		
	}while(continuar == 's' || continuar == 'S');
		
		
	printf("*******************************\n");
	printf("*            Fatura           *\n");
	printf("*                             *\n");
	printf("* Total a Pagar: %.2f        *\n", precoFinal);
	printf("*                             *\n");
	printf("*******************************\n");
	
return;
}
//------------------------------------------------------------------------------------

void disponivel_vendas(){
		
			
	int  qnt=0;
	float totalP=0;
	char valor;
			
	printf("\nQual a categoria que pretende visualizar: ");
	legendaCategoria();
	printf("->");
    scanf("%c", &valor);
    fflush(stdin);
	  	
  	for (int i = 0; i < MAX; i++) {
        if(categoria[i]==valor)	{
			qnt= qnt+qnt_Stock[i];
			totalP = preco[i]*qnt;
		 }
	}
		   printf("\nPara a categoria %c, tem disponivel %i", valor, qnt);
		   printf("\n Um total de total de %.2f \n\n", totalP);
	
return;
}
	
//------------------------------------------------------------------------------------
void mediaArtigoVendido(){ 
	
	float soma=0, media=0;
	    if(cnt == 0){
	    	printf("Ainda nao existem vendas!\n");
		}else{
			
			for(int i=0; i<cnt; i++){
		 		soma=soma+vendas[i];
			}
			media= soma/cnt;
			printf("A média de preços dos artigos vendidos é de %.2f\n\n", media);
		}
return;
}

//------------------------------------------------------------------------------------

void consultaStock(){
				
	printf("**********************************\n");
	printf("*            Stocks              *\n");
  	printf("* Id | Artigo|Categoria|Qnt Stock*\n");
	for(int i=0; i < contador;i++){	
		printf("*  %i       %c      %c       %i     *\n", id[i], artigo[i], categoria[i], qnt_Stock[i]);
	}
	printf("**********************************\n\n");
return;
}

//------------------------------------------------------------------------------------
void informacaoArtigos(){
				
		printf("*******************************************\n");
		printf("*            Produtos:                    *\n");
		printf("* Id | Artigo|Categoria|Qnt Stock| Preço  *\n");
		
		for(int i=0; i< contador;i++){
			printf("* %i     %c       %c          %i      %.2f   *\n", id[i], artigo[i], categoria[i], qnt_Stock[i], preco[i]);
	    }  
		printf("*******************************************\n\n");
return;	
}
//------------------------------------------------------------------------------------
void informacaoCategorias(){
	
	char   valor;
		
		printf("\nQual a categoria que pretende visualizar: ");
  	    fflush(stdin);
		scanf("%c", &valor);
		
     	printf("\n*******************************************\n");
		printf("*                Produtos:                *\n");
  	   	printf("* Id | Artigo|Categoria|Qnt Stock| Preço  *\n");
		
		for(int i=0; i< contador;i++){
			 if(categoria[i]==valor)	{
				printf("* %i     %c       %c          %i      %.2f   *\n", id[i], artigo[i], categoria[i], qnt_Stock[i], preco[i]);
		    }   
		}
	    printf("*******************************************\n\n");
return;
}	
//-----------------------------------------------------------------------------------

void mediaStock(){   
	
    float media=0;
    int soma=0;
    int condicao=0;
   
		printf("\n* Artigo|Qnt Stock| Preço   *\n");
		for(int i=0; i<contador; i++){
			soma =soma + qnt_Stock[i];
	        media= soma	/ n_Categorias;
	      if(qnt_Stock[i] < media && qnt_Stock[i] != 0){
				condicao = 1;
				printf("*  %c       %i        %.2f   *\n", artigo[i], qnt_Stock[i], preco[i]);
			}
			
	    }
	     if(condicao == 0){
			printf("Todos os artigos tem um Stock igual ou Superior á media de stock\n\n");
		}
	
	
return;
}

//------------------------------------------------------------------------------------
void total_Vendas(){
	
	float soma=0;
	
	for(int i=0; i<cnt; i++){
		soma = soma + vendas[i];
	}
	printf("O total, ganho em vendas é de %.2f\n\n", soma);
return;	
}


//------------------------------------------------------------------------------------
void ArtigoMaisCaro(){

	
	float soma=0, media=0;


	    if(contador == 0){
	    	printf("\nAinda nao existem vendas!\n");
		}else{
			
			for(int i=0; i<contador; i++){
			soma=soma+preco[i];
			}
			media= soma/contador;
		}
		printf("\nArtigos com Preço acima da media:\n");
		printf("\n* Id | Artigo|Categoria|Qnt Stock| Preço*\n");
		for(int i=0; i<contador; i++){
				if(preco[i]> media){
	
		printf("* %i     %c       %c        %i        %.2f *\n", id[i], artigo[i], categoria[i], qnt_Stock[i], preco[i]);
	   
		}
	 }  
		
	
return;	
}

//------------------------------------------------------------------------------------
void desperdicios(){ //POR TERMINAR CONTAS NAO ESTAO BEM FEITAS
	
	char cat;
	int qnt=0, qntF=0;
	float precoL=0, soma=0;
	
	
	printf("Que categoria, pertende visualizar: ");
	scanf("%c", &cat);
	
	switch(cat){
		case 'R':
				for(int x=0; x<contador; x++){
					if(categoria[x]==cat){
						
						qnt = qnt + qnt_Stock[x] ;
					}	
				}
				
				qntF= qnt*0.07;  
				printf("\nEsta previsto %i Ramos ir para o lixo.", qntF);
					
				for(int i=0; i<contador; i++){
					if(categoria[i]== 'R'){
						soma=soma+preco[i];
					}  
				}
				precoL = qntF*soma;
				printf("\nNum total de %.2f euros\n\n", precoL);
			break;
			
		case 'A':
				for(int x=0; x<contador; x++){
					if(categoria[x]==cat){
						
						qnt = qnt + qnt_Stock[x] ;
					}	
				}
				
				qntF= qnt*0.03;
				
				printf("\nEsta previsto %i Arranjos ir para o lixo.", qntF);
				
				for(int i=0; i<contador; i++){
					if(categoria[i]== 'A'){
						soma=soma+preco[i];
					}  
				}
				precoL = qntF*soma;
				printf("\nNum total de %.2f euros\n\n", precoL);
			break;
			
		default:
				for(int x=0; x<contador; x++){
					if(categoria[x]==cat){
						
						qnt = qnt + qnt_Stock[x] ;
					}	
				}
				
				qntF = qnt*0.04;
			
				printf("\nEsta previsto %i ir para o lixo.", qntF);
				
				for(int i=0; i<contador; i++){
					if(categoria[i]!= 'A' && categoria[i]!= 'R'){
						soma=soma+preco[i];
					}  
				}
				precoL = qntF*soma;
				printf("\nNum total de %.2f euros\n\n", precoL);
	}
return;	
}

//------------------------------------------------------------------------------------

void subMenu(){
	int opcao;
	
	printf("\n****************************************\n");
	printf("*                Menu                  *\n");
	printf("****************************************\n");
    printf("* 1 - Produtos Disponiveis /valor      *\n");
    printf("* 2 - Média de preços/Vendas           *\n");
    printf("* 3 - Artigo preço Acima da Média      *\n");
    printf("* 4 - Total ganho em vendas            *\n");
    printf("* 5 - Previsão Desperdicio Anual       *\n");
    printf("* 6 - Sair                             *\n");
    printf("****************************************\n");
  
    printf("Qual a operação que pertende efetuar: ");
    scanf("%i", &opcao);
    fflush(stdin);
    printf("\n");
    
    if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 6){
    
    printf("Operação Invalida! \n");
    printf("Qual a operação que pertende efetuar: ");
    scanf("%i", &opcao);
    fflush(stdin);
    printf("\n");
	}
  
  switch(opcao){
    	case 1:
	    	    disponivel_vendas();
	    	   	break;
	    		
    	case 2:
	    		mediaArtigoVendido();
	    		break;
    		
    	case 3:
	    		ArtigoMaisCaro();
	    		break;
				
    		
    	case 4:
				total_Vendas();
    			break;
	    		
    	case 5:
    			desperdicios();
				break;	
    		
    	case 6:
	    		return;
	    		break;
	}
return;
}


//------------------------------------------------------------------------------------

int menu(int opcao){
	


	switch(opcao){
    	case 1:
			    adicionar_Artigo();
			     
 				break;
	    		
	    		
    	case 2:
    		   remover_Artigo();
    		  
    		   break;
    		   
    	case 3:
    		   modificar_Artigo();
    		   break;
    		
    	case 4:
    		    venda();
    		   break;
    		
    	case 5:
	    		consultaStock();
	    		break;
    	case 6:
    	    	informacaoArtigos();
			    break;
			  
    	case 7:
    			informacaoCategorias();
    			break;
    			
        case 8:
    			mediaStock();
    			break;
    		
    	case 9:
	    	    subMenu();
	    		break;
    		
    	case 10:
	    		printf("Adeus!");
				return 0;
	    		break;
	    		
    
	}	
	    	
return 0;
}

//------------------------------------------------------------------------------------
int main(){
	
setlocale(LC_ALL, "portuguese");

	int opcao=0;
	inicioStock();  //incia o stock
	
 do{ 
 
 
	printf("\n****************************************\n");
	printf("*               Bem Vindo!             *\n");
	printf("****************************************\n");
    printf("* 1 - Adicionar Artigo                 *\n");
    printf("* 2 - Eliminar Artigo                  *\n");
    printf("* 3 - Modificar Artigo                 *\n");
    printf("* 4 - Realizar Venda                   *\n");
    printf("* 5 - Consulta de Stock                *\n");
    printf("* 6 - Informações Artigos              *\n");
    printf("* 7 - Informações Artigos/Categoria    *\n");
    printf("* 8 - Média Stock                      *\n");
    printf("* 9 - Informações Vendas               *\n");
    printf("* 10 - Sair                            *\n");
    printf("****************************************\n");
     
    
  
    printf("Qual a operação que pertende efetuar: ");
    scanf("%i", &opcao);
    fflush(stdin);
    printf("\n");
    
    if(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 &&opcao != 5 && opcao != 6 && opcao != 7 && opcao != 8 && opcao != 9 && opcao != 10){
    
    printf("\nOperação Invalida! \n");
    printf("\nQual a operação que pertende efetuar: ");
    scanf("%i", &opcao);
    fflush(stdin);
    printf("\n");
	}

	menu(opcao);
    

	}while(opcao!=10);
	
    
    
    
	return 0;
}
