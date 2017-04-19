/*
 * Copyright (C) 2015 Francisco Domínguez Lerma, 2016 DalmeGNU [dalmemail@amaya.tk]
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "fcl.h"
#include "poketty.h"
#include "upkm/upkm.h"

#define VERSION "1.4"

char modo[3];
int turno=1;
 
int main() {

	printf("Elige un modo de juego\n");
	printf("0 -> Modo multijugador (contra un amigo)\n");
	printf("1 -> Modo un jugador (contra CPU)\n");
	printf("si no eliges una opcion, se usará modo multijugador\n");

	fgets(modo, 3, stdin);
	
	if(strlen(modo)-1=='\n') modo[strlen(modo)-1]='\0';	

	printf("--------------------\n");
	if (modo[0]=='1') printf("Has elegido modo un jugador\n");
	if (modo[0]!='1') printf("Has elegido modo multijugador\n");
	printf("--------------------\n");

	char pokemon1_fcl[100];
	printf("Escribe el nombre del primer pokemon (en modo contra CPU controlas a este)...");
	fgets(pokemon1_fcl, 100, stdin);

	char pokemon2_fcl[100];
	printf("Escribe el nombre del segundo pokemon...");
	fgets(pokemon2_fcl, 100, stdin);

	if(pokemon1_fcl[strlen(pokemon1_fcl)-1]=='\n') pokemon1_fcl[strlen(pokemon1_fcl)-1]='\0';
	if(pokemon2_fcl[strlen(pokemon2_fcl)-1]=='\n') pokemon2_fcl[strlen(pokemon2_fcl)-1]='\0';

	if(fopen(pokemon1_fcl, "r")==NULL) {printf("error al abrir el archivo %s\n", pokemon1_fcl); return 1;}
	if(fopen(pokemon2_fcl, "r")==NULL) {printf("error al abrir el archivo %s\n", pokemon2_fcl); return 1;}

	char pkm[64];
	char path_buffer[40];
	if ((get_value_string(pokemon1_fcl, "pkm", pkm) != 0) || (strcmp(pkm, VERSION)) != 0) {
		char option[3];
		do {
			printf("El archivo '%s' necesita ser convertido.\n¿Iniciar la conversión? [S/n]", pokemon1_fcl);
			fgets(option, 3, stdin);
                        if(option[strlen(option)-1]=='\n') option[strlen(option)-1]='\0';
		} while(option[0] != 's' && option[0] != 'S' && option[0] != 'n' && option[0] != 'N');
		if (option[0] == 'n' || option[0] == 'N') {
			return 1;
		}
		else {
			sprintf(path_buffer, "%s.new", pokemon1_fcl);
			upkm(pokemon1_fcl, path_buffer);
			if ((strcmp(pokemon1_fcl, pokemon2_fcl)) == 0) {
				strcpy(pokemon2_fcl, path_buffer);
			}
			strcpy(pokemon1_fcl, path_buffer);
		}
	}
	if ((get_value_string(pokemon2_fcl, "pkm", pkm) != 0) || (strcmp(pkm, VERSION)) != 0) {
		char option[3];
		do {
			printf("El archivo '%s' necesita ser convertido.\n¿Iniciar la conversión? [S/n]", pokemon2_fcl);
			fgets(option, 3, stdin);
                        if(option[strlen(option)-1]=='\n') option[strlen(option)-1]='\0';
		} while(option[0] != 's' && option[0] != 'S' && option[0] != 'n' && option[0] != 'N');
		if (option[0] == 'n' || option[0] == 'N') {
			return 1;
		}
		else {
			sprintf(path_buffer, "%s.new", pokemon2_fcl);
			upkm(pokemon2_fcl, path_buffer);
			strcpy(pokemon2_fcl, path_buffer);
		}
	}
	definir_pokemon(pokemon1_fcl, pokemon2_fcl);

	char comando;
	ayuda();
 
	while (1) {

		if (turno==1)
			printf("[\E[0;32m%s\E[00m(%s)]", pokemon1.nombre, pokemon1.estado);
		else
			printf("[\E[0;31m%s\E[00m(%s)]", pokemon2.nombre, pokemon2.estado);
 
		printf("Introduce la orden...");
		if((modo[0]=='1') && (turno==2)) {enemigo(); continue;}
		comando = fgetc(stdin);
		while(fgetc(stdin) != '\n');
		switch ( comando ) {
 
			case 'h':
				ayuda();
				break;;
			case 'a':
				atacar();
				break;;
			case 'p':
				pocion();
				break;;
			case 'x':
				antidoto();
				break;;
			case 'i':
				informacion();
				break;;
			case 'e':
				printf("Se cancelo la partida\n");
				return 0;
			default:
				ayuda();
 
		}
	}
}

