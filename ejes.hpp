#ifndef EJES_HPP
#define EJES_HPP

#include <SFML/Graphics.hpp>
/****************************************************************/
class Ejes : public sf::CircleShape
{
	public:
		Ejes();
		void actualizar();
	private:
		sf::Vector2f velocidad;
		sf::Vector2f posicion;

		void dibujarEjeX();
		void dibujarEjeY();

		bool ejeY;
};
#endif