# C_programs
A repository for various C programs and projects.

**Degree_Planner_and_Audit_Program_1** - allows the user to read and populate text files with official coursework and planned coursework as well as check the GPA and rate of progress to diploma (EE degree only). Users can add courses, remove courses, and edit courses.

**Maze_Game_1** - this program generates a maze from a predetermined board size. The computer then attempts to solve the maze using Tremaux's Algorithm. Future capability includes allowing the user to run through the maze. Two subsets of this algorithm were programmed that alters the priority of directions selected. The first prioritizes directions clockwise, starting with North. The second prioritizes directions based off of the smallest distance (using Pythagorean's Theorem) between the next tile in a direction and the end tile.

**WildfireScienceProjectAlgorithm_Cver** - a program transcribed from JAVA (see Java-Program repo) in which a tsv file with the formatted data (PDSI, Avg Temp, NDVI, Acreage Burned) is converted into an array of equations in which their average percent error is calculated. The user inputs the intercepts and coefficients of the data variables and the program outputs the list of average percent errors.

**Fight_sim_1** - This program is a simple fighting simulator, in which the Player fights a pre-generated opponent. The Player is given the option to attack, use a special attack (which is dependent on stamina, or defend, and damage is based off of a pseudo random number generator. The pre generated opponent has three modes, building up to the full capability as the player.

**Baum_Sweet_Sequence_Program_1** - given a number n, outputs either the Baum Sweet Sequence result for n or for the list for numbers 0 - n.

**Cipher_program_1** - shifts the chars in a given message using a primitive Caesar cipher. Encrypts and decrypts.

**IO_program_1** - simple IO program that asks for name, age, and username and echoes it back.

**IO_program_2** - simple IO program that takes two strings and removes the letters in the first string in the second string.

**LoadingBar_1** - simple IO program playing around with the carriage return and a wait() function.

**Packet_Assembler_Program_1** - a program that is given a text file of scrambled information packets and unscrambles it in order received.

**Pass_generator_1** - creates a set of pseudo-randomly generated strings based on a given input of how many characters and how many passwords.

**Permutation_program_1** - outputs all the possible permutations of an input string.

**Prime_num_program_1** - returns all prime numbers below an input integer N. Algorithm used is the Sieve of Eratosthenes.

**Text_RPG_1** - a simple text role playing game program that takes user input to make decisions about the story's progression.

**Water_Fill_Sim** - a simple simulator that emulates water (or probably more appropiately, sand) falling into a 2d box with walls.


*Some programs are in a folder instead of just the c program and the executable. The C file can be found in the first level of the folder and the executable in the cmake-build-debug folder.

**Some programs require an assist file (e.g. Degree_Planner_and_Audit_Program_1's OfficialCoursework.txt, WildfireScienceProjectAlgorithm_Cver's DataN20082012N0Event.tsv) in order for the .exe to work. Please read the documentation for each program and include the required files when downloading.

***This work was created by Matthew Yu, student of the University of Texas at Austin. Please attribute the original author of any code taken from these programs for the purposes of: criticism, comment, news reporting, teaching (including multiple copies for classroom use), scholarship, and research.
