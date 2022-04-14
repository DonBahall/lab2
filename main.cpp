#include <iostream>
#include <string>

using namespace std;
enum SubjectName {OOP,Fisics,English,Chemistry};
enum SubjectNumSem{first,second};

struct Subject{
    SubjectName name;
    SubjectNumSem numSem;
    int time;
    int lec_time;
    int prac_time;
};
ostream& operator <<(ostream& out,  Subject& subject);
istream& operator >>(istream& in, Subject& subject);

struct Facult{
    string name_f;
    string name_un;
};
ostream& operator <<(ostream& out, const Facult& facult);
istream& operator >>(istream& in, Facult& facult);
class Specialiry {
private:
    string nameS;
    Facult facult;
    string specialisation;
    Subject* subject;

public:
    int n = 0;
    Specialiry();
    Specialiry(const Specialiry& specialiry);
    Specialiry(const string&  name_,const Facult&  facult1);
    ~Specialiry();
    const string &getName() const;

    const Facult &getfacult() const;

    int getNumberOfSubj() const;

    void outputSubj(ostream &out) const;

    void setName(const string &name_);
    void setSpecialization(const string& specializations);
    void setFacult(const Facult &facult1);

    void setNumberOfSubj(int nSubj);

    void showInfoFacult(ostream &out) const;
    void showInfoSpecialization(ostream& out) const;

    void showGeneralTime(ostream &out);

    Specialiry &operator =(const Specialiry& specialiry);
    Specialiry& operator +=(const Subject& subject1);
    bool operator < (const Specialiry& arg2) const;
     explicit operator int() const;
    bool addSubj(const Subject &subject1);
    const string& getSpecialization() const {return specialisation;}
    bool isExistSubject(SubjectName name_, SubjectNumSem num_sem,int time, int lec_time,
                        int prac_time) const;
    bool deleteSubject(SubjectName Name_, SubjectNumSem num_sem ,int time, int lec_time, int prac_time);
};
ostream& operator <<(ostream& out, const Specialiry& specialiry);
istream& operator >>(istream& in, Specialiry& specialiry);
SubjectName input_name(istream& in){
    string name;
    in >> name;
    if(name=="OOP"){
        return OOP;
    }
    if(name=="Fisics"){
        return Fisics;
    }
    if(name=="English"){
        return English;
    }
    return Chemistry;
}
SubjectNumSem input_num_sem(istream& in){
    string num_sem;
    in>>num_sem;
    if(num_sem=="first"){
        return first;
    }else{
        return second;
    }

}
int main() {
Specialiry specialiry;
cin>>specialiry;
cout<<specialiry<<endl;
    cout << endl << endl;
    cout << "==========================" << endl;
    specialiry.showInfoFacult(cout) ;
    cout << "==========================" << endl;
    specialiry.showInfoSpecialization(cout);
    cout << "==========================" << endl;
    cout <<"Show total number of hours";
    specialiry.showGeneralTime(cout);

    cout << "Chouse a subject need to delete" <<endl;
    int a,b,c;
    SubjectName d;
    SubjectNumSem e;
    cout << "write a subject name";
    d=input_name(cin);
    cout << "write a semester";
    e=input_num_sem(cin);
    cout << "write a general time";
    cin>>a;
    cout << "write a lecture time";
    cin>>b;
    cout << "write a prac time";
    cin>>c;
    specialiry.deleteSubject(d,e,a,b,c);
    cout<<specialiry<<endl;
   // specialiry.showInfoAboutSubject(input_name(cin));

}
ostream& operator <<(ostream& out, const Facult& facult) {
    out << "\t" << facult.name_f
        << "\t "<< facult.name_un;
    return out;
}
istream& operator >>(istream& in, Facult& facult){
    cout << "Input the name of facult";
    getline(in,facult.name_f);
    cout << "Input the name of universiry";
    getline(in,facult.name_un);
    return in;
}
Specialiry::Specialiry() :nameS("KN"), facult(),n(0),specialisation("It"), subject(nullptr){}
Specialiry::Specialiry(const Specialiry &specialiry) {
    nameS=specialiry.nameS;
    facult=specialiry.facult;
    n=specialiry.n;
    specialisation=specialiry.specialisation;
    subject=new Subject[n];
    for(int i = 0; i < n; i++){
        subject[i]=specialiry.subject[i];
    }
}
Specialiry::Specialiry(const string& name_,const Facult& facult1) :nameS(name_), facult(facult1),n(0),subject(nullptr){}
Specialiry::~Specialiry() {
    delete []subject;
    subject=nullptr;
    n=0;
}
void set_name_subject(const string& name_, Subject& subject_){

    if(name_=="OOP"){
        subject_.name=OOP;
    }
    else if (name_=="Fisics"){
        subject_.name=Fisics;
    }
    else if(name_=="English"){
        subject_.name=English;
    }
    else if(name_=="Chemistry"){
        subject_.name=Chemistry;
    } else{
        cout<<"incorrect name"<<endl;
    }

}
void set_num_sem(const string& name_, Subject& subject_){
    if(name_=="first"){
        subject_.numSem=first;
    }
    else if(name_=="second"){
        subject_.numSem=second;
    } else{
        cout<<"incorrect name"<<endl;
    }
}

string get_name_subject(const Subject& subject_){
    if(subject_.name==OOP){
        return "OOP";
    }
    else if(subject_.name==Fisics){
        return "Fisics";
    }
    else if(subject_.name==English){
        return "English";
    }
    else if(subject_.name==Chemistry){
        return "Chemistry";
    } else{
        return "unsigned name";
    }
}
string get_num_sem(const Subject& subject_){
    if(subject_.numSem==first){
        return "first";
    }
    if(subject_.numSem==second){
        return "second";
    }
    return "unsigned semester";
}


