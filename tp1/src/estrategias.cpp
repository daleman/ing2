#include "estrategias.h"

#include "acciones.h"
#include "posiciones.h"

ColectivaExternaDe3PuntosLuegoDeKPases::ColectivaExternaDe3PuntosLuegoDeKPases(int k)
	: k(k)
{
}

AccionOfensiva&& ColectivaExternaDe3PuntosLuegoDeKPases::darAccionDe(const Equipo& unEquipo)
{
	return Pase(Base(), Escolta(), unEquipo,
		Pase(Escolta(), Alero(), unEquipo,
			Pase(Alero(), AlaPivot(), unEquipo,
				Tiro3Puntos(AlaPivot(), unEquipo)
			)
		)
	);
}
