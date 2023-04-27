# CW-Event-Registry
Grade 12 final project: a purely C++ database run through the console

CW Passport Registry is a resourceful database program used to record and
register students for Claude Watson passport events. Users, such as the Claude
Watson ambassadors, can add and delete events as well as add, delete, and modify
participant information in the events using simple commands.

The base class, Event, contains a vector of participants, acting as a list. Within
the class, there are more functions that modify and add Participant information into
the vector: listInfo, addInfo, deleteInfo, modifyInfo. There are also three subclasses,
Online, Hall, and Room, each representing events hosted in locations online, in
Cringan Hall, or in a classroom. Each subclass contains a specific registration limit in
relation to the actual size of the locations (Maximum capacity of Online events -
100, Hall events - 300, Room events - 50).

The user is prompted to enter a single digit integer to choose their action at
the beginning. There are also many user-friendly titles and headers for each
function the user decides to perform. The user may then follow the on-screen
instructions and information to make their inputs. All inputs are validated
immediately and exceptions are thrown using functions from the Exception class,
which inherits from the exceptions class the c++ library provides. Afterwards,
exceptions are caught and displayed using the displayMessage function of the
Exception class.

After exiting the program, all used memory and vectors are freed to prevent
memory leakage. There are destructors in both the Event and Participant class,
which clears vectors and other information.

[View the full report here](https://github.com/angeladev333/CW-Event-Registry/blob/main/2021%20-%20CW%20Passport%20Registry%20Report.pdf)
