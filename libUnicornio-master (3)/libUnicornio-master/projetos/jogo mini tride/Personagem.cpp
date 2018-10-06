#include "Personagem.h"



Personagem::Personagem()
{
	x = 400;	
	y = 300;
	vel = 2;
}


Personagem::~Personagem()
{
}

void Personagem::inicializar()
{
}

void Personagem::setPosInicial(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Personagem::atualisar()
{

}

void Personagem::atqueEspecial()
{
}





void Personagem::setX(int aux)
{
	x = aux;
}

void Personagem::setY(int aux)
{
	y = aux;
}

void Personagem::desenhar()
{
}

void Personagem::setVel(float vel)
{
}

void Personagem::mover()
{
	if (gTeclado.segurando[TECLA_D])
	{
		x += vel + 2;


	}
	else if (gTeclado.segurando[TECLA_A])
	{
		x -= vel + 2;

	}
	else if (gTeclado.segurando[TECLA_W])
	{
		y -= vel + 2;
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		y += vel + 2;
	}

}

void Personagem::moverAnim()
{
}

void Personagem::desenharAtk()
{
}

void Personagem::animacao()
{
}
