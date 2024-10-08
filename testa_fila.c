// Testes para a LibFila.c

#include <stdio.h>
#include "LibFila.h"

fila_t *teste_criar_fila()
{
    fila_t *f;

    if (!(f = cria_fila()))
        printf("Falha na alocação da fila.\n");

    printf("Fila criada com sucesso.\n");
    return f;
}

void teste_fila_vazia(fila_t *f)
{
    if (fila_vazia(f))
        printf("Fila vazia.\n");
    else
        printf("Fila não está vazia.\n");
    printf("O tamanho da fila é: %d\n", tamanho_fila(f));
}

void teste_queue(fila_t *f, int nelem)
{
    for (int i = 1; i <= nelem; i++)
    {
        if (!insere_fila(f, i))
            printf("Fila cheia, não foi possível inserir: %d\n", i);
        else
            printf("Enfileirou: %d\n", i);

        if (fila_vazia(f))
            printf("A fila está erroneamente vazia.\n");
    }

    printf("O tamanho da fila é: %d\n", tamanho_fila(f));
}

void teste_dequeue(fila_t *f)
{
    int elem;

    // Remove todos os elementos.
    printf("Desenfileirando todos os elementos...\n");
    while (!fila_vazia(f))
    {
        if (retira_fila(f, &elem))
            printf("Removeu: %d\n", elem);
    }
    printf("O tamanho da fila é: %d\n", tamanho_fila(f));
}

void imprime_fila(fila_t *f)
{
    int inicio;

    int n = tamanho_fila(f);
    printf("Tam: %d | Fila: ", n);

    for (int i = 0; i < n; i++)
    {
        if (!retira_fila(f, &inicio))
            printf("A fila erroneamente não foi capaz de remover um elemento.");
        else
        {
            printf("%d ", inicio);
            insere_fila(f, inicio);
        }
    }
    printf("\n");
}

int main()
{
    fila_t *f;
    int i;

    printf("\n------------> Teste 1: cria fila e testa se está vazia...\n");
    f = teste_criar_fila();
    teste_fila_vazia(f);
    printf("--> Esperado: fila vazia com tamanho zero.\n");
    printf("\n");

    printf("------------> Teste 2: enfileira alguns elementos...\n");
    teste_queue(f, 5);
    printf("--> Esperado: mostrar que enfileirou de 1 a 5.\n");
    printf("--> Esperado: tamanho tem que ser 5.\n");
    teste_fila_vazia(f);
    printf("--> Esperado: fila não vazia.\n");
    printf("--> Esperado: tamanho tem que ser 5.\n");
    printf("\n");

    printf("------------> Teste 3: desenfileira até a fila ficar vazia...\n");
    teste_dequeue(f); 
    printf("--> Esperado: mostrar remoção de 1 até 5.\n");
    printf("--> Esperado: tamanho tem que ser 0.\n");
    printf("\n");

    printf("------------> Teste 4: testa se a fila ficou de fato vazia...\n");
    teste_fila_vazia(f);
    printf("--> Esperado: fila vazia.\n");
    printf("--> Esperado: tamanho tem que ser 0.\n");
    printf("\n");

    printf("------------> Teste 5: tenta desenfileirar em uma fila vazia...\n");
    if (!retira_fila(f, &i))
        printf("--> Esperado: não dar segmentation fault.\n");
    printf("\n");

    printf("------------> Teste 6: destruir fila vazia...\n");
    f = destroi_fila(f);
    printf("--> Esperado: fila vazia destruída, verificar por valgrind se deu leak...\n");
    printf("\n");

    printf("------------> Teste 7: destruir fila com elementos presentes...\n");
    f = teste_criar_fila();
    teste_queue(f, 5); 
    f = destroi_fila(f);
    printf("--> Esperado: a fila com elementos foi destruída, verificar por valgrind se deu leak...\n");
    printf("\n");

    printf("------------> Teste 8: enfileira alguns elementos para mais testes...\n");
    f = teste_criar_fila();
    teste_queue(f, 5); 
    printf("--> Esperado: mostrar que enfileirou de 1 a 5.\n");
    printf("--> Esperado: tamanho tem que ser 5.\n");
    printf("\n");

    printf("------------> Teste 9: imprime a fila...\n");
    imprime_fila(f);
    printf("--> Esperado: imprimir Tam: 5 | Fila: 1 2 3 4 5 \n");
    printf("\n");

    printf("------------> Teste 10: desenfileira até a fila ficar vazia...\n");
    teste_dequeue(f); 
    printf("--> Esperado: mostrar remoção de 1 até 5.\n");
    printf("--> Esperado: tamanho tem que ser 0.\n");
    printf("\n");

    printf("------------> Teste 11: imprime uma fila vazia...\n");
    imprime_fila(f);
    printf("--> Esperado: imprimir Tam: 0 | Fila: \n");
    printf("\n");

    printf("------------> Teste 12: Final: liberar a fila sem erros no valgrind...\n\n");
    f = destroi_fila(f);

    return 0;
}
