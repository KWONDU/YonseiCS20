#include <iostream>
#include <string>
#include <random>
#include "character.hpp"

//sort int array : from lowest to higest using bubble sort
void intsort(int temp[], int len)
{
	int inttemp;
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - i - 1; j++)
			if (temp[j] > temp[j + 1])
			{
				inttemp = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = inttemp;
			}
}

//delete array's element
int* deletearr(int temp[], int &len, int delnum)
{
	int delpos = 0;
	while (delpos < len)
	{
		if (temp[delpos] == delnum)
			break;
		delpos++;
	}
	if (delpos < len)
	{
		int deltemp[len - 1];
		for (int i = 0; i < len; i++)
		{
			if (i < delpos)
				deltemp[i] = temp[i];
			else if (i > delpos)
				deltemp[i - 1] = temp[i];
		}
		delete temp;
		temp = new int[len - 1];
		for (int i = 0; i < len - 1; i++)
			temp[i] = deltemp[i];
	}
	len--;
	
	return temp;
}

//add array's element
int* addarr(int temp[], int &len, int addnum)
{
	int addtemp[len + 1];
	for (int i = 0; i < len; i++)
		addtemp[i] = temp[i];
	addtemp[len] = addnum;
	
	delete temp;
	temp = new int[len + 1];
	for (int i = 0; i < len + 1; i++)
		temp[i] = addtemp[i];
	len++;
	intsort(temp, len);
	
	return temp;
}

