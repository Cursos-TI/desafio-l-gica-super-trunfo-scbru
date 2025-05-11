#include <stdio.h>

struct CartaSuperTrunfo {
    char estado;                    // Letra do estado (A a H)
    char codigo[4];                 // Código da carta (ex: A01, B03)
    char nomeCidade[50];           // Nome da cidade
    int populacao;                 // Número de habitantes
    float area;                    // Área da cidade (em km²)
    float pib;                     // Produto Interno Bruto
    int pontosTuristicos;         // Número de pontos turísticos  
};

int main() {
    struct CartaSuperTrunfo carta1, carta2;     // Declarando duas cartas separadamente
        float densidade1, densidade2;
    float pibperC1, pibperC2;
    float superpoderpopulacao, superpoderarea, superpoderpib, superpoderpontosturisticos, superpoderpibperc, superpoderinvdensidadepop;
    float SuperPoderTotal1,SuperPoderTotal2;
    int opcao1, opcao2;                      // Opção a ser escolhida no menu


    // Entrada de dados para a primeira carta

    printf("### Digite os dados da primeira carta ###\n");

    printf("Estado (A a H): ");
    scanf(" %c", &carta1.estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta1.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade); // Lê uma string com espaços
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    printf("\n");   //Pula linha para iniciar captação de dados da segunda carta

    printf("\n### Digite os dados da segunda carta ###\n");
    printf("Estado (A a H): ");
    scanf(" %c", &carta2.estado);
    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta2.codigo);
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade); // Lê uma string com espaços
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    //Cálculo da Densidade (Divisão da população da cidade pela sua área. )
    densidade1 = carta1.populacao / carta1.area;
    densidade2 = carta2.populacao / carta2.area;

    //Cálculo da PIB Per Capita (Divisão do PIB da cidade pela sua população. )
    pibperC1 = carta1.pib / carta1.populacao;
    pibperC2 = carta2.pib / carta2.populacao;


    //Cálculo do Super Poder Total
    SuperPoderTotal1 = carta1.populacao + carta1.area + carta1.pib + carta1.pontosTuristicos + (1/densidade1);
    SuperPoderTotal2 = carta2.populacao + carta2.area + carta2.pib + carta2.pontosTuristicos + (1/densidade2);
   
    //Comparação entre as cartas
    
    //População (Maior vence)
    int resultadoPop = carta1.populacao > carta2.populacao;

    //Area (Maior vence)
    int resultadoArea = carta1.area > carta2.area;

    //PIB (Maior vence)
    int resultadoPIB = carta1.pib > carta2.pib;

    // Pontos Turísticos (Maior vence)
    int resultadoPontos = carta1.pontosTuristicos > carta2.pontosTuristicos;

    // Densidade Populacional (Menor vence)
    int resultadoDensidade = densidade1 < densidade2;

    // PIB per Capita (Maior vence)
    int resultadoPIBperC = pibperC1 > pibperC2;

    // Super Poder (Maior vence)
    int resultadoSuperPoder = SuperPoderTotal1 > SuperPoderTotal2;

    // Nova exibição dos dados das cartas

    printf("\n=========== CARTA 1 ===========\n");
    printf("Cidade: %s\nPopulação: %d\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\n",
           carta1.nomeCidade, carta1.populacao, carta1.area, carta1.pib, carta1.pontosTuristicos, densidade1, pibperC1);
    
           printf("\n=========== CARTA 2 ===========\n");
    printf("Cidade: %s\nPopulação: %d\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\n",
           carta2.nomeCidade, carta2.populacao, carta2.area, carta2.pib, carta2.pontosTuristicos, densidade2, pibperC2);

    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica (MENOR vence)\n6 - PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao1);

    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    if (opcao1 != 1) printf("1 - População\n");
    if (opcao1 != 2) printf("2 - Área\n");
    if (opcao1 != 3) printf("3 - PIB\n");
    if (opcao1 != 4) printf("4 - Pontos Turísticos\n");
    if (opcao1 != 5) printf("5 - Densidade Demográfica (MENOR vence)\n");
    if (opcao1 != 6) printf("6 - PIB per Capita\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao2);

    float valor1_1 = 0, valor1_2 = 0;
    float valor2_1 = 0, valor2_2 = 0;

    switch (opcao1) {
        case 1: valor1_1 = carta1.populacao; valor2_1 = carta2.populacao; 
        break;
        case 2: valor1_1 = carta1.area; valor2_1 = carta2.area; 
        break;
        case 3: valor1_1 = carta1.pib; valor2_1 = carta2.pib; 
        break;
        case 4: valor1_1 = carta1.pontosTuristicos; valor2_1 = carta2.pontosTuristicos; 
        break;
        case 5: valor1_1 = densidade1; valor2_1 = densidade2; 
        break;
        case 6: valor1_1 = pibperC1; valor2_1 = pibperC2; 
        break;
    }

    switch (opcao2) {
        case 1: valor1_2 = carta1.populacao; valor2_2 = carta2.populacao; 
        break;
        case 2: valor1_2 = carta1.area; valor2_2 = carta2.area; 
        break;
        case 3: valor1_2 = carta1.pib; valor2_2 = carta2.pib; 
        break;
        case 4: valor1_2 = carta1.pontosTuristicos; valor2_2 = carta2.pontosTuristicos; 
        break;
        case 5: valor1_2 = densidade1; valor2_2 = densidade2; 
        break;
        case 6: valor1_2 = pibperC1; valor2_2 = pibperC2; 
        break;
    }

    float soma1, soma2;
    soma1 = (opcao1 == 5 ? -valor1_1 : valor1_1) + (opcao2 == 5 ? -valor1_2 : valor1_2);
    soma2 = (opcao1 == 5 ? -valor2_1 : valor2_1) + (opcao2 == 5 ? -valor2_2 : valor2_2);

    printf("\n=========== RESULTADO DA COMPARAÇÃO ===========\n");
    printf("%s: %.2f e %.2f | Soma: %.2f\n", carta1.nomeCidade, valor1_1, valor1_2, soma1);
    printf("%s: %.2f e %.2f | Soma: %.2f\n", carta2.nomeCidade, valor2_1, valor2_2, soma2);

    if (soma1 > soma2)
        printf("\nVencedora: %s\n", carta1.nomeCidade);
    else if (soma2 > soma1)
        printf("\nVencedora: %s\n", carta2.nomeCidade);
    else
        printf("\nEmpate!\n");

    return 0;
}