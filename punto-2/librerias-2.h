class figuraGeometrica{
	private:
		int lado; //radio para circulo, base para rectangulo, lados del triangulo

	public:
		figuraGeometrica(int lado);
		int getLado();
		static int numElem;
		virtual void print() = 0;
		~figuraGeometrica();
	
};

class Rectangulo: public figuraGeometrica{
	private:
		int altura;
	public:
		Rectangulo(int base, int alt):figuraGeometrica(base){
			altura = alt;
		}
		void print();
		~Rectangulo();
};

class Circulo: public figuraGeometrica{
	public:
		Circulo(int radio):figuraGeometrica(radio){}
		void print();
		~Circulo();
};

class Triangulo: public figuraGeometrica{
	public:
		Triangulo(int lado):figuraGeometrica(lado){}
		void print();
		~Triangulo();
};