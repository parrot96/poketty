#include <stdio.h>
#include <stdlib.h>
#include "poketty.h"
#include <math.h>
#include <time.h>
#include <string.h>
#include "ant/ant.h"

pokemon pokemon1;
pokemon pokemon2;

char modo[3];
int turno;

void ayuda() {
 
	printf("h -> Despliega esta ayuda\n");
	printf("a -> Ataca al pokemon enemigo\n");
	printf("p -> Cura a tu pokemon si tienes pociones\n");
	printf("x -> Usar antídoto\n");
 	printf("i -> Da información sobre tu pokemon, ataques, pociones y el pv enemigo\n");
	printf("e -> Cancelar la partida\n");
 
 
	}

int atacar() {
 
int dano;
int ataque;
int est_aleatorio=azar(0, 2);


if(turno==1) {

    if((strcmp(pokemon1.estado, "normal")!=0) && (est_aleatorio==1)) {
	
	printf("El pokemon %s está %s y no se puede mover\n", pokemon1.nombre, pokemon1.estado);
	turno=2;
	return 0;

	}	
    printf("1. %s pp:%d\n", pokemon1.ataque1, pokemon1.pp[0]);
    printf("2. %s pp:%d\n", pokemon1.ataque2, pokemon1.pp[1]);
    printf("3. %s pp:%d\n", pokemon1.ataque3, pokemon1.pp[2]);
    printf("4. %s pp:%d\n", pokemon1.ataque4, pokemon1.pp[3]);
    
    printf("\nElige el ataque a usar [1-4]\n");
    
} else {

   if((strcmp(pokemon2.estado, "normal")!=0) && (est_aleatorio==1)) {
	
	printf("El pokemon %s está %s y no se puede mover\n", pokemon2.nombre, pokemon2.estado);
	turno=1;
	return 0;

	}
    if (modo[0]=='0') {
    printf("1. %s pp:%d\n", pokemon2.ataque1, pokemon2.pp[0]);
    printf("2. %s pp:%d\n", pokemon2.ataque2, pokemon2.pp[1]);
    printf("3. %s pp:%d\n", pokemon2.ataque3, pokemon2.pp[2]);
    printf("4. %s pp:%d\n", pokemon2.ataque4, pokemon2.pp[3]);
    
    printf("\nElige el ataque a usar [1-4]\n");
}
    
}

if((modo[0]=='1') && (turno==2)) {
	do {
		ataque=azar(1,4);
		} while (pokemon2.pp[ataque]==0); }
else {
ataque=fgetc(stdin);
while(fgetc(stdin) != '\n');
ataque=ataque-48;
}
printf("--------------------\n");
if (turno==1) {

		switch ( ataque ) {
 
			case 1:
				if (pokemon1.pp[0]==0){printf("no te quedan pp\n"); turno=2; break;;}
				dano=azar(pokemon1.pd_min[ataque-1], pokemon1.pd_max[ataque-1]);
				printf("\E[0;32m%s uso %s\n", pokemon1.nombre, pokemon1.ataque1);
				pokemon1.pp[0]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon2.pv-=dano;
					if (pokemon2.pv<=0)
						ganador();
				if(est_aleatorio==1)
					estado(pokemon1.ataque1_estado, turno); 					
				turno=2;
				break;;
			case 2:
				if (pokemon1.pp[1]==0){printf("no te quedan pp\n"); turno=2; break;;}
				dano=azar(pokemon1.pd_min[ataque-1], pokemon1.pd_max[ataque-1]);
				printf("\E[0;32m%s uso %s\n", pokemon1.nombre, pokemon1.ataque2);
				pokemon1.pp[1]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon2.pv-=dano;
					if (pokemon2.pv<=0)
						ganador();
				if(est_aleatorio==1)
					estado(pokemon1.ataque2_estado, turno);  
				turno=2;
				break;;
			case 3:
				if (pokemon1.pp[2]==0){printf("no te quedan pp\n"); turno=2; break;;}
				dano=azar(pokemon1.pd_min[ataque-1], pokemon1.pd_max[ataque-1]);
				printf("\E[0;32m%s uso %s\n", pokemon1.nombre, pokemon1.ataque3);
				pokemon1.pp[2]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon2.pv-=dano;
					if (pokemon2.pv<=0)
						ganador();
				if(est_aleatorio==1)
					estado(pokemon1.ataque3_estado, turno);  
				turno=2;
				break;;
			case 4:
				if (pokemon1.pp[3]==0){printf("no te quedan pp\n"); turno=2; break;;}
				dano=azar(pokemon1.pd_min[ataque-1], pokemon1.pd_max[ataque-1]);
				printf("\E[0;32m%s uso %s\n", pokemon1.nombre, pokemon1.ataque4);
				pokemon1.pp[3]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon2.pv-=dano;
					if (pokemon2.pv<=0)
						ganador(); 
				if(est_aleatorio==1)
					estado(pokemon1.ataque4_estado, turno); 
				turno=2;
				break;;
			default:
				printf("no has elegido ningun ataque, así que pierdes el turno\n");
				turno=2;
				break;;
 
		}

	}else{

		switch ( ataque ) {
 
			case 1:
				if (pokemon2.pp[0]==0){printf("no te quedan pp\n"); turno=1; break;;}
				dano=azar(pokemon2.pd_min[ataque-1], pokemon2.pd_max[ataque-1]);
				printf("\E[0;31m%s uso %s\n", pokemon2.nombre, pokemon2.ataque1);
				pokemon2.pp[0]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon1.pv-=dano;
					if (pokemon1.pv<=0)
						ganador(); 
				if(est_aleatorio==1)
					estado(pokemon2.ataque1_estado, turno); 
				turno=1;
				break;;
			case 2:
				if (pokemon2.pp[1]==0){printf("no te quedan pp\n"); turno=1; break;;}
				dano=azar(pokemon2.pd_min[ataque-1], pokemon2.pd_max[ataque-1]);
				printf("\E[0;31m%s uso %s\n", pokemon2.nombre, pokemon2.ataque2);
				pokemon2.pp[1]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon1.pv-=dano;
					if (pokemon1.pv<=0)
						ganador(); 
				if(est_aleatorio==1)
					estado(pokemon2.ataque2_estado, turno); 
				turno=1;
				break;;
			case 3:
				if (pokemon2.pp[2]==0){printf("no te quedan pp\n"); turno=1; break;;}
				dano=azar(pokemon2.pd_min[ataque-1], pokemon2.pd_max[ataque-1]);
				printf("\E[0;31m%s uso %s\n", pokemon2.nombre, pokemon2.ataque3);
				pokemon2.pp[2]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon1.pv-=dano;
					if (pokemon1.pv<=0)
						ganador(); 
				if(est_aleatorio==1)
					estado(pokemon2.ataque3_estado, turno); 
				turno=1;
				break;;
			case 4:
				if (pokemon2.pp[3]==0){printf("no te quedan pp\n"); turno=1; break;;}
				dano=azar(pokemon2.pd_min[ataque-1], pokemon2.pd_max[ataque-1]);
				printf("\E[0;31m%s uso %s\n", pokemon2.nombre, pokemon2.ataque4);
				pokemon2.pp[3]--;
				printf("Le has quitado %d puntos de vida\E[00m\n", dano);
				pokemon1.pv-=dano;
					if (pokemon1.pv<=0)
						ganador(); 
				if(est_aleatorio==1)
					estado(pokemon2.ataque4_estado, turno); 
				turno=1;
				break;;
			default:
				printf("no has elegido ningun ataque, así que pierdes el turno\n");
				turno=1;
				break;;
		}

	}
printf("--------------------\n");
return 0;
 
 
}
 
