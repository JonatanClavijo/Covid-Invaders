#pragma once
#ifndef CONTROLADORENTRADASELECCION_H
#define CONTROLADORENTRADASELECCION_H

#include "ControladorEntrada.h"

class ControladorEntradaSeleccion: public ControladorEntrada
{
    public:
        void manejar_TeclaPresionada(Event& event,
            RenderWindow& window) override;

        void manejar_ClickIzquierdo(std::string& botonInteraccioncon,
            RenderWindow& window) override;
};

#endif
