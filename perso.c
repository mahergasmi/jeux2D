#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include "perso.h"

void init_perso(perso *p,vie *v)
{
   int i;
   p->devant=1;
   p->arriere=0;
   p->cache=0;
   p->attaquer=0;
   p->pos.x=0;
   p->pos.y=400;
   v->num=0;//ce compteur va augmenter lorsque le personnage sera blessé (v->num)++ pour afficher l'image de la vie quand elle diminue
   v->pos.x=0;
   v->pos.y=0;
   p->score=0;
   p->posscore.x=0;
   p->posscore.y=0;
   p->debout=NULL;
   p->texte=NULL;
   for(i=0;i<9;i++)
	{
	    p->marche_dev[i]=NULL;
	}

   for(i=0;i<9;i++)
	{
	    p->marche_arr[i]=NULL;
	}
   for(i=0;i<7;i++)
	{
	    p->cacher[i]=NULL;
	}
   for(i=0;i<27;i++)
	{
	    p->attaque_droite[i]=NULL;
	}
   for(i=0;i<13;i++)
	{
	    p->attaque_gauche[i]=NULL;
	}
   for(i=0;i<5;i++)
	{
	    v->vi[i]=NULL;
	}
}

void load_perso(perso *p,vie *v)
{
   int i;
   char nom_image[10],ch[10];
   SDL_Color couleur={0,255,0};
   for(i=0;i<9;i++)
	{   
	    sprintf(nom_image,"md%d.png",i+1);
	    p->marche_dev[i]=IMG_Load(nom_image);
	}
   for(i=0;i<9;i++)
	{   
	    sprintf(nom_image,"ma%d.png",i+1);
	    p->marche_arr[i]=IMG_Load(nom_image);
	}
   for(i=0;i<7;i++)
	{   
	    sprintf(nom_image,"cache%d.png",i+1);
	    p->cacher[i]=IMG_Load(nom_image);
	}
   for(i=0;i<27;i++)
	{   
	    sprintf(nom_image,"attaqued%d.png",i+1);
	    p->attaque_droite[i]=IMG_Load(nom_image);
	}
   for(i=0;i<13;i++)
	{   
	    sprintf(nom_image,"attaqueg%d.png",i+1);
	    p->attaque_gauche[i]=IMG_Load(nom_image);
	}
   for(i=0;i<5;i++)
	{
	    sprintf(nom_image,"vie%d.png",i+1);
	    v->vi[i]=IMG_Load(nom_image);
	}
   p->police=TTF_OpenFont("labo.ttf",60);
   sprintf(ch,"Score: %d",p->score);
   p->texte=TTF_RenderText_Blended(p->police,ch,couleur);
}

void blit_debout(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
   SDL_BlitSurface(fond,NULL,ecran,&pos);
   if(p->devant==1)
         p->debout=IMG_Load("we9ef.png");
   if(p->arriere==1)
         p->debout=IMG_Load("we9efa.png");
   SDL_BlitSurface(p->debout,NULL,ecran,&p->pos);
   SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
   SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
   SDL_Flip(ecran);
}
void blit_marche_perso(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   int i;
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
   if(p->devant==1) {
		      for(i=0;i<9;i++)
	                {  
			   SDL_BlitSurface(fond,NULL,ecran,&pos);
			   if(p->pos.x<590)  p->pos.x=p->pos.x+10;
	    		   SDL_BlitSurface(p->marche_dev[i],NULL,ecran,&p->pos);
                           SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
			   SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
                           SDL_Flip(ecran);
	                }
		      }

   if(p->arriere==1) {
		      for(i=0;i<9;i++)
	                {
			   SDL_BlitSurface(fond,NULL,ecran,&pos);
			   if(p->pos.x>10)   p->pos.x=p->pos.x-10;
	    		   SDL_BlitSurface(p->marche_arr[i],NULL,ecran,&p->pos);
                           SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
                           SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
                           SDL_Flip(ecran);
	                }
		     }
}
void blit_cacher(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   int i;
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
   for(i=0;i<7;i++)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->cacher[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }		      
}

void blit_plus_cacher(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   int i;
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
   for(i=6;i>=0;i--)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->cacher[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }
}

void charger_attaque(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   int i;
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
if(p->devant==1)
{
   for(i=0;i<8;i++)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->attaque_droite[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }
}
if(p->arriere==1)
{
   for(i=0;i<8;i++)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->attaque_gauche[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }
}

}

void decharger_attaque(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   int i;
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
if(p->devant==1)
{
   for(i=7;i>=0;i--)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->attaque_droite[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }
}
if(p->arriere==1)
{
   for(i=7;i>=0;i--)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->attaque_gauche[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }
}
}

void blit_attaquer(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   int i;
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
if(p->devant==1)
{
   for(i=8;i<27;i++)
   {  
      SDL_BlitSurface(fond,NULL,ecran,&pos);
      SDL_BlitSurface(p->attaque_droite[i],NULL,ecran,&p->pos);
      SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
      SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
      SDL_Flip(ecran);
   }
}
}

void deplacer_attaque(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v)
{
   SDL_Rect pos;
   pos.x=0;
   pos.y=0;
   if(p->devant==1)
   {
   p->pos.x=p->pos.x+10;
   SDL_BlitSurface(fond,NULL,ecran,&pos);
   SDL_BlitSurface(p->attaque_droite[7],NULL,ecran,&p->pos);
   SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
   SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
   SDL_Flip(ecran);
   }
  
   if(p->arriere==1)
   {
   p->pos.x=p->pos.x-10;
   SDL_BlitSurface(fond,NULL,ecran,&pos);
   SDL_BlitSurface(p->attaque_gauche[7],NULL,ecran,&p->pos);
   SDL_BlitSurface(p->texte,NULL,ecran,&p->posscore);
   SDL_BlitSurface(v->vi[v->num],NULL,ecran,&v->pos);
   SDL_Flip(ecran);
   }
}
void free_perso(perso *p,vie *v)
{
   int i;
   TTF_CloseFont(p->police);
   TTF_Quit();
   for(i=0;i<9;i++)
   {
      SDL_FreeSurface(p->marche_dev[i]);
      SDL_FreeSurface(p->marche_arr[i]);
   }
   for(i=0;i<7;i++)
   {
      SDL_FreeSurface(p->cacher[i]);
   }
  
   for(i=0;i<5;i++)
   {
      SDL_FreeSurface(v->vi[i]);
   }
   SDL_FreeSurface(p->texte);
   
}
