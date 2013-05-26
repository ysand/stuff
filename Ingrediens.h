#include <string>

class Ingrediens
{
public:
Ingrediens();

Ingrediens(double id, std::string name, double water, double kjoule, double fat, double cholesterol, 
  					double carbohydrate,double fiber, double proteins, double vitA, double vitD, double vitE, double vitC);

double getID();
double getWater();
double getKjoule();
double getFat();
double getCholesterol();
double getCarbohydrate();
double getFiber();
double getProteins();
double getVitA();
double getVitD();
double getVitE();
double getVitC();

private:
	double id;
	std::string name;
	double water;
	double kjoule;
	double fat;
	double cholesterol;
	double carbohydrate;
	double fiber;
	double proteins;
	double vitA;
	double vitD;
	double vitE;
	double vitC;
};
