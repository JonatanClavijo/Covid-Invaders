#include "ObjetoJuegoFactoryModoJuego.h"
#include <iostream>
#include "TransformarComponente.h"
#include "ComponenteGraficoEstandar.h"
#include "ComponenteActualizacionJugador.h"
#include "ComponenteColisionadorRect.h"
#include "ComponenteActualizacionBala.h"
#include "ComponenteActualizacionCovid.h"

void ObjetoJuegoFactoryModoJuego::ConstruirObjetoJuego(
	ObjetoJuegoPlano& bp,
	std::vector<ObjetosJuego>& ObjetosJuego_m)
{
	ObjetosJuego ObjetosJuego_mn;
	ObjetosJuego_mn.setTag(bp.getNombre());

	auto it = bp.getListaComponente().begin();
	auto end = bp.getListaComponente().end();
	for (it; it != end; ++it)
	{
		if (*it == "Transform")
		{
			ObjetosJuego_mn.addComponente(make_shared<TransformarComponente>(
				bp.getAncho(),
				bp.getAlto(),
				Vector2f(bp.getLocationX(), bp.getLocationY())));
		}
		else if (*it == "Player Update")
		{
			ObjetosJuego_mn.addComponente(make_shared
				<ComponenteActualizacionJugador>());
		}
		else if (*it == "Invader Update")
		{
			ObjetosJuego_mn.addComponente(make_shared
				<ComponenteActualizacionCovid>());
		}
		else if (*it == "Bullet Update")
		{
			ObjetosJuego_mn.addComponente(make_shared
				<ComponenteActualizacionBala>());
		}
		else if (*it == "Standard Graphics")
		{
			shared_ptr<ComponenteGraficoEstandar> sgp =
				make_shared<ComponenteGraficoEstandar>();

			ObjetosJuego_mn.addComponente(sgp);
			sgp->inicializarGrafico(
				bp.getBitmapNombre(),
				Vector2f(bp.getAncho(),
					bp.getAlto()));
		}
	}

	if (bp.getAbarcandoColisionadorRect()) {
		shared_ptr<ComponenteColisionadorRect> rcc =
			make_shared<ComponenteColisionadorRect>(
				bp.getAbarcandoColisionadorRectLabel());

		ObjetosJuego_mn.addComponente(rcc);
		rcc->setOrMoveColisionador(bp.getLocationX(),
			bp.getLocationY(),
			bp.getAncho(),
			bp.getAlto());
	}

	ObjetosJuego_m.push_back(ObjetosJuego_mn);
}
