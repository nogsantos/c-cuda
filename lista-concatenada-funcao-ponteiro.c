/*
 * Utilizando lista concatenada e como fazer uma função que 
 * retorna um ponteiro(endereço de memória).
 */
#include <stdio.h>
/*
 * Definição da estrutura
 */
struct List{
    int value;
    struct List *next;
};
/*
 * Função que percorre a estrutura e verifica se o valor informado 
 * está contido nela.
 * 
 * @return struct List
 */
struct List *searchValue(struct List *pList, int value){
    while (pList != (struct List *) 0) {
        if(pList->value == value){
            return (pList);
        }else{
            pList = pList->next;
        }
    }
    return (struct List *) 0;
}
/*
 */
int main(){
    
    struct List m1, m2, m3;
    struct List *result, *hook = &m1;
    int in;
    
    m1.value = 1;
    m2.value = 2;
    m3.value = 3;
    
    m1.next = &m2;
    m2.next = &m3;
    m3.next = 0;
    
    printf("Type a value to search: ");
    scanf("%i", &in);
    
    result = searchValue(hook, in);
    
    if(result == (struct List *) 0){
        printf("Value not found. \n");
    }else{
        printf("Value %i found. \n", result->value);
    }
}