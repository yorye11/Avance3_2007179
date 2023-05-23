#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>

using namespace std;


struct datos
{
	  int NumArt, ADL;
    float Precio, Impuesto, total;
    string NomVid, clasif, consola, genero, status;

    string caracteristicas;
    string descripcion;
};
int contador, alta;

datos* tienda;
void Alta();
void eliminar();
void listas();
void modificar();
void archivos();

int main()
{
	int opcion;
	 printf("----- Menú de Opciones -----\n");
        printf("1. Agregar Artículo\n");
        printf("2. Lista de articulos\n");
        printf("3. Limpiar pantalla \n");
        printf("4. Modificar videojuego\n");
        printf("5. Eliminar videojuego\n");
        printf("6. Salir\n");
        printf("----------------------------\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

	switch (opcion)
	{
	case 1:
		Alta();
		return main();
		break;

	case 2:
		listas();
		return main();
		break;

	case 3:
		system("cls"); //system("clear");
		return main();
		break;

	case 4:
		modificar();
		return main();
		break;

	case 5:
		eliminar();
		return main();
		break;

	case 6:
		archivos();
		break;
	}
}
void Alta()
{
	printf("cuantos videojuegos desea dar de alta? \n");
	scanf("%d", &alta);
	tienda = new datos[alta];
	for (int i = 0; i < alta; i++)
	{


	 printf("Ingrese numero de articulo: ");
    scanf("%d", &tienda[i].NumArt);
		
		while (getchar() != '\n'); //se vacia el buffer o el espacio o cin.ignore
		printf("Ingrese nombre del videojuego\n");
		getline(cin, tienda[i].NomVid); //permite los espacios en el nombre
		printf("Ingrese el año de lanzamiento: ");
		
scanf("%d", &tienda[i].ADL);
getchar();
	    printf("Ingrese el genero: ");
    char genero[100];
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].genero = genero;

    printf("Ingrese la clasificacion del videojuego: ");
    char clasif[100];
    fgets(clasif, sizeof(clasif), stdin);
    clasif[strcspn(clasif, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].clasif = clasif;

    printf("Ingrese la consola a la que pertenece: ");
    char consola[100];
    fgets(consola, sizeof(consola), stdin);
    consola[strcspn(consola, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].consola = consola;

    printf("Ingrese las caracteristicas: ");
    char caracteristicas[100];
    fgets(caracteristicas, sizeof(caracteristicas), stdin);
    caracteristicas[strcspn(caracteristicas, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].caracteristicas = caracteristicas;

    printf("Ingrese una breve descripcion del videojuego: ");
    char descripcion[100];
    fgets(descripcion, sizeof(descripcion), stdin);
    descripcion[strcspn(descripcion, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].descripcion = descripcion;
		 printf("Ingrese el precio del articulo: ");
    scanf("%f", &tienda[i].Precio);
	tienda[i].Impuesto= tienda[i].Precio * .16;	
printf("El impuesto es de %f\n", tienda[i].Impuesto);

tienda[i].total = tienda[i].Precio + tienda[i].Impuesto;
printf(" dando un total de %f\n",tienda[i].total);

}
}

void listas()
{
	for (int i = 0; i < alta; i++)
	{
		//if (matricula[i] == 0)
		if (tienda[i].status == "ELIMINADO")
		{
printf("REGISTRO ELIMINADO %d\n", i + 1);

		}
		else
		{
			printf("Registro %d\n", i + 1);

		printf("%d\n", tienda[i].NumArt);
 printf("Nombre del videojuego: %s\n", tienda[i].NomVid.c_str());
    printf("Año de lanzamiento: %d\n", tienda[i].ADL);
    printf("Género: %s\n", tienda[i].genero.c_str());
    printf("Clasificación: %s\n", tienda[i].clasif.c_str());
    printf("Consola: %s\n", tienda[i].consola.c_str());
    printf("Características: %s\n", tienda[i].caracteristicas.c_str());
    printf("Descripción: %s\n", tienda[i].descripcion.c_str());
    printf("Precio: %f\n", tienda[i].Precio);
    printf("Impuesto: %f\n", tienda[i].Impuesto);
    printf("Total: %f\n", tienda[i].total);

		}
	}
}
void eliminar()
{
	int j;
printf("Ingrese el registro a eliminar: ");
scanf("%d", &j);

	j = j - 1;
	for (int i = j; i == j; i++)
	{
		printf("Eliminando registro %d\n", j + 1);
		tienda[i].status = "ELIMINADO";
		/*
		matricula[i] = 0;
		nombre[i] = " ";
		calf[i] = 0;
		calflab[i] = 0;
		*/
	}
}
void modificar()
{
	int j, opcion, op2;
	do
	{
	printf("Ingrese el número de registro a modificar: ");
scanf("%d", &j);

		j = j - 1; // esto debido a que i inicia en 0

		for (int i = j; i == j; i++)
		{
			if ((tienda[i].status == "ELIMINADO"))
			{
				printf("REGISTRO ELIMINADO %d\n", i + 1);

				printf("ingrese un registro valido \n");
				op2 = 1;
			}
			else
			{
				op2 = 2;
			}
		}
	} while (op2 == 1);
printf("Ingrese qué desea modificar:\n 1.Numero de articulo\n 2. Nombre del videojuego\n 3.año de lanzamiento \n 4.Genero\n 5.Clasificacion \n 6. Consola\n 7.caracteristicas\n 8. Descripcion\n 9.Precio\n");
scanf("%d", &opcion);


	switch (opcion)
	{
	case 1:
		for (int i = j; i == j; i++)
		{
		printf("ingrese el numero de articulo");
			scanf("%d", &tienda[i].NumArt);
		}
		break;
	case 2:
		for (int i = j; i == j; i++)
		{
			while (getchar() != '\n'); //se vacia el buffer o el espacio
		printf("ingrese el nombre del videojuego");
			getline(cin, tienda[i].NomVid);
		}
		break;

	case 3:
		for (int i = j; i == j; i++)
		{
			printf("ingrese el año de lanzamiento ");
			scanf("%d", &tienda[i].ADL);
getchar();
		}
		
	case 4:
		for (int i = j; i == j; i++)
		{
		 printf("Ingrese el genero: ");
    char genero[100];
    fgets(genero, sizeof(genero), stdin);
    genero[strcspn(genero, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].genero = genero;
		}
		break;
		
		case 5:
		for (int i = j; i == j; i++)
		{
		 char clasif[100];
    fgets(clasif, sizeof(clasif), stdin);
    clasif[strcspn(clasif, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].clasif = clasif;
		}
		break;
		
		case 6:
		for (int i = j; i == j; i++)
		{
	  printf("Ingrese la consola a la que pertenece: ");
    char consola[100];
    fgets(consola, sizeof(consola), stdin);
    consola[strcspn(consola, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].consola = consola;
		}
		break;
		
		case 7:
		for (int i = j; i == j; i++)
		{
		printf("Ingrese las caracteristicas: ");
    char caracteristicas[100];
    fgets(caracteristicas, sizeof(caracteristicas), stdin);
    caracteristicas[strcspn(caracteristicas, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].caracteristicas = caracteristicas;
		}
		break;
		
		case 8:
		for (int i = j; i == j; i++)
		{
	 printf("Ingrese una breve descripcion del videojuego: ");
    char descripcion[100];
    fgets(descripcion, sizeof(descripcion), stdin);
    descripcion[strcspn(descripcion, "\n")] = '\0'; // Eliminar el carácter de nueva línea
    tienda[i].descripcion = descripcion;
		}
		break;
		
		case 9:
		for (int i = j; i == j; i++)
		{
		 printf("Ingrese el precio del articulo: ");
    scanf("%f", &tienda[i].Precio);
	tienda[i].Impuesto= tienda[i].Precio * .16;	
printf("El impuesto es de %f\n", tienda[i].Impuesto);

tienda[i].total = tienda[i].Precio + tienda[i].Impuesto;
printf(" dando un total de %f\n",tienda[i].total);

		}
		break;
		
	
	}


}

void archivos()
{
    ofstream archivo;
    string nombrearchivo;
    int texto;
    string texto2;

    nombrearchivo = "gamesquad.txt";

    archivo.open(nombrearchivo.c_str(), ios::out);

    if (archivo.fail())
    {
        cout << "ERROR NO SE PUDO CREAR EL ARCHIVO";
        exit(1);
    }

    archivo << "Num de articulo" << "\t";
    archivo << "Nom del videojuego" << "\t";
    archivo << "Año de lanzamiento" << "\t";
    archivo << "Genero" << "\t";
    archivo << "Clasificacion" << "\t";
    archivo << "Consola" << "\t";
    archivo << "Caracteristicas" << "\t";
    archivo << "Descripcion" << "\t";
    archivo << "Precio" << "\t";
    archivo << "Impuestos" << "\t";
    archivo << "Total" << "\n";

    for (int i = 0; i < alta; i++)
    {
         if (tienda[i].status == "ELIMINADO")
        {
            texto2 = "REGISTRO ELIMINADO ";
            texto = i;
            archivo << texto2 << texto << "\n";
        }
        else
        {
            texto = tienda[i].NumArt;
            archivo << texto << "\t \t \t";
            texto2 = tienda[i].NomVid;
            archivo << texto2 << "\t \t \t";
            texto = tienda[i].ADL;
            archivo << texto << "\t \t \t";
            texto2 = tienda[i].genero;
            archivo << texto2 << "\t \t \t";
            texto2 = tienda[i].clasif;
            archivo << texto2 << "\t \t \t";
            texto2 = tienda[i].consola;
            archivo << texto2 << "\t \t \t";
            texto2 = tienda[i].caracteristicas;
            archivo << texto2 << "\t \t \t";
            texto2 = tienda[i].descripcion;
            archivo << texto2 << "\t \t \t";
            texto = tienda[i].Precio;
            archivo << texto << "\t \t \t";
            texto2 = tienda[i].Impuesto;
            archivo << texto << "\t \t \t";
            texto = tienda[i].total;
            archivo << texto << "\n";
        }
    }

    archivo.close();
}




	