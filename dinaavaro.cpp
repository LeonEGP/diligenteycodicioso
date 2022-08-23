// ---------- DATOS DE ENTREGA ---------- //
//Programa que: Implementa la Técnica de Programación Dinámica y los Algoritmos.
//Programadores: León Emiliano García Pérez [A00573074], Carla Morales López [A01639225].
//Fechad de entrega: Martes 23 de Agosto de 2022.

//Inclusión de librerías.
#include <iostream>
#include <vector>
#include <algorithm>

//Ajuste a estandar.
using namespace std;

//Función que imprime en consola un salto de línea, no recibe parámetros y no tiene valor de retorno.
void espacio() { //Complejidad Computacional O(1).
	cout << endl;
}

//Función que implementa programación dinámica con el fin de dar la cantidad de posibilidades de cambio, recibe un vector de enteros con las posibles denominaciones de vuelto, un entero con el precio del producto y un entero con el valor del billete/moneda de pago. No tiene valor de retorno.
void dynamic(vector<int> denominaciones, int p, int q) { //Complejidad computacional O(nm), siendo n la cantidad de denominaciones, y siendo m la cantidad de posibilidades. 
	
	int cambio;
	cambio = q - p;

	sort(denominaciones.begin(), denominaciones.end());

	vector <int> formas(cambio + 1);

	formas[0] = 1;

	for (int i = 0; i < denominaciones.size(); i++) {

		for (int j = 0; j < formas.size(); j++) {

			if (denominaciones[i] <= j) {
				formas[j] += formas[(j - denominaciones[i])];
			}

		}

	}

	cout << "SE TIENE LA SIGUIENTE CANTIDAD DE POSIBILIDADES PARA DEVOLVER CAMBIO: " << endl;
	cout << formas[cambio] << "formas" << endl;
}

//Función que implementa un algoritmo avaro con el fin de dar el mínimo de monedas de cambio, recibe un vector de enteros con las posibles denominaciones de vuelto, un entero con el precio del producto y un entero con el valor del billete/moneda de pago. No tiene valor de retorno.
void greedy(vector<int> denominaciones, int p, int q) { //Complejidad computacional O(n), siendo n el número de denominaciones. 

	//Declaración/Inicialización de variables.
	int cambio;
	int cambioOriginal;
	int contador;
	vector <int> vuelto;

	cambio = q - p;
	cambioOriginal = cambio;

	//Ordenamiento del vector con las denominaciones.
	sort(denominaciones.begin(), denominaciones.end());

	// Buscando saber cantidad de cada denominación del vuelto.
	for (int i = (denominaciones.size()) - 1; i >= 0; i--) {

		contador = 0;

		while (cambio >= denominaciones[i]) {
			cambio -= denominaciones[i];
			contador++;
		}

		vuelto.push_back(contador);
	}

	//Ordenamiento inverso del vector de denominaciones con el fin de impresión de resultado
	reverse(denominaciones.begin(), denominaciones.end());

	//Impresión del vector resultante

	cout << "El cambio es de: " << cambioOriginal << endl;

	for (int j = 0; j < vuelto.size(); j++) {
		cout << denominaciones[j] << " : " << vuelto[j] << endl;
	}

	cout << "Falta devolver [por carencia de denominacion]: " << cambio << endl;
}

//Función main que ejecuta el programa, no recibe parámetros, retorna un entero [return 0].
int main() { //Complejidad Computacional O(1).

	// ---------- DECLARACIÓN DE VARIABLES ---------- //

	int n; //Cantidad de denominaciones.
	vector <int> denominaciones; //Vector que almacena las posibles denominaciones.
	int auxiliar; //Valor momentaneo de denominación ingresado. 
	int p; //Precio del producto dado.
	int q; //Billete con el que se paga dicho producto.

	// ---------- INICIA PROGRAMA ---------- //

	espacio();

	cout << " --- BIENVENIDO AL SISTEMA DE CAMBIO ---" << endl;

	espacio();

	cout << "Favor de ingresar la cantidad de denominaciones a manejar: " << endl;
	cin >> n;

	espacio();

	cout << "Favor de ingresar los valores enteros de dichas denominaciones: " << endl;

	for (int i = 0; i < n; i++) {
		cin >> auxiliar;
		denominaciones.push_back(auxiliar);
	}

	espacio();

	cout << "Favor de ingresar el precio del producto: " << endl;
	cin >> p;

	espacio();

	cout << "Favor de ingresar el valor del billete / moneda de pago: " << endl;
	cin >> q;

	// ---------- DETECCIÓN DE ERRORES PROGRAMA ---------- //

	if (q < p) {
		espacio();
		cout << " --- SE HA DETECTADO UN ERROR EN CAPTURA DE DATOS, SALIENDO DEL PROGRAMA [PAGO MENOR AL PRECIO] ---" << endl;
		espacio();
		return 0;
	}

	espacio();

	cout << " --- EJECUTANDO SOLUCION POR PROGRAMACION DINAMICA ---" << endl;

	espacio();

	dynamic(denominaciones, p, q); //SOLUCIÓN POR PROGRAMACIÓN DINÁMICA --- PENDIENTE DESARROLLO

	espacio();

	cout << " --- EJECUTANDO SOLUCION POR ALGORITMO AVARO ---" << endl;

	espacio();

	greedy(denominaciones, p, q); //SOLUCIÓN POR PROGRAMACIÓN DINÁMICA

	espacio();

	// ---------- TERMINA PROGRAMA ---------- //

	cout << "--- SALIENDO DEL SISTEMA DE CAMBIO ---" << endl;

	return 0;
}