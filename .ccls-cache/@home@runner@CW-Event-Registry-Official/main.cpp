/* *********************************************************************
Created by: Angela Xu
Project: Claude Watson Event Registry
Goal: Create Events and Register Participants to said events. Display option is available as well. Note that the rules to getting passport stamps and registering Participants are made to be as similar to the real Claude Watson Program's rules as possible. 
Class: ICS4U1-4A Dr. N
Date: Monday, May 30, 2022
***********************************************************************/

#include <algorithm> 
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//enumerator for 7 choices
enum choices{
ADDEV = 1, ADDPAR, MODPAR, DELPAR, DELEV, DISINFO, EXIT
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
	cout<<"            ,   ,0     ,        "<<endl;
	cout<<"            |)  |)   ,'|        "<<endl;
	cout<<"   ___     0'   '   | 0'      "<<endl;
	cout<<"  |  |             0'     "<<endl;
	cout<<" 0' 0'---—---------------------------------------------"<<endl;
	cout<< "1. Add Event"<<endl;
	cout<<"2. Add Participant"<<endl;
	cout<<"3. Modify Participant"<<endl;
	cout<<"4. Delete Participant"<<endl;
	cout<<"5. Delete Event" <<endl;
	cout<<"6. Display Information"<<endl;
	cout<<"7. Exit Program"<<endl;
	cout<<endl;
	cout<< "–----------—--------------------------------------------"<<endl;
}

