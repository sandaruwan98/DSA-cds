#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

struct organ
{
	string name;
	float RedbloodCells;
	float WhitebloodCells;
	float Platelets;
	float FlowRate;
	float Distance;
	void SetDetails(string name, float RedbloodCells, float WhitebloodCells, float Platelets, float FlowRate, float Distance)
	{
		this->name = name;
		this->RedbloodCells = RedbloodCells;
		this->WhitebloodCells = WhitebloodCells;
		this->Platelets = Platelets;
		this->FlowRate = FlowRate;
		this->Distance = Distance;
	}
};

class Graph
{
    list<int> *list1;
    int v;

	public:
    	Graph(int v);
    	void AddEdge(int v, int w);
    	void getList(int v,struct organ Array[9]); 
};

Graph::Graph(int v)
{
    this->v = v;
    list1 = new list<int>[v];
}

void Graph::AddEdge(int v, int w)
{
    list1[v].push_back(w);
}

void Graph::getList(int v,struct organ Array[9])
{
	list<int>::iterator i;
	for ( i=list1[v].begin(); i!=list1[v].end(); ++i)
	{
		cout << '\t' << Array[*i].name << endl;
	}
	cout << endl;
}

void ViewOrgan(struct organ Array[9])
{
	int i;
	for ( i=0; i<9; i++)
	{
		cout << '\t' << i << '.'<< Array[i].name << endl;
	}
}

void OrganDetails(int i, struct organ Array[9])
{
	cout << endl << " Organ                                   : " << Array[i].name << endl
		 //<< " Count of Red blood cells in billion     : " << Array[i].RedbloodCells << " billion " << endl
		 //<< " Count of White blood cells million      : " << Array[i].WhitebloodCells << " million " << endl
		 //<< " Count of Platelets million              : " << Array[i].Platelets << " million " << endl
		 << " Flow rate of blood per minute in liters : " << Array[i].FlowRate << endl
		 << " Distance from the heart to " << Array[i].name << " in inches : " << Array[i].Distance << " inch" << endl << endl; 
}

void TraverseRedBloodCells(int i, struct organ Array[9])
{
	float j, total;
	if ( Array[i].name == "Right_atrium" || Array[i].name == "Left_atrium" )
	{
		cout << " Before the heart beat " << Array[i].name << " was empty" << endl 
			 << " After traversing blood ";  // There are 5 million red blood cells in 1 qubic milimeter of blood
		j = 70 * 5 ;	                     // capacity of left and right atriums is 70 ml
		total = j + Array[i].RedbloodCells;
		cout << Array[i].name << " receives " << total << " billion red blood cells " << endl
			 << " Total Red blood cells in the " << Array[i].name << " is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Right_ventricle" || Array[i].name == "Left_ventricle" )
	{
		cout << " Before the heart beat " << Array[i].name << " had " << Array[i].RedbloodCells << " billion red blood cells " << endl
			 << " After traversing blood "; //capacity of left and right ventricle is 120ml.
											// After squeezing 50ml amount of blood remains
			 
		j = Array[i].RedbloodCells - 70 * 5;
		Array[i].RedbloodCells = j;
		
		cout << 70*5 << " billion of red blood cells eject from " << Array[i].name << " and " 
			 << Array[i].RedbloodCells << " billion of red blood cells remains in " << Array[i].name << endl;
	}
	
	else if ( Array[i].name == "Lungs")
	{
		j = 70 * 5;
		total = j + Array[i].RedbloodCells;
		
		cout << " Lungs receives " << Array[i].RedbloodCells << " billion of red blood cells from Right_ventricle" << endl 
			 << " Total Red blood cells in the Lungs is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Brain")
	{
		j = 70 * 5 * 0.13; 
		total = j + Array[i].RedbloodCells;   // Brain receives 13% from the cardic output
		cout << " Brain receives " << j << " billion of red blood cells from Left_ventricle" << endl
			 << " Total Red blood cells in the Brain is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Liver")
	{
		j = 70 * 5 * 0.06;     // Liver receives 6% from the cardic output
		total = j + Array[i].RedbloodCells;
		cout << " Liver receives " << j << " billion of red blood cells from Left_ventricle" << endl
			 << " Total Red blood cells in the Liver is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Kidneys")
	{
		j = 70 * 5 * 0.20;     // Kidneys receives 20% from the cardic output
		total = j + Array[i].RedbloodCells;
		cout << " Kidneys receives " << j << " billion of red blood cells from Left_ventricle" << endl
			 << " Total Red blood cells in the Kidney is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Skin")
	{
		j = 70 * 5 * 0.09;     // Skin receives 9% from the cardic output
		total = j + Array[i].RedbloodCells;
		cout << " Skin receives " << j << " billion of red blood cells from Left_ventricle" << endl
			 << " Total Red blood cells in the Skin is " << total << " billion " << endl;	 
	}
	
}


