struct node;
struct queue;
void initQueue(struct queue *q);
struct queue* get_queue();
bool enqueue(struct queue *q, struct Requisicao *newValue);
int get_size(struct queue *q);
void dequeue(struct queue *q, struct Requisicao *resultado);