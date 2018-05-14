/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "function_definations.h"

func_def::func_def(std::string name, int k){
    fName = name;
    k_neighbors = k;
}

std::vector<int> func_def::get_size(){
    ifstream fin(fName);
    std::string line;
    std::vector<int> val(2);
    int row = 0, col = 0;
        while (std::getline(fin, line, '\n'))
    {
        int n;
        stringstream s(line);
        while (s >>n)
            if(row == 0)
                col++;
        row++;
    }
    val[0] = col;
    val[1] = row;
    
    return val;
}