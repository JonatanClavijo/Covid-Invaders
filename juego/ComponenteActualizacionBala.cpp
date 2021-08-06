#include "ComponenteActualizacionBala.h"
#include "WorldState.h"

void ComponenteActualizacionBala::GenerarParaJugador(
	Vector2f spawnPosition)
{
	Subiendo_m = true;
	PertenecealJugador_m = true;
	EsGenerado_m = true;

	TC_m->getLocation().x = spawnPosition.x;
	TC_m->getLocation().y = spawnPosition.y - TC_m->getSize().y;
	RCC_m->setOrMoveColisionador(TC_m->getLocation().x,
		TC_m->getLocation().y,
		TC_m->getSize().x, TC_m->getSize().y);
}

void ComponenteActualizacionBala::GenerarParaCovid(
	Vector2f spawnPosition)
{
	Subiendo_m = false;
	PertenecealJugador_m = false;
	EsGenerado_m = true;

	srand((int)time(0));
	ModificadorVelocidadBalaCovid_m = (
		((rand() % ModificadorComponenteAleatorio_m)))
		+ ModificadorAdicionalMinimo_m;

	TC_m->getLocation().x = spawnPosition.x;
	TC_m->getLocation().y = spawnPosition.y;
	RCC_m->setOrMoveColisionador(
		TC_m->getLocation().x, TC_m->
		getLocation().y, TC_m->getSize().x, TC_m->getSize().y);
}

void ComponenteActualizacionBala::Desaparecer()
{
	EsGenerado_m = false;
}

bool ComponenteActualizacionBala::Esta_Subiendo()
{
	return Subiendo_m;
}

void ComponenteActualizacionBala::update(float fps)
{
	if (EsGenerado_m)
	{
		if (Subiendo_m)
		{
			TC_m->getLocation().y -= Velocidad_m * fps;
		}
		else
		{
			TC_m->getLocation().y += Velocidad_m /
				ModificadorVelocidadBalaCovid_m * fps;
		}

		if (TC_m->getLocation().y > WorldState::WORLD_ALTURA
			|| TC_m->getLocation().y < -2)
		{
			Desaparecer();
		}

		RCC_m->setOrMoveColisionador(TC_m->getLocation().x,
			TC_m->getLocation().y,
			TC_m->getSize().x, TC_m->getSize().y);
	}
}

