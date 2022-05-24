#pragma once
#include <iostream>

using namespace std;

class cMantenimiento
{
	int costo;
public:
	cMantenimiento();
	virtual ~cMantenimiento();
	void virtual RealizarMantenimiento();
};

