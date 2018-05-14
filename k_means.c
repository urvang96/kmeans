/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "k_means.h"

k_means::k_means(std::string name, int k, int row, int col){
    fName = name;
    k_neighbors = k;
    rowCount = row;
    colCount = col;
}