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

void Logger::loguearInicioTurno(string nombreInicial, string nombreJugadorInicial)
{
	file << "Empieza un nuevo turno en el partido, donde " << nombreInicial << " hace el saque." << std::endl;
}

void Logger::loguearInicioJugada(string nombreJugador)
{
	file << nombreJugador << " tiene la pelota." << std::endl;
}

void Logger::loguearPase(const Pase &pase, bool exito)
{
	file << pase.desde->darPosicion(pase.equipo).nombre << " le pasa la pelota a " << pase.hasta->darPosicion(pase.equipo).nombre;

	if (!exito)
		file << " pero se le cayó de la mano!" << std::endl;
	else
		file << "." << std::endl;
}

void Logger::loguearTiro3(const Tiro3Puntos &tiro, bool exito)
{
	file << tiro.desde->darPosicion(tiro.equipo).nombre << " intenta tirar al aro por 3 puntos..." << std::endl;

	if (exito)
		file << "Y lo logra!" << std::endl;
	else
		file << "Y fue un intento fallido." << std::endl;
}

void Logger::loguearTiro2(const Tiro2Puntos &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void Logger::loguearIntersepcionDefensiva(const IntercepcionDefensiva &inter, bool exito)
{
	file << inter.desde->darPosicion(inter.equipo).nombre << " le saco la pelota de las manos!" << std::endl;
}

void Logger::loguearIntersepcionContraofensiva(const IntercepcionContraofensiva &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void Logger::loguearBloqueoDefensiva(const BloqueoDefensivo &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void Logger::loguearBloqueoContraofensiva(const BloqueoContraofensivo &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void Logger::loguearRebote(const Rebote &unRebote)
{
	assert(("Not implemented", false));
}

void Logger::loguearPelotaDividida()
{
	file << "La pelota esta dividida, y cualquier equipo puede conseguir el control!" << std::endl;
}
