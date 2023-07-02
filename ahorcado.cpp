#include <iostream>
#include <cstdlib>
#include <string.h>
#include <random>

using namespace std;

string frutas[] = { "banano", "ochuva", "manzana", "mango" };
string deportes[] = {"futbol", "tenis", "ciclismo", "golf"};
string paises[] = { "bolivia","colombia","argentina","rusia"};//CaseSensitive, debe ser full minúscula

string temas[] = { "Frutas", "Deportes", "Paises" };
int vidas = 5;
int cantidadCaracteresTexto = 0;
string palabraEscogida;

char letra;
char palabraCensurada[25];

void censurarPalabra(); //Función que agarra la palabra y convierte cada caracter en _
void seleccionarTema(); //Función para seleccionar el tema a jugar
void randomizarPalabra(); //Función para escoger una palabra al azar en base los temas

bool existeLetra = false;

int main()
{
	seleccionarTema();
	randomizarPalabra();
	censurarPalabra();
	cout << palabraCensurada << endl;
	while (vidas > 0) {

		cout << "Ingrese una letra: ";
		cin >> letra;
		cin.ignore();
		system("cls");
		for (int i = 0; i < cantidadCaracteresTexto; i++) {
			if (palabraEscogida[i] == letra) {
				palabraCensurada[i] = letra;
				
			}
			
			else {
				for (int j = 0; j < cantidadCaracteresTexto; j++) {
					if (palabraEscogida[j] == letra) {
						existeLetra = true;
						break;
					}
				}
				if (existeLetra != true) {
					vidas--;
					cout << "Uh, esta letra no se encuentra en la palabra"<<endl<<vidas <<" vidas restantes..."<<endl;
					break;
				}
				existeLetra = false;
			}
			
		}
		cout << palabraCensurada << endl;
		if (palabraCensurada == palabraEscogida) {
			cout << "Felicidades, ganaste con " << vidas << " vidas restantes.";
			break;
		}
	}
	cout << "Perdiste, la palabra secreta era: " << palabraEscogida;
	
	
}


void censurarPalabra() {
	for (int i = 0; i < cantidadCaracteresTexto; i++) {
		palabraCensurada[i] = '_';
	}
	
}
int opcionTema = 0;
void seleccionarTema() {
	cout << "Selecciona el tema el cual quieres jugar: \n";
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << ". " << temas[i]<<endl;
	}
	cin >> opcionTema;
	system("cls");
}

void randomizarPalabra() {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<> dis(0, 3);	
	int randomNumber = dis(gen);

	
	switch (opcionTema)
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
	cantidadCaracteresTexto = palabraEscogida.size();
}




