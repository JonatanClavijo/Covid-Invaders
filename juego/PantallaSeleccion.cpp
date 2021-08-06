#include "PantallaSeleccion.h"
#include "PanelUISeleccion.h"
#include "ControladorEntradaSeleccion.h"

PantallaSeleccion::PantallaSeleccion(
	ControlRemotodelAdministradordePantalla* smrc, Vector2i res)
{
	auto suip = make_unique<PanelUISeleccion>(res);
	auto sih = make_shared<ControladorEntradaSeleccion>();
	addPanel(move(suip), smrc, sih);
	ControlRemotodelAdministradordePantalla_m = smrc;

	FondoTexture_m.loadFromFile("graphics/fondo.png");

	FondoSprite_m.setTexture(FondoTexture_m);
	auto textureSize = FondoSprite_m.getTexture()->getSize();

	FondoSprite_m.setScale(float(
		vista_m.getSize().x) / textureSize.x,
		float(vista_m.getSize().y) / textureSize.y);
}

void PantallaSeleccion::draw(RenderWindow& window)
{
	window.setView(vista_m);
	window.draw(FondoSprite_m);

	Pantalla::draw(window);
}
