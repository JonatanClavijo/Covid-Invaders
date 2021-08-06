#pragma once
#ifndef PANTALLASELECCION_H
#define PANTALLASELECCION_H

#include "Pantalla.h"

class PantallaSeleccion: public Pantalla
{
    private:
        ControlRemotodelAdministradordePantalla* ControlRemotodelAdministradordePantalla_m;

        Texture FondoTexture_m;
        Sprite FondoSprite_m;

    public:
        PantallaSeleccion(ControlRemotodelAdministradordePantalla* smrc, Vector2i res);
        void virtual draw(RenderWindow& window);
};

#endif
