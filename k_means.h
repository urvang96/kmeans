/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   k_means.h
 * Author: Urvang
 *
 * Created on 5 May, 2018, 11:48 PM
 */

#ifndef K_MEANS_H
#define K_MEANS_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

class k_means{
    std::string fName;
    int k_neighbors;
    int rowCount;
    int colCount;
    auto data = new float [rowCount][colCount];
    
public:
    
k_means(std::string name, int k, int row, int col);   

};


#endif /* K_MEANS_H */

