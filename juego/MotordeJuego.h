#pragma once
#ifndef MOTORDEJUEGO_H
#define MOTORDEJUEGO_H

#include <SFML/Graphics.hpp>
#include "AdministradordePantalla.h"
#include "MotordeSonido.h"

using namespace sf;

class MotordeJuego {
private:
	Clock Clock_m;
	Time DT_m;
	RenderWindow Window_m;

	unique_ptr<AdministradordePantalla> AdministradordePantalla_m;

	float FPS_m = 0;
	Vector2f Resolucion_m;

	void manejo_entrada();
	void update();
	void draw();

public:
	MotordeSonido MotordeSonido_m;

	MotordeJuego();
	void run();
};

#endif
