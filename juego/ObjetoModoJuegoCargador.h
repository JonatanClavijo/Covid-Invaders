#pragma once
#ifndef OBJETOMODOJUEGOCARGADOR_H
#define OBJETOMODOJUEGOCARGADOR_H

#include <vector>
#include <string>
#include "ObjetosJuego.h"
#include "ObjetoPlanoAnalizador.h"
#include "ObjetoJuegoFactoryModoJuego.h"

using namespace std;

class ObjetoModoJuegoCargador
{
    private:
        ObjetoPlanoAnalizador BOP_m;
        ObjetoJuegoFactoryModoJuego ObjetoJuegoFactoryModoJuego_m;

    public:
        void CargarObjetosJuegoParaModoJuego(
            string RutaArchivo, vector<ObjetosJuego>& ObjetosJuego_m);
};

#endif
