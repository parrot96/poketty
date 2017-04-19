# ¿Qué es poketty?

Poketty es un simulador de batallas p0kemon en modo consola para GNU/Linux.
Esta licenciado bajo GPL y es totalmente libre, poketty usa la librería fcl.h
para leer los archivos .pkm que contienen información de cada p0kemon,
(librería que es también libre bajo GPL y creada por el autor de este software)
de esa forma puedes crear tus propios p0kemons personalizados para combatir,
el programa al arrancar te pedirá el nombre de los pkm a cargar.

# Compilando poketty

Para compilar y ejecutar el programa, ir a la carpeta descomprimida y compilarlo con:
```
make
```
Esto genera un ejecutable, para correrlo, primero darle permisos de ejecución con:
```
chmod +x poketty
```
Y ejecutarlo con:
```
./poketty
```
# Creando tus propios .pkm

Poketty no implementa los datos de los p0kemons hardcodeado en el código fuente, sino que utiliza archivos en texto plano 
con extensión .pkm para ello, de esta forma, cada p0kemon es un archivo .pkm.

Para crear un pkm, crear un archivo de texto plano en la carpeta donde está el ejecutable 
y la librería y rellenar los siguientes campos:
```
#version de poketty
pkm=
#nombre del p0kemon
nombre=
#vida del p0kemon
pv=
#ataques del p0kemon
ataque1=
ataque2=
ataque3=
ataque4=
#estados que induce cada ataque
ataque1_estado=
ataque2_estado=
ataque3_estado=
ataque4_estado=
#puntos de daño mínimo del p0kemon, es decir, la fuerza mínima de los ataques, corresponden con los ataques anteriores en 
orden
pd1_min=
pd2_min=
pd3_min=
pd4_min=
#puntos de daño máximo del p0kemon, es decir, la fuerza máxima de los ataques, corresponden con los ataques anteriores en 
orden
pd1_max=
pd2_max=
pd3_max=
pd4_max=
#puntos de poder del p0kemon, es decir, las veces que puedes usar un ataque en la partida, corresponden 
#a los ataques anteriores y a los pd anteriores
pp1=
pp2=
pp3=
pp4=
#numero de pociones que tiene el p0kemon
pociones=
#numero de antidotos que tiene el p0kemon
antidotos=
```
Un ejemplo de archivo pkm valido es:
```
pkm=1.3
nombre=abaddon
pv=100
ataque1=mirada terrible
ataque2=golpe brutal
ataque3=energía iónica
ataque4=voluntad destructiva
ataque1_estado=paralizado
ataque2_estado=normal
ataque3_estado=normal
ataque4_estado=normal
pd1_min=25
pd2_min=40
pd3_min=50
pd4_min=65
pd1_max=35
pd2_max=45
pd3_max=55
pd4_max=70
pp1=50
pp2=10
pp3=2
pp4=1
pociones=4
antidotos=2
```
En los archivos pkm, poniendo "#" al empezar una linea permite escribir comentarios, estos serán ignorados por el programa.

Durante el juego se te pedirá que escribas el nombre del p0kemon, debes especificarle el nombre del archivo.pkm con su 
extensión, por ejemplo "pikachu.pkm".

En el repositorio podrás encontrar tres ficheros .pkm: pikachu.pkm, infernape.pkm y abaddon.pkm, no son más que puros 
ejemplos para probar el juego, ¡Siéntete libre de escribir los tuyos propios!

# Módulo de compatibilidad entre versiones

Poketty en cada versión suele romper la compatibilidad con anteriores ficheros .pkm, ya que al incluir nuevas 
características son necesarios nuevos campos dentro de dicho .pkm. Dan rulos creó un módulo llamado "upkm" que convierte 
automáticamente archivos .pkm entre distintas versiones mientras se ejecuta poketty.

# COLABORACIONES

El desarrollador principal de este juego, como la licencia lo indica, es Francisco Domínguez Lerma, pero también ha colaborado una persona con el nick "abaddon", ha contribuido aportando un .pkm que viene en esta release (aunque he tenido 
que adaptarlo a poketty 1.3).

En esta última versión, ha colaborado muchísimo Dan Rulos con su aportación de upkm, upkm tiene su propio repositorio en github mantenido por Dan en: https://github.com/dalmemail/upkm

Espero que disfrutes del juego, tanto jugándolo como leyendo su código fuente y aprendiendo mucho de él.


