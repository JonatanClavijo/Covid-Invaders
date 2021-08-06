#pragma once
#ifndef OBJETOJUEGOFACTORYMODOJUEGO_H
#define OBJETOJUEGOFACTORYMODOJUEGO_H

#include "ObjetoJuegoPlano.h"
#include "ObjetosJuego.h"
#include <vector>

class ObjetoJuegoFactoryModoJuego
{
    public:
        void ConstruirObjetoJuego(ObjetoJuegoPlano& bp,
            std::vector <ObjetosJuego>& ObjetosJuego_m);
};

#endif
