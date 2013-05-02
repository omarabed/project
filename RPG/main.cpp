#include "hero.h"
#include <fstream>


int main(int argc, char *argv[])
{
    string line;
    ifstream myfile ("story.txt");
    myfile.is_open();

    //myfile.seekg(1, myfile.beg);

    getline(myfile, line);
    for(int i=0; i<6; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Hero myHero;

    getline(myfile, line);
    for(int i=0; i<5; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }

    Enemy enemy1(1);
    myHero.fight(&enemy1);

    getline(myfile, line);
    for(int i=0; i<3; i++)
    {
        getline(myfile, line);
        cout << line << endl;
    }



    /*
    Enemy enemy2(3);
    myHero.fight(&enemy2);
    Enemy enemy3(2);
    myHero.fight(&enemy3);
    Enemy enemy4(1);
    myHero.fight(&enemy4);
    Enemy enemy5(4);
    myHero.fight(&enemy5);
    */

    return 0;
}