istream& operator >>(istream& in, Subject &subject_) {
    cout<<"input name of Subject";
    string tmp;
    getline(in, tmp);
    set_name_subject(tmp,subject_);
    cout<<"input namber of semeter";
    getline(in, tmp);
    set_num_sem(tmp,subject_);
    cout<<"input a general time";
    getline(in,tmp);
    subject_.time=  stoi(tmp);
    cout<<"input a lecture time";
    getline(in,tmp);
    subject_.lec_time=  stoi(tmp);
    cout<<"input a practical time";
    getline(in,tmp);
    subject_.prac_time= stoi(tmp);
    return in;
}
ostream& operator <<(ostream& out, Subject &subject_){
    out <<"\t" <<" Info about subject: "<<endl
         << "\t" <<"name of subject: "<<get_name_subject(subject_)<<endl
        << "\t" <<"namber of semester: "<< get_num_sem(subject_)<<endl
        << "\t" <<"general time: "<<subject_.time<<endl
        << "\t" <<"lec_time: "<<subject_.lec_time<<endl
        << "\t" <<"prac_time: " <<subject_.prac_time<<endl;
    return  out;
}
const string& Specialiry::getName() const {return nameS;}
const Facult& Specialiry::getfacult() const {return facult;}
int Specialiry::getNumberOfSubj () const {return n;}
void Specialiry::outputSubj(ostream &out) const  {
    for (int i = 0; i < n; i++) {
        out << subject[i] << endl;
    }
}
void  Specialiry::setName(const string& name_) {nameS = name_;}
void  Specialiry::setSpecialization(const string& specializations) {specialisation = specializations;}
void  Specialiry::setFacult(const Facult& facult1) {facult = facult1;}
void  Specialiry::setNumberOfSubj(int nSubj) {n = nSubj;}
void Specialiry::showInfoFacult(ostream& out) const {
    cout << "Info about the facult: \t";
    out << this->facult << endl;
}
void Specialiry::showInfoSpecialization(ostream& out) const {
    cout << "Info about the specialization: \t";
    out << this->specialisation << endl;
}
void Specialiry::showGeneralTime(ostream& out){
    for(int i = 0 ; i < n; i++){
       out<< subject[i].time<<" ";
    }
}
ostream& operator <<(ostream& out, const Specialiry& specialiry) {

    specialiry.outputSubj(out);
    return out;
}
Specialiry& Specialiry:: operator =(const Specialiry& specialiry) {
    if (this == &specialiry) return (*this);
    this -> ~Specialiry();
    nameS = specialiry.nameS;
    specialisation =specialiry.specialisation;
    facult =specialiry.facult;
    n = specialiry.n;
    subject = new Subject[n];
    for (int i = 0; i < n; i++) {
        subject[i] = specialiry.subject[i];
    }
}
bool Specialiry::isExistSubject(SubjectName name_, SubjectNumSem num_sem ,int time, int lec_time, int prac_time ) const {
    for (int i = 0; i < n; i++) {
        if (subject[i].numSem == num_sem && subject[i].name == name_ && subject[i].time == time && subject[i].lec_time==lec_time && subject[i].prac_time == prac_time) {
            return true;
        }
    }
    return false;
}

bool Specialiry::deleteSubject(SubjectName Name_, SubjectNumSem num_sem ,int time, int lec_time, int prac_time)
{
    if (!isExistSubject(Name_, num_sem,time,lec_time,prac_time)) return false;
    auto * mas = new Subject[n - 1]; //выделяем новую область памяти
    int j = 0;
    for (int i = 0; i < n; ++i)
    {
        if (subject[i].name == Name_ && subject[i].numSem == num_sem && subject[i].time == time && subject[i].lec_time ==lec_time && subject[i].prac_time ==prac_time)
        {
            continue;
        }
        mas[j++] = subject[i];    //переносим массив в новую область памяти
    }
    delete[]subject;//удаляем старый массив
    subject = mas;//пернаправляем указатель на новый увеличенный массив
    --n;
    return true;
}

Subject addSubj(SubjectName name_,SubjectNumSem num_sem, int time, int lec_time, int prac_time){
    Subject newSubj ={name_,num_sem, time, lec_time, prac_time};
    return newSubj;
}
bool Specialiry::addSubj(const Subject& subject1) {
    if (isExistSubject(subject1.name, subject1.numSem, subject1.time, subject1.lec_time, subject1.prac_time)) {
        return false;
    }
    auto *mas = new Subject[n + 1];
    for (int i = 0; i < n; i++) {
        mas[i] = subject[i];
    }
    mas[n] = subject1;
    delete[]subject;
    subject = mas;
    ++n;
    return true;
}
    Specialiry &Specialiry::operator += (const Subject &subject1) {
        addSubj(subject1);
        return (*this);
    }
    bool Specialiry::operator<(const Specialiry &arg2) const {
        return (this->n < arg2.n);
    }
Specialiry::operator int() const {
    return n;
}
istream& operator >> (istream& in, Specialiry& specialiry) {
    string tmp;
    cout << " input name of speciality: ";
    getline(in, tmp);
    specialiry.setName(tmp);
    cout << " input specialization of speciality: ";
    getline(in, tmp);
    specialiry.setSpecialization(tmp);
    cout << "Please input facult data: \n";
    Facult facultTmp;
    in >> facultTmp;
    specialiry.setFacult(facultTmp);
    string answer;

    do {
        cout << "Please add subject: \n";
        Subject subject;
        in >> subject;
        specialiry += subject;
        cout << "Do you want to continue add subject(y/n): ";
        getline(in, answer);
    } while (!answer.empty() && answer[0] == 'y');
    return in;
}
