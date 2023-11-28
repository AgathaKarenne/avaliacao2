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
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define USUARIOS 1000

typedef struct
{
    char id[4]; // Alteração para string para evitar estouro de buffer
    char nome[50];
    char email[50];
    char sexo[3];
    char endereco[100];
    double altura;
    int vacina;
} Usuario;

int validarEmail(const char email[])
{
    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
        {
            printf("E-mail validado\n");
            return 1;
        }
    }

    printf("E-mail inválido! Tente novamente\n");
    return 0;
}

void validarSexo(char sexo[])
{
    do
    {
        printf("Informe o gênero (M, F ou I): ");
        scanf(" %2s", sexo);

        if (sexo[0] == 'M' && sexo[1] == '\0')
        {
            printf("Gênero: Masculino\n");
            return;
        }
        else if (sexo[0] == 'F' && sexo[1] == '\0')
        {
            printf("Gênero: Feminino\n");
            return;
        }
        else if (sexo[0] == 'I' && sexo[1] == '\0')
        {
            printf("Gênero: Indiferente\n");
            return;
        }
        else
        {
            printf("Opção inválida! Tente novamente\n");
        }

    } while (1);
}

void validaAltura(double *altura)
{
    if (*altura >= 1.0 && *altura <= 2.0)
    {
        printf("Altura válida: %.2lf metros\n", *altura);
    }
    else
    {
        printf("Altura inválida! Informe um valor entre 1.0 metro e 2.0 metros.\n");
    }
}

void validaVacina(int vacina)
{
    if (vacina == 1)
    {
        printf("Tomou a vacina.\n");
    }
    else if (vacina == 0)
    {
        printf("Não tomou a vacina.\n");
    }
    else
    {
        printf("Opção inválida! Tente novamente.\n");
    }
}

void cadastrar(Usuario usuarios[], int *totalCadastrados)
{
    srand((unsigned int)time(NULL));

    snprintf(usuarios[*totalCadastrados].id, sizeof(usuarios[*totalCadastrados].id), "%d", rand() % 1000 + 1);

    printf("\nCadastro de Usuários\n");

    printf("Informe o nome:");
    fgets(usuarios[*totalCadastrados].nome, sizeof(usuarios[*totalCadastrados].nome), stdin);
    usuarios[*totalCadastrados].nome[strcspn(usuarios[*totalCadastrados].nome, "\n")] = '\0';

    while (!validarEmail(usuarios[*totalCadastrados].email))
    {
        printf("Informe o e-mail:");
        fgets(usuarios[*totalCadastrados].email, sizeof(usuarios[*totalCadastrados].email), stdin);
        usuarios[*totalCadastrados].email[strcspn(usuarios[*totalCadastrados].email, "\n")] = '\0';
    }

    validarSexo(usuarios[*totalCadastrados].sexo);

    printf("Informe o endereço:");
    fgets(usuarios[*totalCadastrados].endereco, sizeof(usuarios[*totalCadastrados].endereco), stdin);
    usuarios[*totalCadastrados].endereco[strcspn(usuarios[*totalCadastrados].endereco, "\n")] = '\0';

    printf("Informe a altura: ");
    scanf("%lf", &usuarios[*totalCadastrados].altura);
    validaAltura(&usuarios[*totalCadastrados].altura);

    printf("Informe se tomou a vacina (1 para sim, 0 para não): ");
    scanf("%d", &usuarios[*totalCadastrados].vacina);
    validaVacina(usuarios[*totalCadastrados].vacina);

    (*totalCadastrados)++;
}

void imprimir(Usuario usuarios[], int totalCadastrados)
{
    if (totalCadastrados == 0)
    {
        printf("Cadastro de usuários vazio\n");
        return;
    }

    printf("\nLista de Usuarios\n");
    for (int i = 0; i < totalCadastrados; i++)
    {
        printf("ID: %s\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf metros\n", usuarios[i].altura);
        printf("Vacina: ");
        validaVacina(usuarios[i].vacina);
        printf("\n");
    }
}

