#include "MotorFisicoModoJuego.h"
#include "DevelopState.h"
#include <iostream>
#include "MotordeSonido.h"
#include "WorldState.h"
#include "ComponenteActualizacionCovid.h"
#include "ComponenteActualizacionBala.h"

void MotorFisicoModoJuego::DetectarColisionCovid(
	vector<ObjetosJuego>& objetos,
	const vector<int>& PosicionBalas)
{
	Vector2f FueradePantalla(-1, -1);

	auto CovidIt = objetos.begin();
	auto CovidEnd = objetos.end();
	for (CovidIt; CovidIt != CovidEnd; ++CovidIt)
	{
		if ((*CovidIt).estaActivo()
			&& (*CovidIt).getTag() == "invader")
		{
			auto BalaIt = objetos.begin();
			advance(BalaIt, PosicionBalas[0]);
			auto BalaEnd = objetos.end();
			for (BalaIt; BalaIt != BalaEnd; ++BalaIt)

			{
				if ((*CovidIt).getAbarcandoColisionadorRect()
					.intersects((*BalaIt)
						.getAbarcandoColisionadorRect())
					&& (*BalaIt).getTag() == "bullet"
					&& static_pointer_cast<ComponenteActualizacionBala>(
					(*BalaIt).getPrimerComponenteActualizacion())
					->PertenecealJugador_m )
				{
					MotordeSonido::playCovidExplota();
					(*CovidIt).getTransformarComponente()
						->getLocation() = FueradePantalla;

					(*BalaIt).getTransformarComponente()
						->getLocation() = FueradePantalla;

					WorldState::PUNTAJE++;
					WorldState::NUM_COVID--;
					(*CovidIt).setInactivo();
				}
			}
		}
	}
}

void MotorFisicoModoJuego::DetectarColisionJugadorYDireccionCovid(
	vector<ObjetosJuego>& objetos,
	const vector<int>& PosicionBalas)
{
	Vector2f FueradePantalla(-1, -1);

	FloatRect JugadorColision =
		Jugador_m->getAbarcandoColisionadorRect();

	shared_ptr<TransformarComponente> JugadorTransformar =
		Jugador_m->getTransformarComponente();

	Vector2f JugadorLocation =
		JugadorTransformar->getLocation();

	auto it3 = objetos.begin();
	auto end3 = objetos.end();
	for (it3; it3 != end3; ++it3)
	{
		if ((*it3).estaActivo() && (*it3).TieneColisionador() && (*it3).getTag() != "Player")
		{
			FloatRect ColisonActual = (*it3).getAbarcandoColisionadorRect();
			if (ColisonActual.intersects(JugadorColision))
			{
				if ((*it3).getTag() == "bullet")
				{
					MotordeSonido::playJugadorExplota();
					WorldState::VIDAS--;
					(*it3).getTransformarComponente()->
						getLocation() = FueradePantalla;
				}

				if ((*it3).getTag() == "invader")
				{
					MotordeSonido::playJugadorExplota();
					MotordeSonido::playCovidExplota();
					WorldState::VIDAS--;
					(*it3).getTransformarComponente()->
						getLocation() = FueradePantalla;

					WorldState::PUNTAJE++;
					(*it3).setInactivo();
				}
			}

			shared_ptr<TransformarComponente>
				TransformacionActual =
				(*it3).getTransformarComponente();

			Vector2f ActualLocation =
				TransformacionActual->getLocation();

			string ActualTag = (*it3).getTag();
			Vector2f ActualSize =
				TransformacionActual->getSize();
			if (ActualTag == "invader")
			{
				if (!NecesitaBajarYRetroceder_m && !CovidGolpeoMarcoPared_m)
				{
					if (ActualLocation.x >= WorldState::WORLD_ANCHO - ActualSize.x)
					{
						if (static_pointer_cast<ComponenteActualizacionCovid>((*it3)
							.getPrimerComponenteActualizacion())->
							SeMueveDerecha())
						{
							CovidGolpeoMarcoPared_m = true;
						}
					}
					else if (ActualLocation.x < 0)
					{
						if (!static_pointer_cast<ComponenteActualizacionCovid>(
							(*it3).getPrimerComponenteActualizacion())->SeMueveDerecha())
						{
							CovidGolpeoMarcoPared_m = true;
						}
					}
				}
				else if (NecesitaBajarYRetroceder_m && !CovidGolpeoMarcoParedAnterior_m)
				{
					if ((*it3).TieneComponenteActualizacion())
					{
						static_pointer_cast<ComponenteActualizacionCovid>(
							(*it3).getPrimerComponenteActualizacion())
							->DesplegaryRevertir();
					}
				}
			}
		}

	}
}

void MotorFisicoModoJuego::manejar_DireccionCovid()
{
	if (CovidGolpeoMarcoPared_m)
    {
		NecesitaBajarYRetroceder_m = true;
		CovidGolpeoMarcoPared_m = false;
	}
	else
    {
		NecesitaBajarYRetroceder_m = false;
	}
}

void MotorFisicoModoJuego::inicializar(CompartidordeObjetosdeJuego& gos) {
	PUC_m = static_pointer_cast<ComponenteActualizacionJugador>(
		gos.EncontrarPrimerObjetoConEtiqueta("Player")
		.getComponentePorTipoyTipoEspecifico("update", "player"));

	Jugador_m = &gos.EncontrarPrimerObjetoConEtiqueta("Player");
}

void MotorFisicoModoJuego::DetectarColision(
	vector<ObjetosJuego>& objetoss,
	const vector<int>& PosicionBalas)
{
	DetectarColisionCovid(objetoss, PosicionBalas);
	DetectarColisionJugadorYDireccionCovid(objetoss, PosicionBalas);

	manejar_DireccionCovid();
}
