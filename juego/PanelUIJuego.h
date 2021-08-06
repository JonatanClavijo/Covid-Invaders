#pragma once
#ifndef PANELUIJUEGO_H
#define PANELUIJUEGO_H

#include "PanelUI.h"

class PanelUIJuego : public PanelUI
{
    public:
        PanelUIJuego(Vector2i res);
        void draw(RenderWindow& window) override;
};

#endif
