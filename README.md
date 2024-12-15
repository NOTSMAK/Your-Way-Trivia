# Your Way Trivia - Trivia Maker Tool

Authors: [Ryan Pinto](https://github.com/rpintobusiness), [SM Kamal](https://github.com/notasim), [Kim Nguyen](https://github.com/npqkim), [Isaiah Gaines](https://github.com/Isaiah1520), and [Tris Hu](https://github.com/trisfaleel)

## Project Description
  Trivia is one of the world's most well-known and loved games. It can be an intense party game that combines logic, user interaction,  and fun visual elements. To apply and develop our programming skills, we wanted to recreate this famous game. 

  For the game logic and core mechanics, such as question generation, answer validation, and score calculation, we will be using C++. It will be a terminal-based game. 
  
  Users input questions and answers via text file representing question pools. They will interact with keyboard prompts, for example, to start the game, submit answers, or navigate menus. The output will display said questions, feedback on correctness of answers, and player scores. 

  There are three main features of this project. The first is the question and answer mechanism. This may take the form of multiple-choice or true/false and will be in differing subject categories. The second is the score tracking, which automatically keeps track of correctness and updates each player's score for the leaderboard. The third feature will be animations and visual feedback, which we hope to make the project appear more seamless and high quality. 

## User Interface Specification
### Navigation Diagram
![Screenshot 2024-12-14 192706](https://github.com/user-attachments/assets/82791576-50d2-4e1a-b76e-74af008f0341)

)
The diagram summarizes the user interactions. From the home menu, users can choose to start or create a game. Choosing to start a game leads the user to a loop that loads and prompts questions, while creating a game leads the user to another menu. Display messages will be provided to give user feedback before re-navigating back to a menu.

### Screen Layouts
Since this is a terminal game, the screen layouts will appear as output to the console.Screen (1) displays the question when the program runs the game, which expects keyboard input of the letter corresponding to answer choice. Screens (2)-(4) display scores and final score at different stages of the game. Screen (5)-(6) give the user feedback to confirm their input was saved before renavigating to the menu. Screens (9) and (10) are both menus, with (10) being the home menu, which simply display numbers for users to input and navigate to.

## Screen Layouts for Terminal Game
---

### Screen (1): Question Display  
This screen shows a question during gameplay and expects the user to input the letter corresponding to the correct answer.  

<img src="https://github.com/user-attachments/assets/d45e7421-b5ce-421f-8887-c019cfb1c36e" width="500" alt="Screen 1: Question Display">

---

### Screens (2-4): Scores and Final Score  
These screens display scores at various stages of the game and the final score at the end.  

<img src="https://github.com/user-attachments/assets/64d1a056-8fce-4cc8-be88-926c5368041b" width="500" alt="Screens 2-4: Scores and Final Score">

---

### Screens (5-8): Input Feedback  
Displays feedback after user inputs, confirming that the action has been successfully saved or executed.  

<img src="https://github.com/user-attachments/assets/416dbf3e-0ca2-4278-8152-1823c3cf617c" width="500" alt="Screens 5-8: Input Feedback">

---

### Screen (9): Navigation Menu  
A secondary menu offering navigation to various parts of the game.  

<img src="https://github.com/user-attachments/assets/e3fc3094-266f-43e4-a50d-8b90787a1894" width="500" alt="Screen 9: Navigation Menu">

---

### Screen (10): Home Menu  
The home menu displays options for navigation and expects numeric input.  

<img src="https://github.com/user-attachments/assets/a74232c7-8e45-4f75-b84a-b10d79a0d06f" width="500" alt="Screen 10: Home Menu">

---


## Class Diagram
![image](https://github.com/user-attachments/assets/001f41ba-0f00-4be8-a00e-76671ec22d28)

Description: 

The 'Question' class is the base class for all types of questions. The attributes include the question prompt, the correct answer, and the answer given by the student. The methods are display() (which displays the question), checkAnswer() (which checks if the provided answer is correct), and serialize() (which converts question to a string format for saving).

The 'QuestionPool' class stores a collection of questions read from a file. It is aggreagate to the 'Question' class.

The 'TriviaGame' class represents a trivia game containing various questions and is aggregate to the 'QuestionPool' class. The attributes include the list of questions for the game and the title of the game.

The 'GameManager' class is a collection of games where you are able to add more games, load and display previously created games, and save modified games.

The 'User' class represents the user of 'Your Way Trivia - Trivia Maker Tool'. It contains attributes representing the username and the user's score.



 
 > ## Phase III
## Updated Class Diagram
![image](https://github.com/user-attachments/assets/b58ecc0c-3c95-48bd-821a-105e6004c9cb)

 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * Make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for phase III. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for phase III, and a description of their contributions. Remember that each team member should submit the form individually.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history.
>  * Each team member should also submit the Individual Contributions Form on Canvas for this final phase. In this form, you need to fill in the names of all team members, the percentage of work contributed by each member for the final phase, and a description of their contributions. Remember that each team member should submit the form individually.
 

## Screenshots

---

### Menu
The main menu of the application.

<img src="https://github.com/user-attachments/assets/9ef15bfb-5c6f-48de-9618-c3ae751eabfa" width="600" alt="Menu">

---

### Starting Game
The interface shown when the game begins.

<img src="https://github.com/user-attachments/assets/551abc14-8a79-4a41-bce6-5d328f01c096" width="600" alt="Starting Game">

---

### Formatting of All Question Types
Demonstrates the formatting used for different types of questions in the game.

<img src="https://github.com/user-attachments/assets/a4386547-86e2-4d64-8749-0c51c45b152c" width="600" alt="Formatting of All Question Types">

---

### List of All Available Quizzes
Displays a list of all quizzes available in the application.

<img src="https://github.com/user-attachments/assets/cf52c942-0046-4558-b784-f081eed3d423" width="600" alt="List of All Available Quizzes">

---

### Input/Output Screenshots
Screenshots showcasing the input and output after running your application.


 ## Installation/Usage
  #  To Install and Run 'Trivia Game'
  **Clone the Repository**  
   ```
   git clone https://github.com/cs100/final-project-crazyfive.git
   ```
  **After cloning the repository, you can now compile it using the following commands**  
  ```
  g++ -o a src/gameManager.cpp src/main.cpp src/test_gameManager.cpp
  ```
  **Then after compiling the program, you can run it using the following command**
  ```
  ./a 
  ```
 ## Testing
**Our project underwent thorough testing and validation using the Google Test framework and continuous integration (CI). We implemented unit tests to ensure our code’s reliability and maintainability. To facilitate this, we created a dedicated tests directory that includes gameManagerTest.cpp and leaderboardTest.cpp. We also updated the CMakeLists.txt file to streamline the test execution process.**
