#pragma once
#ifndef COMPONENTEACTUALIZACION_H
#define COMPONENTEACTUALIZACION_H

#include "Componente.h"


class ComponenteActualizacion : public Componente
{
    private:
        string Tipo_m = "update";
        bool Habilitar_m = false;

    public:
        virtual void update(float fps) = 0;

        string getTipo()
        {
            return Tipo_m;
        }

        void ComponenteDeshabilitado() {
            Habilitar_m = false;
        }

        void ComponenteHabilitado() {
            Habilitar_m = true;
        }

        bool Habilitar() {
            return Habilitar_m;
        }

        void iniciar(
            CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {
        }
};

#endif
