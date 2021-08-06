#include "ControladorEntradaJuego.h"
#include "MotordeSonido.h"
#include "PantallaJuego.h"

class GeneradorBalas;

void ControladorEntradaJuego::inicializar()
{
	PUC_m = static_pointer_cast<ComponenteActualizacionJugador>
		(getPunteroaControlRemotodelAdministradordePantalla()
			->compartirCompartidordeObjetosdeJuego()
			.EncontrarPrimerObjetoConEtiqueta("Player")
			.getComponentePorTipoyTipoEspecifico(
				"update", "player"));

	PTC_m = getPunteroaControlRemotodelAdministradordePantalla()->
		compartirCompartidordeObjetosdeJuego().EncontrarPrimerObjetoConEtiqueta(
			"Player").getTransformarComponente();
}

void ControladorEntradaJuego::manejar_Gamepad()
{
	float ZonaMuerta = 10.0f;
	float x = Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = Joystick::getAxisPosition(0, sf::Joystick::Y);

	if (x < ZonaMuerta && x > -ZonaMuerta)
	{
		x = 0;
	}

	if (y < ZonaMuerta && y > -ZonaMuerta)
	{
		y = 0;
	}

	PUC_m->actualizarNaveViajeconControlador(x, y);

	if (Joystick::isButtonPressed(0, 1))
	{
		BotonPresionadomB = true;
	}

	if (!Joystick::isButtonPressed(0, 1) && BotonPresionadomB)
	{
		BotonPresionadomB = false;

		MotordeSonido::playDisparo();
		Vector2f spawnLocation;
		spawnLocation.x = PTC_m->getLocation().x +
			PTC_m->getSize().x / 2;

		spawnLocation.y = PTC_m->getLocation().y;

		static_cast<PantallaJuego*>(getmpantalladePadres())->
			getGeneradorBalas()->GenerarBala(spawnLocation, true);
	}
}

void ControladorEntradaJuego::manejar_TeclaPresionada(
	Event& event, RenderWindow& window)
{
	if (event.key.code == Keyboard::Escape)
	{
		MotordeSonido::playClick();
		getPunteroaControlRemotodelAdministradordePantalla()->
			CambiarPantallas("Seleccione");
	}

	if (event.key.code == Keyboard::Left)
	{
		PUC_m->moverIzquierda();
	}

	if (event.key.code == Keyboard::Right)
	{
		PUC_m->moverDerecha();
	}

	if (event.key.code == Keyboard::Up)
	{
		PUC_m->moverArriba();
	}

	if (event.key.code == Keyboard::Down)
	{
		PUC_m->moverAbajo();
	}
}

void ControladorEntradaJuego::manejar_TeclaLiberada(
	Event& event, RenderWindow& window)
{
	if (event.key.code == Keyboard::Left)
	{
		PUC_m->detenerIzquierda();
	}

	else if (event.key.code == Keyboard::Right)
	{
		PUC_m->detenerDerecha();
	}

	else if (event.key.code == Keyboard::Up)
	{
		PUC_m->detenerArriba();
	}

	else if (event.key.code == Keyboard::Down)
	{
		PUC_m->detenerAbajo();
	}

	else if (event.key.code == Keyboard::Space)
	{
		MotordeSonido::playDisparo();
		Vector2f spawnLocation;
		spawnLocation.x = PTC_m->getLocation().x +
			PTC_m->getSize().x / 2;

		spawnLocation.y = PTC_m->getLocation().y;

		static_cast<PantallaJuego*>(getmpantalladePadres())->
			GenerarBala(spawnLocation, true);
	}
}
