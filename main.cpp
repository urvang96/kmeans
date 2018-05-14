/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Urvang
 *
 * Created on 5 May, 2018, 6:06 PM
 */

#include "kcluster.h"

std::vector<int> get_size(std::string fName){
    ifstream fin(fName);
    std::string line;
    std::vector<int> val(2);
    int row = 0, col = 0;

    while (std::getline(fin, line, '\n'))
    {
        float n;
        col = 0;
        stringstream s(line);
        while (s >> n){
            col++;
        }
        row++;
    }
    val[0] = col;
    val[1] = row;
    
    fin.close();
    
    cout<<"Rows:"<<row<<endl;
    cout<<"Columns:"<<col<<endl;
    
    return val;
}

int main(int argc, char** argv) {
    

    std::string name = argv[1];
    std::string kn = argv[2];

//    std::string name = "points.txt";
    
    std::vector<int> a(2);
    a = get_size(name);

    k_means k(name, 2, a[1], a[0]);
    k.parse_data();
    k.rand_init();

    int iterations = 0;
    while (iterations < 5){
        cout<<"Call no:"<<iterations + 1<<endl;
        k.assign_cluster();
        iterations++;
    }
    return 0;
}

