/*Copyright <2017> <Francisco Domínguez Lerma>

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY <Francisco Domínguez Lerma> ''AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <Francisco Domínguez Lerma> OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ant.h"

int get_string(char file_conf[], char subject_i[], char value_i[]) {
	
	FILE * file;

	int file_line_size=50;
	int subject_size=25;
	int value_size=25;

	char buffer[file_line_size];
	char subject[subject_size];
	char value[value_size];

	file=fopen(file_conf, "r");
	if (file==NULL) {
		return(-2);

	}

	int x, y;	
	while (!feof(file))
 	{
		clear_array(buffer, file_line_size);
		clear_array(subject, subject_size);
		clear_array(value, value_size);
		
 		fgets(buffer,file_line_size,file);
 		if (buffer[0]=='#') continue;
 		
		x=0;
		
		for (x=0; x<subject_size; x++) {
			if(buffer[x]=='=') break;
			subject[x]=buffer[x];
		}
		
		y=0;
		
		for (x=x+1; x<file_line_size; x++) {		
			if(buffer[x]=='\n') break;
			value[y]=buffer[x];
			y++;
		}
		
		if (strcmp(subject_i, subject)==0) {		
			 strcpy(value_i, value); 
			 fclose(file); 
			 return(0); 
			 }
 	}
 	
	fclose(file);
	return(-1);
}

int get_int(char file_conf[], char subject_i[]) {
	
	FILE * file;

	int file_line_size=50;
	int subject_size=25;
	int value_size=25;

	char buffer[file_line_size];
	char subject[subject_size];
	char value[value_size];

	file=fopen(file_conf, "r");
	if (file==NULL) return(-2);

	int x, y;	
	while (!feof(file))
 	{
		clear_array(buffer, file_line_size);
		clear_array(subject, subject_size);
		clear_array(value, value_size);
		
 		fgets(buffer,file_line_size,file);
 		if (buffer[0]=='#') continue;
		x=0;
		for (x=0; x<subject_size; x++) {
			if(buffer[x]=='=') break;
			subject[x]=buffer[x];
		}
		
		y=0;
		
		for (x=x+1; x<file_line_size; x++) {		
			if(buffer[x]=='\n') break;
			value[y]=buffer[x];
			y++;
		}
		
		if (strcmp(subject_i, subject)==0) {
			fclose(file); 
			return(atoi(value));
			}
 	}
	
	fclose(file);
	return(-1);
}

static void clear_array(char array[], int size) {

int x;
for(x=0;x<size;x++) array[x]='\0';

}

