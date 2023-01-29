// PruebaOMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <omp.h>

#define N 1000  // Ser� la cantidad de elementos a manejar en los arreglos
#define chunk 100 //Ser� el tama�o que tendr�n los pedazos de los arreglos para que cada hilo creado se encargue de esta cantidad de elementos
#define mostrar 10 //Permitir� manejar la cantidad de datos a imprimir

void imprimeArreglo(float *d); // funci�n que se encargue de imprimir los arreglos



int main()
{
    std::cout << "Sumando arreglos en paralelo! \n";
	float a[N], b[N], c[N]; //3 arreglos, llamados a, b y c, los dos primeros ser�n utilizados para asignarles los valores que pueden ser aleatorios,y el tercer arreglo llamado c servir� para almacenar el resultado de la suma de los dos primeros.
	int i;

	for (i = 0; i < N; i++) // declaramos los arreglos de un tama�o N (constante que definimos previamente) y asignamos valores a los arreglos a y b realizando un c�lculo sencillo
	{
		a[i] = i * 10;
		b[i] = (i + 3) * 3.7;

	}
	
	int pedazos = chunk;

    #pragma omp parallel  for \
    shared(a, b, c, pedazos) private (i) \
    schedule(static, pedazos) // La parte m�s importante de la pr�ctica es el procedimiento que se encarga de crear los hilos y ejecutar las operaciones de manera paralela.  Esto es bastante sencillo con la librer�a OpenMP.

	for (i = 0; i < N; i++)
	   c[i] = a[i] + b[i]; // Ahora pudes colocar la instrucci�n for como si fuera una suma de arreglos com�n, pero en realidad ya todo est� configurado para que se ejecute en paralelo
	
	    std::cout << "IMprimiendo los primeros \n" << mostrar << "valores de arreglo a:" << std::endl;
	    imprimeArreglo(a);
		std::cout << "IMprimiendo los primeros \n" << mostrar << "valores de arreglo b:" << std::endl;
		imprimeArreglo(b);
		std::cout << "IMprimiendo los primeros \n" << mostrar << "valores de arreglo c:" << std::endl;
		imprimeArreglo(c);
	}

void imprimeArreglo(float *d) //podemos imprimir parte de los arreglos a y b as� como el resultado de la suma almacenado en el arreglo c, esta impresi�n ser� apoyada por la funci�n imprimeArreglo
{
	
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << "-";
	std::cout << std::endl;
}








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
