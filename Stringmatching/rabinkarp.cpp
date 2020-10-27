#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

int d = 10;

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

void RabinKarp(string text, string pattern)
{
    int N = text.length();
    int M = pattern.length();

    int q = 91;

    int Hpat = 0;
    int Htext = 0;
    int h = 1;
    int count = 0;

    int i,j;

    for ( i=0; i<M-1; i++)
    {
        h = ( h*d ) % q;
    }

    for ( i=0; i<M; i++ )
    {
        Hpat = ( d*Hpat + pattern.at(i) ) %q;
        Htext = ( d*Htext + text.at(i) ) %q;
    }

    for ( i=0; i< N-M+1; i++ )
    {
        if ( Hpat==Htext )          //check the hash values of the pattern and M length text at i position
        {
            for ( j=0; j<M; j++ )
            {
                if ( text.at(i+j)!=pattern.at(j) )      
                {
                    break;
                }
            }

            if ( j==M )
            {
                cout << "Found the pattern at index " << i << endl;
                count++;
            }
        }

        //hash values are not matched. calculte the hash value for the next shift of the text
        if ( i<N-M )
        {
            Htext = ( d*( Htext - text.at(i)*h) + text.at(i+M))%q;

            if ( Htext<0 )
            {
                Htext = Htext+q;
            }
        }
    }
    cout << count << endl;
}

int main()
{
    string pattern = "981211";

    RabinKarp(ReadFile(), pattern);

    return 0;
}
