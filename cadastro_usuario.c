// Implemente um algoritmo que:

// Inclua até 1000 usuários;
// Edite um usuário;
// Exclua um usuário;
// Busque um usuário pelo e-mail;
// Imprima todos os usuários cadastrados;

// Obrigatório uso de struct, vetor e função.

// Obrigatório uso de switch case com char para escolha da opção desejada.

// ATENÇÃO: (1) NA CRIAÇÃO DE NOMES DE IDENTIFICADORES; (2) NOS TEXTOS DE INTERAÇÃO COM USUÁRIOS – ENTRADA E SAÍDA; (3) NA ORGANIZAÇÃO DO CÓDIGO.

// Dados do usuário:

// Id (int) => preenchido automaticamente por números randômicos e não podem ser repetir.
// Nome completo (string)
// Email (string) => validação do campo: verificar se o caractere "@" aparece
// Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Indiferente.
// Endereço (string)
// Altura (double) => validação do campo: aceitar valores entre 1 e 2 m.
// Vacina (int) => validação de 1 para sim e 0 para não
// Individual

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Indiferente.
// definir um tipo para sexo
typedef enum
{
    MASCULINO,
    FEMININO,
    INDIFERENTE
} Sexo;

typedef struct
{
    int id;
    char nome[50];
    char email[100];
    Sexo sexo[3];
    char endereco[100];
    double altura;
    int vacina;

} Usuario;
// iriei utilizar funções para fazer modificações nos usuarios;
// Edite um usuário;
void editar(Usuario usuarios[], int totalCadastro, int id);
// Exclua um usuário;
void excluir(Usuario usuarios[], int quantidade);
// cadastrar usuarios;
int cadastro(Usuario usuarios[], int quantidade);
// Imprima todos os usuários cadastrados
void imprimir(Usuario usuarios[], int totalCadastros);
// classificar sexo
Sexo validar();
// função para buscar usuario pelo email
void buscarEmail(Usuario usuarios[], int totalCadastros);

