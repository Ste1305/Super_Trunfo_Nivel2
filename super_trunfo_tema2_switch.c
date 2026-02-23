#include <stdio.h> //inclue a biblioteca de entrada e saida padrão
#include <string.h> // biblioteca con funções para strings

int main(){
    //declarando as variaveis da carta 1 e 2
    char letra_codigo1, letra_codigo2, escolha1, escolha2, escolhaExtra1, escolhaExtra2;
    char codigo_estado1[10], codigo_estado2[10], nome_cidade1[20], nome_cidade2[20]; 
    unsigned long int populaçao1, populaçao2; 
    long double pib1, pib2;
    float densidade_populacional1, densidade_populacional2, pib_capita1, pib_capita2, area1, area2;
    int pontos_turisticos1, pontos_turisticos2, opcaoMenu, resultado1, resultado2, resultadoExtra1, resultadoExtra2, rodadaExtra;
    float superPoder1, superPoder2;

    printf("*************************************************\n");
    printf("*** Benvindo/a ao SUPER TRUNFO edição Paises! ***\n");
    printf("*************************************************\n\n\t");
    printf("Para começar, digite os dados das Cartas!\n");

    //mensagens de input e inicialização das variaveis através do input, Carta 1 e Carta 2
    printf("Digite uma letra de A até H para identificar o Estado da Carta 1: "); scanf(" %c", &letra_codigo1);
    printf("Digite uma letra de A até H para identificar o Estado da Carta 2: "); scanf(" %c", &letra_codigo2);
    
    printf("Digite a letra escolhida para a Carta 1 seguida dos numeros de 01 até 04: "); scanf("%s", codigo_estado1);
    printf("Digite a letra escolhida para a Carta 2 seguida dos numeros de 01 até 04: "); scanf("%s", codigo_estado2);

    getchar(); //função que tira o \n do buffer, para poder fazer o input antes do fgets

    printf("Digite o nome da cidade da Carta 1: ");
    fgets(nome_cidade1, sizeof(nome_cidade1), stdin); //fgets = (nome variavel, tamanho da string, stdin ou seja o meio de entrada, o teclado)
    nome_cidade1[strlen(nome_cidade1) - 1] = '\0'; // strlen() computa o comprimento da string, tiramos 1 para que não apareçam espaços brancos apos o nome
    printf("Digite o nome da cidade da Carta 2: ");
    fgets(nome_cidade2, sizeof(nome_cidade2), stdin);
    nome_cidade2[strlen(nome_cidade2) - 1] = '\0';

    printf("Digite a população da cidade da Carta 1: "); scanf("%lu", &populaçao1);
    printf("Digite a população da cidade da Carta 2: "); scanf("%lu", &populaçao2);
    
    printf("Digite a area da cidade da Carta 1 em KM2: "); scanf("%f", &area1);
    printf("Digite a area da cidade da Carta 2 em KM2: "); scanf("%f", &area2);
    
    printf("Digite o PIB da cidade da Carta 1 em R$: "); scanf("%Lf", &pib1);
    printf("Digite o PIB da cidade da Carta 2 em R$: "); scanf("%Lf", &pib2);
    
    printf("Digite o numero dos pontos turisticos que a cidade da Carta 1 tem: "); scanf("%d", &pontos_turisticos1);
    printf("Digite o numero dos pontos turisticos que a cidade da Carta 2 tem: "); scanf("%d", &pontos_turisticos2);
    
    //calculando as variaveis densidade_populacional e pib_capita
    densidade_populacional1 = populaçao1 / area1;
    densidade_populacional2 = populaçao2 / area2;
    pib_capita1 = pib1 / populaçao1;
    pib_capita2 = pib2 / populaçao2;
    //calculando variavel superPoder
    superPoder1 = (float)populaçao1 + area1 + pib1 + (float)pontos_turisticos1 + pib_capita1 + (1 / densidade_populacional1);
    superPoder2 = (float)populaçao2 + area2 + pib2 + (float)pontos_turisticos2 + pib_capita2 + (1 / densidade_populacional2);

    printf("### DADOS INSERIDOS: ###\n\n");
    //exibindo os dados da Carta 1
    printf("CARTA 1\n");
    printf("Codigo do Estado: %c\n", letra_codigo1);
    printf("Codigo da carta: %s\n", codigo_estado1);
    printf("Cidade: %s\n", nome_cidade1);
    printf("População: %lu\n", populaçao1);
    printf("Area: %.2f KM2\n", area1);
    printf("PIB: %.2Lf R$\n", pib1);
    printf("Pontos turisticos: %d\n", pontos_turisticos1);
    printf("Densidade populacional: %.2f hab/KM2\n", densidade_populacional1);
    printf("PIB per capita: %.2f R$\n", pib_capita1);
    printf("Super Poder: %.2f\n\n", superPoder1);

    //exibindo os dados da Carta 2
    printf("CARTA 2\n");
    printf("Codigo do Estado: %c\n", letra_codigo2);
    printf("Codigo da carta: %s\n", codigo_estado2);
    printf("Cidade: %s\n", nome_cidade2);
    printf("População: %lu\n", populaçao2);
    printf("Area: %.2f KM2\n", area2);
    printf("PIB: %.2Lf R$\n", pib2);
    printf("Pontos turisticos: %d\n", pontos_turisticos2);
    printf("Densidade populacional: %.2f hab/KM2\n", densidade_populacional2);
    printf("PIB per capita: %.2f R$\n", pib_capita2);
    printf("Super Poder: %.2f\n\n", superPoder2);

    //exibindo o menu principal
    printf("### MENU DE JOGO ###\n1. Regras do jogo\n2. Jogar!\n3. Sair do jogo\n");
    scanf("%d", &opcaoMenu);

    switch(opcaoMenu){
        case 1:
        printf("As regras são: o valor maior vence, exceto para o valor Densidade Populacional, onde é o menor que ganha tudo!\n"); break;
        case 2:
        printf("Chegou a hora da batalha!\nEscolhe dois parametros diferentes para ver quem vence a rodada: \n");
        printf("P - População\nA - Area\nB - PIB\nT - Pontos Turisticos\nD - Densidade Populacional\nC - PIB per Capita\nS - Super Poder\n");
        scanf(" %c %c", &escolha1, &escolha2);
        if(escolha2 == escolha1){
            printf("Por favor escolhe parametros diferentes\n"); break; //verifica se a segunda escolha for igual á primeira
        }
        switch(escolha1){ //primeiro parametro escolhido
            case 'p': 
            case 'P': printf("População: %lu vs %lu\n", populaçao1, populaçao2);
            resultado1 = (populaçao1 > populaçao2) ? 1 : 0; break;
            case 'a': 
            case 'A': printf("Area: %.2lfKM2 vs %.2lf KM2\n", area1, area2);
            resultado1 = (area1 > area2) ? 1 : 0; break;
            case 'b': 
            case 'B': printf("PIB: %.2LfR$ vs %.2Lf R$\n", pib1, pib2);
            resultado1 = (pib1 > pib2) ? 1 : 0; break;
            case 't': 
            case 'T': printf("Pontos Turisticos: %d vs %d\n", pontos_turisticos1, pontos_turisticos2);
            resultado1 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0; break;
            case 'd': 
            case 'D': printf("Densidade Populacional: %.2f hab/KM2 vs %.2f hab/KM2\n", densidade_populacional1, densidade_populacional2);
            resultado1 = (densidade_populacional1) < densidade_populacional2 ? 1 : 0; break;
            case 'c': 
            case 'C': printf("PIB per Capita: %.2f R$ vs %.2f R$\n", pib_capita1, pib_capita2);
            resultado1 = (pib_capita1 > pib_capita2) ? 1 : 0; break;
            case 's': 
            case 'S': printf("Super Poder: %.2f vs %.2f\n", superPoder1, superPoder2);
            resultado1 = (superPoder1 > superPoder2) ? 1 : 0; break;
            default:
            printf("Escolha invalida, tente novamente!\n");
        } 
        switch(escolha2){ //segundo parametro escolhido
            case 'p': 
            case 'P': printf("População: %lu vs %lu\n", populaçao1, populaçao2);
            resultado2 = (populaçao1 > populaçao2) ? 1 : 0; break;
            case 'a': 
            case 'A': printf("Area: %.2lfKM2 vs %.2lf KM2\n", area1, area2);
            resultado2 = (area1 > area2) ? 1 : 0; break;
            case 'b': 
            case 'B': printf("PIB: %.2LfR$ vs %.2Lf R$\n", pib1, pib2);
            resultado2 = (pib1 > pib2) ? 1 : 0; break;
            case 't': 
            case 'T': printf("Pontos Turisticos: %d vs %d\n", pontos_turisticos1, pontos_turisticos2);
            resultado2 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0; break;
            case 'd': 
            case 'D': printf("Densidade Populacional: %.2f hab/KM2 vs %.2f hab/KM2\n", densidade_populacional1, densidade_populacional2);
            resultado2 = (densidade_populacional1) < densidade_populacional2 ? 1 : 0; break;
            case 'c': 
            case 'C': printf("PIB per Capita: %.2f R$ vs %.2f R$\n", pib_capita1, pib_capita2);
            resultado2 = (pib_capita1 > pib_capita2) ? 1 : 0; break;
            case 's': 
            case 'S': printf("Super Poder: %.2f vs %.2f\n", superPoder1, superPoder2);
            resultado2 = (superPoder1 > superPoder2) ? 1 : 0; break;
            default:
            printf("Escolha invalida, tente novamente!\n");
        } // comparações
        if(resultado1 && resultado2){
            printf("*** Carta 1 %s %s VENCEU! ***\n", codigo_estado1, nome_cidade1);
        } else if(resultado1 != resultado2){
            printf("*** Carta 1 %s %s e Carta 2 %s %s EMPATE! ***\n", codigo_estado1, nome_cidade1, codigo_estado2, nome_cidade2);
        } else{
            printf("*** Carta 2 %s %s VENCEU! ***\n", codigo_estado2, nome_cidade2);
        }
        //oportunidade para rodada extra
        printf("Que tal uma rodada extra??\n1 - Com certeza!\n2 - Não obrigado\n"); scanf("%d", &rodadaExtra); 
        switch(rodadaExtra){
            case 1:
            printf("Ultima possibilidade!\nEscolha dois parametros que não foram escolhidos ainda: \n");
            printf("P - População\nA - Area\nB - PIB\nT - Pontos Turisticos\nD - Densidade Populacional\nC - PIB per Capita\nS - Super Poder\n");
            scanf(" %c %c", &escolhaExtra1, &escolhaExtra2);
            if((escolhaExtra1 == escolhaExtra2) && (escolhaExtra1 == escolha1) && (escolhaExtra1 == escolha2) && (escolhaExtra2 == escolha1) && (escolhaExtra2 == escolha2)){
                printf("Por favor escolhe parametros diferentes\n"); break;
            } switch(escolhaExtra1){ // primeiro parametro extra escolhido
                case 'p': 
                case 'P': printf("População: %lu vs %lu\n", populaçao1, populaçao2);
                resultadoExtra1 = (populaçao1 > populaçao2) ? 1 : 0; break;
                case 'a': 
                case 'A': printf("Area: %.2lfKM2 vs %.2lf KM2\n", area1, area2);
                resultadoExtra1 = (area1 > area2) ? 1 : 0; break;
                case 'b': 
                case 'B': printf("PIB: %.2LfR$ vs %.2Lf R$\n", pib1, pib2);
                resultadoExtra1 = (pib1 > pib2) ? 1 : 0; break;
                case 't': 
                case 'T': printf("Pontos Turisticos: %d vs %d\n", pontos_turisticos1, pontos_turisticos2);
                resultadoExtra1 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0; break;
                case 'd': 
                case 'D': printf("Densidade Populacional: %.2f hab/KM2 vs %.2f hab/KM2\n", densidade_populacional1, densidade_populacional2);
                resultadoExtra1 = (densidade_populacional1) < densidade_populacional2 ? 1 : 0; break;
                case 'c': 
                case 'C': printf("PIB per Capita: %.2f R$ vs %.2f R$\n", pib_capita1, pib_capita2);
                resultadoExtra1 = (pib_capita1 > pib_capita2) ? 1 : 0; break;
                case 's': 
                case 'S': printf("Super Poder: %.2f vs %.2f\n", superPoder1, superPoder2);
                resultadoExtra1 = (superPoder1 > superPoder2) ? 1 : 0; break;
                default:
                printf("Escolha invalida, tente novamente!\n");
            } 
            switch(escolhaExtra2){ //segundo parametro extra escolhido
                case 'p': 
                case 'P': printf("População: %lu vs %lu\n", populaçao1, populaçao2);
                resultadoExtra2 = (populaçao1 > populaçao2) ? 1 : 0; break;
                case 'a': 
                case 'A': printf("Area: %.2lfKM2 vs %.2lf KM2\n", area1, area2);
                resultadoExtra2 = (area1 > area2) ? 1 : 0; break;
                case 'b': 
                case 'B': printf("PIB: %.2LfR$ vs %.2Lf R$\n", pib1, pib2);
                resultadoExtra2 = (pib1 > pib2) ? 1 : 0; break;
                case 't': 
                case 'T': printf("Pontos Turisticos: %d vs %d\n", pontos_turisticos1, pontos_turisticos2);
                resultadoExtra2 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0; break;
                case 'd': 
                case 'D': printf("Densidade Populacional: %.2f hab/KM2 vs %.2f hab/KM2\n", densidade_populacional1, densidade_populacional2);
                resultadoExtra2 = (densidade_populacional1) < densidade_populacional2 ? 1 : 0; break;
                case 'c': 
                case 'C': printf("PIB per Capita: %.2f R$ vs %.2f R$\n", pib_capita1, pib_capita2);
                resultadoExtra2 = (pib_capita1 > pib_capita2) ? 1 : 0; break;
                case 's': 
                case 'S': printf("Super Poder: %.2f vs %.2f\n", superPoder1, superPoder2);
                resultadoExtra2 = (superPoder1 > superPoder2) ? 1 : 0; break;
                default:
                printf("Escolha invalida, tente novamente!\n");
            } // resultados da rodada extra
            if(resultadoExtra1 && resultadoExtra2){
                printf("*** Carta 1 %s %s VENCEU! ***\n", codigo_estado1, nome_cidade1);
            } else if(resultadoExtra1 != resultadoExtra2){
            printf("*** Carta 1 %s %s e Carta 2 %s %s EMPATE! ***\n", codigo_estado1, nome_cidade1, codigo_estado2, nome_cidade2);
            } else{
            printf("*** Carta 2 %s %s VENCEU! ***\n", codigo_estado2, nome_cidade2);
            } 
            case 2: //despedida do jogo em fall-through caso termino rodada extra ou case 3 sair menu principal
            printf("Valeu!\n");
        }
        case 3:
        printf("Saindo do jogo...\nObrigado por ter jogado, até a proxima!\n"); break;
        default:
        printf("Escolha invalida, tente de novo\n");
    }
   return 0; //fim do programa
}   
