#include "iostream"
#include "fstream"
#include "vector"
#include "cmath"

#define X 0
#define Y 1

#define PI 3.14159265358979323846

using namespace std;

void LoadData(vector<double>[]);
void Normalize(vector<double>[]);
void Calculate(vector<double>[], double*, vector<double>, vector<double>, double*);

void main()
{
    vector<double> data[2];
    LoadData(data);

    int m = data[X].size();

    double a_0, a_m;
    vector<double> a_k, b_k;

    Normalize(data);
    Calculate(data, &a_0, a_k, b_k, &a_m);
}

void LoadData(vector<double> data[])
{
    ifstream f("test_data.txt");
    if (f.good())
    {
        int x = 0, y = 0;
        cout << "Loading data from .txt" << endl;
        while(f >> x >> y)
        {
            data[X].push_back(x);
            data[Y].push_back(y);
        }
        cout << "All data is loaded..." << endl;
        //Check x2-x1 = x3-x2 = ... 
    } else 
        cout << "Error: Data file does not exist!" << endl;
}

void Normalize(vector<double> data[])
{
    if(data[X][data[X].size() - 1] > 2*PI)
    {
        cout << "Normalizing x to 2pi..." << endl;
        double stretch = data[X][data[X].size() - 1] / (2 * PI);
        for(int i = 0; i < data[X].size(); i ++)
        {
            cout << data[X][i] << " " << data[Y][i] << " | ";
            data[X][i] /= stretch;
            cout << data[X][i] << " " << data[Y][i] << endl;
        }
        cout << "---------------" << endl;
    }
    else
        cout << "No need to normalize x." << endl;
}

void Calculate(vector<double> data[], double *a_0, vector<double> a_k, vector<double> b_k, double *a_m)
{
    int n = data[X].size();

    //Calculating a_0
    *a_0 = 0;
    for(int i = 0; i < n; i++)
        *a_0 += data[Y][i];
    *a_0 = *a_0 * 2 / n;  
    cout << "a_0: " << *a_0 << endl;

    //Calculating a_k
    cout << "a_k: ";
    for(int k = 0; k < n/2 - 1; k++)
    {
        a_k.push_back(0);
        for(int i = 0; i < n; i++)
            a_k[k] += data[Y][i] * cos(2*PI*(k+1)*i/n);
        a_k[k] = a_k[k] * 2 / n;
        cout << a_k[k] << " ";
    }
    cout << endl;

    //Calculating b_k
    cout << "b_k: ";
    for(int k = 0; k < n/2 - 1; k++)
    {
        b_k.push_back(0);
        for(int i = 0; i < n; i++)
            b_k[k] += data[Y][i] * sin(2*PI*(k+1)*i/n);
        b_k[k] = b_k[k] * 2 / n;
        cout << b_k[k] << " ";
    }
    cout << endl;
    
    //Calculating a_m
    *a_m = 0;
	for(int i = 0; i < n; i++)
		*a_m += (pow(-1,i)*data[Y][i]);
    *a_m = *a_m * 2 / n;
    cout << "a_m: " << *a_m << endl;
}