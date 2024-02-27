

int* game_with_number(int arr[], int n)
{
    int prev = 0;
    for(int i = n-1; i >= 0; i--) {
        int temp = arr[i];
        arr[i] = arr[i] | prev;
        prev = temp;
    }
    
    return arr;
}
