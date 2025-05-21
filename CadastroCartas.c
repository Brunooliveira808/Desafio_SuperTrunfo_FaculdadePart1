#include <stdio.h>

#define NUM_CARTAS 2

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    long int populacao;
    float areaKm2;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para calcular o super poder
float calcularSuperPoder(Carta c) {
    return c.populacao + c.areaKm2 + c.pib + c.pontosTuristicos + (1 / c.densidadePopulacional);
}

// Função para comparar dois valores (1 se carta1 vence, 0 se carta2 vence)
int compararMaior(float v1, float v2) {
    return (v1 > v2) ? 1 : 0;
}

// Função para comparar densidade (menor valor vence)
int compararMenor(float v1, float v2) {
    return (v1 < v2) ? 1 : 0;
}

int main() {
    Carta cartas[NUM_CARTAS];

    printf("Cadastro das Cartas do Super Trunfo:\n\n");

    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("Carta %d:\n", i + 1);

        printf("Estado (letra de A a H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Código da Carta: ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da Cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);

        printf("População: ");
        scanf("%ld", &cartas[i].populacao);

        printf("Área (em km²): ");
        scanf(" %s", &cartas[i].areaKm2);

        printf("PIB (em bilhões de reais): ");
        scanf(" %a", &cartas[i].pib);

        printf("Número de Pontos Turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        cartas[i].densidadePopulacional = cartas[i].populacao / cartas[i].areaKm2;
        cartas[i].pibPerCapita = (cartas[i].pib * 1000000000) / cartas[i].populacao;
        cartas[i].superPoder = calcularSuperPoder(cartas[i]);

        printf("\n");
    }

    printf("Comparação de Cartas:\n");

    // População (maior vence)
    if (cartas[0].populacao > cartas[1].populacao) {
        printf("População: Carta 1 venceu (1)\n");
    } else {
        printf("População: Carta 2 venceu (0)\n");
    }

    // Área (maior vence)
    if (cartas[0].areaKm2 > cartas[1].areaKm2) {
        printf("Área: Carta 1 venceu (1)\n");
    } else {
        printf("Área: Carta 2 venceu (0)\n");
    }

    // PIB (maior vence)
    if (cartas[0].pib > cartas[1].pib) {
        printf("PIB: Carta 1 venceu (1)\n");
    } else {
        printf("PIB: Carta 2 venceu (0)\n");
    }

    // Pontos Turísticos (maior vence)
    if (cartas[0].pontosTuristicos > cartas[1].pontosTuristicos) {
        printf("Pontos Turísticos: Carta 1 venceu (1)\n");
    } else {
        printf("Pontos Turísticos: Carta 2 venceu (0)\n");
    }

    // Densidade Populacional (menor vence)
    if (cartas[0].densidadePopulacional < cartas[1].densidadePopulacional) {
        printf("Densidade Populacional: Carta 1 venceu (1)\n");
    } else {
        printf("Densidade Populacional: Carta 2 venceu (0)\n");
    }

    // PIB per Capita (maior vence)
    if (cartas[0].pibPerCapita > cartas[1].pibPerCapita) {
        printf("PIB per Capita: Carta 1 venceu (1)\n");
    } else {
        printf("PIB per Capita: Carta 2 venceu (0)\n");
    }

    // Super Poder (maior vence)
    if (cartas[0].superPoder > cartas[1].superPoder) {
        printf("Super Poder: Carta 1 venceu (1)\n");
    } else {
        printf("Super Poder: Carta 2 venceu (0)\n");
    }

    return 0;
}
