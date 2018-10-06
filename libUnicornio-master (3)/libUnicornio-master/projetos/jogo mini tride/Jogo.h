#pragma once
#include "libUnicornio.h"
#include"Personagem.h"
#include"Corte.h"
#include"invisibilidade.h"
class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
	Personagem* personagem[3];
	tClasse classe;
	int cla;
	Corte  corte;
	invisibilidade invi;
	int atk;
	int tempo;
	animG anG;
	int animadorGuerrero;
};

