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
#define USUARIOS 1000 // Inclua até 1000 usuários;

// Edite um usuário;
void editar();
// Exclua um usuário;
void excluir();
// Busque um usuário pelo e-mail;
void buscarEmail();
// Imprima todos os usuários cadastrados;
void imprimir();
// cadastrar usuarios
void cadastrar();

typedef struct
{

    int id;
    char nome[50];
    char email[50];
    char sexo[3];
    char endereco[100];
    double altura;
    int vacina;

} Usuario;
// Email (string) => validação do campo: verificar se o caractere "@" aparece
int validarEmail(char email[])
{
    int valido = 0; // Iniciar como e-mail inválido

    for (int i = 0; email[i] != '\0'; i++)
    {
        // Imprimir mensagem de validação ou invalidação dentro da função.
        if (email[i] == '@')
        {
            printf("E-mail validado\n"); // Encontrou o caractere arroba
            return 1;                    // Valor positivo para confirmar
        }
    }

    printf("E-mail inválido! Tente novamente\n");
    return 0; // Valor negativo para inválido
}
// Sexo (string) => validação do campo: aceitar somente as palavras Feminino, Masculino e Indiferente.
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

// Na versão que desenvolvi, comparei os caracteres individualmente.
// Certifiquei-me de que o array sexo tivesse pelo menos 3 caracteres para acomodar dois caracteres de gênero e o caractere nulo de terminação '\0'.
//  Utilizei o formato "%2s" no scanf para garantir a leitura de apenas dois caracteres, e o espaço em branco antes de %2s ajudou na eliminação de quaisquer espaços em branco adicionais.
//  Essas escolhas foram feitas para assegurar uma entrada de usuário controlada e apropriada para o contexto do programa.

