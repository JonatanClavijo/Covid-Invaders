#pragma once
#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H

#include "Pantalla.h"
#include "ControladorEntradaJuego.h"
#include "ControladorEntradaJuegoTerminado.h"
#include "GeneradorBalas.h"
#include "MotorFisicoModoJuego.h"

class PantallaJuego : public Pantalla, public GeneradorBalas
{
    private:
        ControlRemotodelAdministradordePantalla* ControlRemotodelAdministradordePantalla_m;
        shared_ptr<ControladorEntradaJuego> GIH_m;
        MotorFisicoModoJuego MotorFisicoModoJuego_m;

        int NumeroCovidenWorldFile_m = 0;

        vector<int> LocalizacionObjetosBala_m;
        int SiguienteBala_m = 0;
        bool EsperandoParaGenerarBalaParaJugador_m = false;
        bool EsperandoParaGenerarBalaParaCovid_m  = false;
        Vector2f UbicacionAparicionBalasJugador_m;
        Vector2f UbicacionAparicionBalasCovid_m;
        Clock BalaReloj_m;

        Texture FondoTexture_m;
        Sprite FondoSprite_m;
    public:
        static bool JuegoTerminado_m;

        PantallaJuego(ControlRemotodelAdministradordePantalla* smrc, Vector2i res);
        void inicializar() override;
        virtual void update(float fps);
        virtual void draw(RenderWindow& window);

        GeneradorBalas* getGeneradorBalas();

        void generarBala(Vector2f generarLocalizacion, bool paraJugador)
        {
            if (paraJugador)
            {
                Time TiempoTranscurrido = BalaReloj_m.getElapsedTime();
                if (TiempoTranscurrido.asMilliseconds() > 500) {
                    UbicacionAparicionBalasJugador_m.x = generarLocalizacion.x;
                    UbicacionAparicionBalasJugador_m.y = generarLocalizacion.y;
                    EsperandoParaGenerarBalaParaJugador_m = true;
                    BalaReloj_m.restart();
                }
            }
            else
            {
                UbicacionAparicionBalasCovid_m.x = generarLocalizacion.x;
                UbicacionAparicionBalasCovid_m.y = generarLocalizacion.y;
                EsperandoParaGenerarBalaParaCovid_m = true;
            }
        }
};

#endif
