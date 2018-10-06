#include "Ladrao.h"



Ladrao::Ladrao()
{
	tipo = tBandido;
}


Ladrao::~Ladrao()
{
}

void Ladrao::inicializar()
{
	if (!gRecursos.carregouSpriteSheet("Bandido"))
	{
		gRecursos.carregarSpriteSheet("Bandido", "spritesheets/Thief.png",4,4);

		sprite.setSpriteSheet("Bandido");
}
}

void Ladrao::desenhar()
{
	sprite.desenhar(x, y);
}

void Ladrao::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void Ladrao::ataqueSpecial()
{
}

void Ladrao::moverAnim()
{
	
	if (gTeclado.segurando[TECLA_D])
	{
	
		sprite.setAnimacao(dir);

	}
	else if (gTeclado.segurando[TECLA_A])
	{
		sprite.setAnimacao(esq);
	}
	else if (gTeclado.segurando[TECLA_W])
	{
		sprite.setAnimacao(cima);
	}
	else if (gTeclado.segurando[TECLA_S])
	{
		sprite.setAnimacao(baixo);
	}
}

void Ladrao::animacao()
{
	sprite.avancarAnimacao();
}
