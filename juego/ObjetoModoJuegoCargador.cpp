#include "ObjetoModoJuegoCargador.h"
#include "ObjetoEtiquetas.h"
#include <iostream>
#include <fstream>

void ObjetoModoJuegoCargador::
CargarObjetosJuegoParaModoJuego(
	string RutaArchivo, vector<ObjetosJuego>& ObjetosJuego_m)
{
	ifstream reader(RutaArchivo);
	string Linea_Archivo;

	float x = 0, y = 0, ancho = 0, alto = 0;
	string valor = "";
	while (getline(reader, Linea_Archivo)) {
		if (Linea_Archivo.find(
			ObjetoEtiquetas::START_OF_OBJECT) != string::npos) {

			ObjetoJuegoPlano bp;
			BOP_m.SiguienteObjetoPlanoAnalizar(reader, bp);
			ObjetoJuegoFactoryModoJuego_m.ConstruirObjetoJuego(
				bp, ObjetosJuego_m);
		}
	}
}


