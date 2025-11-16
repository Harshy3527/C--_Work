#include <stdio.h>
#include <math.h>
int fact(int num) {
  int pr = 1;
  for (int j = 1; j <= num; j++) pr *= j;
  return pr;
}

void prog41() {
  int num, base, i = 0;
  printf("Enter the number and the base to convert it to : ");
  scanf("%d %d", &num, &base);
  int copy = num;
  int res[32];
  while (copy > 0) {
    res[i++] = copy % base;
    copy /= base;
  }
  printf("%d in base %d = ", num, base);
  for (int j = i - 1; j >= 0; j--) {
    if (res[j] >= 10)
      printf("%c", (char)(res[j] - 10 + 'A'));
    else
      printf("%d", res[j]);
  }
  printf("\n");
}

void prog42() {
  int n;
  printf("Enter the number : ");
  scanf("%d", &n);
  for (int i = 1; i <= 100; i++) {
    if (i % n == 3) printf("%d ", i);
  }
  printf("\n");
}

void prog43() {
  printf("Enter choice 1-5: ");
  int choice;
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) printf("* ");
        printf("\n");
      }
      break;

    case 2:
      for (int i = 1; i <= 5; i++) {
        for (int j = 5; j >= 1; j--) printf("* ");
        printf("\n");
      }
      break;

    case 3:
      for (int i = 1; i <= 5; i++) {
        for (int j = 5 - i; j >= 1; j--) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("*");
        printf("\n");
      }
      break;

    case 4:
      for (int i = 1, k = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++, k++) printf("%d", (k % 2 == 1) ? 1 : 0);
        printf("\n");
      }
      break;

    case 5:
      for (int i = 1; i <= 5; i++) {
        for (int j = 5 - i; j >= 1; j--) printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++) printf("%d", i);
        printf("\n");
      }
      break;
  }
}

void prog44() {
  for (int i = 0; i < 6; i++) {
    for (int j = 5 - i; j >= 1; j--) printf(" ");
    for (int j = 0; j <= i; j++) {
      printf(" %d ", fact(i) / (fact(j) * fact(i - j)));
    }
    printf("\n");
  }
}

void prog45() {
  int a[] = {1, 2, 3, 4, 5};
  for (int i = 4; i >= 0; i--) printf(" %d ", a[i]);
  printf("\n");
}

void prog46() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", &n);
  int a[n];
  printf("Enter the elements : ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int max = a[0], min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] > max) max = a[i];
    if (a[i] < min) min = a[i];
  }
  printf("Max = %d\nMin = %d\n", max, min);
}

void prog47() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", &n);
  int a[n], b[n];
  printf("Enter the elements of array 1: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printf("Enter the elements of array 2: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    int temp = a[i];
    a[i] = b[i];
    b[i] = temp;
  }
  printf("Array 1 : ");
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\nArray 2 : ");
  for (int i = 0; i < n; i++) printf("%d ", b[i]);
  printf("\n");
}

void prog48() {
  int n, i;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter %d integers:\n", n);
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  double sum = 0.0;
  for (i = 0; i < n; i++) sum += arr[i];
  double mean = sum / n;

  double variance_sum = 0.0;
  for (i = 0; i < n; i++) {
    variance_sum += pow(arr[i] - mean, 2);
  }
  double std_dev = sqrt(variance_sum / n);  

  printf("\nAverage (Mean) = %.2lf\n", mean);
  printf("Standard Deviation = %.2lf\n", std_dev);
}

void prog49() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // bubble sort descending
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] < arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("Sorted Array (descending): ");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\nEnter the key to search : ");
  int key;
  scanf("%d", &key);
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      printf("%d found at index %d\n", key, i);
      return;
    }
  }
  printf("Key not found.\n");
}

void prog410() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", &n);
  int arr[n + 1];
  printf("Enter the elements of array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the index and the element to be inserted : ");
  int index, num;
  scanf("%d %d", &index, &num);
  for (int i = n; i > index; i--) {
    arr[i] = arr[i - 1];
  }
  arr[index] = num;
  printf("New Array: ");
  for (int i = 0; i <= n; i++) printf("%d ", arr[i]);
  printf("\n");
}

void prog411() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements of array: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  printf("Enter the index to be deleted : ");
  int index;
  scanf("%d", &index);
  for (int i = index; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
  printf("New Array: ");
  for (int i = 0; i < n - 1; i++) printf("%d ", arr[i]);
  printf("\n");
}

void prog412() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("Enter the index to be shifted : ");
  int index;
  scanf("%d", &index);
  for (int i = index - 1; i < 9; i++) {
    a[i] = a[i + 1];
  }
  a[9] = 0;
  printf("New Array :- \n");
  for (int i = 0; i < 10; i++) printf("%d ", a[i]);
  printf("\n");
}

void prog413() {
  printf("Enter the number of elements : ");
  int n;
  scanf("%d", &n);
  int arr[n];
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i < n; i++) {
    arr[i] = arr[i - 2] + arr[i - 1];
  }
  printf("Fibonacci Series :- \n");
  for (int i = 0; i < n; i++) printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  // Uncomment the program you want to run
  // prog41();
  // prog42();
  // prog43();
  // prog44();
  // prog45();
  // prog46();
  // prog47();
  prog48();
  // prog49();
  // prog410();
  // prog411();
  // prog412();
  // prog413();
  return 0;
}
// #include <stdio.h>

// int main() {
//     int n, i;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);

//     int arr[n];
//     printf("Enter %d integers:\n", n);
//     for (i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }

//     // Store the first element
//     int first = arr[0];

//     // Shift elements one position to the left
//     for (i = 0; i < n - 1; i++) {
//         arr[i] = arr[i + 1];
//     }

//     // Move the first element to the last position (optional)
//     arr[n - 1] = first;

//     printf("\nArray after shifting one position to the left:\n");
//     for (i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     printf("\n");
//     return 0;
// }
