#include "PanelUIJuegoTerminado.h"
#include "PantallaJuego.h"

bool PantallaJuego::JuegoTerminado_m;

PanelUIJuegoTerminado::PanelUIJuegoTerminado(Vector2i res) :
	PanelUI(res,
	(res.x / 10) * 3,
		res.y / 2,
		(res.x / 10) * 3,
		res.y / 6,
		50, 255, 255, 255)
{
	BotonAncho_m = res.x / 20;
	BotonAlto_m = res.y / 20;
	BotonRelleno_m = res.x / 100;

	Texto_m.setFillColor(sf::Color(0, 255, 0, 255));
	Texto_m.setString("GAME OVER!");

	Fuente_m.loadFromFile("fonts/Roboto-Bold.ttf");
	Texto_m.setFont(Fuente_m);

	Texto_m.setPosition(Vector2f(BotonRelleno_m,
		(BotonRelleno_m * 2) + BotonAlto_m));

	Texto_m.setCharacterSize(60);

	inicializarBotones();
}

void PanelUIJuegoTerminado::inicializarBotones()
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
		"Home");
}

void PanelUIJuegoTerminado::draw(RenderWindow& window)
{
	if (PantallaJuego::JuegoTerminado_m)
	{
		mostrar();
		PanelUI::draw(window);
		window.draw(Texto_m);
	}
	else
	{
		esconder();
	}
}
