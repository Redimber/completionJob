//
//  main.cpp
//  minimizingTheWeightedSum
//
//  Created by Ibrahim El Mountasser on 8/15/19.
//  Copyright © 2019 Ibrahim El Mountasser. All rights reserved.
//
//In this programming problem and the next you'll code up the greedy algorithms from lecture
//for minimizing the weighted sum of completion times.. Download the text file here.
//This file describes a set of jobs with positive and integral weights and lengths. It has the format
//[number_of_jobs]
//[job_1_weight] [job_1_length]
//[job_2_weight] [job_2_length]
//...
//For example, the third line of the file is "74 59", indicating that the second job has weight 74 and length 59.
//You should NOT assume that edge weights or lengths are distinct.
//Your task in this problem is to run the greedy algorithm that schedules jobs in
//decreasing order of the difference (weight - length). Recall from lecture that this algorithm
//is not always optimal. IMPORTANT: if two jobs have equal difference (weight - length),
//you should schedule the job with higher weight first. Beware: if you break ties in a different way,
//you are likely to get the wrong answer. You should report the sum of weighted completion times
//of the resulting schedule --- a positive integer --- in the box below.
#include <iostream>
#include <vector>
#include <fstream>
struct Node {
    int diff;
    int w;
    int l;
};
bool nodeSorter(Node const& lhs, Node const& rhs) {
    if (lhs.diff == rhs.diff)
        return lhs.w > rhs.w;
    return lhs.diff > rhs.diff;
}
std::vector<Node> getDifferenceFromFile(std::string file) {
    std::vector<Node> vector;
    std::ifstream infile(file);
    int a, b;
    while (infile >> a >> b) {
        Node node;
        node.diff = a - b;
        node.w = a;
        node.l = b;
        vector.push_back(node);
    }
    
    std::sort(vector.begin(), vector.end(), nodeSorter);
    return vector;
}

int main(int argc, const char * argv[]) {
    std::vector<Node> vec = getDifferenceFromFile("jobs.txt");
    unsigned long completionTime = 0;
    unsigned long result = 0;

    
    for (Node node : vec) {
        std::cout<<node.diff<<" "<<node.w<<" "<<node.l<<"\n";
        completionTime += node.l;
        result += node.w * completionTime;
    }
    
    std::cout<<result;
    return 0;
}

