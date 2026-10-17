#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

double randUnit() {return rand() / (RAND_MAX+1);} //this guaruntees that we'll never get anything besides a number between 0 and 1

bool insideQuarterCircle(double x, double y){return (x*x + y*y <=1.0);} //returns true if the paremetization of x and y is within the unit circle

double estimatePi(unsigned int n, unsigned int& hits){
    hits = 0;

    for(int i = 0; i < n; i++){
        double x = randUnit();
        double y = randUnit();

        if (insideQuarterCircle(x,y)) { hits ++;}


    }
    return 4.0 * hits/n;
}

 void summarizeErrors(const vector<double>& errors)
 {
    double max = errors[0];
    double min = errors[0];

    double sum = 0;
    for(int i = 0; i < errors.size(); i++)

    {

        sum += errors[i];
        if(max < errors[i]) { max = errors[i];}
        if (min > errors[i]){min = errors[i]; }
    }

    double mean = sum/ errors.size();
    cout << "\nMean Error: " << mean << endl;
    cout <<"max: " <<max << endl;
    cout <<"min: " << min << endl;



 }

 int nextExperimentId()
{
    static int id = 0;
    id++;
    return id;
}