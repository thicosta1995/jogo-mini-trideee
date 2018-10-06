#include "Jogo.h"
#include"Guerreiro.h"
#include"Ladrao.h"
#include"Mago.h"

#include"invisibilidade.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	personagem[0] = new Guerreiro;
	personagem[0]->inicializar();
	personagem[1] = new Mago;
	personagem[1]->inicializar();
	personagem[2] = new Ladrao;
	personagem[2]->inicializar();

	corte.inicializar();

	cla = 1;
 
	animadorGuerrero = 1;
	
}

void Jogo::finalizar()
{
	
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Jogo::executar()
{
	while (!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		/*	personagem[0]->desenhar();
			personagem[0]->mover();*/
		switch (cla)
		{

		case 0: classe = tGuerreiro;

			if (gTeclado.pressionou[TECLA_2])
			{
				cla = 1;

				personagem[0]->atualisar();
				personagem[1]->setX(personagem[0]->getX());
				personagem[1]->setY(personagem[0]->getY());

			}
			if (gTeclado.pressionou[TECLA_3])
			{
				cla = 2;
				personagem[2]->setX(personagem[0]->getX());
				personagem[2]->setY(personagem[0]->getY());

			}
			corte.ataqueEspecial();
			if (corte.time > 0)
			{
				if (personagem[0]->dir == true ) {

					
					corte.spriteC.desenhar(personagem[0]->getX() + 100, personagem[0]->getY());
					corte.spriteC.avancarAnimacao();
					corte.time--;
				}
				if (personagem[0]->esq == true)
			    {
					corte.spriteC.desenhar(personagem[0]->getX() - 100, personagem[0]->getY());
				corte.spriteC.avancarAnimacao();
				corte.time--;
			    }
				if (personagem[0]->baixo == true)
				{
					corte.spriteC.desenhar(personagem[0]->getX() , personagem[0]->getY()+100);
					corte.spriteC.getInverterX();

					corte.spriteC.avancarAnimacao();
					corte.time--;
				}
				if (personagem[0]->cima== true)
				{
					corte.spriteC.desenhar(personagem[0]->getX(), personagem[0]->getY() - 100);
					corte.spriteC.avancarAnimacao();
					corte.time--;
				}

					


			
			}
			else if (corte.time == 0)
			{
				if (corte.spriteC.terminouAnimacao())
				{
					corte.sprite.~Sprite();
				}
			}

				/*corte.avancarAnimaçao();*/
			/*	if (gTeclado.pressionou[TECLA_ESPACO])
				{

					corte.desenhar(personagem[0]->getX() + 100, personagem[0]->getY());
					corte.avancarAnimaçao();
				}
				*/
				/*corte.corteAtivo();*/
			/*	if (corte.spriteC.terminouAnimacao() == true)
				{
					corte.spriteC.~Sprite();

				}*/
				/*if (gTeclado.soltou[TECLA_ESPACO]) {
					corte.desenhar(personagem[0]->getX() + 100, personagem[0]->getY());
					corte.avancarAnimaçao();
					if (corte.spriteC.terminouAnimacao() == false)
						corte.avancarAnimaçao();
				}*/

				/*
				if (!corte.corteAtivar == true) {

					{
						corte.corteAtivar = true;

					}
				}
				if (corte.corteAtivar == true)
				{
					//corte.getanim();
					corte.desenhar(personagem[0]->getX() + 100, personagem[0]->getY());

					if(corte.spriteC.getFrame() !=4)
						corte.avancarAnimaçao();
					corte.corteAtivar = false;
					corte.paraAnimaçao(1000);

				}*/
				/*if (atk <= 200)
				{
					corte.corteAtivar == false;
				}*/
				/*else if (corte.corteAtivar == false)
				{

				}
*/
				{

				}


				//while (atk > 0)
				//{

				//	corte.desenhar();
				///*	
				//	personagem[0]->animacao();
				//	personagem[0]->moverAnim();
				//	personagem[0]->desenhar();
				//	personagem[0]->mover();*/
				//		atk--;

				//	



				//}
				personagem[0]->animacao();
				personagem[0]->moverAnim();
				personagem[0]->desenhar();
				personagem[0]->mover();
				/*corte.timeAnimacao();*/
				break;
		case 1: classe = tMago;

			if (gTeclado.pressionou[TECLA_1])
			{
				cla = 0;

				personagem[0]->desenhar();
				personagem[0]->setX(personagem[1]->getX());
				personagem[0]->setY(personagem[1]->getY());
			}
			if (gTeclado.pressionou[TECLA_3])
			{
				cla = 2;
				personagem[2]->setX(personagem[1]->getX());
				personagem[2]->setY(personagem[1]->getY());

			}
			personagem[1]->animacao();
			personagem[1]->moverAnim();

			personagem[1]->desenhar();
			personagem[1]->mover();
			break;
		case 2: classe = tBandido;

			if (gTeclado.pressionou[TECLA_2])
			{
				cla = 1;
				personagem[0]->atualisar();
				personagem[1]->setX(personagem[2]->getX());
				personagem[1]->setY(personagem[2]->getY());

			}
			if (gTeclado.pressionou[TECLA_1])
			{
				cla = 0;
				personagem[0]->setX(personagem[2]->getX());
				personagem[0]->setY(personagem[2]->getY());

			}
			if (gTeclado.pressionou[TECLA_ESPACO])
			{
				personagem[2]->sprite.setCorAlpha(100);

			}
			else if (gTeclado.soltou[TECLA_ESPACO])
			{
				personagem[2]->sprite.setCorAlpha(-10000);
			}

			personagem[2]->animacao();
			personagem[2]->moverAnim();

			personagem[2]->desenhar();
			personagem[2]->mover();
			break;
			}



			uniTerminarFrame();
		}
	}
 
