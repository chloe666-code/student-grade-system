#include <iostream>
#include <string>
using namespace std;
class Student{
  protected:
    string name;
    int id;
    double grades[3];
  public:
    Student(){
      name=" ";
      id=0;
      grades[0]=0;
      grades[1]=0;
      grades[2]=0;
    };
    void setName(string n){
      name=n;
    } 
    void setId(int stu_id){
      id=stu_id;
    }
    void setGrade(double stu_grades[]){
      grades[0]=stu_grades[0];
      grades[1]=stu_grades[1];
      grades[2]=stu_grades[2];
    }

    string getName(){
      return name;
    }
    int getId(){
      return id;
    }
    double *getGrades(){
      return grades;
    }

    virtual void print()=0;

    bool sameName(Student *student){
      if(student->getName()==name){
        return true;
      }
      else
        return false;
    }
};

class UndergradStudent:public Student{
  public:
    UndergradStudent(){
      name=" ";
       id=0;
      grades[0]=0;
      grades[1]=0;
      grades[2]=0;
    }
    UndergradStudent(string n,int stu_id,double stu_grades[]){
      name=n;
      id=stu_id;
      grades[0]=stu_grades[0];
      grades[1]=stu_grades[1];
      grades[2]=stu_grades[2];
    }

    //print method
    void print(){
      cout<<"\nThis is an Undergraduate Student."<<endl;
      cout<<"Student name : "<<name<<endl;
      cout<<"Student ID : "<<id<<endl;
      cout<<"Student Grades : "<<grades[0]<<' '<<grades[1]<<' '<<grades[2]<<endl;
    }
};
class GradStudent:public Student{
  public:
    GradStudent(){
      name=" ";
       id=0;
      grades[0]=0;
      grades[1]=0;
      grades[2]=0;
    }
    GradStudent(string n,int stu_id,double stu_grades[]){
      name=n;
      id=stu_id;
      grades[0]=stu_grades[0];
      grades[1]=stu_grades[1];
      grades[2]=stu_grades[2];
    }

    //print method
    void print(){
      cout<<"\nThis is an Graduate Student."<<endl;
      cout<<"Student name : "<<name<<endl;
      cout<<"Student ID : "<<id<<endl;
      cout<<"Student Grades : "<<grades[0]<<' '<<grades[1]<<' '<<grades[2]<<endl;
    }
};
int main() {
  UndergradStudent u1;
  double grades1[3]={100,99,98};
  GradStudent g1("Yizhe",461048535,grades1);
  cout<<"Default Name : "<<u1.getName()<<endl;
  cout<<"Default ID : "<<u1.getId()<<endl;
  cout<<"Default Grades : "<<u1.getGrades()[0]<<' '<<u1.getGrades()[1]<<' '<<u1.getGrades()[2]<<endl;

  cout<<"\n";

  double grade2[3]={100,98,96};
  u1.setName("Amliy");
  u1.setId(283918293);
  u1.setGrade(grade2);

  cout<<"Undergraduate Student Name : "<<u1.getName()<<endl;
  cout<<"Undergraduate Student ID : "<<u1.getId()<<endl;
  cout<<"Undergraduate Student Grades : "<<u1.getGrades()[0]<<' '<<u1.getGrades()[1]<<' '<<u1.getGrades()[2]<<endl;

  cout<<"\n";

  cout<<"Graduate Student Name : "<<g1.getName()<<endl;
  cout<<"Graduate Student ID : "<<g1.getId()<<endl;
  cout<<"Graduate Student Grades :  "<<g1.getGrades()[0]<<' '<<g1.getGrades()[1]<<' '<<g1.getGrades()[2]<<endl;

  cout<<"\n";

Student *gradStudent=&g1;

if (u1.sameName(gradStudent)){
  cout<<"The name is same which are"<<u1.getName()<<" and "<< gradStudent->getName();
}
else
  cout<<"The name is not same, the name for undergraduate student is "<<u1.getName()<<". The name for Graduate Student is "<<gradStudent->getName();

cout<<"\n";

u1.print();
g1.print();
gradStudent->print();

return 0;
}