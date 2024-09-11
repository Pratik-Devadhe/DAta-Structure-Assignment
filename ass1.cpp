#include <iostream>
using namespace std;

int firstpos = -1, lastpos = -1;

int search(int arr[], int target, int size) {
    int count = 0;
    firstpos = -1;
    lastpos = -1;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
            if (firstpos == -1) {
                firstpos = i;
            }
            lastpos = i;
        }
    }

    return count > 0 ? count : -1; // Return count if found, otherwise -1
}

int main() {
    int size = 0;
    int target;
    int *arr = nullptr; // Use dynamic allocation
    
    int ch, choice;

    do {
        cout << "Which operation do you want to perform:" << endl;
        cout << "1. Add new array" << endl;
        cout << "2. Search number of times target value occurs in the array" << endl;
        cout << "3. Search first and last occurrence of target" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter the choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                // Allocate memory for the array
                if (arr != nullptr) {
                    delete[] arr; // Free any previously allocated memory
                }
                
                cout << "Enter the number of elements in array: ";
                cin >> size;

                if (size <= 0) {
                    cout << "Size must be greater than 0." << endl;
                    break;
                }

                arr = new int[size];
                
                cout << "Enter the array elements:" << endl;
                for (int i = 0; i < size; i++) {
                    cin >> arr[i];
                }

                cout << "Enter the target value: ";
                cin >> target;
                break;

            case 2:
                if (arr == nullptr) {
                    cout << "Array is not initialized." << endl;
                    break;
                }

                int count;
                count = search(arr, target, size);

                if (count != -1) {
                    cout << "Total number of times the element found: " << count << endl;
                } else {
                    cout << "Element is not present in the given array." << endl;
                }
                break;

            case 3:
                if (arr == nullptr) {
                    cout << "Array is not initialized." << endl;
                    break;
                }

                search(arr, target, size);
                
                if (firstpos != -1) {
                    cout << "First occurrence is at position: " << firstpos << endl;
                    cout << "Last occurrence is at position: " << lastpos << endl;
                } else {
                    cout << "Element is not present in the given array." << endl;
                }
                break;

            case 4:
                break;

            default:
                cout << "Wrong choice, please choose again." << endl;
                break;
        }

        cout << "Do you want to continue (1/0)? ";
        cin >> choice;

    } while (choice == 1);

    // Clean up memory
    if (arr != nullptr) {
        delete[] arr;
    }

    return 0;
}

