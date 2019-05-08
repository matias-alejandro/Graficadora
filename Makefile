#Makefile

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJS = main.o punto.o

all: Graficadora

%.o: %.cpp
	g++ -c $< -o $@

%.o: %.hpp
	g++ -c $< -o $@

Graficadora: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS)

clean:
	rm -f Graficadora *.o