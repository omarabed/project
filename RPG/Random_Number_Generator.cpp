#include <iostream>
#include <cstdlib>

using namespace std;

int rangeRand( int a, int b )
{
	int num( 0 );

	num = a + rand() % ( b + 1 - a );

	return num;
}
