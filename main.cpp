#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class Person {
private:
  string name;
  int age;
  string id;
  string contact_detail;
  string gender;

public:
  Person();
  Person(string name, int age, string id, string contact_detail, string gender);
  string getName();
  void setName(string name);
  int getAge();
  void setAge(int age);
  string getId();
  void setid(string id);
  string getContact_detail();
  void setContact_detail(string contact_detaildetail);
  string getGender();
  void setGender(string gender);
  virtual void enterInfor() = 0;
  virtual void display() = 0;
};

Person ::Person() {
  name = "";
  age = 0;
  id = "";
  contact_detail = "";
  gender = "";
}

Person ::Person(string name, int age, string id, string contact_detail,
                string gender) {
  this->name = name;
  this->age = age;
  this->id = id;
  this->contact_detail = contact_detail;
  this->gender = gender;
}

string Person::getName() { return name; }

void Person ::setName(string name) { this->name = name; }

int Person ::getAge() { return age; }

void Person ::setAge(int age) { this->age = age; }

string Person ::getId() { return id; }

void Person ::setid(string id) { this->id = id; }

string Person ::getContact_detail() { return contact_detail; }

void Person ::setContact_detail(string contact_detail) {
  this->contact_detail = contact_detail;
}

string Person ::getGender() { return gender; }

void Person ::setGender(string gender) { this->gender = gender; }

void Person ::enterInfor() {
  cout << " enter name: ";
  getline(cin, name);
  cout << "enter age: ";
  cin >> age;
  cout << "enter ID: ";
  cin.ignore();
  getline(cin, id);
  cout << "enter contact_detail: ";
  getline(cin, contact_detail);
  cout << "enter gender: ";
  getline(cin, gender);
}

void Person ::display() {
  cout << "name: " << name << endl;
  cout << "age: " << age << endl;
  cout << "id: " << id << endl;
  cout << "contact detail:" << contact_detail << endl;
  cout << "gender: " << gender << endl;
}

class Student : public Person {
private:
  string grade;
  string subject;
  double score;

public:
  Student();
  Student(string name, int age, string id, string contact_detail, string gender,
          string grade, string subject, double score);
  string getGrade();
  void setGrade(string grade);
  string getSubject();
  void setSubject(string subject);
  double getScore();
  void setScore(double score);
  virtual void enterInfor() override;
  void checkScore();

  virtual void display() override;
};

Student ::Student() {
  grade = "";
  subject = "";
  score = 0.0;
}
Student ::Student(string name, int age, string id, string contact_detail,
                  string gender, string grade, string subject, double score)
    : Person(name, age, id, contact_detail, gender) {
  this->grade = grade;
  this->subject = subject;
  this->score = score;
}
string Student ::getGrade() { return grade; }

void Student ::setGrade(string grade) { this->grade = grade; }

string Student ::getSubject() { return subject; }

void Student ::setSubject(string subject) { this->subject = subject; }

double Student ::getScore() { return score; }

void Student ::setScore(double score) { this->score = score; }

void Student ::enterInfor() {
  Person ::enterInfor();
  cout << "enter grade:";
  getline(cin, grade);
  cout << "enter subject: ";
  getline(cin, subject);
  cout << "enet your score:";
  cin >> score;
}

void Student ::display() {
  Person ::display();
  cout << "grade: " << grade << endl;
  cout << "subject: " << subject << endl;
}
void Student ::checkScore() {
  if (score < 0 || score > 10) {
    cout << "enter again your score" << endl;
  } else if (score >= 5) {
    cout << "you pass" << endl;
  } else if (score < 5) {
    cout << " you not pass";
  }
}
int main() {

  Student s;
  s.enterInfor();
  s.checkScore();
  cout << "======== display============" << endl;
  cout << "                            " << endl;
  s.display();
}