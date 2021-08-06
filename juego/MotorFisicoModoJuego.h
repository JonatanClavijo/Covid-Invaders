#pragma once
#ifndef MOTORFISICOMODOJUEGO_H
#define MOTORFISICOMODOJUEGO_H

#include "CompartidordeObjetosdeJuego.h"
#include "ComponenteActualizacionJugador.h"

class MotorFisicoModoJuego
{
    private:
        shared_ptr<ComponenteActualizacionJugador> PUC_m;

        ObjetosJuego* Jugador_m;
        bool CovidGolpeoMarcoPared_m = false;
        bool CovidGolpeoMarcoParedAnterior_m = false;
        bool NecesitaBajarYRetroceder_m = false;
        bool CompletadoDesplegarYRetroceder_m = false;


        void DetectarColisionCovid(
            vector<ObjetosJuego>& objetos,
            const vector<int>& PosicionBalas);

        void DetectarColisionJugadorYDireccionCovid(
            vector<ObjetosJuego>& objetos,
            const vector<int>& PosicionBalas);

        void manejar_DireccionCovid();

    public:
        void inicializar(CompartidordeObjetosdeJuego& gos);
        void DetectarColision(
            vector<ObjetosJuego>& objetos,
            const vector<int>& PosicionBalas);
};

#endif
