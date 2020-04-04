#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>
#include"perso.h"

int main(int arg,char *argc)
{
   perso p;
   vie v;
SDL_Surface *ecran=NULL,*fond=NULL;
SDL_Init(SDL_INIT_VIDEO);
TTF_Init();
   SDL_Event event;
   int continuer=1;
   init_perso(&p,&v);
ecran=SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE||SDL_DOUBLEBUF);
   fond=IMG_Load("background.png");//ce backround est juste pour tester le travail et il sera changer au cours de l'integration par le vrai backround qui bouge
   load_perso(&p,&v);
   while(continuer)
   {  
      if((p.cache==0)&&(p.attaquer==0)) 
         blit_we9ef(ecran,fond,&p,&v);
      SDL_PollEvent(&event);
      switch(event.type)
      {
         case SDL_QUIT: 
                         continuer=0;
                         break;
  
         case SDL_KEYDOWN:
                             switch(event.key.keysym.sym)
                             {

			         /*case SDLK_UP:  
						blit_saut_perso(ecran,fond,&p,&v);
						break;*/

			         case SDLK_RIGHT:
						   if(p.cache==1)
						      blit_plus_cacher(ecran,fond,&p,&v);

						   if(p.attaquer==1)
						   {
                                                      if((p.devant==0)&&(p.arriere==1)) 
                                                      {
                                                         p.devant=1;p.arriere=0;
                                                         charger_attaque(ecran,fond,&p,&v);
                                                      }
						      if(p.pos.x<600)
						         {
                                                            p.devant=1;p.arriere=0;
                                                            deplacer_attaque(ecran,fond,&p,&v);
							 }
							//la camera avance vers la droite et le perso est en position d'attaque
						   }else
					  	   {
						      p.devant=1;p.arriere=0;p.cache=0;p.attaquer=0;
						      blit_marche_perso(ecran,fond,&p,&v);
						   }
						   break;
			         case SDLK_LEFT:
						   if(p.cache==1)
						      blit_plus_cacher(ecran,fond,&p,&v);

						   if(p.attaquer==1)
						   {
                                                      if((p.devant==1)&&(p.arriere==0))
                                                      {
                                                         p.devant=0;p.arriere=1;
                                                         charger_attaque(ecran,fond,&p,&v);
                                                      }
                                                      if(p.pos.x>0)
						         {
                                                            p.devant=0;p.arriere=1;
                                                            deplacer_attaque(ecran,fond,&p,&v);
							 }

							//la camera avance vers la gauche et le perso est en position d'attaque
						   }else
						   {
						      p.arriere=1;p.devant=0;p.cache=0;p.attaquer=0;
						      blit_marche_perso(ecran,fond,&p,&v);
						   }
						   break;
				 case SDLK_DOWN:  
                                                   p.cache=1;p.attaquer=0;
						   blit_cacher(ecran,fond,&p,&v);
						   break;
				 case SDLK_a:
						   if(p.attaquer==1)
						   {
						      decharger_attaque(ecran,fond,&p,&v);
						      p.attaquer=0;p.cache=0;
						   }else
						   { 
						      charger_attaque(ecran,fond,&p,&v);
						      p.attaquer=1;p.cache=0;
						   }
						   break;
				 case SDLK_SPACE: 
						   if(p.attaquer==1)
						      blit_attaquer(ecran,fond,&p,&v);

                             }
      }
   }
   free_perso(&p,&v);
   SDL_FreeSurface(fond);
   SDL_Quit();
return EXIT_SUCCESS;
}
