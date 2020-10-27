#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<algorithm>

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

void naive(string text, char* pattern)
{
	int c = 0;
    int N = text.length();
    int M = strlen(pattern);

    int i;

    for ( i=0; i< N-M+1; i++ )                               //shift the pattern by one position
    {
        int j;
        for ( j=0; j<M; j++ )                                //check the pattern with each element
        {
            if ( text.at(i+j)!=pattern[j] )
            break;
        }
        if ( j==M )                                         //no of matching characters = length of the pattern
        {
            cout << "pattern found at index " << i << endl;
            c++;
        }
    }
    cout << c << endl;
}

int main()
{
    char pattern[] = "981211";

    naive( ReadFile(), pattern );

    return 0;
}
