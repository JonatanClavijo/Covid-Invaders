#include "MotordeJuego.h"

MotordeJuego::MotordeJuego()
{
	Resolucion_m.x = VideoMode::getDesktopMode().width;
	Resolucion_m.y = VideoMode::getDesktopMode().height;
	Window_m.create(VideoMode(Resolucion_m.x, Resolucion_m.y),
		"Covid Invaders", Style::Fullscreen);

	AdministradordePantalla_m = unique_ptr<AdministradordePantalla>(new AdministradordePantalla(
		Vector2i(Resolucion_m.x, Resolucion_m.y)));
}

void MotordeJuego::run()
{
	while (Window_m.isOpen())
	{
		DT_m = Clock_m.restart();
		FPS_m = DT_m.asSeconds();
		manejo_entrada();
		update();
		draw();
	}
}

void MotordeJuego::manejo_entrada()
{
	AdministradordePantalla_m->manejo_entrada(Window_m);
}

void MotordeJuego::update()
{
	AdministradordePantalla_m->update(FPS_m);
}

void MotordeJuego::draw()
{
	Window_m.clear(Color::Black);
	AdministradordePantalla_m->draw(Window_m);
	Window_m.display();
}