void TraverseWhiteBloodCells(int i, struct organ Array[9])
{
	float j, total;
	if ( Array[i].name == "Right_atrium" || Array[i].name == "Left_atrium" )
	{
		cout << " Before the heart beat " << Array[i].name << " was empty" << endl 
			 << " After traversing blood ";  // There are average 7500 white blood cells in 1 qubic milimeter of blood
			                    			 // capacity of left and right atriums is 70 ml
		j = 7 * 75 ;
		total = j + Array[i].WhitebloodCells;
		cout << Array[i].name << " receives " << j << " million of white blood cells " << endl;
			  
	}
	
	else if ( Array[i].name == "Right_ventricle" || Array[i].name == "Left_ventricle" )
	{
		cout << " Before the heart beat " << Array[i].name << " had " << Array[i].WhitebloodCells << " million of white blood cells " << endl
			 << " After traversing blood "; //capacity of left and right ventricle is 120ml. 
			                                //After squeezing 50ml amount of blood remains
			 
		j = Array[i].WhitebloodCells - 7 * 75 ;
		Array[i].WhitebloodCells = j;
		
		cout << 7 * 75  << " million of white blood cells eject from " << Array[i].name << " and " 
			 << Array[i].WhitebloodCells << " million of white blood cells remains in " << Array[i].name << endl;
	}
	
	else if ( Array[i].name == "Lungs")
	{
		j = 7 * 75 ;
		total = j + Array[i].WhitebloodCells;
		cout << " Lungs receives " << j << " million of white blood cells from Right_ventricle " << endl
			 << " Total white blood cells in the Lungs is " << total << " million " << endl;
	}
	
	else if ( Array[i].name == "Brain")
	{
		j = 7 * 75  * 0.13;    // Brain receives 13% from the cardic output
		total = j + Array[i].WhitebloodCells;
		
		cout << " Brain receives " << j << " million of white blood cells from Left_ventricle" << endl
			 << " Total white blood cells in the Brian is " << total << " million " << endl;
	}
	
	else if ( Array[i].name == "Liver")
	{
		j = 7 * 75  * 0.06;     // Liver receives 6% from the cardic output
		total = j + Array[i].WhitebloodCells;
		
		cout << " Liver receives " << j << " million of white blood cells from Left_ventricle" << endl
			 << " Total white blood cells in the Liver is " << total << " million " << endl;
	}
	
	else if ( Array[i].name == "Kidneys")
	{
		j = 7 * 75 * 0.20;     // Kidneys receives 20% from the cardic output
		total = j + Array[i].WhitebloodCells;
		
		cout << " Kidneys receives " << j << " million of white blood cells from Left_ventricle" << endl
			 << " Total white blood cells in the Kidneys is " << total << " million " << endl;
	}
	
	else if ( Array[i].name == "Skin")
	{
		j = 7 * 75 * 0.09;     // Skin receives 9% from the cardic output
		total = j + Array[i].WhitebloodCells;
		
		cout << " Skin receives " << j << " million of white blood cells from Left_ventricle" << endl
			 << " Total white blood cells in the Skin is " << total << " million " << endl;
	}
}



