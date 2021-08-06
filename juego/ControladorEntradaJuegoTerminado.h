#pragma once
#ifndef CONTROLADORENTRADAJUEGOTERMINADO_H
#define CONTROLADORENTRADAJUEGOTERMINADO_H

#include "ControladorEntrada.h"


class ControladorEntradaJuegoTerminado: public ControladorEntrada
{
    public:
        void manejar_TeclaPresionada(Event& event,
            RenderWindow& window) override;

        void manejar_ClickIzquierdo(std::string&
            botonInteraccioncon, RenderWindow& window) override;
};


#endif
