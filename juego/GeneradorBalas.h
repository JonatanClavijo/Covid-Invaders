#pragma once
#ifndef GENERADORBALAS_H
#define GENERADORBALAS_H

#include <SFML/Graphics.hpp>

using namespace sf;

class GeneradorBalas
{
    public:
        virtual void GenerarBala(
            sf::Vector2f spawnLocation, bool paraJugador) = 0;
};

#endif
