#include <SFML/Graphics.hpp>

#include "punto.hpp"
/****************************************************************/
#define anchoP 200
#define altoP 200

/****************************************************************/
int main(int argc, char const *argv[])
{
	sf::RenderWindow ventana(sf::VideoMode(anchoP,altoP),"Graficadora");
	sf::Event evento;

	ventana.setVerticalSyncEnabled(true);
	ventana.setMouseCursorVisible(false);

	Punto punto;
	punto.graficar();

	while(ventana.isOpen())
	{
		punto.actualizar();
		ventana.draw(punto);
		ventana.display();

		while(ventana.pollEvent(evento))
		{
			switch(evento.type)
			{
				case evento.Closed:
					ventana.close();
					break;
				case evento.KeyPressed:
					if(evento.key.code==sf::Keyboard::Key::Escape)
						ventana.close();
					break;
				default:
					break;
			}
		}
	}
	return 0;
}