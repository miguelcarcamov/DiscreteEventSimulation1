#include <string>
class lecturaArchivo
{
private:
	//VARIABLES PRIVADAS
	int numproc;
	int quantum;
	string algoritmo;
	string interarrivo;
	int interarrivoInter[2];
	string servicio;
	int servicioInter[2];
	string RP;
	int RPInter[2]; 
	string RIO;
	int RIOInter[2]:
	string nombreArchivo;
	////VARIABLES PRIVADAS///////


	///////////METODOS PUBLICOS/////////////////////////////////
	//////////CONSTRUCTORES, ACCESORES Y MUTADORES//////////////
public:
	//AQUÍ VA LA DECLARACIÓN DE MÉTODOS////
    //CONSTRUCTORES
    lecturaArchivo(int numproc, int quantum, string algoritmo, string interarrivo, string servicio, string RP, string RIO, int* interarrivoInter, int* servicioInter, int* RPInter, int* RIOInter);
    lecturaArchivo(string nombreArchivo);
    ~lecturaArchivo();
    //GETTERS
	int getNumProc();
	int getQuantum();
	string getAlgoritmo();
	string getInterarrivo();
	int* getInterarrivoInter();
	string getServicio();
	int* getServicioInter();
	string getRP();
	int* getRPInter();
	string getRIO();
	int* getRIOInter();

};
