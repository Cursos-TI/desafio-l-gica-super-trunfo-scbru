#include <stdio.h>

struct CartaSuperTrunfo {
    char estado;                    // Letra do estado (A a H)
    char codigo[4];                 // Código da carta (ex: A01, B03)
    char nomeCidade[50];            // Nome da cidade
    int populacao;                  // Número de habitantes
    float area;                     // Área da cidade (em km²)
    float pib;                      // Produto Interno Bruto
    int pontosTuristicos;           // Número de pontos turísticos  
   
};

int main() {
    struct CartaSuperTrunfo carta1, carta2; // Declarando duas cartas separadamente

    float densidade1, densidade2;
    float pibperC1, pibperC2;
    float superpoderpopulacao, superpoderarea, superpoderpib, superpoderpontosturisticos, superpoderpibperc, superpoderinvdensidadepop;
    float SuperPoderTotal1,SuperPoderTotal2;
    int opcao; 

    // Entrada de dados para a primeira carta
    printf("Digite os dados da primeira carta:\n");

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

    // Entrada de dados para a segunda carta
    printf("Digite os dados da segunda carta:\n");

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

    printf("\n");

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
     printf("=========== CARTA 1 ===========\n");
    printf("Cidade: %s\nPopulação: %d\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\n",
           carta1.nomeCidade, carta1.populacao, carta1.area, carta1.pib, carta1.pontosTuristicos, densidade1, pibperC1);
    printf("\n");    
    printf("=========== CARTA 2 ===========\n");
    printf("Cidade: %s\nPopulação: %d\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\n",
           carta2.nomeCidade, carta2.populacao, carta2.area, carta2.pib, carta2.pontosTuristicos, densidade2, pibperC2);

    // Menu de escolha
    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (MENOR vence)\n");
    printf("6 - PIB per Capita\n");
    printf("7 - Super Poder Total\n");
    printf("\n");
    printf("Digite a opção: ");
    scanf("%d", &opcao);

    // Lógica de comparação com switch
    printf("\n=========== RESULTADO ===========\n");

    switch (opcao) {
        case 1:
            printf("Comparando População:\n");
            printf("%s: %d habitantes\n", carta1.nomeCidade, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nomeCidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (carta1.populacao < carta2.populacao)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 2:
            printf("Comparando Área:\n");
            printf("%s: %.2f km²\n", carta1.nomeCidade, carta1.area);
            printf("%s: %.2f km²\n", carta2.nomeCidade, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (carta1.area < carta2.area)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 3:
            printf("Comparando PIB:\n");
            printf("%s: %.2f\n", carta1.nomeCidade, carta1.pib);
            printf("%s: %.2f\n", carta2.nomeCidade, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (carta1.pib < carta2.pib)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 4:
            printf("Comparando Pontos Turísticos:\n");
            printf("%s: %d\n", carta1.nomeCidade, carta1.pontosTuristicos);
            printf("%s: %d\n", carta2.nomeCidade, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (carta1.pontosTuristicos < carta2.pontosTuristicos)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 5:
            printf("Comparando Densidade Demográfica (MENOR vence):\n");
            printf("%s: %.2f hab/km²\n", carta1.nomeCidade, densidade1);
            printf("%s: %.2f hab/km²\n", carta2.nomeCidade, densidade2);
            if (densidade1 < densidade2)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (densidade1 > densidade2)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 6:
            printf("Comparando PIB per Capita:\n");
            printf("%s: %.2f reais\n", carta1.nomeCidade, pibperC1);
            printf("%s: %.2f reais\n", carta2.nomeCidade, pibperC2);
            if (pibperC1 > pibperC2)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (pibperC1 < pibperC2)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        case 7:
            printf("Comparando Super Poder Total:\n");
            printf("%s: %.2f\n", carta1.nomeCidade, SuperPoderTotal1);
            printf("%s: %.2f\n", carta2.nomeCidade, SuperPoderTotal2);
            if (SuperPoderTotal1 > SuperPoderTotal2)
                printf("Vencedora: %s\n", carta1.nomeCidade);
            else if (SuperPoderTotal1 < SuperPoderTotal2)
                printf("Vencedora: %s\n", carta2.nomeCidade);
            else
                printf("Empate!\n");
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    return 0;
}