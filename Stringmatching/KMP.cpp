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
    //cout << "File read successfully" << endl;

    return text;

}

void preprocessFunc(char* pattern, int* lps, int M)
{
	//cout << "1";

    lps[0] = 0;

    int i,j;
    //M = strlen(pattern);
    j=0;
    i=1;

    while ( i<M )                               //preprocess terminates at the end of the pattern
    {
        if ( pattern[i]==pattern[j] )
        {
            lps[i] = j+1;
            i++;
            j++;
        }
        else
        {
            if ( j==0 )
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }
    /*cout << "lps successfully" << endl;
    for ( i=0; i<M; i++ )
    {
        cout << lps[i];
    }
    return lps;*/
}


void KMP(string text, char* pattern)
{
    //cout << "KMP call successfully" << endl;
    int N = text.length();
    int M = strlen(pattern);
    int matches = 0;
    
    int lps[M];

    preprocessFunc(pattern, lps, M);
    //cout << "lps return successfully" << endl;

    int i = 0;
    int j = 0;

    while ( i<N )
    {
        if ( text.at(i)== pattern[j] )
        {
            i++;
            j++;
        }

        if ( j == M )                                               //no.of matching characters = length of the pattern
        {
            cout << "Pattern found at index " << i-j << endl;
            j = lps[j-1];                                           //although the pattern found, keeps searching 
            matches++;
        }

        else if ( i<N && text.at(i) != pattern[j] )
        {
            if ( j != 0 )
            {
                j = lps[j-1];
            }
            else 
            {
                i++;
            }
        }
    }
    cout << matches << endl;                                //no.of matches
}


int main()
{
    char pattern[] = "981211";
    KMP( ReadFile(), pattern );

    return 0;
}
