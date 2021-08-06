#pragma once
#ifndef TIENDADEMAPADEBITS_H
#define TIENDADEMAPADEBITS_H

#include <SFML/Graphics.hpp>
#include <map>

class TiendadeMapadeBits
{
    private:
        std::map<std::string, sf::Texture> mapadeMapadeBits_m;
        static TiendadeMapadeBits* m_s_Instancia;

    public:
        TiendadeMapadeBits();
        static sf::Texture& getMapaBits(std::string const& filename);
        static void addMapaBits(std::string const& filename);
};

#endif
