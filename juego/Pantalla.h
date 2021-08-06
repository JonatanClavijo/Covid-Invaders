#pragma once
#ifndef PANTALLA_H
#define PANTALLA_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "ControladorEntrada.h"
#include "PanelUI.h"
#include "ControlRemotodelAdministradordePantalla.h"

class ControladorEntrada;

class Pantalla {
private:
	vector<shared_ptr<ControladorEntrada>> ControladoresEntrada_m;
	vector<unique_ptr<PanelUI>> Paneles_m;

protected:
	void addPanel(unique_ptr<PanelUI> p,
		ControlRemotodelAdministradordePantalla* smrc,
		shared_ptr<ControladorEntrada> ih);

public:
	virtual void inicializar();
	void virtual update(float fps);
	void virtual draw(RenderWindow& window);
	void manejar_entrada(RenderWindow& window);

	View vista_m;
};
#endif
