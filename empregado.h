//arquivo de cabeçalho para a estrutura definida em tad.c

struct empregado;
struct empregado* get_empregado();
void set_nome(struct empregado *e, char *c);
char* get_nome(struct empregado *e);
void set_cpf(struct empregado *e, double cpf);
double get_cpf(struct empregado *e);
void set_salario(struct empregado *e, double salario);
double get_salario(struct empregado *e);