class Persona{
	private:
		string nombre;
		string apellido;
		string parentesco;
		int edad;

	public:
		Persona();
		void makePerson(string name, string apellido, string parentesco, int years);
		string getNombre();
		string getApellido();
		string getParentesco();
		int getEdad();
		void impData();
		~Persona();
};

class Familia{
	private:
		Persona *ptrArray;
	public:
		Familia();
		void makeFamilia();
		void impDataF();
		void searchMember(string nombre);
		~Familia();
	friend int searchFamily(Familia *array, string apellido, int numFamCreadas);
};