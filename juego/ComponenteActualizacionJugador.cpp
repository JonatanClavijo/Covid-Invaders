#include "ComponenteActualizacionJugador.h"
#include "WorldState.h"

void ComponenteActualizacionJugador::update(float fps)
{
	if (sf::Joystick::isConnected(0))
	{
		TC_m->getLocation().x += ((Velocidad_m / 100)
			* GradoX_m) * fps;

		TC_m->getLocation().y += ((Velocidad_m / 100)
			* GradoY_m) * fps;
	}

	if (EstaSosteniendoIzquierda_m)
	{
		TC_m->getLocation().x -= Velocidad_m * fps;
	}
	else if (EstaSosteniendoDerecha_m)
	{
		TC_m->getLocation().x += Velocidad_m * fps;
	}

	if (EstaSosteniendoArriba_m)
	{
		TC_m->getLocation().y -= Velocidad_m * fps;
	}
	else if (EstaSosteniendoAbajo_m)
	{
		TC_m->getLocation().y += Velocidad_m * fps;
	}

	RCC_m->setOrMoveColisionador(TC_m->getLocation().x,
		TC_m->getLocation().y, TC_m->getSize().x,
		TC_m->getSize().y);

	if (TC_m->getLocation().x >
		WorldState::WORLD_ANCHO - TC_m->getSize().x)
	{
		TC_m->getLocation().x =
			WorldState::WORLD_ANCHO - TC_m->getSize().x;
	}
	else if (TC_m->getLocation().x < 0)
	{
		TC_m->getLocation().x = 0;
	}
	if (TC_m->getLocation().y >
		WorldState::WORLD_ALTURA - TC_m->getSize().y)
	{
		TC_m->getLocation().y =
			WorldState::WORLD_ALTURA - TC_m->getSize().y;
	}
	else if (TC_m->getLocation().y <
		WorldState::WORLD_ALTURA / 2)
	{
		TC_m->getLocation().y =
			WorldState::WORLD_ALTURA / 2;
	}
}

void ComponenteActualizacionJugador::
actualizarNaveViajeconControlador(float x, float y)
{
	GradoX_m = x;
	GradoY_m = y;
}

void ComponenteActualizacionJugador::moverIzquierda()
{
	EstaSosteniendoIzquierda_m = true;
	detenerDerecha();
}

void ComponenteActualizacionJugador::moverDerecha()
{
	EstaSosteniendoDerecha_m = true;
	detenerIzquierda();
}

void ComponenteActualizacionJugador::moverArriba()
{
	EstaSosteniendoArriba_m = true;
	detenerAbajo();
}

void ComponenteActualizacionJugador::moverAbajo()
{
	EstaSosteniendoAbajo_m = true;
	detenerArriba();
}

void ComponenteActualizacionJugador::detenerIzquierda()
{
	EstaSosteniendoIzquierda_m = false;
}

void ComponenteActualizacionJugador::detenerDerecha()
{
	EstaSosteniendoDerecha_m = false;
}

void ComponenteActualizacionJugador::detenerArriba()
{
	EstaSosteniendoArriba_m = false;
}

void ComponenteActualizacionJugador::detenerAbajo()
{
	EstaSosteniendoAbajo_m = false;
}
