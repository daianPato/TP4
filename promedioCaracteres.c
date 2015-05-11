/*
 * promedioCaracteres.c
 *
 *  Created on: 10/5/2015
 *      Author: Pato Daian 141940-7
 */

#include <stdio.h> /* getchar EOF feof perror printf */
#include <stdlib.h> /* EXIT_SUCCESS */
int main(void) {
int nl; /* la cantidad de lineas */
int nc; /* la cantidad de caracteres */
int c; /* el caracter leido */

for(nl = 0, nc = 0; ( c = getchar()) != EOF;){
	if(c == '\n')
			++nl;
	if(c != '\n')
		++nc;
}
if( !feof(stdin) )
	perror("No se pudo seguir leyendo de la entrada debido a un error");
printf("Longitud promedio: %.1f\n", (nl==0 ? nl=0 :(nc / ((float)nl))));
printf("Cantidad de lineas: %d\nCantidad de caracteres: %d\n",nl,nc);
return 0;
}