void TraversePlatelets(int i, struct organ Array[9])
{
	float j,total;
	if ( Array[i].name == "Right_atrium" || Array[i].name == "Left_atrium" )
	{
		cout << " Before the heart beat " 
			 << Array[i].name << " was empty" << endl 
			 << " After traversing blood ";  // There are average 300000 Platelets in 1 qubic milimeter of blood
			 
		j = 7 * 3 ;	                  // capacity of left and right atriums is 70 ml
		cout << Array[i].name << " receives " << j << " billion of platelets " << endl;
			  
	}
	
	else if ( Array[i].name == "Right_ventricle" || Array[i].name == "Left_ventricle" )
	{
		cout << " Before the heart beat " << Array[i].name 
			 << " had " << Array[i].Platelets << " billion of platelets " << endl
			 
			 << " After traversing blood "; //capacity of left and right ventricle is 120ml. After squeezing 50ml amount of blood remains
			 
		j = Array[i].Platelets - 7 * 3 ;
		Array[i].Platelets = j;
		
		cout << 7 * 3 << " billion of platelets eject from " << Array[i].name 
			 << " and " << Array[i].Platelets 
			 << " billion of platelets remains in " << Array[i].name << endl;
	}
	
	else if ( Array[i].name == "Lungs")
	{
		j = 7 * 3 ;
		total = j + Array[i].Platelets;
		
		cout << " Lungs receives " << Array[i].Platelets << " billion of platelets from Right_ventricle " << endl
			 << " Total Platelets in the Lungs is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Brain")
	{
		j = 7 * 3 * 0.13;    // Brain receives 13% from the cardic output
		total = j + Array[i].Platelets;
		
		cout << " Brain receives " << j << " billion of platelets from Left_ventricle" << endl
			 << " Total Platelets in the Brain is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Liver")
	{
		j = 7 * 3  * 0.06;     // Liver receives 6% from the cardic output
		total = j + Array[i].Platelets;
		
		cout << " Liver receives " << j << " billion of platelets from Left_ventricle" << endl
			 << " Total Platelets in the Liver is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Kidneys")
	{
		j = 7 * 3 * 0.20;     // Kidneys receives 20% from the cardic output
		total = j + Array[i].Platelets;
		
		cout << " Kidneys receives " << j << " billion of platelets from Left_ventricle" << endl
			 << " Total Platelets in the Kidneys is " << total << " billion " << endl;
	}
	
	else if ( Array[i].name == "Skin")
	{
		j = 7 * 3 * 0.09;     // Skin receives 9% from the cardic output
		total = j + Array[i].Platelets;
		
		cout << " Skin receives " << j << " billion of platelets from Left_ventricle" << endl
			 << " Total Platelets in the Skin is " << total << " billion " << endl;
	}
}

void CalculateNumberOfTimesRed(int i, struct organ Array[9])
{
	int DayTime;
	cout << " The heart beats 100000 times per day " << endl
		 << " The life span of a red blood cell is 100 days " << endl
		 << " Hence a red blood cell traverse through the heart 10 million times " << endl
		 << " A red blood cell traverse through ";
	
	DayTime = 10;
		 
	if ( Array[i].name == "Right_atrium" || Array[i].name == "Right_ventricle" || Array[i].name == "Left_atrium" ||  Array[i].name =="Left_ventricle" || Array[i].name == "Lungs")
	{
		cout << Array[i].name << ' ' << DayTime;
	}
	
	else if (Array[i].name == "Brain")
	{
		cout << Array[i].name << ' ' << DayTime * 0.13;
	}
	else if (Array[i].name == "Liver")
	{
		cout << Array[i].name << ' ' << DayTime * 0.06;
	}
	else if (Array[i].name == "Kidneys")
	{
		cout << Array[i].name << ' ' << DayTime * 0.20;
	}
	else if (Array[i].name == "Skin")
	{
		cout << Array[i].name << ' ' << DayTime * 0.09;
	}
	
	cout << " million times in its life span " << endl;
}

void CalculateNumberOfTimesWhite(int i, struct organ Array[9])
{
	float DayTime;
	cout << " The heart beats 100000 times per day " << endl
		 << " The life span of a red blood cell is 15 days " << endl
		 << " Hence a white blood cell traverse through the heart 1.5 million times " << endl
		 << " A white blood cell traverse through ";
	
	DayTime = 1.5;
		 
	if ( Array[i].name == "Right_atrium" || Array[i].name == "Right_ventricle" || Array[i].name == "Left_atrium" ||  Array[i].name =="Left_ventricle" || Array[i].name == "Lungs")
	{
		cout << Array[i].name << ' ' << DayTime;
	}
	
	else if (Array[i].name == "Brain")
	{
		cout << Array[i].name << ' ' << DayTime * 0.13;
	}
	else if (Array[i].name == "Liver")
	{
		cout << Array[i].name << ' ' << DayTime * 0.06;
	}
	else if (Array[i].name == "Kidneys")
	{
		cout << Array[i].name << ' ' << DayTime * 0.20;
	}
	else if (Array[i].name == "Skin")
	{
		cout << Array[i].name << ' ' << DayTime * 0.09;
	}
	
	cout << " million times in its life span " << endl;
}

