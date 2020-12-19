#ifndef __CHARACTER_H__
#define __CHARACTER_H__

class Character
{
	public:
		Character();	//constructor
		virtual ~Character();	//distructor
		
		//get function
		const int getlife();
		virtual char icon();
		
		//set function
		void setlife(const int new_life);
		
		bool step_grass;
		bool step_food;
	protected:
		int life;	//life
	private:
		char private_icon = '-';	//icon
};

class Hunter : public Character
{
	public:
		Hunter();	//constructor
		
		//get function
		virtual char icon();
	private:
		char private_icon = 'H';	//icon
};

class Tiger : public Character
{
	public:
		Tiger();	//constructor
		
		//get function
		virtual char icon();
	private:
		char private_icon = 'T';	//icon
};

class Rabbit : public Character
{
	public:
		Rabbit();	//constructor
		
		//get function
		virtual char icon();
	private:
		char private_icon = 'R';	//icon
};

class Grass : public Character
{
	public:
		//get function
		virtual char icon();
	private:
		char private_icon = '*';	//icon
};

class Food : public Character
{
	public:
		//get function
		virtual char icon();
	private:
		char private_icon = 'F';	//icon
};

#endif //__CHARACTER_H__

