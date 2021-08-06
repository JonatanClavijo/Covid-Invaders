#pragma once
#ifndef COMPONENTECOLISIONADOR_H
#define COMPONENTECOLISIONADOR_H
#include "Componente.h"
#include <iostream>

class ComponenteColisionador : public Componente
{
    private:
        string Tipo_m = "collider";
        bool Habilitar_m = false;

    public:

        string getTipo() {
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

        void iniciar(CompartidordeObjetosdeJuego* gos, ObjetosJuego* self) {

        }
};

#endif
