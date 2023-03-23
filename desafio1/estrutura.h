struct node;
struct fila;
void inicia_fila(struct fila *q);
struct fila* aloca_fila();
void inserir(struct fila *q, struct Requisicao *newValue);
int get_size(struct fila *q);
void remover(struct fila *q, struct Requisicao *resultado);