int main()
{
	/*##################################################################################################
	
	
	
												Initialization
	
	
	
	##################################################################################################*/
	//create world
	int height, width;
	std::cout << "Enter grid height: ";
	std::cin >> height;
	std::cout << "Enter grid width: ";
	std::cin >> width;
	Character* world[height][width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			world[i][j] = new Character();
	
	//initial state
	int hnum = 1, tnum, rnum, gnum;
	std::cout << "\n";
	std::cout << "Enter initial number of grasses: ";
	std::cin >> gnum;
	std::cout << "Enter initial number of rabbits: ";
	std::cin >> rnum;
	std::cout << "Enter initial number of tigers: ";
	std::cin >> tnum;
	std::cout << "\n";
	int *allh = new int[1];
	int *allt = new int[tnum];
	int *allr = new int[rnum];
	int *allg = new int[gnum];
	
	//use random libray
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, height * width - 1);
	
	int init_num = gnum + rnum + tnum + 1;
	bool init_state[height * width];
	for (int i = 0; i < height * width; i++)
		init_state[i] = true;
	while (init_num > 0)
	{
		//set hunter's initial position
		while (init_num > gnum + rnum + tnum)
		{
			int init_hpos = dis(gen);
			if (init_state[init_hpos] == true)
			{
				init_state[init_hpos] = false;
				allh[0] = init_hpos;
				delete world[init_hpos / width][init_hpos % width];
				world[init_hpos / width][init_hpos % width] = new Hunter();
				init_num--;
			}
		}
		
		//set tigers's initial position
		while (init_num > gnum + rnum)
		{
			int init_tpos = dis(gen);
			if (init_state[init_tpos] == true)
			{
				init_state[init_tpos] = false;
				allt[gnum + rnum + tnum - init_num] = init_tpos;
				delete world[init_tpos / width][init_tpos % width];
				world[init_tpos / width][init_tpos % width] = new Tiger();
				init_num--;
			}
		}
		
		//set rabbits's initial position
		while (init_num > gnum)
		{
			int init_rpos = dis(gen);
			if (init_state[init_rpos] == true)
			{
				init_state[init_rpos] = false;
				allr[gnum + rnum - init_num] = init_rpos;
				delete world[init_rpos / width][init_rpos % width];
				world[init_rpos / width][init_rpos % width] = new Rabbit();
				init_num--;
			}
		}
		
		//set grass's initial position
		int init_gpos = dis(gen);
		if (init_state[init_gpos] == true)
		{
			init_state[init_gpos] = false;
			allg[gnum - init_num] = init_gpos;
			delete world[init_gpos / width][init_gpos % width];
			world[init_gpos / width][init_gpos % width] = new Grass();
			init_num--;
		}
	}
	
	intsort(allt, tnum);
	intsort(allr, rnum);
	intsort(allg, gnum);
	
	/*##################################################################################################
	
	
	
								   Survival game - Save Rabbits from Tigers



	##################################################################################################*/
	//game loop
	int step = 1;
	bool chk = true;
	while (chk)
	{
		//print world
		std::cout << "\n";
		std::cout << "==================================================\n\n";
		std::cout << "Time Step: " << step << "		Life: " << world[allh[0] / width][allh[0] % width]->getlife() << "\n";
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				std::cout << world[i][j]->icon() << " ";
			std::cout << "\n";
		}
		std::cout << "\n";
		
		/*#######################
		   #1. Hunter's action
		#######################*/
		
		int move_or_shoot;
		std::cout << "Select next command [0: move / 1: shoot]: ";
		std::cin >> move_or_shoot;
		
		//hunter move
		if (move_or_shoot == 0)
		{
			int move_direction;
			std::cout << "Enter the direction [0: up / 1: down / 2: right / 3: left]: ";
			std::cin >> move_direction;
			
			//simplify
			int h = allh[0] / width;
			int w = allh[0] % width;
			bool hunter_eat_food = false;
			switch (move_direction)
			{
				case 0:	//up
					if (h > 0 && (world[h - 1][w]->icon() != 'T' && world[h - 1][w]->icon() != 'R'))
					{
						//hunter eat food
						if (world[h - 1][w]->icon() == 'F')
							hunter_eat_food = true;
						
						//move:up action
						if (world[h - 1][w]->icon() == '*')	//after action, hunter steps on grass
						{
							delete world[h - 1][w];
							world[h - 1][w] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h - 1][w]->step_grass = true;
						}
						else	//after action, humter doesn't step on grass
						{
							delete world[h - 1][w];
							world[h - 1][w] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h - 1][w]->step_grass = false;
						}
						allh[0] -= width;
					}
					break;
				case 1: //down
					if (h < height - 1 && (world[h + 1][w]->icon() != 'T' && world[h + 1][w]->icon() != 'R'))
					{
						//hunter eat food
						if (world[h + 1][w]->icon() == 'F')
							hunter_eat_food = true;
							
						//move:down action
						if (world[h + 1][w]->icon() == '*')	//after action, hunter steps on grass
						{
							delete world[h + 1][w];
							world[h + 1][w] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h + 1][w]->step_grass = true;
						}
						else	//after action, humter doesn't step on grass
						{
							delete world[h + 1][w];
							world[h + 1][w] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h + 1][w]->step_grass = false;
						}
						allh[0] += width;
					}
					break;
				case 2: //right
					if (w < width - 1 && (world[h][w + 1]->icon() != 'T' && world[h][w + 1]->icon() != 'R'))
					{
						//hunter eat food
						if (world[h][w + 1]->icon() == 'F')
							hunter_eat_food = true;
							
						//move:down action
						if (world[h][w + 1]->icon() == '*')	//after action, hunter steps on grass
						{
							delete world[h][w + 1];
							world[h][w + 1] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h][w + 1]->step_grass = true;
						}
						else	//after action, humter doesn't step on grass
						{
							delete world[h][w + 1];
							world[h][w + 1] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h][w + 1]->step_grass = false;
						}
						allh[0] += 1;
					}
					break;
				case 3: //left
					if (w > 0 && (world[h][w - 1]->icon() != 'T' && world[h][w - 1]->icon() != 'R'))
					{
						//hunter eat food
						if (world[h][w - 1]->icon() == 'F')
							hunter_eat_food = true;
							
						//move:down action
						if (world[h][w - 1]->icon() == '*')	//after action, hunter steps on grass
						{
							delete world[h][w - 1];
							world[h][w - 1] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h][w - 1]->step_grass = true;
						}
						else	//after action, humter doesn't step on grass
						{
							delete world[h][w - 1];
							world[h][w - 1] = world[h][w];
							if (world[h][w]->step_grass == true)
								world[h][w] = new Grass();
							else
								world[h][w] = new Character();
							world[h][w - 1]->step_grass = false;
						}
						allh[0] -= 1;
					}
					break;
				default:
					std::cout << "unexpected error : direction error" << std::endl;	//error
					break;
			}
			
			//life change
			if (hunter_eat_food == true)
				world[allh[0] / width][allh[0] % width]->setlife(7);
			else
				world[allh[0] / width][allh[0] % width]->setlife(world[allh[0] / width][allh[0] % width]->getlife() - 1);
		}
		
		//hunter shoot
		else if (move_or_shoot == 1)
		{
			int move_direction;
			std::cout << "Enter the direction [0: up / 1: down / 2: right / 3: left]: ";
			std::cin >> move_direction;
			
			//simplify
			int h = allh[0] / width;
			int w = allh[0] % width;
			bool shoot_chk = false;
			switch (move_direction)
			{
				case 0:	//up
					while (h >= 0)
					{
						if (world[h][w]->icon() == 'T' || world[h][w]->icon() == 'R')
						{
							shoot_chk = true;
							break;
						}
						h--;
					}
					break;
				case 1:	//down
					while (h < height)
					{
						if (world[h][w]->icon() == 'T' || world[h][w]->icon() == 'R')
						{
							shoot_chk = true;
							break;
						}
						h++;
					}
					break;
				case 2:	//right
					while (w < width)
					{
						if (world[h][w]->icon() == 'T' || world[h][w]->icon() == 'R')
						{
							shoot_chk = true;
							break;
						}
						w++;
					}
					break;
				case 3:	//left
					while (w >= 0)
					{
						if (world[h][w]->icon() == 'T' || world[h][w]->icon() == 'R')
						{
							shoot_chk = true;
							break;
						}
						w--;
					}
					break;
				default:
					std::cout << "unexpected error : direction error" << std::endl;	//error
					break;
			}
			
			//if hunter shoots animanl(tiger or rabbit)
			if (shoot_chk)
			{	
				if (world[h][w]->icon() == 'T')	//if hunter shoots tiger
				{
					allt = deletearr(allt, tnum, h * width + w);
					if (world[h][w]->step_grass == true)	//if tiger steps on grass
						deletearr(allg, gnum, h * width + w);
				}
				else	//if hunter shoots rabbit
					allr = deletearr(allr, rnum, h * width + w);
				
				delete world[h][w];
				world[h][w] = new Food();
			}
		
			//life change
			world[allh[0] / width][allh[0] % width]->setlife(world[allh[0] / width][allh[0] % width]->getlife() - 1);
		}
		else
		{
			std::cout << "unexpected error : command error" << std::endl;	//error
			
			//life change
			world[allh[0] / width][allh[0] % width]->setlife(world[allh[0] / width][allh[0] % width]->getlife() - 1);
		}
		
		//hunter die
		if (world[allh[0] / width][allh[0] % width]->getlife() == 0)
		{
			if(world[allh[0] / width][allh[0] % width]->step_grass == true)
			{
				delete world[allh[0] / width][allh[0] % width];
				world[allh[0] / width][allh[0] % width] = new Grass();
			}
			else
			{
				delete world[allh[0] / width][allh[0] % width];
				world[allh[0] / width][allh[0] % width] = new Character();
			}
			allh = deletearr(allh, hnum, allh[0]);
		}
		
		/*#######################
		   #2. Tiger's action
		#######################*/
		
		bool tiger_breed = false;
		for (int i = 0; i < tnum; i++)	//from the top left to the bottom right
		{
			//for every 10 steps, tigers breed
			if (step % 10 == 0)
			{
				tiger_breed = true;
				break;
			}
			
			//simplify
			int h = allt[i] / width;
			int w = allt[i] % width;
			
			std::string hunter_exist = "";
			std::string rabbit_exist = "";
			std::string etc = "";
			
			//classification
			if (h > 0)	//up
			{
				if (world[h - 1][w]->icon() == 'H')
					hunter_exist += "0";
				else if (world[h - 1][w]->icon() == 'R')
					rabbit_exist += "0";
				else if (world[h - 1][w]->icon() != 'T')
					etc += "0";
			}
			if (h < height - 1)	//down
			{	
				if (world[h + 1][w]->icon() == 'H')
					hunter_exist += "1";
				else if (world[h + 1][w]->icon() == 'R')
					rabbit_exist += "1";
				else if (world[h + 1][w]->icon() != 'T')
					etc += "1";
			}
			if (w < width - 1)	//right
			{
				if (world[h][w + 1]->icon() == 'H')
					hunter_exist += "2";
				else if (world[h][w + 1]->icon() == 'R')
					rabbit_exist += "2";
				else if (world[h][w + 1]->icon() != 'T')
					etc += "2";
			}
			if (w > 0)	//left
			{
				if (world[h][w - 1]->icon() == 'H')
					hunter_exist += "3";
				else if (world[h][w - 1]->icon() == 'R')
					rabbit_exist += "3";
				else if (world[h][w - 1]->icon() != 'T')
					etc += "3";
			}

			bool next_step_grass = false;
			bool next_step_food = false;
			bool starve_chk = false;
			if (hunter_exist != "")	//tiger eat hunter
			{
				switch (std::stoi(hunter_exist))
				{
					case 0:	//up
						if (world[h - 1][w]->step_grass == true)
							next_step_grass = true;
						allh = deletearr(allh, hnum, (h - 1) * width + w);
						allt[i] -= width;
						break;
					case 1:	//down
						if (world[h + 1][w]->step_grass == true)
							next_step_grass = true;
						allh = deletearr(allh, hnum, (h + 1) * width + w);
						allt[i] += width;
						break;
					case 2:	//right
						if (world[h][w + 1]->step_grass == true)
							next_step_grass = true;
						allh = deletearr(allh, hnum, h * width + (w + 1));
						allt[i] += 1;
						break;
					case 3:	//left
						if (world[h][w - 1]->step_grass == true)
							next_step_grass = true;
						allh = deletearr(allh, hnum, h * width + (w - 1));
						allt[i] -= 1;
						break;
					default:
						break;
				}
				
				//life change
				world[h][w]->setlife(world[h][w]->getlife() - 1);
			}
			else if (rabbit_exist != "")	//tigher eat rabbit
			{
				//use random library
				std::random_device rd_2_1;
				std::mt19937 gen_2_1(rd_2_1());
				std::uniform_int_distribution<int> dis_2_1(0, rabbit_exist.length() - 1);

				switch (rabbit_exist[dis_2_1(gen_2_1)] - '0')
				{
					case 0:	//up
						if (world[h - 1][w]->step_food == true)
							next_step_food = true;
						allr = deletearr(allr, rnum, (h - 1) * width + w);
						allt[i] -= width;
						break;
					case 1:	//down
						if (world[h + 1][w]->step_food == true)
							next_step_food = true;
						allr = deletearr(allr, rnum, (h + 1) * width + w);
						allt[i] += width;
						break;
					case 2:	//right
						if (world[h][w + 1]->step_food == true)
							next_step_food = true;
						allr = deletearr(allr, rnum, h * width + (w + 1));
						allt[i] += 1;
						break;
					case 3:	//left
						if (world[h][w - 1]->step_food == true)
							next_step_food = true;
						allr = deletearr(allr, rnum, h * width + (w - 1));
						allt[i] -= 1;
						break;
					default:
						break;
				}
				
				//life change
				world[h][w]->setlife(7);
			}
			else
			{
				//life change
				world[h][w]->setlife(world[h][w]->getlife() - 1);
				
				//tiger starvation
				if (world[h][w]->getlife() == 0)
				{
					starve_chk = true;
					if (world[h][w]->step_grass == true)
					{
						delete world[h][w];
						world[h][w] = new Grass();
					}
					else if (world[h][w]->step_food == true)
					{
						delete world[h][w];
						world[h][w] = new Food();
					}
					else
					{
						delete world[h][w];
						world[h][w] = new Character();
					}
					allt = deletearr(allt, tnum, h * width + w);
				}
				
				if (etc != "")
				{
					//use random library
					std::random_device rd_2_2;
					std::mt19937 gen_2_2(rd_2_2());
					std::uniform_int_distribution<int> dis_2_2(0, etc.length() - 1);
					
					switch (etc[dis_2_2(gen_2_2)] - '0')
					{
						case 0:	//up
							if (world[h - 1][w]->icon() == '*')
								next_step_grass = true;
							else if (world[h - 1][w]->icon() == 'F')
								next_step_food = true;
							allt[i] -= width;
							break;
						case 1:	//down
							if (world[h + 1][w]->icon() == '*')
								next_step_grass = true;
							else if (world[h + 1][w]->icon() == 'F')
								next_step_food = true;
							allt[i] += width;
							break;
						case 2:	//right
							if (world[h][w + 1]->icon() == '*')
								next_step_grass = true;
							else if (world[h][w + 1]->icon() == 'F')
								next_step_food = true;
							allt[i] += 1;
							break;
						case 3:	//left
							if (world[h][w - 1]->icon() == '*')
								next_step_grass = true;
							else if (world[h][w - 1]->icon() == 'F')
								next_step_food = true;
							allt[i] -= 1;
							break;
						default:
							break;
					}
				}
			}
			
			//tiger move
			if (starve_chk == false)
			{
				if(hunter_exist != "" || rabbit_exist != "" || etc != "")
				{
					delete world[allt[i] / width][allt[i] % width];
					world[allt[i] / width][allt[i] % width] = world[h][w];
					
					if (world[h][w]->step_grass == true)
						world[h][w] = new Grass();
					else if (world[h][w]->step_food == true)
						world[h][w] = new Food();
					else
						world[h][w] = new Character();
					
					if (next_step_grass == true)
					{
						world[allt[i] / width][allt[i] % width]->step_grass = true;
						world[allt[i] / width][allt[i] % width]->step_food = false;
					}
					else if (next_step_food == true)
					{
						world[allt[i] / width][allt[i] % width]->step_grass = false;
						world[allt[i] / width][allt[i] % width]->step_food = true;
					}
					else
					{
						world[allt[i] / width][allt[i] % width]->step_grass = false;
						world[allt[i] / width][allt[i] % width]->step_food = false;
					}
				}
			}
		}
		
		/*#######################
		   #3. Rabbit's action
		#######################*/
		
		bool rabbit_breed = false;
		for (int i = 0; i < rnum; i++)	//from the top left to the bottom right
		{
			//for every 7 steps, rabbits breed
			if (step % 7 == 0)
			{
				rabbit_breed = true;
				break;
			}
			
			//simplify
			int h = allr[i] / width;
			int w = allr[i] % width;
			
			std::string grass_exist = "";
			std::string etc = "";
			
			//classification
			if (h > 0)	//up
			{
				if (world[h - 1][w]->icon() == '*')
					grass_exist += "0";
				else if (world[h - 1][w]->icon() != 'H' && world[h - 1][w]->icon() != 'T' && world[h - 1][w]->icon() != 'R')
					etc += "0";
			}
			if (h < height - 1)	//down
			{
				if (world[h + 1][w]->icon() == '*')
					grass_exist += "1";
				else if (world[h + 1][w]->icon() != 'H' && world[h + 1][w]->icon() != 'T' && world[h + 1][w]->icon() != 'R')
					etc += "1";
			}
			if (w < width - 1)	//right
			{
				if (world[h][w + 1]->icon() == '*')
					grass_exist += "2";
				else if (world[h][w + 1]->icon() != 'H' && world[h][w + 1]->icon() != 'T' && world[h][w + 1]->icon() != 'R')
					etc += "2";
			}
			if (w > 0)	//left
			{
				if (world[h][w - 1]->icon() == '*')
					grass_exist += "3";
				else if (world[h][w - 1]->icon() != 'H' && world[h][w - 1]->icon() != 'T' && world[h][w - 1]->icon() != 'R')
					etc += "3";
			}
			
			bool next_step_food = false;
			bool starve_chk = false;
			if (grass_exist != "")	//rabbit eat grass
			{
				//use random library
				std::random_device rd_3_1;
				std::mt19937 gen_3_1(rd_3_1());
				std::uniform_int_distribution<int> dis_3_1(0, grass_exist.length() - 1);
				
				switch(grass_exist[dis_3_1(gen_3_1)] - '0')
				{
					case 0:	//up
						allg = deletearr(allg, gnum, (h - 1) * width + w);
						allr[i] -= width;
						break;
					case 1:	//down
						allg = deletearr(allg, gnum, (h + 1) * width + w);
						allr[i] += width;
						break;
					case 2:	//right
						allg = deletearr(allg, gnum, h * width + (w + 1));
						allr[i] += 1;
						break;
					case 3:	//left
						allg = deletearr(allg, gnum, h * width + (w - 1));
						allr[i] -= 1;
						break;
					default:
						break;
				}
				
				//life change
				world[h][w]->setlife(5);
			}
			else
			{
				//life change
				world[h][w]->setlife(world[h][w]->getlife() - 1);
				
				//rabbit starvation
				if (world[h][w]->getlife() == 0)
				{
					starve_chk = true;
					if (world[h][w]->step_food == true)
					{
						delete world[h][w];
						world[h][w] = new Food();
					}
					else
					{
						delete world[h][w];
						world[h][w] = new Character();
					}
					allr = deletearr(allr, rnum, h * width + w);
				}
				
				if (etc != "")
				{
					//use random library
					std::random_device rd_3_2;
					std::mt19937 gen_3_2(rd_3_2());
					std::uniform_int_distribution<int> dis_3_2(0, etc.length() - 1);
					
					switch(etc[dis_3_2(gen_3_2)] - '0')
					{
						case 0:	//up
							if (world[h - 1][w]->icon() == 'F')
								next_step_food = true;
							allr[i] -= width;
							break;
						case 1:
							if (world[h + 1][w]->icon() == 'F')
								next_step_food = true;
							allr[i] += width;
							break;
						case 2:
							if (world[h][w + 1]->icon() == 'F')
								next_step_food = true;
							allr[i] += 1;
							break;
						case 3:
							if (world[h][w - 1]->icon() == 'F')
								next_step_food = true;
							allr[i] -= 1;
							break;
						default:
							break;
					}
				}
 			}
 			
	 		//rabbit move
	 		if (starve_chk == false)
			{
				if (grass_exist != "" || etc != "")
				{
					delete world[allr[i] / width][allr[i] % width];
					world[allr[i] / width][allr[i] % width] = world[h][w];
					
					if (world[h][w]->step_food == true)
						world[h][w] = new Food();
					else
						world[h][w] = new Character();
						
					if (next_step_food == true)
						world[allr[i] / width][allr[i] % width]->step_food = true;
					else
						world[allr[i] / width][allr[i] % width]->step_food = false;
				}
			}
		}
		
		/*#######################
		   #4. Grass generation
		#######################*/
		
		//find all empty cells
		int empty_len = 0;
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (world[i][j]->icon() == '-')
					empty_len++;
		int* empty = new int[empty_len];
		int k = 0;
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (world[i][j]->icon() == '-')
				{
					empty[k] = i * width + j;
					k++;
				}
		
		//use random library
		std::random_device rd_4;
		std::mt19937 gen_4(rd_4());
		std::uniform_int_distribution<int> dis_4(0, 9);
		
		for (int i = 0; i < empty_len; i++)
			if (dis_4(gen_4) == 0)
			{
				delete world[empty[i] / width][empty[i] % width];
				world[empty[i] / width][empty[i] % width] = new Grass();
			}
		
		/*#######################
		   #5. Breed				//end of the time step
		#######################*/
		
		//tiger_breed
		if (tiger_breed == true)
		{
			//temporary data
			int temp_tnum = tnum;
			int temp_allt[temp_tnum];
			for (int i = 0; i < temp_tnum; i++)
				temp_allt[i] = allt[i];
			
			for (int i = 0; i < temp_tnum; i++)
			{
				//simplify
				int h = temp_allt[i] / width;
				int w = temp_allt[i] % width;
				
				std::string breed_exist = "";
				
				//classification
				if (h > 0)
					if (world[h - 1][w]->icon() != 'H' && world[h - 1][w]->icon() != 'R' && world[h - 1][w]->icon() != 'T')
						breed_exist += "0";
				if (h < height - 1)
					if (world[h + 1][w]->icon() != 'H' && world[h + 1][w]->icon() != 'R' && world[h + 1][w]->icon() != 'T')
						breed_exist += "1";
				if (w < width - 1)
					if (world[h][w + 1]->icon() != 'H' && world[h][w + 1]->icon() != 'R' && world[h][w + 1]->icon() != 'T')
						breed_exist += "2";
				if (w > 0)
					if (world[h][w - 1]->icon() != 'H' && world[h][w - 1]->icon() != 'R' && world[h][w - 1]->icon() != 'T')
						breed_exist += "3";
				
				if (breed_exist != "")
				{
					//use random library
					std::random_device rd_5_1;
					std::mt19937 gen_5_1(rd_5_1());
					std::uniform_int_distribution<int> dis_5_1(0, breed_exist.length() - 1);
					
					int breed_tiger_pos;
					switch (breed_exist[dis_5_1(gen_5_1)] - '0')
					{
						case 0:	//up
							breed_tiger_pos = (h - 1) * width + w;
							allt = addarr(allt, tnum, (h - 1) * width + w);
							break;
						case 1:	//down
							breed_tiger_pos = (h + 1) * width + w;
							allt = addarr(allt, tnum, (h + 1) * width + w);
							break;
						case 2:	//right
							breed_tiger_pos = h * width + (w + 1);
							allt = addarr(allt, tnum, h * width + (w + 1));
							break;
						case 3:	//left
							breed_tiger_pos = h * width + (w - 1);
							allt = addarr(allt, tnum, h * width + (w - 1));
							break;
						default:
							break;
					}
					
					if (world[breed_tiger_pos / width][breed_tiger_pos % width]->icon() == '*')
					{
						delete world[breed_tiger_pos / width][breed_tiger_pos % width];
						world[breed_tiger_pos / width][breed_tiger_pos % width] = new Tiger();
						world[breed_tiger_pos / width][breed_tiger_pos % width]->step_grass = true;
					}
					else if (world[breed_tiger_pos / width][breed_tiger_pos % width]->icon() == 'F')
					{
						delete world[breed_tiger_pos / width][breed_tiger_pos % width];
						world[breed_tiger_pos / width][breed_tiger_pos % width] = new Tiger();
						world[breed_tiger_pos / width][breed_tiger_pos % width]->step_food = true;
					}
					else
					{
						delete world[breed_tiger_pos / width][breed_tiger_pos % width];
						world[breed_tiger_pos / width][breed_tiger_pos % width] = new Tiger();
					}
				}
			}
		}
		
		//rabbit breed
		if (rabbit_breed == true)
		{
			//temporary data
			int temp_rnum = rnum;
			int temp_allr[rnum];
			for (int i = 0; i < temp_rnum; i++)
				temp_allr[i] = allr[i];
			
			for (int i = 0; i < temp_rnum; i++)
			{
				//simplify
				int h = temp_allr[i] / width;
				int w = temp_allr[i] % width;
				
				std::string breed_exist = "";
				
				//classification
				if (h > 0)
					if (world[h - 1][w]->icon() != 'H' && world[h - 1][w]->icon() != 'R' && world[h - 1][w]->icon() != 'T')
						breed_exist += "0";
				if (h < height - 1)
					if (world[h + 1][w]->icon() != 'H' && world[h + 1][w]->icon() != 'R' && world[h + 1][w]->icon() != 'T')
						breed_exist += "1";
				if (w < width - 1)
					if (world[h][w + 1]->icon() != 'H' && world[h][w + 1]->icon() != 'R' && world[h][w + 1]->icon() != 'T')
						breed_exist += "2";
				if (w > 0)
					if (world[h][w - 1]->icon() != 'H' && world[h][w - 1]->icon() != 'R' && world[h][w - 1]->icon() != 'T')
						breed_exist += "3";
				
				if (breed_exist != "")
				{
					//use random libarary
					std::random_device rd_5_2;
					std::mt19937 gen_5_2(rd_5_2());
					std::uniform_int_distribution<int> dis_5_2(0, breed_exist.length() - 1);
					
					int breed_rabbit_pos;
					switch (breed_exist[dis_5_2(gen_5_2)] - '0')
					{
						case 0:	//up
							breed_rabbit_pos = (h - 1) * width + w;
							allr = addarr(allr, rnum, (h - 1) * width + w);
							break;
						case 1:	//down
							breed_rabbit_pos = (h + 1) * width + w;
							allr = addarr(allr, rnum, (h + 1) * width + w);
							break;
						case 2:	//right
							breed_rabbit_pos = h * width + (w + 1);
							allr = addarr(allr, rnum, h * width + (w + 1));
							break;
						case 3:	//left
							breed_rabbit_pos = h * width + (w - 1);
							allr = addarr(allr, rnum, h * width + (w - 1));
							break;
						default:
							break;
					}
					
					if (world[breed_rabbit_pos / width][breed_rabbit_pos % width]->icon() == 'F')
					{
						delete world[breed_rabbit_pos / width][breed_rabbit_pos % width];
						world[breed_rabbit_pos / width][breed_rabbit_pos % width] = new Rabbit();
						world[breed_rabbit_pos / width][breed_rabbit_pos % width]->step_food = true;
					}
					else
					{
						delete world[breed_rabbit_pos / width][breed_rabbit_pos % width];
						world[breed_rabbit_pos / width][breed_rabbit_pos % width] = new Rabbit();
					}
				}	
			}
		}
		
		/*#######################
		   #0-1. Game over
		#######################*/
		
		//if all rabbits die
		if (rnum == 0)
		{
			std::cout << "Rabbits are gone" << std::endl;
			std::cout << "Game Over!" << std::endl;
			chk = false;
		}
		
		//if hunter dies
		else if (hnum == 0)
		{
			std::cout << "Hunter is dead" << std::endl;
			std::cout << "Game Over!" << std::endl;
			chk = false;
		}
		
		/*#######################
		   #0-2. Game win
		#######################*/
		
		//if one or more rabbits alive and all tigers are dead
		if (tnum == 0)
		{
			std::cout << "Tigers are all dead" << std::endl;
			std::cout << "You Win!" << std::endl;
			chk = false;
		}
		
		intsort(allt, tnum);
		intsort(allr, rnum);
		intsort(allg, gnum);
		
		//next step
		step++;
	}
}