void pocion() {
 
  if (turno==1){

	turno=2;
	if(pokemon1.pociones==0) {

	printf("no tienes pociones, así que pierdes el turno\n");

	} else {

		pokemon1.pociones-=1;
		pokemon1.pv+=60;
		if (pokemon1.pv>100) pokemon1.pv=100;
		printf("Poción activa, ahora tu pv es de %d\n", pokemon1.pv);

		}


  } else {

	turno=1;
	if(pokemon2.pociones==0) {

	printf("no tienes pociones, así que pierdes el turno\n");

	} else {

		pokemon2.pociones-=1;
		pokemon2.pv+=60;
		if (pokemon2.pv>100) pokemon2.pv=100;
		printf("Poción activa, ahora tu pv es de %d\n", pokemon2.pv);

		}


	}
 
}

void antidoto() {
 
  if (turno==1){

	turno=2;
	if(pokemon1.antidotos==0) {

	printf("no tienes antidoto, así que pierdes el turno\n");

	} else {

		pokemon1.antidotos--;
		if(strcmp(pokemon1.estado, "normal")==0) 
			printf("El pokemon estaba en estado normal, no le hacía falta el antídoto\n");
		else {
		strcpy(pokemon1.estado, "normal");
		printf("Antídoto aplicado con éxito, el pokemon vuelve a la normalidad\n");}
  }} else {

	turno=1;
	if(pokemon2.antidotos==0) {

	printf("no tienes antidoto, así que pierdes el turno\n");

	} else {

		pokemon2.antidotos--;
		if(strcmp(pokemon2.estado, "normal")==0) 
			printf("El pokemon estaba en estado normal, no le hacía falta el antídoto\n");
		else {
		strcpy(pokemon2.estado, "normal");
		printf("Antídoto aplicado con éxito, el pokemon vuelve a la normalidad\n");}
	}
 
}
}

