#include <iostream>
#include "pch.h"
#include "consola.h"

#define CANT_COCHERAS 100 // numero de cocheras


int main()
{
	ST_COCHERA cocheras[CANT_COCHERAS];
	llenarCocheras(cocheras, CANT_COCHERAS);
	prenderConsola();
}