#pragma once
#ifndef ADMINISTRADORDEPANTALLA_H
#define ADMINISTRADORDEPANTALLA_H

#include <SFML/Graphics.hpp>
#include <map>
#include "PantallaJuego.h"
#include "ControlRemotodelAdministradordePantalla.h"
#include "PantallaSeleccion.h"
#include "AdministradorNivel.h"
#include "TiendadeMapadeBits.h"
#include <iostream>

using namespace sf;
using namespace std;

class AdministradordePantalla : public ControlRemotodelAdministradordePantalla {
private:
	map <string, unique_ptr<Pantalla>> Pantallas_m;
	AdministradorNivel AdministradordeNivel_m;

protected:
	string PantallaActual_m = "Seleccione";

public:
	TiendadeMapadeBits TMB_m;

	AdministradordePantalla(Vector2i res);
	void update(float fps);
	void draw(RenderWindow& window);
	void manejo_entrada(RenderWindow& window);

	void CambiarPantallas(string pantalla_para_Cambiar_a)
	{
		PantallaActual_m = "" + pantalla_para_Cambiar_a;
		Pantallas_m[PantallaActual_m]->inicializar();
	}

	void NiveldeCargaenMododeJuego(string PantallaParaCargar)
	{
		AdministradordeNivel_m.getObjetosdelJuego().clear();
		AdministradordeNivel_m.
			CargarObjetosJuegoParaModoJuego(PantallaParaCargar);
		CambiarPantallas("Juego");
	}

	vector<ObjetosJuego>& getObjetosdelJuego()
	{
		return AdministradordeNivel_m.getObjetosdelJuego();
	}

	CompartidordeObjetosdeJuego& compartirCompartidordeObjetosdeJuego()
	{
		return AdministradordeNivel_m;
	}
};

#endif
