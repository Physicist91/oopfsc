#include <fstream>
#include <vector>
#include <signal.h>
#include <regex.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include <iostream>
#include <stdint.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#include "Dog.h"
#include "Cat.h"
#include "Global.h"

using namespace std;

int main()
{
   cout << "hello" << endl;
   Global::getCat();
	return 0;
}

