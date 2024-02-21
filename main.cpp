#include "header.h"

int main(){

    int dim_B = count_line("buche.dat");
    buca* B = new buca[dim_B];

    int dim_P = count_line ("particelle.dat");
    part* P = new part [dim_P];


    load_data_B("buche.dat", B, dim_B);
    print_first_B(B,dim_B); 

    load_data_P("particelle.dat", P, dim_P);
    print_first_P(P,dim_P);

    get_npart(P, B, dim_B, dim_P);

    print_npart(B, dim_B);




return 0;    
}
