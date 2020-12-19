#include <iostream>
#include <cstdlib>
#include <string>

struct Food
{
	std::string name;
	int price;
};
static struct Food mcMenu[9] = {{"", 0},
	{"Hamberger", 1000},
	{"Cheeseburger", 1500},
	{"Big Mac", 3000},
	{"Quarter Pounder Burger", 4000},
	{"Dobule Quarter Burger", 5000},
	{"Fries", 1500},
	{"Chicken McNuggets", 2000},
	{"Coke", 1500}}; //Mcdonalds Menu

class User
{
	public:
		User();
		std::string getid() {return id;}
		std::string getpassword() {return password;}
		int getcharge() {return charge;}
		std::string getorder() {return history;}
		void setid(std::string user_id) {id = user_id;}
		void setpassword(std::string user_password) {password = user_password;}
		void setcharge(int user_charge) {charge = user_charge;}
		void plusorder(int user_order) {history += static_cast<char>(user_order);}
		void minusorder(int user_pos) {history.erase(user_pos-1, 1);}
		
		int purchase; //total purchase amount
		
	private:
		std::string id; //ID
		std::string password; //password
		int charge; //charge amount
		std::string history; //order history
};

User* server = new User[100]; //void accounts
bool li_chk = false; //login check
int li_pos = -1; //account position

void menu1(); //Sign up
void menu2(); //login
void menu3(); //Show Menu
void menu4(); //Order
void menu5(); //Order condition
void menu6(); //Refund
void menu7(); //Logout
void menu0(); //Exit

int main()
{
	char option;
	while(true)
	{
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "-----Mcdonalds Delivery System-----" << std::endl;
		std::cout << "-----------------------------------" << std::endl;
		std::cout << "\n";
		std::cout << "1. Sign up" << std::endl;
		std::cout << "2. login" << std::endl;
		std::cout << "3. Show Menu" << std::endl;
		std::cout << "4. Order" << std::endl;
		std::cout << "5. Order condition" << std::endl;
		std::cout << "6. Refund" << std::endl;
		std::cout << "7. Logout" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << "Select -> ";
		std::cin >> option;
		switch(option)
		{
			case '1':
				menu1();
				break;
			case '2':
				menu2();
				break;
			case '3':
				menu3();
				break;
			case '4':
				menu4();
				break;
			case '5':
				menu5();
				break;
			case '6':
				menu6();
				break;
			case '7':
				menu7();
				break;
			case '0':
				menu0();
				break;
			default:
				continue;
		}
	}
}

User::User()
{
	purchase = 0;
	
	id = "";
	password = "";
	charge = 0;
	history = "";
}

void menu1()
{
	if (li_chk) // if already log in
	{
		std::cout << "\nYou are already logged in to " << server[li_pos].getid() << " account" << std::endl;
		std::cout << "Return to main menu" << std::endl;
		std::cout << "\n";
		return;
	}

	int pos = 0;
	std::string user_id;
	while (pos < 100)
	{
		if (pos == 0)
		{
			std::cout << "\nInput your ID(0-to main menu) : ";
			std::cin >> user_id;
			if (user_id == "0") //return to main menu
			{
				std::cout << "\n";
				return;
			}
		}
		pos++;
		if (server[pos-1].getid() != "")
		{
			if (user_id == server[pos-1].getid()) //ID already exists
			{
				std::cout << "Duplicated user id" << std::endl;
				pos = 0;
			}
		}
		else //empty account space
			break;
	}
	if (pos-1 < 100)
	{
		pos--;
		server[pos].setid(user_id);

		std::string user_password;
		int user_charge;
		std::cout <<"Input your password : ";
		std::cin >> user_password;
		server[pos].setpassword(user_password);
		std::cout <<"Input your total money : ";
		std::cin >> user_charge;
		server[pos].setcharge(user_charge);
		
		std::cout << "\nWelcome, " << server[pos].getid() << std::endl;
		std::cout << "\n";
	}
}

void menu2()
{
	if (li_chk) // if already log in
        {
                std::cout << "\nYou are already logged in to " << server[li_pos].getid() << " account" << std::endl;
                std::cout << "Return to main menu" << std::endl;
                std::cout << "\n";
                return;
        }

	std::string user_id;
	std::cout << "\nInput your ID(0-to main menu) : ";
	std::cin >> user_id;
	if (user_id == "0") //return to main menu
	{
		std::cout << "\n";
		return;
	}
	int pos = 0;
	while (pos < 100 && server[pos].getid() != "")
	{
		if (user_id == server[pos].getid())
			break; //existing ID
		pos++;
	}
	if (pos == 100 || server[pos].getid() == "") //not existing ID
	{
		std::cout << "ID is not existing" << std::endl;
		std::cout << "\n";
		return;
	}
	
	li_pos = pos;
	std::string user_password;
	std::cout << "Input your password : ";
	std::cin >> user_password;
	while (user_password != server[pos].getpassword()) //wrong password
	{
		std::cout << "Wrong password!" << std::endl;
		std::cout << "Input your password : ";
		std::cin >> user_password;
	}
	
	li_chk = true; //login complete
	std::cout << "\nWelcome, " << server[pos].getid() << std::endl;
	std::cout << "\n";
}