void CalculateNumberOfTimesPlatelets(int i, struct organ Array[9])
{
	float DayTime;
	cout << " The heart beats 100000 times per day " << endl
		 << " The life span of a platelet is 7 days " << endl
		 << " Hence a platelet traverse through the heart 700000 times " << endl
		 << " A platelet traverse through ";
	
	DayTime = 700000;
		 
	if ( Array[i].name == "Right_atrium" || Array[i].name == "Right_ventricle" || Array[i].name == "Left_atrium" ||  Array[i].name =="Left_ventricle" || Array[i].name == "Lungs")
	{
		cout << Array[i].name << ' ' << DayTime;
	}
	
	else if (Array[i].name == "Brain")
	{
		cout << Array[i].name << ' ' << DayTime * 0.13;
	}
	else if (Array[i].name == "Liver")
	{
		cout << Array[i].name << ' ' << DayTime * 0.06;
	}
	else if (Array[i].name == "Kidneys")
	{
		cout << Array[i].name << ' ' << DayTime * 0.20;
	}
	else if (Array[i].name == "Skin")
	{
		cout << Array[i].name << ' ' << DayTime * 0.09;
	}
	
	cout << " times in its life span " << endl;
}

int main()
{
	struct organ OrganArray[9];
	OrganArray[0].SetDetails("Right_atrium", 0, 0, 0, 5.15, 0);
	OrganArray[1].SetDetails("Right_ventricle", 600.0, 900.0, 36.0, 5.15, 0);
	OrganArray[2].SetDetails("Left_atrium", 0, 0, 0, 5.15, 0);
	OrganArray[3].SetDetails("Left_ventricle", 600.0, 900.0, 36.0, 5.15, 0);
	OrganArray[4].SetDetails("Lungs", 350.0, 525.0, 21.0, 3.5, 2.2);
	OrganArray[5].SetDetails("Brain", 45.5, 68.25, 2.73, 0.75, 13);
	OrganArray[6].SetDetails("Liver", 21.0, 31.5, 1.26, 0.115, 8);
	OrganArray[7].SetDetails("Kidneys", 70.0, 105.0, 4.2, 1.25, 15);
	OrganArray[8].SetDetails("Skin", 31.5, 47.25, 1.89, 0.25, 12);
	
    Graph g(9);
    g.AddEdge(0, 1);
    g.AddEdge(1, 4);
    g.AddEdge(2, 3);
    g.AddEdge(3, 5);
    g.AddEdge(3, 6);
    g.AddEdge(3, 7);
    g.AddEdge(3, 8);
    g.AddEdge(4, 2);
    g.AddEdge(5, 0);
    g.AddEdge(6, 0);
    g.AddEdge(7, 0);
    g.AddEdge(8, 0);

    while (1)
    {
    	int opt, n;
    	cout << endl
			 << " Cardiovascular System " << endl
    		 << " --------------------- " << endl << endl
    		 << " 1. View Organ Details " << endl
    		 << " 2. View Adjacent Organs " << endl 
    		 << " 3. Traversal of the Red Blood Cells to an Organ in a heart beat " << endl 
    		 << " 4. Traversal of the White Blood Cells to an Organ in a heart beat " << endl
    		 << " 5. Traversal of the Platelets to an Organ in a heart beat " << endl 
    		 << " 6. The number of times a red blood cell traverse through an organ in its life span " << endl 
    		 << " 7. The number of times a white blood cell traverse through an organ in its life span " << endl 
    		 << " 8. The number of times a platelet traverse through an organ in its life span " << endl << endl
    		 << " Enter your option : ";
    		 
    	cin >> opt;
    	ViewOrgan( OrganArray );
    	cout << endl << " Enter the index of the particular Organ : ";
   		cin >> n;
   		
	  	if ( n> 9)
		{
   			cout << " Enter a valid index " << endl << endl;
		}
		else
    	{
    		switch(opt)
    		{
    			case 1: 
					OrganDetails(n, OrganArray);
					cout << ' ' << OrganArray[n].name << " carries blood to " << endl;
					g.getList(n,OrganArray);

					break;
				
				case 2:
					cout << ' ' << OrganArray[n].name << " carries blood to " << endl;
					g.getList(n,OrganArray);
				
					break;
					
				case 3:
					TraverseRedBloodCells(n,OrganArray);
					break;
					
				case 4:
					TraverseWhiteBloodCells(n,OrganArray);
					break;
					
				case 5:
					TraversePlatelets(n,OrganArray);
					break;
					
				case 6:
					CalculateNumberOfTimesRed(n,OrganArray);
					break;
					
				case 7:
					CalculateNumberOfTimesWhite(n,OrganArray);
					break;
					
				case 8:
					CalculateNumberOfTimesPlatelets(n,OrganArray);
					break;
				
				default:
					break;
			}
		}
	}
   
    return 0;
}
