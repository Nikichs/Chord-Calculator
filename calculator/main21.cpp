#include <bits/stdc++.h>

using namespace std;

string string_six, string_five, string_four, string_three, string_two, string_one;
vector <string> string_names{string_six, string_five, string_four, string_three, string_two, string_one};

int check_fret(string string_name, int number){
    string num_str = to_string(6-number);
    cout << num_str+"th String"<<endl;
    cin >> string_name;
    string_names[number] = string_name;
    bool check_letter = ((string_name != "0") && (atoi(string_name.c_str())==0));
    bool test = ((string_name!="x")&&(check_letter==1));
    bool test_num = ((atoi(string_name.c_str())>20) || (atoi(string_name.c_str())<0));
    if (!test != !test_num){
        cout<<"Check your input and try again" << endl;
        check_fret(string_name, number);
    }
}

int notes_on_frets(int fret[], int root_note, string fret_on_string){

    for (int i = 0; i<=20; i++){
    int cnt;
    if (i == 0) {cnt = root_note;}
    if (cnt == 12){cnt = 0;}
    fret[i] = cnt;
    cnt++;
  }

  if (fret_on_string == "x"){
    return - 1;
  }
  else {return fret[atoi(fret_on_string.c_str())];}
}

string get_note(int fret){
    switch(fret){
        case -1: return "Muted";
        case 0: return "C";
        case 1: return "C#";
        case 2: return "D";
        case 3: return "D#";
        case 4: return "E";
        case 5: return "F";
        case 6: return "F#";
        case 7: return "G";
        case 8: return "G#";
        case 9: return "A";
        case 10: return "A#";
        case 11: return "B";
        default: return " - ";
    }
}

int get_note_number(string note){

        if (note == "C" ){return 0;}
        if (note == "C#" ){return 1;}
        if (note == "D" ){return 2;}
        if (note == "D#" ){return 3;}
        if (note == "E" ){return 4;}
        if (note == "F" ){return 5;}
        if (note == "F#" ){return 6;}
        if (note == "G" ){return 7;}
        if (note == "G#" ){return 8;}
        if (note == "A" ){return 9;}
        if (note == "A#" ){return 10;}
        if (note == "B" ){return 11;}
        else {return -100;}
}

int major(int note, int scale[], bool need_output = false){
        int next_note;
        int add;
        scale[0] = note;
        for(int i = 1; i<=7; i++){
            if((i==3)||(i==7)){add = 1;}
            else{add = 2;}
            next_note = scale[i-1] + add;
            if (next_note>=12){next_note = next_note - 12;}
            scale[i] = next_note;
        }

        if (need_output == true){
            for(int i = 0; i<=7; i++){
            cout << get_note(scale[i]) << " ";
        }
        }
    }

int minor(int note, int scale[], bool need_output = false){
        int next_note;
        int add;
        scale[0] = note;
        for(int i = 1; i<=7; i++){
            if((i==2)||(i==5)){add = 1;}
            else{add = 2;}
            next_note = scale[i-1] + add;
            if (next_note>=12){next_note = next_note - 12;}
            scale[i] = next_note;
        }

        if (need_output == true){
            for(int i = 0; i<=7; i++){
            cout << get_note(scale[i]) << " ";
        }
        }
    }

string get_chord(vector<int> notes){

    bool ismajor = false;
    bool isminor = false;
    int tonic;
    int scale[8];

            if (notes.size()==2){
                if((notes[0]-notes[1]==-7)||(notes[0]-(notes[1]+12)==-7)){
                    return get_note(notes[0]) + "5";
                }
            }
            sort(notes.begin(), notes.end());
            if (notes.size()==3){
            major(notes[0], scale);
            if(((scale[2]==notes[1])&&(scale[4]==notes[2]))||((scale[2]==notes[2])&&(scale[4]==notes[1]))){

                if (notes.size()==3){
                return get_note(notes[0]) + " Major";
                }
                else {
                    tonic = notes[0]; ismajor = true;
                }
            }

            major(notes[1], scale);
            if (ismajor == false){
            if(((scale[2]==notes[0])&&(scale[4]==notes[2]))||((scale[2]==notes[2])&&(scale[4]==notes[0]))){

                if (notes.size()==3){
                return get_note(notes[1]) + " Major";
                }
                else {
                    tonic = notes[1]; ismajor = true;
                }

            }
            }

            if (ismajor == false){
            major(notes[2], scale);
            if(((scale[2]==notes[1])&&(scale[4]==notes[0]))||((scale[2]==notes[0])&&(scale[4]==notes[1]))){
                if (notes.size()==3){
                return get_note(notes[2]) + " Major";
                }
                else {
                    tonic = notes[2]; ismajor = true;
                }
            }
            }

            if (ismajor==false){

            minor(notes[0], scale);
            if(((scale[2]==notes[1])&&(scale[4]==notes[2]))||((scale[2]==notes[2])&&(scale[4]==notes[1]))){
                if (notes.size()==3){
                return get_note(notes[0]) + " Minor";
                }
                else {
                    tonic = notes[0]; isminor = true;
                }
            }

            if (isminor == false){
            minor(notes[1], scale);
            if(((scale[2]==notes[0])&&(scale[4]==notes[2]))||((scale[2]==notes[2])&&(scale[4]==notes[0]))){
                if (notes.size()==3){
                return get_note(notes[1]) + " Minor";
                }
                else {
                    tonic = notes[1]; isminor = true;
                }
            }
            }

            if (isminor == false){
            minor(notes[2], scale);
            if(((scale[2]==notes[1])&&(scale[4]==notes[0]))||((scale[2]==notes[0])&&(scale[4]==notes[1]))){
                if (notes.size()==3){
                return get_note(notes[2]) + " Minor";
                }
                else {
                    tonic = notes[2]; isminor = true;
                }
            }
            }
            }
            }

            if (notes.size()==4){
                int p1 = notes[0];
                int p2 = notes[1];
                int p3 = notes[2];
                int p4 = notes[3];
                if ((p4 - p3 == 3)&&(p3 - p2 == 3)&&(p2 - p1 == 4)) {
                    return get_note(notes[0])+"7";
                }
                else if((p1 + 12 - p4 == 3)&&(p4 - p3 == 3)&&(p3 - p2 == 4)) {
                    return get_note(notes[1])+"7";
                }
                else if((p2 - p1 == 3)&&(p1 + 12 - p4 == 3)&&(p4 - p3 == 4)) {
                    return get_note(notes[2])+"7";
                }
                else if((p3 - p2 == 3)&&(p2 - p1 == 3)&&(p1 + 12 - p4 == 4)) {
                    return get_note(notes[3])+"7";
                }
                else if ((p4 - p3 == 3)&&(p3 - p2 == 4)&&(p2 - p1 == 3)) {
                    return get_note(notes[0])+"m7";
                }
                else if((p1 + 12 - p4 == 4)&&(p4 - p3 == 3)&&(p3 - p2 == 3)) {
                    return get_note(notes[1])+"m7";
                }
                else if((p2 - p1 == 3)&&(p1 + 12 - p4 == 4)&&(p4 - p3 == 3)) {
                    return get_note(notes[2])+"m7";
                }
                else if((p3 - p2 == 3)&&(p2 - p1 == 4)&&(p1 + 12 - p4 == 3)) {
                    return get_note(notes[3])+"m7";
                }
            }
}

