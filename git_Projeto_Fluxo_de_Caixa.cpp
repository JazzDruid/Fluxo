#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <locale.h>

struct produto {
    char nome[50];
    int quantidade;
    float preco, valorVendido;
} mercadoria[100]; 

struct venda{
    produto mercadoria[100];
    float valorVenda;
    int itensVendido;

}vendido[200];


struct caixa{
    float abertura, fechamento, total;
    int numeroVendas;
} caixa;

int totalCadastrados = 0;

void cabecalho();
void vender();
void cadastrar( );
void listar();
void buscar();
void exibirVenda(int venda);
void exibirVendas();
void fecharCaixa();
void abrirCaixa();
void programa();

int main(){
    abrirCaixa();
    programa();
}

void vender(){
    system("cls");
    fflush(stdin);
    printf("\tCarrinho De Vendas\n");
    char entrada;

    do{
        system("cls");
        listar( );
        printf("\n");
        fflush(stdin); 
        int quantidade, codigoProduto;
        
        printf("Informe o Código Do Produto\n");
        scanf("%d", &codigoProduto);
        strcpy(vendido[caixa.numeroVendas].mercadoria[vendido[caixa.numeroVendas].itensVendido].nome, mercadoria[codigoProduto].nome);
        fflush(stdin);
        printf("Informe a Quantidade\n");
        scanf("%d", &quantidade);

        vendido[caixa.numeroVendas].mercadoria[vendido[caixa.numeroVendas].itensVendido].preco = mercadoria[codigoProduto].preco;
        vendido[caixa.numeroVendas].mercadoria[vendido[caixa.numeroVendas].itensVendido].quantidade = quantidade;

        vendido[caixa.numeroVendas].mercadoria[vendido[caixa.numeroVendas].itensVendido ].valorVendido = 
        vendido[caixa.numeroVendas].mercadoria[vendido[caixa.numeroVendas].itensVendido].quantidade * 
        vendido[caixa.numeroVendas].mercadoria[vendido[caixa.numeroVendas].itensVendido].preco;

        vendido[caixa.numeroVendas].itensVendido++;

        fflush(stdin);
        printf("Digite (S) para adicionar outro produto...\nOu pressione qualquer tecla para continuar... ");
        scanf("%c", &entrada);
    }
    while(entrada == 's' || entrada == 'S' );

    for(int index = 0; index < vendido[caixa.numeroVendas].itensVendido ; index ++){

        vendido[caixa.numeroVendas].valorVenda = vendido[caixa.numeroVendas].valorVenda + 
        vendido[caixa.numeroVendas].mercadoria[index].valorVendido ;
    }

	exibirVenda(caixa.numeroVendas);
    caixa.numeroVendas++;
}

void programa(){
    setlocale(LC_ALL,"portuguese");
    int entrada;
    bool fechar = false;

    while(!fechar){
        fflush(stdin);
        system("cls");
        
        cabecalho();

        
        printf("\n[1] >>> Cadastrar produtos:\n");
        printf("[2] >>> Listar produtos cadastrados:\n");
        printf("[3] >>> Buscar produtos:\n");
        printf("[4] >>> Vender produtos:\n");
        printf("[5] >>> Fechar caixa:\n");
        
        printf("Digite o número da operação desejada: ");


        scanf("%d", &entrada);
        switch(entrada){
            case 1:

                system("cls");
                cadastrar();
                break;
            case 2:
                system("cls");
                cabecalho();
                listar( );
                system("pause");
                break;
            case 3:
                system("cls");
                cabecalho();
                buscar( );
                break;
            case 4:
                vender();
                cabecalho();
                system("pause");
                break;
            case 5:
            	fechar = true;
                break;
            default:
                system("cls");
                printf("ERRO!!! - Operação inválida");
                system("pause");
                break;
        }

        if(fechar == true){
            fecharCaixa();  
        }
        

    }

}