// Altura (double) => validação do campo: aceitar valores entre 1 e 2 m.
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
// Vacina (int) => validação de 1 para sim e 0 para não
int validaVacina(int vacina)
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
// agora criar funcao void cadastrar que utiliza as funcoes de validação para preencher os campos de typedef scruct usuario
void cadastrar(Usuario usuarios[], int *totalCadastrados)
{
    srand((unsigned int)time(NULL));

    // Gera um ID único entre 1 e 1000
    usuarios[*totalCadastrados].id = rand() % 1000 + 1;

    printf("\nCadastro de Usuários\n");

    printf("Informe o nome:");
    scanf("%s", usuarios[*totalCadastrados].nome);

    // Continuar solicitando o e-mail enquanto o e-mail fornecido for inválido.
    while (!validarEmail(usuarios[*totalCadastrados].email))
    {
        printf("Informe o e-mail:");
        scanf("%s", usuarios[*totalCadastrados].email);
    }

    // Solicitar e validar o gênero do usuário.
    validarSexo(usuarios[*totalCadastrados].sexo);

    printf("Informe o endereço:");
    scanf("%s", usuarios[*totalCadastrados].endereco);

    // Solicitar e validar a altura do usuário
    printf("Informe a altura: ");
    scanf("%lf", &usuarios[*totalCadastrados].altura);
    validaAltura(&usuarios[*totalCadastrados].altura);

    // Solicitar e validar a resposta da vacina
    printf("Informe se tomou a vacina (1 para sim, 0 para não): ");
    scanf("%d", &usuarios[*totalCadastrados].vacina);
    validaVacina(usuarios[*totalCadastrados].vacina);

    (*totalCadastrados)++;
}
// criar funcao que ira imprimir todo as informacoes do cadastro
void imprimir(Usuario usuarios[], int totalCadastrados)
{
    if (totalCadastrados == 0)
    {
        printf("Cadastro de usuarios vazio");
        return;
    }
    printf("\nLista de Usuarios\n");
    for (int i = 0; i < totalCadastrados; i++)
    {
        printf("ID: %d\n", usuarios[i].id);
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
// criar funcao que ira buscar o usuario cadastrado pelo email
void buscarEmail(Usuario usuarios[], int totalCadastros, char email[])
{
    if (totalCadastros == 0)
    {
        printf("Cadastro de usuarios vazio\n"); // sempre verificar se a lista de cadastros esta preenchida
        return;
    }
    // Percorrer a lista de cadastros para encontrar o usuário com o e-mail fornecido
    int encontrado = 0; // Flag para indicar se o e-mail foi encontrado

    for (int i = 0; i < totalCadastros; i++)
    {
        int j;
        for (j = 0; usuarios[i].email[j] != '\0' && email[j] != '\0'; j++)
        {
            if (usuarios[i].email[j] != email[j])
            {
                break; // Se encontrar uma diferença, sai do loop interno
            }
        }
        // Se ambos os e-mails chegaram ao final (são iguais até agora)
        if (usuarios[i].email[j] == '\0' && email[j] == '\0')
        {
            printf("Usuario Encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf metros\n", usuarios[i].altura);
            printf("Vacina: ");
            validaVacina(usuarios[i].vacina);
            printf("\n");

            encontrado = 1; // Atualizar a flag para indicar que o e-mail foi encontrado
            break;          // Não é necessário continuar procurando
        }
    }
    // se o email nao foi encontrado
    if (!encontrado)
    {
        printf("Usuário com o e-mail %s não encontrado.\n", email);
    }
}
// criar funcao para editar o cadastrado pelo id dele
void editar(Usuario usuarios[], int totalCadastrados, int id)
{
    printf("Editando usuário ID %d\n", id);

    for (int i = 0; i < totalCadastrados; i++)
    {
        if (usuarios[i].id == id)
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
                    scanf("%s", usuarios[i].nome);
                    break;
                case 2:
                    printf("Informe o novo e-mail (ou '0' para sair): ");
                    scanf("%s", usuarios[i].email);
                    break;
                case 3:
                    printf("Informe o novo sexo (M/F): ");
                    scanf(" %s", usuarios[i].sexo);
                    // Solicitar e validar o novo gênero do usuário
                    validarSexo(usuarios[i].sexo);
                    break;
                case 4:
                    printf("Informe o novo endereço:");
                    scanf("%s", usuarios[i].endereco);
                    break;
                case 5:
                    // Solicitar e validar a nova altura do usuário
                    printf("Informe a nova altura:");
                    scanf("%lf", &usuarios[i].altura);
                    validaAltura(&usuarios[i].altura);
                    break;
                case 6:
                    // Solicitar e validar a nova resposta da vacina
                    printf("Informe se tomou a vacina (1 para sim, 0 para não): ");
                    scanf("%d", &usuarios[i].vacina);
                    validaVacina(usuarios[i].vacina);
                    break;
                case 7:
                    // Editar o cadastro inteiro
                    printf("\nEditando cadastro inteiro do Usuário ID %d\n", id);
                    cadastrar(usuarios, &totalCadastrados);
                    break;
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
    printf("Usuário ID %d não encontrado!\n", id);
}

// criar uma funcao para excluir usuarios cadastrados
void excluir(Usuario usuarios[], int *totalCadastrados, int id)
{
    if (*totalCadastrados == 0)
    {
        printf("Cadastro de usuarios vazio\n"); // descobrir se existem usuarios cadastrados na lista cadastrar, se nao imprimir uma mensagem avisando sobre o cadastro
        return;
    }
    else
    {
        for (int i = 0; i < *totalCadastrados; i++)
        {
            if (usuarios[i].id == id)
            {
                // Implementar a lógica para excluir o usuário
                // (pode ser necessário deslocar outros usuários no array)
                for (int j = i; j < *totalCadastrados - 1; j++)
                {
                    usuarios[j] = usuarios[j + 1];
                }
                (*totalCadastrados)--;
                printf("Usuário ID %d excluído com sucesso!\n", id);
                return;
            }
        }
        printf("Usuário ID %d não encontrado!\n", id);
    }
}
main()
{
    srand((unsigned int)time(NULL));

    Usuario usuarios[USUARIOS]; // incluir 1000 usuarios
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
        case 1:
            cadastrar(usuarios, &totalCadastros);
            break;
        case 2:
            imprimir(usuarios, totalCadastros);
            break;
        case 3:
            printf("Informe o e-mail a ser buscado: ");
            char buscaEmail[50];
            scanf("%s", buscaEmail);
            buscarEmail(usuarios, totalCadastros, buscaEmail);
            break;
        case 4:
            printf("Informe o ID do usuário a ser editado: ");
            int idEditar;
            scanf("%d", &idEditar);
            editar(usuarios, totalCadastros, idEditar);
            break;
        case 5:
            printf("Informe o ID do usuário a ser excluído: ");
            int idExcluir;
            scanf("%d", &idExcluir);
            excluir(usuarios, &totalCadastros, idExcluir);
            break;
        case 0:
            printf("Saiu do Programa\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente\n");
        }
    } while (opcao != 0);
}