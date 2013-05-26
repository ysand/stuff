#include <string>

class Ingrediens
{
public:
Ingrediens(double id, std::string name, double grammes, double water, double kjoule, double fat, double cholesterol, 
  					double carbohydrate,double fiber, double proteins, double vitA, double vitD, double vitE, double vitC);

double getID();

private:
	double id;
	std::string name;
	double grammes;
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
