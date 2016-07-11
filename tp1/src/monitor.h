#ifndef MONITOR_H
#define MONITOR_H

#include "clases.h"

#include <string>
#include <tuple>

using std::pair;
using std::string;

class Monitor
{
	string nombreEquipo1;
	string nombreEquipo2;
	int puntaje1;
	int puntaje2;

	public:
	string ganador() const;
	bool empate() const;

	void sumarPuntaje(
		int unPuntaje,
		string unEquipo
	);

	pair<string, string> nombresEquipos();
	pair<int, int> puntakePartidoEmpezandoPor(string unNombreEquipo);
};

#endif
