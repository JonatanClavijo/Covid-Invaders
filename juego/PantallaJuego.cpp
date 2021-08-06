#include "PantallaJuego.h"
#include "PanelUIJuego.h"
#include "ControladorEntradaJuego.h"
#include "PanelUIJuegoTerminado.h"
#include "WorldState.h"
#include "ObjetosJuego.h"
#include "ComponenteActualizacionBala.h"
#include "ComponenteActualizacionCovid.h"

class GeneradorBalas;

int WorldState::WORLD_ALTURA;
int WorldState::NUM_COVID;
int WorldState::NUM_COVID_AL_INICIO;

PantallaJuego::PantallaJuego(ControlRemotodelAdministradordePantalla* smrc,
	Vector2i res)
{
	GIH_m = make_shared<ControladorEntradaJuego>();
	auto guip = make_unique<PanelUIJuego>(res);
	addPanel(move(guip), smrc, GIH_m);

	auto GOIH_m = make_shared<ControladorEntradaJuegoTerminado>();
	auto gouip = make_unique<PanelUIJuegoTerminado>(res);
	addPanel(move(gouip), smrc, GOIH_m);

	ControlRemotodelAdministradordePantalla_m = smrc;
	float formatoPantalla = VideoMode::getDesktopMode().width /
		VideoMode::getDesktopMode().height;

	WorldState::WORLD_ALTURA = WorldState::WORLD_ANCHO /
		formatoPantalla;

	vista_m.setSize(
		WorldState::WORLD_ANCHO, WorldState::WORLD_ALTURA);

	vista_m.setCenter(Vector2f(WorldState::WORLD_ANCHO /
		2, WorldState::WORLD_ALTURA / 2));

	FondoTexture_m.loadFromFile("graphics/fondo.png");

	FondoSprite_m.setTexture(FondoTexture_m);
	auto textureSize = FondoSprite_m.getTexture()->getSize();
	FondoSprite_m.setScale(float(vista_m.getSize().x) / textureSize.x,
		float(vista_m.getSize().y) / textureSize.y);
}

void PantallaJuego::inicializar()
{
	GIH_m->inicializar();
	MotorFisicoModoJuego_m.inicializar(
		ControlRemotodelAdministradordePantalla_m->
		compartirCompartidordeObjetosdeJuego());

	WorldState::NUM_COVID = 0;

	int i = 0;
	auto it = ControlRemotodelAdministradordePantalla_m->
		getObjetosdelJuego().begin();

	auto end = ControlRemotodelAdministradordePantalla_m->
		getObjetosdelJuego().end();

	for (it; it != end; ++it)
	{
		if ((*it).getTag() == "bullet")
		{
			LocalizacionObjetosBala_m.push_back(i);
		}
		if ((*it).getTag() == "invader")
		{
			static_pointer_cast<ComponenteActualizacionCovid>(
				(*it).getPrimerComponenteActualizacion())->
				inicializarGeneradorBalas(
					getGeneradorBalas(), i);

			WorldState::NUM_COVID++;
		}

		++i;
	}

	JuegoTerminado_m = false;

	if (WorldState::NUMERO_OLEADA == 0)
	{
		WorldState::NUM_COVID_AL_INICIO = WorldState::NUM_COVID;
		WorldState::NUMERO_OLEADA = 1;
		WorldState::VIDAS = 3;
		WorldState::PUNTAJE = 0;
	}
}

void PantallaJuego::update(float fps)
{
	Pantalla::update(fps);

	if (!JuegoTerminado_m)
	{
		if (EsperandoParaGenerarBalaParaJugador_m)
		{
			static_pointer_cast<ComponenteActualizacionBala>(
				ControlRemotodelAdministradordePantalla_m->
				getObjetosdelJuego()
				[LocalizacionObjetosBala_m[SiguienteBala_m]].
				getPrimerComponenteActualizacion())->
				GenerarParaJugador(UbicacionAparicionBalasJugador_m);

			EsperandoParaGenerarBalaParaJugador_m = false;
			SiguienteBala_m++;

			if (SiguienteBala_m == LocalizacionObjetosBala_m.size())
			{
				SiguienteBala_m = 0;
			}
		}

		if (EsperandoParaGenerarBalaParaCovid_m)
		{
			static_pointer_cast<ComponenteActualizacionBala>(
				ControlRemotodelAdministradordePantalla_m->
				getObjetosdelJuego()
				[LocalizacionObjetosBala_m[SiguienteBala_m]].
				getPrimerComponenteActualizacion())->
				GenerarParaCovid(UbicacionAparicionBalasCovid_m);

			EsperandoParaGenerarBalaParaCovid_m = false;
			SiguienteBala_m++;

			if (SiguienteBala_m == LocalizacionObjetosBala_m.size())
			{
				SiguienteBala_m = 0;
			}
		}

		auto it = ControlRemotodelAdministradordePantalla_m->
			getObjetosdelJuego().begin();

		auto end = ControlRemotodelAdministradordePantalla_m->
			getObjetosdelJuego().end();

		for (it; it != end; ++it)
		{
			(*it).update(fps);
		}

		MotorFisicoModoJuego_m.DetectarColision(
			ControlRemotodelAdministradordePantalla_m->getObjetosdelJuego(),
			LocalizacionObjetosBala_m);

		if (WorldState::NUM_COVID <= 0)
		{
			WorldState::NUMERO_OLEADA++;
			ControlRemotodelAdministradordePantalla_m->
				NiveldeCargaenMododeJuego("level1");
		}

		if (WorldState::VIDAS <= 0)
		{
			JuegoTerminado_m = true;
		}
	}
}

void PantallaJuego::draw(RenderWindow& window)
{
	window.setView(vista_m);
	window.draw(FondoSprite_m);

	auto it = ControlRemotodelAdministradordePantalla_m->
		getObjetosdelJuego().begin();

	auto end = ControlRemotodelAdministradordePantalla_m->
		getObjetosdelJuego().end();

	for (it; it != end; ++it)
	{
		(*it).draw(window);
	}

	Pantalla::draw(window);
}


GeneradorBalas* PantallaJuego::getGeneradorBalas()
{
	return this;
}
