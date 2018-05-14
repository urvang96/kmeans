/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "kcluster.h"

k_means::k_means(std::string name, int k, int row, int col){
    fName = name;
    k_neighbors = k;
    rowCount = row;
    colCount = col;
}

void k_means::parse_data(){

    std::vector<float> row;
    ifstream fin(fName);
    std::string line;
    int i = 0;

    while (std::getline(fin, line, '\n'))
    {
        
        float n; 
        int j = 0;
        stringstream s(line);
        while (s >> n)
        {
            row.push_back(n);
        }
        data.push_back(row);
        row.clear();
        row.shrink_to_fit();
    }
    fin.close();
    
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout<<data[i][j]<<"\t";
        }
        cout<<endl;
    }
    data.shrink_to_fit();
    cout<<"Data Prased"<<endl;    
}



void k_means::rand_init(){

    srand((int) time(0));
    int rand_num = 0;
    for (int i = 0; i < k_neighbors; i++){
        rand_num = (rand() % rowCount) + 1;
        clusters.push_back(data[rand_num]);
    }
    
//    vector<float> temp;
//    for(int j =0; j < rowCount; j++){
//        for(int i = 0; i < colCount; i++){
//            temp.push_back(0);
//        }
//        clusters.push_back(temp);
//    }
    cout<<"init done";
    
    cout<<"Old Clusters:";
    for (int i = 0; i < k_neighbors; i++){
        for (int j = 0; j < colCount; j++){
            cout<<clusters[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    clusters.shrink_to_fit();
}

int get_minimum(std::vector<float> &difference){

    std::vector<float>::iterator it;
    int i;
    float min_val = difference[0];
    int position = 0;
    for (it = difference.begin(), i = 0; it != difference.end(); it++, i++){
        cout<<"Distance Calculated:"<<*it<<endl;
        if (*it < min_val){
            min_val = *it;
            position = i;
        }
    }
    cout<<position<<endl;
    position += 1;
    return position;
}

void k_means::assign_cluster(){
        
    cout<<"Cluster Assignment"<<endl;
    vector< vector<float> >::iterator row, crow;
    vector<float>::iterator col, ccol;
    vector<int>::iterator clus;
    float dist = 0, dif = 0, sq_val = 0, sum = 0;
    std::vector<float> distance;
    std::vector<int> cluster_no;
    std::vector<std::vector<float> > clusterMeans;
    int i = 0, k = 0;

    for (row = data.begin(); row != data.end(); row++) {
        for (crow = clusters.begin(); crow != clusters.end(); crow++) {
            sum = 0;
            for (col = row->begin(), ccol = crow->begin(); col != row->end(); col++,ccol++) {
                dif = *ccol - *col;
                sq_val = pow(dif,2);
                sum += sq_val;
            }
            dist = sqrt(sum); 
            cout<<"Calc Dist:"<<dist<<endl;
            distance.push_back(dist);
        }
        int p = get_minimum(distance);
        distance.clear();
        distance.shrink_to_fit();
        cluster_no.push_back(p);
    }
    
//    cout<<"Distance Calculated";
    
    cout<<"Cluster Numbers"<<endl;
    for (clus = cluster_no.begin(); clus != cluster_no.end(); clus++){
        cout<<*clus<<endl;
    }
    
    std::vector<float> sums(colCount);
    int same_row = 0;
    std::vector<float> means(colCount);
    for(int j =0; j < k_neighbors; j++){
        for (clus = cluster_no.begin(), k = 0; clus != cluster_no.end(); clus++, k++){
            if (*clus - 1 == j){ 
                same_row++;
                for (row = data.begin()+ k; row != data.begin()+ k + 1; row++) {
                    for (col = row->begin(), i =0; col != row->end(); col++, i++) {
                        sums[i] += *col;
                    }
                }
            }
            if(k == rowCount -1){
                for(int i = 0; i < colCount; i++){
                    if(same_row == 0){
                        means[i] = 0; //clusters[j][i];
                    } else {
                        cout<<"Sum Val:"<<sums[i]<<"\t"<<same_row<<endl;
                        means[i] = sums[i] / same_row;
                        cout<<means[i]<<endl;
                    }
                }
                same_row = 0;
                cout<<endl;
            }
        }
        clusterMeans.push_back(means);
        sums.shrink_to_fit();
        means.shrink_to_fit();
    }
    
    cout<<"New Cluster Mean:";
    for (int i = 0; i < k_neighbors; i++){
        for (int j = 0; j < colCount; j++){
            cout<<clusterMeans[i][j]<<"\t";
        }
    cout<<endl;
    }
    clusters = clusterMeans;
    
    cout<<"New Cluster:";
    for (int i = 0; i < k_neighbors; i++){
        for (int j = 0; j < colCount; j++){
            cout<<clusters[i][j]<<"\t";
        }
    cout<<endl;
    }
    
    cluster_no.clear();
    clusterMeans.clear();
    cluster_no.shrink_to_fit();
    clusterMeans.shrink_to_fit();
}

k_means::~k_means(){
    data.clear();
    clusters.clear();
    data.shrink_to_fit();
    clusters.shrink_to_fit();
}