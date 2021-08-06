#include "ControladorEntradaSeleccion.h"
#include "MotordeSonido.h"
#include "WorldState.h"
#include <iostream>

int WorldState::NUMERO_OLEADA;

void ControladorEntradaSeleccion::manejar_TeclaPresionada(
	Event& event, RenderWindow& window)
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}
}

void ControladorEntradaSeleccion::manejar_ClickIzquierdo(
	std::string& botonInteraccioncon, RenderWindow& window)
{
	if (botonInteraccioncon == "Play") {
		MotordeSonido::playClick();
		WorldState::NUMERO_OLEADA = 0;

		getPunteroaControlRemotodelAdministradordePantalla()
			->NiveldeCargaenMododeJuego("level1");
	}

	if (botonInteraccioncon == "Salir") {
		MotordeSonido::playClick();
		window.close();
	}
}
