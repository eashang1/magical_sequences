# magical_sequences

### Definitions
  - cyclic de Bruijn sequence with parameters (X,Y,Z): a binary sequence of length X where each substring of length Y appears at most Z times
  - balanced sequence: a sequence with an equal number of each character in the alphabet from which it is created (i.e. equal number of 1s and 0s for binary)
  - de Bruijn couple: a pair of sequence that together form a sequence satisfying the conditions necessary to make the sledgehammer stack trick work
  
 \*For more details see README in a_stuck_wizard repository and the "de Bruijn Magic" PROMYS paper

check_couple.cpp checks if two sequences form a de Bruijn couple

### Descriptions
  - check_de_bruijn.cpp checks if a sequence is a balanced, cyclic de Bruijn sequence
  - generate_B(52,5,2).cpp generates random sequences, checks if they are cycic de Bruijn sequences wih parameters (52,5,2), and outputs the passing sequences
  - generate_balanced.cpp does the same as generate_B(52,5,2).cpp, but only tests balanced sequences
  - generate_couple.cpp generates random sequences to pair with an already balanced sequence and checks if they forma  de Bruijn couple

