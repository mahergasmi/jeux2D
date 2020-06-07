#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

#include<SDL/SDL.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL_ttf.h>
#include"ennemi.h"
#include"minimap.h"
#include"object.h"
/**
*@struct perso
*@brief struct for the hero
*/
typedef struct
{
int devant,arriere, cache,attaquer,score;
SDL_Rect pos;
SDL_Rect posscore;
SDL_Surface *debout;
SDL_Surface *marche_dev[9];
SDL_Surface *marche_arr[9];
SDL_Surface *cacher[7];
SDL_Surface *attaque_droite[26];
SDL_Surface *attaque_gauche[8];
SDL_Surface *texte;
TTF_Font *police;
}perso;

/**
*@struct vie
*@brief struct for the life of the hero
*/
typedef struct
{
int num;
SDL_Surface *vi[5];
SDL_Rect pos;
}vie;

/**
*@brief to initalize the hero
*@param hero
*@param life of the hero
*/
void init_perso(perso *p,vie *v);

/**
*@brief to load the images of the hero anf his life
*@param hero
*@param life of the hero
*/
void load_perso(perso *p,vie *v);

/**
*@brief to blit the hero when he's not moving
*@param hero
*@brief all the rest of the params is for the blit because in our game all the blits are in the hero fonctions because we used (for) to do the animation of the hero
*/
void blit_debout(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero walking
*@param hero
*/
void blit_marche_perso(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,int d,int g,int h,int jump,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero when he's hiding
*@param hero
*/
void blit_cacher(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero when he's done hiding
*@param hero
*/
void blit_plus_cacher(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero when he charge his attack
*@param hero
*/
void charger_attaque(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero when he moves while the attack is charging
*@param hero
*/
void deplacer_attaque(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,int d,int g,int h,int jump,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero while discharging his attack
*@param hero
*/
void decharger_attaque(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);
/**
*@brief to animate the hero when he attacks
*@param hero
*/
void blit_attaquer(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief in this function we called all the previous functions concerning the hero 
*@param hero
*/
void animation_jeu(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v,int d,int g,int b,int a,int espace,int h,int jump,ennemi *enn,SDL_Surface *texte_temps,SDL_Rect pos_temps,mini *minimap,OBJECT *obj);

/**
*@brief to animate the hero when he won at the end of the game
*@param hero
*/
void fin_jeu_animation(SDL_Surface *ecran,SDL_Rect *camera,SDL_Surface *fond,perso *p,vie *v);

/**
*@brief to free the hero and the life 
*@param hero
*@param life of the hero
*/
void free_perso(perso *p,vie *v);

#endif
