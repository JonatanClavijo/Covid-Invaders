#pragma once
#ifndef CONTROLADORENTRADA_H
#define CONTROLADORENTRADA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Boton.h"
#include "Pantalla.h"
#include "ControlRemotodelAdministradordePantalla.h"

using namespace sf;
using namespace std;

class Pantalla;

class ControladorEntrada
{
private:
	Pantalla* pantallaPadre_m;
	vector<shared_ptr<Boton>> Botones_m;
	View* punteroalaVistadePanelUI_m;
	ControlRemotodelAdministradordePantalla* ControlRemotodelAdministradordePantalla_m;

public:
	void inicializarControladorEntrada(
		ControlRemotodelAdministradordePantalla* sw,
		vector<shared_ptr<Boton>>,
		View* punteroalaVistadeIU,
		Pantalla* pantallaPadre);

	void manejar_entrada(RenderWindow& window, Event& event);

	virtual void manejar_Gamepad();
	virtual void manejar_TeclaPresionada(Event& event,
		RenderWindow& window);

	virtual void manejar_TeclaLiberada(Event& event,
		RenderWindow& window);

	virtual void manejar_ClickIzquierdo(string& botonInteraccioncon,
		RenderWindow& window);

	View* getpunteroalaVistadeIU();
	ControlRemotodelAdministradordePantalla*
		getPunteroaControlRemotodelAdministradordePantalla();

	Pantalla* getmpantalladePadres();
};

#endif
