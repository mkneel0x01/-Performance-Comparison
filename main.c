#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//linear search function

int linearSearch(int arr[], int n, int key){
    for(int i=0; i < n; i++){
        if(arr[0]==key){
            return 0;
        }
    }
    return -1;
}

//Binary search function

int binarySearch(int arr[], int low,int high, int key){
    while(low < high){
        int mid = low + (high - low)/2;
        if (arr[mid]==key){
            return mid;
        }else if (arr[mid] < key){
            low = mid + 1; 
        }else {
            high = mid -1;
        }
    }
    return -1;
}

int main(){
    File * file;
    int n, key;
    clock_t start,end;
    double linear_time,binary_time;
    
    //open file for reading
    file = topen("input.txt","r");
    if (file == NULL){
        printf("Error opening file.\n");
        return 1;
    }
    
    // Read number of elements
    fscanf(file,"%d",&n);
    
    //Dynamically allocate memory for array
    int arr=(int)malloc(n*sizeof(int j));
    if (arr == NULL ){
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    //Read array element
    for (int i = 0; i < n; i++){
        fscanf(file,"%d",&arr[i]);
    }
    
    //Read key to be searched
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    // Perform linear search
    start = clock();
    int linear_result = linearSearch(arr, n, key);
    end = clock();
    linear_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Perform Binary search
    start = clock();
    int binary_result = binarySearch(arr, 0, n-1, key);
    end = clock();
    binary_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Display results and comparison
    printf("\n");
    if(linear_result != -1){
        printf("Linear search: Element found at index %d\n",linear_result);
        } else {
            printf("Linear search: Element not found\n");
        }
        printf("Time taken for linear search: %f seconds\n", linear_time);
        
        if(binary_result != -1){
        printf("Binary search: Element found at index %d\n",binary_result);
        } else {
            printf("Binary search: Element not found\n");
        }
        printf("Time taken for Binary search: %f seconds\n", binary_time);
        
        // Determine efficiency
        printf("\n");
        if(linear_time < binary_time){
            printf("Linear search is more efficient.\n");
        }else if (linear_time > binary_time){
            printf("Binary search is more efficient.\n");
        }else {
            printf("Both search algorithm have similar efficient.\n");
        }
        
        //free dynamically allocated memory
        free(arr);
        
        // close the file
        fclose(file);
        
        return 0;
}
