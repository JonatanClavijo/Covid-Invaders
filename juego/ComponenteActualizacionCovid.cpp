#include "ComponenteActualizacionCovid.h"
#include "GeneradorBalas.h"
#include "WorldState.h"
#include "MotordeSonido.h"

void ComponenteActualizacionCovid::update(float fps)
{
	if (MoverDerecha_m)
	{
		TC_m->getLocation().x += Velocidad_m * fps;
	}
	else
	{
		TC_m->getLocation().x -= Velocidad_m * fps;
	}

	RCC_m->setOrMoveColisionador(TC_m->getLocation().x,
		TC_m->getLocation().y, TC_m->getSize().x, TC_m->getSize().y);

	TiempoDesdeUltimoDisparo_m += fps;

	if ((TC_m->getLocation().x + (TC_m->getSize().x / 2)) >
		(JugadorTC_m->getLocation().x - ModificadorPrecision_m) &&
		(TC_m->getLocation().x + (TC_m->getSize().x / 2)) <
		(JugadorTC_m->getLocation().x +
		(JugadorTC_m->getSize().x + ModificadorPrecision_m)))
	{
		if (TiempoDesdeUltimoDisparo_m > TiempoEntreDisparos)
		{
            MotordeSonido::playDisparo();
			Vector2f spawnLocation;
			spawnLocation.x = TC_m->getLocation().x +
				TC_m->getSize().x / 2;

			spawnLocation.y = TC_m->getLocation().y +
				TC_m->getSize().y;

			GeneradorBalas_m->GenerarBala(spawnLocation, false);
			srand(SemillaRand_m);
			int TiempoEntreDisparosm = (((rand() % 10)) + 1) /
				WorldState::NUMERO_OLEADA;

			TiempoDesdeUltimoDisparo_m = 0;
		}
	}
}

void ComponenteActualizacionCovid::DesplegaryRevertir()
{
	MoverDerecha_m = !MoverDerecha_m;
	TC_m->getLocation().y += TC_m->getSize().y;
	Velocidad_m += (WorldState::NUMERO_OLEADA) +
		(WorldState::NUM_COVID_AL_INICIO - WorldState::NUM_COVID)
		* ModificadorVelocidad_m;
}

bool ComponenteActualizacionCovid::SeMueveDerecha()
{
	return MoverDerecha_m;
}

void ComponenteActualizacionCovid::inicializarGeneradorBalas(GeneradorBalas*
            generadorBalas, int SemillaRand)
{
	GeneradorBalas_m = generadorBalas;
	SemillaRand_m = SemillaRand;
	srand(SemillaRand_m);
	TiempoEntreDisparos = (rand() % 15 + SemillaRand_m);

	ModificadorPrecision_m = (rand() % 2);
	ModificadorPrecision_m += 0 + static_cast <float> (
		rand()) / (static_cast <float> (RAND_MAX / (10)));
}
