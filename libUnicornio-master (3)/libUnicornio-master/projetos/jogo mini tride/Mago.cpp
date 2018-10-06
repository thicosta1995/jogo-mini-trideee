#include "Mago.h"



Mago::Mago()
{
	tipo = tMago;
}


Mago::~Mago()
{
}

void Mago::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("Mago"))
	{
		gRecursos.carregarSpriteSheet("Mago", "spritesheets/Mage.png", 4, 4);
		
		sprite.setSpriteSheet("Mago");

	}
}

void Mago::desenhar()
{
	sprite.desenhar(x, y);
}

void Mago::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Mago::ataqueSpecial()
{
}

void Mago::moverAnim()
{
	if (gTeclado.segurando[TECLA_D])
	{

		sprite.setAnimacao(Mdir);

	}
	else if (gTeclado.segurando[TECLA_A])
	{
		sprite.setAnimacao(Mesq);
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		sprite.setAnimacao(Mcima);
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		sprite.setAnimacao(Mbaixo);
	}
}

void Mago::animacao()
{
	sprite.avancarAnimacao();
}
