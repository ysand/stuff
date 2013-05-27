#include "ingrediens.h"

Ingrediens::Ingrediens()
{}

Ingrediens::Ingrediens(double _id, std::string _name, double _water, double _kjoule, double _fat, double _cholesterol, 
						double _carbohydrate,double _fiber, double _proteins, double _vitA, double _vitD, double _vitE, double _vitC){
	id = _id;
	name = _name;
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
std::string Ingrediens::getName()
{
	return name;
}
double Ingrediens::getWater()
{
	return water;
}
double Ingrediens::getKjoule()
{
	return kjoule;
}
double Ingrediens::getFat()
{
	return fat;
}
double Ingrediens::getCholesterol()
{
	return cholesterol;
}
double Ingrediens::getCarbohydrate()
{
	return carbohydrate;
}
double Ingrediens::getFiber()
{
	return fiber;
}
double Ingrediens::getProteins()
{
	return proteins;
}
double Ingrediens::getVitA()
{
	return vitA;
}
double Ingrediens::getVitD()
{
	return vitD;
}
double Ingrediens::getVitE()
{
	return vitE;
}
double Ingrediens::getVitC()
{
	return vitC;
}
