#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

struct Sequence {
    string name;
    string sequence;
};

bool isValid(const string& seq){

for(int i = 0; i < seq.length(); i++){
    if (seq[i] != 'A' && seq[i] != 'C' && seq[i] != 'G' && seq[i]!='T' && seq.empty()){ return false;}
    
}
return true;

}

double gcContent(const string& seq)
{
    int gc = 0;
    for (char ch : seq)
    {if (ch == 'G' || ch == 'C')gc++;}
    return (100.0 * gc) / seq.length();
}

string reverseComplement(const string& seq){
    char temp;
    int first = 0;                      //first index
    int last = seq.length()-1;          //last index
    string seq2 = seq;

    while(last > first){            //this loop flips the string
        temp = seq2[first];
        seq2[first] = seq2[last];
        seq2[last] = temp;
        first++;
        last--;
        }
    for(int i = 0; i < seq2.size(); i++){           //swap the a/t and g/c pars
        switch(seq2[i]){
            case 'A':
            seq2[i] = 'T';
            break;
            case 'T':
            seq2[i] = 'A';
            break;
            case 'G':
            seq2[i] = 'C';
            break;
            case 'C':
            seq2[i] = 'G';
            break;
        }

    }
    return seq2;
}

void complementInPlace( string& seq){
 


    for(int i = 0; i < seq.size(); i++){           //swap the a/t and g/c pars
        switch(seq[i]){
            case 'A':
            seq[i] = 'T';
            break;
            case 'T':
            seq[i] = 'A';
            break;
            case 'G':
            seq[i] = 'C';
            break;
            case 'C':
            seq[i] = 'G';
            break;
        }

    }
   
}

void insertionSortByName(vector<Sequence>& records,int& comparisons,int& shifts)
{
    comparisons = 0;
    shifts = 0;
     for(int i = 1; i < records.size(); i++)
    {
    Sequence key = records[i];      //temp sequence
    int j = i - 1;                  //
    while(j >= 0){                  //shiftinh loop
    comparisons++;
    if(records[j].name > key.name){     //keep shifting 
    records[j + 1] = records[j];
    shifts++;   
    j--;}
    else{break;}
    }
     records[j + 1] = key;
    }
}

int linearSearchByName(const vector<Sequence>& records, const string& target, int& comparisons)
{ comparisons = 0;
    for(int i = 0; i < records.size(); i++)
    {comparisons++;
    if(records[i].name == target){return i;} //returns index of found name
    }

    return -1;
}

int binarySearchByName(const vector<Sequence>& records,const string& target,int& comparisons)
{
    comparisons = 0;

    int low = 0;
    int high = records.size() - 1;
    while(low <= high)
    {
    int mid = (low + high) / 2;
    comparisons++;
    if(records[mid].name == target) {return mid;}           //check if midpoint is target
    comparisons++;
    if(target < records[mid].name){high = mid - 1;}     //check if target is on left side
    else{low = mid + 1;}                                //check if target is on right side
    }

    return -1;
}


int main()
{
    vector<Sequence> records;
    ifstream fin("dna.txt");            //input file
    string name, sequence;
    while(fin >> name >> sequence)
    {
    if(isValid(sequence))
{
            records.push_back({name, sequence});            //push back appends date to a record
}
        else{ cout << "not a valid sequence" << endl;}
    }
    

    // Print table
    cout << "\nName GC Reverse Complement\n";

    for(int i = 0; i < records.size(); i++)
    {
        cout << records[i].name << "\n" << gcContent(records[i].sequence) << "\n"<< reverseComplement(records[i].sequence)<< endl; // output the data for table
    }

    // Highest GC record
    int best = 0;

    for(int i = 1; i < records.size(); i++)
    {
        double currentGC =
            gcContent(records[i].sequence);

        double bestGC =
            gcContent(records[best].sequence);

        if(currentGC > bestGC)
        {
            best = i;
        }
        else if(currentGC == bestGC &&
                records[i].name < records[best].name)
        {
            best = i;
        }
    }

