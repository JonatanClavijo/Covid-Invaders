#include "ObjetoPlanoAnalizador.h"
#include "ObjetoEtiquetas.h"
#include <iostream>
#include <fstream>

void ObjetoPlanoAnalizador::SiguienteObjetoPlanoAnalizar(
	ifstream& reader, ObjetoJuegoPlano& bp)
{
	string linea_Archivo;
	string valor = "";

	while (getline(reader, linea_Archivo)) {

		if (linea_Archivo.find(ObjetoEtiquetas::COMPONENT)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::COMPONENT,
				ObjetoEtiquetas::COMPONENT_END);

			bp.addAListaComponente(valor);
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::NAME)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::NAME, ObjetoEtiquetas::NAME_END);

			bp.setNombre(valor);
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::WIDTH)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::WIDTH, ObjetoEtiquetas::WIDTH_END);

			bp.setAncho(stof(valor));
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::HEIGHT)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::HEIGHT, ObjetoEtiquetas::HEIGHT_END);

			bp.setAlto(stof(valor));
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::LOCATION_X)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::LOCATION_X,
				ObjetoEtiquetas::LOCATION_X_END);

			bp.setLocationX(stof(valor));
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::LOCATION_Y)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::LOCATION_Y, ObjetoEtiquetas::LOCATION_Y_END);

			bp.setLocationY(stof(valor));
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::BITMAP_NAME)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::BITMAP_NAME, ObjetoEtiquetas::BITMAP_NAME_END);
			bp.setBitmapNombre(valor);
		}

		else if (linea_Archivo.find(
			ObjetoEtiquetas::ENCOMPASSING_RECT_COLLIDER)
			!= string::npos) {

			valor = extraerStringEntreTags(linea_Archivo,
				ObjetoEtiquetas::ENCOMPASSING_RECT_COLLIDER,
				ObjetoEtiquetas::ENCOMPASSING_RECT_COLLIDER_END);

			bp.setAbarcandoColisionadorRect(valor);
		}

		else if (linea_Archivo.find(ObjetoEtiquetas::END_OF_OBJECT)
			!= string::npos) {

			return;
		}
	}

}

string ObjetoPlanoAnalizador::extraerStringEntreTags(
	string stringParaBuscar, string TagInicio, string TagFin)
{
	int inicio = TagInicio.length();
	int count = stringParaBuscar.length() - TagInicio.length()
		- TagFin.length();

	string StringEntreTags = stringParaBuscar.substr(
		inicio, count);

	return StringEntreTags;
}

