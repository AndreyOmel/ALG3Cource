#include <iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;
void bubble(std::vector<int>& arr, size_t size) {
    int temp; 

    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }  
}
void insertSort(std::vector<int>& arr, size_t size) {
    int x=arr[0];
    size_t j;

    for (size_t i = 0; i < size; i++) {
        x = arr[i];

        for (j = i - 1; j >= 0 && arr[j] > x; j--)
            arr[j + 1] = arr[j];  	
        arr[j + 1] = x;
    }
   
}

int halfing(std::vector<int>& arr, int low, int high) {
    int opor = arr[high];
    size_t i = low - 1;

    for (size_t j = low; j < high; j++) {
        if (arr[j] < opor) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int op = halfing(arr, low, high);       
        quickSort(arr, low, op - 1);
        quickSort(arr, op + 1, high);
    }
}
int main()
{

    size_t size = 10000;
    srand(time(0));
    std::vector<int> arr ;
    for (size_t i = 0; i < size; i++) {
        arr.push_back( rand() % 10000);
    }
    //quickSort(arr, 0, size - 1);
    //bubble(arr, size);
    insertSort(arr, size);

    for (size_t i = 0; i < size-1; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    
   
}