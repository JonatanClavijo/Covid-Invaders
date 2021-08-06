#pragma once
#ifndef MOTORDESONIDO_H
#define MOTORDESONIDO_H

#include <SFML/Audio.hpp>

using namespace sf;

class MotordeSonido
{
private:
	SoundBuffer DispararBuffer_m;
	SoundBuffer JugadorExplotaBuffer_m;
	SoundBuffer CovidExplotaBuffer_m;
	SoundBuffer ClickBuffer_m;

	Sound SonidoDisparo_m;
	Sound SonidoJugadorExplota_m;
	Sound SonidoCovidExplota_m;
	Sound SonidoUh_m;
	Sound SonidoOh_m;
	Sound SonidoClick_m;

public:
	MotordeSonido();

	static void playDisparo();
	static void playJugadorExplota();
	static void playCovidExplota();
	static void playClick();

	static MotordeSonido* m_s_Instancia;
};

#endif
