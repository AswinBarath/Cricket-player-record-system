# Cricket Player Record System Documentation

**A Simple C++ Cricket Player Recording System (Class-XII CS Project)**

This project is a text-based C++ application that helps manage and record cricket match statistics for two teams. It was developed as a high school computer science project with my teammates Subin and Arjun (and myself, of course). It uses basic file I/O along with a simple user interface created with console graphics.

---

## 1. Overview

The application allows the user to:
- **Input Match Details:** Enter the names of two teams, the match venue, and date.
- **Record Player Statistics:** For each team, enter each player’s number, name, number of matches played, and individual match scores.
- **Perform CRUD Operations:** Insert new records, display existing records, search for a record by player code, modify a record, and delete a record.
- **Simulate a Toss:** Decide which team wins the toss based on a random selection and the user’s choice of “Head” or “Tail.”
- **Display Results:** After recording runs and other match data (e.g., overs, boundaries, dot balls, wickets), the system calculates the team’s total runs and displays the match outcome with a trophy graphic.

The project uses several files to store data:
- **record1.dat / record2.dat:** Binary files that store the player records for Team 1 and Team 2 respectively.
- **matchdet.txt:** A text file that holds match details such as team names, venue, and date.
- **players1.txt / players2.txt:** Text files used to display the players in each team.
- **tempo.dat:** A temporary file used during record deletion.

---

## 2. Features

- **User Interface and Visuals:**
  - *Front Screen:* Displays a decorative star pattern and a title banner.
  - *ASCII Trophy:* At the end of the match, a trophy is displayed as ASCII art.
- **Record Keeping:**
  - Insert new records for players.
  - Display all records along with computed total runs.
  - Search for a record using a player’s code.
  - Modify and delete existing records.
- **Match Simulation:**
  - Simulated toss function that uses randomness to determine which team calls the toss.
  - Recording of match details (overs, boundaries, dot balls, wickets) to calculate run rate.
- **File Operations:**
  - Uses both binary and text file I/O to store and retrieve match and player data.

---

## 3. System Requirements

- **Compiler:** The code uses old Turbo C++ style headers (e.g., `<conio.h>`, `<fstream.h>`). It is best compiled with a legacy C++ compiler or updated with modern equivalents if porting to a modern IDE.
- **Operating System:** The project is platform independent but was originally designed for DOS-based environments.
- **Libraries:** Standard C/C++ libraries for input/output, string handling, and file streams.

---

## 4. Installation and Setup

1. **Clone or Download the Repository:**
   ```bash
   git clone https://github.com/AswinBarath/Cricket-player-record-system.git
   ```
2. **Compile the Code:**
   - Using an older Turbo C++ environment: Open the project and compile `COMPROJECT.CPP`.
   - For modern compilers, you might need to replace non-standard headers (e.g., use `<fstream>`, `<iostream>`, `<cstring>`, and remove `<conio.h>` or substitute with standard equivalents like `system("cls")` for clearing the screen).
3. **Prepare the Required Files:**
   - Create (or ensure existence of) text files `players1.txt` and `players2.txt` that list the players for each team (one player per line).
   - The program will generate or update `record1.dat`, `record2.dat`, and `matchdet.txt` during execution.

---

## 5. Code Overview and Design

### a. Main Flow

- **`main()` Function:**  
  - Clears the screen and calls the `front()` function to display a decorative pattern.
  - Prompts the user to press **M** to continue.
  - Calls `second()` to capture match details (team names, venue, date) and writes them into `matchdet.txt`.
  - Displays the match details by calling the `begining()` function.
  - Proceeds to perform a toss by calling `toss()`.
  - Based on the toss outcome, the system alternates between two batting interfaces: `play1()` and `play2()`.
  - Finally, after the match, the `result()` function calculates and displays the match winner with a trophy graphic.

### b. Data Handling (Class `data`)

