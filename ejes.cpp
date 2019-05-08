#include "ejes.hpp"

#define VEL 1
/****************************************************************/
Ejes::Ejes() : sf::CircleShape()
{
	this->posicion.x=100; //anchoP/2
	this->posicion.y=0;
	this->velocidad.x=0;
	this->velocidad.y=0;
	this->setPosition(posicion);
	this->setFillColor(sf::Color(0,255,0));
	this->setRadius(1.0);
	this->ejeY=true;
}
/****************************************************************/
void Ejes::actualizar()
{
	if(this->ejeY)
		this->dibujarEjeY();
	else
		this->dibujarEjeX();
	return;
}
/****************************************************************/
void Ejes::dibujarEjeY()
{
	this->posicion=this->getPosition();
	if(this->posicion.x == 100 && this->posicion.y <= 200/*altoP*/)
	{
		this->velocidad.y=VEL;
		this->velocidad.x=0;
	}
	else
	{
		this->velocidad.y=0;
		this->posicion.x=0;
		this->posicion.y=100;
		this->setPosition(posicion);
		this->ejeY=false;
	}
	this->move(this->velocidad);
	return;
}
/****************************************************************/
void Ejes::dibujarEjeX()
{
	this->posicion=this->getPosition();
	if(this->posicion.y == 100 && this->posicion.x <= 200/*anchoP*/)
	{
		this->velocidad.x=VEL;
		this->velocidad.y=0;
	}
	else
	{
		this->velocidad.x=0;
	}
	
	this->move(this->velocidad);
	return;
}
/****************************************************************/