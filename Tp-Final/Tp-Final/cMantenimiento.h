#pragma once
#include <iostream>

using namespace std;

class cMantenimiento
{
	int Costo;
public:
	cMantenimiento(int costo);
	virtual ~cMantenimiento();
	void virtual RealizarMantenimiento() = 0;
};

