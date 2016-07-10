#ifndef DESAFIO_H
#define DESAFIO_H

#include <set>
#include <string>
#include <vector>

#include "clases.h"

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
	string nombre;
	int fichas;
	int cap;

	vector <Equipo> equipos;

	public:
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
	string nombre;
	Posicion MVP;

	Tecnico tecnico;
	Jugador base, escolta, alero, alapivot, pivot;

	public:
	Posicion darMVP const;
	const Tecnico& darTecnico() const;

	const Jugador&
		darBase() const,
		darEscolta() const,
		darAlero() const,
		darAlaPivot() const,
		darPivot() const;

	Equipo(
		string nombre,
		Tecnico tecnico,
		Jugador base,
		Jugador escolta,
		Jugador alero,
		Jugador alapivot,
		Jugador pivot
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
	int apuesta;

	const Participante& participante;
	const Equipo& equipo;

	public:
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

	vector <string> nombresEquipos() const;
	vector <int> puntajeEmpezandoPor(string unNombreEquipo) const;

	Monitor(
		const Equipo& unEquipo,
		const Equipo& otroEquipo
	);
};

class Jugador
{
	string nombre;
	float fgpt, tppt, rpg, apt, bpg, spg, to, ppg;

	public:
	string darNombre() const;

	float darFgpt() const;
	float darTppt() const;
	float darRpg() const;
	float darApt() const;
	float darBpg() const;
	float darSpg() const;
	float darTo() const;
	float darPpg() const;

	Jugador(
		string nombre,
		float fgpt,
		float tppt,
		float rpg,
		float apt,
		float bpg,
		float spg,
		float to,
		float ppg
	);
};

class Tecnico
{
	const string nombre;

	const vector <PreferenciaOfensiva> tacticasOfensivas;
	const vector <PreferenciaDefendiva> tacticasDefensivas;

	public:
	string darNombre() const;

	const EstrategiaOfensiva& elegirEstrategiaOfensiva() const;
	const EstrategiaDefensiva& elegirEstrategiaDefensiva() const;

	Tecnico(
		string nombre,
		vector <PreferenciaOfensiva> tacticasOfensivas,
		vector <PreferenciaDefendiva> tacticasDefensivas
	);
};

class Preferencia
{
	int peso;

	public:
	Preferencia() = delete;
};

class PreferenciaOfensiva : public Preferencia
{
	public:
	const EstrategiaOfensiva estrategia;

	PreferenciaOfensiva(
		int peso,
		EstrategiaOfensiva estrategia
	);
};

class PreferenciaDefensiva : public Preferencia
{
	public:
	const EstrategiaDefensiva estrategia;

	PreferenciaDefensiva(
		int peso,
		EstrategiaDefensiva estrategia
	);
};

#endif
