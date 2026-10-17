#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;

typedef struct Runner{
    int bib;
    string name;
    double minutes;
}Runner;

void selectionSortbyBib(vector<Runner>& ppl){
    
    for(int i = 0; i < ppl.size()-1; i++){
        int min = i;
        for(int j = i+1; j<ppl.size(); j++)         //find index ofsmallest element and swap
        {if(ppl[min].bib > ppl[j].bib){min = j;}
        
        }
        swap(ppl[min], ppl[i]);

    }
}

int insertionSortByMinutes(vector<Runner>& ppl){
int count = 0;
 for(int i = 1; i < ppl.size(); i++)
 {
 Runner key = ppl[i];
 int j = i - 1;
 while(j >= 0 && ppl[j].minutes > key.minutes)
 {
    count++;
 ppl[j + 1] = ppl[j];                       //shift everything below key to the right until key is greatest
 j--;
 }
 ppl[j + 1] = key;
 
 }
 return count;
       }

int linearSearchByBib(int bib, const vector<Runner>& ppl)
{
    for(int i = 0; i < ppl.size(); i++){
        if(ppl[i].bib == bib){return i;}
    }
    return -1;
}

void loadRunners(vector<Runner>& ppl){

    ifstream inputFile("runners.txt");
    if(!inputFile){cout <<"\nERROR: CANNOT OPEN RUNNERS.TXT:("; return;}

    int b;
    string n;
    double m;
    int count = 0;
    Runner r;

    while(inputFile>> r.bib >>r.name >> r.minutes  ){
        
       ppl.push_back(r);
    }
}

bool isSortedByBib(vector<Runner>& ppl){
    for(int i = 0; i< ppl.size()-1; i++){
        if (ppl[i].bib > ppl[i+1].bib){return false;}
    }
    return true;
}

int binarySearchByBib(int bib, vector<Runner>& ppl){
    if(!isSortedByBib(ppl)){selectionSortbyBib(ppl);} 
    else{}

    int low = 0;
    int high = ppl.size() -1;

    while (low<= high){
        int mid = (low+high)/2;  //find midpoint

        if(ppl[mid].bib == bib){return mid;}
        else if(ppl[mid].bib > bib){high = mid - 1;}        //search left side of vector
        else {low = mid + 1;}                               //search right side of vector
    }
    return -1;

    }


double meanTime(const vector<Runner>& ppl)
{
    double sum = 0;
     for(int i = 0; i < ppl.size(); i++)
    {sum += ppl[i].minutes;
    }
    return sum / ppl.size();
}

double medianTime(const vector<Runner>& ppl)
{
    int n = ppl.size();
     if(n % 2 == 1)          //check if there is an odd amount
     {return ppl[n/2].minutes;}
    else
    {
        return (ppl[n/2 - 1].minutes +          //if even then avergae the two middle ones
                ppl[n/2].minutes) / 2.0;
    }
}

int countUnder(double limit, const vector<Runner>& ppl)
{
    int count = 0;
     for(int i = 0; i < ppl.size(); i++)    //loop thru vector
    {   if(ppl[i].minutes < limit)          //check if the time is below limit and increment count if it isnt
        {count++;}}
    return count;
}

void printTop(const vector<Runner>& ppl, int k)
{
    for(int i = 0; i < k && i < ppl.size(); i++)        //print first k people in vector. vector will
    {
        cout << ppl[i].bib << " "           //prints the ppl on one line
             << ppl[i].name << " "
             << ppl[i].minutes << endl;
    }
}


    int main(){
        vector<Runner> ppl;
        loadRunners(ppl);
        for(int i = 0 ; i < ppl.size(); i++){

            cout << ppl[i].bib << " "           //prints the ppl on one line
             << ppl[i].name << " "
             << ppl[i].minutes << endl;
            
        }
        int count = insertionSortByMinutes(ppl);     //insertion sort 

        cout << "\nsort count: " << count <<endl;
        cout << "top 3: "; printTop(ppl, 3);
        cout << "\nmedian: " << medianTime(ppl) <<endl;
        cout << "mean: " << meanTime(ppl) << endl;

        //find number below 210
        int n = 0;
        for(int i = 0; i < ppl.size(); i++){
            if (ppl[i].minutes > 210) {break;}
            else {n++;}
        
        }
        cout << "people below 210 mins: " << n <<endl;
        
        return 0;


    }