void buscarEmail(Usuario usuarios[], int totalCadastros, const char email[])
{
    if (totalCadastros == 0)
    {
        printf("Cadastro de usuarios vazio\n");
        return;
    }

    int encontrado = 0;

    for (int i = 0; i < totalCadastros; i++)
    {
        int j;
        for (j = 0; usuarios[i].email[j] != '\0' && email[j] != '\0'; j++)
        {
            if (usuarios[i].email[j] != email[j])
            {
                break;
            }
        }

        if (usuarios[i].email[j] == '\0' && email[j] == '\0')
        {
            printf("Usuario Encontrado:\n");
            printf("ID: %s\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf metros\n", usuarios[i].altura);
            printf("Vacina: ");
            validaVacina(usuarios[i].vacina);
            printf("\n");

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Usuário com o e-mail %s não encontrado.\n", email);
    }
}

void editar(Usuario usuarios[], int totalCadastrados, const char id[])
{
    printf("Editando usuário ID %s\n", id);

    for (int i = 0; i < totalCadastrados; i++)
    {
        if (strcmp(usuarios[i].id, id) == 0)
        {
            int opcao;

            do
            {
                printf("\nEscolha a opção que deseja editar\n");
                printf("1: Nome\n");
                printf("2: E-mail\n");
                printf("3: Sexo\n");
                printf("4: Endereço\n");
                printf("5: Altura\n");
                printf("6: Vacina\n");
                printf("7: Alterar cadastro inteiro\n");
                printf("0: Sair\n");
                printf("Opção:");
                scanf("%d", &opcao);

                switch (opcao)
                {
                case 1:
                    printf("Informe o novo nome:");
                    getchar(); // Limpar o buffer do teclado antes de fgets
                    fgets(usuarios[i].nome, sizeof(usuarios[i].nome), stdin);
                    usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0';
                    break;
                case 2:
                    printf("Informe o novo e-mail (ou '0' para sair): ");
                    getchar();
                    fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
                    usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
                    if (strcmp(usuarios[i].email, "0") == 0)
                    {
                        break; // Sair da edição de e-mail
                    }
                    while (!validarEmail(usuarios[i].email))
                    {
                        printf("Informe o novo e-mail (ou '0' para sair): ");
                        fgets(usuarios[i].email, sizeof(usuarios[i].email), stdin);
                        usuarios[i].email[strcspn(usuarios[i].email, "\n")] = '\0';
                        if (strcmp(usuarios[i].email, "0") == 0)
                        {
                            break; // Sair da edição de e-mail
                        }
                    }
                    break;
                case 3:
                    printf("Informe o novo sexo (M/F): ");
                    scanf(" %2s", usuarios[i].sexo);
                    validarSexo(usuarios[i].sexo);
                    break;
                case 4:
                    printf("Informe o novo endereço:");
                    getchar();
                    fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);
                    usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';
                    break;
                case 5:
                    printf("Informe a nova altura:");
                    scanf("%lf", &usuarios[i].altura);
                    validaAltura(&usuarios[i].altura);
                    break;
                case 6:
                    printf("Informe se tomou a vacina (1 para sim, 0 para não): ");
                    scanf("%d", &usuarios[i].vacina);
                    validaVacina(usuarios[i].vacina);
                    break;
                case 7:
                    printf("\nEditando cadastro inteiro do Usuário ID %s\n", id);
                    cadastrar(usuarios, &totalCadastrados);
                    return;
                case 0:
                    printf("Saindo da edição.\n");
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                }
            } while (opcao != 0);

            printf("Cadastro atualizado com sucesso!\n");
            return;
        }
    }

    printf("Usuário ID %s não encontrado!\n", id);
}

void excluir(Usuario usuarios[], int *totalCadastrados, const char id[])
{
    if (*totalCadastrados == 0)
    {
        printf("Cadastro de usuarios vazio\n");
        return;
    }
    else
    {
        for (int i = 0; i < *totalCadastrados; i++)
        {
            if (strcmp(usuarios[i].id, id) == 0)
            {
                for (int j = i; j < *totalCadastrados - 1; j++)
                {
                    usuarios[j] = usuarios[j + 1];
                }
                (*totalCadastrados)--;
                printf("Usuário ID %s excluído com sucesso!\n", id);
                return;
            }
        }
        printf("Usuário ID %s não encontrado!\n", id);
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    Usuario usuarios[USUARIOS];
    int totalCadastros = 0;

    char opcao;

    do
    {
        printf("\nOpcoes\n");
        printf("1:Cadastrar\n");
        printf("2:Imprimir\n");
        printf("3:Buscar pelo E-mail\n");
        printf("4:Editar\n");
        printf("5:Excluir\n");
        printf("0:Sair\n");

        printf("Escolha a opcao desejada: ");
        scanf(" %c", &opcao);
        switch (opcao)
        {
        case '1':
            cadastrar(usuarios, &totalCadastros);
            break;
        case '2':
            imprimir(usuarios, totalCadastros);
            break;
        case '3':
            printf("Informe o e-mail a ser buscado: ");
            char buscaEmail[50];
            scanf(" %s", buscaEmail);
            buscarEmail(usuarios, totalCadastros, buscaEmail);
            break;
        case '4':
            printf("Informe o ID do usuário a ser editado: ");
            char idEditar[4];
            scanf(" %3s", idEditar);
            editar(usuarios, totalCadastros, idEditar);
            break;
        case '5':
            printf("Informe o ID do usuário a ser excluído: ");
            char idExcluir[4];
            scanf(" %3s", idExcluir);
            excluir(usuarios, &totalCadastros, idExcluir);
            break;
        case '0':
            printf("Saiu do Programa\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente\n");
        }
    } while (opcao != '0');

    return 0;
}
