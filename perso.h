#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>

typedef struct
{
int devant,arriere,num,num_saut,cache,attaquer;
SDL_Surface *we9ef;
SDL_Surface *marche_dev[10];
SDL_Surface *saut_dev[10];
SDL_Surface *marche_arr[10];
SDL_Surface *saut_arr[10];
SDL_Surface *cacher[7];
SDL_Surface *attaque_droite[27];
SDL_Surface *attaque_gauche[13];
SDL_Rect pos;
Mix_Chunk son_marche;
}perso;

typedef struct
{
int num;
SDL_Surface *vi[5];
SDL_Rect pos;
Mix_Chunk perdu;
Mix_Chunk blesse;
}vie;


void init_perso(perso *p,vie *v);
void load_perso(perso *p,vie *v);
void blit_we9ef(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void blit_marche_perso(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void blit_cacher(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void blit_plus_cacher(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void charger_attaque(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void deplacer_attaque(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void decharger_attaque(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void blit_attaquer(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
//void blit_saut_perso(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
//void blit_marche__saut_perso(SDL_Surface *ecran,SDL_Surface *fond,perso *p,vie *v);
void free_perso(perso *p,vie *v);




#endif



