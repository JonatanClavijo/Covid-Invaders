#include "TransformarComponente.h"

TransformarComponente::TransformarComponente(
	float ancho, float alto, Vector2f location)
{
	Alto_m = alto;
	Ancho_m = ancho;
	Location_m = location;
}

Vector2f& TransformarComponente::getLocation()
{
	return Location_m;
}

Vector2f TransformarComponente::getSize()
{
	return Vector2f(Ancho_m, Alto_m);
}
