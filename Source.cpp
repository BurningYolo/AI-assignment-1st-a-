#include <iostream>
using namespace std;

class world
{
public:
    world()
    {
        west = 0;
        east = 0;
        checking = 0;
        cleaning = 0;
        time = 0;
        dirt = 0;
        energy = 0;
        total_energy = 0;
        total_dirt = 0;
        total_time = 0;
        total_energy_only_for_dirt = 0; 
        total_energy_only_for_movement_and_checking_purposes = 0; 

    }

    int rooms[2]{ 1 , 2 };
    struct
    {
        int west;
        int east;
        int checking;
        int cleaning;
    };
    struct
    {
        int time;
        int dirt;
        int energy;
        int total_time;
        int total_dirt;
        int total_energy;
        int total_energy_only_for_dirt;
        int total_energy_only_for_movement_and_checking_purposes; 
    };

    int dirt_generation()
    {
        dirt = rand() % 4;
        return dirt;
    }

    int process(int a)
    {

        if (rooms[0] == a)
        {
            cout << "In room A " << endl;
            dirt = dirt_generation();
            checking = 1;
            total_energy_only_for_movement_and_checking_purposes++;
            total_energy++; 
            total_time++;
            if (dirt > 0)
            {
                cleaning = 1;
                total_time++;
                cout << "Cleaning room A " << endl;
                cout << "Amount of Dirt in room A = " << dirt << endl;
 
                total_dirt += dirt;
                total_energy += dirt * 2;
                total_energy_only_for_dirt += dirt * 2;
                cout << "Total Dirt Collected until now = " << total_dirt << endl;
                cout << "Total Energy used until now = " << total_energy << endl;
                total_time += total_dirt; 
                cout << "Moving left to room B " << endl;
                total_time++;
                total_energy++; 
                total_energy_only_for_movement_and_checking_purposes++;
                west = 1;
                cout << "Total Time consumed until now = " << total_time << endl;
            }
            else if (dirt == 0)
            {
                cout << "Room A is clean " << endl;
                cout << "Moving left to room B " << endl;
                total_energy++;
                total_energy_only_for_movement_and_checking_purposes++;
                west = 1;
            }

            int dc1 = dirt;
            return dc1;
        }

        if (rooms[1] == a)
        {

            cout << "In room B" << endl;
            dirt = dirt_generation();
            checking = 1;
            total_energy_only_for_movement_and_checking_purposes++;
            total_energy++;
            total_time++;
            if (dirt > 0)
            {
                cleaning = 1;
                total_time++;
                cout << "Cleaning room B " << endl;
                cout << "Amount of Dirt in room B = " << dirt << endl;
                total_dirt += dirt;
                total_energy += dirt * 2;
                total_energy_only_for_dirt += dirt * 2;
                cout << "Total Dirt Collected until now = " << total_dirt << endl;
                cout << "Total Energy used until now = " << total_energy << endl;
                total_time += total_dirt; 
                cout << "Moving right to room A " << endl;
                total_time++;
                total_energy++;
                total_energy_only_for_movement_and_checking_purposes++;
                east = 1;
                cout << "Total Time consumed until now = " << total_time << endl;
            }
            else if (dirt == 0)
            {
                cout << "Room B is clean " << endl;
                cout << "Moving right to room A " << endl;
                total_energy++;
                total_energy_only_for_movement_and_checking_purposes++;
                east = 1;
            }


            int dc2 = dirt;
            return dc2;
        }


    }

    void ending_screen()
    {
        cout << " " << endl;
        cout << "Total Energy used : " << total_energy << endl;
        cout << "total_time used : " << total_time << endl;
        cout << "Total_dirt Collected / Total_sucks done : " << total_dirt << endl;
        cout << "Total Energy used only for dirt collection : " << total_energy_only_for_dirt << endl;
        cout << "Total Energy used only for  movement purposes : " << total_energy_only_for_movement_and_checking_purposes << endl;
    }

    


};

int main()
{
    world w;
    int cycle_dirt1, cycle_dirt2;
    cycle_dirt1 = 1; 
    cycle_dirt2 = 1; 
    int cycles = 0;
    int cycle_dirt = 1; 


    {
        while ( cycles <= 9 && cycle_dirt!=0 )
        {


            cycle_dirt1 = w.process(1);
            cycle_dirt2 = w.process(2);
            cycle_dirt = cycle_dirt1 + cycle_dirt2; 
            cycles++; 
        }
    }
    if (cycles == 10)
    {
        cout << " " << endl;
        cout << "Cycle limit reached which is  : " << cycles << endl;
        cout << " " << endl;
    }
    else
    {
        cout << " " << endl;
        cout << "Both the rooms are clean " << endl;
        cout << " " << endl;
    }
    w.ending_screen();
}