void cadastrar(){

    char entrada;
    bool controle;
    bool confirmado = false;

    fflush(stdin);
    system("cls");
    cabecalho();
    printf("\nInsira o [NOME] do produto para ser cadastrado: \n");
    gets(mercadoria[totalCadastrados].nome);
    system("cls");
    //
    fflush(stdin);
    cabecalho();
    printf("\nNome escolhido do produto: %s\n", mercadoria[totalCadastrados].nome);
    printf("Insira valor unitário (preço): ");
    scanf("%f", &mercadoria[totalCadastrados].preco);
    system("cls");
    //
    cabecalho();
    printf("\nNome escolhido para o produto: %s\n", mercadoria[totalCadastrados].nome);
    printf("Preço unitário definido para o produto: R$ %g\n", mercadoria[totalCadastrados].preco);
    fflush(stdin);
    totalCadastrados++;
    printf("Deseja cadastrar outro produto? (S) para 'SIM' e (N) para 'Nï¿½O':");
    scanf("%c", &entrada);
    fflush(stdin);
    
    if (entrada == 's' || entrada == 'S'){
        cadastrar();
    }else if (entrada == 'n' || entrada == 'N'){
        system("pause");
    }
  
     
}

void listar(){
    printf("Lista De Produtos Cadastrados\n");
    for(int index = 0 ; index < totalCadastrados; index++){
        printf("Código -> [%d] %s Preco Por Unidade - R$ %g\n", index, mercadoria[index].nome, mercadoria[index].preco);
    }
   
}

void buscar(){
    bool naoEncontrou = true;
    char entradaProduto[50], repetirBusca;
    printf("Buscar Produtos (UTILIZANDO O NOME): ");
    scanf("%s", &entradaProduto);

    for(int index = 0 ; index < totalCadastrados; index++){

        if(strcmp(entradaProduto, mercadoria[index].nome) == 0 ){
            printf("Produto encontrado\n");
            printf("Codigo [%d] - %s / Preço R$ %g\n", index, mercadoria[index].nome, mercadoria[index].preco);
            naoEncontrou = false;
        }

    } 

    if (naoEncontrou == true)
    {
        printf("\nNenhum produto encontrado!");
    }
    

    fflush(stdin);
    printf("\nDeseja buscar outro produto? (S) para 'SIM' e (N) para 'NÃO':");
    scanf("%c", &repetirBusca);
    
    if (repetirBusca == 's' || repetirBusca == 'S'){
        buscar();
    }else if (repetirBusca == 'n' || repetirBusca == 'N'){
        system("pause");
    }
}

void exibirVenda(int venda){	
    for(int index = 0; index < vendido[venda].itensVendido ; index++){
    	fflush(stdin);
        printf("Item Vendido %s    ", vendido[venda].mercadoria[index].nome);
        printf("Valor Unidade R$ %g ", vendido[venda].mercadoria[index].preco);
        printf("Unidades Vendidas %d\n", vendido[venda].mercadoria[index].quantidade);
    }

    printf("Valor Vendido R$ %g\n\n", vendido[venda].valorVenda);
}
void exibirVendas(){
    fflush(stdin);
    for(int index = 0; index < caixa.numeroVendas; index++){
        exibirVenda(index);
    }
    
}

void abrirCaixa(){
    fflush(stdin);
    cabecalho();
    printf("\nInforme O Valor Inicial para abrir o caixa: ");
    scanf("%f", &caixa.abertura);
}




void fecharCaixa(){
    fflush(stdin);
    int total;
    caixa.total = caixa.fechamento - caixa.abertura;

    

    for(int venda = 0; venda < caixa.numeroVendas; venda++){
        caixa.fechamento = caixa.fechamento + vendido[venda].valorVenda;
        printf("valor venda R$ %g\n", vendido[venda].valorVenda);
    }

    printf("CAIXA total- R$ %g \n CAIXA Abertura- R$ %g", caixa.total, caixa.abertura);


    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");


}

void cabecalho(){
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("|\t     CAIXA DREAMTEAMSOLUTIONS             |\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}
