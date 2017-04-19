void ayuda(void);
int atacar();
void pocion();
void antidoto();
void informacion();
int azar(int, int);
void ganador();
void definir_pokemon(char [], char []);
void enemigo(void);
int estado(char [], int);

extern char modo[3];
extern int turno;

typedef struct {
 
	char nombre[25];
	int pv;
	char ataque1[25];
	char ataque2[25];
	char ataque3[25];
	char ataque4[25];
	char ataque1_estado[25];
	char ataque2_estado[25];
	char ataque3_estado[25];
	char ataque4_estado[25];
	char estado[25];
	int pd_max[4];
        int pd_min[4];
	int pp[4];
	int pociones;
	int antidotos;
 
	} pokemon;

extern pokemon pokemon1;
extern pokemon pokemon2;


