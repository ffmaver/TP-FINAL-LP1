#pragma once
#include <iostream>
#include <string>

using namespace std;

class cEquipo;

class cMantenimiento
{
	int Costo;
public:
	cMantenimiento(int costo);
	virtual ~cMantenimiento();
	void virtual RealizarMantenimiento(cEquipo* equipo) = 0;
	friend ostream& operator<<(ostream& out, cMantenimiento& mant);
};

