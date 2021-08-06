#ifndef PANELUIJUEGOTERMINADO_H
#define PANELUIJUEGOTERMINADO_H

#include "PanelUI.h"
class PanelUIJuegoTerminado : public PanelUI
{
    private:
        void inicializarBotones();

    public:
        PanelUIJuegoTerminado(Vector2i res);
        void virtual draw(RenderWindow& window);
};
#endif
