/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   function_definations.h
 * Author: Urvang
 *
 * Created on 5 May, 2018, 11:13 PM
 */

#ifndef FUNCTION_DEFINATIONS_H
#define FUNCTION_DEFINATIONS_H



class func_def{
    std::string fName;
    int k_neighbors;
    int rowCount;
    int colCount;
    auto data = new float [rowCount][colCount];
    
public:
    
 func_def(std::string name, int k);   
 std::vector<int> get_size();
 
            
};


#endif /* FUNCTION_DEFINATIONS_H */

