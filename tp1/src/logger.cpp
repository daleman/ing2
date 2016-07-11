#include "logger.h"

#include "posiciones.h"

#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

Logger::Logger()
  : file(getNextFile())
{
	file.basic_ios<char>::rdbuf(std::cout.rdbuf());
}

string Logger::getNextFile()
{
	bool valid = access(logPrefix, F_OK) != -1;

	if (!valid)
	{
		std::cerr << "Creando directorio de logs" << std::endl;
		mkdir(logPrefix, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}

	int r = 0;
	while (true)
	{
		string agar = string("log/") + std::to_string(r) + string(".log");

		if (access(agar.c_str(), F_OK) == -1)
		{
			std::cerr << "Usando archivo " << agar << std::endl;
			return agar;
		}

		r += 1;

	}
}

void Logger::loguearInicioTurno(string nombreInicial)
{
	file << "Empieza un nuevo turno en el partido, donde " << nombreInicial << " tiene la pelota." << std::endl;
}

void Logger::loguearPase(const Pase &pase, bool exito)
{
	file << pase.desde->darPosicion(pase.equipo).nombre << " le pasó la pelota a " << pase.hasta->darPosicion(pase.equipo).nombre;

	if (!exito)
		file << " pero se le cayó de la mano!" << std::endl;
	else
		file << "." << std::endl;
}

void loguearTiro3(const Tiro3Puntos &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void loguearTiro2(const Tiro2Puntos &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void loguearIntersepcionDefensiva(const IntercepcionDefensiva &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void loguearIntersepcionContraofensiva(const IntercepcionContraofensiva &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void loguearBloqueoDefensiva(const BloqueoDefensivo &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void loguearBloqueoContraofensiva(const BloqueoContraofensivo &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void loguearRebote(const Rebote &unRebote)
{
	assert(("Not implemented", false));
}

