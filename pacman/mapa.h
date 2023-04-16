typedef struct mapa MAPA;

void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void liberamapa(MAPA* m);
void imprimemapa(MAPA* m);

struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};
