/*Com a proposta para ampliação da terceirização da mão de obra,
o Ministério da Fazenda está empenhado em elaborar uma análise sobre o recebimento de salário regular através do registro em carteira profissional dos funcionários no país.
Assim, elabore um algoritmo que obtenha, para cada assalariado, com carteira profissional assinada, o seu sexo M(masculino) e F(feminino) e o valor de seu salário,
devendo este salário ser maior que um real (R$1,00). Seu algoritmo deverá analisar e classificar este assalariado em Acima, Igual ou Abaixo do salário mínimo.
Sabe-se que o salário mínimo nacional é de R$ 1400,00.
Após a leitura dos dados de cada assalariado cadastrado pelo ministério deverá ser apresentado o seu salário em reais,
a classificação por extenso em relação ao salário mínimo e o sexo por extenso (Masculino ou Feminino).
A classificação em relação ao salário mínimo nacional deverá ser feita pelo sub-algoritmo classificaSalario e os resultados solicitados para cada assalariado deverão ser apresentados
pelo sub-algoritmo denominado mostraClassifica.
Você deverá fazer a entrada de dados para todos os assalariados que foram pesquisados pelo ministério,
lembrando de fazer sempre a validação de todos os dados informados em sub-algoritmos específicos.
Na solução deste problema os resultados finais de cada assalariado que participou desta pesquisa deverão ser apresentados.
Após a leitura dos dados de todos os assalariados pesquisados o seu algoritmo deverá apresentar
 a quantidade de assalariados com salário abaixo do salário mínimo e a quantidade assalariados com salário acima do salário mínimo
*/
#include <stdio.h>

#define TAM 5
#define SALARIOABAIXO 1.00
#define SALARIO_MINIMO_NACIONAL 1400, 00

struct Assalariado
{
    char nome[50];
    int sexo;
    float salario;
};

// Função para cadastrar assalariados com carteira assinada
void cadastrarAssalariados(struct Assalariado assalariados[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("Nome do assalariado %d: ", i + 1);
        scanf("%s", assalariados[i].nome);

        printf("Gênero do assalariado %d ('M' ou 'F'): ", i + 1);
        scanf(" %c", &assalariados[i].sexo);

        do
        {
            printf("Salário do assalariado %d (maior que R$1,00): ", i + 1);
            scanf("%f", &assalariados[i].salario);

            if (assalariados[i].salario <= SALARIOABAIXO)
            {
                printf("O salário deve ser maior que R$1,00. Tente novamente.\n");
            }
        } while (assalariados[i].salario <= SALARIOABAIXO);

        printf("\n");
    }
}

int main()
{
    struct Assalariado assalariados[TAM];

    // Chamando a função para cadastrar assalariados
    cadastrarAssalariados(assalariados, TAM);

    // Exibindo os dados dos assalariados cadastrados
    printf("Dados dos assalariados:\n");
    for (int i = 0; i < TAM; ++i)
    {
        printf("Assalariado %d:\n", i + 1);
        printf("Nome: %s\n", assalariados[i].nome);
        printf("Gênero: %c\n", assalariados[i].sexo);
        printf("Salário: %.2f\n\n", assalariados[i].salario);
    }
}