void informacion() {

	
	if (turno==1){
		printf("**********\n");
		printf("%s\n", pokemon1.nombre);
		printf("Estado del pokemon: %s\n", pokemon1.estado);
		printf("Estado del pokemon enemigo: %s\n", pokemon2.estado);
		printf("pv:%d\n", pokemon1.pv);
		printf("\t-----ATAQUES-----\n");
		printf("\t%s pp: %d\n", pokemon1.ataque1, pokemon1.pp[0]);
		printf("\t%s pp: %d\n", pokemon1.ataque2, pokemon1.pp[1]);
		printf("\t%s pp: %d\n", pokemon1.ataque3, pokemon1.pp[2]);
		printf("\t%s pp: %d\n", pokemon1.ataque4, pokemon1.pp[3]);
		printf("\t-----------------\n");
		printf("Numero de pociones: %d\n", pokemon1.pociones);
		printf("Numero de antidotos: %d\n", pokemon1.antidotos);
		printf("pv enemigo: %d\n", pokemon2.pv);
		printf("**********\n");
}
	if (turno==2){
		printf("**********\n");
		printf("%s\n", pokemon2.nombre);
		printf("Estado del pokemon: %s\n", pokemon2.estado);
		printf("Estado del pokemon enemigo: %s\n", pokemon1.estado);
		printf("pv: %d\n", pokemon2.pv);
		printf("\t-----ATAQUES-----\n");
		printf("\t%s pp: %d\n", pokemon2.ataque1, pokemon2.pp[0]);
		printf("\t%s pp: %d\n", pokemon2.ataque2, pokemon2.pp[1]);
		printf("\t%s pp: %d\n", pokemon2.ataque3, pokemon2.pp[2]);
		printf("\t%s pp: %d\n", pokemon2.ataque4, pokemon2.pp[3]);
		printf("\t-----------------\n");
		printf("Numero de pociones: %d\n", pokemon2.pociones);
		printf("Numero de antidotos: %d\n", pokemon2.antidotos);
		printf("pv enemigo: %d\n", pokemon1.pv);
		printf("**********\n");

}

}

int azar(int minimo, int maximo){
srand(time(NULL));
return rand() % (maximo - minimo + 1) + minimo;
} 

void ganador() {

if (turno==1) {
	printf("--------------------\n");
	printf("%s ha ganado la partida\n", pokemon1.nombre);
	printf("--------------------\n");
	exit(0);

} else {
	printf("--------------------\n");
	printf("%s ha ganado la partida\n", pokemon2.nombre);
	printf("--------------------\n");
	exit(0);

	}
}