int cadastro(Usuario usuarios[], int quantidade)
{
    srand((unsigned)time(NULL));

    usuarios[quantidade].id = rand() % 100;
    printf("Informe seu nome: ");
    scanf("%c", usuarios[quantidade].nome);

    printf("Informe seu genero (M, F ou I): ");
    scanf("%s", usuarios[quantidade].sexo);

    printf("Informe sua altura: ");
    scanf("%lf", usuarios[quantidade].altura);

    printf("Informe se tem vacina (1 para sim ou 0 para não): ");
    scanf("%d", usuarios[quantidade].vacina);

    printf("Informe seu email: ");
    scanf("%c", usuarios[quantidade].email);

    printf("Informe seu endereço: ");
    scanf("%c", usuarios[quantidade].endereco);
    printf("\n\n");

    return quantidade + 1; // retorna uma nova quantidade de usuarios
}
void imprimir(Usuario usuarios[], int totalCadastros)
{
    for (int i = 0; i < totalCadastros; i++)
    {
        printf("Nome: %c\n", usuarios[i].nome);
        printf("Altura: %lf\n", usuarios[i].altura);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Vacina: %d\n", usuarios[i].vacina);
        printf("Email: %c\n", usuarios[i].email);
        printf("Endereço: %c\n", usuarios[i].endereco);
        printf("\n\n");
    }
}
void editar(Usuario usuarios[], int totalCadastros, int id)
{
    int escolha;
    if (totalCadastros == 0)
    {
        printf("Cadastro vazio");
        return;
    }
    else
    {
        for (int i = 0; i < totalCadastros; i++)
        {
            if (usuarios[i].id == id)
            {
                printf("\nEscolha\n");
                printf("1: Editar nome\n");
                printf("2: Editar altura\n");
                printf("3: Editar genero\n");
                printf("4: Editar escolha da vacina (1 para sim e 0 para não)\n");
                printf("5: Editar e-mail\n");
                printf("6: Editar endereço\n");
                scanf("%d", &escolha);

                switch (escolha)
                {
                case 1:
                    printf("Editar nome: ");
                    scanf("%c", usuarios[i].nome);
                    break;
                case 2:
                    printf("Editar altura: ");
                    scanf("%lf", &usuarios[i].altura);
                    break;
                case 3:
                    printf("Editar genero: ");
                    usuarios[i].sexo == validar();
                    break;
                case 4:
                    printf("Editar escolha de vacina: ");
                    scanf("%d", &usuarios[i].vacina);
                    break;
                case 5:
                    printf("Editar e-mail: ");
                    scanf("%c", usuarios[i].email);
                    break;
                case 6:
                    printf("Editar endereço: ");
                    scanf("%c", usuarios[i].endereco);
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
                }
                return;
            }
        }
    }
    printf("Não existe esse registro no cadastro\n");
}
// Essas alterações visam melhorar a robustez e a clareza da função.
//  Certifique-se de que o restante do seu código esteja em conformidade com essas modificações, especialmente se estiver manipulando e-mails em diferentes partes do programa.
void buscarEmail(const Usuario usuarios[], int totalCadastros, const char email[])
{
    if (totalCadastros == 0)
    {
        printf("Cadastro Vazio\n");
        return;
    }
    else
    {
        for (int i = 0; i < totalCadastros; i++)
        {
            if (strcasecmp(usuarios[i].email, email) == 0)
            {
                printf("Nome: %c\n", usuarios[i].nome);
                printf("Altura: %lf\n", usuarios[i].altura);
                printf("Sexo: %d\n", usuarios[i].sexo);
                printf("Vacina: %d\n", usuarios[i].vacina);
                printf("Email: %c\n", usuarios[i].email);
                printf("Endereço: %c\n", usuarios[i].endereco);
                printf("\n\n");
                return;
            }
        }
    }
    printf("E-mail não encontrado no cadastro\n");
}
// a função recebe um ponteiro para totalCadastros para que a atualização seja refletida fora da função. Quando chamar a função, passe o endereço da variável que armazena o total de cadastros
void excluir(Usuario usuarios[], int *totalCadastros, int id)
{
    if (*totalCadastros == 0)
    {
        printf("Cadastro Vazio\n");
    }
    else
    {
        int i;
        for (i = 0; i < *totalCadastros; i++)
        {
            if (usuarios[i].id == id)
            {
                for (int j = i; j < *totalCadastros - 1; j++)
                {
                    usuarios[j] = usuarios[j + 1];
                }
                (*totalCadastros)--; // Decrementa o total de cadastros
                printf("Excluído com sucesso\n");
                return;
            }
        }
    }
    printf("Não existe esse registro no cadastro\n");
}
Sexo validar()
{
    char opcao;
    do
    {
        printf("Informe o genero (M, F ou I): ");
        scanf(" %c", &opcao);
        if (opcao == 'M')
        {
            return MASCULINO;
        }
        else if (opcao == 'F')
        {
            return FEMININO;
        }
        else if (opcao == 'I')
        {
            return INDIFERENTE;
        }
        else
        {
            printf("Opção inválida! Tente novamente\n");
        }

    } while (1);
}

int main()
{
    // Inicializa o gerador de números aleatórios com base no tempo atual
    srand(time(NULL));

    Usuario usuarios[1000]; // Inclua até 1000 usuários
    int quantidade = 0, totalCadastros = 0, idBusca = 0;
    char opcao, email[100];

    do
    {
        printf("\nEscolha uma opção:\n");
        printf("1: Cadastrar usuário\n");
        printf("2: Imprimir cadastros dos usuários\n");
        printf("3: Editar usuário\n");
        printf("4: Excluir usuário\n");
        printf("5: Procurar usuário pelo e-mail\n");
        printf("0: Encerrar programa\n");

        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            if (totalCadastros < 1000)
            {
                quantidade = cadastro(usuarios, quantidade);
                totalCadastros++;
            }
            else
            {
                printf("\nTotal cadastros atingido\n");
            }
            break;
        case '2':
            if (totalCadastros == 0)
            {
                printf("\n\nNão existem pessoas no cadastro\n");
            }
            else
            {
                imprimir(usuarios, totalCadastros);
            }
            break;
        case '3':
            printf("Digite o id para editar: ");
            scanf("%d", &idBusca);
            editar(usuarios, totalCadastros, idBusca);
            break;
        case '4':
            printf("Digite o id para exclusão: ");
            scanf("%d", &idBusca);
            excluir(usuarios, totalCadastros, idBusca);
            totalCadastros--;
            break;
        case '5':
            printf("Digite o e-mail para buscar: ");
            scanf("%s", email);
            buscarEmail(usuarios, totalCadastros, email);
            break;
        case '0':
            printf("Encerrar\n");
            break;
        default:
            printf("Opção inválida! Tente novamente\n");
            break;
        }
    } while (opcao != '0');
}
