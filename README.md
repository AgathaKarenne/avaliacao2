# avaliacao2
exercicio 1:Limpando o buffer em C: fflush e __fpurge
Ainda no primeiro exemplo desse artigo ( o que dá problema ), digitamos a letra 'C', que é armazenada na variável 'letra1' e em seguida apertamos enter.
Esse caractere (enter), ficará armazenado no buffer do teclado (um memória temporária).

Em seguida, noss programa em C pede para que algo seja armazenado na variável 'letra2'.
Porém, antes do C receber um novo dado do usuário, ele checa se não tem mais alguma coisa armazenada no teclado (ele sempre faz isso...fez antes, para pegar a letra 'C'). E lá tem um caractere sim, o enter.

Então o programa pega esse caractere e o coloca na variável letra2, e é por isso que aparece uma quebra de linha em nosso programa.

Portanto, uma alternativa, caso não queria usar o espaço entre " e o %c na scanf, é limpar o buffer após cada scanf(), getchar(), getc() ou fgetc().

Para limpar o buffer em Windows, use: fflush(stdin)
Para limpar o buffer em Linux, use: __fpurge(stdin)
Fica ao seu dispor escolher como vai ser.
E se habitue com essas coisas, em C há várias maneiras de se fazer várias coisas. Muitas vezes, porém, a solução que usamos não é muito segura ou portável, mas é a mais simples.

Limpar o buffer, por exemplo, nem sempre é algo desejável, e para programação mais profissional e segura não é recomendado que se use fflush por exemplo.

Mas para quem está  começando, não há problema algum ficar limpando o buffer após cada scanf, e o  scanf (embora seja arriscado e não indicado em alguns casos) é o mais usado.
