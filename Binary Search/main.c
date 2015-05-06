//
//  main.c
//  Binary Search
//
//  Created by Jeremy Petter on 2015-05-05.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>

typedef struct Range Range;

struct Range {
    int firstInstance;
    int numberOfInstances;
};

Range binarySearch(int numbers[], int target, int min, int max);


int main(int argc, const char * argv[]) {
    
    int testNumbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9, 9, 10, 11, 12, 13, 15, 16};
    int testLength = sizeof(testNumbers)/sizeof(testNumbers[0]);
    int testTarget = 20;
    
    Range final = binarySearch(testNumbers, testTarget, 0, testLength-1);
    printf("the target starts at index %d and goes for %d index(es).", final.firstInstance, final.numberOfInstances);
    
    return 1;
}

Range binarySearch(int numbers[], int target, int min, int max){
    
    /* set query value to half of the array length */
    int query = (max + min)/2;
    
    if (min > max){
        Range failure;
        failure.firstInstance = -1;
        failure.numberOfInstances = 0;
        return failure;
    }
    

    /* If query is too big, set the minimum to the current query to
     reduce the range of the search */
    if (numbers[query] > target)
    {
        return binarySearch(numbers, target, min, --query);
    }
    
    /* If query is too small, set the maximum to the current query to
     reduce the range of the search */
    else if (numbers[query] < target)
    {
        return binarySearch(numbers, target, ++query, max);
    }
    else
    {
        //printf("Number is at index %d, and is %d", query, numbers[query]);
        int firstInstance = query;
        int numberOfInstances = 0;
        
        /* navigate backwards through the array to find the first 
         index that matches the target number */
        for (int i = query; numbers[i] == numbers[query]; i--){
            firstInstance = i;
        }
        
        /* navigate forward from the first index that matches our array
         to determine the total number of indexes that match that value */
        for (int i = firstInstance; numbers[i] == numbers[query]; i++){
            numberOfInstances++;
        }
        
        Range solution;
        solution.firstInstance = firstInstance;
        solution.numberOfInstances = numberOfInstances;
        
        return solution;
        
    }
}
