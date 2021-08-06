#pragma once
#ifndef CONTROLADORENTRADAJUEGO_H
#define CONTROLADORENTRADAJUEGO_H

#include "ComponenteActualizacionJugador.h"
#include "TransformarComponente.h"
#include "ControladorEntrada.h"

class PantallaJuego;

class ControladorEntradaJuego : public ControladorEntrada
{
    private:
        shared_ptr<ComponenteActualizacionJugador> PUC_m;
        shared_ptr<TransformarComponente> PTC_m;

        bool BotonPresionadomB = false;

    public:

        void inicializar();
        void manejar_Gamepad() override;
        void manejar_TeclaPresionada(Event& event,
            RenderWindow& window) override;

        void manejar_TeclaLiberada(Event& event,
            RenderWindow& window) override;
};

#endif
