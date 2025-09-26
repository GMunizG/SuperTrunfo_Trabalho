#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CIDADES 4
#define NUM_ATRIBUTOS 3

typedef struct {
    char nome[30];
    int populacao;  // em mil habitantes
    int area;       // em km²
    int pib;        // em bilhões
} Cidade;

void mostrar_cidade(Cidade c) {
    printf("Cidade: %s\n", c.nome);
    printf("1) População: %d mil\n", c.populacao);
    printf("2) Área     : %d km²\n", c.area);
    printf("3) PIB      : %d bi\n", c.pib);
}

int main() {
    srand(time(NULL));

    // baralho de cidades
    Cidade cidades[NUM_CIDADES] = {
        {"São Paulo", 12000, 1521, 699},
        {"Rio de Janeiro", 6700, 1182, 400},
        {"Belo Horizonte", 2500, 331, 120},
        {"Curitiba", 1900, 435, 95}
    };

    printf("=== Super Trunfo - Cidades ===\n\n");

    // jogador escolhe uma carta
    int escolha;
    printf("Escolha sua cidade:\n");
    for (int i = 0; i < NUM_CIDADES; i++) {
        printf("%d) %s\n", i+1, cidades[i].nome);
    }
    printf("> ");
    scanf("%d", &escolha);
    escolha--; // índice no vetor

    if (escolha < 0 || escolha >= NUM_CIDADES) {
        printf("Escolha inválida!\n");
        return 0;
    }

    Cidade sua = cidades[escolha];

    printf("\nSua carta:\n");
    mostrar_cidade(sua);

    // jogador escolhe atributo
    int atributo;
    printf("\nEscolha um atributo (1=População, 2=Área, 3=PIB): ");
    scanf("%d", &atributo);

    if (atributo < 1 || atributo > NUM_ATRIBUTOS) {
        printf("Atributo inválido!\n");
        return 0;
    }

    // CPU pega cidade aleatória diferente
    int cpu_escolha;
    do {
        cpu_escolha = rand() % NUM_CIDADES;
    } while (cpu_escolha == escolha);

    Cidade cpu = cidades[cpu_escolha];

    printf("\nCPU escolheu a cidade: %s\n", cpu.nome);
    mostrar_cidade(cpu);

    // comparar
    int valor_jogador, valor_cpu;
    if (atributo == 1) {
        valor_jogador = sua.populacao;
        valor_cpu = cpu.populacao;
    } else if (atributo == 2) {
        valor_jogador = sua.area;
        valor_cpu = cpu.area;
    } else {
        valor_jogador = sua.pib;
        valor_cpu = cpu.pib;
    }

    printf("\nResultado:\n");
    printf("Você: %d | CPU: %d\n", valor_jogador, valor_cpu);

    if (valor_jogador > valor_cpu) {
        printf("Parabéns, você venceu!\n");
    } else if (valor_cpu > valor_jogador) {
        printf("CPU venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
