#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

#define num 10
#define len 100000000

using namespace std;



string ReadFile()
{
    string text;

    ifstream inFile;
    inFile.open("pi.txt");

    int count = 0;
    string line = "null";

    while(!inFile.eof())
    {
        getline(inFile,line);
        
        if ( line=="" || count < 21 )
        {
            count = count+1;
        }
        else
        {
            line.erase( remove( line.begin(), line.end(), ' ' ), line.end() ); // remove all spaces in the line
            line.erase( line.begin()+50, line.end() );                          // leave only first 50 charactors in the line
            text.append(line);
            
        }
            
    }
    
    inFile.close();

    return text;

}

void BadValueTable(string pattern, int BadValue[num], int M)
{
	int i;
    //char Characters[num];
    for ( i=0; i<num; i++)
    {
        BadValue[i] = -1;
    }
    //cout << Characters[0];
    for ( i=0; i<M; i++)
    {
        BadValue[(int)pattern[i]] = i;
    }
    
    /*for ( i=0; i<num; i++)
    {
    	cout << BadValue[i] << " ";
	}*/
}

void BoyerMoore(char *text, char *pattern)
{
	//cout << "1" << endl;
    // To store bad character value

    int M = strlen(pattern);
    int N = strlen(text);
    int i=0,j,count;
    
    int BadValue[num];

    // To calculate bad values
    BadValueTable(pattern, BadValue, M);
    //cout << "2" << endl;



    while ( i <= (N-M) )
    {
        j = M-1;

        while ( j >= 0 && pattern[j]==text[i+j])
        {
            j--;
        }

        if ( j < 0 )
        {
        	count++;
            cout /*<< " Found the pattern at index " */<< i << endl;
            if ( (i+M) < N)
            {
                i = i + M - BadValue[(int)text[i+M]];
            }
            else
            {
                i++;
            }
            //cout << "step1:i=" << i << endl;
            //i += (i + M < N)? M-BadValue[text[i + M]] : 1;  
        }
        else
        {
            //int p = max(1, j-BadValue[ text.at(i+j) ] );
            i = i + max(1, (j - BadValue[(int)text[i+j]]));
        }
    }
	cout << count << endl;
}	

int main()
{
    char pattern[] = "981211";
    	
	string text;

    ifstream inFile;
    inFile.open("pi.txt");

    int count = 0;
    string line = "null";

    while(!inFile.eof())
    {
        getline(inFile,line);
        
        if ( line=="" || count < 21 )
        {
            count = count+1;
        }
        else
        {
            line.erase( remove( line.begin(), line.end(), ' ' ), line.end() ); // remove all spaces in the line
            line.erase( line.begin()+50, line.end() );                          // leave only first 50 charactors in the line
            text.append(line);
            
        }
            
    }
    
    inFile.close();
    
    char *temp = new char[text.length()+1];
    strcpy (temp, text.c_str());
		
	BoyerMoore( temp, pattern );

    return 0;
}
