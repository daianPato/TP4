Pato Daian Lucas Ezq. 141940-7
11/05/2015
Respuestas Tp N�4 

1. En la primera expresi�n del for (nl=0,nc=0) la coma cumpla la funci�n de operador. El operador de la izquierda no produce ning�n resultado, despu�s es evaluado el operador de la derecha, el valor y el tipo de la derecha son los que toma la operaci�n coma. La evaluaci�n de este operador siempre es de izquierda a derecha y tiene que conocer todos los valores.
    Otra expresi�n que colocarse en la primera sentencia del for es nc=nl=0.

2. Getchar tiene los par�ntesis por que es una funciona a si como printf o putchar, y los necesita para saber que variables va a utilizar. En este caso va a recibir el siguiente car�cter de entrada de una secuencia de texto.
    Si no los tuviera no har�a nada la funci�n.
	
3. La pragm�tica de la sentencia if es ver si el archivo termino correctamente, sin ning�n error.
    La sem�ntica es evaluar que la expresi�n del if sea verdadera, si es distinto de 0 se invoca la funci�n perror.

4. La funci�n perror(x) imprime x y un mensaje de error definido por la implantaci�n, como si fuera un printf().

5. La expresi�n feof(stdin) se puede remplazar por ferror(stdin).
    La sem�ntica de feof es que va a devolver un valor distinto de  0 si se encuentra en fin del archivo. Y la de ferror es que va a devolver un valor distinto de 0 si hay un error en el flujo del archivo.
    No son mutuamente excluyentes, puede pasar que  ferror me devuelva que hay un error y ese error se encuentre en la mitad del archivo, por lo tanto no estoy en el final del mismo.
    La pragm�tica en este caso es verificar que el archivo termine sin problemas.

6. El formato %.1f , va a escribir el valor de la variable como punto flotante, con 1 decimal luego de la coma.

7. Se castea la variable nl, ya que de no hacerlo el resultado final no seria el deseado, truncaria la parte entera de la divisi�n a 0. Si usamos el casteo la divisi�n se hace con coma flotante y el resultado es el deseado. 
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
      El condicional quedar�a de la siguiente manera : (nl==0 ? nl=0 :(nc / ((float)nl))). 
      Eval�a si la cantidad de lineas es 0 o no, en el caso de ser 0 se le asigna cero a nl si no hace la divisi�n.

11. No es precisa ya el programa esta contando los /n como caracteres para calcular el promedio final. 
      Para solucionarlo se puede implementar la siguiente estructura para el cuerpo del for:

 for(nl = 0, nc = 0; ( c = getchar()) != EOF;){
	if(c == '\n')
			++nl;
	if(c != '\n')
		++nc;
}
      Esta soluci�n solo incrementar�a la cantidad de caracteres (nc) son contar los enters(/n).

12. Solo hay que modificar printf o agregar uno nuevo en el programa ya que la cantidad de lineas est�n guardadas en la variable nl y la cantidad de caracteres en nc.
      El printf que se agregaria es: printf("Cantidad de lineas: %d\nCantidad de caracteres: %d\n",nl,nc);
