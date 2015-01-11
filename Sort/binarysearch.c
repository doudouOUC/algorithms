/*************************************************************************
    > File Name: binarysearch.c
    > Author: jinye
    > Mail: jinye.djy@alibaba-inc.com
    > Created Time: Sun 11 Jan 2015 03:24:50 PM CST
 ************************************************************************/

#include <stdio.h>

int binarysearch(int sort[], int n, int value){
    int low = 0;
    int high = n-1;
    int middle = 0;
    while(low <= high){
        middle = (low+high)/2;
        if(sort[middle] < value){
            low = middle+1;
        }
        else if(sort[middle] > value){
            high = middle-1;
        }
        else if(sort[middle] == value){
            return middle;
        }
    }
    return -1;
}


int main(){
    int sort[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans1, ans2, ans3, ans4, ans5;
    ans1 = binarysearch(sort, 9, 6);
    ans2 = binarysearch(sort, 9, 1);
    ans3 = binarysearch(sort, 9, 9);
    ans4 = binarysearch(sort, 9, 0);
    ans5 = binarysearch(sort, 9, 10);
    fprintf(stdout, "%d %d %d %d %d\n", ans1, ans2, ans3, ans4, ans5);
    return 0;
}
