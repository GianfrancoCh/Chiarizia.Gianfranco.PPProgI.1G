#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct {
	int id;
	char nombre[20];
	char tipo;
	float efectividad;

} eVacuna;

float aplicarAumento(float importe, int porcentaje);
int reemplazarCaracteres(char palabra, char letraA, char letraB);
int ordenarVacunas(eVacuna vac[], int tam);
int mostrarVacunas(eVacuna vac[], int tam);
void mostrarVacuna(eVacuna vac);

int main(void) {

	setbuf(stdout, NULL);
	eVacuna vacunas[TAM] = { { 1, "Sputnik", 'A', 98.5 },
			{ 2, "Pfizer", 'B', 67 }, { 3, "Astrazeneca", 'A', 86 } };

	mostrarVacunas(vacunas, TAM);
	ordenarVacunas(vacunas, TAM);
	mostrarVacunas(vacunas, TAM);

}

float aplicarAumento(float importe, int porcentaje) {
	float importeAumento;

	importeAumento = importe + ((importe * porcentaje / 100));

	return importeAumento;
}

int reemplazarCaracteres(char palabra, char letraA, char letraB) {

	int cantReemplazos = 0;
	int len;
	len = strlen(palabra);

	if (palabra != NULL) {

		for (int i = 0; i < len; i++) {
			if (palabra[i] == letraA) {
				palabra[i] = letraB;
				cantReemplazos++;
			}
		}
	}

	return cantReemplazos;

}

int ordenarVacunas(eVacuna vac[], int tam) {
	int todoOk = 0;
	eVacuna aux;

	if (vac != NULL && tam > 0) {
		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {
				if ((vac[i].tipo == vac[j].tipo)
						&& (vac[i].efectividad > vac[j].efectividad)) {
					aux = vac[i];
					vac[i] = vac[j];
					vac[j] = aux;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

void mostrarVacuna(eVacuna vac) {
	printf("%04d    ", vac.id);
	printf("%8s  ", vac.nombre);
	printf("%c  ", vac.tipo);
	printf("  %f    ", vac.efectividad);

}

int mostrarVacunas(eVacuna vac[], int tam) {
	int todoOk = 0;
	if (vac != NULL && tam > 0) {

		printf("***** LISTA DE VACUNAS *****\n");

		for (int i = 0; i < tam; i++) {

			mostrarVacuna(vac[i]);

		}
		todoOk = 1;
	}

	return todoOk;
}
