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

	void loguearInicioTurno(string nombreInicial, string nombreJugadorInicial);
	void loguearInicioJugada(string nombreJugador);
	void loguearPase(const Pase &unPase, bool exito);
	void loguearTiro3(const Tiro3Puntos &unPase, bool exito);
	void loguearTiro2(const Tiro2Puntos &unPase, bool exito);
	void loguearIntersepcionDefensiva(const IntercepcionDefensiva &unPase, bool exito);
	void loguearIntersepcionContraofensiva(const IntercepcionContraofensiva &unPase, bool exito);
	void loguearBloqueoDefensiva(const BloqueoDefensivo &unPase, bool exito);
	void loguearBloqueoContraofensiva(const BloqueoContraofensivo &unPase, bool exito);
	void loguearRebote(const Rebote &unRebote);
	void loguearPelotaDividida();
};

#endif
