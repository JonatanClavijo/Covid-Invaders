#include "Boton.h"

Boton:: Boton(Vector2f posicion,
            float ancho, float alto,
            int rojo, int verde, int azul,
            std::string texto)
{
	Boton_m.setPosition(posicion);
	Boton_m.setFillColor(sf::Color(rojo, verde, azul));
	Boton_m.setSize(Vector2f(ancho, alto));

	Texto_m = "" + texto;

	float rellenotextoX = ancho / 10;
	float rellenotextoY = alto / 10;
	BotonTexto_m.setCharacterSize(alto * .7f);
	BotonTexto_m.setString(texto);
	Fuente_m.loadFromFile("fonts/Roboto-Bold.ttf");
	BotonTexto_m.setFont(Fuente_m);
	BotonTexto_m.setPosition(Vector2f((posicion.x + rellenotextoX),
		(posicion.y + rellenotextoY)));

	Colisionador_m = FloatRect(posicion, Vector2f(ancho, alto));
}

void Boton::draw(RenderWindow& window)
{
	window.draw(Boton_m);
	window.draw(BotonTexto_m);
}
