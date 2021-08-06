#pragma once
#ifndef PANELUISELECCION_H
#define PANELUISELECCION_H

#include "PanelUI.h"

class PanelUISeleccion: public PanelUI
{
    private:
        void inicializarBotones();

    public:
        PanelUISeleccion(Vector2i res);
        void virtual draw(RenderWindow& window);
};

#endif