int main() {
  int answer;
  cout << "Welcome to the brand new music calculator!" << endl;
  cout << "If you want to see what chord it is, depending on inputed positions, type 1" << endl;
  cout << "If you want to see the scale (minor/major) of a given note type 2" << endl;
  cin >> answer;
  if (answer == 2){
    int temp_scale[8];
    string your_note;
    cout << "Choose type of scale" << endl;
    cout << "1 - Minor" << endl;
    cout << "2 - Major" << endl;
    cin >> answer;
    cout << "Enter your note, example C# D. Note: your can't use Bb or Db, use # instead." << endl;
    cin >> your_note;
    if (answer==1){
        minor(get_note_number(your_note), temp_scale, true);
    }
    else if (answer == 2){
        major(get_note_number(your_note), temp_scale, true);
    }
    else {
        cout << "We are sorry. Your input is incorrect. Try again" << endl;
    }
  }

  else if (answer == 1){
  cout << "Frets 20. Muted x. Open string 0."<<endl;
  for (int i = 0; i<=5; i++){
    check_fret(string_names[i], i);
  }

  int e_notes[20], B_notes[20], G_notes[20], D_notes[20], A_notes[20], E_notes[20];
  int e_root = 4, B_root = 11, G_root = 7, D_root = 2, A_root = 9, E_root = 4;
  int E_note, A_note, D_note, G_note, B_note, e_note;
  int notes[6] = {E_note, A_note, D_note, G_note, B_note, e_note};

  string E_notename, A_notename, D_notename, G_notename, B_notename, e_notename;
  string notenames[6] = {E_notename, A_notename, D_notename, G_notename, B_notename, e_notename};

  notes[5] = notes_on_frets(e_notes, e_root, string_names[5]);
  notes[4] = notes_on_frets(B_notes, B_root, string_names[4]);
  notes[3] = notes_on_frets(G_notes, G_root, string_names[3]);
  notes[2] = notes_on_frets(D_notes, D_root, string_names[2]);
  notes[1] = notes_on_frets(A_notes, A_root, string_names[1]);
  notes[0] = notes_on_frets(E_notes, E_root, string_names[0]);

  int All_Notes[6];
  vector<int> Unique_Notes;

  for (int i = 0; i<=5; i++){
    All_Notes[i] = notes[i];
  }
cout << endl;
  int f = 5;
  int m = 5;
  while(f>0){
    while(m>0){
        if(All_Notes[f] == All_Notes[m-1]){
            All_Notes[f]=-10;
        }
        m--;
    }
   f--;
   m = f;
  }

  for(int i = 0; i<=5; i++){
    if ((All_Notes[i]!=-10)&&(All_Notes[i]!=-1)){Unique_Notes.push_back(All_Notes[i]);}
  }

  for (int i = 0; i<=5; i++){
    notenames[i] = get_note(notes[i]);
  }

  cout << "Your input: "<<endl;
  cout << endl;
  cout << "e: Fret: " + string_names[5] + " Note: " + notenames[5]<< endl;
  cout << "B: Fret: " + string_names[4] + " Note: " + notenames[4]<< endl;
  cout << "G: Fret: " + string_names[3] + " Note: " + notenames[3] << endl;
  cout << "D: Fret: " + string_names[2] + " Note: " + notenames[2] << endl;
  cout << "A: Fret: " + string_names[1] + " Note: " + notenames[1] << endl;
  cout << "E: Fret: " + string_names[0] + " Note: " + notenames[0] << endl;
  cout << endl;
  cout << "Notes: [ "; for(int i = 0; i<=Unique_Notes.size()-1; cout << get_note(Unique_Notes[i]) << " ", i++){;} cout << "]";
  cout << endl;
  cout << "Chord: " << get_chord(Unique_Notes) << endl;
  }
  else {
    cout << "We are sorry. Your input is incorrect. Try again" << endl;
  }
}
