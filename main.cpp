#include <SFML/Graphics.hpp>

#include "punto.hpp"
#include "ejes.hpp"
/****************************************************************/
#define anchoP 201
#define altoP 201

/****************************************************************/
int main(int argc, char const *argv[])
{
	sf::RenderWindow ventana(sf::VideoMode(anchoP,altoP),"Graficadora");
	sf::Event evento;

	ventana.setVerticalSyncEnabled(true);
	ventana.setMouseCursorVisible(false);

	Punto punto;
	Ejes ejes;
	punto.graficar();

	while(ventana.isOpen())
	{
		ejes.actualizar();
		punto.actualizar();

		ventana.draw(punto);
		ventana.draw(ejes);

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