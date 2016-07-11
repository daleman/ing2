#ifndef DESAFIO_H
#define DESAFIO_H

#include <set>
#include <string>
#include <vector>

#include "clases.h"

#include "personas.h"
#include "posiciones.h"

using std::set;
using std::string;
using std::vector;

class Cuenta
{
	string email;
	string contrasena;

	public:
	bool validar(string unaContrasena) const;
};

class Participante
{
	int fichas;
	int cap;

	vector <Equipo> equipos;

	public:
	const string nombre;

	const Equipo& crearEquipo(
		string unNombre,
		const Tecnico& unTecnico,
		const Jugador& jugadorBase,
		const Jugador& jugadorEscolta,
		const Jugador& jugadorAlero,
		const Jugador& jugadorAlaPivot,
		const Jugador& jugadorPivot
	);

	void procesarResultado(
		const Monitor& unMonitor,
		string unNombreEquipo
	);

	const vector <Equipo>& darEquipos();
	int darFichas();
	int darCap();
};

class Plantel
{
	vector <Tecnico> tecnicos;
	vector <Jugador> jugadores;

	public:
	const vector <Tecnico>& darTecnicos() const;
	const vector <Jugador>& darJugadores() const;
};

class Equipo
{
	public:
	const string nombre;
	const Tecnico tecnico;
	const Jugador base, escolta, alero, alapivot, pivot;
	const Posicion& MVP;

	Equipo(
		string nombre,
		Tecnico tecnico,
		Jugador base,
		Jugador escolta,
		Jugador alero,
		Jugador alapivot,
		Jugador pivot,
		const Posicion& MVP
	);
};

class PlanillaDesafios
{
	vector <Desafio> desafios;

	public:
	const Desafio& nuevoDesafio(
		const Participante& unParticipante,
		const Equipo& unEquipo,
		int unaApuesta
	);

	const vector <Desafio>& darDesafios() const;

	void aceptarDesafio(
		const Desafio& unDesafio,
		const Participante& unParticipante,
		const Equipo& unEquipo
	);
};

class Desafio
{
	public:
	const int apuesta;

	const Participante& participante;
	const Equipo& equipo;

	void aceptar(
		const Participante& unParticipante,
		const Equipo& unEquipo
	);

	Desafio(
		const Participante &unParticipante,
		const Equipo& unEquipo,
		int unaApuesta
	);
};

class TablaPosiciones
{
	struct Posicion
	{
		string nombreEquipo;
		int partidosGanados;
		int puntajeTotal;

		bool operator< (const Posicion& otraPosicion) const;
	};
	set <Posicion> tabla;

	public:
	void agregarResultado(const Monitor& unMonitor);
};

class Monitor
{
	int puntaje1;
	int puntaje2;

	public:
	const string nombreEquipo1;
	const string nombreEquipo2;

	string ganador() const;
	bool empate() const;

	void sumarPuntaje(
		int unPuntaje,
		string unEquipo
	);

	vector <string> nombresEquipos() const;
	vector <int> puntajeEmpezandoPor(string unNombreEquipo) const;

	Monitor(
		const string& unEquipo,
		const string& otroEquipo
	);
};

#endif
