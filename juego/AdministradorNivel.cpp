#include "AdministradorNivel.h"
#include "ObjetoModoJuegoCargador.h"
#include <iostream>

void AdministradorNivel::
CargarObjetosJuegoParaModoJuego(string Cargar_pantalla)
{
	ObjetosJuego_m.clear();
	string Cargar_Nivel = ""
		+ WORLD_FOLDER + SLASH + Cargar_pantalla;

	ObjetoModoJuegoCargador pmol;
	pmol.CargarObjetosJuegoParaModoJuego(
		Cargar_Nivel, ObjetosJuego_m);

	EjecutarFaceInicio();
}

vector<ObjetosJuego>& AdministradorNivel::getObjetosdelJuego()
{
	return ObjetosJuego_m;
}

void AdministradorNivel::EjecutarFaceInicio()
{
	auto it = ObjetosJuego_m.begin();
	auto end = ObjetosJuego_m.end();
	for (it; it != end; ++it)
	{
		(*it).iniciar(this);
	}

	ActivarTodosObjetosJuego();
}

void AdministradorNivel::ActivarTodosObjetosJuego()
{
	auto it = ObjetosJuego_m.begin();
	auto end = ObjetosJuego_m.end();
	for (it; it != end; ++it)
	{
		(*it).setActivo();
	}
}
