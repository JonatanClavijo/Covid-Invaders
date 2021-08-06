#pragma once
#ifndef COMPARTIDORDEOBJETOSDEJUEGO_H
#define COMPARTIDORDEOBJETOSDEJUEGO_H

#include<vector>
#include<string>

class ObjetosJuego;

class CompartidordeObjetosdeJuego
{
    public:
        virtual std::vector<ObjetosJuego>& getObjetosJuegoConGOS() = 0;
        virtual ObjetosJuego& EncontrarPrimerObjetoConEtiqueta(std::string tag) = 0;
};

#endif
