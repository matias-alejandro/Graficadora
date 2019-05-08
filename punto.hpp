#ifndef PUNTO_HPP
#define PUNTO_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
/****************************************************************/
class Punto : public sf::CircleShape
{
	public:
		Punto();
		void mover(float x, float y);
		void actualizar();
		void graficar();
	private:
		sf::Vector2f posicionI; //Inicial
		sf::Vector2f posicionF; //Final
		sf::Vector2f velocidad;

		bool isGraficoListo;
		int contador;
};
#endif