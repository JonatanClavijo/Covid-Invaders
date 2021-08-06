#include "ObjetosJuego.h"
#include "DevelopState.h"
#include <iostream>
#include "ComponenteActualizacion.h"
#include "ComponenteColisionadorRect.h"

void ObjetosJuego::update(float fps)
{
	if (Activo_m && TieneComponenteActualizacion_m)
	{
		for (int i = UbicacionPrimerComponenteActualizacion_m; i <
			UbicacionPrimerComponenteActualizacion_m +
			NumeroComponentesActualizados_m; i++)
		{

			shared_ptr<ComponenteActualizacion> Actualizacion_temp =
				static_pointer_cast<ComponenteActualizacion>(Componentes_m[i]);

			if (Actualizacion_temp->Habilitar())
			{
				Actualizacion_temp->update(fps);
			}
		}
	}
}

void ObjetosJuego::draw(RenderWindow& window)
{
	if (Activo_m && TieneComponenteGrafico_m)
	{
		if (Componentes_m[UbicacionComponentesGraficos_m]->Habilitar())
		{
			getComponenteGrafico()->draw(window,
				getTransformarComponente());
		}
	}
}

shared_ptr<ComponenteGrafico> ObjetosJuego::getComponenteGrafico()
{
	return static_pointer_cast<ComponenteGrafico>(
		Componentes_m[UbicacionComponentesGraficos_m]);
}

shared_ptr<TransformarComponente> ObjetosJuego::getTransformarComponente()
{
	return static_pointer_cast<TransformarComponente>(
		Componentes_m[UbicacionTransformarComponente_m]);
}

void ObjetosJuego::addComponente(shared_ptr<Componente> componente)
{
	Componentes_m.push_back(componente);
	componente->ComponenteHabilitado();

	if (componente->getTipo() == "state")
	{
		TieneComponenteEstado_m = true;
		UbicacionComponenteEstado_m = Componentes_m.size() - 1;
	}
	else if (componente->getTipo() == "update")
	{
		TieneComponenteActualizacion_m = true;
		NumeroComponentesActualizados_m++;
		if (NumeroComponentesActualizados_m == 1)
		{
			UbicacionPrimerComponenteActualizacion_m =
				Componentes_m.size() - 1;
		}
	}
	else if (componente->getTipo() == "graphics")
	{
		TieneComponenteGrafico_m = true;
		UbicacionComponentesGraficos_m = Componentes_m.size() - 1;
	}
	else if (componente->getTipo() == "transform")
	{
		UbicacionTransformarComponente_m = Componentes_m.size() - 1;
	}
	else if (componente->getTipo() == "collider" &&
		componente->getTipoSpecifico() == "rect")
	{
		TieneColisionador_m = true;
		NumeroComponenteColisionesRect_m++;
		if (NumeroComponenteColisionesRect_m == 1)
		{
			UbicacionPrimerComponenteColisionesRect_m =
				Componentes_m.size() - 1;
		}
	}
}

void ObjetosJuego::setActivo()
{
	Activo_m = true;
}

void ObjetosJuego::setInactivo()
{
	Activo_m = false;
}

bool ObjetosJuego::estaActivo()
{
	return Activo_m;
}

void ObjetosJuego::setTag(String tag)
{
	Tag_m = "" + tag;
}

std::string ObjetosJuego::getTag()
{
	return Tag_m;
}

void ObjetosJuego::iniciar(CompartidordeObjetosdeJuego* gos)
{
	auto it = Componentes_m.begin();
	auto end = Componentes_m.end();
	for (it; it != end; ++it)
	{
		(*it)->iniciar(gos, this);
	}
}

shared_ptr<Componente> ObjetosJuego::getComponentePorTipoyTipoEspecifico(
	string tipo, string tipoEspecifico) {

	auto it = Componentes_m.begin();
	auto end = Componentes_m.end();
	for (it; it != end; ++it)
	{
		if ((*it)->getTipo() == tipo)
		{
			if ((*it)->getTipoSpecifico() == tipoEspecifico)
			{
				return  (*it);
			}
		}
	}

#ifdef debuggingErrors
	cout <<
		"ObjetosJuego.cpp::getComponentePorTipoyTipoEspecifico-"
		<< "COMPONENT NOT FOUND ERROR!"
		<< endl;
#endif
	return Componentes_m[0];
}

FloatRect& ObjetosJuego::getAbarcandoColisionadorRect()
{
	if (TieneColisionador_m)
	{
		return (static_pointer_cast<ComponenteColisionadorRect>(
			Componentes_m[UbicacionPrimerComponenteColisionesRect_m]))
			->getColisionadorRectF();
	}
}

string ObjetosJuego::getAbarcandoColisionadorRectTag()
{
	return static_pointer_cast<ComponenteColisionadorRect>(
		Componentes_m[UbicacionPrimerComponenteColisionesRect_m])->
		getColisionadorTag();
}


shared_ptr<ComponenteActualizacion> ObjetosJuego::getPrimerComponenteActualizacion()
{
	return static_pointer_cast<ComponenteActualizacion>(
		Componentes_m[UbicacionPrimerComponenteActualizacion_m]);
}

bool ObjetosJuego::TieneColisionador()
{
	return TieneColisionador_m;
}

bool ObjetosJuego::TieneComponenteActualizacion()
{
	return TieneComponenteActualizacion_m;
}
