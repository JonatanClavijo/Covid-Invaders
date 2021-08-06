#include "AdministradordePantalla.h"

AdministradordePantalla::AdministradordePantalla(Vector2i res)
{
	Pantallas_m["Juego"] = unique_ptr<PantallaJuego>(
		new PantallaJuego(this, res));

	Pantallas_m["Seleccione"] = unique_ptr<PantallaSeleccion>(
		new PantallaSeleccion(this, res));
}

void AdministradordePantalla::manejo_entrada(RenderWindow& window)
{
	Pantallas_m[PantallaActual_m]->manejar_entrada(window);
}

void AdministradordePantalla::update(float fps)
{
	Pantallas_m[PantallaActual_m]->update(fps);
}

void AdministradordePantalla::draw(RenderWindow& window)
{
	Pantallas_m[PantallaActual_m]->draw(window);
}
