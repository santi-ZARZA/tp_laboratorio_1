#include <stdio.h>
#include <stdlib.h>
#define MAXPERSONAS 5


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 *  recibe el array de las personas a ingresar.
 * \param se setean los estados a disponibles[0].
 *
 */
void seteadorDeEstados(EPersona estados[]);

/**
 *  recibe el array de las personas a cargar.
 * \param se busca un espacio libre en el array.
 * \param en canso de haber espacio se procede a hacer la carga, en caso contrario se informa de que no hay espacio.
 *
 */
void cargarPersona(EPersona personas[]);

/**
 *  recibe el array de las personas
 * \param se busca el DNI que coincida con el que se quiere dar de baja, si se encuentra se muestra, en caso contrario se
 *        informa de la inexistencia del DNI buscado.
 * \param se da la baja al DNI ingresado(Estado[0]).
 *
 */
void bajaPersona(EPersona persona[]);

/**
 *  recibe el array de personas a mostrar.
 * \param se muestran todas las personas dadas de alta, exceptuando a las dadas de baja.
 *
 */
void mostrarPersonas(EPersona personas[]);

/** recibe el array de personas a graficar por condiciones.
 *
 * \param se declaran 3 contadores para incrementar apartir de condiciones.
 * \param se valida si alla personas ingresadas.
 * \param se muestra grafico si entra en la validacion , sino se informa de que no hay personas ingresadas.
 *
 */
 void grafico(EPersona grafico[]);

/** \brief recibe por parametros el array de personas.
 *
 * \param se verifica que alla en existencia alguna persona ingresada.
 * \return en caso de haber personas se retorna [1],en caso contrario [-1].
 *
 */
 int hayPersonas(EPersona personas[]);

