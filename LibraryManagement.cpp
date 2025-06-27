#include <iostream>
#include <string>
class Book {
public:
  virtual void BookVariety() { std::cout << "Normal Book" << std::endl; }
  virtual double BookPrice(int lastday) = 0;
};
class AcadamicBook : public Book {
public:
  void BookVariety() {
    std::cout << "Acadamic Book" << '\n'
              << "Renew Period: 7 Days" << '\n'
              << "Fine: 3 Rs. After due date" << std::endl;
  }
  double BookPrice(int lastday) { return lastday * 3.0; }
};
class FictionBook : public Book {
public:
  void BookVariety() {
    std::cout << "Fiction Book" << '\n'
              << "Renew Period: 14 Days" << '\n'
              << "Fine: 4 Rs After due date" << std::endl;
  }
  double BookPrice(int lastday) { return lastday * 4.0; }
};
class Magazine : public Book {
public:
  void BookVariety() {
    std::cout << "Magazine" << '\n'
              << "Renew Period : 20 Days" << '\n'
              << "Fine: 2 Rs. After due date" << std::endl;
  }
  double BookPrice(int lastday) { return lastday * 2.0; }
};
class MysteryBook : public Book {
public:
  void BookVariety() {
    std::cout << "Mystery Book" << '\n'
              << "Renew Period : 18 Days" << '\n'
              << "Fine: 5 Rs. After due date" << std::endl;
  }
  double BookPrice(int lastday) { return lastday * 5.0; }
};
int main() {
  Book *bk;
  AcadamicBook ab;
  FictionBook fb;
  Magazine mg;
  MysteryBook msb;
  int choice, lastday;
  std::cout << "*************LIBRARY MANAGEMENT SYSTEM************"
            << std::endl;
  std::cout << "1. Acadamic Book" << std::endl;
  std::cout << "2. Fiction Book" << std::endl;
  std::cout << "3. Magazine" << std::endl;
  std::cout << "4. Mystery Book" << std::endl;

  std::cout << "Enter your Choice(1-4): ";
  std::cin >> choice;
  switch (choice) {
  case 1:
    bk = &ab;
    break;
  case 2:
    bk = &fb;
    break;
  case 3:
    bk = &mg;
    break;
  case 4:
    bk = &msb;
    break;
  }
  std::cout << "Enter your late days...." << std::endl;
  std::cin >> lastday;
  if (lastday < 0) {
    std::cout << "Invalid Date Entered Please Check!!" << std::endl;
  }
  bk->BookVariety();
  double fine = bk->BookPrice(lastday);
  std::cout << "The amount your fine is: " << fine << std::endl;

  std::cout << "**************************************************"
            << std::endl;
}
