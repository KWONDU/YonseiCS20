#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;


class Robot{
    private:
        int m_posX;
        int m_posY;
        int m_dir; // north=0, south=1, east=2, west=3

    public:
        /*
            Your Code for constructors
            1. default constructor (0, 0, north)
            2. other constructor with three parameters (m_posX, m_posY, m_dir)
        */
	Robot() {
		m_posX = 0;
		m_posY = 0;
		m_dir = 0;
	}
	Robot(int posX, int posY, int dir) {
		m_posX = posX;
		m_posY = posY;
		m_dir = dir;
	}	

        void move(int distance);
        void left_face();
        void right_face();
        int get_x_position();
        int get_y_position();
        int get_orientation();
};

void Robot::move(int distance){
    // Moves the robot a given distance in the direction it is facing. 
    // This is done by adding the distance from the appropriate coordi­nate. 
    switch(m_dir)
    {
	    case 0:
		    m_posY += distance;
		    break;
	    case 1:
		    m_posY -= distance;
		    break;
	    case 2:
		    m_posX += distance;
		    break;
	    case 3:
		    m_posX -= distance;
		    break;
	    default:
		    break;
    }
}

void Robot::left_face(){
    // Turn the robot to the left by 90 degrees. 
    if (m_dir == 0)
	    m_dir = 3;
    else if (m_dir == 1)
	    m_dir = 2;
    else if (m_dir == 2)
	    m_dir = 0;
    else if (m_dir == 3)
	    m_dir = 1;
}

void Robot::right_face(){
    // Turn the robot to the right by 90 degrees. 
    if (m_dir == 0)
	    m_dir = 2;
    else if (m_dir == 1)
	    m_dir = 3;
    else if (m_dir == 2)
	    m_dir = 1;
    else if (m_dir == 3)
	    m_dir = 0;
}

int Robot::get_x_position() {
    // Return appropriate values: m_posX (int)
    return m_posX;
}

int Robot::get_y_position() {
    // Return appropriate values: m_posY (int)
    return m_posY;
}

int Robot::get_orientation() {
    // Return appropriate values: m_dir (int)
    return m_dir;
}

void show_Robot(Robot robot){
    // Print current position of robot
    // input (Robot)
    // output format: m_posX m_posY m_dir
    // example: current position (0, 0, north) --> 0 0 0
    cout << robot.get_x_position() << " " << robot.get_y_position() << " " << robot.get_orientation() << endl;
}


int main(){ 
    // Problem 4-1
    /*
    (1) Create a robot1 at default position (0, 0, north)
        with default constructor
	(2) Then, print current status
    */
    cout << "##### Problem 4-1 #####" << endl;
    Robot robot1;
    show_Robot(robot1);

    
    // Problem 4-2
    /*
    (1) Create a robot2 at position (20, 20, north)
	(2) Then, print current status
    */
    cout << "##### Problem 4-2 #####" << endl;
    Robot robot2(20, 20, 0);
    show_Robot(robot2);

    
    // Problem 4-3
    /*
    (1) Move robot1 to position (10, 10, east)
        only using these 3 functions
        1) void move()
        2) void left_face()
        3) void right_face()
    (2) Whenever the direction or position is changed,
        print changed status each time
    */
    cout << "##### Problem 4-3 #####" << endl;
    robot1.move(10);
    show_Robot(robot1);
    robot1.right_face();
    show_Robot(robot1);
    robot1.move(10);
    show_Robot(robot1);


    // Problem 4-4
    /*
    (1) Move robot2 to position (10, 10, east)
        using these functions
        1) void move()
        2) void left_face()
        3) void right_face()
    (2) Whenever the direction or position is changed,
        print changed status each time
    */
    cout << "##### Problem 4-4 #####" << endl;
    robot2.left_face();
    show_Robot(robot2);
    robot2.move(10);
    show_Robot(robot2);
    robot2.left_face();
    show_Robot(robot2);
    robot2.move(10);
    show_Robot(robot2);
    robot2.left_face();
    show_Robot(robot2);
    

	return 0;
}
