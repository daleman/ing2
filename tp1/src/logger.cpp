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
}

string Logger::getNextFile()
{
	struct stat info;
	bool valid = stat(logPrefix, &info) == 0;

	assert(("Prefix exists and not a directory.", !(valid && (info.st_mode & S_IFDIR))));

	if (!valid)
	{
		std::cerr << "Creating logging directory." << std::endl;
		mkdir(logPrefix, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}

	int r = 0;
	while (true)
	{
		string file = logPrefix + std::to_string(r);
		if (access(file.c_str(), F_OK) != -1)
		{
			std::cerr << "Using file " << file << std::endl;
			return file;
		}
	}
}

void Logger::loguearInicioTurno(string nombreInicial)
{
	file << "Empieza un nuevo turno en el partido, donde " << nombreInicial << " tiene la pelota" << std::endl;
}

void Logger::loguearPase(
	const Pase &pase,
	bool exito
)
{
	file << pase.desde.darPosicion(pase.equipo).nombre << " le pasó la pelota a " << pase.hasta.darPosicion(pase.equipo).nombre;

	if (exito)
		file << " y fue exitoso" << std::endl;
	else
		file << " y se le cayó de la mano" << std::endl;
}