void modparMenu(){
	cout<<" `[]       , "<<endl;
	cout<<"  ||    ,   |   "<<endl;
	cout<<"  ||    |  0'    "<<endl;
	cout<<"  ||   0'    "<<endl;
	cout<<"\\`::') "<<endl;
	cout<<"/ :: \\"<<endl;
	cout<<"\\___:/  –----------—--------------------------------------------"<<endl;

	cout<<"What would you like to modify in Participant? (Department cannot be changed due to stamp calculations.) "<<endl;

	cout<<"1. Name"<<endl;
	cout<<"2. Number of Stamps"<<endl;
	cout<<"3. Grade"<<endl;
	cout<<"4. Email"<<endl;
	cout<<"5. Event Attending"<<endl;
	cout<<endl;
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

void delparTitle(){
	cout<< "========================================================"<<endl;
	cout<<endl;
	cout<< "						DELETE PARTICIPANT"<<endl;
	cout<<endl;
	cout<< "========================================================"<<endl;
}

void delevTitle(){
	cout<< "========================================================"<<endl;
	cout<<endl;
	cout<< "						DELETE EVENT"<<endl;
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
		cout<< "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<< "Error: "<< getMessage() <<endl;
		cout<< "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	}

~Exception(){}
};

//Examples:
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
		cout<< "		Registrants in Event "<< name<< ": "<<endl;
		//if no participants, then output no participants
		if(participants.size()==0){
			cout<< "		No Participants in this event."<<endl;
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

	bool isnotEmpty(){
		if(participants.size() != 0){
			return true;
		}
		return false;
	}

//-----------------------Participant Information------------------------
//add Participant records
	virtual void addInfo(Participant p){
		participants.push_back(p);
	}

//delete Participant records
	void deleteInfo(Participant p){
		int index = findParpos(p);
		if(index ==-1){
			throw Exception("Participant is not registered in this Event.");
		}
		auto it = participants.begin() + index;
		participants.erase(it);
	}

//modify Participant records
	void modifyInfo(Participant p, int index){
		participants.at(index) = p;
	}

//find Participant position
	int findParpos(Participant p){
		for(int i=0; i<participants.size(); i++){
			if(participants[i].getName() == p.getName()){
				return i;
			}
		}
		return -1;
	}
//find Participant Information
	string getParName(int index){
		//use index of participant to locate participant
		return participants[index].getName();
	}
	string getParDep(int index){
		return participants[index].getDep();
	}
	string getParEmail(int index){
		return participants[index].getEmail();
	}
	int getParStamp(int index){
		return participants[index].getStamp();
	}
	int getParGrade(int index){
		return participants[index].getGrade();
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

//check if there is no Participant yet (Cannot Modify or Delete Participant)
bool isEmpty(vector<vector<Event>*> vec){
	//loop through all the Event location vectors
	for(int i=0; i<3; i++){
		//loop through all the events
		for(int j=0; j<vec[i]->size(); j++){
			//if an event is not empty, then entire vector is not Empty
			if(vec[i]->at(j).isnotEmpty()){
				return false;
			}
		}
	}
	return true;
}

//check if there is no Event yet (Cannot add Participant, Modify Participant, Delete Participant, or Delete Event)
bool noEvent(vector<vector<Event>*> vec){
	//see if the size is 0 for any of the Event location vectors
	for(int i=0; i<3; i++){
		//if any of the Event location vectors has an Event, the overall vector is not empty
		if(vec[i]->size() != 0){
			return false;
		}
	}
	return true;
}

void displayInfo(vector<vector<Event>*> vec){
	//if there are no events in the vector
	for(int i=0; i<3; i++){
		cout<<endl;
		if(i==0){
			cout<< "ONLINE EVENTS: "<<endl;
		}
		if(i==1){
			cout<< "HALL EVENTS: "<<endl;
		}
		if(i==2){
			cout<< "ROOM EVENTS: "<<endl;
		}
		if(vec[i]->size() == 0){
		cout<<"		No events."<<endl;
		}
		else{
			for(int j=0; j<vec[i]->size(); j++){
		vec[i]->at(j).listInfo();
			}
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
	throw Exception("Event does not exist in the database.");
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
	throw Exception("Event does not exist in the database.");
	return -1;
}

//verify if the email is valid
void emailCheck(string email){
	//an email is valid if it contains a @ and . symbol
	//there must be at least 1 . symbol after the @ symbol

	//if the character is not found, find function will return string::npos
	if(email.find('@') == string::npos || email.find('.') == string::npos ){
		throw Exception("Email invalid. Email must contain '@' and '.' symbols.");
	}
	int index = email.find('@');
	if(email.substr(index).find('.') == string ::npos){
		throw Exception("Email invalid. There must be a '.' symbol after the '@'.");
	}
}

void gradeCheck(int grade){
	//registrants must be between grade 9 and 12
	if(grade < 9 || grade > 12){
		throw Exception("Grade invalid. Only students can register in events. Please enter a grade from 9 to 12. ");
	}
}

void stampCheck(int& stamps){
	// input stamps can only be between 0 and 16
	if(stamps < 0){
		throw Exception("Stamp number invalid. Please enter a number from 0 to 8. (Each Claude Watson student must graduate with 8 stamps; 2 stamps per year)");
	}
	if(stamps > 8){
		cout << "Congratulations! You have exceeded the maximum number of stamps (8) and cannot receive more!"<<endl;
		//set stamps number to 8 if exceeded
		stamps = 8;
	}
}

//-----------------------------Main Class-----------------------------------

//make vector of vector type
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
	string locname;
	int index;
	int locnew;
	int indexnew;
	int indexPar;
	//default participant
	Participant p("", "", 0, 0, "");
	
	string command;

	
	while(flag){
		try{
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
				else if(input == "c" || input == "C"){
					//make Hall Event type
					Hall hall(evname, evdep);
					hallev.push_back(hall);
					//or events[1].push_back(hall);
					cout<< "Created an Event in Cringan Hall: "<<evname<< " in the "<<evdep<< " Department!"<<endl;
				}
				else if(input == "r" || input == "R"){
					//make Room Event type
					Room room(evname, evdep);
					roomev.push_back(room);
					//or events[2].push_back(room);
					cout<< "Created an Event in a classroom: "<<evname<< " in the "<<evdep<< " Department!"<<endl;
				}
				else{
					throw Exception("Input invalid. Please enter o for Online, c for Cringan Hall, r for Classroom");
				}
					break;
			}
			//-----------------------------Add Participant-----------------------------------
			case ADDPAR:
				addparTitle();
				
				//if no events in database, dont let them add
				if(noEvent(events) == true){
					throw Exception("Cannot create a Participant. Please add an Event first. ");
				}
				
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
				if(pardep == "N/A" && parstamps != 0){
					throw Exception("Students not within the Claude Watson program cannot receive stamps. ");
				}
				stampCheck(parstamps);
				cout << "Grade: ";
				cin >> pargrade;
				gradeCheck(pargrade);
				cout << "Email: ";
				cin >> paremail;
				emailCheck(paremail);
				
				cout<< "Which Event are you attending? (Name): ";
				getline(cin>>ws, evname);

				//loop through events to find the event you are looking for
				//cout << "Event Name is: " << events[0][0].getName()<<endl;
				loc = findEventloc(events, evname); 
				index = findEventindex(events, evname, loc);

				p.modInfo(parname, pardep, parstamps, pargrade, paremail);

				//check if there is already a participant registered under the same name
				//function findParpos returns -1 if no participant of the same name is found
				if(events[loc-1]->at(index).findParpos(p) != -1){
					throw Exception("There is already a Participant registered under this Event with the same name. Please use the MODIFY PARTICIPANT function to edit this Participant's Information. ");
				}

				//if department of event is different than the department of participant, then add a stamp number when displaying. 
				evdep = events[loc-1]->at(index).getDepartment();
				if(evdep != pardep && pardep != "N/A"){
					cout<< "***Event Department and Participant Department not the same. Participant is eligible for another Claude Watson stamp!***"<<endl;
					if(parstamps+1 <= 8){
						parstamps= parstamps + 1;
					}
					else{
						cout<< "Maximum number of stamps (8) reached. Participant cannot receive more stamps but can continue attending events. "<<endl;
					}
				}
				
				//Example Participant p("Angela", "Music", 3, 12, "angela@gmail.com");
				//Participant p(parname, pardep, parstamps, pargrade, paremail);
				p.modInfo(parname, pardep, parstamps, pargrade, paremail);
				events[loc-1]->at(index).addInfo(p);
				cout << "Registered Participant: " << p.getName() << " to Event: "<<events[loc-1]->at(index).getName() <<"!"<<endl;
				
			break;
			//-----------------------------Modify Participant-----------------------------------
			case MODPAR:
				modparTitle();

				//if no Participants in Database and if there are no Events, then cannot modify Participant
				if(noEvent(events) == true || isEmpty(events) == true){
					throw Exception("Cannot Modify Participant. Must have at least 1 Event and 1 Participant. ");
				}
				
				//get participant name and event attending first
				cout<< "What is the current Participant Name?: ";
				getline(cin>>ws, parname);
				p.modInfo(parname, "", 0, 0, "");
				cout<< "What is the Event Name the Participant is currently attending?: ";
				getline(cin>>ws, evname);

				loc = findEventloc(events, evname); 
				index = findEventindex(events, evname, loc);

				//find the index of the participant at location [loc] and event index [index]
				//findParpos uses participant name to locate the position of the participant in the event
				indexPar = events[loc-1]->at(index).findParpos(p);
				//find current participant information and change p
				pardep = events[loc-1] ->at(index).getParDep(indexPar);
				paremail = events[loc-1]->at(index).getParEmail(indexPar);
				parstamps = events[loc-1]->at(index).getParStamp(indexPar);
				pargrade = events[loc-1]->at(index).getParGrade(indexPar);
				p.modInfo(parname, pardep, parstamps, pargrade, paremail);
				
				
				modparMenu();
				cin>> command;
				if(command == "1" || command == "2" || command == "3" || command == "4"){
					if(command == "1"){
						cout << "Current Name: " << p.getName()<<endl;
						cout << "New Name: ";
						getline(cin>>ws, parname);
					}
					if(command == "2"){
						cout << "Current Number of Stamps: "<<p.getStamp() <<endl;
						cout << "New Number of Stamps: ";
						cin>>parstamps;
						if(pardep == "N/A" && parstamps != 0){
							throw Exception("Students not within the Claude Watson program cannot receive stamps. ");
						}
						stampCheck(parstamps);
					}
					if(command == "3"){
						cout << "Current Grade: " <<p.getGrade()<<endl;
						cout << "New Grade: " ;
						cin>>pargrade;
						gradeCheck(pargrade);
					}
					if(command == "4"){
						cout<< "Current Email: "<<p.getEmail() <<endl;
						cout << "New Email: ";
						cin>>paremail;
						emailCheck(paremail);
					}
					p.modInfo(parname, pardep, parstamps, pargrade, paremail);
					events[loc-1]->at(index).modifyInfo(p, indexPar);
					cout<<"Successfully modified Participant Information!"<<endl;
				}

				//if modify Participant Event location:
				else if(command == "5"){
					cout<< "Current Event Attending: " << events[loc-1]->at(index).getName()<<endl;
					cout<< "Name of new Event Attending: ";
					getline(cin>>ws, evname);

					locnew = findEventloc(events, evname); 
					indexnew = findEventindex(events, evname, locnew);

					//check if there is already a participant registered under the same name
					//function findParpos returns -1 if no participant of the same name is found
					if(events[locnew-1]->at(indexnew).findParpos(p) != -1){
						throw Exception("There is already a Participant registered under this Event with the same name. Please modify the Existing Participant or delete it before moving this Participant's Event. ");
					}

					events[loc-1]->at(index).deleteInfo(p);
					events[locnew-1]->at(indexnew).addInfo(p);

					cout<<"Successfully moved Participant "<<parname<< " from Event "<< events[loc-1]->at(index).getName() <<" to Event "<< events[locnew-1]->at(indexnew).getName() <<"!"<<endl;
					
				}
				else{
					throw Exception("Input invalid. Please enter a number between and including 1-5. ");
				}

			break;
			//-----------------------------Display Information-----------------------------------
			case DISINFO:
				displayinfoTitle();
				displayInfo(events);	
				break;

			//-----------------------------Delete Participant-----------------------------------
			case DELPAR:
				delparTitle();

				//if no Participants in Database and if there are no Events, then cannot delete Participant
				if(noEvent(events) == true || isEmpty(events) == true){
					throw Exception("Cannot Delete Participant. Must have at least 1 Event and 1 Participant. ");
				}
				
				cout<< "What is the current Participant Name?: ";
				getline(cin>>ws, parname);
				p.modInfo(parname, "", 0, 0, "");
				cout<< "What is the Event Name the Participant is currently attending?: ";
				getline(cin>>ws, evname);

				loc = findEventloc(events, evname); 
				index = findEventindex(events, evname, loc);

				//find the index of the participant at location [loc] and event index [index]
				//findParpos uses participant name to locate the position of the participant in the event
				indexPar = events[loc-1]->at(index).findParpos(p);
				pardep = events[loc-1] ->at(index).getParDep(indexPar);
				paremail = events[loc-1]->at(index).getParEmail(indexPar);
				parstamps = events[loc-1]->at(index).getParStamp(indexPar);
				pargrade = events[loc-1]->at(index).getParGrade(indexPar);
				p.modInfo(parname, pardep, parstamps, pargrade, paremail);

				events[loc-1]->at(index).deleteInfo(p);
				cout<< "Successfully deleted Participant "<<parname <<" from "<<events[loc-1]->at(index).getName() << "!"<<endl;

			break;

			//-----------------------------Delete Event-----------------------------------
			case DELEV:
				delevTitle();

				//if no events, then cannot delete event
				if(noEvent(events) == true){
					throw Exception("Cannot Delete. Must have at least 1 Event to delete. ");
				}
				
				cout<< "What is the Event Name?: ";
				getline(cin>>ws, evname);

				loc = findEventloc(events, evname); 
				index = findEventindex(events, evname, loc);

				if(loc == 1){
					locname = "Online";
				}
				if(loc == 2){
					locname = "Hall";
				}
				if(loc == 3){
					locname = "Room";
				}

				//delete the Event class situated at events[loc-1], which gives the location vector, and with the index of where the location vector begins + index found
				events[loc-1]->erase(events[loc-1]->begin() + index);

				cout<< "Successfully deleted Event "<<evname <<" from "<< locname << " Events!"<<endl;

			break;

			//-----------------------------Exit Program-----------------------------------
			case EXIT:
				cout<< ",---------. .---.  .---.    ____    ,---.   .--..--.   .--.             ____     __   ,-----.      ___    _"<<endl;
				cout<< "\\          \\|   |  |_ _|  .'  __ `. |    \\  |  ||  | _/  /              \\   \\   /  /.'  .-,  '.  .'   |  | | "<<endl;
				cout<< " `--.  ,---'|   |  ( ' ) /   '  \\  \\|  ,  \\ |  || (`' ) /                \\  _. /  '/ ,-.|  \\ _ \\ |   .'  | | "<<endl;
				cout<< "    |   \\   |   '-(_{;}_)|___|  /  ||  |\\_ \\|  ||(_ ()_)                  _( )_ .';  \\  '_ /  | :.'  '_  | | "<<endl;
				cout<< "    :_ _:   |      (_,_)    _.-`   ||  _( )_\\  || (_,_)   __          ___(_ o _)' |  _`,/ \\ _/  |'   ( \\.-.| "<<endl;
				cout<< "    (_I_)   | _ _--.   | .'   _    || (_ o _)  ||  |\\ \\  |  |        |   |(_,_)'  : (  '\\_/ \\   ;' (`. _` /| "<<endl;
				cout<< "   (_(=)_)  |( ' ) |   | |  _( )_  ||  (_,_)\\  ||  | \\ `'   /        |   `-'  /    \\ `\"/  \\  ) / | (_ (_) _) "<<endl;
				cout<< "    (_I_)   (_{;}_)|   | \\ (_ o _) /|  |    |  ||  |  \\    /          \\      /      '. \\_/``\".'   \\ /  . \\ / "<<endl;
				cout<< "    '---'   '(_,_) '---'  '.(_,_).' '--'    '--'`--'   `'-'            `-..-'         '-----'      ``-'`-''  "<<endl;

				cout<<endl;
				cout<< "For using Claude Watson Event Registry! "<<endl;
				flag = false;
				break;

			//-----------------------------Default Case-----------------------------------
			default: throw Exception("Input invalid. Please try again.");
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
}

//for future me, add Participant verification when modifying Participant. If Participant is not found, then cannot proceed to modify it.