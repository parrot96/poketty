# English

This library is used to extract information from a configuration file, the goal of ant is to produce the smallest software possible for that task.

You can use the following functions:

Get_string -> get the value of a string field and copy it to the specified string, eg: "get_string (config_file," field ", array_destination);", 
If it can not find the field inside the file it returns -1, if it can not open the file -2, if no error occurs it returns 0

Get_int -> return the value of an int field, 
If it can not find the field inside the file it returns -1, if it can not open the file -2, if no error occurs it returns 0

# Spanish

Esta biblioteca sirve para extraer información de un archivo de configuración, el objetivo de ant es producir el software más pequeño posible para dicha tarea.

Puedes usar las siguientes funciones:

get_string -> obtiene el valor de un campo string y lo copiará al string expecificado, ejemplo: "get_string(archivo_conf, "campo", array_destino);", 
sino puede encontrar el campo dentro del fichero devuelve -1, sino puede abrir el fichero -2, sino se produce ningún error devuelve 0

get_int -> devuelve el valor de un campo int, 
si no puede encontrar el campo dentro del fichero devuelve -1, si no puede abrir el fichero -2, si no se produce ningún error devuelve 0

# Example

## In plain text file "test.conf":
```
Field1=foobarstring
Field2=34
#Foobar comment
Field3=foobarstring2
```
## In C file:

```
#include <stdio.h>
#include <stdlib.h>
#include "ant.h"

void main() {
    
    int number;
    char string[15];
    int status=get_string("test.conf", "Field1", string);
    
    if(status==-1) printf("The field not exist\n");
    if(status==-2) printf("The file not exist\n");
    
    number=get_int("test.conf", "Field2");
    
    if(number==-1) printf("The field not exist\n");
    if(number==-2) printf("The file not exist\n");
    
    
    if(status>=0 && number>=0) {
        printf("%s\n", string);
        printf("%d\n", number);
    }
    
}
```
## For compile
```
CC myprogram.c ant.c -o myprogram
```
