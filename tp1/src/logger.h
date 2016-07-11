#ifndef LOGGER_H
#define LOGGER_H

#include "acciones.h"

#include <fstream>
#include <string>

using std::ofstream;
using std::string;

class Logger
{
	const constexpr static char* logPrefix = "log/";
	ofstream file;

	string getNextFile();
	public:

	Logger();

	void loguearInicioTurno(string nombreInicial);
	void loguearPase(
		const Pase &unPase,
		bool exito
	);
};

#endif
