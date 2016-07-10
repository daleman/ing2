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

	public:
	Equipo crearEquipo(
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

#endif
