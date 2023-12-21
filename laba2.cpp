#include <iostream>
#include <chrono>
using namespace std;
int binarySearch(int arr[], int value, int start, int end) {
    if (end >= start) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value) {
            return mid;
        }

        if (arr[mid] > value) {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}

void shell(int arr[], int size) {
    int step = size / 2;
    while (true){
        for (int i = 0; i < step; i++) {
            for (int j = i; j < size; j += step) {
                for (int tempj = j; tempj >= step; tempj -= step) {
                    if (arr[tempj] < arr[tempj - step]) {
                        swap(arr[tempj], arr[tempj - step]);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        if (step == 1) {
            break;
        }
        step /= 2;
    }
}


int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    constexpr int N = 100;
    int arr[N] = {};
    int choose = 0;
    int  maxnots, minnots, maxs, mins, a, b,k,k2,sum, Index1, Index2;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> durationTime = end - start;
    while (choose != -1) {
        cout << "\n\n\n�������� �������, ������� ������ ���������: \n"
            "1.������� ������������� ������ ����������� N = 100. �������� ������� ��������� ��������� �������� � ��������� �� -99 �� 99.\n"
            "2.������������� 1 ������ ����������� (�� �������� � ��������). ���������� �����,����������� �� ����������.\n"
            "3.����� ������������ � ����������� ������� �������. ���������� ����� ������ ���� ��������� � ��������������� � �����������������.\n"
            "4.������� ������� �������� ������������� � ������������ �������� � ��������������� � �����������������. ������� ������� ���� ��������� � �� ����������. ���������� ����� ������.\n"
            "5.������� ���������� ��������� � ��������������� �������, ������� ������ ����� a.\n"
            "6.������� ���������� ��������� � ��������������� �������, ������� ������ ����� b.\n"
            "7.������� ���������� � ���, ���� �� ��������� ������������� ����� � ��������������� �������.\n"
            "8.������ ������� �������� �������, ������� ������� ������ ������������. �������� �������� ������.\n"
            "9.���.\n\n\n";

        cout << "�������: ";
        cin >> choose;
        cout << "\n";

        if (choose != 1 and choose != 2 and choose != 3 and choose != 4 and choose != 5 and choose != 6 and choose != 7
            and choose != 8 and choose != 9)
            cout << "������ ������ ������� ��� \n";
        else
            int arr[N];
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 199 - 99;
        }
        switch (choose) {
        case 1:
            cout << '\n' << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                arr[i] = rand() % 199 - 99;
                cout << arr[i] << " ";
            }
            cout << '\n' << '\n';
            break;
        case 2:
  
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1 - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr1 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr1;
                    }
                }
            }
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n' << '\n' << "����������� �����: " << durationTime.count() << " ������" << '\n' << '\n';
            break;
        case 3:
            maxnots = arr[0];
            minnots = arr[0];
            start = chrono::high_resolution_clock::now();
            for (int i = 1; i < N; ++i) {
                if (arr[i] > maxnots) {
                    maxnots = arr[i];
                }
                if (arr[i] < minnots) {
                    minnots = arr[i];
                }
            }
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << '\n' << "����������������� ������: " << '\n' << '\n' << "����������� ��������: " \
                << minnots << '\n' << "������������ ��������: " << maxnots << '\n' \
                << "����� ������: " << durationTime.count() << " ������" << '\n';
            cout << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n' << '\n';
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr2 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr2;
                    }
                }
            }
            start = chrono::high_resolution_clock::now();
            maxs = arr[99];
            mins = arr[0];
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << "��������������� ������: " << '\n' << '\n' << "����������� ��������: " \
                << mins << '\n' << "������������ ��������: " << maxs << '\n' \
                << "����� ������: " << durationTime.count() << " ������" << '\n';
            cout << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n' << '\n';
            break;
        case 4:
            sum = 0;
            k = 0;
           
            maxnots = arr[0];
            minnots = arr[0];
            for (int i = 0; i < N; ++i) {
                if (arr[i] > maxnots) {
                    maxnots = arr[i];
                }
                if (arr[i] < minnots) {
                    minnots = arr[i];
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr3 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr3;
                    }
                }
            }
            sum = ((maxnots + minnots) / 2);
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n' << "������� ��������: " << sum << '\n';
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                if (arr[i] == sum) {
                    k += 1;
                    cout << "������ �������� ������ �������� ��������: " << i << endl;

                }
            }
            if (k == 0) {
                cout << "����� ������� ���" << endl;
            }
            else
                cout << "����������: " << k;

                
            
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << "����������� �����: " << durationTime.count() << " ������" << '\n' << '\n';
            break;

        case 5:
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr4 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr4;
                    }
                }
            }
            cout << '\n' << "������� �����: ";
            cin >> a;
            k = 0;
            while (arr[k] < a) {
                k += 1;
            }
            cout << '\n' << "���������� ���������: " << k << '\n' << '\n';
            break;
        case 6:
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr4 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr4;
                    }
                }
            }
            cout << '\n' << "������� �����: ";
            cin >> b;
            k2 = 99;
            while (arr[k2] > b) {
                k2 -= 1;
            }
            cout << "���������� ���������: " << 99 - k2 << '\n' << '\n';
            break;
        case 7: {
            int choice = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1 - i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr1 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr1;
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n';
            cin >> choice;
            cout << '\n';


            
            start = chrono::high_resolution_clock::now();
            int is_in_array = binarySearch(arr, choice, 0, N);
            end = chrono::high_resolution_clock::now();
          
            cout << '\n' << "����������� �����: " << durationTime.count() << " ������" << '\n' << '\n';

           
            const auto start1 = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                if (choice == arr[i] || i == N - 1)
                {
                    const auto end1 = chrono::high_resolution_clock::now();
                    const std::chrono::duration<float> durationTime1 = end1 - start1;
                    cout << '\n' << "����������� �����1: " << durationTime1.count() << " ������" << '\n' << '\n';
                    break;
                }
            }
            if (is_in_array != -1)
                cout << "��������� � �������\n";
            else
                cout << "�� ��������� � �������\n";
            break;
        }
        case 8:
            cout << '\n' << "������� ������ ������: ";
            cin >> Index1;
            cout << '\n' << "������� ������ ������: ";
            cin >> Index2;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int arr4 = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = arr4;
                    }
                }
            }
            start = chrono::high_resolution_clock::now();
            swap(arr[Index1], arr[Index2]);
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << '\n' << "����������� �����: " << durationTime.count() << " ������" << '\n';
            cout << '\n' << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n';
            break;
        case 9:
            int tempArr[N];
            for (int i = 0; i < N; i++) {
                tempArr[i] = arr[i];
            }
            cout << "���� ����\n";
            start = chrono::high_resolution_clock::now();
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N - 1 - i; j++) {
                    if (tempArr[j] > tempArr[j + 1]) {
                        int arr1 = tempArr[j];
                        tempArr[j] = tempArr[j + 1];
                        tempArr[j + 1] = arr1;
                    }
                }
            }
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << tempArr[i] << " ";
            }
            cout << '\n' << '\n' << "����������� �����: " << durationTime.count() << " ������" << '\n' << '\n';
        

            cout << "���� ����\n";
            for (int i = 0; i < N; i++) {
                tempArr[i] = arr[i];
            }
            start = chrono::high_resolution_clock::now();
            shell(tempArr, N);
            end = chrono::high_resolution_clock::now();
            durationTime = end - start;
            cout << "���������� ������: ";
            for (int i = 0; i < N; i++) {
                cout << tempArr[i] << " ";
            }
            cout << '\n' << '\n' << "����������� �����: " << durationTime.count() << " ������" << '\n' << '\n';
            break;
        }
    }
  
}