#include "punto.hpp"

#define VEL 1
/****************************************************************/
Punto::Punto() : sf::CircleShape()
{
	this->posicionI.x=0;
	this->posicionI.y=0;

	this->posicionF.x=0;
	this->posicionF.y=0;

	this->setPosition(this->posicionI);
	this->setFillColor(sf::Color(255,255,255));
	this->setRadius(1.0);
	this->isGraficoListo=false;
	this->contador=0;
}
/****************************************************************/
void Punto::graficar()
{
		//Y=(X-10)**2 //ejemplo
		this->setPosition(this->contador, -(pow(this->contador-10, 2.0))+100);
}
/****************************************************************/
void Punto::actualizar()
{
	if(this->isGraficoListo)
		return;

	if(this->posicionI.x > 201 || this->posicionI.x < 0) //201 es ancho pantalla
	{
		this->isGraficoListo=true;
		return;
	}

	if(this->posicionI.y > 201 || this->posicionI.y < 0) //201 es alto pantalla
	{
		this->isGraficoListo=true;
		return;
	}

	if(this->velocidad.x == 0 && this->velocidad.y == 0)
	{
		this->contador++;
		this->mover(this->contador, -(pow(this->contador-10, 2.0))+100);
	}

	if(this->posicionI.x == this->posicionF.x)
		this->velocidad.x=0;

	if(this->posicionI.y == this->posicionF.y)
		this->velocidad.y=0;

	if(this->posicionF.x > this->posicionI.x)
	{
		this->velocidad.x=VEL;
	}
	else if(this->posicionF.x < this->posicionI.x)
	{
		this->velocidad.x=-VEL;
	}

	if(this->posicionF.y > this->posicionI.y)
	{
		this->velocidad.y=VEL;
	}
	else if(this->posicionF.y < this->posicionI.y)
	{
		this->velocidad.y=-VEL;
	}

	this->move(this->velocidad);
	this->posicionI=this->getPosition();
	
	return;
}
/****************************************************************/
void Punto::mover(float x, float y)
{
	this->posicionF.x=x;
	this->posicionF.y=y;
}
/****************************************************************/