#include "header.h"

//fumzione per trovare la dimensione del file "buche.dat" e del file "particelle.dat"
int count_line(const string& filename){
    ifstream infile(filename); 
    if(!infile.good())         
        cout << "Error... Cannot open the file." << endl;
    
    int count = 0;     
    string str = "";   

    while(!infile.eof()){                
        getline(infile, str);            
        count++;
    }

    infile.clear();   
    infile.seekg(0);  
    infile.close();
    
    return count;   
}

//funzione per caricare l'array B 
void load_data_B(const string& filename, buca* vec, int length){ 
    ifstream infile(filename);   
    if(!infile.good())           
           cout << "Error... Cannot open the file." << endl;

    for(int i = 0; i < length; i++)   
        infile >> vec[i].xc >> vec[i].yc >> vec[i].rad >> vec[i].lab;  

    infile.close(); 
}

//funzione per stampare l'array B
void print_first_B(buca* vec, int length){  
    for(int i = 0; i < length; i++){
        cout << "Il cerchio numero " << i+1 << " ha descrizione: ("<< vec[i].xc << ",\t" << vec[i].yc << ",\t" << vec[i].rad << ",\t" << vec[i].lab << ")"<< endl; 
        }                                                                         
    cout << "Il numero di cerchi letti è: " << length << endl; 
    cout << endl;
}

//funzione per caricare l'array P
void load_data_P(const string& filename, part* vec, int length){ 
    ifstream infile(filename);   
    if(!infile.good())           
           cout << "Error... Cannot open the file." << endl;

    for(int i = 0; i < length; i++)   
        infile >> vec[i].x >> vec[i].y >> vec[i].c >> vec[i].m;  

    infile.close(); 
}

//funzione per stampare l'array P
void print_first_P(part* vec, int length){  
    cout << "La prima particella ha x = " << vec[0].x << ",  ha y = "<< vec[0].y << ", ha carica = " << vec[0].c << ", ha massa = " << vec[0].m << endl; 
    cout << "La seconda particella ha x = " << vec[1].x << ",  ha y = "<< vec[1].y << ", ha carica = " << vec[1].c << ", ha massa = " << vec[1].m << endl; 
    cout << "La terza particella ha x = " << vec[2].x << ",  ha y = "<< vec[2].y << ", ha carica = " << vec[2].c << ", ha massa = " << vec[2].m << endl; 
    cout << "L'ultima particella ha x = " << vec[length -1].x << ",  ha y = "<< vec[length-1].y << ", ha carica = " << vec[length-1].c << ", ha massa = " << vec[length-1].m << endl;
    cout << "La penultima particella ha x = " << vec[length -2].x << ",  ha y = "<< vec[length-2].y << ", ha carica = " << vec[length-2].c << ", ha massa = " << vec[length-2].m << endl;
    cout << "La terzultima particella ha x = " << vec[length -3].x << ",  ha y = "<< vec[length-3].y << ", ha carica = " << vec[length-3].c << ", ha massa = " << vec[length-3].m << endl;
    cout << endl;
}


// funzione per calcolare la distanza tra centro del cerchio e particella
int calculate_distance (part p, buca b){
    int distance = sqrt(pow(b.xc-p.x,2)-pow(b.yc-p.y,2));

return distance;
}

bool is_in(part p, buca b){
    if(calculate_distance(p,b) < b.rad == true)
        return true;
    return false;
}


void get_npart(part* p, buca* b, int dim_p, int dim_b){
    int count = 0;
    for(int i = 0; i < dim_b; i++){
        for(int j = 0; j < dim_p; j++){
            if(is_in(p[j], b[i]) == true){
                count++;
            }
        }
        b[i].n_part = count;
        count = 0;
    }
}


void print_npart(buca* b, int dim_B){
    for(int i = 0; i < dim_B; i++)
        cout << "N_PART: " << b[i].n_part << endl;
}
