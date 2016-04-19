#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int dimx = 10;
    int num_bytes = dimx * sizeof (int);
    int *h_a = 0;
    
    h_a = (int *) malloc(num_bytes);
    
    struct Horario{
        int hora;
        int minuto;
        int segundo;
        double calc;
        char letra;
    }tempo = {
        .hora = 13,
        .minuto = 8,
        .segundo = 59,
        .calc = 5.6,
        .letra = 'A'
    }tempoAgora = {
        .hora = tempo.hora + 12,
        .letra = 'D'
    };
    printf("\n******************************************\n");
    printf("%i", tempo.hora);
    printf("\n");
    printf("%i", tempo.minuto);
    printf("\n");
    printf("%i", tempo.segundo);
    printf("\n");
    printf("%f", tempo.calc);
    printf("\n");
    printf("%c", tempo.letra);
    printf("\n******************************************\n");        
    printf("%i", tempoAgora.hora);
    printf("\n");
    printf("%c", tempoAgora.letra);
    printf("\n******************************************\n");
    printf("%p", h_a);
    printf("\n");
    free(h_a);
    return 0;
}