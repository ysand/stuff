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

vector<string> getIngredient()
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

			return ingresultfound;
			
			
			in.close();
		}
	}

void parseIngredient(vector<string> _vectortobeparsed)
	{
		vector<string> vectortobeparsed = _vectortobeparsed;
			/*
			Converts the values in the vector as needed and assigns them to a variable. 
			*/
			double id = atof(vectortobeparsed[0].c_str());
			string navn = vectortobeparsed[1];
			double vann = atof(vectortobeparsed[2].c_str());
			double kilojoule = atof(vectortobeparsed[3].c_str());
			double fett = atof(vectortobeparsed[4].c_str());
			double kolesterol = atof(vectortobeparsed[5].c_str());
			double karbohydrat = atof(vectortobeparsed[6].c_str());
			double kostfiber= atof(vectortobeparsed[7].c_str());
			double protein = atof(vectortobeparsed[8].c_str());
			double vitaminA = atof(vectortobeparsed[9].c_str());
			double vitaminD = atof(vectortobeparsed[10].c_str());
			double vitaminE = atof(vectortobeparsed[11].c_str());
			double vitaminC = atof(vectortobeparsed[12].c_str());
			
			double gram = 2.0; //placeholder for debugging the Ingrediens constructor
 
			Ingrediens ing(id,navn,vann,kilojoule,fett,kolesterol,karbohydrat,kostfiber,protein,vitaminA,vitaminD,vitaminE,vitaminC);
			

			//TODO: make push_back to a vector or an array for storing multiple ingredients in a recipe along with their amounts.
			pair<Ingrediens,double> par;
			vector<pair<Ingrediens,double>> recipe;

			par = std::make_pair(ing,gram);
			
			//debugging to see if we can access the variables in the pair
			cout << par.first.getCarbohydrate() << "  " << par.second << endl; 

			//more debugging to see if we can do ~math~
			cout << par.first.getCarbohydrate() * par.second << endl;  

			//put the pair into a vector
			recipe.push_back(par);

			//see if we can print the contents of the pair inside the vector
			cout << recipe[0].first.getCarbohydrate() << " " << recipe[0].second <<endl;

			//perform ~math~ on the contents inside etc etc...
			cout << recipe[0].first.getCarbohydrate() * recipe[0].second << endl;
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
	parseIngredient(getIngredient());

	system("PAUSE");
	}
