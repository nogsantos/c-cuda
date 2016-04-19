#include <stdio.h>

int main() {
    
    struct Horario{
        int hora;
        int minuto;
        int segundo;
    };
    
    struct Horario tempo;
    
    tempo.hora = 13;
    tempo.minuto = 08;
    tempo.segundo = 59;
    
    printf("%i : %i : %i", tempo.hora, tempo.minuto, tempo.segundo);
    printf("\n");
    
    return 0;
}