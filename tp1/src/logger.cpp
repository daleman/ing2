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
			std::cerr << "Usando archivo " << agar << std::endl << std::endl;
			return agar;
		}

		r += 1;

	}
}

void Logger::loguearInicioTurno(string nombreAtacante, string nombreDefensor, string nombreJugadorInicial)
{
	file << "El equipo " << nombreAtacante << " tiene la pelota y es el atacante"
		<< " y " << nombreDefensor << " es el defensor." << std::endl;
	file << nombreJugadorInicial << " tiene la pelota" << std::endl;
}

void Logger::loguearInicioJugada(string nombreJugador)
{
	file << nombreJugador << " tiene la pelota." << std::endl;
}

void Logger::loguearPase(const Pase &pase, bool exito)
{
	file << pase.desde->darPosicion(pase.equipo).nombre << " le pasa la pelota a " << pase.hasta->darPosicion(pase.equipo).nombre;

	if (!exito)
		file << " pero se le cayo de la mano y se fue de la cancha!" << std::endl;
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

void Logger::loguearTiro2(const Tiro2Puntos &tiro, bool exito)
{
	file << tiro.desde->darPosicion(tiro.equipo).nombre << " intenta tirar al aro por 2 puntos..." << std::endl;

	if (exito)
		file << "Y lo logra!" << std::endl;
	else
		file << "Y fue un intento fallido." << std::endl;
}

void Logger::loguearIntersepcionDefensiva(const IntercepcionDefensiva &inter, bool exito)
{
	file << inter.desde->darPosicion(inter.equipo).nombre << " le saco la pelota de las manos!" << std::endl;
}

void Logger::loguearIntersepcionContraofensiva(const IntercepcionContraofensiva &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void Logger::loguearBloqueoDefensivo(const BloqueoDefensivo &bloq, bool exito)
{
	if (exito)
		file << bloq.desde->darPosicion(bloq.equipo).nombre << " bloqueo un intento de tiro al aro!" << std::endl;
	else
		file << bloq.desde->darPosicion(bloq.equipo).nombre << " intento bloquear el tiro, pero no llego al aro." << std::endl;
}

void Logger::loguearBloqueoContraofensiva(const BloqueoContraofensivo &unPase, bool exito)
{
	assert(("Not implemented", false));
}

void Logger::loguearRebote(const Rebote &unRebote, bool exito)
{
	file << unRebote.desde->darPosicion(unRebote.equipo).nombre << " intenta hacerse de la pelota, ";

	if (!exito)
		file << "y no lo logra." << std::endl;
	else
		file << "y lo logro!" << std::endl;
}

void Logger::loguearPelotaDividida()
{
	file << "La pelota esta dividida, y cualquier equipo puede conseguir el control!" << std::endl;
}

void Logger::loguearFinTurno()
{
	file << "La pelota se fue de la cancha, y es el fin del turno" << std::endl;
}

void Logger::loguearEstado(const Monitor& monitor)
{
	file << std::endl;
	file << "Resultado actual:" << std::endl;
	file << monitor.nombreEquipo1 << " " << monitor.darPuntajeEquipo1() << " --- "
		<< monitor.nombreEquipo2 << " " << monitor.darPuntajeEquipo2() << std::endl;
	file << std::endl;
}

void Logger::loguearGanador(const Monitor& monitor)
{
	file << "Y el ganador es... " << monitor.ganador() << "!" << std::endl;
}

void Logger::loguearEmpate()
{
	file << "Y hubo un empate! 6 turnos extra!" << std::endl;
}

void Logger::loggearEstrategias(
	string nombreTecnicoAtacante,
	string nombreEstrategiaOfensiva,
	string nombreTecnicoDefensor,
	string nombreEstrategiaDefensiva
)
{
	file << nombreTecnicoAtacante << " eligio " << nombreEstrategiaOfensiva << " como estrategia ofensiva." << std::endl;
	file << nombreTecnicoDefensor << " eligio " << nombreEstrategiaDefensiva << " como estrategia defensiva." << std::endl;
}
