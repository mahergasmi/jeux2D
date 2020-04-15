#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>

typedef struct
{
int devant,arriere, cache,attaquer,score;
SDL_Rect pos;
SDL_Rect posscore;
SDL_Surface *debout;
SDL_Surface *marche_dev[10];
SDL_Surface *marche_arr[10];
SDL_Surface *cacher[7];
SDL_Surface *attaque_droite[27];
SDL_Surface *attaque_gauche[8];
SDL_Surface *texte;
TTF_Font *police;
}perso;

typedef struct
{
int num;
SDL_Surface *vi[5];
SDL_Rect pos;
}vie;


void init_perso(perso *p,vie *v);
void load_perso(perso *p,vie *v);
void blit_debout(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void blit_marche_perso(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void blit_cacher(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void blit_plus_cacher(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void charger_attaque(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void deplacer_attaque(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void decharger_attaque(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void blit_attaquer(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v);
void animer_deplacer_perso(SDL_Surface *ecran,SDL_Rect camera,SDL_Surface *fond,perso *p,vie *v,int d,int g,int b,int a,int espace);
void free_perso(perso *p,vie *v);





#endif