void menu3()
{
	std::cout << "\n----------MCdonalds Menu----------" << std::endl;
	std::cout << "1.  Hamburger               - 1000" << std::endl;
	std::cout << "2.  Cheeseburger            - 1500" << std::endl;
	std::cout << "3.  Big Mac                 - 3000" << std::endl;
	std::cout << "4.  Quarter Pounder Burger  - 4000" << std::endl;
	std::cout << "5.  Double Quarter Pounder  - 5000" << std::endl;
	std::cout << "6.  Fries                   - 1500" << std::endl;
	std::cout << "7.  Chicken McNuggets       - 2000" << std::endl;
	std::cout << "8.  Coke                    - 1500" << std::endl;
	std::cout << "\n";
}

void menu4()
{
	if (!li_chk) //if already log in
	{
		std::cout << "\nYou have to login first" << std::endl;
		std::cout << "Return to main menu" << std::endl;
		std::cout << "\n";
		return;
	}

	int m_num = -1;
	int m_count = 0;
	
	while (1)
	{
		std::cout << "\nSelect menu number(0-to main menu) : ";
		std::cin >> m_num;
		if (m_num == 0)
			break;
		std::cout << "How many \'" << mcMenu[m_num].name << "\' do you want : ";
		std::cin >> m_count;
		
		if (mcMenu[m_num].price * m_count > server[li_pos].getcharge()) //over the budget
			std::cout << "\nYou don\'t have enough money!" << std::endl;
		else
		{
			for (int i = 0; i < m_count; i++)
				server[li_pos].plusorder(m_num); //order condition
			server[li_pos].purchase += (mcMenu[m_num].price * m_count); //total purchase
			server[li_pos].setcharge(server[li_pos].getcharge() - mcMenu[m_num].price * m_count); //balance
		}
	}
	std::cout << "Your total purchase amount is " << server[li_pos].purchase << std::endl;
	std::cout << "Your balance is " << server[li_pos].getcharge() << std::endl;
	std::cout << "Thanks" << std::endl;
	std::cout << "\n";
}

void menu5()
{
	if (!li_chk) //if already log in
    {
            std::cout << "\nYou have to login first" << std::endl;
	        std::cout << "Return to main menu" << std::endl;
            std::cout << "\n";
	        return;
	}
    
    std::cout << "\n";
    std::string ord = server[li_pos].getorder();
    int i = 1;
    while (ord != "")
    {
    	std::cout << i << ". \'" << mcMenu[static_cast<int>(ord[0])].name << "\'" << std::endl;
    	ord.erase(0, 1);
    	i++;
	}
	std::cout << "\nYour total price is " << server[li_pos].purchase << std::endl;
	std::cout << "Your total money is " << server[li_pos].getcharge() << std::endl;
	std::cout << "\n";
}

void menu6()
{
	if (!li_chk) //if already log in
    {
            std::cout << "\nYou have to login first" << std::endl;
	        std::cout << "Return to main menu" << std::endl;
            std::cout << "\n";
	        return;
	}
	
	bool chk = true;
	while(chk)
	{
		std::cout << "\n";
		std::string ord = server[li_pos].getorder();
    	int i = 1;
    	while (ord != "")
    	{
    		std::cout << i << ". \'" << mcMenu[static_cast<int>(ord[0])].name << "\'" << std::endl;
    		ord.erase(0, 1);
    		i++;
		}
		std::cout << "Your total price is " << server[li_pos].purchase << std::endl;
		std::cout << "Your total money is " << server[li_pos].getcharge() << std::endl;
		std::cout << "\n";
		while(1)
		{
			int j;
			std::cout << "Choose number(0 - to main menu) : ";
			std::cin >> j;
			if (j == 0)
			{
				std::cout << "\n";
				chk = false;
				break;
			}
			else if (0 < j && j < i)
			{
				int p = mcMenu[static_cast<int>(server[li_pos].getorder()[j-1])].price;
				server[li_pos].purchase -= p;
				server[li_pos].setcharge(server[li_pos].getcharge() + p);
				server[li_pos].minusorder(j);
				std::cout << "Successfully returned" << std::endl;
				break;
			}
			else
			{
				std::cout << "Wrong input!" << std::endl;
				std::cout << "\n";
			}
		}
	}
}

void menu7()
{
	if (!li_chk)
        {
                std::cout << "\nYou have to login first" << std::endl;
                std::cout << "Return to main menu" << std::endl;
                std::cout << "\n";
                return;
        }
	
	int chk = -1;
	while (1)
	{
		std::cout << "\nIf you want to logout, Please enter 1 (0-to main menu) : ";
		std::cin >> chk;
		if (chk == 0)
		{
			std::cout <<"Logout is canceled" << std::endl;
			std::cout << "\n";
			return;
		}
		else if (chk == 1)
		{
			li_chk = false;
			std::cout << "\n";
			break;
		}
		std::cout << "Wrong input!";
	}
}

void menu0()
{
	std::cout << "End the program" << std::endl;
	exit(0);
	
}

