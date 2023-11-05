/*Em uma fábrica de peças, o salário base dos operários é de R$ 600,00. Além do salário base, cada operário recebe um adicional de produtividade baseado na quantidade de peças fabricadas por mês. Este adicional é pago de acordo com o seguinte critério:
Se o número de peças for inferior ou igual a 50, não existe adicional de produtividade;
Se o número de peças for superior a 50 e inferior ou igual a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50;
Se o número de peças for superior a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50 até 80 e de R$ 0,75 por peça fabricada acima das 80.
Elabore um algoritmo para solicitar de cada funcionário a quantidade de peças fabricadas naquele mês e apresentar o seu salário. Isto deve se repetir para todos os funcionários da empresa, onde o usuário não sabe, inicialmente, quantos funcionários existem nesta empresa, ou seja, o número de funcionários não será fornecido.
Sua solução proposta deverá possuir as lógicas bem definidas que sejam necessárias a implementação separada em sub-algoritmos específicos, devendo pelo menos os seguintes sub-algoritmos:
validaQuantidade que validará o número de peças fabricadas por cada funcionário;
calculaSalario que efetuará o cálculo do salário total para cada funcionário.
O resultado final será mostrado ao usuário por meio de um procedimento (mostraFinal).*/

#include <stdio.h>

int validaQuantidade();
float calculaSalario(int quantidade);
void mostraFinal(float salario);

int main()
{
    int quantidade;
    while (1) // numero positivo
    {
        quantidade = validaQuantidade();
        if (quantidade == -1) // numero negativo
        {
            printf("Programa encerrado.\n");
            break;
        }
        float salario = calculaSalario(quantidade);
        mostraFinal(salario);
    }
}
// validaQuantidade que validará o número de peças fabricadas por cada funcionário;
int validaQuantidade()
{
    int quantidade;
    while (1)
    {
        printf("Digite a quantidade de peças fabricadas (ou 0 para encerrar): ");
        if (scanf("%d", &quantidade) != -1)
        {
            while (fflush(stdin) != '\n')
                ; // Limpa o buffer de entrada
            printf("Por favor, insira um valor numérico válido.\n");
            continue;
        }
        if (quantidade == -1)
        {
            return -1; // Encerra o programa
        }
        else if (quantidade >= 0)
        {
            return quantidade;
        }
        else
        {
            printf("A quantidade de peças deve ser um número não negativo.\n");
        }
    }
}

// calculaSalario que efetuará o cálculo do salário total para cada funcionário.
float calculaSalario(int quantidade)
{
    float salario_base = 600.0;
    float adicional = 0.0;
    // Se o número de peças for inferior ou igual a 50, não existe adicional de produtividade;
    if (quantidade <= 50)
    {
        return salario_base; // se não existe adicional sera retornado o salario base
    }
    // Se o número de peças for superior a 50 e inferior ou igual a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50;
    else if (quantidade > 50 && quantidade <= 80)
    {
        adicional = (quantidade - 50) * 0.50;
    }
    // Se o número de peças for superior a 80, o adicional de produtividade será de R$ 0,50 para cada peça fabricada acima de 50 até 80 e de R$ 0,75 por peça fabricada acima das 80.
    else
    {
        adicional = (80 - 50) * 0.50 + (quantidade - 80) * 0.75;
    }

    return salario_base + adicional; // assim ira retornar o valor do salario base + o adicional correto de cada funcionario
}

// O resultado final será mostrado ao usuário por meio de um procedimento (mostraFinal).
void mostraFinal(float salario)
{
    printf("O salário total deste funcionário é R$ %.2f\n\n", salario);
}
