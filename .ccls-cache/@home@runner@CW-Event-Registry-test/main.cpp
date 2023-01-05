/* **********************************
Angela Xu
ICS4U1-4A Dr. N
Monday, May 30, 2022
	************************************/

//Claude Watson Passport Event
//1. Select from events (Music - Music Revue, Art - Fashion Gallery, Drama - One Acts, Dance - Dance Night, Film - ZOOM Festival)
//2. Add participants/audience name, cw (y/n), major
//3. List Applicant statuses within the event
//4. Delete Applicant, delete event
//5. Exit Program

#include <algorithm> 
#include <iostream>
#include <vector>

using namespace std;

enum choices{
ADDEV = 1, ADDPAR, MODPAR, DISINFO, EXIT
};

void welcomeMessage(){

	cout<< "                            _     _"<<endl;
	cout<< "                           ( \\---/ )"<<endl;
	cout<< "                            ) . . ("<<endl;
	cout<< "___Welcome To_________,--._(___Y___)_,--._______________"<<endl;
	cout<< "                      `--'           `--'"<<endl;
	
	cout<<" ______ ________      ______                     __  "<<endl;
	cout<<"|      |  |  |  |    |   ___|.--.--.-----.-----.|  |_ "<<endl;
	cout<<"|   ---|  |  |  |    |   ___||  |  |  -__|     ||   _| "<<endl;
	cout<<"|______|________|    |______| \\___/|_____|__|__||____|"<<endl;
	cout<<endl;
	cout<<"    ______               __         __         "<<endl;
	cout<<"   |   __ \\.-----.-----.|__|.-----.|  |_.----.--.--. "<<endl;
	cout<<"   |      <|  -__|  _  ||  ||__ --||   _|   _|  |  |"<<endl;
	cout<<"   |___|__||_____|___  ||__||_____||____|__| |___  |"<<endl;
	cout<<"                 |_____|                     |_____|"<<endl;
	cout<< "–----------—--------------------------------------------"<<endl;
}

void choicesMenu(){
	cout<< "–----------—--------------------------------------------"<<endl;
	cout<< "1. Add Event"<<endl;
	cout<<"2. Add Participant"<<endl;
	cout<<"3. Modify Participant"<<endl;
	cout<<"4. Display Information"<<endl;
	cout<<"5. Exit Program"<<endl;
	cout<<endl;
	cout<< "Example Input: 1"<<endl;
	cout<< "–----------—--------------------------------------------"<<endl;
}

void addevTitle(){
	cout<< "========================================================"<<endl;
	cout<<endl;
	cout<< "						ADD EVENT"<<endl;
	cout<<endl;
	cout<< "========================================================"<<endl;
}

void addparTitle(){
	cout<< "========================================================"<<endl;
	cout<<endl;
	cout<< "						ADD PARTICIPANT"<<endl;
	cout<<endl;
	cout<< "========================================================"<<endl;
}

void modparTitle(){
	cout<< "========================================================"<<endl;
	cout<<endl;
	cout<< "						MODIFY PARTICIPANT"<<endl;
	cout<<endl;
	cout<< "========================================================"<<endl;
}

void displayinfoTitle(){
	cout<< "========================================================"<<endl;
	cout<<endl;
	cout<< "						DISPLAY INFORMATION"<<endl;
	cout<<endl;
	cout<< "========================================================"<<endl;
}

//-----------------------Exception Class----------------------------------------
class Exception : public exception{
private:
	string msg;
public:
//make Exception constructor
	Exception( const string &message): msg(message){};
	string getMessage(){
		return msg;
	}
	void displayMessage(){
		cout<< "\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<< "Error: "<< getMessage() <<endl;
		cout<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}
};

//Add Event Info (Name of Event, Method of Gathering, Department Hosting)
//Add Participant Info (Event attending, Name of Participant, (Number of stamps of Participant), //Department of Participant, Grade, Email)

//-----------------------Participant Class--------------------------------------
class Participant{
	//add properties of participant
private:
	string name;
	string department;
	int stamps;
	int grade;
	string email;

//if department of event is different than the department of participant, then add a stamp number when displaying. If the participant has more than 8 stamps, display message "You cannot collect more stamps, but can continue attending events."
//verify email: if the email string has @ and . in the string...
public:

//create Participant constructor
	Participant(string n, string dep, int stp, int grd, string em): name(n), department(dep), stamps(stp), grade(grd), email(em){
		transform(name.begin(), name.end(), name.begin(), ::toupper);
	}