void definir_pokemon(char pokemon1_fcl[], char pokemon2_fcl[]) {
	
	//PRIMER POKEMON
	//nombre del pokemon
	get_string(pokemon1_fcl, "nombre", pokemon1.nombre);
	//vida del pokemon
	pokemon1.pv=get_int(pokemon1_fcl, "pv");
	//nombre de los 4 ataques del pokemon
	get_string(pokemon1_fcl, "ataque1", pokemon1.ataque1);
	get_string(pokemon1_fcl, "ataque2", pokemon1.ataque2);
	get_string(pokemon1_fcl, "ataque3", pokemon1.ataque3);
	get_string(pokemon1_fcl, "ataque4", pokemon1.ataque4);
	//puntos de daño máximo, el valor maximo de daño que causa cada ataque
	pokemon1.pd_max[0]=get_int(pokemon1_fcl, "pd1_max");
	pokemon1.pd_max[1]=get_int(pokemon1_fcl, "pd2_max");
	pokemon1.pd_max[2]=get_int(pokemon1_fcl, "pd3_max");
	pokemon1.pd_max[3]=get_int(pokemon1_fcl, "pd4_max");
        //puntos de daño mínimo, el valor maximo de daño que causa cada ataque
	pokemon1.pd_min[0]=get_int(pokemon1_fcl, "pd1_min");
	pokemon1.pd_min[1]=get_int(pokemon1_fcl, "pd2_min");
	pokemon1.pd_min[2]=get_int(pokemon1_fcl, "pd3_min");
	pokemon1.pd_min[3]=get_int(pokemon1_fcl, "pd4_min");
	//estado en el que puede dejar al otro pokemon cada ataque
	get_string(pokemon1_fcl, "ataque1_estado", pokemon1.ataque1_estado);
	get_string(pokemon1_fcl, "ataque2_estado", pokemon1.ataque2_estado);
	get_string(pokemon1_fcl, "ataque3_estado", pokemon1.ataque3_estado);
	get_string(pokemon1_fcl, "ataque4_estado", pokemon1.ataque4_estado);
	//puntos de poder, las veces que podemos usar x ataque en una batalla
	pokemon1.pp[0]=get_int(pokemon1_fcl, "pp1");
	pokemon1.pp[1]=get_int(pokemon1_fcl, "pp2");
	pokemon1.pp[2]=get_int(pokemon1_fcl, "pp3");
	pokemon1.pp[3]=get_int(pokemon1_fcl, "pp4");
	//numero de pociones que tiene el pokemon
	pokemon1.pociones=get_int(pokemon1_fcl, "pociones");
	//numero de antidotos que tiene el pokemon
	pokemon1.antidotos=get_int(pokemon1_fcl, "antidotos");
	//estado inicial del pokemon
	strcpy(pokemon1.estado, "normal");
 	
// SEGUNDO POKEMON

	//nombre del pokemon
	get_string(pokemon2_fcl, "nombre", pokemon2.nombre);
	//vida del pokemon
	pokemon2.pv=get_int(pokemon2_fcl, "pv");
	//nombre de los 4 ataques del pokemon
	get_string(pokemon2_fcl, "ataque1", pokemon2.ataque1);
	get_string(pokemon2_fcl, "ataque2", pokemon2.ataque2);
	get_string(pokemon2_fcl, "ataque3", pokemon2.ataque3);
	get_string(pokemon2_fcl, "ataque4", pokemon2.ataque4);
	//puntos de daño máximo, el valor maximo de daño que causa cada ataque
	pokemon2.pd_max[0]=get_int(pokemon2_fcl, "pd1_max");
	pokemon2.pd_max[1]=get_int(pokemon2_fcl, "pd2_max");
	pokemon2.pd_max[2]=get_int(pokemon2_fcl, "pd3_max");
	pokemon2.pd_max[3]=get_int(pokemon2_fcl, "pd4_max");
        //puntos de daño mínimo, el valor maximo de daño que causa cada ataque
	pokemon2.pd_min[0]=get_int(pokemon2_fcl, "pd1_min");
	pokemon2.pd_min[1]=get_int(pokemon2_fcl, "pd2_min");
	pokemon2.pd_min[2]=get_int(pokemon2_fcl, "pd3_min");
	pokemon2.pd_min[3]=get_int(pokemon2_fcl, "pd4_min");
	//estado en el que puede dejar al otro pokemon cada ataque
	get_string(pokemon2_fcl, "ataque1_estado", pokemon2.ataque1_estado);
	get_string(pokemon2_fcl, "ataque2_estado", pokemon2.ataque2_estado);
	get_string(pokemon2_fcl, "ataque3_estado", pokemon2.ataque3_estado);
	get_string(pokemon2_fcl, "ataque4_estado", pokemon2.ataque4_estado);
	//puntos de poder, las veces que podemos usar x ataque en una batalla
	pokemon2.pp[0]=get_int(pokemon2_fcl, "pp1");
	pokemon2.pp[1]=get_int(pokemon2_fcl, "pp2");
	pokemon2.pp[2]=get_int(pokemon2_fcl, "pp3");
	pokemon2.pp[3]=get_int(pokemon2_fcl, "pp4");
	//numero de pociones que tiene el pokemon
	pokemon2.pociones=get_int(pokemon2_fcl, "pociones");
	//numero de antidotos que tiene el pokemon
	pokemon2.antidotos=get_int(pokemon2_fcl, "antidotos");
	//estado inicial del pokemon
	strcpy(pokemon2.estado, "normal");

}

void enemigo() {

int comando_enemigo;

//Pequeña I.A para la CPU
if(strcmp(pokemon2.estado, "normal")!=0 && (pokemon2.pv>20) && (pokemon2.antidotos!=0)) comando_enemigo=azar(0,1);
else if ((pokemon2.pv<=20) && (pokemon2.pociones!=0)) comando_enemigo=azar(3,4);
else if ((pokemon2.pv<80) && (pokemon2.pociones!=0)) comando_enemigo=azar(2,4);
else comando_enemigo=0;
printf("\n");

switch (comando_enemigo) {

	case 0:
		atacar();
		break;
	case 1:
		antidoto();
		break;
	case 2:
		atacar();
		break;
	case 3:
		atacar();
		break;
	case 4:
		pocion();
		break;

}
}

int estado(char estado[], int turno) {
if (strcmp(estado, "normal")==0)
	return 0;
if (turno==1) {
	strcpy(pokemon2.estado, estado);
	printf("El pokemon %s cambia al estado %s\n", pokemon2.nombre, estado);
	turno=2;
	return 0;
}
else {
	strcpy(pokemon1.estado, estado);
	printf("El pokemon %s cambia al estado %s\n", pokemon1.nombre, estado);
	turno=1;
	return 0;
}
}
