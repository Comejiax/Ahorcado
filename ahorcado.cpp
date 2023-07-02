#include <iostream>
#include <string.h>
#include <random>

using namespace std;
//Categorías

/*Deben de ser Arrays de tipo string*/
string frutas[] = { "banano", "ochuva", "manzana", "mango" };
string deportes[] = {"futbol", "tenis", "ciclismo", "golf"};
string paises[] = { "bolivia","colombia","argentina","rusia"};//CaseSensitive, debe ser full minúscula



string temas[] = { "Frutas", "Deportes", "Paises" };


int vidas = 5; //Vidas del jugador
int cantidadCaracteresTexto = 0; //Variable que toma el tamaño de caracteres que tiene un elemento de los arrays de temas
string palabraEscogida; //Variable que toma un elemento al azar del tema escogido

char letra; //Letra que el usuario irá escogiendo
char palabraCensurada[25]; //Array de caracteres que agarra la palabra escogida y cambia sus caracteres por guiones bajo_

void censurarPalabra(); //Función que agarra la palabra y convierte cada caracter en _
void seleccionarTema(); //Función para seleccionar el tema a jugar
void randomizarPalabra(); //Función para escoger una palabra al azar en base los temas

bool existeLetra = false; //Variable booleana que determinará si existe esa letra en el contexto de la palabra escogida

int main()
{
	seleccionarTema(); 
	randomizarPalabra();
	censurarPalabra();
	cout << palabraCensurada << endl;
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
					cout << "Uh, esta letra no se encuentra en la palabra"<<endl<<vidas <<" vidas restantes..."<<endl;
					break;
				}
				existeLetra = false; //reinicia la variable a false;
			}
			
		}
		cout << palabraCensurada << endl; //después de cada iteración muestra la palabra censurada actualizada
		if (palabraCensurada == palabraEscogida) { //Evalúa si la palabra censurada es igual a la palabra escogida, si son iguales significa que ganó :D
			cout << "Felicidades, ganaste con " << vidas << " vidas restantes.";
			break;
		}
	}
	cout << "Perdiste, la palabra secreta era: " << palabraEscogida; //Si la vida <= 0 perdió y se sale del bucle, indicando que perdió
	
	
}


void censurarPalabra() { //Itera el tamaño del texto y lo convierte en _ censurándolo
	for (int i = 0; i < cantidadCaracteresTexto; i++) {
		palabraCensurada[i] = '_';
	}
	
}



int opcionTema = 0; 
void seleccionarTema() { 
	cout << "Selecciona el tema el cual quieres jugar: \n"; 
	for (int i = 0; i < 3; i++) {	 //Recorrerá el array de temas y mostrará uno por uno sus elementos, SI AÑADISTE NUEVOS ELEMENTOS DEBERÁS DE MODIFICAR EL NÚMERO DE LA CONDICIÓN (i<3)
		cout << i + 1 << ". " << temas[i]<<endl;
	}
	cin >> opcionTema; //Agarra la opción que el usuario mete
	system("cls"); //Limpia consola
}

void randomizarPalabra() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);	
	int randomNumber = dis(gen); //Generación de número aleatorio, lo vi más sencillo que el rand()zzzz

	
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
}




