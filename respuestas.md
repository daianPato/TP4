Pato Daian Lucas Ezq. 141940-7
11/05/2015
Respuestas Tp Nº4 

1. En la primera expresión del for (nl=0,nc=0) la coma cumpla la función de operador. El operador de la izquierda no produce ningún resultado, después es evaluado el operador de la derecha, el valor y el tipo de la derecha son los que toma la operación coma. La evaluación de este operador siempre es de izquierda a derecha y tiene que conocer todos los valores.
    Otra expresión que colocarse en la primera sentencia del for es nc=nl=0.

2. Getchar tiene los paréntesis por que es una funciona a si como printf o putchar, y los necesita para saber que variables va a utilizar. En este caso va a recibir el siguiente carácter de entrada de una secuencia de texto.
    Si no los tuviera no haría nada la función.
	
3. La pragmática de la sentencia if es ver si el archivo termino correctamente, sin ningún error.
    La semántica es evaluar que la expresión del if sea verdadera, si es distinto de 0 se invoca la función perror.

4. La función perror(x) imprime x y un mensaje de error definido por la implantación, como si fuera un printf().

5. La expresión feof(stdin) se puede remplazar por ferror(stdin).
    La semántica de feof es que va a devolver un valor distinto de  0 si se encuentra en fin del archivo. Y la de ferror es que va a devolver un valor distinto de 0 si hay un error en el flujo del archivo.
    No son mutuamente excluyentes, puede pasar que  ferror me devuelva que hay un error y ese error se encuentre en la mitad del archivo, por lo tanto no estoy en el final del mismo.
    La pragmática en este caso es verificar que el archivo termine sin problemas.

6. El formato %.1f , va a escribir el valor de la variable como punto flotante, con 1 decimal luego de la coma.

7. Se castea la variable nl, ya que de no hacerlo el resultado final no seria el deseado, truncaria la parte entera de la división a 0. Si usamos el casteo la división se hace con coma flotante y el resultado es el deseado. 
	Ej: sin casteo =  printf("Longitud promedio: %.1f\n", nc /nl );
		Al ejecutar el programa con el texto 
		Daian 
		Daian 
		(ctrl.+d)
		Imprimiria por pantalla = -0.0.
      con casteo =  printf("Longitud promedio: %.1f\n", nc /(float)nl );
		Al ejecutar el programa con el texto 
		Daian 
		Daian 
		(ctrl.+d)
		Imprimiria por pantalla = 6.0.


10. El programa no funciona para una entrada nula. Hay que agregar un condicional para que no divida por 0 cuando no hay lineas. 
      El condicional quedaría de la siguiente manera : (nl==0 ? nl=0 :(nc / ((float)nl))). 
      Evalúa si la cantidad de lineas es 0 o no, en el caso de ser 0 se le asigna cero a nl si no hace la división.

11. No es precisa ya el programa esta contando los /n como caracteres para calcular el promedio final. 
      Para solucionarlo se puede implementar la siguiente estructura para el cuerpo del for:

 for(nl = 0, nc = 0; ( c = getchar()) != EOF;){
	if(c == '\n')
			++nl;
	if(c != '\n')
		++nc;
}
      Esta solución solo incrementaría la cantidad de caracteres (nc) son contar los enters(/n).

12. Solo hay que modificar printf o agregar uno nuevo en el programa ya que la cantidad de lineas están guardadas en la variable nl y la cantidad de caracteres en nc.
      El printf que se agregaria es: printf("Cantidad de lineas: %d\nCantidad de caracteres: %d\n",nl,nc);
