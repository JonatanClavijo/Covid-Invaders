#include "ControladorEntradaJuegoTerminado.h"
#include "MotordeSonido.h"
#include "WorldState.h"
#include <iostream>

void ControladorEntradaJuegoTerminado::manejar_TeclaPresionada(Event& event,
	RenderWindow& window)
{
	if (event.key.code == Keyboard::Escape)
	{
		MotordeSonido::playClick();
		getPunteroaControlRemotodelAdministradordePantalla()->
			CambiarPantallas("Seleccione");
	}
}

void ControladorEntradaJuegoTerminado::manejar_ClickIzquierdo(
	std::string& botonInteraccioncon, RenderWindow& window)
{
	if (botonInteraccioncon == "Play") {
		MotordeSonido::playClick();
		WorldState::NUMERO_OLEADA = 0;
		getPunteroaControlRemotodelAdministradordePantalla()->
			NiveldeCargaenMododeJuego("level1");
	}

	else if (botonInteraccioncon == "Home") {
		MotordeSonido::playClick();
		getPunteroaControlRemotodelAdministradordePantalla()->
			CambiarPantallas("Select");
	}
}
