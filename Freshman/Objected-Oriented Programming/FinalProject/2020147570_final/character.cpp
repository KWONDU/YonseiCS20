#include "character.hpp"

//Class Character
Character::Character()
{
	life = 0;
}

Character::~Character()
{}

const int Character::getlife()
{
	return life;
}

char Character::icon()
{
	return private_icon;
}
		
void Character::setlife(const int new_life)
{
	life = new_life;
}

//Class Hunter
Hunter::Hunter()
{
	life = 7;
	step_grass = false;
}

char Hunter::icon()
{
	return private_icon;
}

//Class Tiger
Tiger::Tiger()
{
	life = 7;
	step_grass = false;
	step_food = false;
}

char Tiger::icon()
{
	return private_icon;
}

//Class Rabbit
Rabbit::Rabbit()
{
	life = 5;
	step_food = false;
}

char Rabbit::icon()
{
	return private_icon;
}

//Class Grass
char Grass::icon()
{
	return private_icon;
}

//Class Food
char Food::icon()
{
	return private_icon;
}

