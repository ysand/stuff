#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <utility>
#include "ingrediens.h"
using namespace std;
    
	ifstream in("Matvaretabellen2012.csv");

	string line, field;
	
	size_t find_Start,ingStart;
	vector< vector<string> > array;  // the 2D array
    vector<string> v; // array of values for one line only
	string vecsearch = " ";

void selectCat()
	{
		cout << "Select food category to list (1 - 13)" << endl;
		int catnumber;
		cin >> catnumber;
		switch(catnumber)
		{
			case 1:
				{
				vecsearch = "01.";
				}
				break;
			case 2:
				{
				vecsearch = "02.";
				}
				break;
			case 3:
				{
				vecsearch = "03.";
				}
				break;
			case 4:
				{
				vecsearch = "04.";
				}
				break;
			case 5:
				{
				vecsearch = "05.";
				}
				break;
			case 6:
				{
				vecsearch = "06.";
				}
				break;
			case 7:
				{
				vecsearch = "07.";
				}
				break;
			case 8:
				{
				vecsearch = "08.";
				}
				break;
			case 9:
				{
				vecsearch = "09.";
				}
				break;
			case 10:
				{
				vecsearch = "10.";
				}
				break;
			case 11:
				{
				vecsearch = "11.";
				}
				break;
			case 12:
				{
				vecsearch = "12.";
				}
				break;
			case 13:
				{
				vecsearch = "13.";
				}
				break;
			default:
			{
				cout << "Select food category to list (1 - 13)" << endl;
				cin >> catnumber;
			}
			break;
		}
	}

void searchCategory()
	{		
		if (in == nullptr)
		{
			cout << "Could not open file!" << endl;			
		}
		else
		{
			vector< vector<string> > searchresults;
			vector<string> catresultfound;
			string word, searchline;
			selectCat();
			searchresults.clear();
			while(getline(in,searchline))
			{
				catresultfound.clear();
				find_Start = searchline.find(vecsearch);
				stringstream ss(searchline);
				
				if (searchline.find(vecsearch) == 0) 
				{
					while(getline(ss,word,','))
					{
					catresultfound.push_back(word);
					}
					searchresults.push_back(catresultfound);
				}				
			}
			for (size_t i=0; i<searchresults.size(); ++i)
			{
				for (size_t j=0; j<searchresults[i].size(); ++j)
				{
					cout << searchresults[i][j];
				}
				cout << endl;
			}
			in.close();	
		}		
	}

void parseIngredient()
	{
		if(in == nullptr)
		{
			cout << "Could not open file!" << endl;
		}
		else
		{
			vecsearch = "01.001";
			vector<string> ingresultfound;
			string ingword,ingsearchline;
			ingresultfound.clear();
			while(getline(in, ingsearchline))
			{
				ingStart = ingsearchline.find(vecsearch);
				stringstream ss(ingsearchline);

				if (ingsearchline.find(vecsearch) == 0)
				{
					while(getline(ss,ingword,';'))
					{
						ingresultfound.push_back(ingword);
					}
				}
			}
			
			/*
			Konverterer alle nummerverdiene i vektoren og tilordner de hver sin variabel: 
			*/
			double id = atof(ingresultfound[0].c_str());
			string navn = ingresultfound[1];
			double vann = atof(ingresultfound[2].c_str());
			double kilojoule = atof(ingresultfound[3].c_str());
			double fett = atof(ingresultfound[4].c_str());
			double kolesterol = atof(ingresultfound[5].c_str());
			double karbohydrat = atof(ingresultfound[6].c_str());
			double kostfiber= atof(ingresultfound[7].c_str());
			double protein = atof(ingresultfound[8].c_str());
			double vitaminA = atof(ingresultfound[9].c_str());
			doublevitaminD = atof(ingresultfound[10].c_str());
			double vitaminE = atof(ingresultfound[11].c_str());
			double vitaminC = atof(ingresultfound[12].c_str());
			
			double gram = 1.0;

			Ingrediens ing(); 
			
			//Create a new Ingrediens object using the parsed values:
			Ingrediens ing(id,navn,gram,vann,kilojoule,fett,kolesterol,karbohydrat,kostfiber,protein,vitaminA,vitaminD,vitaminE,vitaminC);
			
			
			//TODO: make a push_back to a vector for storing multiple ingredients in a recipe.
			pair<Ingrediens,double> par;
			vector<pair<Ingrediens,double>> recipe;

			par = std::make_pair(ing,gram);
			
			//debugging to see if the variables are getting passed correctly.
			cout << par.first.getCarbohydrate() << "  " << par.second << endl;  
											   
			//more debugging to see if we can do ~math~
			cout << par.first.getCarbohydrate() * par.second << endl;  
			
			
			in.close();
		}
	}

int main()
	{
		

	//while ( getline(in,line) )    // get next line in file
    //{
    //    v.clear();
    //    stringstream ss(line);

    //    while (getline(ss,field,','))  // break line into comma delimitted fields
    //    {
    //        v.push_back(field);  // add each field to the 1D array
    //    }

    //    array.push_back(v);  // add the 1D array to the 2D array
    //}

	// print out what was read in

    //for (size_t i=0; i<array.size(); ++i)
    //{
    //    for (size_t j=0; j<array[i].size(); ++j)
    //    {
    //        cout << array[i][j] << ","; // (separate fields by ,)
    //    }
    //    cout << "\n";
    //}
	
	//searchCategory();
	parseIngredient();

	system("PAUSE");
	}
