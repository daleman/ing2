#ifndef DESAFIO_H
#define DESAFIO_H

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

class PlanillaDesafios
{
	vector <Desafio> desafios;

	public:
	const Desafio& nuevoDesafio(
		const Participante& unParticipante,
		const Equipo& unEquipo,
		int unaApuesta
	);

	void aceptarDesafio(
		const Desafio& unDesafio,
		const Participante& unParticipante,
		const Equipo& unEquipo
	);
};

class Desafio
{
	int apuesta;

	public:
	void aceptar(
		const Participante& unParticipante,
		const Equipo& unEquipo
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
};

#endif
