#include "PanelUI.h"

PanelUI::PanelUI(Vector2i res, int x, int y,
            float ancho, float alto,
            int alpha, int rojo, int verde, int azul)
{
	PanelUI_m.setFillColor(sf::Color(rojo, verde, azul, alpha));

	PanelUI_m.setSize(Vector2f(ancho, alto));

	vista_m.setSize(Vector2f(ancho, alto));

	vista_m.setCenter(ancho / 2, alto / 2);

	float VentanaGraficaInicioX = 1.f / (res.x / x);
	float VentanaGraficaInicioY = 1.f / (res.y / y);
	float VentanaGraficaSizeX = 1.f / (res.x / ancho);
	float VentanaGraficaSizeY = 1.f / (res.y / alto);

	vista_m.setViewport(FloatRect(VentanaGraficaInicioX, VentanaGraficaInicioY,
		VentanaGraficaSizeX, VentanaGraficaSizeY));
}

vector<shared_ptr<Boton>> PanelUI::getBotones()
{
	return Botones_m;
}

void PanelUI::addBoton(float x, float y,
	int ancho, int alto,
	int rojo, int verde, int azul,
	string label)
{
	Botones_m.push_back(make_shared<Boton>(Vector2f(x, y),
		ancho, alto,
		rojo, verde, azul,
		label));
}

void PanelUI::draw(RenderWindow& window)
{
	window.setView(vista_m);
	if (!Oculto_m) {
		window.draw(PanelUI_m);
		for (auto it = Botones_m.begin();
			it != Botones_m.end(); ++it)
		{
			(*it)->draw(window);
		}
	}
}

void PanelUI::mostrar()
{
	Oculto_m = false;
}

void PanelUI::esconder()
{
	Oculto_m = true;
}
