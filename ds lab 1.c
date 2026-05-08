#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100], n, i, pos, value, choice, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {

        printf("\n--- MENU ---\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Searching\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:

                printf("Array elements are:\n");

                for(i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }

                printf("\n");
                break;

            case 2:

                printf("Enter position and value: ");
                scanf("%d %d", &pos, &value);

                for(i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 3:

                printf("Enter position to delete: ");
                scanf("%d", &pos);

                for(i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 4:

                printf("Enter element to search: ");
                scanf("%d", &value);

                found = 0;

                for(i = 0; i < n; i++) {

                    if(arr[i] == value) {

                        printf("Element found at position %d\n", i + 1);

                        found = 1;
                        break;
                    }
                }

                if(found == 0) {
                    printf("Element not found\n");
                }

                break;

            case 5:

                printf("Exiting...\n");
                break;

            default:

                printf("Invalid choice\n");
        }

    } while(choice != 5);

    return 0;
}
