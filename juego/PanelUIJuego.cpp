#include "PanelUIJuego.h"
#include <sstream>
#include "WorldState.h"

int WorldState::PUNTAJE;
int WorldState::VIDAS;

PanelUIJuego::PanelUIJuego(Vector2i res) :
	PanelUI(res,
		1,
		1,
		res.x / 3,
		res.y / 12,
		50, 255, 255, 255)
{
	Texto_m.setFillColor(sf::Color(0, 255, 0, 255));
	Texto_m.setString("Puntaje: 0 Vidas: 3 Oleada: 1");
	Fuente_m.loadFromFile("fonts/Roboto-Bold.ttf");
	Texto_m.setFont(Fuente_m);
	Texto_m.setPosition(Vector2f(15, 15));
	Texto_m.setCharacterSize(60);
}

void PanelUIJuego::draw(RenderWindow& window)
{
	PanelUI::draw(window);

	std::stringstream ss;
	ss << "Puntaje: " << WorldState::PUNTAJE <<
        "  Vidas: " << WorldState::VIDAS <<
        " Oleada: " << WorldState::NUMERO_OLEADA;
	Texto_m.setString(ss.str());

	window.draw(Texto_m);
}