	void listParInfo(){
		cout<< "Participant Name: " << name <<endl;
		cout<< "Department of Major: " << department <<endl;
		cout<< "Number of Stamps: " <<stamps <<endl;
		cout<< "Grade: "<<grade<<endl;
		cout<< "Email: "<<email<<endl;
	}

	void modInfo(string n, string dep, int stp, int grd, string em){
		name = n;
		department = dep;
		stamps = stp;
		grade = grd;
		email = em;
		transform(name.begin(), name.end(), name.begin(), ::toupper);
	}

	string getName(){
		return name;
	}
	string getDep(){
		return department;
	}
	string getEmail(){
		return email;
	}
	int getStamp(){
		return stamps;
	}
	int getGrade(){
		return grade;
	}

//destructor frees memory
~Participant(){}
	
};



//-----------------------Event Class-----------------------------------------------
class Event{
	//add properties of Event
protected:
	string name;
	string department;
	vector<Participant> participants;

public:
//constructor for Event class
	Event(string n, string dep):name(n), department(dep){};

//list Participant records
	void listInfo(){
		cout<< "Registrants in Event "<< name<< ": "<<endl;
		//if no participants, then output no participants
		if(participants.size()==0){
			cout<< "No Participants in this event."<<endl;
		}
		else{
			//display GUI here
			cout<< "–----------—--------------------------------------------"<<endl;
		
			for(int i=0; i<participants.size(); i++){
				//print participant information
				participants[i].listParInfo();
			}
			cout<< "–----------—--------------------------------------------"<<endl;
		}
	}

	string getName(){
		return name;
	}
	string getDepartment(){
		return department;
	}

//-----------------------Participant Information------------------------
//add Participant records
	virtual void addInfo(Participant& p){
		participants.push_back(p);
	}

//delete Participant records
	void deleteInfo(Participant& p){
		
	}

//modify Participant records
	void modifyInfo(Participant& p){
		
	}

//destructor frees memory
virtual ~Event(){
	participants.clear();
}
};

//-----------------------Sub Classes-------------------------------------------

class Online : public Event{
private:
	//limit is 100
	int maxParticipants = 100;
public: 
	Online(string n, string department) : Event(n, department){}
	void addInfo(Participant& p){
		if(participants.size() < maxParticipants){
			participants.push_back(p);
		}
		else{
			throw Exception("Maximum number of Registrants reached. Cannot register more participants in this event.");
		}
	}
	void listInfo(){
		Event::listInfo();
	}
};

class Hall : public Event{
private:
	//limit is 300
	int maxParticipants = 300;
public:
	Hall(string n, string dep) : Event(n, dep){}
	void addInfo(Participant& p){
		if(participants.size() < maxParticipants){
			participants.push_back(p);
		}
		else{
			throw Exception("Maximum number of Registrants reached. Cannot register more participants in this event.");
		}
	}
	void listInfo(){
		Event::listInfo();
	}
};

class Room : public Event{
private:
	//limit is 50
	int maxParticipants = 50;
public:
	Room(string n, string dep) : Event(n, dep){}
	void addInfo(Participant& p){
		if(participants.size() <maxParticipants){
			participants.push_back(p);
		}
		else{
			throw Exception("Maximum number of Registrants reached. Cannot register more participants in this event.");
		}
	}
	void listInfo(){
		Event::listInfo();
	}
};

//-----------------------------Other Methods---------------------------------

void displayInfo(vector<vector<Event>*> vec){
	//if there are no events in the vector
	for(int i=0; i<3; i++){
		cout<<endl;
		if(i==0){
			cout<< "Online Events: "<<endl;
		}
		if(i==1){
			cout<< "Hall Events: "<<endl;
		}
		if(i==2){
			cout<< "Room Events: "<<endl;
		}
		if(vec.size() == 0){
		cout<<"No Events."<<endl;
	}
	for(int j=0; j<vec.size(); j++){
		vec[i]->at(j).listInfo();
	}
	}
	
}

int findEventloc(vector<vector<Event>*> vec, string name){
	bool flag = false;
	int loc=0;
	for(int i =0 ; i<3; i++){
		for(int k= 0; k<vec[i]->size(); k++){
			if(vec[i]->at(k).getName() == name){
				loc = i + 1; 
				//1 = online, 2 = hall, 3 = room, 0 = not found
				return loc;
			}
		}
	}
	return loc;
}

int findEventindex(vector<vector<Event>*> vec, string name, int loc){
	int index;
	for(int i=0; i<vec[loc-1]->size(); i++){
		if(vec[loc-1]->at(i).getName() == name){
			return i;
		}
	}
	//if the event name cannot be found
	return -1;
}

