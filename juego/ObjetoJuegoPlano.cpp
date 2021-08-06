#include "ObjetoJuegoPlano.h"

float ObjetoJuegoPlano::getAncho() {
	return Ancho_m;
}

void ObjetoJuegoPlano::setAncho(float ancho) {
	Ancho_m = ancho;
}

float ObjetoJuegoPlano::getAlto() {
	return Alto_m;
}

void ObjetoJuegoPlano::setAlto(float alto) {
	Alto_m = alto;
}

float ObjetoJuegoPlano::getLocationX() {
	return LocationX_m;
}

void ObjetoJuegoPlano::setLocationX(float locationX) {
	LocationX_m = locationX;
}

float ObjetoJuegoPlano::getLocationY() {
	return LocationY_m;
}

void ObjetoJuegoPlano::setLocationY(float locationY) {
	LocationY_m = locationY;
}

void ObjetoJuegoPlano::setNombre(string nombre)
{
	Nombre_m = "" + nombre;
}

string ObjetoJuegoPlano::getNombre()
{
	return Nombre_m;
}

vector<string>& ObjetoJuegoPlano::getListaComponente()
{
	return ListaComponente_m;
}

void ObjetoJuegoPlano::addAListaComponente(string newComponente)
{
	ListaComponente_m.push_back(newComponente);
}

string ObjetoJuegoPlano::getBitmapNombre()
{
	return BitmapNombre_m;
}

void ObjetoJuegoPlano::setBitmapNombre(string bitmapNombre)
{
	BitmapNombre_m = "" + bitmapNombre;
}

string ObjetoJuegoPlano::getAbarcandoColisionadorRectLabel() {
	return AbarcandoColisionadorRectLabel_m;
}

bool ObjetoJuegoPlano::getAbarcandoColisionadorRect() {
	return AbarcandoColisionadorRect_m;
}

void ObjetoJuegoPlano::setAbarcandoColisionadorRect(string label) {
	AbarcandoColisionadorRect_m = true;
	AbarcandoColisionadorRectLabel_m = "" + label;
}
