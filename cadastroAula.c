#include<stdio.h>
#define TAM 3

typedef struct{
    char nome[20];
    int idade;
    int id;
    int status;
}Pessoa;

void cadastrar(Pessoa p[], int indice){
    p[indice].status = 1;
    p[indice].id = rand() % 100; //descobrir como concertar esse erro
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(p[indice].nome, sizeof(p[indice].nome), stdin);
    fflush(stdin);
    printf("Digite a idade ");
    fflush(stdin);
    scanf("%d", &p[indice].idade);
    fflush(stdin);
    printf("\n\n ");
}
void imprimirLista(Pessoa p[], int totalCadastrados){
    for(int i = 0; i < totalCadastrados; i++){
        printf("Nome: %s", p[i].nome);
        printf("Idade: %d", p[i].idade);
        if(p[i].status == 1){
            printf("\nstatus Ativo");
        }else{
            printf("\nstatus Inativo");
        }
        printf("\n\n ");
    }

}
void buscar(Pessoa p[], int totalCadastros, int id){
    if(totalCadastros = 0){
        printf("lista vazia");
        return;
    }else
    {
        for (int i = 0; i < totalCadastros; i++)
        {
            if (p[i].id == id)
            {
                printf("Nome: %s", p[i].nome);
                printf("Idade: %d", p[i].idade);
                return;
            }
            
        }
        
    }
    printf("nao existe o registro da lista");
}

    void alterar(Pessoa p[], int totalCadastros, int id){
    int escolha;
    if(totalCadastros = 0){
        printf("lista vazia");
        return;
    }else
    {
        for (int i = 0; i < totalCadastros; i++)
        {
            if (p[i].id == id)
            {
                //achei na lista
                printf(" 1 - alterar nome, 2 - alterar idade, 3 - alterar status, 4 - alterar tudo");
                scanf("%d", &escolha);
                switch (escolha)
                {
                case 1:
                    printf("\nalterar nome");
                    fgets(p[i].nome , sizeof(p[i].nome), stdin);
                    break;
                case 2:
                    printf("\nalterar idade");
                    scanf("%d", &p[i].idade);
                    break;
                case 3:
                    printf("\nalterar status 1 - ativo / 0 - inativo:");
                    scanf("%d", &p[i].status);
                    break;
                case 4:
                    printf("\nalterar nome:");
                    fflush(stdin);
                    fgets(p[i].nome , sizeof(p[i].nome), stdin);
                    fflush(stdin);
                    printf("\nalterar idade");
                    scanf("%d", &p[i].idade);
                    fflush(stdin);
                    printf("\nalterar status 1 - ativo / 0 - inativo:");
                    scanf("%d", &p[i].status);
                    fflush(stdin);
                }
                return;
            }
            
        }
        
    }
    printf("nao existe o registro da lista");
     
    }
    void excluir(Pessoa p[], int totalCadastros, int id){
        if(totalCadastros = 0){
        printf("lista vazia");
        return;
            }else
            {
                for (int i = 0; i < totalCadastros; i++)
                {
                    if (p[i].id == id)
                    {
                    //percorrer as posicoes subsequentes para reposicionar
                        for (int j = 0; j < totalCadastros; j++)
                        {
                                p[j] = p[j +1];
                        }
                        printf("excluido com sucesso");
                        return;
                    }
                }
        }
    }  

main(){

    Pessoa p[TAM];
    int opcao, totalCadastros = 0, idBusca;

    do{
        printf("\n\nDigite 1 para cadastrar");
        printf("\nDigite 2 para mostrar os cadastros");
        printf("\nDigite 3 para buscar um registro");
        printf("\nDigite 4 para alterar os cadastros");
        printf("\nDigite 5 para excluir cadastros");
        printf("\nDigite 0 para sair\n\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                if(totalCadastros < TAM){
                    cadastrar(p, totalCadastros);
                    totalCadastros++;
                }else{
                    printf("\n\nTotal de cadastros atingido");
                }
                break;
            case 2:
                if(totalCadastros == 0){
                    printf("\n\nNão existem pessoas na lista");
                }else{
                    imprimirLista(p, totalCadastros);
                }
                break;
            case 3:
                printf("digite o id para buscar");
                scanf("%d", &idBusca);
                buscar(p, totalCadastros, idBusca);
                break; 
            case 4:  
                printf("digite o id para alteracao");
                scanf("%d", &idBusca); 
                alterar(p, totalCadastros, idBusca);
                break;
                default:
                printf("Voce digitou 0 o sistema sera encerrado");
                break;
            case 5:
                printf("digite o id para exclusao");
                scanf("%d", &idBusca);
                excluir(p, totalCadastros, idBusca);
                totalCadastros--;
                break;
                printf("Voce digitou 0 o sistema sera encerrado");
        }

    }while(opcao != 0);
    
}