//-----------------------------Main Class-----------------------------------

//make vector of vecotr type
int main() {
	welcomeMessage();
	bool flag = true;
	vector<vector<Event>*> events;
	vector<Event> onlineev;
	vector<Event> hallev;
	vector<Event> roomev; 
	events.push_back(&onlineev);
	events.push_back(&hallev);
	events.push_back(&roomev);
	
	string evname;
	string evdep;
	string parname;
	string pardep;
	int parstamps;
	int pargrade;
	string paremail;
	int loc;
	int index;
	//default participant
	Participant p("", "", 0, 0, "");
	
	string command;

	try{
		while(flag){
		choicesMenu();
		
		string command;
		cin >> command;
		//throw exception if stoi(command) is an invalid argument
	
		switch(stoi(command)){
			//-----------------------------Add Event-----------------------------------
			case ADDEV: {
				//output the title
				addevTitle();

				cout<<"Event Name: ";
				//get Event Name and allow spaces
				getline(cin>>ws, evname);
				//if an event of same name and department exists, throw error
				cout<< "Department (Music, Visual, Drama, Film, Dance): ";
				cin >> evdep;
				if(evdep!= "Music" && evdep!="Visual" && evdep!= "Drama" && evdep!= "Film" && evdep!= "Dance"){
					//throw error
					throw Exception("Please enter a valid department type. (Case sensitive)");
				}
				cout<< "Event Location (Online - o, Cringan Hall - c, Classroom - r): ";
				string input;
				cin>>input;
				if(input == "o" || input == "O"){
					//make Online Event type
					Online online(evname, evdep);
					onlineev.push_back(online);
					//or events[0].push_back(online);
					cout<< "Created an Online Event: "<<evname<< " in the "<<evdep<< " Department!"<<endl;
				}
				if(input == "c" || input == "C"){
					//make Hall Event type
					Hall hall(evname, evdep);
					hallev.push_back(hall);
					//or events[1].push_back(hall);
					cout<< "Created an Event in Cringan Hall: "<<evname<< " in the "<<evdep<< " Department!"<<endl;
				}
				if(input == "r" || input == "R"){
					//make Room Event type
					Room room(evname, evdep);
					roomev.push_back(room);
					//or events[2].push_back(room);
					cout<< "Created an Event in a classroom: "<<evname<< " in the "<<evdep<< " Department!"<<endl;
				}
					break;
			}
			//-----------------------------Add Participant-----------------------------------
			case ADDPAR:
				addparTitle();
				
				cout<< "Name: ";
				getline(cin>>ws, parname);
				cout<< "Department (Music, Visual, Drama, Film, Dance, N/A): ";
				cin>> pardep;
				//throw error if partipant's department does not exist in the selection
				if(pardep!= "Music" && pardep!="Visual" && pardep!= "Drama" && pardep!= "Film" && pardep!= "Dance" && pardep!= "N/A"){
					throw Exception("Please enter a valid department type. (Case sensitive)");
				}
				cout << "Number of CW event stamps: ";
				cin >> parstamps;
				cout << "Grade: ";
				cin >> pargrade;
				cout << "Email:";
				cin >> paremail;

				//Example Participant p("Angela", "Music", 3, 12, "angela@gmail.com");
				//Participant p(parname, pardep, parstamps, pargrade, paremail);
				
				cout<< "Which Event are you attending? (Name): ";
				getline(cin>>ws, evname);

				//loop through events to find the event you are looking for
				//cout << "Event Name is: " << events[0][0].getName()<<endl;
				loc = findEventloc(events, evname); //=0
				if(loc == 0){
					throw Exception("Event does not exist in the database.");
				}
				index = findEventindex(events, evname, loc);
				if(index == -1){
					throw Exception("Event does not exist in the database.");
				}

				p.modInfo(parname, pardep, parstamps, pargrade, paremail);
				events[loc-1]->at(index).addInfo(p);
				cout << "Registered Participant: " << p.getName() << " to Event: "<<events[loc-1]->at(index).getName() <<"!"<<endl;
				
			break;
			//-----------------------------Modify Participant-----------------------------------
			case MODPAR:






				
			break;
			//-----------------------------Display Information-----------------------------------
			case DISINFO:
				displayInfo(events);	
				break;
			
			case EXIT:
				cout<< "Thank you for using Claude Watson Event Registry! "<<endl;
				flag = false;
				break;

			default: throw Exception("Input invalid. Please try again.");
			}
		}
	}
	catch(Exception &e){
		e.displayMessage();
	}
	catch(exception &e){
		Exception obj(e.what());
		obj.displayMessage();
	}
}