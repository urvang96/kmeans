/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kcluster.h
 * Author: Urvang
 *
 * Created on 5 May, 2018, 11:57 PM
 */

#ifndef KCLUSTER_H
#define KCLUSTER_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <ctime>
#include <math.h>
#include <cmath>
#include <cstring>

using namespace std;

class k_means{
    std::string fName;
    int k_neighbors;
    int rowCount;
    int colCount;
    std::vector<std::vector<float> > data;
    std::vector<std::vector<float> > clusters;
    
public:
    
k_means(std::string name, int k, const int row, const int col);
void parse_data();
void rand_init();
void assign_cluster();
void calcmean(std::vector<float> cNo);
~k_means();

};

#endif /* KCLUSTER_H */

