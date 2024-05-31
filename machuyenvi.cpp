#include <iostream>
#include <string>
#include <limits>

using namespace std;
string rm_Spaces(const string& input) {
    string result;
    for (char c : input) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}
string encrypt_Scytale(const string& chuoi, int a) {
    string result=rm_Spaces(chuoi);
    int n = result.length();
    int socot = (n + a - 1) / a;
    int space=a*socot-n;
    char** arr = new char*[a];
    for (int i = 0; i < a; i++) {
        arr[i] = new char[socot];
    }

    int chiso = 0;
    if(n==a*socot){ 
        for (int i = 0; i < a; i++) {
        for (int j = 0; j < socot; j++) {
                arr[i][j] = result[chiso];
                chiso++;
        }
    }
    }

    else {
    for (int i = 0; i < a-space; i++) {
        for (int j = 0; j < socot; j++) {
            if (chiso < n) {
                arr[i][j] = result[chiso];
                chiso++;
            }
        }
    }
    for(int i=a-space;i<a;i++){
        for(int j=0;j<socot-1;j++){
            arr[i][j]=result[chiso];
            chiso++;
        }
        arr[i][socot-1]='@';
    }
    }

    string mahoa;
    for (int j = 0; j < socot; j++) {
        for (int i = 0; i < a; i++) {
            mahoa += arr[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    string Mahoa=rm_Spaces(mahoa);
    return Mahoa;
}
string decrypt_Scytale(const string& chuoi, int a){
  int n = chuoi.length();
      int socot = (n + a - 1) / a;
      char* b = new char[a*socot];
      char** arr = new char*[a];
      for (int i = 0; i < a; i++) {
          arr[i] = new char[socot];
      }
      int chiso = 0;
      for (int j = 0; j < socot; j++) {
          for (int i = 0; i < a; i++) {
              if (chiso < n) {
                  arr[i][j] = chuoi[chiso];
                  chiso++;
              }
          }
      }

      string giaiMa;
      for (int i = 0; i < a; i++) {
          for (int j = 0; j < socot; j++) {
              giaiMa += arr[i][j];
          }
      }

      for (int i = 0; i < a; i++) {
          delete[] arr[i];
      }
      delete[] arr;

      return giaiMa;
}
int enter_key() {
  int num;
  cout << "Enter key: ";
  while (true) {
      cin >> num;
      if (cin.fail() || num <= 0) {
          cin.clear(); // Xóa cờ lỗi
          cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bỏ qua các ký tự còn lại trong buffer
          cout << "Invalid value. Please try again. ";
      } else {
          return num; // Trả về số nguyên dương hợp lệ
      }
  }
}

string enter_text() {
  string input;
  cout << "Enter text: ";
  getline(cin,input);
  return input;
}
int main(){
  cout << "____SCYTALE CIPHER______" << endl;
  cout << "|  1. ECRYPT               |" << endl;
  cout << "|  2. DECRYPTION           |" << endl;
  cout << "!__________________________!" << endl;
  cout << "SELECT OPTION: ";
  int option;
  while (true){
  cin >> option;
  cin.ignore(); 
    if (option == 1 || option == 2) {
      break;
    } else {
      cout << "Invalid selection. Please choose again (choose 1 or 2)." << endl;
    }
  }
  if (option == 1) {
      string plaintext = enter_text();
      int rows = enter_key();
      string encryptedText = encrypt_Scytale(plaintext, rows);
      cout << "Text after encoding: " << encryptedText << endl;
  } else if (option == 2) {
      string ciphertext = enter_text();
      int rows = enter_key();
      string decryptedText = decrypt_Scytale(ciphertext, rows);
      cout << "Text after decoding: " << decryptedText << endl;
  }
  return 0;
}
