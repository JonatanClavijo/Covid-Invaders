#pragma once
#ifndef COMPONENTE_H
#define COMPONENTE_H

#include "CompartidordeObjetosdeJuego.h"
#include <string>

using namespace std;

class ObjetosJuego;

class Componente {
    public:
        virtual string getTipo() = 0;
        virtual string getTipoSpecifico() = 0;
        virtual void ComponenteDeshabilitado() = 0;
        virtual void ComponenteHabilitado() = 0;
        virtual bool Habilitar() = 0;
        virtual void iniciar(CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) = 0;
};

#endif
