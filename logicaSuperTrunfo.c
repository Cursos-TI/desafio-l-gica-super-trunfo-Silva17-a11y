#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void limparBuffer() {
    while (getchar() != '\n');
}

int main() {
    // Variáveis para as cartas
    char pais1[50], pais2[50];
    int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;

    // Entrada de dados para a Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", pais1);
    printf("População (em milhões): ");
    scanf("%d", &populacao1);
    printf("Área (em milhares de km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões de dólares): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    densidade1 = populacao1 / area1;

    // Entrada de dados para a Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Nome do país: ");
    scanf(" %[^\n]", pais2);
    printf("População (em milhões): ");
    scanf("%d", &populacao2);
    printf("Área (em milhares de km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões de dólares): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    densidade2 = populacao2 / area2;

    // Menu interativo
    int opcao1, opcao2;
    bool atributos_selecionados[6] = {false}; // Controla quais atributos já foram selecionados

    do {
        // Primeira escolha de atributo
        printf("\n=== ESCOLHA O PRIMEIRO ATRIBUTO ===\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao1);

        if (opcao1 == 0) {
            printf("Encerrando o programa...\n");
            return 0;
        }

        if (opcao1 < 1 || opcao1 > 5) {
            printf("Opção inválida! Tente novamente.\n");
            limparBuffer();
            continue;
        }

        atributos_selecionados[opcao1] = true;

        // Segunda escolha de atributo (menu dinâmico)
        printf("\n=== ESCOLHA O SEGUNDO ATRIBUTO (diferente do primeiro) ===\n");
        if (!atributos_selecionados[1]) printf("1 - População\n");
        if (!atributos_selecionados[2]) printf("2 - Área\n");
        if (!atributos_selecionados[3]) printf("3 - PIB\n");
        if (!atributos_selecionados[4]) printf("4 - Pontos Turísticos\n");
        if (!atributos_selecionados[5]) printf("5 - Densidade Demográfica\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao2);

        if (opcao2 == 0) {
            atributos_selecionados[opcao1] = false;
            limparBuffer();
            continue;
        }

        if (opcao2 < 1 || opcao2 > 5 || atributos_selecionados[opcao2]) {
            printf("Opção inválida ou repetida! Tente novamente.\n");
            atributos_selecionados[opcao1] = false;
            limparBuffer();
            continue;
        }

        // Variáveis para os atributos selecionados
        char atributo1[30], atributo2[30];
        float valor1_1, valor1_2; // Valores para a carta 1
        float valor2_1, valor2_2; // Valores para a carta 2
        bool menor_vence1 = false, menor_vence2 = false;

        // Configura o primeiro atributo selecionado
        switch(opcao1) {
            case 1:
                strcpy(atributo1, "População");
                valor1_1 = populacao1;
                valor2_1 = populacao2;
                break;
            case 2:
                strcpy(atributo1, "Área");
                valor1_1 = area1;
                valor2_1 = area2;
                break;
            case 3:
                strcpy(atributo1, "PIB");
                valor1_1 = pib1;
                valor2_1 = pib2;
                break;
            case 4:
                strcpy(atributo1, "Pontos Turísticos");
                valor1_1 = pontos_turisticos1;
                valor2_1 = pontos_turisticos2;
                break;
            case 5:
                strcpy(atributo1, "Densidade Demográfica");
                valor1_1 = densidade1;
                valor2_1 = densidade2;
                menor_vence1 = true;
                break;
        }

        // Configura o segundo atributo selecionado
        switch(opcao2) {
            case 1:
                strcpy(atributo2, "População");
                valor1_2 = populacao1;
                valor2_2 = populacao2;
                break;
            case 2:
                strcpy(atributo2, "Área");
                valor1_2 = area1;
                valor2_2 = area2;
                break;
            case 3:
                strcpy(atributo2, "PIB");
                valor1_2 = pib1;
                valor2_2 = pib2;
                break;
            case 4:
                strcpy(atributo2, "Pontos Turísticos");
                valor1_2 = pontos_turisticos1;
                valor2_2 = pontos_turisticos2;
                break;
            case 5:
                strcpy(atributo2, "Densidade Demográfica");
                valor1_2 = densidade1;
                valor2_2 = densidade2;
                menor_vence2 = true;
                break;
        }

        // Exibe os dados para comparação
        printf("\n=== COMPARAÇÃO ===\n");
        printf("Países: %s vs %s\n", pais1, pais2);
        printf("Atributos selecionados: %s e %s\n\n", atributo1, atributo2);

        // Comparação do primeiro atributo
        printf("%s:\n", atributo1);
        printf("%s: %.2f\n", pais1, valor1_1);
        printf("%s: %.2f\n", pais2, valor2_1);
        printf("Vencedor: ");
        if (menor_vence1) {
            printf("%s\n", (valor1_1 < valor2_1) ? pais1 : (valor2_1 < valor1_1) ? pais2 : "Empate!");
        } else {
            printf("%s\n", (valor1_1 > valor2_1) ? pais1 : (valor2_1 > valor1_1) ? pais2 : "Empate!");
        }

        // Comparação do segundo atributo
        printf("\n%s:\n", atributo2);
        printf("%s: %.2f\n", pais1, valor1_2);
        printf("%s: %.2f\n", pais2, valor2_2);
        printf("Vencedor: ");
        if (menor_vence2) {
            printf("%s\n", (valor1_2 < valor2_2) ? pais1 : (valor2_2 < valor1_2) ? pais2 : "Empate!");
        } else {
            printf("%s\n", (valor1_2 > valor2_2) ? pais1 : (valor2_2 > valor1_2) ? pais2 : "Empate!");
        }

        // Cálculo da soma dos atributos
        float soma1 = valor1_1 + valor1_2;
        float soma2 = valor2_1 + valor2_2;

        printf("\nSoma dos atributos:\n");
        printf("%s: %.2f\n", pais1, soma1);
        printf("%s: %.2f\n", pais2, soma2);
        printf("Resultado final: ");
        if (soma1 > soma2) {
            printf("%s venceu!\n", pais1);
        } else if (soma2 > soma1) {
            printf("%s venceu!\n", pais2);
        } else {
            printf("Empate!\n");
        }

        // Reinicia os atributos selecionados para nova comparação
        memset(atributos_selecionados, false, sizeof(atributos_selecionados));
        limparBuffer();

    } while (true);

    return 0;
}