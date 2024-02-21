#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

struct part{
float x;  //Ascissa particella
float y;  //Ordinata particella
int c;    //Carica particella
float m;  //Massa particella
};

struct buca{
float xc;     //Ascissa centro
float yc;     //Ordinata centro
float rad;    //Raggio
char lab;     //Etichetta
int n_part;   //Num. part in cerchio
part *v_part; //Vettore particelle
};

int count_line(const string& filename);
void load_data_B(const string& filename, buca* vec, int length);
void print_first_B(buca* vec, int length);
void load_data_P(const string& filename, part* vec, int length);
void print_first_P(part* vec, int length);
int calculate_distance (part p, buca b);
bool is_in(part p, buca b);
void get_npart(part* p, buca* b, int dim_p, int dim_b);
void print_npart(buca* b, int dim_B);
