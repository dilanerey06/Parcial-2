using namespace std;

class Nav{
private:
	int numOpt;
	string *array;

public:
	Nav();
	void makeNav(int numOpt);
	void makeOpt(int n, string opt);
	//void changeState(bool stateChanged);
	int printNav();
	~Nav();
};

