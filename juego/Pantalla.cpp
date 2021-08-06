#include "Pantalla.h"

void Pantalla::inicializar() {}

void Pantalla::addPanel(unique_ptr<PanelUI> uip,
	ControlRemotodelAdministradordePantalla* smrc,
	shared_ptr<ControladorEntrada> ih)
{
	ih->inicializarControladorEntrada(smrc,
		uip->getBotones(), &uip->vista_m, this);
	Paneles_m.push_back(move(uip));
	ControladoresEntrada_m.push_back(ih);
}

void Pantalla::manejar_entrada(RenderWindow& window)
{
	Event event;
	auto itr = ControladoresEntrada_m.begin();
	auto end = ControladoresEntrada_m.end();
	while (window.pollEvent(event))
	{
		for (itr; itr != end; ++itr)
		{
			(*itr)->manejar_entrada(window, event);
		}
	}
}

void Pantalla::update(float fps) {}

void Pantalla::draw(RenderWindow& window)
{
	auto itr = Paneles_m.begin();
	auto end = Paneles_m.end();
	for (itr; itr != end; ++itr)
	{
		(*itr)->draw(window);
	}
}

