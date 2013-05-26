#include "ingrediens.h"

Ingrediens::Ingrediens(double _id, std::string _name, double _grammes, double _water, double _kjoule, double _fat, double _cholesterol, 
  					double _carbohydrate,double _fiber, double _proteins, double _vitA, double _vitD, double _vitE, double _vitC){
	id = _id;
	name = _name;
	grammes = _grammes;
	kjoule = _kjoule;
	fat = _fat;
	cholesterol = _cholesterol;
	carbohydrate = _carbohydrate;
	fiber = _fiber;
	proteins = _proteins;
	vitA = _vitA;
	vitD = _vitD;
	vitE = _vitE;
	vitC = _vitC;
}
// TODO: make Get methods
double Ingrediens::getID()
{
	return id;
}
