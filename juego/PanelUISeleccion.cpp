#include "PanelUISeleccion.h"

#include <iostream>

PanelUISeleccion::PanelUISeleccion(Vector2i res) :
	PanelUI(res,
	(res.x / 10) * 2,
		res.y / 3,
		(res.x / 10) * 6,
		res.y / 3,
		50, 255, 255, 255)
{
	BotonAncho_m = res.x / 20;
	BotonAlto_m = res.y / 20;
	BotonRelleno_m = res.x / 100;

	Texto_m.setFillColor(sf::Color(0, 255, 0, 255));
	Texto_m.setString("COVID INVADERS");

	Fuente_m.loadFromFile("fonts/Roboto-Bold.ttf");
	Texto_m.setFont(Fuente_m);

	Texto_m.setPosition(Vector2f(BotonRelleno_m,
		BotonAlto_m + (BotonRelleno_m * 2)));

	Texto_m.setCharacterSize(160);

	inicializarBotones();
}

void PanelUISeleccion::inicializarBotones()
{
	addBoton(BotonRelleno_m,
		BotonRelleno_m,
		BotonAncho_m,
		BotonAlto_m,
		0, 255, 0,
		"Play");

	addBoton(BotonAncho_m + (BotonRelleno_m * 2),
		BotonRelleno_m,
		BotonAncho_m,
		BotonAlto_m,
		255, 0, 0,
		"Salir");
}

void PanelUISeleccion::draw(RenderWindow& window)
{
	mostrar();
	PanelUI::draw(window);
	window.draw(Texto_m);
}
