#pragma once
#ifndef CONTROLREMOTODELADMINISTRADORDEPANTALLA_H
#define CONTROLREMOTODELADMINISTRADORDEPANTALLA_H

#include <string>
#include <vector>
#include "ObjetosJuego.h"
#include "CompartidordeObjetosdeJuego.h"

class ControlRemotodelAdministradordePantalla
{
    public:
        virtual void CambiarPantallas(string pantalla_para_Cambiar_a) = 0;
        virtual void NiveldeCargaenMododeJuego(string PantallaParaCargar) = 0;
        virtual vector<ObjetosJuego>& getObjetosdelJuego() = 0;
        virtual CompartidordeObjetosdeJuego& compartirCompartidordeObjetosdeJuego() = 0;
};

#endif