- **Member Variables:**
  - `name`: Player’s name.
  - `playercode`: Unique code (ID) for each player.
  - `MR`: Variable to store runs for each match (reused during input).
  - `total_run1` and `total_run2`: To aggregate total runs for Team 1 and Team 2.
- **Key Member Functions:**
  - **`enter_name_runs(char t[])`:**  
    Prompts the user for the player’s code, name, and number of matches. For each match, it inputs the runs scored and updates the total runs depending on the team (using comparison with `t1` and `t2`).
  - **`show_record()`:**  
    Displays the player’s record including player number, name, and match run(s).
  - **`modify_data(char t[])`:**  
    Allows the user to update a player’s match run entries and recalculate the total runs.

### c. File I/O Operations

The project uses several functions to handle file operations for each team’s records:

- **`insert(char t[])`:**  
  Opens the corresponding binary file (either `record1.dat` or `record2.dat`) in append mode and writes new records.
- **`display(char t[])`:**  
  Reads and displays all records from the team’s binary file. It also prints the team’s total runs.
- **`search(char t[])`:**  
  Searches for a record based on a player code and displays it if found.
- **`modify(char t[])`:**  
  Modifies a record matching a given player code.
- **`delete_record(char t[])`:**  
  Deletes a record by copying all records except the one to be deleted into a temporary file (`tempo.dat`), then replacing the original file.
- **`teamrec(char t[])`:**  
  Records additional team match details (such as overs played, boundaries, dot balls, wickets) and computes the run rate. The data is written to a file named after the team.

### d. User Interface and Visual Functions

- **`front()`:**  
  Clears the screen and prints a decorative pattern using nested loops to generate a star (asterisk) design, followed by a bold heading.
  
  **Visual Sample:**
  ```
       *         *
      ***       ***
     *****     *****
  ... (pattern continues) ...
  =========================
  +++++++++++++++++++++++++||| CRICKET |||++++++++++++++++++++++++
  ```

- **`second()`, `begining()`:**  
  Collect match details such as team names, venue, and date. These details are saved to `matchdet.txt` and then displayed.
- **`toss()`:**  
  Randomly selects a team and asks for a call (Head or Tail). Displays whether the call was correct.
- **`play1()` and `play2()`:**  
  Provide the menu for operations related to inserting, displaying, searching, modifying, and deleting records. They also offer options to view team details or switch to the other team’s record keeping.
- **`trophy()`, `sresult()`, and `tresult()`:**  
  After match completion, a trophy graphic is printed. The functions determine and display the match winner or indicate a tie.

---

## 6. Expected Execution Flow and Sample Outputs

Below is a simulated run of the application. (Note: Actual outputs may vary based on user inputs and random outcomes during the toss.)

### **A. Front Screen and Introduction**

```
        *         *
       ***       ***
      *****     *****
     *******   *******
  ... (additional pattern lines) ...

*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=

+++++++++++++++++++++++++||| CRICKET |||++++++++++++++++++++++++

Press M to continue: M
```

### **B. Match Details Input**

```
         ------------------------
         ---------WELCOME--------
         ------------------------

*ENTER THE FIRST TEAM: Mumbai Indians
*ENTER THE SECOND TEAM: Chennai Super Kings
*ENTER THE PLACE: Wankhede Stadium
*ENTER THE DATE: 15/08/2018

   Mumbai Indians Vs Chennai Super Kings

   TEAM_1--Mumbai Indians
   TEAM_2--Chennai Super Kings
   PLACE--Wankhede Stadium
   DATE--15/08/2018

WOW! 
THE CLIMATE IS AWESOME.
NOW IT WOULD BE A GOOD MATCH BETWEEN TWO GOOD TEAMS.
LETS MOVE ON TO THE TOSS, PRESS E TO TOSS: E
```

### **C. Toss Process**

Suppose the random toss gives Team 1 the chance:
```
  THE CALL IS FOR TEAM 'Mumbai Indians'
  DO YOU WANT HEAD(H) OR TAIL(T): H

WOW! GOOD BEGINNING.
YOU HAVE WON THE TOSS.
```

