# Your Way Trivia - Trivia Maker Tool

Authors: [Ryan Pinto](https://github.com/rpintobusiness), [SM Kamal](https://github.com/notasim), [Kim Nguyen](https://github.com/npqkim), [Isaiah Gaines](https://github.com/Isaiah1520), and [Tris Hu](https://github.com/trisfaleel)

## Project Description
  Trivia is one of the world's most well-known and loved games. It can be an intense party game that combines logic, user interaction,  and fun visual elements. To apply and develop our programming skills, we wanted to recreate this famous game. 

  For the game logic and core mechanics, such as question generation, answer validation, and score calculation, we will be using C++. It will be a terminal-based game. 
  
  Users input questions and answers via text file representing question pools. They will interact with keyboard prompts, for example, to start the game, submit answers, or navigate menus. The output will display said questions, feedback on correctness of answers, and player scores. 

  There are three main features of this project. The first is the question and answer mechanism. This may take the form of multiple-choice or true/false and will be in differing subject categories. The second is the score tracking, which automatically keeps track of correctness and updates each player's score for the leaderboard. The third feature will be animations and visual feedback, which we hope to make the project appear more seamless and high quality. 

## User Interface Specification
### Navigation Diagram
![naviDiagram(2)](https://github.com/user-attachments/assets/0e723ce4-c689-440c-a7a7-8809dfe62dfd)
The diagram summarizes the user interactions. From the home menu, users can choose to start or create a game. Choosing to start a game leads the user to a loop that loads and prompts questions, while creating a game leads the user to another menu. Display messages will be provided to give user feedback before re-navigating back to a menu.

### Screen Layouts
Since this is a terminal game, the screen layouts will appear as output to the console.Screen (1) displays the question when the program runs the game, which expects keyboard input of the letter corresponding to answer choice. Screens (2)-(4) display scores and final score at different stages of the game. Screen (5)-(6) give the user feedback to confirm their input was saved before renavigating to the menu. Screens (9) and (10) are both menus, with (10) being the home menu, which simply display numbers for users to input and navigate to.
![screenLayout(all)](https://github.com/user-attachments/assets/d9fda930-b513-47a1-a09a-1e2e37f508ff)


## Class Diagram
![umlClassDiagram](https://github.com/user-attachments/assets/6123b173-d7e7-42b4-ad85-e7292820afeb)
Description: 

The 'Question' class is the base class for all types of questions. The attributes include the question prompt, the correct answer, and the answer given by the student. The methods are display() (which displays the question), checkAnswer() (which checks if the provided answer is correct), and serialize() (which converts question to a string format for saving).

The 'QuestionPool' class stores a collection of questions read from a file. It is aggreagate to the 'Question' class.

The 'TriviaGame' class represents a trivia game containing various questions and is aggregate to the 'QuestionPool' class. The attributes include the list of questions for the game and the title of the game.

The 'GameManager' class is a collection of games where you are able to add more games, load and display previously created games, and save modified games.

The 'User' class represents the user of 'Your Way Trivia - Trivia Maker Tool'. It contains attributes representing the username and the user's score.

## Updated Class Diagram
![UML class-2](https://github.com/user-attachments/assets/bcd392fb-76be-45f4-9b2f-14d758c5893d)


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
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
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
