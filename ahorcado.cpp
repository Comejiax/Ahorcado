#include <iostream>
#include <string.h>
#include <random>
#include <stdlib.h>
#include <time.h>

using namespace std;
//Categorías

/*Deben de ser Arrays de tipo string*/
string frutas[] = { "banano", "ochuva", "manzana", "mango" };
string deportes[] = {"futbol", "tenis", "ciclismo", "golf"};
string paises[] = { "bolivia","colombia","argentina","rusia"};//CaseSensitive, debe ser full minúscula

string humanito[] = { "   (X_X)", "    /|\\", "  /  |  \\", "     |","    / \\", "   /...\\"};
int vidaHumanito = 0;

string temas[] = { "Frutas", "Deportes", "Paises" };


int vidas = 6; //Vidas del jugador
int cantidadCaracteresTexto = 0; //Variable que toma el tamaño de caracteres que tiene un elemento de los arrays de temas
string palabraEscogida; //Variable que toma un elemento al azar del tema escogido

char letra; //Letra que el usuario irá escogiendo
 



bool existeLetra = false; //Variable booleana que determinará si existe esa letra en el contexto de la palabra escogida
bool salir = false;
int continuarGame = 0;

int main()
{
	while (salir == false) {
		char palabraCensurada[25] = ""; //Array de caracteres que agarra la palabra escogida y cambia sus caracteres por guiones bajo_
		int opcionTema = 0;
		cout << "   ##     ##  ##    ####    #####     ####      ##     ####      ####\n####    ##  ##   ##  ##   ##  ##   ##  ##    ####    ## ##    ##  ##\n##  ##   ##  ##   ##  ##   ##  ##   ##       ##  ##   ##  ##   ##  ##\n######   ######   ##  ##   #####    ##       ######   ##  ##   ##  ##\n##  ##   ##  ##   ##  ##   ####     ##       ##  ##   ##  ##   ##  ##\n##  ##   ##  ##   ##  ##   ## ##    ##  ##   ##  ##   ## ##    ##  ##\n##  ##   ##  ##    ####    ##  ##    ####    ##  ##   ####      ####\n\n\n";
		cout << "+-+-----|\n";
		cout << "+ +-----|\n";
		for (int i = 0; i < vidas; i++) {
			cout << "| |" << humanito[i] << endl;
		}
		cout << "Bienvenid@ al juego de AHORCADO, selecciona el tema el cual quieras jugar. \n\n\n\n";
		cout << "Selecciona el tema el cual quieres jugar: \n";
		for (int i = 0; i < 3; i++) {	 //Recorrerá el array de temas y mostrará uno por uno sus elementos, SI AÑADISTE NUEVOS ELEMENTOS DEBERÁS DE MODIFICAR EL NÚMERO DE LA CONDICIÓN (i<3)
			cout << i + 1 << ". " << temas[i] << endl << endl;
		}
		cout << "0. Salir " << endl << endl;
		cin >> opcionTema; //Agarra la opción que el usuario mete
		if (opcionTema == 0) {
			cout << "Has salido del juego. ";
			break;
		}
		system("cls"); //Limpia consola


		srand(time(NULL));
		int randomNumber = 0 + rand() % (4); //Generación de número aleatorio


		switch (opcionTema) //Evalúa la opción seleccionado por el usuario y guarda en palabra escogida un elemento al azar en base a ese número aleatorio
		{
		case 1:
			//fruta
			palabraEscogida = frutas[randomNumber];
			break;

		case 2:
			//deporte
			palabraEscogida = deportes[randomNumber];
			break;

		case 3:
			//pais
			palabraEscogida = paises[randomNumber];
			break;
		default:
			break;
		}
		cantidadCaracteresTexto = palabraEscogida.size(); //Determina el número de caracteres que tiene esa palabra escogida para luego poder recorrerla sin problemas

		//Itera el tamaño del texto y lo convierte en _ censurándolo
		for (int i = 0; i < cantidadCaracteresTexto; i++) {
			palabraCensurada[i] = '_';
		}

		for (int i = 0; i < cantidadCaracteresTexto; i++) {
			cout << palabraCensurada[i] <<" ";
		}
		cout << "\n";

		
		while (vidas > 0) { //Bucle mientras las vidas sea mayor a 0
			

			cout << "Ingrese una letra: ";
			cin >> letra;
			cin.ignore();
			system("cls");
			for (int i = 0; i < cantidadCaracteresTexto; i++) { //Recorre un array que es la palabra escogida y por eso tenemos el tamaño de esa palabra
				if (palabraEscogida[i] == letra) { //Si la palabra escogida en su caracter i es igual a la letra añadida por el usuario actualiza la palabra censurada cambiando _ por la letra donde corresponde
					palabraCensurada[i] = letra;
				}
				else { //sino itera nuevamente esa palabra y hace un barrido verificando si la letra existe en el contexto de ese texto, si sí torna la variable existeLetra en true y rompe el for porque solo basta con que ya le atine
					for (int j = 0; j < cantidadCaracteresTexto; j++) {
						if (palabraEscogida[j] == letra) {
							existeLetra = true;
							break;
						}
					}
					if (existeLetra != true) { //Si la variable booleana es falsa significa que en el contexto de esa palabra no existe la letra que añadimos, quitándonos 1 vida y mostrando un mensaje de feedback
						vidas--;
						vidaHumanito++;
						cout << "Uh, esta letra no se encuentra en la palabra" << endl << vidas << " vidas restantes..." << endl << endl << endl;
						cout << "+-+-----|\n";
						cout << "+ +-----|\n";
						for (int i = 0; i < vidaHumanito; i++) {
							cout <<"| |" << humanito[i] << endl;
						}
						cout<<endl << endl;
						break;
					}
					existeLetra = false; //reinicia la variable a false;
				}
			}
			
			if (palabraCensurada == palabraEscogida) { //Evalúa si la palabra censurada es igual a la palabra escogida, si son iguales significa que ganó :D
				cout << "Felicidades, ganaste con " << vidas << " vidas restantes." << endl << endl << endl;
				cout << "  ####      ##     ##  ##     ##      ####    ######   ######\n##  ##    ####    ### ##    ####    ##  ##     ##     ##\n##       ##  ##   ######   ##  ##   ##         ##     ##\n## ###   ######   ######   ######    ####      ##     ####\n##  ##   ##  ##   ## ###   ##  ##       ##     ##     ##\n##  ##   ##  ##   ##  ##   ##  ##   ##  ##     ##     ##\n####    ##  ##   ##  ##   ##  ##    ####      ##     ######" << endl << endl << endl;
				break;
			}
			cout << "Desea continuar?" << endl << "1. Si" << endl << "2. No: ";
			cin >> continuarGame;
			system("cls");
			if (continuarGame == 2) {
				break;
			}
			for (int i = 0; i < cantidadCaracteresTexto; i++) {
				cout << palabraCensurada[i] << " ";//después de cada iteración muestra la palabra censurada actualizada
			}
			cout << "\n";
			
		}
		if (vidas <= 0) {
			cout << "Perdiste, la palabra secreta era: " << palabraEscogida<<endl << endl << endl; //Si la vida <= 0 perdió y se sale del bucle, indicando que perdió
			cout<<" #####    ######   #####    ####      ####     ####    ######   ######\n##  ##   ##       ##  ##   ## ##      ##     ##  ##     ##     ##\n##  ##   ##       ##  ##   ##  ##     ##     ##         ##     ##\n#####    ####     #####    ##  ##     ##      ####      ##     ####\n##       ##       ####     ##  ##     ##         ##     ##     ##\n##       ##       ## ##    ## ##      ##     ##  ##     ##     ##\n##       ######   ##  ##   ####      ####     ####      ##     ######" << endl << endl << endl << endl << endl << endl;
		}
		vidas = 5;
		vidaHumanito = 0;
		system("pause");
		system("cls");

	}
	
}