*(Alternatively, if the call is wrong, the output would be: “OOPS! YOU HAVE LOST THE TOSS”.)*

### **D. Batting Record Menu (for each team)**

Once the toss is decided, the system enters the record keeping mode. An example menu for Team 1 might look like:

```
=*=*=*=*=*=*=*=*=* PLAYER RECORD KEEPING SYSTEM Mumbai Indians *=*=*=*=*=*=*=*=*=*

1. INSERT RECORD 
2. DISPLAY RECORD 
3. SEARCH RECORD 
4. MODIFY RECORD 
5. DELETE PREVIOUS ENTERED RECORD 
6. VIEW TEAM DETAILS 
7. ENTER NEXT TEAM RECORD 

Enter any one of the options: 1
```

After choosing to insert a record, the program will prompt:
```
::Entry of new record(s)::
How many record(s) you want to enter: 2

Enter player's number: 10
Enter player name: Rohit Sharma
Enter number of matches: 3
'1'-match run(s): 45
'2'-match run(s): 50
'3'-match run(s): 30

[... further entries as per the user’s input ...]
```

### **E. Displaying Records and Team Details**

Upon choosing option 2 (DISPLAY RECORD), the application might print:
```
|||||||||||||||||||||| Entered record(s) ||||||||||||||||||||||||
Player number : 10
Player name : Rohit Sharma
'1'-match run(s) : 30
TOTAL RUNS:125
```

And for viewing team details (option 6), it might additionally read from `players1.txt` to list the players and also display a summary from the binary file.

### **F. Match Result and Trophy Display**

After finishing record entry for both teams, the program calls `result()` which compares the total runs and displays the winner. For example, if Team 1 scores higher:
```
         (***=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=***)
          -############## INDIA ##############-
          -############## 2018 ##############-
          ------------------------------
          #########
          ###########
          #############
          ###############
          #########################

HURRAY! MATCH WON BY Mumbai Indians
[Match details from the team’s record file are printed here]
----------------------------------THANK YOU! ----------------------------------
```

---

## 7. File and Data Dependencies

- **Source Files:**
  - `COMPROJECT.CPP`: Contains all the source code.
  - `computer project code.docx`: (Documentation/Project description file.)
- **Data Files:**
  - `record1.dat` & `record2.dat`: Binary files for team records.
  - `matchdet.txt`: Stores match details such as teams, venue, and date.
  - `players1.txt` & `players2.txt`: Should contain the names (or details) of players for Team 1 and Team 2.
  - `tempo.dat`: Used as a temporary file during deletion of records.

---

## 8. Limitations and Considerations

- **Legacy Code:**  
  The project uses outdated headers (like `<conio.h>` and `<fstream.h>`) that may require updating for modern C++ standards.
  
- **User Input:**  
  The program assumes correct user inputs (e.g., numeric values for runs). Input validation is minimal.

- **Platform Dependency:**  
  Functions like `clrscr()` and `getch()` are specific to certain compilers/OS environments.

- **File I/O:**  
  The file operations are done using binary mode without robust error checking. In a production setting, consider adding error handling for file operations.

- **Randomness in Toss:**  
  The `toss()` function uses `randomize()` and `random(2)`, which is based on Turbo C++ conventions. When porting to modern C++, consider using the `<random>` library.

---

## 9. Conclusion

This “Cricket Player Record System” serves as an excellent example of early C++ projects that combine basic file handling, user interaction, and ASCII-based visual design. The project is structured to provide a simple record-keeping system that mimics a real-world scenario—keeping track of player statistics during a cricket match. While it was developed for educational purposes, the project demonstrates concepts such as classes, file I/O, and basic user interface design in console applications.

Feel free to enhance the code further (for example, by modernizing the syntax or adding additional error checking) and enjoy the nostalgia of a high school project reimagined with detailed documentation!
```

