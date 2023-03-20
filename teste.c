#include <stdio.h>
#include "empregado.h"

//para montar a aplicação utilizando o struct definido em tad.c e compilado para tad.o com o head
//gcc teste.c tad.o

int main() {
    // define o ponteiro e do tipo estruturado empregado e recebe o endereço do bloco alocado na memória por get_empregado
    struct empregado *e = get_empregado();

    set_nome(e, "Jurandir Matias de Souza Prado");
    set_cpf(e, 98765432100);
    set_salario(e, 3500);
    printf("e: %d\n",e);
    printf("%s\nCPF %.0f\nSalario: R$ %.2f\n", get_nome(e), get_cpf(e), get_salario(e));
}