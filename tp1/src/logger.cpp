#include "logger.h"

#include "posiciones.h"

#include <cassert>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

Logger::Logger()
  // : file(getNextFile())
  : file("log/dummy.txt")
{
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

void Logger::loguearPase(
	const Pase &pase,
	bool exito
)
{
	file << pase.desde.darPosicion(pase.equipo).nombre << " le pasó la pelota a " << pase.hasta.darPosicion(pase.equipo).nombre << ".";

	if (exito)
		file << " y fue exitoso" << std::endl;
	else
		file << " y se le cayó de la mano" << std::endl;
}

