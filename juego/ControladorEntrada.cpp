#include "ControladorEntrada.h"

#include <sstream>

using namespace sf;
using namespace std;

void ControladorEntrada::inicializarControladorEntrada(
		ControlRemotodelAdministradordePantalla* sw,
		vector<shared_ptr<Boton>> botones,
		View* punteroalaVistadeIU,
		Pantalla* pantallaPadre)
{
	ControlRemotodelAdministradordePantalla_m = sw;
	Botones_m = botones;
	punteroalaVistadePanelUI_m = punteroalaVistadeIU;
	pantallaPadre_m = pantallaPadre;
}

void ControladorEntrada::manejar_entrada(RenderWindow& window,
	Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		manejar_TeclaPresionada(event, window);
	}

	if (event.type == Event::KeyReleased)
	{
		manejar_TeclaLiberada(event, window);
	}

	if (event.type == Event::MouseButtonReleased)
	{
		auto end = Botones_m.end();

		for (auto i = Botones_m.begin(); i != end; ++i)
			{
                if ((*i)->Colisionador_m.contains(
                    window.mapPixelToCoords(Mouse::getPosition(),
                    (*getpunteroalaVistadeIU()))))
                {
                    manejar_ClickIzquierdo((*i)->Texto_m, window);
                    break;
                }
            }
	}

	manejar_Gamepad();
}

void ControladorEntrada::manejar_Gamepad()
{}

void ControladorEntrada::manejar_TeclaPresionada(Event& event,
	RenderWindow& window)
{}

void ControladorEntrada::manejar_TeclaLiberada(Event& event,
	RenderWindow& window)
{}

void ControladorEntrada::manejar_ClickIzquierdo(std::
	string& botonInteraccioncon,
	RenderWindow& window)
{}

View* ControladorEntrada::getpunteroalaVistadeIU()
{
	return punteroalaVistadePanelUI_m;
}

ControlRemotodelAdministradordePantalla*
ControladorEntrada::getPunteroaControlRemotodelAdministradordePantalla()
{
	return ControlRemotodelAdministradordePantalla_m;
}

Pantalla* ControladorEntrada::getmpantalladePadres() {
	return pantallaPadre_m;
}
