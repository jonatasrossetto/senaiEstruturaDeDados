struct node;
struct queue;
void initQueue(struct queue *q);
struct queue* aloca_fila();
void inserir(struct queue *q, struct Requisicao *newValue);
int get_size(struct queue *q);
void remover(struct queue *q, struct Requisicao *resultado);