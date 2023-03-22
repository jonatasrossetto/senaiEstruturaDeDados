//arquivo de cabeçalho para a tad definida em requisicao.c

struct Requisicao;

struct Requisicao* get_requisicao();

void cria_requisicao(struct Requisicao *req, char *novo_nome, int novo_identificador, char *novo_procedimento);

char *get_nome(struct Requisicao *req);

int get_identificador(struct Requisicao *req);

char *get_procedimento(struct Requisicao *req);